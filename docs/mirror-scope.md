# Repository Coverage And Mirror Scope

## Repository Roles
- Gitee is the Chinese primary repository and currently the most complete public source.
- GitHub is the English-facing public mirror / showcase repository. Its entry structure, navigation logic, and common customer paths should stay aligned with Gitee, but detailed coverage can lag behind Gitee.

## What Customers Should Find In Both Repositories
- The high-value entry points in the root README.
- The `docs/` layer: getting started, catalog, document structure, legacy archive, README rules, sync policy, and mirror-scope explanation.
- Entry-layer navigation for high-frequency paths, especially `0.固件`, `1.关节电机`, `5.控制例程`, `6.控制板`, and `8.工具和上位机`.
- Under `8.工具和上位机`, the entry pages for USB2CANFD, host software, `slcan` firmware, SDK routing, and the dual-channel `USB2CANFD` branch.

## Content That Is Still Primarily Gitee-First
- The broader `DM_DeviceSDK` tree under `8.工具和上位机/dm-tools/DM_DeviceSDK/`
- `8.工具和上位机/dm-tools/USB2CANFD通用升级工具/`
- `8.工具和上位机/dm-tools/DM-LinkX-4C/`
- The fuller `gs_usb_drives` adaptation notes under `8.工具和上位机/dm-tools/gs_usb_drives/`
- The fuller public `B.Canopen/Canopen/` package
- Chinese-first model details and legacy materials that have not been fully mirrored yet

## What To Do When GitHub Only Has The Entry Layer
1. Start with the root README to identify the right category.
2. Open the category README to decide whether you need model materials, firmware, examples, tools, or SDK content.
3. If the README, [catalog.md](catalog.md), or this page marks the content as Gitee-first, follow the handoff directly instead of guessing deeper paths inside GitHub.

## Direct Advice For Customers
- Start with [getting-started.md](getting-started.md) if you want the fastest path through the public materials.
- Start with [catalog.md](catalog.md) if you want the canonical public index.
- If GitHub looks incomplete, treat the handoff link as the supported path rather than a dead end.
