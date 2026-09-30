# Versioning Policy — ffx-reconstructed

This document defines the Semantic Versioning contract for the public `ffx-reconstructed` project.  
All contributors **must** follow these rules when bumping versions.

## Format

```
v<MAJOR>.<MINOR>.<PATCH>.<BUILD>
```

Example: `v1.3.7.0`

## Rules

### MAJOR — Public API / Architectural Break
- Complete engine rewrite or subsystem replacement
- Breaking change to the public C++ API (if any header consumer would break)
- Removing a core module (PhyreEngine, Lua, Bullet)
- **Resets MINOR, PATCH, BUILD to 0**

### MINOR — Feature milestone
- Completion of a full ROTA (A-G) or a significant ROTA sub-phase
- Adding an entire new subsystem (Field, Menu, Battle, Save, Audio)
- Feature that meaningfully changes what the `.exe` can do
- **Resets PATCH to 0**

| Current MINOR | Milestone |
|---------------|-----------|
| 0.x | Initial scaffold (game loop + D3D11 + input + save) — **done** |
| 1.x | Render 2D complete (ROTA A) |
| 2.x | Battle HUD complete (ROTA B) |
| 3.x | Save/Load UI complete (ROTA C) |
| 4.x | Type system complete (ROTA D) |
| 5.x | Deploy + test pipeline (ROTA E) |
| 6.x | Editor preview (ROTA F) |
| 7.x | Phyre stubs complete (ROTA G) |

### PATCH — Implemented function / Bug fix
- Replacing a stub (`return 0`) with real implementation
- Bug fix in a previously implemented function
- Adding a new function that doesn't open a new subsystem
- Adding a struct, enum, or type declaration
- **Resets BUILD to 0**

### BUILD — Internal / CI / Documentation
- Comment changes, whitespace, formatting
- Documentation updates (README, `.md` files)
- CI pipeline changes
- Build system fixes (CMakeLists, compiler flags)
- **No functional code change**

## Tags

Every release **must** be tagged:

```bash
git tag -a v<MAJOR>.<MINOR>.<PATCH>.<BUILD> -m "v<MAJOR>.<MINOR>.<PATCH>.<BUILD>: <brief summary>"
git push origin v<MAJOR>.<MINOR>.<PATCH>.<BUILD>
```

## Changelog

Keep `CHANGELOG.md` up to date with every version bump:

```markdown
## [v1.0.0.0] — 2026-07-06

### Added
- Feature A
- Feature B

### Changed
- Refactored X

### Fixed
- Bug Y
```

## Branch Strategy

| Branch | Purpose | Source |
|--------|---------|--------|
| `main` | Stable releases only | — |
| `develop` | Integration branch for next MINOR | `main` |
| `feat/<name>` | Feature branches | `develop` |
| `fix/<name>` | Bug fix branches | `develop` |

## Current Version

**v1.0.0.0** — Initial public release (engine scaffold + ROTA A partial)

---

## Versioning Policy — ffx-editor-main (private monorepo)

The private editor repo uses a separate scheme:

```
v<MAJOR>.<MINOR>.<PATCH>.<BUILD>
```

### Rules

| Component | Bump when |
|-----------|-----------|
| **MAJOR** | Editor UI breaking change, data model migration |
| **MINOR** | New module/feature in the editor (new editor tab, new .bin writer) |
| **PATCH** | Bug fix, minor enhancement, DB quality improvement |
| **BUILD** | Internal changes, docs, CI |

Current: **v2.190.0.0** — Sphere Grid Canvas v3: UI Redesign + Content Fix + Deploy Policy + IDA RE (0xA45570/0x681DB0/0xA51340/0x7F4900/0xA54860)

### DB Version (embedded in commit messages)

The IDA DB (`ffxoficial.exe.i64`) is versioned separately by commit:

```
feat(db): <what changed> — 8.9K comments, 6 vtables, 9 struct field types
```

Tag the DB state with the commit SHA, not a separate version number.
