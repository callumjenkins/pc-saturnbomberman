from cases import case, plant

RETURNS = 0x0600660C        # a bare rts

case("f060A805C", [], True, stubbed=False)
# The two system-call table entries it calls through hold a function that returns, so a real-callee trial runs to the end.
case("f06098C6C", [("any",)] * 4, True, [plant(0x06000300, 4, [RETURNS], 1.0), plant(0x06000344, 4, [RETURNS], 1.0)],
     stubbed=False)
