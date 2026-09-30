# Agent 2 — Format & Linkage Analyst (interpretation)

> Role: aggressive on **finding relationships**, conservative on **promoting conclusions**.
> Cross-references Agent 1 cold evidence against inherited repo docs.
> Labels: `[proved]` `[structural]` `[guess]` `[blocked]`.

## 0. State of inherited knowledge — what actually exists in the repo

Verified by direct listing (the spec's inherited-doc list is **partly aspirational**):

| Spec referenced | Exists? | Note |
|---|---|---|
| `KNOWLEDGE_BASE.md`, `PORT_STATUS.md`, `CHANGELOG.md` | ✅ | but `KNOWLEDGE_BASE.md` has only **1** ps3data mention — asset research is NOT folded into the main KB yet |
| `docs/history/PS3DATA_FULL_TREE_RESEARCH_PLAN.md` | ✅ | **the** primary inherited source (22 ps3data hits) |
| `docs/history/PS2_FULL_TREE_RESEARCH_PLAN.md` | ✅ | PS2 tree (different tree), not ps3data |
| `docs/history/MODELVIEWER_BINDING_FRONTIER_2026-05-31.md` | ✅ | about editor ModelViewer/PS2 binding; 0 ps3data hits |
| `docs/history/NON_FFX_EDITOR_THREADS_ANNEX.md` | ✅ | **verifies Pt46–Pt51 ownership** |
| `PS3DATA_CHECKLIST_MASTER_2026-06-01.md` | ❌ | **does not exist** |
| `EDITOR_READONLY_ABSORPTION_REPORT_2026-06-01.md` | ❌ | **does not exist** |
| `PT_OPERATIONAL_FLOW_2026-06-01.md` | ❌ | **does not exist** |
| `PT52..PT58_*_FILE_MEANING_GUIDE_2026-06-01.md` (5 files) | ❌ | **none exist** |
| `PT52_TO_PT58_CLOSEOUT_REPORT_2026-05-31.md` | ❌ | **does not exist** |

`[proved]` **Divergence #1:** the PT52–58 "file meaning guides", the PS3DATA checklist-master, the readonly-absorption report and the PT operational-flow doc referenced by the task **are not present in this repo**. `Pt52..Pt58` survive only as brief "mini-tools" mentions in `docs/ai/SESSION_HANDOFF.md`. The atlas must not quote content from those non-existent files.

## 1. No asset-handling code exists (state of tooling)

`[proved]` **Divergence #2:** the spec's `FFXProjectEditor/FfxLib/Ps2/*` and `FFXProjectEditor/Modules/Extras/*` **do not exist**.
- `Modules/` holds only gameplay editors (MonEditor, BattleExplorer, ShopExplorer, …) — none asset-related.
- `FfxLib/` holds only gameplay libs (Ability, Battle, Monster, Text, …) — **no Ps2, no Phyre, no texture/graphics lib**.
- No C# source references `.phyre`, `.ahwin32`, `dds.phyre`, etc. (the 9 incidental grep hits were the word "Extras"/"chr" substrings in battle modules).

**Conclusion:** ps3data is a **documentation/research frontier with zero shipped tooling**. The `Extras` surface and its labs are planned (`Pt46–Pt51` wrappers), not built. Any claim of a "parser", "preview", or "extractor" for ps3data is therefore `[blocked]` at the code level today.

## 2. ps3data vs ffx_ps2 — what this tree actually is

`[structural]` ps3data is the **PC/PS3 HD-remaster asset tree** (Phyre engine, `RYHPT`/`11XD`=DX11, `d3d11\` dirs, FMOD FSB5, WebM, CWS-SWF). It is **distinct** from `D:\FFX Extracted\FFX\ffx_ps2\ffx\master\`, which is the **PS2 gameplay data** the editor's existing tooling reads/writes. This explains why no gameplay code touches ps3data: it is the **graphics / audio / media / UI layer** of the remaster, not the kernel/battle data layer. The two trees are siblings under the same extraction, with different engines and owners.

## 3. Inherited family model (research plan) vs Agent 1 evidence

The `PS3DATA_FULL_TREE_RESEARCH_PLAN.md` (2026-05-31) family model, cross-checked:

| Inherited family | Inherited members | Agent 1 verdict |
|---|---|---|
| Phyre texture/container | `*.dds.phyre` | `[proved]` 44,394 files, `RYHPT…11XD`. Confirmed. |
| Phyre geometry/model | `*.dae.phyre`, `*.ags.phyre`, **`*.fgen.phyre`** | `[proved]` dae/ags are geometry (chr/map/btlmap only). **`[structural]` correction:** the lone `*.fgen.phyre` is `fonts/tuffy.fgen.phyre` — a **font-glyph container**, NOT character geometry. → **Divergence #3.** |
| descriptor/index | `*.ahwin32`, `texlist.txt` | `[proved]` — and Agent 1 adds: `.ahwin32`/`.ah` are **auto-generated TEXT** (`// This file is auto-generated…`), not binary. |
| non-Phyre binary | `texturevideo/*.bin`, `lockit/*.bin`, `syncdata/*` | `[proved]` they exist; decode still `[blocked]`. |
| direct media | sound_pc, video, flash, savedataicons | `[proved]` standard magics (FSB5/RIFF/WebM/CWS/PNG). |

The plan's per-folder coverage tags ("best surrounded" / "partial" / "barely documented") are **planning-era guesses**; Agent 1 supersedes them with hard counts.

## 4. Verified historical ownership (Pt lines)

From `docs/ai/SHARED_CONTEXT.md` + `NON_FFX_EDITOR_THREADS_ANNEX.md`:

| Pt | Lab (planned) | Domain | Verify |
|---|---|---|---|
| Pt46 | `ExtrasTexturePhyreLab` | `*.dds.phyre`, `texlist.txt`, Phyre visual; **magic** priority | `[proved]` (repo) |
| Pt47 | `ExtrasAudioLab` | `sound_pc` (`.fev/.fsb/.wav/.txt`) | `[proved]` (repo) |
| Pt48 | `ExtrasVideoLab` | `video` + `texturevideo` as media/container | `[proved]` (repo) |
| Pt49 | `ExtrasUiLocaleLab` | `help*`, `menu_*`, `lockit`, `syncdata`, `fonts`, `flash` | `[proved]` (repo) |
| Pt50 | `ExtrasShaderLab` | `shaders` (`.fx.phyre`, `vfxshader*.txt`) | `[proved]` (repo) |
| Pt51 | `ExtrasKnowledgeHub` | consolidation / inventory hub | `[proved]` (repo) |
| Pt52–58 | "mini-tools" | referenced only in `SESSION_HANDOFF.md`; no guide files | `[structural]` / `[blocked]` |
| Pt59 (chr deep), Pt71–83 (modelviewer chr) | — | **claimed by task prompt; not found in repo docs** | `[blocked]` |

(The repo's model-viewer campaign is `Pt2 + Pt9 + Pt31..Pt35`, not `Pt71–83`.)

## 5. Linkage atlas (relationships, with confidence)

- **Phyre visual:** `*.dds.phyre` → `texlist.txt` (1,024 txt across magic/map/event/btlmap/yonishi) → `*.ahwin32` descriptor. `[proved]` co-location; `[structural]` that texlist enumerates the dds set per dir; `[guess]` exact field schema.
- **Geometry/carrier (chr):** `mdl\d3d11\<m>.dae.phyre` + `<m>.ags.phyre` + `<m>.ahwin32` (root) + `<m>.cdf` + optional `<m>.ah`, all keyed by model dir `chr\mon\m###\` (or `chr\pc\c###\`). `[proved]` dae↔ahwin32 bijection (872↔872). `[structural]` cdf is per-model (113, chr-only) — likely skeleton/cloth/definition. `[blocked]` cdf decode.
- **Audio:** `<X>.fev` (FMOD event project, RIFF) → `<X>_bank00.fsb` (FMOD FSB5 bank). `[proved]` 1,260↔1,260 bijection. SFX `<id>_common.txt`/`<id>_loop.txt` index the sfx banks. `[structural]`.
- **Video:** `video\<region>\ffx_videolist.txt` → `*.webm` (Matroska) + `*.dat` (opaque sidecar) + `texturevideo\texvideo<place>NN.bin` (per-location). `[structural]`; `[blocked]` .dat / texturevideo decode.
- **UI/help/menu/locale:** `help*`/`menu*` = pure `*.dds.phyre`; `lockit/ffx_loc_kit_ps3_<lang>.bin` (8 langs, encoded) = localization; `fonts/tuffy.fgen.phyre` = font; `flash/*.swf` = CWS UI movies; `savedataicons/*.png` = save icons. `[proved]` magics; `[blocked]` lockit codec.
- **Shaders:** `shaders/*.fx.phyre` (102) + `*.fx#<hash>.phyre` (691) → `vfxshader.txt`, `vfxshader_fx.txt` catalogs. `[structural]`; `[blocked]` shader bytecode decode.
- **Cold binaries:** `savesforviewer/<int>` (110 × 25,848 b fixed records), `syncdata_*.txt`, `texturevideo/*.bin`, `video/*.dat`, `lockit/*.bin`, the lone `.pal`/`.log` (texlist siblings in magic). `[blocked]` schemas.

## 6. New hypotheses raised (label = guess unless noted)

- `[structural]` `11XD` = `DX11` little-endian → every `.phyre` here is the **D3D11 platform build** (matches ubiquitous `d3d11\` dirs). The PS3 build would presumably carry a different 4CC.
- `[structural]` `.ahwin32` = "asset header, win32" auto-generated text manifest binding a carrier to its textures/material; the `win32` suffix implies platform-specific variants may exist elsewhere.
- `[guess]` `.cdf` = "character definition file" (chr-only, 113, per-model) — skeleton/cloth/collision. Needs decode.
- `[guess]` `savesforviewer` 25,848-byte records = serialized party/save snapshots for an in-game/remaster **viewer/theater**; fixed size ⇒ flat struct array.
- `[structural]` the lone `.pal`/`.log` are **texlist build artifacts** in `magic` (the `.log` leaks build root `R:/FFX_Data/GameData/PS3Data/` + 32-bit content hashes).
- `[proved]` not all `.txt` are text — the largest (148 KB, sound_pc) opens `ML` + binary ⇒ binary index disguised as `.txt`. Inherited plan already suspected `syncdata/*.txt` is disguised binary; **needs a header sample to confirm** (Agent 3 / Phase 3).

## 7. Conflicts to resolve in the atlas

1. Missing inherited docs (Div #1) → present campaign from what exists; mark the rest `[blocked]`/claimed.
2. No Extras/Ps2 code (Div #2) → honest state = research-only; no parser/preview/extractor today.
3. `.fgen.phyre` = font, not geometry (Div #3) → correct the inherited grouping.
4. Granular Pt59/Pt71–83 ownership unverifiable → label `[blocked]`, attribute to session context only.
