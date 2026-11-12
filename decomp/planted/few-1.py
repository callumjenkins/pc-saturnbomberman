from cases import case, plant

SP = 0x060FFFF0        # r15 on entry; the arguments a caller passed on the stack start here
TARGET = 0x060C0100

# The fifth argument, on the stack, points at a halfword that indexes the object table.
STACK_POINTER = [plant(SP + 4, 4, [TARGET], 1.0), plant(TARGET, 2, [0, 1, 2, 7, 0x80, 0xFFFF], 0.8)]

case("f0605895E", [("any",)] * 4, True, STACK_POINTER)
case("f060589EC", [("any",)] * 4, True, STACK_POINTER)
