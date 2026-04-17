# DAMIAO

[EN](./README.md) | [中文](./README.zh.md) | [Gitee 中文](https://gitee.com/kit-miao/damiao/blob/master/README.md)

`dmBot` is the GitHub-facing English showcase repository for DAMIAO.  
The homepage is README-first: it should answer where to start, what this repo covers, when to switch back to Gitee, and where detailed workflow docs live.

## Repository Role

- English-facing showcase: high-frequency English entry for products, control examples, boards, tools, and public handoff paths.
- Not the full archive: fuller Chinese materials, deeper history, and some broader branches still remain Gitee-first.
- README pages choose the path; detailed install, build, flashing, runtime, and platform steps stay in folder-local `USAGE.md`, `SETUP.md`, `WORKFLOW.md`, `FLASHING.md`, `BUILD.md`, `PLATFORM.md`, `UPDATE.md`, and `FIRMWARE-NOTES.md`.

## Start Here By Task

### Customers And Developers

- Looking for a motor model: start with [1.Joint Motors](1.Joint Motors/README.md).
- Need control examples quickly: start with [5.Control Examples](5.Control Examples/README.md).
- Need control boards, IMU, or Orin carrier entry pages: start with [6.Control Boards](6.Control Boards/README.md).
- Need USB2CANFD, host software, firmware switching, or SDK paths: start with [8.Tools and Host Software](8.Tools and Host Software/README.md).
- Need Canopen materials: start with [B.Canopen](B.Canopen/README.md).

### When GitHub Looks Incomplete

- Read [docs/repository/mirror-scope.md](docs/repository/mirror-scope.md) first.
- If you arrived from an older Chinese-path bookmark, use [docs/repository/path-mapping.md](docs/repository/path-mapping.md).
- When you need the fuller Chinese source, continue in [Gitee damiao](https://gitee.com/kit-miao/damiao/blob/master/README.md).

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
| `A.Open Source Series` | frozen zone in this phase | matching subtree README |
| `B.Canopen` | Canopen public entry | [`B.Canopen/README.md`](B.Canopen/README.md) |

## Clone And Sync

```bash
git clone https://github.com/dmBots/dmBot.git
cd dmBot
git submodule update --init --recursive --remote
```

- If you only need one subtree, locate it here first and then follow that subtree's own README and workflow docs.
- Do not guess missing GitHub paths from older Chinese bookmarks; use `path-mapping` and the local README entry pages.

## GitHub Vs. Gitee In One Minute

- `dmBot` is the English showcase and high-frequency entry layer.
- `damiao` is the Chinese primary repository and the fuller Chinese source.
- `orin-board` stays scope-stable only in this phase and is not part of deeper naming cleanup here.
- `A.Open Source Series` remains frozen in this phase.

## Common Questions

- Why does GitHub have fewer materials than Gitee?  
  Because GitHub is the showcase layer, not the full archive. Read [docs/repository/mirror-scope.md](docs/repository/mirror-scope.md).
- What should I do if an old Chinese-path GitHub bookmark no longer works?  
  Use [docs/repository/path-mapping.md](docs/repository/path-mapping.md) instead of guessing.
- What is the difference between `README.md` and `USAGE.md` / `SETUP.md` / `WORKFLOW.md`?  
  README chooses the path; workflow docs carry the actual steps.
- Where should I go for the fuller Chinese source?  
  Go to [Gitee damiao](https://gitee.com/kit-miao/damiao/blob/master/README.md).

## Support And Security

- [Customer Help Center](https://gl1po2nscb.feishu.cn/wiki/MZ32w0qnnizTpOkNvAZcJ9SlnXb)
- [Motor Firmware Mirror](https://github.com/dmBots/motor-firmware)
- [SECURITY.md](SECURITY.md)

## Maintainers And Contributors

- [CONTRIBUTING.md](CONTRIBUTING.md) - README rules, document placement, and sync gates
- [docs/repository/mirror-scope.md](docs/repository/mirror-scope.md) - coverage boundaries and handoff rules
- [docs/repository/path-mapping.md](docs/repository/path-mapping.md) - path conversion and old-bookmark handling
- Do not push install, build, flashing, or platform steps back into the root README; keep them inside folder-local workflow docs.
