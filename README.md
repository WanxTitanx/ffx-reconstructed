# FFX Reconstructed

**A functional engine for Final Fantasy X, rebuilt from the ground up through massive reverse engineering of the original executable.**

> **License:** MIT — educational reverse engineering and research project. Contains no Square Enix code. Final Fantasy X is property of Square Enix.

---

## What is this project

This project is the result of one of the largest FFX reverse engineering efforts ever undertaken. The original `FFX.exe` executable (Steam, International version, 11MB) was analyzed in IDA Pro with Hex-Rays decompiler, producing a database with:

- **47,432 functions** — 100% named (0 `sub_*` remaining)
- **7,706 globals** in `.data` — 100% named
- **117 enums** populated with members (~1,500+ values)
- **119 named structs** — 37 FFX + 56 Phyre + 26 Bullet
- **15,800+ comments** across functions, structs, and critical addresses
- **40+ bookmarks** at critical engine addresses
- **13,962 strings** mapped and categorized
- **6 segments** fully mapped (.text, .rdata, .data, .idata, .rodata, _RDATA)

From this knowledge base, we are rebuilding the engine in pure C++, compilable with MSVC/Clang, producing a Windows executable that opens a window, initializes D3D11, renders to the screen, and accepts keyboard input.

---

## Key reverse engineering discoveries

### Battle System
- **FFXBattleActorRecord** = 3984 bytes (0xF90), 115+ binary-confirmed fields
  - HP @ 0x5D0, MP @ 0x5D4, MaxHP @ 0x594, MaxMP @ 0x598
  - STR @ 0x5A8, DEF @ 0x5A9, MAG @ 0x5AA, MDEF @ 0x5AB, AGI @ 0x5AC, LUCK @ 0x5AD, EVA @ 0x5AE, ACC @ 0x5AF
  - Overdrive @ 0x5BC, CTB Gauge @ 0x0000, Status Flags A/B/C @ 0x1544-0x1546
  - Accessor: `FFX_Battle_PoolActorByTargetType_structural` @ 0x7B2DD0 — 346-case switch mapping field IDs to offsets
- **FFX_MagicHostContextTable** = 2048 bytes, 512 static function pointers with REAL names (`pfn_Chr_GetPosX`, `pfn_MagicHost_ApplyTransformPattern_M`, etc.)
- **Target sentinel resolution** via `FFX_Battle_QueryActorBitmask` @ 0x794340: 0xFFF1=AllAeons, 0xFFF2=FrontlineChars, 0xFFF3=Self, 0xFFEF=LastAttacker
- **ForcePerformCommand** = 0x705A (not 0x7050 which is reviveOrReinitialize)
- **ATEL_DispatchOpcode** = 0x7018 (ability logger, not WriteChrProperty)

### ATEL VM (Field Event Scripting)
- **Interpreter** @ 0x864180 — `FFX_Field_EventParser_structural`
  - 4208 bytes, 224 basic blocks, cyclomatic complexity 156
  - 123-case switch (0x00-0x7A = 0-122)
  - Fetches opcodes via `FFX_Atel_FetchOpcode` @ 0x869D00
  - Opcodes: NCJMP, JSR, RTS, CALL, REQ, RET, HALT, PUSHN, PUSHT, PUSHVP, PUSHFIX, POPI0-3, POPF0-9, PUSHI0-3, PUSHF0-9, PUSHAINTER, ER, AIT, SYSTEM
- **g_AtelOpcodeTable** @ 0xC54920 — 76 entries, 16 bytes each

### PPP (Particle/Post-Process) System
- **PPP Processor** @ 0x7170F0 — vtable dispatcher
- **274 opcodes** cataloged (strings at 0xB4FEB0-0xB513D4)
  - Categories: Draw(46), Ke/Kernel(106), Rand(33), Matrix(29), op/Special(14), Light(12), Move(7), Accele(4), Point(5), Color(2), Other(20), tt(1)
- **Full pipeline**: PPP bytecode → PppProgramProcessor → PPP draw opcodes → PppDrawRecord_Build (0xA5C370) → VfxDrawDispatch (0xA5BF50) → BuildVfxTextureFromPath (0x714890, loads .dds.phyre) → RenderVfxParticles (0x7697D0)
- **79 DXBC shader blobs** embedded in FFX.exe .rdata (0x82CAE4+)

### PhyreEngine Type System
- **PhyrePClassDescriptor** (148 bytes): +0x18 m_pClassName, +0x1C m_typeSize, +0x44 m_propertyList, +0x54 m_memberListHead
- **PhyrePClassMember** (36 bytes): +0x10 m_pName, +0x14 m_offset, +0x18 m_size
- **Namespace singleton** @ 0xC90B00 (lazy-init, zeros in static binary)
- **InsertIntoPropertyList** @ 0x43C190 — 1228 xrefs (498 DATA from vtables in .rdata)
- **Finding:** all PhyrePClassDescriptor instances are heap-allocated at runtime. Impossible to extract field names offline without a runtime memory dump.

### Magic DLL System
- **monmagic1.bin / monmagic2.bin** format FULLY mapped
  - Container = EntryListFile (header 0x14 bytes + FirstFile=entry table + SecondFile=text pool)
  - MonMagic entry = 0x5C (92 bytes): 16 bytes header + 76 bytes body (Ability_command with ~35 fields)
  - Anim1Id/Anim2Id point to magic_{NNNN}.dll
  - AI operand encoding: 0x4000|id = MonMagic1, 0x6000|id = MonMagic2
- **Texture path swap** in magic DLLs PROVEN in-game (DLLs ID 0700+)
- **Visible magic color** comes from TEXTURES (.dds.phyre), not float4/BGRA in .data

### PS2 Source Code
- **Original PS2 source code** found at `D:\FFX Extracted\FFX\ffx_ps2\ffx\yonishi_data`
  - 130 .h files, 334 .ha files, 112 mag_NNNN directories
  - 4,218 PPMPN() invocations across 120 files
  - pppProg struct = 10 function pointers (40 bytes)
  - bat_eff.h = super-catalog with 139 entries

---

## Current reconstruction status

### ✅ Code written (compiles partially, not yet producing a working .exe)
- **Game loop** — PeekMessage + QueryPerformanceCounter + 0.05s clamp. Code is correct.
- **D3D11 renderer** — Device, swap chain, RTV via LoadLibrary/GetProcAddress. Had a bug (`D3D11_CREATE_DEVICE_DEBUG` caused failure without debug layer) — now fixed with fallback.
- **Render queue** — Quad batching with dynamic vertex buffer, ortho projection, DrawIndexed with SRV batch sorting. Code is correct but untested (build doesn't produce .exe yet).
- **Texture manager** — stb_image integration, 64-slot SRV cache, atlas registry. No actual texture files exist in the project yet.
- **Input** — 256-key polling via GetAsyncKeyState with rising-edge detection. Code is correct.
- **ESC menu** — Toggle with M, arrow navigation, teal highlight. Drawing is inline in main.cpp, not a proper subsystem.
- **Save system** — CRC-16 CCITT implementation, file I/O via Win32 APIs, 7-slot management. Untested.
- **Lua 5.1** — 27 .c files included in repo. Current clang build uses lua_stubs.cpp instead (real Lua not linked yet).

### 🔄 In progress
- **Build system** — Project does not compile yet. Current blocker: duplicate symbol errors between phyre_core.cpp stub and other phyre_*.cpp files. Resolving.
- **Renderer** — D3D11 debug flag removed, error checking added. Needs verification once build succeeds.

### ⚠️ Honest assessment — what does NOT work
- **No .exe is produced** — the build fails. The previous "working" claims were never verified.
- **DrawString** — Placeholder using colored rectangles. Does NOT render actual text.
- **DrawWindow** — Simplified 4-border rect. Does NOT do real 9-slice with atlas textures.
- **DrawPlasma** — Just calls PushRect. Does NOT do procedural plasma.
- **No textures loaded** — No PNG/DDS files exist in the project. Atlas registry is empty.
- **No audio** — FMOD is a stub.
- **No 3D rendering** — Field/scene system is 5% stub.
- **No battle HUD** — Data model exists, visual rendering is 0%.
- **PhyreEngine** — All stubs. PClassDescriptor has partial implementation.
- **Bullet Physics** — All stubs.
- **Steam/Iggy** — All stubs.

### 🎯 Immediate goal
Get the build to produce a working .exe that opens a window, clears the screen to dark blue, and shows the test triangle + FPS bar. Then build toward a title screen.

---

## Architecture

```
ffx_reconstructed/
├── src/
│   ├── ffx/                    # Core game logic
│   │   ├── main.cpp            # Entry point, game loop, init chain
│   │   ├── ffx_renderer.cpp    # D3D11 device, swapchain, shaders
│   │   ├── ffx_renderqueue.cpp # Deferred quad batching pipeline
│   │   ├── ffx_texture.cpp     # Texture manager (stb_image + SRV cache)
│   │   ├── ffx_input.cpp       # Keyboard input polling
│   │   ├── ffx_menu.cpp        # ESC menu + menu2D primitives
│   │   ├── ffx_battle.cpp      # Battle data model + actions
│   │   ├── ffx_battle_hud.cpp  # Battle HUD rendering
│   │   ├── ffx_field.cpp       # Field/scene system
│   │   ├── ffx_save.cpp        # Save/load + CRC-16 + slot management
│   │   └── ffx_debug.cpp       # Debug logging + dev tools
│   ├── phyre/                  # PhyreEngine stubs + implementations
│   ├── include/                # Project headers
│   │   ├── ffx_structs.h       # 20+ FFX/PhyreEngine structs with named fields
│   │   ├── ffx_vtables.h       # 4 vtables with 35+ mapped entries
│   │   ├── ffx_rva.h           # 354 constexpr RVAs from runtime hooks
│   │   └── ffx_debug.h         # Debug logging interface
│   ├── lua-real/               # Lua 5.1 VM (real, full)
│   ├── bullet/                 # Bullet Physics stubs
│   └── lua/                    # Lua bridge stubs
├── stubs/                      # Middleware stubs (Steam, FMOD, Iggy, D3D11, Win32)
├── include/                    # Third-party headers (Bullet, FMOD, ImGui, Lua, stb, zlib)
├── test/                       # Google Test (CRC-16, PClassDescriptor, camera, etc.)
└── CMakeLists.txt              # Build config
```

### Render Pipeline

```
FFX_Renderer_BeginFrame()
  ├── OMSetRenderTargets(1, &RTV, NULL)
  ├── RSSetViewports(backbuffer w/h)
  └── ClearRenderTargetView(RTV, dark blue)

[Scene drawing]
  ├── FFX_RenderQueue_PushRect()    — solid/gradient quads
  ├── FFX_RenderQueue_PushQuad()    — UV-mapped quads with per-vertex colors
  ├── FFX_RenderQueue_PushQuadTex() — textured quads with SRV
  └── FFX_Renderer_DrawTestTriangle() — RGB test triangle

FFX_RenderQueue_Flush()
  ├── Map vertex buffer (WRITE_DISCARD)
  ├── Build orthographic projection matrix (screen-space → clip-space)
  ├── Batch quads by SRV (minimize state changes)
  ├── Set IA/VS/PS state
  └── DrawIndexed()

FFX_Renderer_EndFrame()
  └── SwapChain->Present(1, 0)
```

---

## Building

### Requirements
- **Windows 10+**
- **Clang 22+** (or Visual Studio 2022 with C++ workload)
- **Windows SDK** (for d3d11.h, dxgi.h, windows.h)

### Build with Clang
```bash
cd ffx_reconstructed
mkdir build
clang++ -Isrc\ffx -Isrc\include -Isrc -Iinclude -Istubs -Isrc\lua-real \
    -std=c++17 -O2 -DWIN32_LEAN_AND_MEAN -D_CRT_SECURE_NO_WARNINGS \
    -Wl,/SUBSYSTEM:WINDOWS \
    -o build\FFX_Reconstructed.exe \
    src\ffx\*.cpp src\phyre\*.cpp src\bullet\*.cpp stubs\*.cpp src\lua\lua_stubs.cpp \
    -ld3d11 -ldxgi -ldinput8 -lxinput -lwinmm -ladvapi32 -luser32 -lgdi32 -lshell32 -lole32
```

### Build with CMake + Visual Studio
```bash
cd ffx_reconstructed
cmake -S . -B build -G "Visual Studio 17 2022" -A Win32
cmake --build build --config Release
```

### Controls
| Key | Action |
|-----|--------|
| `M` | Toggle ESC menu |
| `↑/↓` | Navigate menu |
| `Enter` | Confirm / close menu |
| `Esc` | Close menu / quit |
| `F11` | Toggle fullscreen |

---

## IDA knowledge base

The IDA database (`ffxoficial.exe.i64`) is the source of truth for the entire reconstruction. Current state:

| KPI | Target | Actual | Status |
|-----|--------|--------|--------|
| Function names | 100% | 47,432 (0 sub_*) | ✅ |
| .data globals | ≥80% | 7,706/7,706 = 100% | ✅ |
| Enums | ≥90% | 117 enums, all populated | ✅ |
| Bookmarks | ≥140 | 40+ critical | ✅ |
| Comments | ≥5,000 | 15,800+ | ✅ |
| Struct coverage | ≥95% | ~68% (blocked: vtable dispatch) | 🟡 |
| .text intact | verified | zero modifications | ✅ |

### Key mapped structs
- **FFXBattleActorData** (3984B/115 fields) — HP, MP, stats, overdrive, CTB, status flags, animation
- **FFXFieldMap** (284B/64 fields) — field flags, state, scene pointer
- **FFX_MagicHostContextTable** (2048B/512 fields) — function pointers with real names
- **FFXBattleState** (184B) — battle flags, formation, turn, overdrive
- **FFXEncounterState** (340B) — flags, area, type, mode, formation, spawn, music
- **FFXMenu2DContext** (228B/57 fields) — highRes, modifier, capture, geom/tex slots
- **FFXMenuObject** (148B/33 fields) — callbacks, state machine, rows, scroll, window
- **PhyrePClassDescriptor** (148B/37 fields) — RTTI class descriptor
- **PhyrePClassMember** (36B/9 fields) — RTTI class member (name, offset, size)
- **PhyrePCamera** (264B) — view/projection/view-projection matrices, fog, glow, DOF
- **26 Bullet physics structs** — btRigidBody, btCollisionObject, btBoxShape, etc.

### DB backups
Incremental backups in `work/reverse/ida/backups_ffxoficial/`:
- `ffxoficial_post_catalog_v2_20260711_150000.i64`
- `ffxoficial_post_p4_enums_20260711_160000.i64`
- `ffxoficial_post_p3_p4_p6_20260711_163000.i64`
- `ffxoficial_post_p5_infer_20260711_164500.i64`

---

## Related documentation

- `docs/history/FFX_IDA_DB_RECONSTRUCTION_FINAL_2026-07-11.md` — Final DB reconciliation report
- `work/reverse/ida/STRUCT_CATALOG_20260711.md` — Struct catalog (v2.0)
- `work/reverse/ida/DB_RECONSTRUCTION_MASTERPLAN.md` — 8-phase plan
- `docs/ai/SESSION_HANDOFF.md` — Session handoff
- `KNOWLEDGE_BASE.md` — Project long-term memory index
- `PORT_STATUS.md` — Live operational status board

---

## License

MIT — This is an educational reverse engineering and research project. It contains no original Square Enix code, only original implementations based on software behavior observation. Final Fantasy X is property of Square Enix.
