from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

FIX = 0x060C0100
FIX2 = 0x060C0400
CUR = plant(0x060D7768, 4, [bomber(0)], 1.0)
MOVER = plant(0x060D7B3C, 4, [FIX], 1.0)
TASK = 0x060C2100
SPIN = 0x060C2200


def words(base, values, size=4, stride=None):
    """The image's own table at base, which a random trial overwrites."""
    return [plant(base + i * (stride or size), size, [v], 1.0) for i, v in enumerate(values)]


# the jump tables of 0606B6D2 and 0606B6BC, and of 060A5E7C, 060A5EB6 and 060A6668
STATES = [plant(0x060B90E8 + 8 * i + j, 4, [v], 1.0)
          for i, (a, b) in enumerate([(0x0606B6E8, 0x0606B734), (0x0606B778, 0x0606B78E),
                                      (0x0606B758, 0x0606B758), (0x0606B78E, 0x0606B78E)])
          for j, v in ((0, a), (4, b))]
# what the handlers reach: an animation script by id, and the object 060C1AA8 names
STATES += [plant(0x060BD904, 4, [0x060C0800], 1.0), plant(0x060C0804, 4, [0x060C0900], 1.0)]
STATES += [plant(0x060C0900 + 4 * i, 4, [0x060C0A00], 1.0) for i in range(-1, 12)]
STATES += [plant(0x060C1AA8, 2, [3], 1.0), plant(obj(3) + 44, 2, [9], 1.0), plant(obj(3) + 42, 2, [0, 0, 1], 1.0),
           plant(FIX + 48, 2, [0, 1, 2], 1.0), plant(FIX + 50, 2, [0, 1, 2, 3], 1.0), plant(bomber(0) + 80, 2, [0, 1, 2], 1.0)]
HANDLERS = [plant(0x060B1224 + 16 * i, 4, [v], 1.0) for i, v in ((0, 0x060A733C), (3, 0x060A62A0), (4, 0x060A64C0), (5, 0x060A64F2))]
HANDLERS += [plant(0x060B122C + 16 * i, 4, [v], 1.0) for i, v in ((0, 0x060A7460), (3, 0x060A6496), (4, 0x060A64C8), (5, 0x060A6534))]
HANDLERS += [plant(0x060B1258 + 12 * i, 4, [v], 1.0) for i, v in ((0, 0x060A6336), (1, 0x060A64C0), (2, 0x060A64EE), (3, 0x060A6534))]

# vertical limit the mover is compared with, the bomber's object and the mover's position
case("f06026AD4", [], False, [
    CUR, MOVER,
    plant(0x060C090A, 2, [100, 400], 1.0),
    plant(FIX + 18, 2, [-100, 100, 600], 1.0),
    plant(bomber(0) + 36, 2, [3, 4], 1.0),
    plant(bomber(0) + 42, 2, [5, 0, 3], 1.0),
    plant(bomber(0) + 58, 2, [0, 1, 1], 1.0),
    plant(bomber(0) + 6, 1, [1, 2], 1.0),
    plant(obj(3) + 52, 4, [0], 1.0), plant(obj(4) + 52, 4, [0], 1.0),
    plant(obj(3) + 56, 4, [0, 12, 16, 19, 4, 20, 30], 1.0), plant(obj(4) + 56, 4, [0, 12, 16, 19, 4, 20, 30], 1.0),
])
case("f0602F638", [], False, [plant(0x060C1034, 4, [0x0602FCCE, 0x060306F0], 0.9)])
case("f0603500C", [], False, [plant(0x060C164C, 4, [SPIN], 1.0)])
case("f0604AF5C", [span(0, 5), pick(FIX)], False, [
    plant(FIX + 2, 2, [3], 1.0),
    plant(obj(3) + 22, 2, [100, 90, 110, -300], 0.9),
    plant(obj(3) + 30, 2, [291, 200, 400, 0], 0.9),
])
case("f06054086", [], False, [
    plant(0x060D7E60, 4, [TASK], 1.0),
    plant(TASK + 14, 2, [0, 1, 2, 3, 3, 4, 5, 6, 7], 1.0),
    plant(TASK + 18, 2, [4, 8, 16, 5], 1.0),
    plant(TASK + 10, 2, [0, 1, 2, 3, 4, -1, 5], 1.0),
    plant(TASK + 12, 2, [0, 1, 2, 3, 4, -1, 5], 1.0),
])
case("f0606B6D2", [], False, STATES + [CUR, MOVER, plant(bomber(0) + 46, 2, [0, 1, 2, 3], 1.0)])
case("f0606D986", [], False, STATES + [CUR, MOVER, plant(bomber(0) + 46, 2, [0, 1, 2, 3], 1.0)])
case("f0606D410", [], True, [
    CUR, MOVER,
    plant(bomber(0) + 42, 2, [0, 16, 0x80, 0x90, 1, 17], 1.0),
    plant(bomber(0) + 20, 2, [0, 0x2000, 5], 1.0),
    plant(0x060C1E44, 2, [0, 1], 1.0),
    plant(FIX + 4, 2, [0, 50, 84, 100], 1.0),
    plant(0x060E2150, 4, [FIX2], 1.0),
    plant(FIX2 + 4, 4, [0x0606B1EC], 1.0),
])
_OBJ = [plant(FIX, 4, [FIX2], 1.0)]
_VT = [plant(FIX2 + 364, 4, [0x060A629C], 1.0), plant(FIX2 + 460, 4, [0x060A629C], 1.0)]
case("f060A3AAA", [pick(0, FIX), span(0, 9), span(0, 9), span(0, 9)], False, _OBJ + _VT)
case("f060A4BE2", [pick(0, FIX), span(0, 9), span(0, 9), span(0, 9)], False, _OBJ + _VT)
case("f060A5E7C", [pick(FIX), span(0, 9), span(0, 9), span(0, 9)], False, HANDLERS + [plant(FIX + 40, 4, [0, 3, 4, 5], 1.0)])
case("f060A5EB6", [pick(FIX), span(0, 9), span(0, 9), span(0, 9)], False, HANDLERS + [plant(FIX + 40, 4, [0, 3, 4, 5], 1.0)])
case("f060A6668", [pick(FIX)], True, [
    plant(FIX + 56, 4, [0, 0, 0, 3, 4, 1, 2, 5], 1.0),
    plant(FIX + 16, 4, [FIX2], 1.0),
    plant(FIX2, 4, [0x00200000, 0x002FFFFF, 0x00300000, 0x01FFFFFF, 0x02000000, 0x058FFFFF, 0x05900000, 0x10100000, 0, 5], 1.0),
    plant(FIX2 + 12, 4, [-1, 0, 7], 1.0),
] + HANDLERS)
case("f06018138", [span(-40, 200)], False, words(0x060B45FC, [0x168, 0x190, 0x190, 0x1B8, 0x1E0, 0x208, 0x208, 0x230, 0x258], 2) + [
    CUR, MOVER,
    plant(0x060C062C, 2, [0, 1, 2, 3], 1.0),
    plant(0x060C063D, 1, [2, 3], 1.0),
    plant(bomber(0) + 66, 2, [1, 2, 3, 200], 1.0),
    plant(bomber(0) + 46, 2, [0, 1], 1.0),
    plant(FIX + 38, 2, [-3, 0, 12], 1.0),
])
# two records of the list at 060D776C: the head, and one whose next is 0
LINKS = [plant(0x060D776C, 4, [0xFF010100], 1.0), plant(0x060D7774, 4, [0xFF000000], 1.0)]
_PLAYER = LINKS + [CUR, MOVER, plant(bomber(0) + 46, 2, [0, 1, 2, 3], 1.0), plant(0x060C062C, 2, [0, 1, 2, 3], 1.0)]
case("f06070E2E", [], True, STATES + _PLAYER)
case("f0607E50C", [], False, STATES + _PLAYER)
case("f06084ACC", [], False, STATES + _PLAYER)
case("f0608A8E4", [], True, [
    CUR,
    plant(bomber(0) + 20, 2, [0, 5, 100], 1.0),
    plant(0x060EC8B0, 2, [0x88, 7, 0, 0x10, 0x20], 1.0),
    plant(0x060EC8B0 + 10, 2, [0x88, 7, 0, 0x10, 0x20], 1.0),
    plant(0x060EC8B0 + 200, 2, [0x88, 7, 0, 0x10, 0x20], 1.0),
] + words(0x060B90A0, [0, 1, 0x40, 0xFFFF, 0xFFC0], 2) + words(0x060B90B4, [0, 3, 4, 1, 2], 2))
case("f0609732A", [("pick", [0, 1, -1, 5, -300, 0x8000, 0x10000, 0x10001, -0x20000, 0x123456, 100000]),
                    ("pick", [0, 1, -1, 7, 300, 0x4000, 0x10000, 0x10001, 0x30000, -0x23456, 99999])], True)
