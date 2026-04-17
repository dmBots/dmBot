# Contributing

Thanks for helping keep DAMIAO maintainable.  
This file consolidates contributor-facing repository rules so maintainers can determine document placement, synchronization, and README scope from one page.

## Decide The Change Layer First

| If you are changing | Put it here | Do not put it here |
| --- | --- | --- |
| Repository role, first-visit guidance, high-frequency entry paths, common questions | root `README.md` | old repo-level start pages |
| Category entry logic | that category `README.md` | long root README prose |
| Subtree entry logic | that subtree `README.md` | repo-level docs |
| Install, build, flashing, platform, runtime, or upgrade steps | folder-local `USAGE.md`, `SETUP.md`, `WORKFLOW.md`, `FLASHING.md`, `BUILD.md`, `PLATFORM.md`, `UPDATE.md`, `FIRMWARE-NOTES.md` | root README or repo-level docs |
| GitHub vs. Gitee coverage boundaries | `docs/repository/mirror-scope.md` | scattered README notes |
| English/Chinese path conversion and old bookmarks | `docs/repository/path-mapping.md` | static old-path lists in README |

## Repository Roles And Scope Boundaries

- `damiao`: Chinese primary repository and the more complete Chinese source.
- `dmBot`: English public entry repository with high-frequency English paths.
- Keep entry semantics aligned across both repositories, but allow language and coverage depth to differ.
- `orin-board` keeps its current directory and documentation pattern.
- `A.Open Source Series` is maintained in its current structure.

## README Rules

### Root README

- Answer what the repository is, where to start, how to clone, why GitHub and Gitee differ, and the common questions.
- Provide necessary repository-level guidance directly instead of spreading it across several thin pages.
- Do not push install, build, flashing, or platform steps back into the root README.

### Category And Subtree README Files

- Prefer the four-part pattern: `Overview`, `Documentation / Resources`, `Quick Start`, `Status`.
- README files are entry pages only: they should route, index, and direct readers to the next page.
- If a workflow moved into a local workflow doc, leave a clear README jump instead of deleting the path.
- If English is incomplete, mark it as `Translation pending` rather than guessing content.

## Copy Style

- Public pages should use factual, concise, user-facing language.
- Avoid internal or conversational phrases such as `this phase`, `trim`, `deep cleanup`, `where to look first`, `how to download`, or `do not guess` when a neutral statement can express the same meaning.
- README and repository-level pages should explain scope, available content, and the next link, rather than documenting internal design rationale.
- Chinese pages should remain professional and restrained. English pages should remain neutral, repository-facing, and user-facing.

## Which Repo-Level Docs Still Stay Separate

Only a small repo-level set should stay separate:

- [docs/repository/mirror-scope.md](docs/repository/mirror-scope.md)
- [docs/repository/path-mapping.md](docs/repository/path-mapping.md)
- [SECURITY.md](SECURITY.md)

If a repo-level explanation can reasonably live in root README or this file, merge it there instead of creating another thin page.

## Sync Gates

Keep both repositories aligned in meaning when a change touches:

- root README repository role, first-visit flow, high-frequency entry paths, or common questions
- `CONTRIBUTING.md`
- `SECURITY.md`
- `docs/repository/mirror-scope.md`
- `docs/repository/path-mapping.md`
- hosting-platform repository descriptions
- `.gitmodules` path or URL changes
- `.github` templates that affect contributor workflow

## Canonical Path Rules

- Reader-facing links must use the real checkout path for that repository.
- Do not republish deprecated Chinese GitHub top-level paths in README.
- Keep cross-repository path conversion in [docs/repository/path-mapping.md](docs/repository/path-mapping.md).
- If a path only exists in one repository, explain that difference instead of inventing a fake shared path.

## Before You Submit

- Keep changes clear, specific, and tied to real paths.
- Do not fill translation gaps with guessed content.
- Keep link text aligned with the real path.
- Make sure root or category README files did not grow install, build, flashing, or environment prose again.
- Keep local workflow docs reachable.
- Explain repo-specific differences instead of hiding them.

## Where To Open Issues

- Use the issue templates in `.github/ISSUE_TEMPLATE/`.
- If the problem belongs to a submodule repository, open it there instead of here.

## Pull Requests

- Use [`.github/pull_request_template.md`](.github/pull_request_template.md).
- Mention which paths changed and whether the change needs to be mirrored in the other repository.
