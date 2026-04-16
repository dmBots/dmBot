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
| `A.Open Source Series` | `A.达妙开源系列` | `A.达妙开源系列` | GitHub now uses an English top-level path; Gitee keeps the Chinese path |

## Common Cross-Repository Examples

| What you want | GitHub path | Gitee path |
| --- | --- | --- |
| Firmware entry | `0.Firmware/Firmware/README.md` | `0.固件/固件/README.md` |
| Firmware subtree root | `0.Firmware/Firmware/` | `0.固件/固件/` |
| Joint motor entry | `1.Joint Motors/README.md` | `1.关节电机/README.md` |
| Control examples entry | `5.Control Examples/README.md` | `5.控制例程/README.md` |
| Motor control examples subtree | `5.Control Examples/Motor Control Examples/` | `5.控制例程/电机控制例程/` |
| Orin board entry | `6.Control Boards/orin-board/README.md` | `6.控制板/orin-board/README.md` |
| Tools entry | `8.Tools and Host Software/README.md` | `8.工具和上位机/README.md` |
| `dm-tools` entry | `8.Tools and Host Software/dm-tools/README.md` | `8.工具和上位机/dm-tools/README.md` |
| `USB2CANFD` entry | `8.Tools and Host Software/dm-tools/USB2CANFD/README.md` | `8.工具和上位机/dm-tools/USB2CANFD/README.md` |
| `USB2CANFD` host software entry | `8.Tools and Host Software/dm-tools/USB2CANFD/Host Applications/README.md` | `8.工具和上位机/dm-tools/USB2CANFD/上位机/README.md` |
| User-manual subtree | `9.User Manuals/Documentation/` | `9.使用手册/文档/` |
| `DM_DeviceSDK` handoff | `8.Tools and Host Software/dm-tools/DM_DeviceSDK/README.md` | `8.工具和上位机/dm-tools/DM_DeviceSDK/README.md` |
| Open-source series entry | `A.Open Source Series/agv` | `A.达妙开源系列/AGV` |

## Common Resource Directory Mapping

GitHub now uses English resource-directory names inside the migrated public subrepos.
Gitee keeps the matching Chinese resource-directory names.

| GitHub resource directory | Older GitHub resource directory | Gitee resource directory |
| --- | --- | --- |
| `Manual/` | `说明书/` | `说明书/` |
| `2D Drawings/` | `2D图纸/` | `2D图纸/` |
| `3D Models/` | `3D模型/` | `3D模型/` |
| `Performance Curves/` | `性能曲线/` | `性能曲线/` |
| `Motor Characteristic Curves/` | `电机特性曲线/` | `电机特性曲线/` |
| `Efficiency Curves/` | `效率曲线/` | `效率曲线/` |
| `Adapter Boards/` | `转接板/` | `转接板/` |
| `Maximum Overload Duration/` | `最大过载时间/` | `最大过载时间/` |
| `Maximum Overload Curves/` | `最大过载曲线/` | `最大过载曲线/` |
| `Firmware/` | `固件/` | `固件/` |
| `Documentation/` | `文档/` | `文档/` |
| `Motor Control Examples/` | `电机控制例程/` | `电机控制例程/` |
| `Host Applications/` | `上位机/` | `上位机/` |
| `3D Files/` | `3D文件/` | `3D文件/` |
| `Datasheets/` | `数据手册/` | `数据手册/` |
| `Schematics/` | `原理图/` | `原理图/` |
| `Customer Enclosure Files/` | `客户外壳文件/` | `客户外壳文件/` |
| `LCD Module/` | `LCD模块/` | `LCD模块/` |
| `3D Enclosure/` | `3D外壳/` | `3D外壳/` |
| `Package Library - Reference Only/` | `封装库-仅供参考/` | `封装库-仅供参考/` |
| `01.Models and Drawings/` | `01.模型及图纸/` | `01.模型及图纸/` |
| `03.Host Software/` | `03.上位机/` | `03.上位机/` |
| `Enable UART/` | `使能UART方法/` | `使能UART方法/` |
| `USB3.0 Device Tree Changes/` | `USB3.0设备树修改/` | `USB3.0设备树修改/` |
| `XML Files/` | `XML文件/` | `XML文件/` |
| `Module Configuration Tool/` | `模块配置工具/` | `模块配置工具/` |
| `Communication Protocol/` | `通讯协议/` | `通讯协议/` |
| `2D Annotations/` | `2D标注/` | `2D标注/` |
| `Deprecated/` | `弃用的/` | `弃用的/` |
| `Community Open-Source Enclosure/` | `网友分享-开源外壳/` | `网友分享-开源外壳/` |
| `V3 Open-Source Enclosure/` | `V3开源外壳/` | `V3开源外壳/` |
| `IMU BMI088 Module/` | `IMU BMI088模块/` | `IMU BMI088模块/` |
| `CAN Function Test/` | `CAN功能测试/` | `CAN功能测试/` |
| `Customer-made Enclosure/` | `客户自制外壳/` | `客户自制外壳/` |

## Compatibility Notes

- Older GitHub links or bookmarks that still use the former Chinese top-level category path should be treated as retired.
- Older GitHub links or bookmarks that still point to Chinese resource-directory names inside a migrated subrepo should also be treated as retired.
- Re-enter the repository from the root [README.md](../README.md), [getting-started.md](getting-started.md), or [catalog.md](catalog.md) if a copied path no longer matches.
- If the GitHub path exists only as an entry layer or handoff page, continue through [mirror-scope.md](mirror-scope.md) instead of guessing a deeper path.
