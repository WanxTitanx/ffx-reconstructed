# FFX Reconstructed — Development Log

## Project Goal
Reconstruct the FFX.exe engine in C++ from reverse engineering of the original executable, producing a Windows .exe that boots through the same sequence as the real game.

## Architecture

### D3D11 Renderer (`ffx_renderer.cpp`)
- Device + SwapChain + RTV created via `LoadLibrary("d3d11.dll")` + `GetProcAddress` — zero static dependency on d3d11.lib
- Inline HLSL shaders compiled at runtime via `D3DCompile` from `d3dcompiler_47.dll`
- `BeginFrame()`: OMSetRenderTargets + RSSetViewports + ClearRenderTargetView(dark blue)
- `EndFrame()`: SwapChain->Present(1, 0)
- `DrawTestTriangle()`: 3-vertex NDC triangle with per-vertex RGB colors (bypasses render queue)

### Render Queue (`ffx_renderqueue.cpp`)
- Deferred quad batching: up to 2048 quads/frame in a dynamic vertex buffer
- `FFXVertex2D` = 24 bytes: float xyz (12) + float uv (8) + uint32 color (4)
- Index buffer: TL,TR,BL,BL,TR,BR winding per quad
- Orthographic projection matrix (screen-space → clip-space), transposed for HLSL `mul(vector, matrix)`
- Constant buffer: D3D11_USAGE_DYNAMIC + Map(WRITE_DISCARD) — updated per Flush
- Rasterizer state: CULL_NONE, no depth clip
- Blend state: SRC_ALPHA / INV_SRC_ALPHA (required for font rendering)
- Two pixel shaders: solid-color (`return input.color`) and textured (`return tex.Sample() * input.color`)
- Batch sorting by SRV to minimize PSSetShaderResources calls
- `DrawText()`: renders ASCII text using bitmap font atlas as textured quads

### Texture Manager (`ffx_texture.cpp`)
- `FFX_Texture_Load(filePath, name)`: PNG/JPG/BMP/TGA via stb_image → D3D11 texture + SRV
- `FFX_Texture_LoadPhyre(filePath, name)`: .dds.phyre via Phyre decoder → RGBA → D3D11 texture + SRV
- `FFX_Texture_GetSRV(name)`: returns ID3D11ShaderResourceView* by name
- Cache: 256 slots (was 64, caused silent texture drops)
- Atlas registry: maps atlas IDs to named texture slots

### Phyre Texture Decoder (`ffx_phyre_texture.cpp`)
Ported from C# (`PhyreTextureExtractor.cs`) to C++. Byte-exact for ARGB8.

**Container format (.dds.phyre):**
```
[0x00] "RYHPT\0\0\0"  — PhyreEngine cluster magic
[0x0C] "11XD"          — DX11 platform marker
[0x50] m_maxTextureBufferSize — bytes of mip0
[0x54] 0x01020304      — endianness marker
```

**Decode algorithm:**
1. Verify "RYHPT" magic at offset 0
2. Scan for "PTexture2D" instance (not class table entry) in first 16KB
3. Read format token after instance: "ARGB8", "DXT1", "DXT3", "DXT5", "L8"
4. Width = uint32@(pidx - 88), Height = uint32@(pidx - 84)
5. bufferStart = pidx + 11 + len(format) + 38
6. Decode mip0 to RGBA:
   - ARGB8: BGRA → RGBA swap
   - L8: grayscale → RGBA (R=G=B=L, A=255)
   - DXT1: 8 bytes/block, 4x4 blocks, 2 16-bit colors + 2-bit indices
   - DXT3: 16 bytes/block, 4-bit alpha + DXT1 color
   - DXT5: 16 bytes/block, 8-value alpha gradient + DXT1 color

**Supported formats:** ARGB8, DXT1, DXT3, DXT5, L8

### Screen State Machine (`main.cpp`)
```
State 0: Black screen (1s)
State 1: Square Enix logo placeholder (3s)
State 2: Second logo placeholder (3s)
State 3: Intro FMV placeholder (0.5s)
State 4: Title screen = main menu (New Game / Load Game / Options / Credits)
         - ffx_bg.dds.phyre background (DXT1, 2048x1024)
         - water_NN.dds.phyre animation (70 frames, 30fps, DXT5, 1024x256)
         - copyright_nagi.dds.phyre (DXT1, 2048x1024)
         - Menu bars with font rendering
         - Enter/Space → State 5
State 5: Loading screen (2s)
         - loadingbg.dds.phyre (DXT5, 2048x1024)
         - Progress bar
         - Auto-advance → State 6
State 6: In-game menu
         - ffx_bg background
         - meswin.dds.phyre window texture (DXT5, 1024x1024)
         - Menu items (Items, Abilities, Equipment, Status, Formation)
         - Esc → back to State 4
```

### Font Rendering
- Atlas: `menu/xfont1208/d3d11/font_0_0.dds.phyre` (128x256 ARGB8, 16x16 grid, 8x16 px glyphs)
- `DrawText(text, x, y, scale, color, fontSRV, cols, rows, charW, charH)`:
  - Maps each char to (col, row) in atlas
  - Renders as textured quad with UV coordinates
  - Alpha blending enabled for transparent glyph backgrounds

## Key Discoveries (with root cause analysis)

### 1. White Screen (v1.25.0.1)
**Symptom:** Window opens but screen is entirely white.
**Root cause:** `D3D11CreateDeviceAndSwapChain` called with `D3D11_CREATE_DEVICE_DEBUG` flag. If the Direct3D debug layer is not installed (default on Windows), device creation fails with E_FAIL. The return value was ignored in main.cpp, so the game loop ran with NULL device/context/swapchain. All draw calls early-returned on NULL checks. Backbuffer was never cleared or presented.
**Fix:** Remove `D3D11_CREATE_DEVICE_DEBUG` flag. Add error checking on `FFX_Renderer_Init()` return value.

### 2. Access Violation Crash (v1.25.0.3)
**Symptom:** .exe crashes immediately on launch.
**Root cause:** `FFX_Boot_Init` used `float*` pointer arithmetic with byte offsets on a 1KB buffer, causing out-of-bounds access. In x64, pointer arithmetic with `float*` multiplies offsets by 4 (sizeof float), so `ptr + 405` accessed `ptr + 1620 bytes` — well beyond the 1024-byte buffer.
**Fix:** Cast to `char*` before adding byte offsets, then cast back.

### 3. Render Queue Not Drawing (v1.25.0.4)
**Symptom:** Render queue init passes, DrawIndexed is called, but no quads appear on screen. Only the NDC test triangle is visible.
**Root cause:** The orthographic projection matrix was stored in row-major order (C default), but HLSL's `mul(vector, matrix)` treats the matrix as column-major. The matrix was not transposed before uploading to the constant buffer.
**Fix:** Transpose the 4x4 matrix before `Map`/`memcpy` to constant buffer.

### 4. DXT Textures Corrupted (v1.25.0.8)
**Symptom:** ARGB8 textures render correctly, but DXT1/DXT5 textures show moire patterns or solid magenta.
**Root cause:** In `decompress_dxt_color_block()`, the output offset calculation was `(py * 4 + 0) * 0 + px * 4` — the `* 0` nullified the row offset, causing all 16 pixels in a 4x4 block to be written to the same 4 positions.
**Fix:** Correct offset: `(y * 4 + x) * 4` for each pixel in the 4x4 block.

### 5. Font Texture Not Loading (v1.25.1.1)
**Symptom:** Font atlas texture loaded successfully (confirmed in log) but `GetSRV()` returned NULL.
**Root cause:** `FFX_MAX_TEXTURES` was 64, but the game loads 84 textures (70 water frames + 10 menu textures + 1 font + 1 loadingbg + 1 ffx_bg duplicate). The font_0_0 was loaded after the 64-slot limit was exceeded, causing `FFX_Texture_CreateFromMemory` to silently fail (no free slot). `GetSRV()` then returned NULL because the texture was never stored.
**Fix:** Increase `FFX_MAX_TEXTURES` from 64 to 256.

### 6. Alpha Blending Required (v1.25.1.1)
**Symptom:** Font atlas renders as test quad but text is invisible on menu bars.
**Root cause:** D3D11 default blend state has `BlendEnable = FALSE`. Font atlas has transparent pixels (alpha=0) between glyphs. Without alpha blending, `texture.Sample() * vertexColor = (0,0,0,0)` replaces the backbuffer with black, making glyphs invisible against dark backgrounds.
**Fix:** Create blend state with `SRC_ALPHA / INV_SRC_ALPHA` and set it in `Flush()` via `OMSetBlendState()`.

## Build Instructions

### Requirements
- Windows 10+
- Clang 22+ (or MSVC 2022 with C++ workload)
- Windows SDK (for d3d11.h, dxgi.h, windows.h)

### Build with Clang
```bash
cd ffx_reconstructed
clang++ -Isrc\ffx -Isrc\include -Isrc -Iinclude -Istubs -Isrc\lua-real \
    -std=c++17 -O0 -DWIN32_LEAN_AND_MEAN -D_CRT_SECURE_NO_WARNINGS \
    -Wno-microsoft-goto -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast \
    -Wno-writable-strings -Wno-deprecated-declarations -Wno-macro-redefined \
    -Wno-int-to-void-pointer-cast -Wno-void-pointer-to-int-cast \
    -o build_test\FFX_Reconstructed.exe \
    src\ffx\*.cpp src\phyre\*.cpp src\bullet\*.cpp stubs\*.cpp src\lua\lua_stubs.cpp \
    -ld3d11 -ldxgi -ldinput8 -lxinput -lwinmm -ladvapi32 -luser32 -lgdi32 -lshell32 -lole32
```

### Data Setup
Create a junction link from `data/` to the extracted game files:
```cmd
mklink /J data "E:\...\FFX\data\FFX_Data\ffx_data\gamedata\ps3data"
```

### Controls
| Key | Action |
|-----|--------|
| ↑/↓ | Navigate menu |
| Enter/Space | Confirm / advance |
| Esc | Back / quit |
| F11 | Toggle fullscreen |
| M | Toggle debug menu |

## File Structure
```
ffx_reconstructed/
├── src/
│   ├── ffx/
│   │   ├── main.cpp              # Entry point, game loop, screen state machine
│   │   ├── ffx_renderer.cpp     # D3D11 device, swapchain, shaders
│   │   ├── ffx_renderqueue.cpp  # Quad batching, DrawText, blend/rasterizer state
│   │   ├── ffx_texture.cpp      # Texture manager (stb_image + Phyre loader)
│   │   ├── ffx_phyre_texture.cpp # .dds.phyre decoder (ARGB8/DXT1/DXT3/DXT5/L8)
│   │   ├── ffx_input.cpp        # Keyboard input polling
│   │   ├── ffx_menu.cpp         # Menu system
│   │   ├── ffx_battle.cpp       # Battle data model
│   │   ├── ffx_battle_hud.cpp   # Battle HUD
│   │   ├── ffx_field.cpp        # Field/scene system
│   │   ├── ffx_save.cpp         # Save/load with CRC-16
│   │   └── ffx_debug.cpp        # Debug logging
│   ├── phyre/                   # PhyreEngine stubs
│   ├── include/                 # Headers (ffx_structs.h, ffx_vtables.h, stb_image.h)
│   ├── bullet/                  # Bullet Physics stubs
│   └── lua/                     # Lua bridge stubs
├── stubs/                       # Middleware stubs (Steam, FMOD, Iggy, D3D11, Win32)
├── assets/title/                # PNG assets from metamenu
├── data/                        # Junction link to extracted game data
├── build_test/                  # Build output + screenshots
└── docs/                        # Documentation
```

## Current State (v1.25.1.1)

### Working
- D3D11 renderer with render queue
- .dds.phyre native decoder (ARGB8, DXT1, DXT3, DXT5, L8)
- Boot sequence (7 states)
- Title screen with ffx_bg background + water animation (70 frames @ 30fps)
- Menu navigation (↑/↓/Enter/Esc)
- Screen transitions (title → loading → in-game menu)
- Font rendering pipeline (glyphs visible, mapping needs tuning)
- Alpha blending
- 84 textures loaded from game data
- VBF extraction complete (71,979 files, 28.7GB)

### In Progress
- Font character mapping (xfont1208 atlas layout)
- FMV playback (.webm via Media Foundation or libvpx)
- Phyre mesh format parsing (for 3D models)

### Not Started
- 3D rendering (models, fields, battles)
- Audio (FMOD)
- Save/Load UI
- Game logic (battle system, event scripting)
