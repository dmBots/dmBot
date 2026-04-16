# Sync Policy

This document is the review gate for cross-repository maintenance.

## Roles

- Gitee is the Chinese primary repository.
- GitHub is the English-facing showcase repository.
- The two repositories should stay semantically aligned, while each keeps its own language policy.

## Must Sync

When a change affects these items, update both repositories in the same change set:

- Root README overview, scope, and document links
- `docs/catalog.md`
- `docs/readme-guideline.md`
- `docs/sync-policy.md`
- Repository description text in the hosting platform
- `.gitmodules` path or URL changes
- `.github` templates that affect contributor workflow

## Allowed Differences

- README language and section headings
- Repository-specific folder names that truly exist in only one repo
- `TBD` or `Translation pending` markers
- Chinese-only or English-only subtree docs until translation is ready
- Platform-specific links and display text

## Language Policy

- GitHub stays English-first.
- Gitee stays Chinese-first.
- Do not invent content to fill a translation gap.
- If a subtree is not translated yet, mark it explicitly as `TBD` or `Translation pending`.

## README Update Rules

1. Update `docs/catalog.md` first if the path map changes.
2. If the README template structure changes, update `docs/readme-guideline.md` first.
3. Update the subtree README(s) next.
4. Update the root README only when the top-level entry actually changes.
5. If the change affects cross-repository behavior, update this file in the same change set.

## docs Update Rules

- `docs/catalog.md` is the canonical path index.
- `docs/readme-guideline.md` is the canonical subtree README template guide.
- `docs/doc-structure.md` records the document-layer model and migration matrix.
- `docs/legacy-links.md` records historical high-value entries and their destinations.
- Keep the catalog factual and short.
- Do not copy long marketing text into the catalog.
- Add new reference docs under `docs/` only when they are ready to be maintained.

## README Consistency Gate

A subtree README change may merge only if:

- `README.md` and, when present, `README.en.md` follow the four-section structure.
- `Overview` stays entry-level.
- `Documentation / Resources` lists only real directories or files.
- `Quick Start` does not invent steps.
- `Status` shows `ZH` / `EN` / `TBD`, and incomplete English text uses `Translation pending`.
- Template filler such as `xxxx` or the old Gitee boilerplate has been removed.
- `README.md` uses the correct repository language policy.
- The change matches `docs/readme-guideline.md`.

## README Content Migration Gate

- If a README contains download instructions, submodule clone/update steps, firmware entry links, customer help center links, branch-switching notes, flashing steps, device-tree changes, CSI / UART / Wi-Fi configuration, environment setup, external references, real usage instructions, or repository maintenance notes, do not delete them directly.
- Move detailed content into `USAGE.md`, `WORKFLOW.md`, `SETUP.md`, `FLASHING.md`, or `docs/usage.md`.
- README should keep only entry-level notes, resource indexes, and jump links.
- Historical entry information should be recorded in `docs/legacy-links.md` first.
- If a workflow is migrated, review the README, the destination doc, and `docs/legacy-links.md` together.

## .gitmodules and Catalog Rules

- Path, section, and submodule names must match the real checkout.
- If a legacy alias exists, note it here and keep it out of the root README.
- When a path changes, update the catalog, the README, and the submodule entry together.

## Canonical Path Constraints

- Canonical path means the real checkout path for this repository, not a guessed normalization.
- The `.gitmodules` section name must match the canonical `path` value.
- Root README links and `docs/catalog.md` entries must use the same canonical path text as `.gitmodules`.
- Do not publish deprecated aliases in reader-facing files. If an alias is needed temporarily for compatibility, keep it out of README and catalog and mark it deprecated here.
- If the same module has different real paths across Gitee and GitHub, treat each repository-local path as canonical for that repository and document the difference instead of inventing a shared alias.
- New submodules must be added with the canonical path from day one; do not add an alias first and rename later.
- Any alias removal must be reviewed together with the README and catalog changes so link drift does not reappear.

## Repository Description Rule

- Keep the hosting-platform description semantically aligned across Gitee and GitHub.
- GitHub description text should be English.
- Gitee description text should be Chinese.
- Do not leave the description blank if a clear one-line summary is available.

## Review Checklist

- [ ] No template filler or placeholder content
- [ ] No stale static directory tree in the root README
- [ ] `docs/catalog.md` matches the current folder names
- [ ] `.gitmodules` section name, `path`, README links, and catalog entries use the same canonical path
- [ ] `README.md` / `README.en.md` follow `docs/readme-guideline.md`
- [ ] README resource links point to real directories only
- [ ] Missing translations are marked as `TBD` or `Translation pending`
- [ ] Valuable workflow content has been migrated or intentionally preserved with a jump link
- [ ] Root README links to `docs/catalog.md` and `docs/sync-policy.md`
- [ ] Any path drift is reflected in both repositories

## Exception Process

- If the English version is not ready, keep the structure and mark the missing text as `TBD`.
- If a repository-specific section exists only in one repo, document the reason in the catalog.
- If a canonical license has not been confirmed, do not add a new `LICENSE` file in this phase.
