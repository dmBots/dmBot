# GitHub And Gitee Path Mapping

If you just need the current GitHub entry points, start with [getting-started.md](getting-started.md) or [catalog.md](catalog.md).
This file is specifically for cross-repository path mapping and compatibility after GitHub moved its top-level category paths to English.

## Why The Paths Differ

- Gitee remains the Chinese primary repository and keeps Chinese top-level category paths.
- GitHub is the English-facing showcase repository and now uses English top-level category paths.
- The content hierarchy and entry logic still stay aligned, but the real checkout path is repository-local.

## How To Use This File

- If you are switching from GitHub to Gitee, use the `Gitee path` column.
- If you are switching from Gitee to GitHub, use the `GitHub path` column.
- If an older GitHub bookmark still uses a former Chinese top-level path, use the `Older GitHub path` column to reopen the current location.

## Top-Level Path Mapping

| GitHub path | Older GitHub path | Gitee path | Notes |
| --- | --- | --- | --- |
| `0.Firmware` | `0.固件` | `0.固件` | firmware category |
| `1.Joint Motors` | `1.关节电机` | `1.关节电机` | joint-motor category |
| `2.Hollow Shaft Motors` | `2.中空电机` | `2.中空电机` | hollow-shaft-motor category |
| `3.Hub Motors` | `3.轮毂电机` | `3.轮毂电机` | hub-motor category |
| `4.Discrete Series` | `4.分立系列` | `4.分立系列` | discrete product series |
| `5.Control Examples` | `5.控制例程` | `5.控制例程` | example entry category |
| `6.Control Boards` | `6.控制板` | `6.控制板` | control boards, IMU, and Orin materials |
| `7.Motor Driver Boards` | `7.电机驱动板` | `7.电机驱动板` | driver-board category |
| `8.Tools and Host Software` | `8.工具和上位机` | `8.工具和上位机` | USB2CANFD, host software, firmware, and SDK entry category |
| `9.User Manuals` | `9.使用手册` | `9.使用手册` | manuals and support-material category |
| `10.Direct Drive Motors` | `10.直驱电机` | `10.直驱电机` | direct-drive motor category |
| `11.Harmonic Drive Motors` | `11.谐波电机` | `11.谐波电机` | harmonic-drive motor category |
| `B.Canopen` | `B.Canopen` | `B.Canopen` | unchanged because it is already a stable Latin technical path |
| `A.达妙开源系列` | `A.达妙开源系列` | `A.达妙开源系列` | frozen in this round and intentionally unchanged |

## Common Cross-Repository Examples

| What you want | GitHub path | Gitee path |
| --- | --- | --- |
| Firmware entry | `0.Firmware/固件/README.md` | `0.固件/固件/README.md` |
| Joint motor entry | `1.Joint Motors/README.md` | `1.关节电机/README.md` |
| Control examples entry | `5.Control Examples/README.md` | `5.控制例程/README.md` |
| Orin board entry | `6.Control Boards/orin-board/README.md` | `6.控制板/orin-board/README.md` |
| Tools entry | `8.Tools and Host Software/README.md` | `8.工具和上位机/README.md` |
| `dm-tools` entry | `8.Tools and Host Software/dm-tools/README.md` | `8.工具和上位机/dm-tools/README.md` |
| `USB2CANFD` entry | `8.Tools and Host Software/dm-tools/USB2CANFD/README.md` | `8.工具和上位机/dm-tools/USB2CANFD/README.md` |
| `DM_DeviceSDK` handoff | `8.Tools and Host Software/dm-tools/DM_DeviceSDK/README.md` | `8.工具和上位机/dm-tools/DM_DeviceSDK/README.md` |

## Compatibility Notes

- Older GitHub links or bookmarks that still use the former Chinese top-level category path should be treated as retired.
- Re-enter the repository from the root [README.md](../README.md), [getting-started.md](getting-started.md), or [catalog.md](catalog.md) if a copied path no longer matches.
- If the GitHub path exists only as an entry layer or handoff page, continue through [mirror-scope.md](mirror-scope.md) instead of guessing a deeper path.
