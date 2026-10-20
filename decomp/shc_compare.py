"""Compiles krnl.c with Hitachi SHC and compares each function with the game's.

    SHC_DIR=/path/to/shc python decomp/shc_compare.py [-v] [shc options]

SHC_DIR holds shc.exe, which runs under Wine; WINEPREFIX is used if set. The game's side comes from
the recompiler's output in build/recomp. Instruction sequences are compared with literal addresses
and branch targets ignored, at four levels: exact, the same up to register names, the same
instructions in another order, and different.
"""
import re,glob,sys,os,subprocess,collections
HERE=os.path.dirname(os.path.abspath(__file__)); REC=os.path.join(os.path.dirname(HERE),"build","recomp")
SHC_DIR=os.environ["SHC_DIR"]
def norm(ins):
    ins=ins.strip().lower(); ins=re.sub(r"\s+"," ",ins); ins=re.sub(r",\s*",",",ins)
    m=re.match(r"(\S+)\s*(.*)",ins)
    if not m: return None
    op,args=m.groups()
    if op in("bra","bt","bf","bt/s","bf/s","bsr"): return op.replace("/s","")+("/s" if "/s" in op else "")
    if op in("mov.l","mov.w") and re.match(r"(0x[0-9a-f]+|l\d+(\+\d+)?),r\d+$",args): return op+" @pool,"+args.split(",")[1]
    if op in("muls","mulu"): op=op+".w"
    if op in("jsr","jmp"): return op+" "+args
    args=re.sub(r"\(0,(r\d+)\)",r"@\1",args)
    return op+(" "+args if args else "")
def game_funcs():
    g={}
    for fn in sorted(glob.glob(REC+"/p_krnl_*.cpp")):
        cur=None
        for line in open(fn):
            m=re.match(r"void f_([0-9A-F]{8})\(",line)
            if m: cur=g.setdefault(m.group(1),[]); continue
            m=re.search(r"//\s+[0-9A-F]{8}\s+(.*)$",line)
            if m and cur is not None:
                for part in m.group(1).split(" ; "):
                    n=norm(part)
                    if n: cur.append(n)
    return g
def shc_funcs(src):
    out={};cur=None
    for line in open(src,errors="ignore"):
        line=line.split(";")[0].rstrip()
        if not line.strip(): continue
        m=re.match(r"^_(\w+):",line)
        if m: cur=m.group(1); out[cur]=[]; continue
        if cur is None: continue
        if re.match(r"^\s+\.(RES|DATA|SDATA)",line): cur=None; continue
        if re.match(r"^\s+\.",line) or re.match(r"^L\d+:",line): continue
        n=norm(line)
        if n: out[cur].append(n)
    return out
def canon(seq):
    mp={};out=[]
    for i in seq:
        def r(m):
            k=m.group(0)
            if k not in mp: mp[k]="R%d"%len(mp)
            return mp[k]
        out.append(re.sub(r"\br\d+\b",r,i))
    return out
def mnems(seq): return sorted(i.split()[0] for i in seq)
def main():
    args=sys.argv[1:]; verbose="-v" in args
    opts=[a for a in args if a!="-v"] or ["-optimize=1"]
    env=dict(os.environ,WINEDEBUG="-all",SHC_LIB="Z:"+SHC_DIR,SHC_TMP="Z:"+HERE)
    src=os.path.join(HERE,"krnl.src")
    if os.path.exists(src): os.remove(src)
    p=subprocess.run(["wine",os.path.join(SHC_DIR,"shc.exe"),"-cpu=sh2","-code=asmcode"]+opts+["krnl.c"],cwd=HERE,env=env,capture_output=True,text=True)
    errs=[l for l in p.stdout.splitlines() if re.search(r"\((E|F)\)",l)]
    if errs: print("\n".join(errs))
    if not os.path.exists(src): return
    G=game_funcs(); res=[]
    import difflib
    for name,seq in shc_funcs(src).items():
        m=re.match(r"f([0-9A-Fa-f]{8})",name)
        if not m: continue
        a=m.group(1).upper(); g=G.get(a)
        if g is None: print(a,"not in game"); continue
        lvl = 1 if seq==g else 2 if canon(seq)==canon(g) else 3 if mnems(seq)==mnems(g) else 4
        res.append((a,len(g),len(seq),lvl))
        if lvl>1 and verbose:
            print(f"--- {a} game={len(g)} ours={len(seq)}")
            for l in difflib.unified_diff(g,seq,"game","ours",lineterm="",n=0):
                if not l.startswith(("---","+++","@@")): print("  ",l)
    names={1:"exact",2:"same up to register names",3:"same instructions, different order",4:"different"}
    c=collections.Counter(r[3] for r in res)
    print("functions:",len(res),"| "," | ".join(f"{names[k]}: {c[k]}" for k in (1,2,3,4)))
    for r in res: print(f"  {r[0]} game {r[1]:3} ours {r[2]:3}  {names[r[3]]}")
main()
