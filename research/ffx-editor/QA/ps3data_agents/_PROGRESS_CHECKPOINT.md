# PS3DATA ATLAS — PROGRESS CHECKPOINT

> Durable resume anchor. If a session is interrupted (e.g. 5h usage limit), re-read this
> file plus the already-written deliverables in this folder, then continue from the first
> phase not marked DONE. Nothing here is destructive; all source data is read-only.

## Ground truth (confirmed 2026-06-01)
- Repo: `C:\Users\wande\Documents\ffx-editor-main` (git: main, untracked user files AGENTS.md/CLAUDE.md/docs/ai/ — DO NOT TOUCH)
- Source root (READ-ONLY): `D:\FFX Extracted\FFX\ffx_data\gamedata\ps3data`
- Top folders: 35 (matches baseline exactly)
- Baseline file count to verify: 54,337
- Work dir: `work/ps3data_agents/`
- Final output: `docs/history/PS3DATA_EXTENSION_AND_LINKAGE_ATLAS_2026-06-01.md`

## Deliverables checklist
- [x] `ps3data_inventory.csv` (54,337 rows)
- [x] `ps3data_topfolder_extension_matrix.csv`
- [x] `ps3data_topfolder_compound_extension_matrix.csv`
- [x] `ps3data_sample_headers.csv`
- [x] `agent1_inventory_cartographer.md`
- [x] `agent2_format_linkage_analyst.md`
- [ ] `agent3_documentation_architect_guardrail_auditor.md`
- [ ] `docs/history/PS3DATA_EXTENSION_AND_LINKAGE_ATLAS_2026-06-01.md`

## Phase log
- [DONE] Phase 0 — Orientation: paths confirmed, memory read, work dir + tasks created.
- [DONE] Phase 1 — Inventory (Agent 1): 54,337 files = baseline exactly. CSVs + agent1 notes written.
- [DONE] Phase 2 — Inherited knowledge (Agent 2): docs read, code scanned, agent2 notes written.
- [DONE] Phase 3 — Header sampling & linkage: all magics + index formats decoded, content-proven bindings.
- [DONE] Phase 4 — Write atlas (Agent 3): docs/history/PS3DATA_EXTENSION_AND_LINKAGE_ATLAS_2026-06-01.md (403 lines).
- [DONE] Phase 5 — Validation: 35/35 folders, 17/17 exts, 7 tables 0 broken, ps3data 0 files modified (read-only proven).

## COMPLETE — atlas deliverables written and validated.

## DEEP SWEEP — cold families decoded (2026-06-01)
- **DXT dims [proved/SOLVED]:** unified rule `width=U32@(pidx-88)`, `height=U32@(pidx-84)` (pidx = "PTexture2D" instance offset). Self-validated 17/17 (W*H*bpp==mip0@80) across ARGB8/DXT5/DXT1, square+non-square. Extractor now auto-extracts ALL formats; icon still BYTE-EXACT.
- **Visual [proved]:** icon.dds.extracted.dds rendered to PNG = real FFX UI icon atlas (status/element orbs, buttons, "OVERKILL/MISS/IMMUNE/ITEM"). Source texture is X-mirrored (asset property).
- **Texlist naming refine [structural]:** filename `_W_H` = HALF the real dims (actual = 2× name).
- **lockit [proved]:** cipher = **byte − 15** → trophy/achievement/system loc strings, all langs (us/de/fr/...). plaintext+15. Accented = UTF-8 multibyte.
- **.cdf [structural]:** starts with AABB bounding box (6 floats min/max XYZ, X symmetric) + index(0/1/2) + 0xCD fill. Per-entity collision/bounds def; size scales w/ entity (68b..20KB). chr/mon/npc/obj/pc/sum/wep.
- **savesforviewer [structural]:** 25,848 b fixed record, 92.2% constant across saves; sparse small variable fields; token `cxs` @~32.
- **texturevideo [structural]:** `[u32 ver=1][u32 cntA][u32 cntB][float[]]` UV/scroll params per location.
- **video/.dat [structural]:** starts float 1.0 + float + large payload → per-frame timing/sync sidecar for webm.
- **syncdata_*.txt [proved binary]:** float arrays disguised as .txt.

## FOLLOW-UP: Roadmap #1 — .dds.phyre decode (DONE 2026-06-01)
- Extractor: `work/ps3data_agents/Extract-DdsPhyre.ps1` (read-only).
- Doc: `docs/history/PS3DATA_DDS_PHYRE_DECODE_2026-06-01.md`.
- Outputs (proof): `work/ps3data_extract/` (icon byte-exact vs ground-truth DDS).
- PROVED: container = PhyreEngine RYHPT cluster + verbatim texture buffer at end.
  - `bufferStart = indexOf("PTexture2D"_instance) + 11 + len(FORMAT) + 38`
  - U32@80 = mip0 byte size; ARGB8 dims = U32@(bufferStart-142/-138).
  - icon.dds.phyre → reconstructed .dds is BYTE-EXACT (0/2,097,280 mismatches).
- STRUCTURAL: DXT5 mip0 extract with supplied dims (battle 1024x1024, magic 1024x512) — valid DDS, no DXT ground truth.
- BLOCKED frontier: DXT dims-from-header, multi-texture atlas, full mip chain.

## Phase 3 proved facts (content-level)
- `.phyre` = **Sony PhyreEngine** containers (`Phyre::PUInt32` in ahwin32; `RYHPT` magic; `11XD`=DX11 LE).
- `.ahwin32` = auto-gen **PhyreEngine D3D11/32-bit asset-header C++ include**; `g_fileNames[]` array binds the entity's carriers BY NAME → **linkage proved by content** (not just basename).
- `m001.ahwin32` binds: `mdl/D3D11/m001.dae.phyre` + `tex/D3D11/m001.dds.phyre` + 2× `Shaders/D3D11/PhyreChrLitShader.fx#<hash>.phyre`.
- `.fx#<hash>.phyre` = **compiled shader permutations** of named `.fx` shaders (hash=variant), shared in `Shaders/D3D11/`, referenced by ahwin32.
- `texlist.txt` = plaintext list of `.dds.phyre` names; texture name encodes WxH (`..._512_256.dds.phyre`=512×256). Used by pure-visual folders (magic/event) that have no ahwin32.
- `vfxshader.txt` = shader property **bitflag catalog** (0x80000000 water, 0x8 texture, blend modes).
- `ffx_videolist.txt` = ordered `idx:,webm,webm` playlist (OPN/LVx, `_jp` region).
- `syncdata_*.txt` = **binary float arrays** disguised as .txt (41,700 b sample). texturevideo.bin = int32 header(1,6,6)+floats. `.cdf` = small per-entity float record (68 b smallest, chr-only).
- Naming: `magic`=`magic_####` subtrees; `event`=locale-partitioned (ch/de/es/fr/it/kr); `btlmap`=4-letter area codes (azit/bika/dome).

## Key proved facts (for fast resume)
- All `.phyre` share magic `RYHPT` + `11XD` (=DX11 LE → D3D11 platform).
- `.ahwin32`/`.ah` are auto-generated TEXT descriptors.
- chr `.dae.phyre` ↔ `.ahwin32` = 872↔872 bijection (model-dir+leaf).
- audio `<X>.fev` ↔ `<X>_bank00.fsb` = 1260↔1260 bijection.
- Geometry (dae/ags) only in chr/map/btlmap; everything else pure `.dds.phyre`.
- savesforviewer: 110 × 25,848 b fixed records. lockit: 8 `ffx_loc_kit_ps3_<lang>.bin` + placeholder.
- Largest `.txt` (sound_pc, 148KB) is binary (`ML`) → not all txt are text.

## Notes / divergences found
- **Div #1:** spec's PT52–58 file-meaning guides, PS3DATA_CHECKLIST_MASTER, EDITOR_READONLY_ABSORPTION_REPORT, PT_OPERATIONAL_FLOW **do not exist** in repo. Only Pt46–51 ownership is repo-verified (NON_FFX_EDITOR_THREADS_ANNEX). Pt59/Pt71–83 unverified.
- **Div #2:** spec's `FfxLib/Ps2/*` and `Modules/Extras/*` **do not exist** — zero ps3data/Phyre code in editor; research-only state.
- **Div #3:** `.fgen.phyre` is `fonts/tuffy.fgen.phyre` (a font), NOT geometry as the research plan grouped it.
- Inventory count = baseline EXACTLY (54,337). No drift.
- Identity: in this repo the assistant is addressed as **Jarvis** (per CLAUDE.md).
