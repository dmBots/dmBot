# Document Structure and Governance Matrix

If you are just trying to find materials, start with [getting-started.md](getting-started.md) or [catalog.md](catalog.md).
This file explains what each document layer is responsible for, and how governance should avoid deleting valuable information when README pages are tightened.

## Document Layers

- Root README
  Repository-level entry point. It should answer what the repository is, how to download it, and where to find help and materials.
- Category README
  Category-level entry point. It should answer which direction a customer should open first in that category.
- Subtree README
  Directory-level entry point. It should answer what the folder is, where the resources are, and where the workflow moved.
- `docs/catalog.md`
  Real folder and submodule index.
- `docs/getting-started.md`
  Customer-facing first-visit guide.
- `docs/readme-guideline.md`
  README template and migration rules.
- `docs/sync-policy.md`
  Cross-repository sync rules, canonical path rules, and review gates.
- `docs/path-mapping.md`
  Cross-repository top-level path mapping and compatibility notes for older GitHub Chinese bookmarks.
- `docs/legacy-links.md`
  Archive of historical high-value entry points and migration destinations.
- `USAGE.md` / `WORKFLOW.md` / `SETUP.md` / `FLASHING.md` / `PLATFORM.md`
  Workflow content moved out of README.

## Governance Matrix

| Type | Signals | Action | Migrate? | Destination |
| --- | --- | --- | --- | --- |
| Entry README | overview + resources + status | Keep it as an entry page and add jumps | No | - |
| Workflow README | install, build, flashing, environment, interface setup, usage steps | Move workflow details to a dedicated page and keep only entry + jump in README | Yes | Same-folder `USAGE.md` / `WORKFLOW.md` / `SETUP.md` / `FLASHING.md` / `PLATFORM.md` |
| Legacy-entry README | download notes, help center, firmware entry, branch switching, submodule sync | Keep the entry semantics and archive the history | Sometimes | `docs/legacy-links.md` |
| Boilerplate README | `xxxx`, `Gitee Feature`, `Software Architecture`, etc. | Rewrite as a proper entry page | No | - |
| Index / policy docs | catalog, guideline, sync-policy | Maintain them as canonical docs | No | - |

## Migration Loop

1. Identify which parts of a README are entry content, workflow content, and historical high-value entry points.
2. Move workflow content into a dedicated page, and archive legacy entry points when needed.
3. Leave a clear jump and destination note in README.
4. Keep `catalog`, `legacy-links`, and README jumps aligned.

## Public Readiness Check

- Can the root README answer what the repository is, how to download it, and where to find materials?
- Can `docs/README.md` answer what each document in `docs/` is for?
- Can each category README answer which direction a customer should open first?
- Can each subtree README answer what the folder is, where the resources are, and where the workflow moved?
- Is every workflow page linked from an entry page?
- Is there still any place where customers see “many docs” but do not know what to open first?

## Current Examples

- The root README keeps quick download, help-center, and firmware entry points.
- `6.Control Boards/orin-board/USAGE.md` carries flashing, device tree, CSI, UART, Wi-Fi, and CAN workflows.
- `6.Control Boards/dm-mc01/USAGE.md` and `6.Control Boards/dm-mc02/USAGE.md` carry board usage notes.
- `5.Control Examples/Motor Control Examples/orin载板can控制达妙电机例程/USAGE.md` carries install, build, and CAN setup steps.
- `A.Open Source Series` keeps project-specific subtree repos in GitHub, while the matching Gitee path remains `A.达妙开源系列`.
