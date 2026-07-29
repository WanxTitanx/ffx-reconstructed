---
title: PhyreEngine Version Confirmed — FFX.exe = 3.9.0.0 "SacSlicer"
date: 2026-07-27
status: CONFIRMED via %%PVER%% string in binary
tags: [phyreengine, version, ffx, reverse-engineering, ida-pro]
---

# PhyreEngine Version — FFX.exe = 3.9.0.0 "SacSlicer"

> **CONFIRMED**: FFX.exe embeds `%%PVER%%3.9.0.0 "SacSlicer"` at address `0xb0de44`.
> Found via IDA MCP `find_regex` on FFX.exe (session `f0b4b48d`).

## Discovery

The gist [uyjulian/ed8_phyreengine_versions](https://gist.github.com/uyjulian/4c01aa0c5e862e0136e59b1a9b2817f6)
documented that PhyreEngine had a method to embed the version via `%%PVER%%`,
but claimed "it doesn't actually work due to dead code elimination."

**However, FFX.exe has it intact:**

```
addr 0xb0de44: %%PVER%%3.9.0.0 "SacSlicer"
```

## Version

**PhyreEngine 3.9.0.0** (codename "SacSlicer")

## Timeline Context

| Version | Date | Game |
|---------|------|------|
| 3.1.5.0 | Out 2011 | PS3 SDK 3.70 (what we have) |
| 3.6.0.0 | ~2013 | Trails of Cold Steel 1 (PSV) |
| **3.9.0.0** | **~2013** | **FFX HD Remaster (PS3 JP Dec 2013)** |
| 3.12.0.0 | ~2015 | Tokyo Xanadu (PSV) |
| 3.18.0.0 | ~2017 | Trails of Cold Steel 1/2 (PS4) |
| 3.25.0.0 | ~2020 | Trails into Reverie (PS4) |

FFX HD Remaster PS3 JP released 2013-12-26 — PhyreEngine 3.9.0.0 fits perfectly.

## Source Paths in Binary

```
r:\hg_code\middleware_w32\phyreengine\include\Scripting\PhyreScripting.inl
r:\hg_code\middleware_w32\iggysdk\gdraw\gdraw_d3d1x_shared.inl
```

- **PhyreEngine** source at `r:\hg_code\middleware_w32\phyreengine\` (Mercurial repo)
- **Iggy SDK** (UI middleware by RAD Game Tools, now Autodesk) at `r:\hg_code\middleware_w32\iggysdk\`
- Compiled on drive `R:\` — Square Enix build machine

## What This Means

1. **We have the EXACT version** — no guessing needed
2. **PhyreEngine 3.9.0.0 is between 3.6.0.0 (CS1) and 3.12.0.0 (Tokyo Xanadu)**
3. **PS3 SDK 3.70 (Out 2011) we have includes PhyreEngine 3.1.5.0** — older than FFX's 3.9.0.0
4. **FFX HD was built with a newer PhyreEngine** than what shipped in SDK 3.70
5. **Square Enix had PhyreEngine 3.9.0.0 source** (licensee) — not in public SDKs

## Implications for RE

- **RTTI strings (777+)** in FFX.exe are from PhyreEngine 3.9.0.0
- **class_informer** can reconstruct all classes via vftables
- **PhyreEngine 3.1.5.0 SDK** (what we have) is CLOSE but not EXACT — API differences may exist between 3.1.5.0 and 3.9.0.0
- **CHM reference** (42MB) is for 3.1.5.0 — use as guide, but verify against binary

## Other Middleware in FFX.exe

- **Iggy** (RAD Game Tools / Autodesk) — UI rendering, Flash-like
- **FMOD** (Firelight Technologies) — audio
- **Steam API** — DRM/achievements
- **D3D11** — rendering (Windows port)

## Verification

- IDA MCP session `f0b4b48d` on `C:\Users\wande\Documents\ffx-reconstructed\extras\FFX.exe`
- `find_regex "%%PVER%%|PhyreEngine.*[0-9]\.[0-9]\.[0-9]"` → 1 match at `0xb0de44`
- String: `%%PVER%%3.9.0.0 "SacSlicer"`

## References

- [PhyreEngine versions gist (uyjulian)](https://gist.github.com/uyjulian/4c01aa0c5e862e0136e59b1a9b2817f6)
- [PHYREENGINE_RTTI_DISCOVERY_2026-07-27.md](./PHYREENGINE_RTTI_DISCOVERY_2026-07-27.md)
- [PHYREENGINE_GETTING_STARTED_3_1_5_0.md](./PHYREENGINE_GETTING_STARTED_3_1_5_0.md)

---

*Discovered by Jarvis (Verboo Code) on 2026-07-27 via IDA Pro MCP `find_regex` on FFX.exe.*
