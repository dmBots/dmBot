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
| `0.固件/固件/README.md` | `FIRMWARE-NOTES.md` | firmware version notes and upgrade cautions migrated |
| `5.控制例程/电机控制例程/Matlab例程/README.md` | `USAGE.md` | Matlab workflow migrated |
| `5.控制例程/电机控制例程/stm32例程/dm_ctrl(f4)-4310_v1.0 裸机/README.md` | `USAGE.md` | STM32 bare-metal setup and runtime flow migrated |
| `5.控制例程/电机控制例程/orin载板can控制达妙电机例程/README.md` | `USAGE.md` | install, build, CAN setup, and 1M / 5M flow migrated |
| `5.控制例程/电机控制例程/C++例程/u2can/README.md` | `USAGE.md` | C++ usage flow migrated |
| `5.控制例程/电机控制例程/Python例程/u2can/README.md` | `USAGE.md` | Python usage flow migrated |
| `5.控制例程/电机控制例程/C++例程/u2canfd/README.md` | `WORKFLOW.md` | build and runtime flow migrated |
| `5.控制例程/电机控制例程/Python例程/u2canfd/README.md` | `WORKFLOW.md` | device detection and control flow migrated |
| `5.控制例程/电机控制例程/ROS1 例程/README.md` | `USAGE.md` | ROS1 setup, adapter selection, and multi-motor notes migrated |
| `6.控制板/orin-board/README.md` | `USAGE.md` | flashing, device tree, CSI, UART, Wi-Fi, and CAN workflows migrated |
| `6.控制板/dm-mc01/README.md` | `USAGE.md` | board usage flow migrated |
| `6.控制板/dm-mc02/README.md` | `USAGE.md` | board usage flow migrated |
| `6.控制板/orin-board/dm_orin_board_public_information/使能UART方法/README.md` | `USAGE.md` | UART enable workflow migrated |
| `6.控制板/orin-board/dm_orin_board_public_information/Jetson_Orin_CSI_Camera_Support/README.md` | `USAGE.md` | CSI camera adaptation workflow migrated |
| `6.控制板/orin-board/orin载板can控制达妙电机例程/README.md` | `USAGE.md` | Orin carrier CAN control workflow migrated |
| `8.工具和上位机/dm-tools/USB2CANFD/README.md` | `SETUP.md` | install, run, and permission flow migrated |
| `8.工具和上位机/dm-tools/USB2CANFD/上位机/README.md` | `SETUP.md` | host software setup flow migrated |
| `8.工具和上位机/dm-tools/USB2CANFD/固件/socketcan/slcan固件/README.md` | `FLASHING.md` | firmware flashing and CAN switching flow migrated |
| `8.工具和上位机/dm-tools/USB2CANFD/SDK/C++/arm/README.md` | `PLATFORM.md` | arm SDK build and runtime flow migrated |
| `8.工具和上位机/dm-tools/USB2CANFD/SDK/C++/ubuntu/README.md` | `PLATFORM.md` | Ubuntu SDK build and runtime flow migrated |
| `8.工具和上位机/dm-tools/USB2CANFD/SDK/C++/win/README.md` | `PLATFORM.md` | Windows SDK toolchain and runtime flow migrated |
| `8.工具和上位机/dm-tools/USB2CANFD/SDK/Python/README.md` | `USAGE.md` | Python SDK setup, permissions, and control flow migrated |

## Public Handoff Notes
- `8.工具和上位机/dm-tools/DM_DeviceSDK/README.md` now serves as a public GitHub handoff page; the full SDK tree remains Gitee-first.
- `8.工具和上位机/dm-tools/USB2CANFD_Dual/README.md` and `固件/socketcan/README.md` now explicitly describe the mirrored scope and Gitee handoff.
- `B.Canopen/README.md` and `B.Canopen/Canopen/README.md` now keep the GitHub-side category entry and handoff; the fuller public package remains Gitee-first.
