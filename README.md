# FFX Reconstructed

**A functional engine for Final Fantasy X, rebuilt from the ground up through massive reverse engineering.**

This project is the result of one of the largest FFX reverse engineering efforts ever undertaken: **45,114 named functions**, **291 structs**, **91 vtables**, and **thousands of hours** analyzing the Steam build of FFX (International version) using IDA Pro + Hex-Rays. All code is original, written in pure C++, compilable with MSVC, and produces a Windows executable that opens a window, initializes D3D11, renders to the screen, and accepts keyboard input.

---

## Current Status

### ✅ Working Now
- **Game loop** — Non-blocking PeekMessage, delta time via QueryPerformanceCounter, anti-spiral-of-death clamp
- **Native D3D11** — Device, swap chain, render target view created via LoadLibrary + GetProcAddress (zero static dependency on d3d11.lib)
- **Inline HLSL shaders** — Vertex + pixel shaders compiled at runtime via D3DCompile from embedded C strings
- **Render queue** — Quad batching with dynamic vertex buffer (up to 2048 quads/frame), orthographic projection matrix, DrawIndexed with texture-based batch sorting
- **Keyboard input** — Full 256-key polling via GetAsyncKeyState with rising-edge detection
- **ESC menu** — Toggle with M key, arrow navigation, teal accent highlight (#2A9D8F), close with Enter/Esc
- **Textures** — PNG/JPG/BMP/TGA loading via stb_image, 64-slot SRV cache, atlas registry by ID
- **DrawWindow** — 9-slice windows with 2px borders, accent corners, title bar, gradient background
- **DrawString** — Text rendering with colored-rect fallback, 3 font sizes, multi-line support
- **DrawPlasma** — Animated gradient effect (placeholder for procedural plasma)
- **Save system** — Full CRC-16 CCITT, real file I/O via CreateFile/ReadFile/WriteFile, 7-slot management, character data access (HP, MP, stats, equipment, aeons)
- **Fullscreen** — F11 toggle, window resize with backbuffer recreation
- **FPS counter** — Color-coded bar in top-left (green >48fps, yellow >30fps, red below)
- **Lua 5.1** — Complete VM compiled and linked (27 .c files, unmodified)

### 🔄 In Progress
- **Battle HUD** — Actor system (12 slots), action queue, CTB, ATEL scripts. Data model working, visual rendering being implemented
- **Menu system** — 32-slot pool, per-menuId context, scroll, pages, navigation, confirm/cancel. High-level API working, config pages being built
- **Atlas system** — 6 menu textures registered (meswin, menu_new, ffx_bg, stonetexture, summonbg, icon), atlas ID dispatch implemented

### ❌ Stubbed (Next Steps)
- **Field/3D** — Scene loading, 3D rendering, camera, lighting — 5% done
- **Battle HUD rendering** — HP bars, CTB ring, overdrive gauge, status icons — 0% done
- **Save/Load UI** — Save crystal orchestrator with scene freeze — 10% done
- **PhyreEngine Type System** — PClassDescriptor, PNamespace — PClass partial, type system needed for asset loading
- **FMOD Audio** — Music and SFX — stub
- **Steam API** — Achievements, cloud save — stub
- **Iggy UI** — PhyreEngine UI middleware — stub
- **DirectInput / XInput** — Gamepad, analog controls — stub

---

## Architecture

```
ffx-reconstructed/
├── src/
│   ├── ffx/                    # Core game logic
│   │   ├── main.cpp            # Entry point, game loop, init chain
│   │   ├── ffx_renderer.cpp    # D3D11 device, swapchain, shaders
│   │   ├── ffx_renderqueue.cpp # Deferred quad batching pipeline
│   │   ├── ffx_texture.cpp     # Texture manager (stb_image + SRV cache)
│   │   ├── ffx_input.cpp       # Keyboard input polling
│   │   ├── ffx_menu.cpp        # Escape menu system + menu2D primitives
│   │   ├── ffx_battle.cpp      # Battle data model + actions
│   │   ├── ffx_field.cpp       # Field/scene system
│   │   ├── ffx_save.cpp        # Save/load + CRC-16 + slot management
│   │   └── ffx_debug.cpp       # Debug logging + dev tools
│   ├── phyre/                  # PhyreEngine stubs + implementations
│   ├── include/                # Project headers
│   ├── lua-real/               # Lua 5.1 VM (real, full)
│   ├── bullet/                 # Bullet Physics stubs
│   └── lua/                    # Lua bridge stubs
├── stubs/                      # Middleware stubs (Steam, FMOD, Iggy, D3D11, Win32)
├── include/                    # Third-party headers (Bullet, FMOD, ImGui, Lua, stb, zlib)
└── CMakeLists.txt              # Visual Studio 2022/2026, Win32, /MD /O2 /LTCG
```

### Render Pipeline

```
FFX_Renderer_BeginFrame()
  ├── OMSetRenderTargets(1, &RTV, NULL)
  └── ClearRenderTargetView(RTV, clearColor)

[Scene drawing]
  ├── FFX_RenderQueue_PushRect()    — solid/gradient quads
  ├── FFX_RenderQueue_PushQuad()    — UV-mapped quads with per-vertex colors
  ├── FFX_RenderQueue_PushQuadTex() — textured quads with SRV
  └── FFX_Renderer_DrawTestTriangle() — RGB test triangle

FFX_RenderQueue_Flush()
  ├── Map vertex buffer (WRITE_DISCARD)
  ├── Build orthographic projection matrix
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
- **Visual Studio 2022 or 2026** with C++ desktop workload
- **CMake** 3.20+ (bundled with VS)

### Build
```bash
cd ffx-reconstructed
cmake -S . -B build -G "Visual Studio 17 2022" -A Win32
cmake --build build --config Release
```

The executable will be at `build/Release/FFX_Reconstructed.exe`.

### Controls
| Key | Action |
|-----|--------|
| `M` | Toggle ESC menu |
| `↑/↓` | Navigate menu |
| `Enter` | Confirm / close menu |
| `Esc` | Close menu / quit game |
| `F11` | Toggle fullscreen |

---

## The Journey

This is the culmination of one of the largest Final Fantasy X reverse engineering efforts ever:

- **45,114 functions** completely analyzed and renamed in the IDA database
- **291 structs** mapped, including PClassDescriptor (type system), PRenderer, PAnimation, Bullet physics, HUD system, and more
- **91 vtables** identified and typed in .rdata
- **~95.7%** of stubs converted to real implementations
- **~76,500+ lines** of reconstruction code generated
- **25+ open-source libraries** integrated: Bullet Physics, Lua 5.1, zlib, stb, ImGui, FMOD (stub), Steam (stub)

The knowledge base is documented in:
- `src/include/ffx_structs.h` — 20 FFX/PhyreEngine structs with named fields
- `src/include/ffx_vtables.h` — 4 vtables with 35 mapped entries

---

## License

MIT — This is an educational reverse engineering and research project. It contains no original Square Enix code, only original implementations based on software behavior observation. Final Fantasy X is property of Square Enix.
