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
- `README.en.md` is supplemental, not a second full README.
- Incomplete English content must stay as `TBD` or `Translation pending`.
- Do not invent Chinese or English content to fill a gap.

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
- After changing a subtree README, check `docs/sync-policy.md` before merging.
