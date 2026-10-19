# Working in Bomberman

This repository owns game configuration, routes, inputs, and research. Generic recompiler and
runtime changes belong in the `saturn-recomp` submodule. Read `README.md` for commands,
`docs/RESEARCH.md` for game timings and reference limitations, and the relevant part of `PLAN.md` (the translation) or `PLAN-RELEASE.md` (builds and playtesters).
Disc data and generated code stay under ignored `build/` directories.

Use the delegation workflow in [docs/AGENT-WORKFLOW.md](docs/AGENT-WORKFLOW.md). Delegate bounded
function checks, reference comparisons, and automation runs when they can proceed independently
or benefit from a fresh assessment. Keep at most two workers active across Claude and Codex for
one task. The main agent owns implementation and integration. Workers return evidence and do
not delegate further. Small sequential changes can stay in one session.

Before a worker runs anything, give it the source identity and build state, its assigned checkout,
output directories, allowed mutations, and timeout. Existing worktree slots may be in use.
Validation of uncommitted work needs that exact work, including the submodule's changes.
Read-only investigation can share a checkout; builds and fixed-output suites need exclusive use.

The three project agents are `function-validator`, `reference-comparer`, and `automation-runner`.
Read the shared workflow before assigning or accepting their work. If the client cannot load
custom agents, give a generic subagent the corresponding role section and the shared contract.

For engine changes, `saturn-recomp/tools/check.sh` checks Python, instruction semantics, and
runtime units without game data. Bomberman's Python tests use `uv run pytest -q`.
`uv run tests/frames.py ROUTE...` checks game regressions. That script can rebuild and already
parallelises routes. Agree on exclusive build access before running it. A reference comparison
provides separate evidence of correctness; frame hashes and the internal interpreter do not.

Callum writes commits. Leave completed work in the working tree unless he asks for a commit.
