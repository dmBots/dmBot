# Tools and Host Software

[EN](./README.md) | [中文](./README.zh.md) | [Gitee 中文](https://gitee.com/kit-miao/damiao/blob/master/8.工具和上位机/README.md)

## Overview

- This folder is the customer-facing task entry for USB2CANFD tools, host software, firmware switching, and SDK materials in the GitHub mirror.
- If you do not know which file to open first, start with [dm-tools/README.md](dm-tools/README.md); it routes by customer task instead of by raw directory tree.
- GitHub mirrors the high-frequency paths, but some broader tool branches still remain Gitee-first. Use [../docs/mirror-scope.md](../docs/mirror-scope.md) when a path seems incomplete.

## Documentation / Resources

- [dm-tools/README.md](dm-tools/README.md) - main task router under `8`; start here if you are not sure whether you need tools, host software, firmware, or SDK materials
- [dm-tools/USB2CANFD/README.md](dm-tools/USB2CANFD/README.md) - main USB2CANFD entry for setup, host software, firmware, and SDK paths
- [dm-tools/DM_DeviceSDK/README.md](dm-tools/DM_DeviceSDK/README.md) - GitHub handoff entry for the generic device SDK path that still mainly lives in Gitee
- [../docs/getting-started.md](../docs/getting-started.md) - first-time repository guide
- [../docs/mirror-scope.md](../docs/mirror-scope.md) - explains GitHub vs. Gitee coverage and where to continue
- [../docs/catalog.md](../docs/catalog.md) - real folder and subtree index

## Quick Start

- To download and use USB2CANFD tools, start with [dm-tools/USB2CANFD/README.md](dm-tools/USB2CANFD/README.md), then continue into `SETUP.md`.
- To run the host software, open [dm-tools/USB2CANFD/上位机/README.md](dm-tools/USB2CANFD/上位机/README.md); it tells you which package to download before you follow `SETUP.md`.
- To flash, switch, or validate `slcan` firmware, open [dm-tools/USB2CANFD/固件/socketcan/slcan固件/README.md](dm-tools/USB2CANFD/固件/socketcan/slcan固件/README.md), then follow `FLASHING.md`.
- To use SDK materials, start with [dm-tools/USB2CANFD/SDK/README.md](dm-tools/USB2CANFD/SDK/README.md) for the mirrored USB2CANFD path; for the generic device SDK route, open [dm-tools/DM_DeviceSDK/README.md](dm-tools/DM_DeviceSDK/README.md) and continue in Gitee if needed.
- To confirm whether this repository has the path you need, start with [dm-tools/README.md](dm-tools/README.md), then verify the real path in [../docs/catalog.md](../docs/catalog.md).
- If GitHub looks incomplete, open [../docs/mirror-scope.md](../docs/mirror-scope.md) and continue in Gitee instead of guessing.
- If you arrived from an older Chinese-path GitHub bookmark, see [../docs/path-mapping.md](../docs/path-mapping.md) before guessing the new top-level path.
- If you are not sure what `README.md`, `SETUP.md`, `WORKFLOW.md`, or `FLASHING.md` are for: README chooses the path, `SETUP.md` handles install and run preparation, `WORKFLOW.md` handles usage sequence, `FLASHING.md` handles firmware work, and SDK README pages help you choose language or platform first.

## Status

- EN: main entry
- ZH: some detailed workflow notes remain Chinese-first
- TBD: broader tool coverage should always be checked against [../docs/mirror-scope.md](../docs/mirror-scope.md)
