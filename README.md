# DAMIAO

[EN](./README.md) | [中文](./README.zh.md) | [Gitee 中文](https://gitee.com/kit-miao/damiao/blob/master/README.md)

This is the GitHub-facing documentation mirror for DAMIAO.  
Its job is not to hold every manual inline, but to help customers quickly answer: what this repository is, how to download it, where to find materials, and where detailed workflows live.

## Project Overview

- GitHub is the English-facing showcase repository.
- Detailed materials stay in the subtree repositories and workflow pages.
- When a README only keeps an entry summary, the detailed steps usually live in `USAGE.md`, `WORKFLOW.md`, `SETUP.md`, `FLASHING.md`, or `PLATFORM.md`.

## First Visit

1. Start with [docs/getting-started.md](docs/getting-started.md)  
   It explains where to start, how to find materials by category, and how to read the document layers.
2. Then open [docs/mirror-scope.md](docs/mirror-scope.md)  
   It explains what GitHub mirrors directly, what still mainly lives in Gitee, and what to do when a path looks incomplete.
3. Then open [docs/catalog.md](docs/catalog.md)  
   This is the canonical index of current paths and subtrees.
4. Then enter the relevant category README  
   For example:
   - [1.关节电机/README.md](1.关节电机/README.md)
   - [5.控制例程/README.md](5.控制例程/README.md)
   - [6.控制板/README.md](6.控制板/README.md)
   - [8.工具和上位机/README.md](8.工具和上位机/README.md)

## Quick Download

### Clone The Full Repository

```bash
git clone https://github.com/dmBots/dmBot.git
cd dmBot
git submodule init
git submodule update --recursive --remote
```

### Use A Single Subtree

- Locate the relevant subtree in this repository first.
- Then follow that subtree's own README and workflow pages for the latest instructions.

## Common Entry Points

- [Customer Help Center](https://gl1po2nscb.feishu.cn/wiki/MZ32w0qnnizTpOkNvAZcJ9SlnXb)
- [Motor Firmware Mirror](https://github.com/dmBots/motor-firmware)

## Common Material Paths

- [1.关节电机](1.关节电机/README.md)  
  Find materials by motor model.
- [5.控制例程](5.控制例程/README.md)  
  Find examples by language, platform, and runtime.
- [6.控制板](6.控制板/README.md)  
  Find control-board, IMU, and Orin carrier documents.
- [8.工具和上位机](8.工具和上位机/README.md)  
  Download USB2CANFD tools, run the host software, flash `slcan` firmware, and choose the right SDK entry from here. If the GitHub mirror looks incomplete, follow [docs/mirror-scope.md](docs/mirror-scope.md).

## Documentation Entry

- [docs/getting-started.md](docs/getting-started.md) - best first stop for customers
- [docs/README.md](docs/README.md) - documentation hub
- [docs/catalog.md](docs/catalog.md) - current folder and subtree index
- [docs/mirror-scope.md](docs/mirror-scope.md) - what is mirrored in GitHub vs. what remains Gitee-first
- [docs/doc-structure.md](docs/doc-structure.md) - document-layer model and public-readiness check
- [docs/legacy-links.md](docs/legacy-links.md) - historical high-value entry archive
- [docs/sync-policy.md](docs/sync-policy.md) - cross-repository sync rules

## Language Policy

- Keep this repository English-first.
- Preserve real folder names and path segments, even when they are Chinese.
- Use `TBD` or `Translation pending` for missing English content.
- Do not fill missing content with guessed wording.

## Contribution

- Read [CONTRIBUTING.md](CONTRIBUTING.md) before opening a change.
- If a change touches a path, folder name, or subtree entry, update [docs/catalog.md](docs/catalog.md) and [docs/sync-policy.md](docs/sync-policy.md) in the same change set.
