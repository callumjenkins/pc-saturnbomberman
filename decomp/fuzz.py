"""Random structured SH-2 programs, lifted and run as C against the interpreter.

    python decomp/fuzz.py FIRST_SEED END_SEED

Each program mixes ALU operations, every addressing mode of a load or store, compares, multiplies, if and
else, while and do-while loops, break and early return. The lifter's C and the instructions must agree on
r0 and on memory. `unsup` means the lifter declined, which is not a failure.
"""
import ctypes
import os
import random
import struct
import sys
import tempfile
from collections import Counter

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(os.path.dirname(HERE), "saturn-recomp", "src"))
import lift, structure, check
from saturnrecomp import sh2, sh2emu
E = sh2.encode
BASE = 0x06006000
NOP = 0x0009

class Asm:
    def __init__(s): s.items=[]; s.n=0
    def w(s,x): s.items.append(('w',x))
    def e(s,fmt,n=0,m=0,low=0): s.w(E(fmt,n,m,low))
    def label(s): s.n+=1; return s.n
    def at(s,l): s.items.append(('l',l))
    def br(s,kind,l): s.items.append(('b',kind,l))
    def assemble(s):
        pos={}; a=0
        for it in s.items:
            if it[0]=='l': pos[it[1]]=a
            else: a+=2
        out=[]; a=0
        for it in s.items:
            if it[0]=='l': continue
            if it[0]=='w': out.append(it[1])
            else:
                d=(pos[it[2]]-(a+4))//2
                if it[1]=='bra': out.append(0xA000|(d&0xFFF))
                else: out.append({'bt':0x8900,'bf':0x8B00,'bt/s':0x8D00,'bf/s':0x8F00}[it[1]]|(d&0xFF))
            a+=2
        return b''.join(struct.pack('>H',x) for x in out)

SCR=[0,5,6,7]       # writable scratch
ALL=[0,1,2,3,5,6,7]
def simple(a,r):
    k=r.choice(['add','sub','and','or','xor','not','neg','sh','shn','ext','swap','xtrct','mov','movi','addi','mem','mem','memq','cmpt','mul','tst','ldpi','sti'])
    d=r.choice(SCR); s=r.choice(ALL)
    if k in('add','sub','and','or','xor'): a.e({'add':'add Rm,Rn','sub':'sub Rm,Rn','and':'and Rm,Rn','or':'or Rm,Rn','xor':'xor Rm,Rn'}[k],d,s)
    elif k=='not': a.e('not Rm,Rn',d,s)
    elif k=='neg': a.e('neg Rm,Rn',d,s)
    elif k=='sh': a.e(r.choice(['shll Rn','shlr Rn','shar Rn','shal Rn']),d)
    elif k=='shn': a.e(r.choice(['shll2 Rn','shlr2 Rn','shll8 Rn','shlr8 Rn','shll16 Rn','shlr16 Rn']),d)
    elif k=='ext': a.e(r.choice(['exts.b Rm,Rn','exts.w Rm,Rn','extu.b Rm,Rn','extu.w Rm,Rn']),d,s)
    elif k=='swap': a.e('swap.w Rm,Rn',d,s)
    elif k=='xtrct': a.e('xtrct Rm,Rn',d,s)
    elif k=='mov': a.e('mov Rm,Rn',d,s)
    elif k=='movi': a.e('mov #imm,Rn',d,low=r.choice([0,1,2,0x7f,0x80,0xff,r.randrange(256)]))
    elif k=='addi': a.e('add #imm,Rn',d,low=r.choice([1,0xff,0x80,0x7f,r.randrange(256)]))
    elif k=='mem':
        sz=r.choice('bwl'); i=r.randrange(6)
        # pointer r4 (never written), offsets up to 60
        if r.random()<.5:
            if sz=='b': a.e('mov.b @(disp,Rm),r0',0,4,r.randrange(16)); 
            elif sz=='w': a.e('mov.w @(disp,Rm),r0',0,4,r.randrange(8))
            else: a.e('mov.l @(disp,Rm),Rn',d,4,r.randrange(16))
        else:
            if sz=='l': a.e('mov.l Rm,@(disp,Rn)',4,s,r.randrange(16))
            elif sz=='w': a.e('mov.w r0,@(disp,Rn)',4,0,r.randrange(8))
            else: a.e('mov.b r0,@(disp,Rn)',4,0,r.randrange(16))
    elif k=='memq':
        sz=r.choice('bwl'); pp=r.choice(['post','pre','r0'])
        if pp=='post':
            a.e('mov Rm,Rn',3,4)
            for _ in range(r.randrange(1,4)):
                a.e({'b':'mov.b @Rm+,Rn','w':'mov.w @Rm+,Rn','l':'mov.l @Rm+,Rn'}[sz],d,3)
        elif pp=='pre':
            a.e('mov Rm,Rn',3,4); a.e('add #imm,Rn',3,low=32)
            a.e({'b':'mov.b Rm,@-Rn','w':'mov.w Rm,@-Rn','l':'mov.l Rm,@-Rn'}[sz],3,r.choice([1,2,5,6,7]))
            a.e({'b':'mov.b Rm,@-Rn','w':'mov.w Rm,@-Rn','l':'mov.l Rm,@-Rn'}[sz],3,r.choice([1,2,5,6,7]))
        else:
            a.e('mov #imm,Rn',0,low=r.randrange(0,60,4)) if False else None
            a.e('and #imm,r0',low=0x3c)
            if r.random()<.5: a.e({'b':'mov.b @(r0,Rm),Rn','w':'mov.w @(r0,Rm),Rn','l':'mov.l @(r0,Rm),Rn'}[sz],r.choice([5,6,7]),4)
            else: a.e({'b':'mov.b Rm,@(r0,Rn)','w':'mov.w Rm,@(r0,Rn)','l':'mov.l Rm,@(r0,Rn)'}[sz],4,r.choice([1,2,3,5,6,7]))
    elif k=='cmpt':
        c=r.choice(['cmp/eq Rm,Rn','cmp/hs Rm,Rn','cmp/ge Rm,Rn','cmp/hi Rm,Rn','cmp/gt Rm,Rn'])
        a.e(c,r.choice(ALL),s); a.e('movt Rn',d)
    elif k=='mul':
        a.e(r.choice(['mul.l Rm,Rn','muls.w Rm,Rn','mulu.w Rm,Rn']),r.choice(ALL),s); a.e('sts macl,Rn',d)
    elif k=='tst':
        if r.random()<.5: a.e('tst Rm,Rn',r.choice(ALL),s)
        else: a.e('tst #imm,r0',low=r.choice([1,0x80,0xff,3]))
        a.e('movt Rn',d)
    elif k=='ldpi': pass
    elif k=='sti':
        a.e(r.choice(['cmp/pz Rn','cmp/pl Rn']),r.choice(ALL)); a.e('movt Rn',d)

def cond(a,r):
    k=r.choice(['rr','rr','imm','pz','tst','shift','shift'])
    if k=='rr': a.e(r.choice(['cmp/eq Rm,Rn','cmp/hs Rm,Rn','cmp/ge Rm,Rn','cmp/hi Rm,Rn','cmp/gt Rm,Rn']),r.choice(ALL),r.choice(ALL))
    elif k=='imm': a.e('cmp/eq #imm,r0',low=r.choice([0,1,0xff,0x80,r.randrange(256)]))
    elif k=='pz': a.e(r.choice(['cmp/pz Rn','cmp/pl Rn']),r.choice(ALL))
    elif k=='tst': a.e('tst Rm,Rn',r.choice(ALL),r.choice(ALL))
    else:
        d=r.choice([5,6,7]); a.e(r.choice(['shlr Rn','shlr2 Rn','shlr8 Rn','shlr16 Rn']),d)
        a.e(r.choice(['cmp/ge Rm,Rn','cmp/gt Rm,Rn','cmp/eq Rm,Rn']),d,r.choice(ALL)) if r.random()<.5 else a.e(r.choice(['cmp/ge Rm,Rn','cmp/gt Rm,Rn']),r.choice(ALL),d)

def block(a,r,depth,loops):
    for _ in range(r.randrange(1,5)):
        c=r.random()
        if depth<3 and c<.25:
            # if / if-else
            cond(a,r); L1=a.label(); L2=a.label()
            if r.random()<.5: a.br(r.choice(['bt','bf']),L1)
            else:
                a.br(r.choice(['bt/s','bf/s']),L1); a.w(NOP if r.random()<.5 else E('add #imm,Rn',5,low=1))
            block(a,r,depth+1,loops)
            if r.random()<.5:
                a.br('bra',L2); a.w(NOP); a.at(L1); block(a,r,depth+1,loops); a.at(L2)
            else: a.at(L1)
        elif depth<3 and c<.45 and len(loops)<2:
            ctr=[1,2][len(loops)]
            a.e('mov #imm,Rn',ctr,low=r.randrange(1,4))
            top=a.label(); end=a.label(); loops.append(end)
            style=r.choice(['dowhile','while','dowhile'])
            if style=='dowhile':
                a.at(top); block(a,r,depth+1,loops)
                if r.random()<.4:   # break
                    cond(a,r); a.br(r.choice(['bt','bf']),end)
                a.e('dt Rn',ctr); a.br('bf',top)
            else:
                a.at(top); a.e('tst Rm,Rn',ctr,ctr); a.br('bt',end)
                block(a,r,depth+1,loops)
                if r.random()<.4:
                    cond(a,r); a.br(r.choice(['bt','bf']),end)
                a.e('add #imm,Rn',ctr,low=0xff); a.br('bra',top); a.w(NOP)
            a.at(end); loops.pop()
        elif depth>0 and c<.5 and r.random()<.2:
            # early return
            cond(a,r); L=a.label(); a.br('bf',L); a.e('mov #imm,Rn',0,low=r.randrange(256)); a.w(0x000B); a.w(NOP); a.at(L)
        else:
            for _ in range(r.randrange(1,4)): simple(a,r)

def program(seed):
    r=random.Random(seed); a=Asm()
    a.e('mov Rm,Rn',0,5); a.e('mov Rm,Rn',1,6); a.e('mov Rm,Rn',2,7); a.e('mov Rm,Rn',3,6)
    block(a,r,0,[])
    # return a mix
    a.e(r.choice(['add Rm,Rn','xor Rm,Rn','sub Rm,Rn']),0,r.choice([1,2,3,5,6,7]))
    a.w(0x000B); a.w(NOP)
    return a.assemble()

KR=0x060B0000
def run_one(seed, trials=40):
    code=program(seed)
    if len(code)>230: return 'big',''
    image=sh2.Image(code,BASE)
    try: c=lift.lift(image,BASE)
    except (lift.Unsupported, structure.Unstructured) as e: return 'unsup',str(e)
    except Exception as e: return 'LIFTCRASH',repr(e)
    path=os.path.join(TMP,'f%d.c'%seed)
    open(path,'w').write('#include "guest.h"\n'+c)
    try: lib=check.build([path])
    except Exception as e: return 'nocompile',c
    fn=getattr(lib,'f06006000'); fn.restype=ctypes.c_int32
    head=c.splitlines()[0]; returns=head.startswith('int'); nparams=head.count('int r')
    fn.argtypes=[ctypes.c_int32]*nparams
    rr=random.Random(seed*7+1)
    for t in range(trials):
        cpu=sh2emu.load(os.devnull,BASE); host=sh2emu.load(os.devnull,BASE)
        w=cpu.mem.regions[0][2]; hw=host.mem.regions[0][2]
        w[BASE-0x06000000:BASE-0x06000000+len(code)]=code
        data=rr.randbytes(0x400)
        # interesting data: mix of extremes
        data=bytes(rr.choice([0,0xff,0x7f,0x80,b]) for b in data)
        w[KR-0x06000000:KR-0x06000000+0x400]=data; hw[:]=w
        vals=[0x060B0000+rr.randrange(0,0x80,4)]+[rr.choice([0,1,2,3,0x7f,0x80,0xff,0x7fff,0x8000,0xffff,0x7fffffff,0x80000000,0xffffffff,0xfffffffe,rr.getrandbits(32)]) for _ in range(3)]
        keep=(ctypes.c_char*len(hw)).from_buffer(hw)
        ctypes.c_void_p.in_dll(lib,'g_wram').value=ctypes.addressof(keep)
        ctypes.c_int.in_dll(lib,'g_fault').value=0
        sv=[v-(1<<32) if v>=1<<31 else v for v in vals[:nparams]]
        got=fn(*sv)
        try: want=cpu.call(BASE,max_steps=100000,**{'r%d'%(4+i):v for i,v in enumerate(vals)})
        except Exception as e: del keep; continue
        del keep
        if returns and (got&0xffffffff)!=want: return 'DIFF',(c,vals,hex(got&0xffffffff),hex(want),seed)
        if bytes(hw[:0x0B0000+0x500])!=bytes(w[:0x0B0000+0x500]): return 'DIFFMEM',(c,vals,seed)
    return 'ok',c
TMP = tempfile.mkdtemp(prefix='fz')


def main():
    lo, hi = int(sys.argv[1]), int(sys.argv[2])
    cnt = Counter()
    for s in range(lo,hi):
        k,info=run_one(s); cnt[k]+=1
        if k in('DIFF','DIFFMEM'): print('=====',k,s); print(info[0]); print(info[1:])
        if k=='LIFTCRASH': print('LIFTCRASH',s,info)
        if k=='nocompile' and cnt[k]<3: print('NOCOMPILE',s)
        if k=='unsup' and cnt[k]<6: print('unsup',s,info)
    print(cnt)


if __name__ == '__main__':
    main()
