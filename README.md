# DAMIAO

[EN](./README.md) | [中文](./README.zh.md) | [Gitee 中文](https://gitee.com/kit-miao/damiao/blob/master/README.md)

`dmBot` is the GitHub English repository for DAMIAO.
The root README provides repository role, primary entry paths, repository differences, and common guidance.

## Repository Role

- English public entry repository: primary English entry for products, control examples, boards, tools, and public continuation paths.
- Not the full archive: more complete Chinese materials, deeper history, and some broader branches remain Gitee-first.
- README pages provide navigation; detailed install, build, flashing, runtime, and platform steps stay in folder-local `USAGE.md`, `SETUP.md`, `WORKFLOW.md`, `FLASHING.md`, `BUILD.md`, `PLATFORM.md`, `UPDATE.md`, and `FIRMWARE-NOTES.md`.

## Start Here By Task

### Customers And Developers

- Looking for a motor model: start with [1.Joint Motors](1.Joint Motors/README.md).
- Need control examples: start with [5.Control Examples](5.Control Examples/README.md).
- Need control boards, IMU, or Orin carrier entry pages: start with [6.Control Boards](6.Control Boards/README.md).
- Need USB2CANFD, host software, firmware switching, or SDK paths: start with [8.Tools and Host Software](8.Tools and Host Software/README.md).
- Need Canopen materials: start with [B.Canopen](B.Canopen/README.md).

### If GitHub Coverage Is Not Enough

- Read [docs/repository/mirror-scope.md](docs/repository/mirror-scope.md) first.
- If you arrived from an older Chinese-path bookmark, use [docs/repository/path-mapping.md](docs/repository/path-mapping.md).
- When you need the more complete Chinese source, continue in [Gitee damiao](https://gitee.com/kit-miao/damiao/blob/master/README.md).

### Maintainers And Contributors

- README rules, document placement, and sync gates now live in [CONTRIBUTING.md](CONTRIBUTING.md).
- Cross-repository coverage rules stay in [docs/repository/mirror-scope.md](docs/repository/mirror-scope.md).
- Path conversion and old-bookmark handling stay in [docs/repository/path-mapping.md](docs/repository/path-mapping.md).

## High-Frequency Entry Paths

- [1.Joint Motors](1.Joint Motors/README.md) - find materials by motor model
- [5.Control Examples](5.Control Examples/README.md) - choose example paths by language, platform, and runtime
- [6.Control Boards](6.Control Boards/README.md) - controller boards, IMU, and Orin carrier entry points
- [8.Tools and Host Software](8.Tools and Host Software/README.md) - USB2CANFD tools, host software, firmware, and SDK entry
- [9.User Manuals](9.User Manuals/README.md) - public manuals and support documents
- [B.Canopen](B.Canopen/README.md) - Canopen public entry

## Repository Map

| Path | What It Contains | First Stop |
| --- | --- | --- |
| `0.Firmware` | public firmware materials and notes | [`0.Firmware/Firmware/README.md`](0.Firmware/Firmware/README.md) |
| `1.Joint Motors` | joint-motor model materials | [`1.Joint Motors/README.md`](1.Joint Motors/README.md) |
| `2.Hollow Shaft Motors` | hollow-shaft motor materials | matching subtree under `2.Hollow Shaft Motors/` |
| `3.Hub Motors` | hub-motor materials | matching subtree under `3.Hub Motors/` |
| `4.Discrete Series` | discrete-series materials | matching subtree under `4.Discrete Series/` |
| `5.Control Examples` | control examples by language and runtime | [`5.Control Examples/README.md`](5.Control Examples/README.md) |
| `6.Control Boards` | controller boards, IMU, Orin carrier, spine | [`6.Control Boards/README.md`](6.Control Boards/README.md) |
| `7.Motor Driver Boards` | driver-board entry paths | [`7.Motor Driver Boards/README.md`](7.Motor Driver Boards/README.md) |
| `8.Tools and Host Software` | tools, host software, firmware switching, and SDK entry | [`8.Tools and Host Software/README.md`](8.Tools and Host Software/README.md) |
| `9.User Manuals` | public manuals and support materials | [`9.User Manuals/README.md`](9.User Manuals/README.md) |
| `10.Direct Drive Motors` | direct-drive motor materials | matching subtree under `10.Direct Drive Motors/` |
| `11.Harmonic Drive Motors` | harmonic-drive motor materials | matching subtree under `11.Harmonic Drive Motors/` |
| `A.Open Source Series` | open-source project entry including `Seeed-reBot-DevArm` | matching subtree README |
| `B.Canopen` | Canopen public entry | [`B.Canopen/README.md`](B.Canopen/README.md) |

## Clone And Sync

```bash
git clone https://github.com/dmBots/dmBot.git
cd dmBot
git submodule update --init --recursive --remote
```

- If you only need one subtree, locate it here first and then follow that subtree's own README and workflow docs.
- For older Chinese-path GitHub bookmarks, use `path-mapping` and the local README entry pages.

## Repository Differences

- `dmBot` is the English public entry repository.
- `damiao` is the Chinese primary repository and the more complete Chinese source.
- `orin-board` keeps its current directory and documentation pattern.
- `A.Open Source Series` keeps its current structure, including external project entries such as `Seeed-reBot-DevArm`.

## Common Questions

- Why does GitHub have fewer materials than Gitee?  
  GitHub is the English entry repository rather than the full archive. Read [docs/repository/mirror-scope.md](docs/repository/mirror-scope.md).
- What should I do if an old Chinese-path GitHub bookmark no longer works?  
  Use [docs/repository/path-mapping.md](docs/repository/path-mapping.md).
- What is the difference between `README.md` and `USAGE.md` / `SETUP.md` / `WORKFLOW.md`?  
  README provides navigation; workflow docs provide the actual steps.
- Where should I go for the more complete Chinese source?
  Go to [Gitee damiao](https://gitee.com/kit-miao/damiao/blob/master/README.md).

## Support And Security

- [Customer Help Center](https://gl1po2nscb.feishu.cn/wiki/MZ32w0qnnizTpOkNvAZcJ9SlnXb)
- [Motor Firmware Mirror](https://github.com/dmBots/motor-firmware)
- [SECURITY.md](SECURITY.md)

## Maintainers And Contributors

- [CONTRIBUTING.md](CONTRIBUTING.md) - README rules, document placement, and sync gates
- [docs/repository/mirror-scope.md](docs/repository/mirror-scope.md) - coverage boundaries and cross-repository continuation guidance
- [docs/repository/path-mapping.md](docs/repository/path-mapping.md) - path conversion and old-bookmark handling
- Keep install, build, flashing, and platform procedures in folder-local workflow docs rather than in the root README.
