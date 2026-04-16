# README Guideline

This file defines the standard subtree README format. The validated template under `1.关节电机`, and any future subtree copy, should follow it.

## Standard Structure

1. `Overview`
2. `Documentation / Resources`
3. `Quick Start`
4. `Status`

## Section Responsibilities

- `Overview`: only give entry-level context. Answer what the folder is. Do not turn it into a full product manual or spec sheet.
- `Documentation / Resources`: list only real directories, files, or external docs that actually exist. Path text must match the repository's canonical path.
- `Quick Start`: optional in depth, but keep the section when it helps. If there is no independent quick-start flow, say so in one sentence.
- `Status`: must show translation state. Use `ZH`, `EN`, and `TBD`, or `Translation pending` when English text is incomplete.

## Language Policy

- Gitee is Chinese-first and uses Chinese in `README.md`.
- GitHub is English-first and uses English in `README.md`.
- Add a language-switch line directly under the H1: Gitee uses `中文 | [EN](./README.en.md)`, while GitHub uses `[EN](./README.md) | [中文](./README.zh.md)`, with a cross-repo link when it helps.
- `README.en.md` is the lightweight English companion for Gitee Chinese-first pages, not a second full README.
- `README.zh.md` is the lightweight Chinese companion for GitHub English-first pages; if the fuller Chinese entry remains Gitee-first, state that handoff explicitly.
- Incomplete English content must stay as `TBD` or `Translation pending`.
- Do not invent Chinese or English content to fill a gap.

## Migration Rules

- If a README contains download instructions, submodule clone/update steps, firmware entry links, customer help center links, branch-switching notes, flashing steps, device-tree changes, CSI / UART / Wi-Fi configuration, environment setup, external references, real usage instructions, or repository maintenance notes, do not delete them directly.
- Move the detailed content into `USAGE.md`, `WORKFLOW.md`, `SETUP.md`, `FLASHING.md`, or `docs/usage.md`, and leave a short jump link in the README.
- If the content is a historical entry rather than a current workflow, record it first in `docs/legacy-links.md`.
- README should stay as an entry page with helpful jumps, not a long-form manual.
- When a folder contains both entry notes and workflow notes, keep the entry in README and move the workflow out.

## Forbidden

- Do not keep `xxxx`, `Gitee Feature`, `Software Architecture`, `Installation`, `Instructions`, `Contribution`, or similar boilerplate.
- Do not copy an old README wholesale and patch it piecemeal.
- Do not invent product capabilities, parameters, compatibility, or step-by-step procedures.
- Do not reference folders or documents that do not exist, and do not use non-canonical path text.

## Copyable Template

```md
# <MODEL-NAME>

## Overview
- This folder is the documentation entry for <MODEL-NAME>.

## Documentation / Resources
- [Manual/](说明书/)
- [2D Drawings/](2D图纸/)
- [3D Model/](3D模型/)
- [Performance Curves/](性能曲线/)
- [USAGE.md](USAGE.md) (if a workflow doc has been split out)

## Quick Start
- This folder does not define a separate quick-start flow.

## Status
- EN: main entry
- ZH: source material exists in this subtree
- TBD: unverified details remain pending
```

## Usage Rules

- If a folder has a real technical note, put it in `Overview` and keep it entry-level.
- If a resource folder does not exist, do not list it.
- If a single sentence is enough, use a single sentence.
- If a workflow doc exists, keep the jump in README and do not delete the value content without migration.
- After changing a subtree README, check `docs/sync-policy.md` before merging.
