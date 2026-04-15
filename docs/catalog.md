# Repository Catalog

Legend:

- `ZH` = current content is Chinese
- `EN` = current content is English
- `TBD` = content or translation is not ready yet

This catalog reflects the current workspace layout. If a folder or submodule path changes, update this file before touching the root README text.

## 0. Firmware

- Status: `ZH`
- Path: `0.固件/固件`
- Notes: firmware packages, changelog, and firmware-specific notes.

## 1. Joint Motors

- Status: `ZH / EN partial`
- Paths:
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
- Notes: model-level docs live in each motor folder.

## 2. Hollow Motors

- Status: `ZH`
- Path: `2.中空电机/DM-G6220`
- Notes: the root README should link here, not to a hand-written subtree map.

## 3. Hub Motors

- Status: `ZH / EN partial`
- Paths:
  - `3.轮毂电机/DM-H3510`
  - `3.轮毂电机/DM-H6215`
  - `3.轮毂电机/DM-H65-1EC`
- Notes: keep the current folder names as-is; note any legacy aliases in sync policy, not here.

## 4. Discrete Series

- Status: `ZH`
- Paths:
  - `4.分立系列/DM-S2325-1EC`
  - `4.分立系列/DM-S3519-1EC`
- Notes: this section is repository data, not a marketing category.

## 5. Control Examples

- Status: `ZH / EN partial`
- Path: `5.控制例程/电机控制例程`
- Notes: keep language-specific examples in their own subtree; do not move them into the root README.

## 6. Control Boards

- Status: `ZH / EN partial`
- Paths:
  - `6.控制板/dm-mc01`
  - `6.控制板/dm-mc02`
  - `6.控制板/orin-board`
  - `6.控制板/spine`
  - `6.控制板/dm-imu`
- Notes: board names are part of the public path and should remain stable.

## 7. Motor Driver Board

- Status: `ZH / EN partial`
- Path: `7.电机驱动板/motor-drive-board`
- Notes: this category should stay a simple navigation node.

## 8. Tools and Hosts

- Status: `ZH / EN partial`
- Paths:
  - `8.工具和上位机/dm-tools`
  - `8.工具和上位机/dm-tools/USB2CANFD`
  - `8.工具和上位机/dm-tools/USB2CANFD_Dual`
  - `8.工具和上位机/dm-tools/USB转CAN`
- Notes: if a nested tool subtree is not present in a later checkout, mark it `TBD` instead of guessing.

## 9. Manuals

- Status: `ZH`
- Path: `9.使用手册/文档`
- Notes: manuals and support materials.

## 10. Direct-Drive Motors

- Status: `ZH / EN partial`
- Paths:
  - `10.直驱电机/DM-D5730-1EC`
  - `10.直驱电机/DM-D5730-1EE`
- Notes: keep direct-drive variants together under one category.

## 11. Harmonic Motors

- Status: `ZH`
- Path: `11.谐波电机/DM-JH11-51_101-2EC`
- Notes: keep one folder per product family and avoid inventing extra levels.

## A. Open-Source Projects

- Status: `ZH / EN partial`
- Paths:
  - `A.达妙开源系列/agv`
  - `A.达妙开源系列/bipedal-robot`
  - `A.达妙开源系列/wheel-legged`
- Notes: GitHub currently mirrors only the folders present in this repo.

## Repository-Specific Notes

- `B.Canopen` is not present in this repository.
- If a legacy alias exists in `.gitmodules`, record it in `docs/sync-policy.md` rather than reintroducing it in the root README.
