# Getting Started With This Repository

This guide is for customers and first-time visitors. It explains what this repository is, where to find materials, how to download them, and how to interpret the different document types.

## What This Repository Is

- This repository is the GitHub-facing documentation mirror for DAMIAO.
- The root README is the repository-level entry page.
- Category README files help you choose the right subtree.
- Subtree README files help you enter a specific product, board, example, or tool folder.

## Recommended Reading Order

1. Start with the root [README.md](../README.md)  
   It explains what the repository is, how to clone it, and where the high-value entry points are.
2. Then open [mirror-scope.md](mirror-scope.md)  
   It explains what GitHub mirrors well, what still mainly lives in Gitee, and where to go when a path is incomplete.
3. Then open [catalog.md](catalog.md)  
   It shows the real folders, submodules, and current path layout.
4. Then enter the relevant category README  
   Examples:
   - [../1.关节电机/README.md](../1.关节电机/README.md)
   - [../5.控制例程/README.md](../5.控制例程/README.md)
   - [../6.控制板/README.md](../6.控制板/README.md)
   - [../8.工具和上位机/README.md](../8.工具和上位机/README.md)

## How To Find Materials

- For a specific motor model: start from [../1.关节电机/README.md](../1.关节电机/README.md).
- For control examples: start from [../5.控制例程/README.md](../5.控制例程/README.md).
- For control-board documents: start from [../6.控制板/README.md](../6.控制板/README.md).
- For tools, host software, firmware switching, or SDK materials: start from [../8.工具和上位机/README.md](../8.工具和上位机/README.md). It will route you to the right first file for USB2CANFD, host software, `slcan` firmware, or `DM_DeviceSDK`.
- If a GitHub tool path looks incomplete, open [mirror-scope.md](mirror-scope.md) and continue in Gitee instead of guessing.

## How To Download

### Clone The Full Repository

```bash
git clone https://github.com/dmBots/dmBot.git
cd dmBot
git submodule init
git submodule update --recursive --remote
```

### Use A Single Subtree

- Locate the relevant subtree in this repository first.
- Then follow that subtree's own README and workflow pages for the latest instructions.

## How To Read The Document Layers

- `README.md`  
  Entry page. It explains what the folder is, where the real resources are, and what to read next.
- `USAGE.md` / `WORKFLOW.md` / `SETUP.md` / `FLASHING.md` / `PLATFORM.md`  
  Workflow pages. Install, build, flashing, environment, and interface setup steps usually live there.
- `docs/catalog.md`  
  Real path and category index.
- `docs/mirror-scope.md`  
  Coverage guide for Gitee vs. GitHub.
- `docs/legacy-links.md`  
  Archive of high-value historical README content and where it moved.

## What `TBD` And `Translation pending` Mean

- `TBD` means the content is not fully confirmed yet.
- `Translation pending` means the English layer is still being filled in.
- When English material is incomplete, check the linked subtree documents, [mirror-scope.md](mirror-scope.md), and the Chinese workflow pages instead of guessing.
