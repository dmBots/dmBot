# Repository Coverage And Mirror Scope

## Repository Roles
- Gitee is the Chinese primary repository and currently the most complete public source.
- GitHub is the English-facing public mirror / showcase repository. Its entry structure, navigation logic, and common customer paths should stay aligned with Gitee, but detailed coverage can lag behind Gitee.

## Path Model
- GitHub now uses English top-level category paths such as `0.Firmware`, `1.Joint Motors`, `5.Control Examples`, `6.Control Boards`, and `8.Tools and Host Software`.
- Gitee keeps Chinese top-level category paths such as `0.固件`, `1.关节电机`, `5.控制例程`, `6.控制板`, and `8.工具和上位机`.
- GitHub now also uses English public subtree paths where the folder is a customer-facing entry or resource directory, such as `0.Firmware/Firmware`, `5.Control Examples/Motor Control Examples`, `9.User Manuals/Documentation`, `USB2CANFD/Host Applications`, `USB-to-CAN/Communication Protocol`, and `DM-LinkX-4C/XML Files`.
- In migrated GitHub subrepos, common resource-only folders also use English names such as `Manual/`, `2D Drawings/`, `3D Models/`, and `Performance Curves/`, while Gitee keeps the matching Chinese folders.
- When you need to map GitHub paths to the matching Gitee paths, or an older GitHub bookmark still uses the former Chinese top-level path, use [path-mapping.md](path-mapping.md).

## What Customers Should Find In Both Repositories
- The high-value entry points in the root README.
- The `docs/` layer: getting started, catalog, document structure, legacy archive, README rules, sync policy, and mirror-scope explanation.
- Entry-layer navigation for high-frequency paths, especially `0.Firmware`, `1.Joint Motors`, `5.Control Examples`, `6.Control Boards`, and `8.Tools and Host Software` in GitHub, with matching Chinese paths in Gitee.
- Under `8.Tools and Host Software`, the entry pages for USB2CANFD, host software, `slcan` firmware, SDK routing, and the dual-channel `USB2CANFD` branch.

## Content That Is Still Primarily Gitee-First
- The broader `DM_DeviceSDK` tree under Gitee `8.工具和上位机/dm-tools/DM_DeviceSDK/`
- Gitee `8.工具和上位机/dm-tools/USB2CANFD通用升级工具/`
- Gitee `8.工具和上位机/dm-tools/DM-LinkX-4C/`
- The fuller `gs_usb_drives` adaptation notes under Gitee `8.工具和上位机/dm-tools/gs_usb_drives/`
- The fuller public `B.Canopen/Canopen/` package
- Chinese-first model details and legacy materials that have not been fully mirrored yet
- Chinese resource-directory names still remain in Gitee even when the matching GitHub subrepo has already switched those folders to English

## What To Do When GitHub Only Has The Entry Layer
1. Start with the root README to identify the right category.
2. Open the category README to decide whether you need model materials, firmware, examples, tools, or SDK content.
3. If the README, [catalog.md](catalog.md), or this page marks the content as Gitee-first, follow the handoff directly instead of guessing deeper paths inside GitHub.
4. If an older GitHub bookmark still points to the former Chinese top-level path, reopen it through [path-mapping.md](path-mapping.md) first.

## Direct Advice For Customers
- Start with [getting-started.md](getting-started.md) if you want the fastest path through the public materials.
- Start with [catalog.md](catalog.md) if you want the canonical public index.
- Start with [path-mapping.md](path-mapping.md) if you are switching between GitHub and Gitee or if an older GitHub bookmark no longer matches the current GitHub top-level path.
- If GitHub looks incomplete, treat the handoff link as the supported path rather than a dead end.
