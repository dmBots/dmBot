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
- Path: `0.Firmware/固件`
- Notes: firmware packages, update logs, and firmware notes.

## 1. Joint Motors

- Status: `ZH / EN partial`
- Path:
  - `1.Joint Motors/DM-J10010-2EC`
  - `1.Joint Motors/DM-J10010L-2EC`
  - `1.Joint Motors/DM-J3507-2EC`
  - `1.Joint Motors/DM-J4310-2EC`
  - `1.Joint Motors/DM-J4310P-2EC`
  - `1.Joint Motors/DM-J4340-2EC`
  - `1.Joint Motors/DM-J4340P-2EC`
  - `1.Joint Motors/DM-J6006-2EC`
  - `1.Joint Motors/DM-J6248P-2EC`
  - `1.Joint Motors/DM-J8006-2EC`
  - `1.Joint Motors/DM-J8009-2EC`
  - `1.Joint Motors/DM-J8009P-2EC`
- Notes: product materials live inside each model folder.

## 2. Hollow Shaft Motors

- Status: `ZH`
- Path: `2.Hollow Shaft Motors/DM-G6220`
- Notes: hollow-shaft-motor entry point.

## 3. Hub Motors

- Status: `ZH / EN partial`
- Path:
  - `3.Hub Motors/DM-H3510`
  - `3.Hub Motors/DM-H6215`
  - `3.Hub Motors/DM-H65-1EC`
- Notes: keep the real paths here instead of rebuilding an old static tree in the root README.

## 4. Discrete Series

- Status: `ZH`
- Path:
  - `4.Discrete Series/DM-S2325-1EC`
  - `4.Discrete Series/DM-S3519-1EC`
- Notes: product-material index, not a marketing page.

## 5. Control Examples

- Status: `ZH / EN partial`
- Path: `5.Control Examples/电机控制例程`
- Notes: examples are maintained by language and runtime; customers should start with the category README before opening a specific example.

## 6. Control Boards

- Status: `ZH / EN partial`
- Path:
  - `6.Control Boards/dm-imu`
  - `6.Control Boards/dm-mc01`
  - `6.Control Boards/dm-mc02`
  - `6.Control Boards/orin-board`
  - `6.Control Boards/spine`
- Notes: board names are part of the public path and should stay stable.

## 7. Motor Driver Boards

- Status: `ZH / EN partial`
- Path: `7.Motor Driver Boards/motor-drive-board`
- Notes: currently kept as a single navigation node.

## 8. Tools and Host Software

- Status: `ZH / EN partial`
- Path: `8.Tools and Host Software/dm-tools`
- Notes: customer-facing USB2CANFD, host-software, `slcan`, and SDK paths start from `dm-tools`; broader tool branches may still hand off to Gitee.

## 9. User Manuals

- Status: `ZH`
- Path: `9.User Manuals/文档`
- Notes: manuals and support-material entry point.

## 10. Direct Drive Motors

- Status: `ZH / EN partial`
- Path:
  - `10.Direct Drive Motors/DM-D5730-1EC`
  - `10.Direct Drive Motors/DM-D5730-1EE`
- Notes: different variants in the same series stay side by side.

## 11. Harmonic Drive Motors

- Status: `ZH`
- Path: `11.Harmonic Drive Motors/DM-JH11-51_101-2EC`
- Notes: keep only the model path that truly exists.

## B. CANopen

- Status: `ZH / EN handoff`
- Path: `B.Canopen/Canopen`
- Notes: GitHub keeps the category entry and handoff page, while the fuller public package currently remains Gitee-first. The `B.Canopen` top-level path is intentionally unchanged because it is already a stable Latin technical label.

## A. Open-Source Series

- Status: `ZH / EN partial`
- Path:
  - `A.达妙开源系列/agv`
  - `A.达妙开源系列/bipedal-robot`
  - `A.达妙开源系列/wheel-legged`
- Notes: open-source projects are maintained in their own subtree repos, remain frozen in this path-migration round, and therefore keep their existing Chinese top-level path in GitHub.

## Repository-Difference Notes

- GitHub uses English top-level category paths, while Gitee keeps Chinese top-level category paths. See [path-mapping.md](path-mapping.md) for the cross-repository mapping table.
- Gitee and GitHub may keep real repository-level differences, but the reason must be documented in `docs/sync-policy.md`.
- Do not put path drift or historical aliases back into the root README. Keep those rules in the sync policy.
