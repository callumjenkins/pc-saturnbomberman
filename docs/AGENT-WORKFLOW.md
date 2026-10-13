# Delegating Bomberman work

Use one main agent and up to two workers. The main agent defines questions, makes source changes,
and assesses results. Workers investigate a bounded question or run an agreed check. The same
contract applies when Claude and Codex work together, although each client starts its own agents.
Both leads must agree on assignments before using the same checkout or build.

## Starting a session

Start Claude or Codex inside the Bomberman checkout containing these files. The parent directory
of the worktree slots is not a Git repository. Definitions in one slot are not installed in the
other slots until those files are brought across. Use an absolute path to this workflow when a
worker's assigned checkout does not contain it.

Claude imports `AGENTS.md` through `CLAUDE.md` and discovers `.claude/agents/*.md`. Codex reads
`AGENTS.md` and discovers `.codex/agents/*.toml`. Codex's project configuration caps spawned
threads at two. Claude's limit, and the combined limit across clients, are instructions to the
lead. Host permission settings still apply, and project configuration must be trusted by the
client. Restart a session after installing the definitions, then check its available agents.

All three agents inherit the main model. Function and reference checks use high effort; the
automation runner uses medium. Keep Opus 5.5 high or 6.1 Sol high for the lead. Try a smaller
runner model only after comparing its reports with these defaults. Native definitions restrict
Claude's available tools to reading, searching, and shell commands; shell access can still write
files. Output ownership below is a workflow rule, not a filesystem sandbox.

The definitions are small adapters. This document owns the roles and procedures. When native
agents are unavailable, pass a generic subagent this document and name its role. Workers do not
spawn further agents. Keep small sequential tasks in the main session.

## Task and evidence contract

Before delegation, the lead supplies these fields in the task message:

| Field | What to supply |
| --- | --- |
| Question | One observable property or a finite list of checks, with expected results where known |
| Scope | Module and guest addresses, routes and comparison window, or exact suite commands |
| Source | Absolute Bomberman and engine checkout paths, both revisions, and relevant uncommitted changes |
| Build | Existing executable path and hash, generated-input stamp, config and seed hashes, and module identity, or the assigned preparation step |
| Ownership | Exclusive build or fixed-output directories, allowed scratch writes, and any permitted build step |
| Budget | Timeout per command or run, maximum retries, and process or compiler job limits |
| Report | A fresh directory such as `build/agent-runs/TASK/ROLE/ATTEMPT/` and the report path within it |

Resolve missing ownership or source identity with the lead before execution. Read-only inspection
can continue meanwhile. A revision alone does not identify a dirty checkout. The lead preserves
the relevant diff and untracked files in scratch, or prepares an isolated copy with those changes.
Record their hashes. Never reset a slot or overwrite someone else's changes to prepare a worker.

A pure Python check can mark executable identity as not applicable. When the task authorises a
build that does not exist yet, identify its source and exclusive output directories first, then
record the executable and generated inputs after building, before running comparisons.

Use `git status --short`, `git rev-parse HEAD`, and the same commands inside `saturn-recomp` to
identify source. Check the actual engine directory and Python import location: a copied virtual
environment can still import the original editable checkout. Give each writing worker its own
engine checkout and build directories. A new worktree at `HEAD` needs the uncommitted changes
applied explicitly before it can validate them.

Copied generated builds can also retain absolute paths to the original engine. Check
`SATURN_RUNTIME` in the generated `CMakeLists.txt` and the source paths in the CMake cache and
Ninja build files before reusing them. Prefer fresh generation and configuration in an isolated
checkout. A correct Python import alone does not establish which C++ runtime gets compiled.

Build once under exclusive ownership, then keep the source, config, seeds, and executable fixed
during comparisons. Record identities before and after. If relevant inputs change mid-run, mark
the evidence invalid and have the lead schedule a run against a stable snapshot. Shared read-only
source inspection can happen while a suite runs; implementation must happen in another snapshot
or wait until the suite releases its checkout.

Account for each command's real writes, including rebuilds, caches, sockets, and fixed run paths.
`tests/frames.py` calls `build.ensure`, writes `build/test/`, and already runs routes concurrently.
`lab verify` calls `build.ensure` and uses `build/lab/verify` and `build/lab` regardless of route.
Two such commands must not share those directories. Give a fixed-output command an exclusive
checkout or run it sequentially. Unique report paths alone do not isolate those writes.

Workers write scratch artifacts and logs, and any specifically authorised build outputs. The lead
owns maintained source, seeds, route inputs, classifications, frame baselines, and submodule pins.
Exploratory seed learning is a separate lead-owned operation. Validation disables it and reports
unknown targets. Workers do not commit, publish, upload, schedule jobs, or send playtest messages.

Each worker returns a short summary and writes its full evidence to the assigned report:

- Status: `pass`, `fail`, `incomplete`, or `invalidated`, with the property and scope checked.
- Source and build identities, uncommitted input hashes, and relevant reference configuration.
- Commands, working directories, relevant non-secret environment settings, exit codes, elapsed
  time, and timeouts. Keep full logs in files.
- Expected and observed values, first divergence, attempted cases, skipped or rejected cases,
  and artifact paths. A missing prerequisite is an incomplete check.
- Reproduction steps and the limits of the conclusion. Report interpreter agreement, frame
  regression agreement, and independent reference agreement separately.

Use `incomplete` when the assignment cannot run against the required source or prerequisites,
and `invalidated` when a run's source or build changed during execution. Report individual command
failures separately even if the overall assignment is incomplete.

Count expected observations as well as failures. A successful process with no observations, a
missing frame, a truncated reference run, or a fatal guest error cannot establish a pass. Some
game commands print mismatches without returning a failing exit code; inspect their reports.
Preserve the first failure before a bounded retry. Default to no retries unless the task allows
one and names a reason, such as confirming reproducibility. Repeated retries cannot erase a fail.

## Function validator

Validate one module and a bounded list of guest entries. Read its original disassembly, generated
implementation, and relevant tests. Module or image identity matters because overlays can reuse
an address. Use `lab disasm --module` when the address is ambiguous.

Reuse `saturnrecomp.recomp.selftest` and the generated `selftest` executable. The generator accepts
`--funcs A,B,...`, `--vectors`, and `--seed`; its module selection is `--test NAME`. Read its help
and the engine README for the exact image and build arguments. Write vectors and throwaway input
tools in assigned scratch. Generation and compilation require explicit output ownership.

Select inputs from what the function reads and the paths it takes. Consider zero, sign boundaries,
overflow, carries, shifts, saturation, delay slots, pointer alignment, aliased buffers, and relevant
structure fields. State the expected result independently where possible. Compare registers,
status flags, and memory effects; a returned value alone may miss the error.

The automatic selector targets functions it can run without hardware and filters faulting vectors.
Report attempted, executed, rejected, and unsupported cases. A hardware-dependent or task-switching
function may need a controlled game route and the reference comparer instead. Do not force it into
the isolated harness and treat discarded inputs as covered.

Agreement with `sh2emu` checks translation against that interpreter. They can share the same wrong
instruction semantics. Hardware-sensitive arithmetic and timing need independent evidence. Retain
any failing vector and identify the smallest state difference; the lead writes permanent tests
and fixes after reviewing it.

## Reference comparer

Read `docs/RESEARCH.md`, the route, and the `beetle-compare` skill when available. The local core is
`~/saturn-recomp/ref/beetle-saturn-libretro/mednafen_saturn_libretro.so`, and the BIOS directory is
`~/saturn-recomp/bios`. Honour assigned `SATURN_REFERENCE_CORE` and `SATURN_BIOS` overrides. Check
those locations directly; do not search the home directory or NAS for them. Missing files make the
check incomplete. Record core and BIOS hashes without copying their contents into tracked files.

Use `uv run bomberman lab verify ROUTE --from N --every N` for selected gameplay state, or
`uv run bomberman compare ROUTE --every N` for decoded pixels. Verify rejects invincibility hooks
and multitaps; the current comparison supports the two ordinary ports and matched memory writes.
An unsupported route remains incomplete. Ask the lead for a supported scenario, or a separately
scoped extension to the harness.

Runs align by the configured game's tick and time since it last changed. Disc loading, wandering
CPUs, and screens that advance on VBlanks while the tick is stopped can defeat that alignment.
State the actual alignment and any assistance. Locate the first divergence and distinguish an
initial offset from continuing drift. Keep unexplained differences visible; never add a tolerance
or remove a compared field just to produce a pass.

For hardware event ordering, use an instrumented private copy of the reference core, with a probe
the lead scoped. Preserve the canonical reference. Match the original and candidate scenarios,
and preserve event logs. Keep scratch probes out of maintained source. Frame hashes from our own
build establish regressions, while independent reference observations help judge correctness.

## Automation runner

Execute the finite command list from the lead. Common checks, from the Bomberman root, are:

```sh
uv run pytest -q
bash saturn-recomp/tools/check.sh
uv run tests/frames.py normal single battle
```

The engine script builds its instruction and runtime checks under `saturn-recomp/build/check`.
Frame tests need the prepared game and can rebuild. The lead must assign those directories and
freeze their inputs before execution. Use the requested route subset; do not widen to the full
corpus without a reason. One runner manages a parallel suite. Honour the task's compiler and
process limits, and avoid running two CPU-heavy suites together by default.

For an already-built route with a unique output directory, use:

```sh
uv run bomberman run normal --once --out build/agent-runs/TASK/automation-runner/ATTEMPT/normal
```

`--once` uses the current executable and learns no seeds. Confirm its build identity first.
Preserve stdout, stderr, and exit status with the process API or a shell command that retains the
original status. Apply the assigned timeout and terminate only the processes this task started.
Check logs for guest fatal errors and missing expected output even when the process exits zero.
Report missing tools, disc preparation, or reference data to the lead. Stop diagnosis at the
smallest useful reproduction; fixes, seed discovery, and baseline updates belong to the lead.

## Lead review and pilot

Before accepting a result, inspect the cited artifacts, confirm identities stayed fixed, and check
that the conclusion matches the observations. Run a focused reproduction for a reported defect.
Workers report findings, and the lead owns permanent tests and fixes. An independent test-gaps
audit can use a fresh generic agent with that skill and an explicit diff, outside these three roles.

Start with a function batch, a supported reference route, and an automation suite on a stable
snapshot. Save assignments and results under `build/agent-runs/`. Record wall time, usage when the
client exposes it, retries, useful findings, and lead corrections. Compare with the same work
performed in one session before changing model defaults or adding more roles.

Check the workflow itself before using it for unattended work:

| Check | Expected result | Level |
| --- | --- | --- |
| Load native definitions | Both clients recognise three named agents and their effort settings | Client configuration |
| Delegate with missing ownership | Worker inspects read-only and requests the missing assignment before execution | Scenario |
| Validate dirty engine work in a clean slot | Worker reports the source mismatch before accepting results | Scenario |
| Run unsupported reference route | Worker reports incomplete and names the unsupported setup | Scenario |
| Compare selected function vectors | Worker reports filtered cases and limits interpreter-agreement claims | Scenario |
| Read a successful process with a fatal guest error or missing output | Worker reports failure or incomplete evidence | Scenario |
| Assign two fixed-output suites in one checkout | Lead serialises them or gives them isolated directories and inputs | Scenario |

Native definitions follow [Claude Code's subagent documentation](https://code.claude.com/docs/en/sub-agents)
and the [official OpenAI documentation](https://learn.chatgpt.com/docs/agent-configuration/subagents).
