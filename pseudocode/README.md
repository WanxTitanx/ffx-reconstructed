# FFX Reconstruction — Pseudocode Directory

## Directory Structure

```
pseudocode/
├── README.md                 ← This file
├── title_screen/             ← Title screen rendering subsystem
│   ├── FFX_System_DrawTitleScreen.c
│   ├── FFX_Title_DrawScreenBackground.c
│   ├── FFX_System_TitleScreenTick.c
│   ├── FFX_Title_DrawCopyrightScreen.c
│   ├── FFX_Title_DrawSplashOverlay.c
│   ├── FFX_Title_LoadingFlashScreen.c
│   ├── FFX_Title_LoadGame.c
│   ├── FFX_UI_TitleAndMenuFlow.c
│   ├── FFX_System_DrawTitleOrField.c
│   └── FFX_PS3_LoadTitleScreenTextures.c
├── menu2d/                   ← 2D menu rendering subsystem
│   ├── FFX_Menu2D_TitleBarDraw.c
│   ├── FFX_Menu2D_DrawAtlasQuad.c
│   ├── FFX_Menu2D_DrawAtlasQuadGeneric.c
│   ├── FFX_Menu2D_DrawCharQuadWithColor.c
│   ├── FFX_Menu2D_DrawTextHeaderWithColor.c
│   ├── FFX_Menu2D_DrawTextBlockGradient.c
│   ├── FFX_Menu2D_DrawStringCenteredInternal.c
│   ├── FFX_Menu2D_DrawFormattedNumber.c
│   ├── FFX_Menu2D_TexHandleByAtlasId.c
│   ├── FFX_Menu2D_GetAtlasDimensions.c
│   ├── FFX_Menu2D_TableLookupAtlasBase.c
│   ├── FFX_Menu2D_DrawTexQuadAtlas.c
│   ├── FFX_Menu2D_RenderSolidColorQuad.c
│   ├── FFX_Menu2D_RenderColorQuad.c
│   ├── FFX_Menu2D_RenderEnqueueQuad.c
│   ├── FFX_Menu2D_ScaleX_1920To512.c
│   └── FFX_Menu2D_ScaleY_1080To416.c
├── font/                     ← Font rendering subsystem
│   ├── FFX_Menu_DrawString.c
│   ├── FFX_Menu_DrawRowString.c
│   ├── FFX_Menu_DrawRowStringDefault.c
│   ├── FFX_TextLayout_RenderStringWithColor.c
│   ├── FFX_System_DisplaySplashLoad_structural.c
│   ├── FFX_Menu2D_DrawAtlasQuad_FullSize.c
│   └── FFX_Font_GetSafeColorKey.c
└── boot/                     ← Boot/system initialization
    ├── FFX_System_SystemBootSequence.c
    ├── FFX_Scene_FieldServiceTick.c
    └── FFX_Scene_MainLoopTick.c
```

## Key Findings

### Internal Resolution
The menu rendering system uses an **internal resolution of 512x416**, scaled from the native 1920x1080:

- **ScaleX_1920To512**: `v * 512.0 / 1920.0` (at `0x644990`)
- **ScaleY_1080To416**: `v * 416.0 / 1080.0` (at `0x6449D0`)

All menu operations (drawing, clipping, positioning) work in this 512x416 coordinate space.

### Color System
Colors are RGBA bytes packed into 32-bit integers with alpha:
- **128 (0x80)**: Default/normal brightness — this is the standard alpha for opaque elements
- **0 (0x00)**: Black / fully transparent
- **255 (0xFF)**: Double brightness / fully opaque
- Color values are typically passed as 4 bytes (R, G, B, A) packed into a single int

### Font Rendering
Fonts are rendered using the **menu atlas texture** (`meswin.dds.phyre`), NOT a separate bitmap font like `xfont1208`:

- Text is rendered via atlas sprite lookups in the meswin atlas (atlas ID 15872, 256x256)
- Characters are mapped to atlas IDs (digits 0-9 use atlas ID = char + 560, or specific IDs 0x260-0x262)
- `FFX_Menu2D_DrawCharQuadWithColor` handles individual character glyph rendering from the atlas
- `FFX_TextLayout_RenderStringWithColor` is the core string layout engine
- Styled text (type 4 in buffer) supports color wrapping and scaling
- Newline advances: 16px per row (or 13.6px with scale 0.63)

### Clip Rect
The menu rendering clip rectangle is **512x416** for all menu operations:
- `FFX_Menu2D_SetClipRect4(0, 0, 512, 416)` — default full-screen clip
- `FFX_Menu2D_SetClipRectCoord(0, 0, 512, 416)` — alternative clip API
- `FFX_Menu2D_SetClipRectWH(x, y, w, h)` — per-element clip adjustment

### Texture Paths
Menu textures are loaded from locale-specific paths:
```
/FFX_Data/GameData/PS3Data/menu/D3D11/{asset}.dds.phyre
```

Localized versions exist for each locale:
- `menu_us/` — US English (default)
- `menu/` — Japanese
- `menu_fr/` — French
- `menu_es/` — Spanish
- `menu_de/` — German
- `menu_it/` — Italian
- `menu_kr/` — Korean
- `menu_ch/` — Chinese

### Key Atlas Textures (atlas ID → file → dimensions)

| Atlas ID | File | Dimensions | Usage |
|----------|------|------------|-------|
| 15808 | `icon.dds.phyre` | 256×128 | Icon sprites |
| 15872 | `meswin.dds.phyre` | 256×256 | Menu window sprites, font glyphs |
| 16000 | `battle_kuang.dds.phyre` | 2048×1024 | Title screen background |
| 16001 | `texture.dds.phyre` | 512×256 | Generic menu textures |
| 16002 | `ffx_bg.dds.phyre` | 512×512 | FFX background |
| 16003 | `menu_new.dds.phyre` | 2048×1024 | Menu new asset |
| 16004 | `stonetexture.dds.phyre` | 1024×1024 | Stone texture |
| 16006 | `summonbg.dds.phyre` | 1024×1024 | Summon background |
| 16128 | `battle.dds.phyre` | 256×256 | Battle atlas sprites |

### Atlas ID Ranges (used in DrawAtlasQuad)
- **0–198**: Sprite data from meswin atlas (15872)
- **200–398**: Sprite data from meswin atlas (15872), index = ID - 200
- **400–598**: Atlas base from battle atlas (16128), index = ID - 400
- **600–631**: Pack data from icon atlas (15808), index = ID - 600

### Boot Flow
1. `FFX_Scene_MainLoopTick` — Main loop: timer update, particles, render begin, message pump
2. `FFX_Scene_FieldServiceTick` — Field service: input, encounter, scene management, rendering
3. `FFX_System_SystemBootSequence` — System boot: config load, subsystem init, menu display

## Source Database
- **Binary**: FFX.exe (PS3 port)
- **IDA DB session**: 1b332ea0
