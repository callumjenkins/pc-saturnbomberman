"""Turns a control-flow graph of basic blocks into C with if, while, break and continue.

A block is a Block: statements, then a terminator. The graph must reduce to those constructs; anything
else raises Unstructured, and the function stays for a person to write.
"""
from dataclasses import dataclass, field


class Unstructured(Exception):
    pass


@dataclass
class Block:
    start: int
    stmts: list[str] = field(default_factory=list)
    kind: str = "return"                    # return, goto, or branch
    value: str = ""                         # the returned expression, or the branch condition
    targets: list[int] = field(default_factory=list)   # goto: [next]; branch: [taken, fallthrough]


def successors(block: Block) -> list[int]:
    return block.targets if block.kind != "return" else []


def reachable(blocks: dict[int, Block], entry: int) -> list[int]:
    """Block starts in reverse postorder."""
    order: list[int] = []
    seen: set[int] = set()

    def visit(at: int) -> None:
        seen.add(at)
        for nxt in successors(blocks[at]):
            if nxt not in seen:
                visit(nxt)
        order.append(at)

    visit(entry)
    return order[::-1]


def postdominators(blocks: dict[int, Block], order: list[int]) -> dict[int, int | None]:
    """The immediate post-dominator of each block, None when the function can return from either side."""
    exit_node = -1
    preds: dict[int, list[int]] = {at: [] for at in order}
    preds[exit_node] = []
    succs: dict[int, list[int]] = {}
    for at in order:
        succs[at] = successors(blocks[at]) or [exit_node]
        for nxt in succs[at]:
            preds[nxt].append(at)
    rpo = [exit_node] + [at for at in reversed(order)]          # roughly reverse postorder of the reverse graph
    index = {at: i for i, at in enumerate(rpo)}
    idom: dict[int, int] = {exit_node: exit_node}

    def intersect(a: int, b: int) -> int:
        while a != b:
            while index[a] > index[b]:
                a = idom[a]
            while index[b] > index[a]:
                b = idom[b]
        return a

    changed = True
    while changed:
        changed = False
        for at in rpo[1:]:
            done = [s for s in succs[at] if s in idom]
            if not done:
                continue
            new = done[0]
            for other in done[1:]:
                new = intersect(new, other)
            if idom.get(at) != new:
                idom[at] = new
                changed = True
    return {at: (None if idom.get(at, exit_node) == exit_node else idom[at]) for at in order}


def loops(blocks: dict[int, Block], order: list[int]) -> dict[int, set[int]]:
    """For each loop header, the blocks of its body, from the back edges that return to it."""
    position = {at: i for i, at in enumerate(order)}
    bodies: dict[int, set[int]] = {}
    preds: dict[int, list[int]] = {at: [] for at in order}
    for at in order:
        for nxt in successors(blocks[at]):
            preds[nxt].append(at)
    for at in order:
        for nxt in successors(blocks[at]):
            if position[nxt] <= position[at]:                       # a back edge to nxt
                body = bodies.setdefault(nxt, {nxt})
                stack = [at]
                while stack:
                    node = stack.pop()
                    if node not in body:
                        body.add(node)
                        stack.extend(preds[node])
    return bodies


def drop_tail_continue(lines: list[str]) -> list[str]:
    """The loop body without a `continue;` that is its last statement, or the last in an if or else at its end."""
    lines = list(lines)
    for i in range(len(lines) - 1, -1, -1):
        if lines[i].strip() == "continue;" and all(line.strip() == "}" for line in lines[i + 1:]):
            del lines[i]
            if i < len(lines) and i > 0 and lines[i - 1].strip() == "} else {" and lines[i].strip() == "}":
                del lines[i - 1]
            break
        if lines[i].strip() != "}":
            break
    return lines


def negate(condition: str) -> str:
    return condition[2:-1] if condition.startswith("!(") and condition.endswith(")") else "!(%s)" % condition


class Structurer:
    def __init__(self, blocks: dict[int, Block], entry: int) -> None:
        self.blocks = blocks
        self.entry = entry
        self.order = reachable(blocks, entry)
        self.ipdom = postdominators(blocks, self.order)
        self.bodies = loops(blocks, self.order)
        self.active: list[tuple[int, int | None]] = []          # (header, exit) of the loops being written

    def run(self) -> list[str]:
        return self.sequence(self.entry, None)

    def exit_of(self, header: int) -> int | None:
        body = self.bodies[header]
        outside = {n for at in body for n in successors(self.blocks[at]) if n not in body}
        if len(outside) > 1:
            raise Unstructured("the loop at %08X leaves in more than one place" % header)
        return outside.pop() if outside else None

    def leaving(self, at: int) -> str | None:
        for header, leave in reversed(self.active):
            if at == header:
                return "continue;"
            if at == leave:
                return "break;"
        return None

    def sequence(self, at: int | None, stop: int | None, first: bool = False) -> list[str]:
        """The blocks from `at` up to `stop`, where the construct around them carries on."""
        out: list[str] = []
        while at is not None and (at != stop or first):
            if not first:
                jump = self.leaving(at)
                if jump:
                    return out + [jump]
                if at in self.bodies and all(at != header for header, _ in self.active):
                    out += self.loop(at)
                    at = self.exit_of(at)
                    continue
            first = False
            block = self.blocks[at]
            out += block.stmts
            if block.kind == "return":
                return out + ["return %s;" % block.value if block.value else "return;"]
            if block.kind == "goto":
                at = block.targets[0]
                continue
            at = self.branch(block, out)
        return out

    def branch(self, block: Block, out: list[str]) -> int | None:
        """Writes an if for the branch and returns where its arms join."""
        merge = self.ipdom[block.start]
        in_loop = not self.active or merge in self.bodies[self.active[-1][0]]
        join = merge if in_loop else None
        then, other = (self.sequence(t, join) for t in block.targets)
        condition = block.value
        if not then and other:
            condition, then, other = negate(condition), other, []
        if then:
            out += ["if (%s) {" % condition] + ["    " + line for line in then]
            out += (["} else {"] + ["    " + line for line in other]) if other else []
            out.append("}")
        return join

    def loop(self, header: int) -> list[str]:
        leave = self.exit_of(header)
        block = self.blocks[header]
        body = self.bodies[header]
        self.active.append((header, leave))
        tests_only = block.kind == "branch" and not block.stmts and (block.targets[0] in body) != (block.targets[1] in body)
        if tests_only:
            stay = block.targets[0] in body
            condition = block.value if stay else negate(block.value)
            inner = self.sequence(block.targets[0] if stay else block.targets[1], header)
            head = "while (%s) {" % condition
        else:
            inner = self.sequence(header, header, first=True)
            head = "while (1) {"
        self.active.pop()
        inner = drop_tail_continue(inner)
        if len(inner) >= 5 and inner[-5].startswith("if (") and inner[-4:] == ["    continue;", "} else {", "    break;", "}"]:
            condition = inner[-5][4:-3]
            return ["do {"] + ["    " + line for line in inner[:-5]] + ["} while (%s);" % condition]
        return [head] + ["    " + line for line in inner] + ["}"]
