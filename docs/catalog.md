# Repository Catalog

If this is your first visit, start with [getting-started.md](getting-started.md).  
This file answers only one question: where the real folders and subtree paths are.

Notes:
- `ZH` = content is mainly Chinese
- `EN` = content is mainly English
- `TBD` = content or translation is not complete yet

This catalog records only the real folders and subtree paths that currently exist in the workspace. If a path changes, update this file first and only then update higher-level entry pages.

## 0. Firmware

- Status: `ZH`
- Path: `0.固件/固件`
- Notes: firmware packages, update logs, and firmware notes.

## 1. Joint Motors

- Status: `ZH / EN partial`
- Path:
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
- Notes: product materials live inside each model folder.

## 2. Hollow Motors

- Status: `ZH`
- Path: `2.中空电机/DM-G6220`
- Notes: hollow-motor entry point.

## 3. Hub Motors

- Status: `ZH / EN partial`
- Path:
  - `3.轮毂电机/DM-H3510`
  - `3.轮毂电机/DM-H6215`
  - `3.轮毂电机/DM-H65-1EC`
- Notes: keep the real paths here instead of rebuilding an old static tree in the root README.

## 4. Discrete Series

- Status: `ZH`
- Path:
  - `4.分立系列/DM-S2325-1EC`
  - `4.分立系列/DM-S3519-1EC`
- Notes: product-material index, not a marketing page.

## 5. Control Examples

- Status: `ZH / EN partial`
- Path: `5.控制例程/电机控制例程`
- Notes: examples are maintained by language and runtime; customers should start with the category README before opening a specific example.

## 6. Control Boards

- Status: `ZH / EN partial`
- Path:
  - `6.控制板/dm-imu`
  - `6.控制板/dm-mc01`
  - `6.控制板/dm-mc02`
  - `6.控制板/orin-board`
  - `6.控制板/spine`
- Notes: board names are part of the public path and should stay stable.

## 7. Motor Drive Board

- Status: `ZH / EN partial`
- Path: `7.电机驱动板/motor-drive-board`
- Notes: currently kept as a single navigation node.

## 8. Tools and Host Software

- Status: `ZH / EN partial`
- Path: `8.工具和上位机/dm-tools`
- Notes: customer-facing USB2CANFD, host-software, `slcan`, and SDK paths start from `dm-tools`; broader tool branches may still hand off to Gitee.

## 9. User Manuals

- Status: `ZH`
- Path: `9.使用手册/文档`
- Notes: manuals and support-material entry point.

## 10. Direct Drive Motors

- Status: `ZH / EN partial`
- Path:
  - `10.直驱电机/DM-D5730-1EC`
  - `10.直驱电机/DM-D5730-1EE`
- Notes: different variants in the same series stay side by side.

## 11. Harmonic Motors

- Status: `ZH`
- Path: `11.谐波电机/DM-JH11-51_101-2EC`
- Notes: keep only the model path that truly exists.

## B. Canopen

- Status: `ZH / EN handoff`
- Path: `B.Canopen/Canopen`
- Notes: GitHub keeps the category entry and handoff page, while the fuller public package currently remains Gitee-first.

## A. Open-Source Series

- Status: `ZH / EN partial`
- Path:
  - `A.达妙开源系列/agv`
  - `A.达妙开源系列/bipedal-robot`
  - `A.达妙开源系列/wheel-legged`
- Notes: open-source projects are maintained in their own subtree repos and currently remain outside the active sync scope.

## Repository-Difference Notes

- Gitee and GitHub may keep real repository-level differences, but the reason must be documented in `docs/sync-policy.md`.
- Do not put path drift or historical aliases back into the root README. Keep those rules in the sync policy.
