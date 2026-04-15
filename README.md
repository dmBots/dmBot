# DAMIAO

English-first entry point for the DAMIAO documentation mirror. This repository is intentionally thin: product details live in the sub-repositories, while this repo keeps navigation, cataloging, and governance.

## Project Overview

- GitHub is the English-facing showcase repository.
- Some subtree documents are already bilingual, while others are still Chinese-only or partially translated.
- Missing English content must stay as `TBD` or `Translation pending`; do not guess or fabricate it.

## Quick Download

1. If you want the full mirror, clone the parent repository and then sync all submodules.

```c
git clone https://github.com/dmBots/dmBot.git
cd dmBot/
git submodule init
git submodule update --recursive --remote
```

2. If you only need one subtree, enter that folder and clone or sync it on its own.

```c
git clone <url>
```

3. After entering a submodule, check its own README and document index for the latest workflow notes.

## Common Entry Points

- [Customer Help Center](https://gl1po2nscb.feishu.cn/wiki/MZ32w0qnnizTpOkNvAZcJ9SlnXb)
- [Motor Firmware Mirror](https://github.com/dmBots/motor-firmware)

## Repository Scope

Current top-level areas in this repository:

- `0.固件/固件`
- `1.关节电机/DM-J10010-2EC`
- `1.关节电机/DM-J10010L-2EC`
- `1.关节电机/DM-J3507-2EC`
- `1.关节电机/DM-J4310-2EC`
- `1.关节电机/DM-J4310P-2EC`
- `1.关节电机/DM-J4340-2EC`
- `1.关节电机/DM-J4340P-2EC`
- `1.关节电机/DM-J6006-2EC`
- `1.关节电机/DM-J6248P-2EC`
- `1.关节电机/DM-J8006-2EC`
- `1.关节电机/DM-J8009-2EC`
- `1.关节电机/DM-J8009P-2EC`
- `2.中空电机/DM-G6220`
- `3.轮毂电机/DM-H3510`
- `3.轮毂电机/DM-H6215`
- `3.轮毂电机/DM-H65-1EC`
- `4.分立系列/DM-S2325-1EC`
- `4.分立系列/DM-S3519-1EC`
- `5.控制例程/电机控制例程`
- `6.控制板/dm-mc01`
- `6.控制板/dm-mc02`
- `6.控制板/orin-board`
- `6.控制板/spine`
- `6.控制板/dm-imu`
- `7.电机驱动板/motor-drive-board`
- `8.工具和上位机/dm-tools`
- `9.使用手册/文档`
- `10.直驱电机/DM-D5730-1EC`
- `10.直驱电机/DM-D5730-1EE`
- `11.谐波电机/DM-JH11-51_101-2EC`
- `A.达妙开源系列/agv`
- `A.达妙开源系列/bipedal-robot`
- `A.达妙开源系列/wheel-legged`

## Documentation Entry

- [docs/README.md](docs/README.md)
- [docs/catalog.md](docs/catalog.md)
- [docs/sync-policy.md](docs/sync-policy.md)

## Repository Catalog

See [docs/catalog.md](docs/catalog.md) for the current folder and submodule index. The catalog is the canonical source for paths and status notes.

## Language Policy

- Keep this repository English-first.
- Preserve real folder names and path segments, even when they are Chinese.
- Use `TBD` or `Translation pending` for missing English content.
- Do not backfill untranslated sections with guessed wording.

## Contribution

- Read [CONTRIBUTING.md](CONTRIBUTING.md) before opening a change.
- Use [`.github/pull_request_template.md`](.github/pull_request_template.md) when submitting a PR.
- If a change touches a path, folder name, or submodule entry, update [docs/catalog.md](docs/catalog.md) and [docs/sync-policy.md](docs/sync-policy.md) in the same change set.

## Status / Notes

- This page is intentionally a thin entry point, not a full manual.
- Any path drift should be fixed in [docs/catalog.md](docs/catalog.md) first.
- Repository-specific gaps should stay marked as `TBD` until verified.
