# Legacy Entry Archive

This file records high-value entry points, workflow notes, and migration destinations that used to live in README files, so they do not disappear during later cleanup.
If you just need the current entry points, start with [getting-started.md](getting-started.md) or [catalog.md](catalog.md).

## Preservation Rules
- Keep a record of content that still matters, but should no longer stay in a README body.
- If content moved, record the destination clearly.
- If GitHub currently only keeps an entry page or handoff page, say that explicitly.

## Preserved Repository-Level Entry Points

| Source | Preserved value | Current destination | Notes |
| --- | --- | --- | --- |
| Root `README.md` | Quick clone / submodule sync flow | Root README `Quick Download` section | The old static tree is not restored |
| Root `README.md` | Customer Help Center | Root README `Common Entry Points` section | Kept as a high-value external entry |
| Root `README.md` | Motor Firmware Mirror | Root README `Common Entry Points` section | Kept as a high-value external entry |
| Root `README.md` | GitHub / Gitee coverage explanation | [mirror-scope.md](mirror-scope.md) | mirror differences are now public and centralized |

## Completed README Migrations

| Source | Current destination | Notes |
| --- | --- | --- |
| `0.Firmware/Firmware/README.md` | `FIRMWARE-NOTES.md` | firmware version notes and upgrade cautions migrated |
| `5.Control Examples/Motor Control Examples/Matlab例程/README.md` | `USAGE.md` | Matlab workflow migrated |
| `5.Control Examples/Motor Control Examples/stm32例程/dm_ctrl(f4)-4310_v1.0 裸机/README.md` | `USAGE.md` | STM32 bare-metal setup and runtime flow migrated |
| `5.Control Examples/Motor Control Examples/orin载板can控制达妙电机例程/README.md` | `USAGE.md` | install, build, CAN setup, and 1M / 5M flow migrated |
| `5.Control Examples/Motor Control Examples/C++例程/u2can/README.md` | `USAGE.md` | C++ usage flow migrated |
| `5.Control Examples/Motor Control Examples/Python例程/u2can/README.md` | `USAGE.md` | Python usage flow migrated |
| `5.Control Examples/Motor Control Examples/C++例程/u2canfd/README.md` | `WORKFLOW.md` | build and runtime flow migrated |
| `5.Control Examples/Motor Control Examples/Python例程/u2canfd/README.md` | `WORKFLOW.md` | device detection and control flow migrated |
| `5.Control Examples/Motor Control Examples/ROS1 例程/README.md` | `USAGE.md` | ROS1 setup, adapter selection, and multi-motor notes migrated |
| `6.Control Boards/orin-board/README.md` | `USAGE.md` | flashing, device tree, CSI, UART, Wi-Fi, and CAN workflows migrated |
| `6.Control Boards/dm-mc01/README.md` | `USAGE.md` | board usage flow migrated |
| `6.Control Boards/dm-mc02/README.md` | `USAGE.md` | board usage flow migrated |
| `6.Control Boards/orin-board/dm_orin_board_public_information/使能UART方法/README.md` | `USAGE.md` | UART enable workflow migrated |
| `6.Control Boards/orin-board/dm_orin_board_public_information/Jetson_Orin_CSI_Camera_Support/README.md` | `USAGE.md` | CSI camera adaptation workflow migrated |
| `6.Control Boards/orin-board/orin载板can控制达妙电机例程/README.md` | `USAGE.md` | Orin carrier CAN control workflow migrated |
| `8.Tools and Host Software/dm-tools/USB2CANFD/README.md` | `SETUP.md` | install, run, and permission flow migrated |
| `8.Tools and Host Software/dm-tools/USB2CANFD/Host Applications/README.md` | `SETUP.md` | host software setup flow migrated |
| `8.Tools and Host Software/dm-tools/USB2CANFD/固件/socketcan/slcan固件/README.md` | `FLASHING.md` | firmware flashing and CAN switching flow migrated |
| `8.Tools and Host Software/dm-tools/USB2CANFD/SDK/C++/arm/README.md` | `PLATFORM.md` | arm SDK build and runtime flow migrated |
| `8.Tools and Host Software/dm-tools/USB2CANFD/SDK/C++/ubuntu/README.md` | `PLATFORM.md` | Ubuntu SDK build and runtime flow migrated |
| `8.Tools and Host Software/dm-tools/USB2CANFD/SDK/C++/win/README.md` | `PLATFORM.md` | Windows SDK toolchain and runtime flow migrated |
| `8.Tools and Host Software/dm-tools/USB2CANFD/SDK/Python/README.md` | `USAGE.md` | Python SDK setup, permissions, and control flow migrated |

## GitHub Top-Level Path Migration

GitHub now uses English top-level category paths in `dmBot`, while Gitee keeps Chinese top-level category paths in `damiao`.
If you need the full mapping, use [path-mapping.md](path-mapping.md). The compatibility summary below keeps the most common entry changes visible.

| Older GitHub path | Current GitHub path | Notes |
| --- | --- | --- |
| `0.固件` | `0.Firmware` | category path renamed in GitHub only |
| `1.关节电机` | `1.Joint Motors` | category path renamed in GitHub only |
| `5.控制例程` | `5.Control Examples` | category path renamed in GitHub only |
| `6.控制板` | `6.Control Boards` | category path renamed in GitHub only |
| `8.工具和上位机` | `8.Tools and Host Software` | category path renamed in GitHub only |
| `0.Firmware/固件` | `0.Firmware/Firmware` | GitHub submodule path renamed to finish the English-facing subtree path |
| `5.Control Examples/电机控制例程` | `5.Control Examples/Motor Control Examples` | GitHub submodule path renamed to finish the English-facing subtree path |
| `9.User Manuals/文档` | `9.User Manuals/Documentation` | GitHub submodule path renamed to finish the English-facing subtree path |

## GitHub Resource Directory Migration

GitHub now also uses English names for common resource-only directories inside the migrated public subrepos.
Gitee keeps the original Chinese directory names for those same resource folders.

| Older GitHub resource directory | Current GitHub resource directory | Notes |
| --- | --- | --- |
| `说明书/` | `Manual/` | customer-facing manual folder |
| `2D图纸/` | `2D Drawings/` | mechanical drawing folder |
| `3D模型/` | `3D Models/` | integration model folder |
| `性能曲线/` | `Performance Curves/` | general performance-curve folder |
| `电机特性曲线/` | `Motor Characteristic Curves/` | motor-characteristic curve folder |
| `效率曲线/` | `Efficiency Curves/` | efficiency-curve folder |
| `转接板/` | `Adapter Boards/` | adapter-board resource folder |
| `最大过载时间/` | `Maximum Overload Duration/` | overload-duration reference folder |
| `最大过载曲线/` | `Maximum Overload Curves/` | overload-curve resource folder |
| `固件/` | `Firmware/` | GitHub subtree folder renamed where the directory is purely a public material entry |
| `文档/` | `Documentation/` | GitHub subtree folder renamed where the directory is purely a public material entry |
| `电机控制例程/` | `Motor Control Examples/` | GitHub subtree folder renamed where the directory is the public example entry |
| `上位机/` | `Host Applications/` | GitHub host-software entry folder renamed in mirrored tool paths |
| `3D文件/` | `3D Files/` | board-material resource folder |
| `数据手册/` | `Datasheets/` | board-material resource folder |
| `原理图/` | `Schematics/` | board-material resource folder |
| `客户外壳文件/` | `Customer Enclosure Files/` | board-material resource folder |
| `LCD模块/` | `LCD Module/` | board-material resource folder |
| `3D外壳/` | `3D Enclosure/` | board-material resource folder |
| `封装库-仅供参考/` | `Package Library - Reference Only/` | board-material reference folder |
| `01.模型及图纸/` | `01.Models and Drawings/` | IMU public-material folder |
| `03.上位机/` | `03.Host Software/` | IMU host-software folder |
| `使能UART方法/` | `Enable UART/` | Orin public-information folder |
| `USB3.0设备树修改/` | `USB3.0 Device Tree Changes/` | Orin guest-source support folder |
| `XML文件/` | `XML Files/` | tool support-material folder |
| `模块配置工具/` | `Module Configuration Tool/` | tool support-material folder |
| `通讯协议/` | `Communication Protocol/` | tool support-material folder |
| `2D标注/` | `2D Annotations/` | Orin v1 public-information drawing folder |
| `弃用的/` | `Deprecated/` | IMU host-software archive folder |
| `网友分享-开源外壳/` | `Community Open-Source Enclosure/` | community-contributed enclosure resource folder |
| `V3开源外壳/` | `V3 Open-Source Enclosure/` | USB-to-CAN V3 enclosure resource folder |
| `IMU BMI088模块/` | `IMU BMI088 Module/` | board support-material folder |
| `CAN功能测试/` | `CAN Function Test/` | Orin guest-source CAN note folder |
| `客户自制外壳/` | `Customer-made Enclosure/` | Orin guest-source enclosure resource folder |

## Public Handoff Notes
- `8.Tools and Host Software/dm-tools/DM_DeviceSDK/README.md` now serves as a public GitHub handoff page; the full SDK tree remains Gitee-first.
- `8.Tools and Host Software/dm-tools/USB2CANFD_Dual/README.md` and `固件/socketcan/README.md` now explicitly describe the mirrored scope and Gitee handoff.
- `B.Canopen/README.md` and `B.Canopen/Canopen/README.md` now keep the GitHub-side category entry and handoff; the fuller public package remains Gitee-first.
