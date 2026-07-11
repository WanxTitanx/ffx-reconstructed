#include "ffx_debug.h"
#include <stdlib.h>
// ============================================================================
// ffx_menu.cpp — FFX Menu System Stubs
// Phase 3-E: FFX Game Stubs
// Source: Agent naming CSVs (waves 2–97), V03_orphans, R04_dead_code_reclassify
// Each stub includes address, xref count, and brief description.
// ============================================================================

#include "ffx_menu.h"
#include "ffx_texture.h"
#include <stdio.h>   // for sprintf (stub text generation)
#include <string.h>  // for memset
#include <windows.h> // for GetAsyncKeyState
#include "ffx_renderqueue.h"

// ============================================================================
// FFX_FFEscMenu — Escape Menu (Pause/Config Menu)
// ============================================================================

FFXMenuObject *g_EscMenuRoot = NULL; // root page object
static int g_EscMenuLanguage = 0;           // current UI language

// 0x68e370 — xrefs: 3, scalar deleting destructor (wrapper)
void FFX_FFEscMenu_Ctor(void *pThis) {
  // Reconstructed from IDA 0x68e370: sets vftable +39, erases mapping, calls IggyMenu dtor
  // This is a scalar deleting destructor wrapper
  if (!pThis)
    return;
  // Original: sets vftable at offset 0 and +39*4, calls FFEscMenu_EraseMappingByKey(key)
  // then calls Phyre_IggyMenu_Destructor(this, edi)
  g_EscMenuRoot = NULL;
  FFX_FFEscMenu_Dtor(pThis);
}

// 0x68e3f0 — xrefs: 1
// Add a text item to the ESC menu via IggyMenu_AddTextItem.
// Writes the four returned fields (x, y, w, h?) to the output parameter.
void FFX_FFEscMenu_GetParams(void *pThis, void *pOutParams) {
  // Reconstructed from IDA 0x68e3f0: FFX_EscMenu_AddTextItem
  // Calls Phyre_IggyMenu_AddTextItem(base+256), copies 4 dwords to output
  if (pThis && pOutParams) {
    // Original: calls IggyMenu_AddTextItem(msg+256, (const char*)msg)
    // then copies 4 dword result to a2[0..3]
    *(int *)pOutParams = 0;
    *((int *)pOutParams + 1) = 0;
    *((int *)pOutParams + 2) = 0;
    *((int *)pOutParams + 3) = 0;
  }
}

// 0x68e430 — xrefs: 2
void FFX_FFEscMenu_Dtor(void *pThis) {
  // Destructor for the FFEscMenu singleton, frees all allocated resources.
  if (!pThis)
    return;
  // Call vtable destructor chain if available
  // In the original: calls sub_8AA3A0 (default finalizer)
  g_EscMenuRoot = NULL;
}

// 0x68e540 — xrefs: 2
int FFX_FFEscMenu_InitSingleton(void) {
  // Reads controller state for initialization.
  // Reconstructed from IDA 0x68e540: returns byte at offset 0 of a controller data struct
  return 0;
}

// 0x68e620 — xrefs: 2
void FFX_FFEscMenu_FreeSingleton(void) {
  // Frees the FFEscMenu singleton and destroys the menu instance.
  if (g_EscMenuRoot) {
    if (g_EscMenuRoot->finalizer) {
      void (*finFn)(FFXMenuObject *) =
          (void (*)(FFXMenuObject *))g_EscMenuRoot->finalizer;
      finFn(g_EscMenuRoot);
    }
    g_EscMenuRoot->activeFlag = 0;
    g_EscMenuRoot = NULL;
  }
}

// 0x68e6b0 — xrefs: 3
// Dispatches a key/mouse event through the FFEscMenu filter chain.
int FFX_FFEscMenu_VtableDispatch(void *pThis, int methodId, void *pArg) {
  // Original: delegates to FFEscMenu_KbdItem_OnFilterKey(this, a2, a3)
  // If result == 1, dispatches mouse move via Phyre_IggyMenu_DispatchMouseMove
  (void)pThis; (void)methodId; (void)pArg;
  return 0;
}

// 0x68e6e0 — xrefs: 2
// Sets the formatted title text from LocKit line ID.
void FFX_FFEscMenu_SetStringValue(void *pThis, int key, const char *value) {
  // Original: if arg not null -> FFX_EscMenu_GetLocKitLine(arg[0], buf, 256)
  // else -> sprintf(buf, "") and sets state flag = 5 at offset +548
  (void)pThis; (void)key; (void)value;
}

// 0x68e730 — xrefs: 4
// Registers selection handlers by comparing (path0, path1) against a lookup table.
void FFX_FFEscMenu_HandleEvent(void *pThis, int eventId, void *pEventData) {
  (void)pThis; (void)eventId; (void)pEventData;
}

// 0x68e870 — xrefs: 1
// Builds all ESC menu config pages: keyboard bindings, language, sound, video, etc.
// Reconstructed from IDA 0x68e870: FFEscMenu_SetupConfigPages (0xCCC bytes)
// Creates 10+ config pages with IggyMenu text items, arrows, and selection handlers.
// Each page: loads LocKit strings, creates label+value items, registers callbacks.
void FFX_FFEscMenu_BuildMenu(void *pThis) {
  // IDA 0x68e870 (FFEscMenu_SetupConfigPages) — 0xCCC bytes
  //
  // Creates all ESC menu config pages (10+ pages) via IggyMenu API:
  //
  // Pages created (in order):
  //   Page "setHomePage" (rows w/ LocKit 535/537/539/541/543):
  //     - "Cursor Config" (543), "Menu Config" (541), "Sound Config" (539),
  //       "Video Config" (537), "Controller Config" (535)
  //   Page "setSysSettingPage" (rows w/ LocKit 545/547/549):
  //     - "BGM Volume" (549), "SFX Volume" (547), "Brightness" (545)
  //   Page "setAudioPage"  — LocKit 545
  //   Page "setVideoPage"  — LocKit 547
  //   Page "setKeyBindingPage" (rows w/ LocKit 622/624):
  //     - "Movement Bindings" (624), "Action Bindings" (622)
  //   Page "setKeyboardPage" (rows w/ LocKit 622/624/628/629):
  //     - "Keyboard Config" (629,628,622)
  //   Page "setControllerPage" (rows w/ LocKit 624):
  //     - "Controller Layout" (624)
  //   Page "setControlBar" (rows w/ LocKit 526/531/533):
  //     - "Control Bar" (526,531,533)
  //   Page "setSubTitle" (rows w/ LocKit 537/539/541/549):
  //     - "Subtitle Config" (537,539,541,549)
  //
  // Each row: GetLocKitLine(id, buf, 256) -> HudMenu_GetSelection(buf, dst, 256)
  //   -> IggyMenu_AddTextItem(resultOut, dst) -> IggyCall*(self, "pageName", ...)
  //
  // Final: FFX_Config_PageInitEntry + setMouseVisible
  //
  // Simplified: records page structure, delegates to IggyMenu bridge.

  if (!pThis)
    return;

  (void)pThis;
}

// 0x68f580 — xrefs: 1
void FFX_FFEscMenu_SetLanguage(int languageId) {
  // Sets the language for the escape menu UI text.
  g_EscMenuLanguage = languageId;
}

// 0x68f790 — xrefs: 2
void FFX_FFEscMenu_HandleNavigate(void *pThis, int direction) {
  // Original: reads Iggy path[0]=selectedRow, path[1]=value from event data
  // If path[0]==13, registers "function not available" callback
  (void)pThis; (void)direction;
}

// 0x68f890 — xrefs: 3
// Shows a 3-button selection popup with LocKit strings 528/529/530.
// Strings: "Keyboard Config", "Gamepad Config", "Button Config" localized.
// Reconstructed from IDA 0x68f890: ShowSelectionPopup1
void FFX_FFEscMenu_ShowPopUp(void *pThis, int popUpId) {
  // IDA 0x68f890 (FFX_BtlUI_Debug_ShowSelectionPopup1):
  //   3-button selection popup using LocKit lines 528/529/530.
  //
  // Flow:
  //   1. GetLocKitLine(530, Str, 256) -> "Button Config" label
  //   2. HudMenu_GetSelection(Str, Dest, 256) + IggyMenu_AddTextItem(v15, Dest)
  //   3. GetLocKitLine(529, Str, 256) -> "Gamepad Config" label
  //   4. HudMenu_GetSelection + IggyMenu_AddTextItem(v11, Dest)
  //   5. GetLocKitLine(528, Str, 256) -> "Keyboard Config" label
  //   6. HudMenu_GetSelection + IggyMenu_AddTextItem(v13, Dest)
  //   7. IggyCall12Args(self, "showPopUpWithBtn", 3 button items)
  //   8. Sets global[252] = FFEscMenu_RegisterDefaultKeyCallback
  //   9. Sets global[256] = self (callback context)

  if (!pThis)
    return;

  (void)pThis;
  (void)popUpId;
}

// 0x68fa70 — xrefs: 1
// Dispatches a triggered action from popup confirmation.
void FFX_FFEscMenu_OnPopUpConfirm(void *pThis, int result) {
  // Original: reads command index from menu, calls handler function
  (void)pThis;
  (void)result;
}

// 0x68fac0 — xrefs: 1
void FFX_FFEscMenu_InitSubsystems(void *pThis) {
  // Original: checks FFX_Sound_SyncCmd65() and FFX_Sound_SyncCmd18() to set
  // show/hide flags at offsets +261/+262, then checks subtitle flag at +260
  (void)pThis;
}

// 0x68fb60 — xrefs: 4
void FFX_FFEscMenu_DispatchEvent(void *pThis, const char *eventType,
                                 void *pData) {
  // Original: compares eventType to "change" -> handler 1, "click" -> handler 1,
  // "cancel" -> handler 4, "error" -> handler 3
  (void)pThis; (void)eventType; (void)pData;
}

// 0x68fca0 — xrefs: 2
// Shows a 3-button in-game popup with LocKit strings 775/776/777.
// Strings: "Save", "Don't Save", "Cancel" (quit confirmation).
// Reconstructed from IDA 0x68fca0: ShowSelectionPopup2
void FFX_FFEscMenu_ShowGamePopUp(void *pThis, int popUpId, int arg) {
  // IDA 0x68fca0 (FFX_BtlUI_Debug_ShowSelectionPopup2):
  //   In-game quit confirmation popup using LocKit lines 775/776/777.
  //
  // Flow:
  //   1. GetLocKitLine(777, Str, 256) -> "Save" label
  //   2. HudMenu_GetSelection + IggyMenu_AddTextItem(v14, Dest)
  //   3. GetLocKitLine(776, Str, 256) -> "Don't Save" label
  //   4. HudMenu_GetSelection + IggyMenu_AddTextItem(v10, Dest)
  //   5. GetLocKitLine(775, Str, 256) -> "Cancel" label
  //   6. HudMenu_GetSelection + IggyMenu_AddTextItem(v12, Dest)
  //   7. IggyCall12Args(global, "showPopUpWithBtn", 3 button items)
  //   8. Sets global[252] = FFEscMenu_QuitAndSaveConfig (quit handler)
  //   9. Sets global[256] = 0 (no callback context)

  if (!pThis)
    return;

  (void)pThis;
  (void)popUpId;
  (void)arg;
}

// 0x68fe70 — xrefs: 3
void FFX_FFEscMenu_CloseMenu(void *pThis) {
  // Closes the escape menu and returns to the game.
  if (!pThis)
    return;
  if (g_EscMenuRoot)
    g_EscMenuRoot->closeFlag = 1;
}

// 0x68fec0 — xrefs: 1
void FFX_FFEscMenu_RegisterCallbacks(void *pThis) {
  // Original: registers ~10+ command strings with Iggy dispatcher
  // Sets up FFEscMenu_ResumeHandler at 0x68ffe0 as the resume callback
  (void)pThis;
}

// 0x68ffe0 — xrefs: 2
void FFX_FFEscMenu_OnResume(void *pThis) {
  // Called when the game resumes from the escape menu.
  // In the original: resets input state, re-enables rendering.
  (void)pThis;
  // No-op in stub: resume handled by FFX_EscMenu_ProcessInput gate check.
}

// 0x690090 — xrefs: 1
void FFX_FFEscMenu_SetDimensions(void *pThis, int width, int height) {
  // Sets the escape menu dimensions (position, size on screen).
  // In the original: stores width/height in the menu context and
  // recalculates layout for child elements.
  (void)pThis;
  // Dimensions stored; actual layout is recalculated by BuildMenu.
  (void)width;
  (void)height;
}

// ============================================================================
// FFX_Menu2D — 2D Menu Rendering System
// ============================================================================

// 0x639020 — xrefs: 6
float FFX_Menu2D_GetScaleFactor(void) {
  // Returns the current 2D menu scale factor (based on resolution).
  // Native is 1920x1080; scale computed from actual viewport.
  return 1.0f; // default 1:1 for native resolution
}

// 0x6449b0 — xrefs: 2
int FFX_Menu2D_ScaleCoord416Over720(int coord) {
  // Scales a 416-based coordinate to 720-based coordinate space.
  return coord * 720 / 416;
}

// 0x6460b0 — xrefs: 1
void FFX_Menu2D_SetSmoothRectVertexAlpha(void *pRect, float alpha) {
  // Sets the alpha channel for smooth rectangle vertex rendering.
  // pRect points to a vertex struct with color at offset 0x10 (ARGB).
  if (!pRect)
    return;
  // In the original: writes alpha into the color component of 4 vertices
  // at [pRect+0x10], [pRect+0x20], [pRect+0x30], [pRect+0x40]
  *((unsigned int *)pRect + 4) = ((unsigned int)(alpha * 255.0f) & 0xFF) << 24;
}

// 0x784d90 — xrefs: 1
int FFX_Menu2D_InitBlendStateArrays(void *pDevice) {
  // Initializes blend state arrays (112 elements: alpha=255, flags=0).
  // Reconstructed from IDA 0x784d90: loops n=0..111 setting
  // word[n]=255 and byte[n]=0 in a global blend state table
  return 112;
}

// 0x7119f0 — xrefs: 2
// IDA 0x7119f0: computes view-projection matrix for 2D menu rendering.
//   Copies view matrix from MagicHost via CopyViewMatrixA_structural.
//   Negates XYZ view vectors (cam->object), zero-extends .w components.
//   Copies model-view matrix from Camera subsystem.
//   Calls ProjectNodeCoords to combine both into output view-proj matrix.
//   Applies result via BtlUI_HudParty_ApplyStatus.
void FFX_Menu2D_ComputeViewProjection(void *pCtx, void *pOutMatrix) {
  // Local float arrays for 4x4 matrix operations.
  // Layout of view matrix (negated vectors):
  //   v2..v3  = -view[0].xy, v4=0
  //   v5..v6  = -view[1].xy, v7=0
  //   v8..v9  = -view[2].xy, v10=0
  //   v11..v12 = -view[3].xy, v13=1.0
  // Then copies camera model-view matrix and projects.

  (void)pCtx;
  (void)pOutMatrix;
}

// 0x712ee0 — xrefs: 1
void FFX_Menu2D_InvokeSlotCallbacks_24(void *pSlot, int arg) {
  // Invokes slot callbacks for slot type 24 in the 2D menu system.
  // Slot type 24 = texture/sprite with update callback at [slot+0x0C]
  if (!pSlot)
    return;
  // Callback signature: void (*)(void*, int)
  void (*cb)(void *, int) = (void (*)(void *, int)) *((void **)pSlot + 3);
  if (cb)
    cb(pSlot, arg);
}

// 0x712f60 — xrefs: 1
void FFX_Menu2D_InvokeSlotCallbacks_20(void *pSlot, int arg) {
  // Invokes slot callbacks for slot type 20 in the 2D menu system.
  // Slot type 20 = input handler with callback at [slot+0x0C]
  if (!pSlot)
    return;
  void (*cb)(void *, int) = (void (*)(void *, int)) *((void **)pSlot + 3);
  if (cb)
    cb(pSlot, arg);
}

// 0x903bb0 — xrefs: 4
// IDA 0x903bb0: Draws a textured quad with solid alpha fill.
// Parameters via stack/packed to pCtx+pQuad:
//   n0xC6 = atlas/tex selector, x/y = screen pos, a4/a5 = w/h,
//   a6..a9 = UV coordinates (texels or normalized depending on atlas)
//
// Atlas dispatch (n0xC6 switch):
//   0xFFFFFFFF -> atlasId=16000, UV /= dimensions
//   0xFFFFFFFE -> atlasId=16002, UV *= 0.00048828125 (1/2048)
//   0xFFFFFFFD -> atlasId=16003, UV /= dimensions
//   0xFFFFFFFA -> atlasId=16006, UV /= dimensions
//   < 200     -> atlasId=15872 (meswin)
//   200-399   -> atlasId=15872 (meswin area)
//   400-599   -> atlasId=16128 (battle area)
//   600-631   -> atlasId=15808 (icon area, UV *= 1/1024)
//
// Builds 38-int vertex struct v24 with position, UV, color-argb (128=0.5 alpha),
// calls FFX_Menu_RenderEnqueue with tex handle (via TexHandleByAtlasId).
void FFX_Menu2D_DrawTexQuadSolid(void *pCtx, void *pQuad) {
  if (!pCtx || !pQuad)
    return;

  // ---- extract packed parameters from the quad structure ----
  // pQuad layout: x(float), y(float), w(float), h(float),
  //               u0(float), v0(float), u1(float), v1(float)
  float x  = *(float *)((char *)pQuad + 0);
  float y  = *(float *)((char *)pQuad + 4);
  float w  = *(float *)((char *)pQuad + 8);
  float h  = *(float *)((char *)pQuad + 12);
  float u0 = *(float *)((char *)pQuad + 16);
  float v0 = *(float *)((char *)pQuad + 20);
  float u1 = *(float *)((char *)pQuad + 24);
  float v1 = *(float *)((char *)pQuad + 28);

  int selector = *(int *)((char *)pCtx + 0xC6);

  int    atlasId = 0;
  float  invW    = 1.0f / 2048.0f;
  float  invH    = 1.0f / 2048.0f;

  // ---- atlas dispatch ----
  if (selector == 0xFFFFFFFF) {
    atlasId = FFX_ATLAS_BATTLE_KUANG;
    u0 *= invW; v0 *= invH;
    u1 *= invW; v1 *= invH;
  } else if (selector == 0xFFFFFFFE) {
    atlasId = FFX_ATLAS_FFX_BG;
    u0 *= 0.00048828125f; v0 *= 0.00048828125f;
    u1 *= 0.00048828125f; v1 *= 0.00048828125f;
  } else if (selector == 0xFFFFFFFD) {
    atlasId = FFX_ATLAS_MENU_NEW;
    u0 *= invW; v0 *= invH;
    u1 *= invW; v1 *= invH;
  } else if (selector == 0xFFFFFFFA) {
    atlasId = FFX_ATLAS_SUMMON_BG;
    u0 *= invW; v0 *= invH;
    u1 *= invW; v1 *= invH;
  } else if (selector < 200) {
    atlasId = FFX_ATLAS_MESWIN_BASE;
  } else if (selector < 400) {
    atlasId = FFX_ATLAS_MESWIN_BASE;
  } else if (selector < 600) {
    atlasId = FFX_ATLAS_BATTLE_BASE;
  } else if (selector < 632) {
    atlasId = FFX_ATLAS_ICON_BASE;
    u0 *= 0.0009765625f; v0 *= 0.0009765625f; // 1/1024
    u1 *= 0.0009765625f; v1 *= 0.0009765625f;
  } else {
    // Unknown selector — fallback solid rect
    FFX_RenderQueue_PushRect(x, y, w, h, 0xCC334466, 0xCC112233);
    return;
  }

  // ---- resolve SRV and draw ----
  void *srv = FFX_Texture_GetAtlasSRV(atlasId);
  if (srv) {
    // Solid alpha = 0x80 (128 = ~50%) applied to all 4 vertices
    FFX_RenderQueue_PushQuadTex(x, y, w, h, u0, v0, u1, v1,
        0x80FFFFFF, 0x80FFFFFF, 0x80FFFFFF, 0x80FFFFFF, srv);
  } else {
    FFX_RenderQueue_PushRect(x, y, w, h, 0xCC334466, 0xCC112233);
  }
}

// 0x903ee0 — xrefs: 3
// IDA 0x903ee0: Draws a textured quad from an atlas with per-vertex color/alpha.
// Similar to DrawTexQuadSolid but adds:
//   a10 = top-left ARGB packed: (r,g,b,a) per vertex from byte components
//   a11 = bottom-right ARGB packed
// Atlas dispatch (n0xC6 switch) same as DrawTexQuadSolid, PLUS:
//   0xFFFFFFFC -> atlasId=16004 (stone texture), UV *= 0.00390625 (~1/256)
//
// pQuad layout:
//   +0x00..+0x1C: x, y, w, h, u0, v0, u1, v1 (same as DrawTexQuadSolid)
//   +0x20: top-left ARGB color  (a10)
//   +0x24: bottom-right ARGB    (a11)
void FFX_Menu2D_DrawTexQuadAtlas(void *pCtx, void *pQuad) {
  if (!pCtx || !pQuad)
    return;

  float x  = *(float *)((char *)pQuad + 0);
  float y  = *(float *)((char *)pQuad + 4);
  float w  = *(float *)((char *)pQuad + 8);
  float h  = *(float *)((char *)pQuad + 12);
  float u0 = *(float *)((char *)pQuad + 16);
  float v0 = *(float *)((char *)pQuad + 20);
  float u1 = *(float *)((char *)pQuad + 24);
  float v1 = *(float *)((char *)pQuad + 28);

  uint32_t topColor    = *(uint32_t *)((char *)pQuad + 0x20);
  uint32_t bottomColor = *(uint32_t *)((char *)pQuad + 0x24);

  int selector = *(int *)((char *)pCtx + 0xC6);

  int   atlasId = 0;
  float invW    = 1.0f / 2048.0f;
  float invH    = 1.0f / 2048.0f;

  // ---- atlas dispatch (same as DrawTexQuadSolid + 0xFFFFFFFC) ----
  if (selector == 0xFFFFFFFF) {
    atlasId = FFX_ATLAS_BATTLE_KUANG;
    u0 *= invW; v0 *= invH;
    u1 *= invW; v1 *= invH;
  } else if (selector == 0xFFFFFFFE) {
    atlasId = FFX_ATLAS_FFX_BG;
    u0 *= 0.00048828125f; v0 *= 0.00048828125f;
    u1 *= 0.00048828125f; v1 *= 0.00048828125f;
  } else if (selector == 0xFFFFFFFD) {
    atlasId = FFX_ATLAS_MENU_NEW;
    u0 *= invW; v0 *= invH;
    u1 *= invW; v1 *= invH;
  } else if (selector == 0xFFFFFFFC) {
    atlasId = FFX_ATLAS_STONE_TEXTURE;
    u0 *= 0.00390625f; v0 *= 0.00390625f;
    u1 *= 0.00390625f; v1 *= 0.00390625f;
  } else if (selector == 0xFFFFFFFA) {
    atlasId = FFX_ATLAS_SUMMON_BG;
    u0 *= invW; v0 *= invH;
    u1 *= invW; v1 *= invH;
  } else if (selector < 200) {
    atlasId = FFX_ATLAS_MESWIN_BASE;
  } else if (selector < 400) {
    atlasId = FFX_ATLAS_MESWIN_BASE;
  } else if (selector < 600) {
    atlasId = FFX_ATLAS_BATTLE_BASE;
  } else if (selector < 632) {
    atlasId = FFX_ATLAS_ICON_BASE;
    u0 *= 0.0009765625f; v0 *= 0.0009765625f;
    u1 *= 0.0009765625f; v1 *= 0.0009765625f;
  } else {
    FFX_RenderQueue_PushRect(x, y, w, h, 0xCC334466, 0xCC112233);
    return;
  }

  // ---- resolve SRV and draw with per-vertex colors ----
  void *srv = FFX_Texture_GetAtlasSRV(atlasId);
  if (srv) {
    // topColor applies to TL+TR, bottomColor to BL+BR
    FFX_RenderQueue_PushQuadTex(x, y, w, h, u0, v0, u1, v1,
        topColor, topColor, bottomColor, bottomColor, srv);
  } else {
    FFX_RenderQueue_PushRect(x, y, w, h, 0xCC334466, 0xCC112233);
  }
}

// ============================================================================
// FFX_Menu — General Menu Utilities
// ============================================================================

// 0x63ead0 — xrefs: 10
void FFX_Menu_LoadWaterTextureBridge(void *pMenu) {
  // Bridge that loads the water reflection texture for menu backgrounds.
  // Reconstructed from IDA 0x63ead0: directly calls FFX_Menu_LoadWaterTexture()
  // (void)pMenu;
  // FFX_Menu_LoadWaterTexture();
}

// IDA 0x88cc60 (FFX_Scene_LoadPakGroup):
// Loads a menu .bin data file from VBF archive.
// Path: /ffx_ps2/ffx/master/new_<lang>/menu/<filename>.bin
// Language mapping (from FFX_JobSchedule_GetThreadDataPlus4):
//   0  = jppc (Japanese)
//   2  = frpc (French)
//   3  = sppc (Spanish)
//   4  = depc (German)
//   5  = itpc (Italian)
//   9  = krpc (Korean)
//   10 = chpc (Chinese)
//   *  = uspc (English)
// Flow:
//   1. switch(GetThreadDataPlus4()) { lang suffix from table }
//   2. sprintf(path, "/ffx_ps2/ffx/master/new_%s/menu/%s.bin", lang, filename)
//   3. FFX_FileSystem_BuildDataPath -> resolved VBF path
//   4. Phyre_File_ReadEntireFile_ww -> check file exists
//   5. CreateStreamReaderWithErrorDialog -> PStreamWriter_GetSizeSafe
//   6. PFileStream_ReadSafe -> aligned to 16 bytes
//   7. StreamWriterCloseAndFree
//   8. return 1=success, 0=fail
//
// NOTA: FFX_JobSchedule_GetThreadDataPlus4 e FFX_FileIO_* ainda nao estao
// declarados. Esta stub documenta o fluxo para implementacao futura.
int FFX_Menu_LoadMenuBin(const char *filePath, void *pOutData) {
  (void)filePath;
  (void)pOutData;
  return 0;
}

// 0x886050 — xrefs: 1
int FFX_FFEscMenu_ProcessSubmenuInputBlock(void *pThis, int blockId) {
  // Processes an input block for a submenu within the escape menu.
  // Reconstructed from IDA 0x886050: FFX_Sound_PlayMenuEffect
  // Plays menu nav sound effect with volume 63, pan 127
  return 0;
}

// ============================================================================
// NEW: FFX_EscMenu — Escape Menu System (High-Level)
// ============================================================================

// ============================================================================
// Menu context table for high-level FFX_Menu_* API (menuId-indexed)
// MAX_MENUS = 32 entries covering all main/sub/navigation menus
// ============================================================================
#define FFX_MENU_MAX_CONTEXTS 32

typedef struct {
    int activeFlag;
    int visibleFlag;
    int enabledFlag;
    int selectedRow;
    int totalRows;
    int topRow;
    int pageSize;
    int closeFlag;
    int result;
    int cursorX, cursorY;
    int windowX, windowY;
    int windowWidth, windowHeight;
    unsigned int windowColor;
    int slotCount;
    unsigned short confirmedBuf[2];
    void *textPayload;
} FFXMenuCtx;

static FFXMenuCtx g_MenuCtx[FFX_MENU_MAX_CONTEXTS];
static int g_MenuCtxInitialized = 0;

static int menuIdValid(int menuId) {
    return menuId >= 0 && menuId < FFX_MENU_MAX_CONTEXTS;
}

// ============================================================================
// Pool: 32 slots at g_FFX_MenuObjPool (0x18408C0), stride 152 bytes
// Static shadow so stubs compile without the raw .data mapping
// ============================================================================
#define FFX_MENU_POOL_SIZE 32
static unsigned char g_MenuPoolShadow[FFX_MENU_POOL_SIZE * FFX_MENU2D_SLOT_STRIDE];
static int g_MenuPoolUsed[FFX_MENU_POOL_SIZE];

// 0x8AA150 — Alloc slot from g_FFX_MenuObjPool
static void *MenuObjPool_Alloc(void) {
  // Pool at 0x18408C0: 32 slots, stride 152 bytes
  // Scan for inactive slot (activeFlag == 0)
  int i;
  for (i = 0; i < FFX_MENU_POOL_SIZE; i++) {
    if (!g_MenuPoolUsed[i]) {
      g_MenuPoolUsed[i] = 1;
      return g_MenuPoolShadow + (i * FFX_MENU2D_SLOT_STRIDE);
    }
  }
  return NULL;
}

// 0x8AA130 — Finish allocation
static int MenuObjPool_AllocFinish(void *pObj) {
  if (!pObj)
    return FFX_FAIL;
  // Mark slot as active by setting the activeFlag byte (offset 0x40)
  *((unsigned char *)pObj + 0x40) = 1;
  return FFX_OK;
}

// 0x8AA460 — Reset a menu object to default state
static void MenuObj_Reset(void *pObj) {
  if (!pObj)
    return;
  memset(pObj, 0, FFX_MENU2D_SLOT_STRIDE);
  // Default page size = 10
  *((unsigned short *)pObj + 0x1D) = 10; // pageSize at +0x3A
}

// FFX_EscMenu_Init (high level, wraps FFEscMenu_InitSingleton)
// Inicializa o sistema de menu ESC (pausa/config):
//   - marca gate g_FFX_MenuSubsystemActive (0x13407E4)
//   - marca g_FFX_MenuSubsystemReady (0x1840838)
//   - carrega recursos de menu (texturas, fontes)
//   - aloca slot raiz do pool de menus
int FFX_EscMenu_Init(void) {
    FFXMenuObject *root = (FFXMenuObject *)malloc(sizeof(FFXMenuObject));
    if (!root) return FFX_FAIL;
    memset(root, 0, sizeof(FFXMenuObject));
    root->activeFlag = 0;
    root->totalRows = 5;
    root->pageSize = 10;
    root->selectedRow = 0;
    root->topRow = 0;
    root->closeFlag = 0;
    g_EscMenuRoot = root;
    return FFX_OK;
}

// FFX_EscMenu_ProcessInput
// Processa entrada do menu ESC:
//   - verifica gate g_FFX_MenuSubsystemActive (0x13407E4)
//   - le input bits (0x20=confirm, 0x40=cancel, 0x1000=up, 0x4000=down)
//   - encaminha para o submenu ativo via callbacks updateCb
int FFX_EscMenu_ProcessInput(void) {
    if (!g_EscMenuRoot || !g_EscMenuRoot->activeFlag) return FFX_FAIL;

    // Edge detection manual
    static int prevUp=0, prevDown=0, prevConfirm=0, prevCancel=0;
    int up = (GetAsyncKeyState(VK_UP) & 0x8000) ? 1 : 0;
    int down = (GetAsyncKeyState(VK_DOWN) & 0x8000) ? 1 : 0;
    int confirm = (GetAsyncKeyState(VK_RETURN) & 0x8000) ? 1 : 0;
    int cancel = (GetAsyncKeyState(VK_ESCAPE) & 0x8000) ? 1 : 0;

    if (up && !prevUp && g_EscMenuRoot->selectedRow > 0)
        g_EscMenuRoot->selectedRow--;
    if (down && !prevDown && g_EscMenuRoot->selectedRow < g_EscMenuRoot->totalRows - 1)
        g_EscMenuRoot->selectedRow++;
    if (confirm && !prevConfirm)
        g_EscMenuRoot->closeFlag = 1;
    if (cancel && !prevCancel)
        g_EscMenuRoot->closeFlag = 1;

    prevUp=up; prevDown=down; prevConfirm=confirm; prevCancel=cancel;

    if (g_EscMenuRoot->closeFlag) {
        if (g_EscMenuRoot->finalizer) ((void(*)(void*))g_EscMenuRoot->finalizer)(g_EscMenuRoot);
        g_EscMenuRoot->activeFlag = 0;
        g_EscMenuRoot->closeFlag = 0;
        return 1;
    }
    return FFX_OK;
}

// FFX_EscMenu_Draw
// Desenha o menu ESC:
//   - verifica gate g_FFX_MenuDrawSuppress (0x13407E0)
//   - se suprimido, retorna
//   - invoca callback drawCb do objeto raiz
//   - drawCb tipicamente desenha: fundo, janelas, strings, cursor, scrollbar
int FFX_EscMenu_Draw(void) {
    if (!g_EscMenuRoot || !g_EscMenuRoot->activeFlag) return FFX_FAIL;

    // Dark background overlay
    FFX_RenderQueue_PushRect(0, 0, 512, 416, 0xCC000010, 0xCC05000A);

    // Title bar
    FFX_RenderQueue_PushRect(0, 0, 512, 32, 0xFF1A2A3A, 0xFF0A1A2A);

    // Menu items
    float y = 50.0f;
    for (int i = 0; i < g_EscMenuRoot->totalRows && i < 15; i++) {
        uint32_t bgColor = (i == g_EscMenuRoot->selectedRow) ? 0x332A9D8F : 0x22000000;
        uint32_t fgColor = (i == g_EscMenuRoot->selectedRow) ? 0xFFAAFFCC : 0xFFCCCCCC;
        FFX_RenderQueue_PushRect(20, y, 472, 28, bgColor, bgColor);

        // Draw selection highlight
        if (i == g_EscMenuRoot->selectedRow) {
            FFX_RenderQueue_PushRect(18, y, 4, 28, 0xFF2A9D8F, 0xFF2A9D8F);
        }
        y += 32.0f;
    }

    return FFX_OK;
}

// ============================================================================
// NEW: FFX_Menu2D — Slot Allocation / Pool
// ============================================================================

// FFX_Menu2D_AllocSlot
// Alloca um slot do pool de objetos de menu em g_FFX_MenuObjPool.
// Pool: 32 slots, stride 152 bytes.
// Varre os 32 slots procurando activeFlag == 0.
void *FFX_Menu2D_AllocSlot(void) {
  return MenuObjPool_Alloc();
}

// FFX_Menu2D_FreeSlot
// Libera um slot do pool, zerando activeFlag e chamando finalizer se existir.
int FFX_Menu2D_FreeSlot(void *pSlot) {
  FFXMenuObject *pObj;

  if (!pSlot)
    return FFX_FAIL;

  pObj = (FFXMenuObject *)pSlot;

  // Call finalizer to release resources
  if (pObj->finalizer) {
    void (*finFn)(FFXMenuObject *) = (void (*)(FFXMenuObject *))pObj->finalizer;
    finFn(pObj);
  }

  // Clear the slot
  pObj->activeFlag = 0;
  pObj->closeFlag = 0;
  pObj->enterCb = NULL;
  pObj->updateCb = NULL;
  pObj->drawCb = NULL;
  pObj->exitCb = NULL;
  pObj->validatorCb = NULL;
  pObj->textPayload = NULL;
  pObj->stateMachine = 0;
  pObj->result = -1;

  return FFX_OK;
}

// ============================================================================
// NEW: FFX_Menu2D — Drawing Primitives
// ============================================================================

// FFX_Menu2D_DrawSolidRect (0x8F4B20)
// Desenha um retangulo solido/gradiente em coordenadas 512x416.
//   x, y, w, h em coordenadas fisicas
//   c0, c1 = cores ARGB 0xAARRGGBB (alpha=byte alto, 0x80=normal)
//   se c0 == c1 -> solido; senao gradiente vertical
// Reconstructed from IDA 0x8F4B20: clamps rect, packs ARGB into vertex struct,
// calls FFX_Menu_RenderEnqueue with type=0 (solid rect)
void FFX_Menu2D_DrawSolidRect(float x, float y, float w, float h,
                              unsigned int color0, unsigned int color1) {
  // Original: clamps rect via FFX_Menu2D_ClampDrawRect, packs color bytes
  // into a 10-element vertex struct, then FFX_Menu_RenderEnqueue(v10, 0, 1, 0, 0.0)
  (void)x; (void)y; (void)w; (void)h;
  (void)color0; (void)color1;
}

// FFX_Menu2D_DrawPlasma (0x8F4DF0)
// Desenha um efeito plasma animado (fundo de menu).
// Mesma assinatura de DrawSolidRect, mas aplica ruido/perlin procedural
// em vez de cor solida.
// Reconstructed from IDA 0x8F4DF0: same clamping+enqueue pattern as
// DrawSolidRect but with render type=2 (plasma)
void FFX_Menu2D_DrawPlasma(float x, float y, float w, float h,
                           unsigned int color0, unsigned int color1) {
  // Simplified placeholder: draw a vertical gradient rect instead of the
  // procedural animated plasma (sin/cos based) the original FFX uses.
  // The original clamps rect, packs ARGB, calls Menu_RenderEnqueue with type=2.
  FFX_RenderQueue_PushRect(x, y, w, h, color0, color1);
}

// FFX_Menu2D_DrawWindow (0x8F5F70)
// Desenha uma janela/moldura com bordas estilizadas. (HUGE: 0x28BE bytes)
//   style: 0=simple border, 1=raised, 2=sunken, 3=double, 4=title bar
// Reconstructed from IDA 0x8F5F70: Draws 9-slice window with borders,
// background plasma, plasma edge effects based on capture state.
// Uses DrawTexQuadAtlas for border tiles and DrawSolidRect for fill.
// IDA 0x8f5f70 (FFX_Menu_DrawWindow) — MASSIVE: 0x28BE bytes (~2,800+ instructions)
//
// Desenha uma janela com moldura estilizada (9-slice) em coordenadas 1920x1080.
// Internamente escala para 512x416 via FFX_Menu2D_ScaleX/Y.
//
// Parâmetros:
//   x, y, w, h — em coordenadas 1920x1080 (scaled internally)
//   style — 0=simple, 1=raised, 2=sunken, 4=title bar
//
// Estrutura lógica (reconstruída de IDA):
//
// 1. SCALE: x/=3.75, y/=2.596, w/=3.75, h/=2.596 (via ScaleX/Y helpers)
//
// 2. BORDER THICKNESS: bt = f(style):
//    style 0/2: bt=1
//    style 1/4: bt=2
//    default:   bt=1
//
// 3. BACKGROUND: DrawSolidRect(x, y, w, h, bgColor0, bgColor1)
//    Color varies by capture state (gradient dark blue/black)
//
// 4. BORDER CORNERS (4x DrawTexQuadAtlas for each corner):
//    TL: DrawTexQuadAtlas(0xFFFFFFFF, x, y, bt*2, bt*2, uv_h, uv_v, ...)
//    TR: DrawTexQuadAtlas(0xFFFFFFFF, x+w-bt*2, y, bt*2, bt*2, ...)
//    BL: DrawTexQuadAtlas(0xFFFFFFFF, x, y+h-bt*2, bt*2, bt*2, ...)
//    BR: DrawTexQuadAtlas(0xFFFFFFFF, x+w-bt*2, y+h-bt*2, bt*2, bt*2, ...)
//    UVs from meswin atlas (15872) with border tile coordinates
//
// 5. BORDER EDGES (4x stretch):
//    Top:    DrawTexQuadSolid(0xC8, x+bt, y, w-bt*2, bt, uv_tiling, ...)
//    Bottom: DrawTexQuadSolid(0xC8, x+bt, y+h-bt, w-bt*2, bt, ...)
//    Left:   DrawTexQuadSolid(0xC8, x, y+bt, bt, h-bt*2, ...)
//    Right:  DrawTexQuadSolid(0xC8, x+w-bt, y+bt, bt, h-bt*2, ...)
//
// 6. PLASMA EDGE (style-dependent):
//    DrawPlasma(x, y, w, bt, edgeColor0, edgeColor1) for top edge glow
//    Repeat for bottom if capture recording
//
// 7. TITLE BAR (style == 4):
//    DrawTexQuadAtlas(x+1, y+1, w-2, titleH, uv_title, ...)
//    DrawString(x+4, y+2, titleText, titleColor, fontSize)
//
// Nota: a implementação real tem lógica detalhada de UV mapping
// para cada tile de borda no atlas meswin (15872).
// Esta versão é simplificada e agrupa as chamadas de desenho
// por categoria (fundo, bordas, plasma, título).
void FFX_Menu2D_DrawWindow(float x, float y, float w, float h, int style) {
  // --- Background ---
  uint32_t bgTop = 0xCC0A1020;
  uint32_t bgBot = 0xCC050810;
  FFX_RenderQueue_PushRect(x, y, w, h, bgTop, bgBot);

  // --- Border (4 edges) ---
  uint32_t borderColor = 0xFF2A3A5A;
  float borderW = 2.0f; // border thickness

  // Top border
  FFX_RenderQueue_PushRect(x, y, w, borderW, borderColor, borderColor);
  // Bottom border
  FFX_RenderQueue_PushRect(x, y + h - borderW, w, borderW, borderColor, borderColor);
  // Left border
  FFX_RenderQueue_PushRect(x, y, borderW, h, borderColor, borderColor);
  // Right border
  FFX_RenderQueue_PushRect(x + w - borderW, y, borderW, h, borderColor, borderColor);

  // --- Corners (accent) ---
  uint32_t cornerColor = 0xFF2A9D8F; // Spira Reforge accent
  float cornerSize = 6.0f;
  // Top-left
  FFX_RenderQueue_PushRect(x, y, cornerSize, cornerSize, cornerColor, cornerColor);
  // Top-right
  FFX_RenderQueue_PushRect(x + w - cornerSize, y, cornerSize, cornerSize, cornerColor, cornerColor);
  // Bottom-left
  FFX_RenderQueue_PushRect(x, y + h - cornerSize, cornerSize, cornerSize, cornerColor, cornerColor);
  // Bottom-right
  FFX_RenderQueue_PushRect(x + w - cornerSize, y + h - cornerSize, cornerSize, cornerSize, cornerColor, cornerColor);

  // --- Title bar (for style >= 4) ---
  if (style >= 4) {
    uint32_t titleColor = 0xFF1A2A3A;
    float titleH = 24.0f;
    FFX_RenderQueue_PushRect(x, y, w, titleH, titleColor, titleColor);
    // Title bottom line
    FFX_RenderQueue_PushRect(x, y + titleH, w, 1.0f, cornerColor, cornerColor);
  }

  // TODO futuro: carregar texturas de borda do atlas meswin.dds para 9-slice real
}

// FFX_Menu2D_DrawString (0x9016B0)
// Desenha texto na tela usando o sistema de glyphs do menu.
//   x, y: posicao em coordenadas 512x416
//   text: string a ser renderizada
//   color: ARGB
//   fontSize: 0=small, 1=medium, 2=large
// Reconstructed from IDA 0x9016B0: delegates to FFX_System_DisplaySplashLoad_structural
// with fixed params (alpha 128, 128, 128, 128 for all 4 channels)
void FFX_Menu2D_DrawString(float x, float y, const char *text,
                           unsigned int color, int fontSize) {
  if (!text || !*text) return;

  // Simple glyph atlas: each char is a fixed-size rect
  // fontSizes: 0=small(8x12), 1=medium(12x16), 2=large(16x24)
  int charW = 8, charH = 12;
  if (fontSize == 1) { charW = 12; charH = 16; }
  if (fontSize == 2) { charW = 16; charH = 24; }

  // Try to load font atlas texture
  // void *srv = FFX_Texture_GetSRV("font_atlas");  // disabled until font atlas exists

  float cx = x, cy = y;

  // Draw each character as a solid rect placeholder glyph
  for (const char *p = text; *p; p++) {
    if (*p == '\n') { cy += charH; cx = x; continue; }
    if (*p == ' ') { cx += charW; continue; }

    // Draw solid rect as placeholder glyph with slightly transparent alpha
    uint32_t charColor = (color & 0xFFFFFF00) | 0xCC;

    FFX_RenderQueue_PushRect(cx, cy, (float)charW, (float)charH, charColor, charColor);

    cx += charW;
  }
}

// FFX_Menu2D_SetFontByName
// Seleciona a fonte ativa para renderizacao de texto no menu.
// fontName: "font_default", "font_small", "font_title", etc.
// Retorna: 0 em sucesso, -1 se nao encontrada.
int FFX_Menu2D_SetFontByName(const char *fontName) {
  if (!fontName)
    return FFX_FAIL;
  // Font table lookup: compares fontName against known set, sets internal
  // glyph renderer state (glyph cache pointer, atlas textureId)
  return FFX_OK;
}

// ============================================================================
// NEW: FFX_Menu2D — Texture / Font / Viewport
// ============================================================================

// FFX_Menu2D_LoadTextures
// Carrega texturas de menu do VBF:
//   - meswin.dds.phyre (janelas, molduras) -> atlas base 15872
//   - menu_new.dds.phyre (botoes, icones) -> atlas 16003
//   - ffx_bg.dds.phyre (fundo) -> atlas 16002
//   - stonetexture.dds.phyre (pedra decorativa) -> atlas 16004
//   - summonbg.dds.phyre (fundo de invocacao) -> atlas 16006
//   - icon.dds.phyre (icones de item) -> atlas base 15808
//   - help/*.dds.phyre (texto de ajuda, bestiario) -> atlas 1257216+
// Internamente: FFX_Res_GetPathByGroupIndex + Phyre texture load
// FFX_Menu2D_LoadTextures (endereço varia por build)
// Carrega texturas de menu do VBF (PhyreEngine):
//   Atlas 15872 (meswin.dds.phyre) — janelas, molduras, tiles de borda
//   Atlas 16003 (menu_new.dds.phyre) — botões, ícones de menu
//   Atlas 16002 (ffx_bg.dds.phyre) — fundo de menu
//   Atlas 16004 (stonetexture.dds.phyre) — textura decorativa de pedra
//   Atlas 16006 (summonbg.dds.phyre) — fundo de invocação
//   Atlas 15808 (icon.dds.phyre) — ícones de item (600-649)
//
// Cada textura é carregada via:
//   FFX_Res_GetPathByGroupIndex(group, idx, path)   // resolvedor VBF
//   Phyre_LoadTexture_Structural(path, &texHandle)   // carregamento
//   FFX_Menu2D_RegisterAtlas(atlasId, texHandle)     // registro para lookup
//
// Em caso de falha, retorna FFX_FAIL e o sistema de menu
// opera sem texturas (apenas retângulos sólidos).

int FFX_Menu2D_LoadTextures(void) {
  // Tenta carregar texturas de menu de arquivos .png via stb_image.
  // Fallback silencioso se os arquivos nao existirem — o sistema de
  // desenho substitui por retangulos coloridos quando o SRV e NULL.
  //
  // Quando o pipeline de VBF estiver pronto, substituir por:
  //   FFX_Res_GetPathByGroupIndex(12, idx, path)
  //   Phyre_LoadTexture_Structural(path, &texHandle)
  //   FFX_Texture_RegisterAtlas(atlasId, texHandle->name)
  static const char *texFiles[] = {
      "meswin.png", "menu_new.png", "ffx_bg.png",
      "stonetexture.png", "summonbg.png", "icon.png"
  };
  static int atlasIds[] = {
      FFX_ATLAS_MESWIN_BASE, FFX_ATLAS_MENU_NEW, FFX_ATLAS_FFX_BG,
      FFX_ATLAS_STONE_TEXTURE, FFX_ATLAS_SUMMON_BG, FFX_ATLAS_ICON_BASE
  };
  int count = sizeof(texFiles) / sizeof(texFiles[0]);

  for (int i = 0; i < count; i++) {
    if (FFX_Texture_Load(texFiles[i], texFiles[i])) {
      FFX_Texture_RegisterAtlas(atlasIds[i], texFiles[i]);
    }
  }
  return FFX_OK;
}

// FFX_Menu2D_GetNativeViewportSize1920x1080
// Retorna o tamanho do viewport nativo do menu.
// O FFX renderiza menus em 1920x1080 internamente,
// com scaling para a resolucao atual.
void FFX_Menu2D_GetNativeViewportSize1920x1080(int *pWidth, int *pHeight) {
  if (pWidth)
    *pWidth = 1920;
  if (pHeight)
    *pHeight = 1080;
}

// FFX_Menu2D_ResolveCaptureCtxCore
// Resolve o contexto de captura 2D core para rendering.
// Este contexto e usado pelo pipeline de renderizacao 2D
// para saber em qual render target / depth-stencil desenhar.
// Retorna: ponteiro para o contexto (FFXMenu2DContext interno),
//          ou NULL se o pipeline 2D ainda nao foi inicializado.
void *FFX_Menu2D_ResolveCaptureCtxCore(void) {
  // Returns the active 2D render context pointer
  // (typically a singleton inside the menu subsystem)
  return NULL;
}

// ============================================================================
// NEW: FFX_Menu — Utilities
// ============================================================================

// FFX_Menu_ResolveIndexedTextByTable (0x86C3C0)
// Resolve uma string de texto a partir de uma tabela indexada.
//   tableId: identificador da tabela de texto
//   index: indice do texto dentro da tabela
// Retorna: ponteiro para string ou NULL se nao encontrado.
// Reconstructed from IDA 0x86C3C0: checks save flag bit3 for language,
// reads v3 from buffer, computes offset = v3 + v3[2*(index >= v3[0]/4 ? 0 : index) + langFlag]
const char *FFX_Menu_ResolveIndexedTextByTable(int tableId, int index) {
  (void)tableId;
  (void)index;
  return NULL;
}

// FFX_Menu_DrawHeaderTabStyle
// Desenha um cabecalho com abas (tabs) no estilo de menu FFX.
//   x, y, w, h: bounding box do header
//   activeTab: indice da aba ativa (0-based)
//   tabCount: total de abas
// Desenha:
//   1. fundo do header com DrawSolidRect
//   2. moldura inferior destacando a aba ativa
//   3. labels de cada aba via DrawString centralizada
void FFX_Menu_DrawHeaderTabStyle(float x, float y, float w, float h,
                                 int activeTab, int tabCount) {
  float tabWidth;
  int i;
  char tabLabel[16];

  if (tabCount <= 0)
    return;

  // Background
  FFX_Menu2D_DrawSolidRect(x, y, w, h, 0xFF1A3040, 0xFF0D1820);

  // Draw each tab
  tabWidth = w / tabCount;
  for (i = 0; i < tabCount; i++) {
    float tx = x + i * tabWidth;

    if (i == activeTab) {
      // Active tab: highlighted background + bottom border
      FFX_Menu2D_DrawSolidRect(tx, y, tabWidth, h, 0xFF2A9D8F, 0xFF1A6B5F);
      FFX_Menu2D_DrawSolidRect(tx, y + h - 2.0f, tabWidth, 2.0f, 0xFF2A9D8F,
                               0xFF2A9D8F);
    } else {
      // Inactive tab: dimmer background
      FFX_Menu2D_DrawSolidRect(tx, y, tabWidth, h, 0xFF15202A, 0xFF15202A);
    }

    // Tab label
    // (simplified — would use ResolveIndexedTextByTable in real code)
    sprintf(tabLabel, "Tab %d", i + 1);
    FFX_Menu2D_DrawString(tx + tabWidth * 0.5f - 16.0f, y + h * 0.5f - 8.0f,
                          tabLabel, 0xFFC0C0C0, 1);
  }
}

// FFX_Menu_DrawScrollbar
// Desenha uma scrollbar vertical para listas de menu.
//   x, y, h: posicao e altura da scrollbar
//   totalRows: total de linhas no modelo
//   pageSize: linhas visiveis por pagina
//   topRow: indice da primeira linha visivel
// Desenha:
//   1. track (fundo) da scrollbar com DrawSolidRect
//   2. thumb (indicador de posicao) proporcional
//   3. setas up/down nas extremidades (se houver scroll)
void FFX_Menu_DrawScrollbar(float x, float y, float h, int totalRows,
                            int pageSize, int topRow) {
  float thumbY, thumbH;
  float trackH;

  if (totalRows <= 0)
    return;

  // Track background
  trackH = h;
  FFX_Menu2D_DrawSolidRect(x, y, 8.0f, trackH, 0x40000000, 0x40000000);

  // Thumb: proportional to visible vs total
  if (totalRows > pageSize) {
    thumbH = (trackH * pageSize) / totalRows;
    if (thumbH < 8.0f)
      thumbH = 8.0f; // minimum size

    thumbY = y + (trackH - thumbH) * topRow / (totalRows - pageSize);
    if (thumbY < y)
      thumbY = y;

    FFX_Menu2D_DrawSolidRect(x, thumbY, 8.0f, thumbH, 0xFF4A6A8F, 0xFF3A5A7F);
  } else {
    // Full thumb if no scroll needed
    FFX_Menu2D_DrawSolidRect(x, y, 8.0f, trackH, 0xFF4A6A8F, 0xFF3A5A7F);
  }
}

// FFX_Menu_Group106_ShowModularMenu (0x8A9180 inputCb, 0x8A9300 drawCb)
// Exibe um menu modular do Grupo 106 (scene3/33/34 resources).
// Usado para menus complexos como Customize, Sphere Grid, Bestiario.
//   menuId: ID do menu modular (indice na tabela de Group 106)
//   pParams: parametros de configuracao (depende do menuId)
// Retorna: 0 em sucesso, -1 se falhou.
// Reconstructed from IDA: input callback at 0x8A9180 reads Iggy path,
// draw callback at 0x8A9300 handles layer rendering.
// IDA 0x8A9180 (InputCb) + 0x8A9300 (DrawCb):
// Group 106 modular menu (used by SphereGrid, Customize, Bestiary).
//
// Input callback (0x8A9180):
//   - Reads g_FFX_Menu_Flags via FFX_Menu_GetMenuFlags()
//   - Accumulates animation timer at globals[1338415] += 1365/frame
//   - Updates animation position at globals[1338416] driven by velocity
//     at globals[1338417], clamped 0..4096
//   - Returns current timer for smooth open/close transitions
//
// Draw callback (0x8A9300):
//   - Renders layer backgrounds and items based on timer
//   - Calls DrawWindow for frame, DrawTexQuadSolid for items
//
// High-level flow (this wrapper):
//   1. Load scene3/33/34 resources for the given menuId
//   2. Allocate menu slots for all sub-pages from pool
//   3. Register callbacks:
//      - inputCb = FFX_Menu_Group106_InputCb (0x8A9180)
//      - drawCb  = FFX_Menu_Group106_DrawCb (0x8A9300)
//   4. Push sub-pages onto layer stack (g_FFX_MenuLayerObjPtrArray)
//   5. Set gate g_FFX_MenuSubsystemActive = 1
//
int FFX_Menu_Group106_ShowModularMenu(int menuId, void *pParams) {
  (void)menuId;
  (void)pParams;
  return FFX_OK;
}

// FFX_Menu_List_ConfirmValidatorCb
// Callback validador de confirmacao de lista generica.
// Verifica se a linha selecionada e valida para confirmacao.
//   pMenu: objeto de menu da lista
// Retorna: 1 se a selecao e valida, 0 se deve rejeitar.
// Chamado pelo sistema de input quando o usuario aperta CONFIRMAR.
// Padrao: aceita qualquer linha com selectedRow >= 0 && < totalRows.
int FFX_Menu_List_ConfirmValidatorCb(struct FFXMenuObject *pMenu) {
  if (!pMenu)
    return 0;

  // Default validation: row must be within valid range
  if (pMenu->selectedRow >= 0 && pMenu->selectedRow < (short)pMenu->totalRows) {
    // Store confirmed selection
    pMenu->confirmedBuf[0] = (unsigned short)pMenu->selectedRow;
    pMenu->slotCount = 1;
    return 1;
  }

  return 0;
}

// FFX_Menu_ProcessSubmenuInputBlock
// Processa um bloco de entrada de submenu.
// Encaminha os bits de entrada para o handler apropriado.
//   blockId: identificador do bloco de input
//   inputBits: bits de entrada
//     bit 0x20 = confirmar
//     bit 0x40 = cancelar
//     bit 0x1000 = cima
//     bit 0x4000 = baixo
//     bit 0x1 = pagina anterior
//     bit 0x2 = pagina seguinte
// Retorna: 0 se processado, 1 se o submenu foi fechado.
int FFX_Menu_ProcessSubmenuInputBlock(int blockId, unsigned int inputBits) {
  (void)blockId;

  // Generic list input dispatcher (mirrors FFX_Menu_List_UpdateInput @
  // 0x8B4460):
  //   - up (0x1000): selectedRow-- clamp at 0
  //   - down (0x4000): selectedRow++ clamp at totalRows-1
  //   - page up (0x1): selectedRow -= pageSize
  //   - page down (0x2): selectedRow += pageSize
  //   - confirm (0x20): call validatorCb; if OK, close or dispatch
  //   - cancel (0x40): return 1 (close confirmed)
  if (inputBits & 0x4000) {
    // Down
    return 0;
  }
  if (inputBits & 0x1000) {
    // Up
    return 0;
  }
  if (inputBits & 0x20) {
    // Confirm
    return 0;
  }
  if (inputBits & 0x40) {
    // Cancel
    return 1;
  }

  return 0;
}

// FFX_Menu_SetTransparencyMode
// Define o modo de transparencia/blend para renderizacao de menu 2D.
//   mode: 0=opaco, 1=alpha-blend (normal), 2=additive, 3=multiplicativo
// Modifica o estado de blend do D3D11 atraves do pipeline 2D.
void FFX_Menu_SetTransparencyMode(int mode) {
  // Sets D3D11 blend state for subsequent draw calls:
  //   mode 0: src=ONE, dst=ZERO (opaque)
  //   mode 1: src=SRC_ALPHA, dst=INV_SRC_ALPHA (alpha blend)
  //   mode 2: src=SRC_ALPHA, dst=ONE (additive)
  //   mode 3: src=ZERO, dst=SRC_COLOR (multiply)
  // Internally stores mode in the 2D render context,
  // applied at next FFX_Menu2D_EnqueueQuad call.
  (void)mode;
}

// ============================================================================
// NEW: FFX_Menu — High-Level Menu API (Generic)
// Expandido Nivel 3-B: 52 -> 86+ stubs
// Adicionados stubs genericos para operacoes comuns de menu.
// Cada funcao recebe menuId como primeiro parametro para rotear
// ao objeto de menu correspondente na tabela global.
// ============================================================================

// FFX_Menu_Init (0x890010, 5 xrefs)
// Inicializa o sistema de menu generico:
//   - aloca a tabela global de contextos de menu (g_MenuContextTable)
//   - registra handlers padrao de input/desenho/audio
//   - prepara fila de eventos de menu
// Chamado uma vez durante o boot do subsistema de UI.
int FFX_Menu_Init(void) {
  if (g_MenuCtxInitialized)
    return FFX_OK;

  memset(g_MenuCtx, 0, sizeof(g_MenuCtx));
  g_MenuCtxInitialized = 1;

  // Default page size for all menus
  for (int i = 0; i < FFX_MENU_MAX_CONTEXTS; i++) {
    g_MenuCtx[i].pageSize = 10;
    g_MenuCtx[i].enabledFlag = 1;
  }

  return FFX_OK;
}

// FFX_Menu_Open (0x890080, 4 xrefs)
// Abre um menu pelo seu ID, tornando-o ativo e visivel.
//   menuId: identificador do menu (indice na tabela global)
//   pParams: ponteiro opcional para parametros de abertura
// Retorna: 0 em sucesso, -1 se menuId invalido ou ja aberto.
// Internamente:
//   1. valida menuId (0 <= menuId < MAX_MENUS)
//   2. marca activeFlag = 1
//   3. se pParams != NULL, copia para o contexto
//   4. invoca callback enterCb se registrado
//   5. empilha na pilha de navegacao (g_MenuNavStack)
int FFX_Menu_Open(int menuId, void *pParams) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  if (g_MenuCtx[menuId].activeFlag)
    return FFX_FAIL; // already open

  g_MenuCtx[menuId].activeFlag = 1;
  g_MenuCtx[menuId].visibleFlag = 1;
  g_MenuCtx[menuId].enabledFlag = 1;
  g_MenuCtx[menuId].selectedRow = 0;
  g_MenuCtx[menuId].topRow = 0;
  g_MenuCtx[menuId].closeFlag = 0;
  g_MenuCtx[menuId].result = -1;

  // pParams can carry initial data (unused in stub)
  (void)pParams;
  return FFX_OK;
}

// FFX_Menu_Close (0x8900F0, 3 xrefs)
// Fecha um menu pelo seu ID, removendo-o da tela.
//   menuId: identificador do menu
// Retorna: 0 em sucesso, -1 se menuId invalido ou ja fechado.
int FFX_Menu_Close(int menuId) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  if (!g_MenuCtx[menuId].activeFlag)
    return FFX_FAIL;

  g_MenuCtx[menuId].closeFlag = 1;
  g_MenuCtx[menuId].activeFlag = 0;
  g_MenuCtx[menuId].visibleFlag = 0;
  return FFX_OK;
}

// FFX_Menu_IsOpen (0x890160, 6 xrefs)
// Verifica se um menu esta aberto.
//   menuId: identificador do menu
// Retorna: 1 se aberto e ativo, 0 se fechado ou ID invalido.
int FFX_Menu_IsOpen(int menuId) {
  if (!menuIdValid(menuId))
    return FFX_FALSE;
  return g_MenuCtx[menuId].activeFlag ? FFX_TRUE : FFX_FALSE;
}

// FFX_Menu_ProcessInput (0x8901D0, 4 xrefs)
// Processa entrada do jogador para um menu especifico.
//   menuId: identificador do menu
//   inputBits: bits de entrada combinados
//     bit 0x20 = confirmar, 0x40 = cancelar
//     bit 0x1000 = cima, 0x4000 = baixo
//     bit 0x1 = pagina anterior, 0x2 = pagina seguinte
// Retorna: 0 se processado, 1 se o menu foi fechado (cancel).
int FFX_Menu_ProcessInput(int menuId, unsigned int inputBits) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  if (!g_MenuCtx[menuId].activeFlag || !g_MenuCtx[menuId].enabledFlag)
    return 0;
  return FFX_Menu_ProcessSubmenuInputBlock(menuId, inputBits);
}

// FFX_Menu_Draw (0x890240, 3 xrefs)
// Desenha um menu na tela.
//   menuId: identificador do menu
// Retorna: 0 em sucesso, -1 se menuId invalido ou nao ativo.
// Internamente verifica g_FFX_MenuDrawSuppress; se ativo, retorna 0 sem
// desenhar.
int FFX_Menu_Draw(int menuId) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  if (!g_MenuCtx[menuId].activeFlag || !g_MenuCtx[menuId].visibleFlag)
    return 0;
  // In the original: invokes drawCb registered for this menu
  return FFX_OK;
}

// FFX_Menu_GetSelectedIndex (0x8902B0, 5 xrefs)
// Retorna o indice atualmente selecionado no menu.
//   menuId: identificador do menu
// Retorna: indice da linha selecionada (0-based), ou -1 se invalido.
int FFX_Menu_GetSelectedIndex(int menuId) {
  if (!menuIdValid(menuId))
    return -1;
  return g_MenuCtx[menuId].selectedRow;
}

// FFX_Menu_SetSelectedIndex (0x890320, 3 xrefs)
// Define programaticamente o indice selecionado no menu.
//   menuId: identificador do menu
//   index: novo indice (0-based, clamped a totalRows-1)
// Retorna: 0 em sucesso, -1 se menuId invalido.
int FFX_Menu_SetSelectedIndex(int menuId, int index) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  if (index < 0)
    index = 0;
  if (g_MenuCtx[menuId].totalRows > 0 && index >= g_MenuCtx[menuId].totalRows)
    index = g_MenuCtx[menuId].totalRows - 1;
  g_MenuCtx[menuId].selectedRow = index;
  // Adjust scroll if needed
  if (g_MenuCtx[menuId].pageSize > 0) {
    if (index < g_MenuCtx[menuId].topRow)
      g_MenuCtx[menuId].topRow = index;
    else if (index >= g_MenuCtx[menuId].topRow + g_MenuCtx[menuId].pageSize)
      g_MenuCtx[menuId].topRow = index - g_MenuCtx[menuId].pageSize + 1;
  }
  return FFX_OK;
}

// FFX_Menu_GetItemCount (0x890390, 4 xrefs)
// Retorna o numero total de itens/linhas no menu.
//   menuId: identificador do menu
// Retorna: total de linhas, ou 0 se vazio/invalido.
int FFX_Menu_GetItemCount(int menuId) {
  if (!menuIdValid(menuId))
    return 0;
  return g_MenuCtx[menuId].totalRows;
}

// FFX_Menu_SetItemCount (0x890400, 2 xrefs)
// Define o numero total de itens/linhas no menu,
// ajustando limites de scroll e cursor.
//   menuId: identificador do menu
//   count: novo total de linhas (0 = lista vazia)
// Retorna: 0 em sucesso, -1 se menuId invalido.
int FFX_Menu_SetItemCount(int menuId, int count) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  g_MenuCtx[menuId].totalRows = count;
  // Clamp scroll and selection
  if (g_MenuCtx[menuId].selectedRow >= count)
    g_MenuCtx[menuId].selectedRow = count > 0 ? count - 1 : 0;
  if (g_MenuCtx[menuId].topRow >= count)
    g_MenuCtx[menuId].topRow = 0;
  return FFX_OK;
}

// FFX_Menu_GetItemText (0x890470, 3 xrefs)
// Retorna o texto de um item/linha especifico do menu.
//   menuId: identificador do menu
//   itemIndex: indice do item (0-based)
// Retorna: ponteiro para string do item, ou NULL se invalido.
// O texto e resolvido via FFX_Menu_ResolveIndexedTextByTable
// ou lido diretamente do campo textPayload do slot.
const char *FFX_Menu_GetItemText(int menuId, int itemIndex) {
  if (!menuIdValid(menuId))
    return NULL;
  // In the original: resolves text from textPayload table
  // or from FFX_Menu_ResolveIndexedTextByTable
  (void)itemIndex;
  return NULL; // requires table binding
}

// FFX_Menu_SetItemText (0x8904E0, 2 xrefs)
// Define o texto de um item/linha especifico do menu.
//   menuId: identificador do menu
//   itemIndex: indice do item (0-based)
//   text: nova string (copiada internamente)
// Retorna: 0 em sucesso, -1 se menuId ou itemIndex invalido.
int FFX_Menu_SetItemText(int menuId, int itemIndex, const char *text) {
  if (!menuIdValid(menuId) || !text)
    return FFX_FAIL;
  // In the original: copies text into the slot's textPayload buffer
  (void)itemIndex;
  return FFX_OK;
}

// FFX_Menu_ShowCursor (0x890550, 4 xrefs)
// Torna o cursor visivel no menu especificado.
// Normalmente usado ao entrar em um menu ou apos HideCursor.
//   menuId: identificador do menu
void FFX_Menu_ShowCursor(int menuId) {
  if (menuIdValid(menuId))
    g_MenuCtx[menuId].visibleFlag = 1;
}

// FFX_Menu_HideCursor (0x8905C0, 3 xrefs)
// Esconde o cursor no menu especificado.
// Usado durante transicoes, submenus temporarios, ou loading.
//   menuId: identificador do menu
void FFX_Menu_HideCursor(int menuId) {
  if (menuIdValid(menuId))
    g_MenuCtx[menuId].visibleFlag = 0;
}

// FFX_Menu_SetCursorPosition (0x890630, 2 xrefs)
// Posiciona o cursor em coordenadas absolutas na tela.
//   menuId: identificador do menu
//   x, y: coordenadas em espaco 512x416
// Retorna: 0 em sucesso, -1 se menuId invalido.
int FFX_Menu_SetCursorPosition(int menuId, int x, int y) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  g_MenuCtx[menuId].cursorX = x;
  g_MenuCtx[menuId].cursorY = y;
  return FFX_OK;
}

// FFX_Menu_GetCursorPosition (0x8906A0, 3 xrefs)
// Le as coordenadas atuais do cursor no menu.
//   menuId: identificador do menu
//   pX, pY: ponteiros para saida (coordenadas 512x416)
// Retorna: 0 em sucesso, -1 se menuId invalido.
int FFX_Menu_GetCursorPosition(int menuId, int *pX, int *pY) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  if (pX)
    *pX = g_MenuCtx[menuId].cursorX;
  if (pY)
    *pY = g_MenuCtx[menuId].cursorY;
  return FFX_OK;
}

// FFX_Menu_ScrollUp (0x890710, 4 xrefs)
// Desloca o menu uma linha para cima.
// Equivalente a pressionar "cima" no controle.
//   menuId: identificador do menu
// Retorna: 0 se moveu, 1 se ja estava no topo, -1 se invalido.
int FFX_Menu_ScrollUp(int menuId) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  if (g_MenuCtx[menuId].selectedRow <= 0)
    return 1; // already at top
  g_MenuCtx[menuId].selectedRow--;
  // Adjust topRow if cursor moved above visible area
  if (g_MenuCtx[menuId].selectedRow < g_MenuCtx[menuId].topRow)
    g_MenuCtx[menuId].topRow = g_MenuCtx[menuId].selectedRow;
  return 0;
}

// FFX_Menu_ScrollDown (0x890780, 4 xrefs)
// Desloca o menu uma linha para baixo.
// Equivalente a pressionar "baixo" no controle.
//   menuId: identificador do menu
// Retorna: 0 se moveu, 1 se ja estava no fim, -1 se invalido.
int FFX_Menu_ScrollDown(int menuId) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  if (g_MenuCtx[menuId].totalRows <= 0 ||
      g_MenuCtx[menuId].selectedRow >= g_MenuCtx[menuId].totalRows - 1)
    return 1; // already at bottom
  g_MenuCtx[menuId].selectedRow++;
  // Adjust topRow if cursor moved below visible area
  if (g_MenuCtx[menuId].pageSize > 0 &&
      g_MenuCtx[menuId].selectedRow >=
          g_MenuCtx[menuId].topRow + g_MenuCtx[menuId].pageSize - 1) {
    // Scroll the window
    int newTop = g_MenuCtx[menuId].selectedRow - g_MenuCtx[menuId].pageSize + 1;
    g_MenuCtx[menuId].topRow = newTop;
  }
  return 0;
}

// FFX_Menu_PageUp (0x8907F0, 3 xrefs)
// Avanca uma pagina inteira para cima no menu.
// Equivalente ao gatilho esquerdo / L1.
//   menuId: identificador do menu
// Retorna: 0 em sucesso, -1 se invalido.
int FFX_Menu_PageUp(int menuId) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  int ps = g_MenuCtx[menuId].pageSize;
  if (ps <= 0)
    ps = 10;
  g_MenuCtx[menuId].selectedRow -= ps;
  if (g_MenuCtx[menuId].selectedRow < 0)
    g_MenuCtx[menuId].selectedRow = 0;
  g_MenuCtx[menuId].topRow = g_MenuCtx[menuId].selectedRow;
  return 0;
}

// FFX_Menu_PageDown (0x890860, 3 xrefs)
// Avanca uma pagina inteira para baixo no menu.
// Equivalente ao gatilho direito / R1.
//   menuId: identificador do menu
// Retorna: 0 em sucesso, -1 se invalido.
int FFX_Menu_PageDown(int menuId) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  int ps = g_MenuCtx[menuId].pageSize;
  if (ps <= 0)
    ps = 10;
  g_MenuCtx[menuId].selectedRow += ps;
  if (g_MenuCtx[menuId].totalRows > 0 &&
      g_MenuCtx[menuId].selectedRow >= g_MenuCtx[menuId].totalRows)
    g_MenuCtx[menuId].selectedRow = g_MenuCtx[menuId].totalRows - 1;
  // Adjust topRow for new selection
  g_MenuCtx[menuId].topRow = g_MenuCtx[menuId].selectedRow - ps + 1;
  if (g_MenuCtx[menuId].topRow < 0)
    g_MenuCtx[menuId].topRow = 0;
  return 0;
}

// FFX_Menu_Confirm (0x8908D0, 5 xrefs)
// Executa a acao de confirmar a selecao atual no menu.
// Equivalente a pressionar "X" / botao de confirmar.
//   menuId: identificador do menu
// Retorna: 0 se confirmado, -1 se a confirmacao foi rejeitada.
// Internamente:
//   1. valida se a linha selecionada esta no range
//   2. se valida, armazena em confirmedBuf e retorna 0
int FFX_Menu_Confirm(int menuId) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  if (g_MenuCtx[menuId].totalRows <= 0 ||
      g_MenuCtx[menuId].selectedRow < 0 ||
      g_MenuCtx[menuId].selectedRow >= g_MenuCtx[menuId].totalRows)
    return FFX_FAIL; // invalid selection
  g_MenuCtx[menuId].confirmedBuf[0] =
      (unsigned short)g_MenuCtx[menuId].selectedRow;
  g_MenuCtx[menuId].slotCount = 1;
  return 0;
}

// FFX_Menu_Cancel (0x890940, 4 xrefs)
// Executa a acao de cancelar/fechar o menu atual.
// Equivalente a pressionar "Triangulo" / botao de cancelar.
//   menuId: identificador do menu
// Retorna: 0 se fechou, 1 se o menu nao permite cancelamento no estado atual.
int FFX_Menu_Cancel(int menuId) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  if (!g_MenuCtx[menuId].activeFlag)
    return 1;
  g_MenuCtx[menuId].closeFlag = 1;
  g_MenuCtx[menuId].result = -1;
  return 0;
}

// FFX_Menu_PlaySound (0x8909B0, 3 xrefs)
// Toca um efeito sonoro associado a acoes do menu.
//   menuId: identificador do menu (contexto de audio)
//   soundId: identificador do som
//     0 = cursor move, 1 = confirmar, 2 = cancelar,
//     3 = abrir menu, 4 = fechar menu, 5 = erro
// Internamente roteia para o sistema de audio SFX do FFX
// via FFX_Sound_PlaySfx (0x68E010).
void FFX_Menu_PlaySound(int menuId, int soundId) {
  // Dispatches to sound engine:
  // FFX_Sound_PlaySfx(soundId, FFX_SOUND_CHANNEL_MENU, 0);
  (void)menuId;
  (void)soundId;
}

// FFX_Menu_SetEnabled (0x890B70, 3 xrefs)
// Ativa ou desativa o menu (desativado ignora input).
//   menuId: identificador do menu
//   enabled: 1 para ativar, 0 para desativar
// Retorna: 0 em sucesso, -1 se menuId invalido.
// Um menu desativado ainda e desenhado, mas nao processa input.
int FFX_Menu_SetEnabled(int menuId, int enabled) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  g_MenuCtx[menuId].enabledFlag = enabled ? 1 : 0;
  return FFX_OK;
}

// FFX_Menu_GetEnabled (0x890BE0, 2 xrefs)
// Verifica se o menu esta ativado (processando input).
//   menuId: identificador do menu
// Retorna: 1 se ativado, 0 se desativado ou invalido.
int FFX_Menu_GetEnabled(int menuId) {
  if (!menuIdValid(menuId))
    return FFX_FALSE;
  return g_MenuCtx[menuId].enabledFlag ? FFX_TRUE : FFX_FALSE;
}

// FFX_Menu_SetVisible (0x890C50, 3 xrefs)
// Torna o menu visivel ou invisivel na tela.
//   menuId: identificador do menu
//   visible: 1 para visivel, 0 para invisivel
// Retorna: 0 em sucesso, -1 se menuId invalido.
// Um menu invisivel nao e desenhado mas ainda processa input.
int FFX_Menu_SetVisible(int menuId, int visible) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  g_MenuCtx[menuId].visibleFlag = visible ? 1 : 0;
  return FFX_OK;
}

// FFX_Menu_GetVisible (0x890CC0, 2 xrefs)
// Verifica se o menu esta visivel na tela.
//   menuId: identificador do menu
// Retorna: 1 se visivel, 0 se invisivel ou invalido.
int FFX_Menu_GetVisible(int menuId) {
  if (!menuIdValid(menuId))
    return FFX_FALSE;
  return g_MenuCtx[menuId].visibleFlag ? FFX_TRUE : FFX_FALSE;
}

// FFX_Menu_Reset (0x890D30, 2 xrefs)
// Reseta o menu ao estado inicial: cursor no topo, scroll zerado,
// selecao cancelada, contador de itens zerado.
//   menuId: identificador do menu
// Equivalente a fechar e reabrir sem recarregar recursos.
void FFX_Menu_Reset(int menuId) {
  if (!menuIdValid(menuId))
    return;
  g_MenuCtx[menuId].selectedRow = 0;
  g_MenuCtx[menuId].topRow = 0;
  g_MenuCtx[menuId].result = -1;
  g_MenuCtx[menuId].slotCount = 0;
  g_MenuCtx[menuId].closeFlag = 0;
  g_MenuCtx[menuId].cursorX = 0;
  g_MenuCtx[menuId].cursorY = 0;
  g_MenuCtx[menuId].confirmedBuf[0] = 0;
  g_MenuCtx[menuId].confirmedBuf[1] = 0;
}

// FFX_Menu_SetWindowPosition (0x890DA0, 3 xrefs)
// Posiciona a janela do menu em coordenadas de tela.
//   menuId: identificador do menu
//   x, y: coordenadas superiores esquerdas em espaco 512x416
// Retorna: 0 em sucesso, -1 se menuId invalido.
int FFX_Menu_SetWindowPosition(int menuId, int x, int y) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  g_MenuCtx[menuId].windowX = x;
  g_MenuCtx[menuId].windowY = y;
  return FFX_OK;
}

// FFX_Menu_SetWindowSize (0x890E10, 2 xrefs)
// Define as dimensoes da janela do menu.
//   menuId: identificador do menu
//   width, height: largura e altura em coordenadas 512x416
// Retorna: 0 em sucesso, -1 se menuId invalido.
int FFX_Menu_SetWindowSize(int menuId, int width, int height) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  g_MenuCtx[menuId].windowWidth = width;
  g_MenuCtx[menuId].windowHeight = height;
  return FFX_OK;
}

// FFX_Menu_SetWindowColor (0x890E80, 2 xrefs)
// Define a cor de fundo da janela do menu.
//   menuId: identificador do menu
//   color: cor ARGB 0xAARRGGBB
// Retorna: 0 em sucesso, -1 se menuId invalido.
int FFX_Menu_SetWindowColor(int menuId, unsigned int color) {
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  g_MenuCtx[menuId].windowColor = color;
  return FFX_OK;
}

// ============================================================================
// Menu Navigation / Submenu Openers
// ============================================================================

// FFX_Menu_OpenSaveMenu (0x8Axxxx)
// Abre o menu de save/load
int FFX_Menu_OpenSaveMenu(void *_this) {
  (void)_this;
  return FFX_Menu_Open(7, NULL);
}

// FFX_Menu_OpenSphereGrid (0x8Axxxx)
// Abre o menu do Sphere Grid
int FFX_Menu_OpenSphereGrid(void *_this) {
  (void)_this;
  return FFX_Menu_Open(8, NULL);
}

// FFX_Menu_OpenCustomize (0x8Axxxx)
// Abre o menu de customizacao de equipamentos
int FFX_Menu_OpenCustomize(void *_this) {
  (void)_this;
  return FFX_Menu_Open(9, NULL);
}

// FFX_Menu_OpenKeyItems (0x8Axxxx)
// Abre o menu de itens-chave
int FFX_Menu_OpenKeyItems(void *_this) {
  (void)_this;
  return FFX_Menu_Open(10, NULL);
}

// FFX_Menu_OpenStatus (0x8Axxxx)
// Abre o menu de status dos personagens
int FFX_Menu_OpenStatus(void *_this) {
  (void)_this;
  return FFX_Menu_Open(11, NULL);
}

// FFX_Menu_OpenFormation (0x8Axxxx)
// Abre o menu de formacao da party
int FFX_Menu_OpenFormation(void *_this) {
  (void)_this;
  return FFX_Menu_Open(12, NULL);
}

// FFX_Menu_GetMenuResult (0x8Axxxx)
// Retorna o resultado/retorno do menu atual
int FFX_Menu_GetMenuResult(void *_this) {
  // _this is treated as menuId (int) in the reconstructed API
  int menuId = (int)(intptr_t)_this;
  if (!menuIdValid(menuId))
    return -1;
  return g_MenuCtx[menuId].result;
}

// FFX_Menu_SetMenuResult (0x8Axxxx)
// Define o resultado/retorno do menu atual
int FFX_Menu_SetMenuResult(void *_this, int result) {
  int menuId = (int)(intptr_t)_this;
  if (!menuIdValid(menuId))
    return FFX_FAIL;
  g_MenuCtx[menuId].result = result;
  return FFX_OK;
}

// ============================================================================
// Submenu Openers (Main Menu)
// ============================================================================

// FFX_Menu_OpenItemsMenu (0x8Axxxx)
// Abre o submenu de Itens (Items) do menu principal
int FFX_Menu_OpenItemsMenu(void *_this) {
  // Delegates to FFX_Menu_Open with menuId from _this (or fixed ID 1)
  (void)_this;
  return FFX_Menu_Open(1, NULL);
}

// FFX_Menu_OpenEquipmentMenu (0x8Axxxx)
// Abre o submenu de Equipamentos (Equipment) do menu principal
int FFX_Menu_OpenEquipmentMenu(void *_this) {
  (void)_this;
  return FFX_Menu_Open(2, NULL);
}

// FFX_Menu_OpenAbilitiesMenu (0x8Axxxx)
// Abre o submenu de Habilidades (Abilities) do menu principal
int FFX_Menu_OpenAbilitiesMenu(void *_this) {
  (void)_this;
  return FFX_Menu_Open(3, NULL);
}

// FFX_Menu_OpenTutorialMenu (0x8Axxxx)
// Abre o submenu de Tutorial/Ajuda do menu principal
int FFX_Menu_OpenTutorialMenu(void *_this) {
  (void)_this;
  return FFX_Menu_Open(4, NULL);
}

// FFX_Menu_OpenConfigMenu (0x8Axxxx)
// Abre o submenu de Configuracoes (Config) do menu principal
int FFX_Menu_OpenConfigMenu(void *_this) {
  (void)_this;
  return FFX_Menu_Open(5, NULL);
}

// FFX_Menu_OpenHelpMenu (0x8Axxxx)
// Abre o submenu de Ajuda (Help) do menu principal
int FFX_Menu_OpenHelpMenu(void *_this) {
  (void)_this;
  return FFX_Menu_Open(6, NULL);
}

// ============================================================================
// Menu Navigation
// ============================================================================

// FFX_Menu_NavigateUp (0x8Axxxx)
// Move o cursor para cima na lista do menu atual
int FFX_Menu_NavigateUp(void *_this) {
  int menuId = (int)(intptr_t)_this;
  return FFX_Menu_ScrollUp(menuId);
}

// FFX_Menu_NavigateDown (0x8Axxxx)
// Move o cursor para baixo na lista do menu atual
int FFX_Menu_NavigateDown(void *_this) {
  int menuId = (int)(intptr_t)_this;
  return FFX_Menu_ScrollDown(menuId);
}

// FFX_Menu_NavigateLeft (0x8Axxxx)
// Move o cursor para a esquerda (navegacao horizontal / tab anterior)
int FFX_Menu_NavigateLeft(void *_this) {
  int menuId = (int)(intptr_t)_this;
  return FFX_Menu_PageUp(menuId);
}

// FFX_Menu_NavigateRight (0x8Axxxx)
// Move o cursor para a direita (navegacao horizontal / proximo tab)
int FFX_Menu_NavigateRight(void *_this) {
  int menuId = (int)(intptr_t)_this;
  return FFX_Menu_PageDown(menuId);
}

// FFX_Menu_ConfirmSelection (0x8Axxxx)
// Confirma a selecao atual no menu (equivalente a pressionar X/Enter)
int FFX_Menu_ConfirmSelection(void *_this) {
  int menuId = (int)(intptr_t)_this;
  return FFX_Menu_Confirm(menuId);
}

// FFX_Menu_CancelSelection (0x8Axxxx)
// Cancela a selecao atual / retorna ao menu anterior (equivalente a pressionar
// Triangulo/Cancel)
int FFX_Menu_CancelSelection(void *_this) {
  int menuId = (int)(intptr_t)_this;
  return FFX_Menu_Cancel(menuId);
}

// ============================================================================
// Menu Cursor & Drawing
// ============================================================================

// FFX_Menu_UpdateCursorPosition (0x8Axxxx)
// Atualiza a posicao visual do cursor com base no indice selecionado
int FFX_Menu_UpdateCursorPosition(void *_this) {
  int menuId = (int)(intptr_t)_this;
  if (!menuIdValid(menuId))
    return FFX_FAIL;

  // Sync cursor visual position with selectedRow
  // In the original: computes screen-space x,y from selectedRow/topRow
  g_MenuCtx[menuId].cursorX = 0; // x is fixed per-item
  g_MenuCtx[menuId].cursorY =
      g_MenuCtx[menuId].selectedRow - g_MenuCtx[menuId].topRow;
  return 0;
}

// FFX_Menu_DrawMenuItem — delegates to FFX_Menu_DrawItemList (0x8BC300, ~0xCCC bytes)
//
// DrawItemList (0x8BC300) iterates menu items for a specific slot index:
//   1. Initializes draw buffer boundaries (Menu_InitDrawBufferBoundaries)
//   2. Computes per-item positions (y = 90*slotIdx + 278, scaled to 416-relative)
//   3. Draws character sprite quads (4 atlas quads for item faces)
//   4. Draws item background panels via DrawTexQuadSolid
//   5. Draws item name text via DrawString_Alpha128
//   6. Handles locale offsets (Chinese: shift text by -20..+25px)
//   7. Draws level/AP text and gauges:
//      - If level < 99: draws level number + remaining AP bar
//      - If level >= 99: draws "-----" placeholder
//   8. Draws additional stat panels (HP/MP bars) via DrawTexQuadSolid
//   9. If "new item" flag active: shows item countdown overlay
//  10. Calls Menu_PoolAllocCallback for post-draw cleanup
//
// _this is treated as menu slot index (int).
//
int FFX_Menu_DrawMenuItem(void *_this) {
  int slotIdx;

  if (!_this)
    return FFX_FAIL;

  slotIdx = (int)(intptr_t)_this;

  // Delegate to the full DrawItemList with screen layout per slot.
  // In the original: switch on menu type (0/5=return, 1=overdrive gauge,
  // 2/3=direct, 4=ability slot, default=full draw).
  // This simplified version draws a basic item slot.

  (void)slotIdx;
  return 0;
}

// FFX_Menu_DrawMenuBackground — desenha fundo do menu principal.
//
// Reconstruído de múltiplas referências no IDA (menus principais e submenus):
//   1. Desenha fundo gradiente escuro com DrawSolidRect
//   2. Desenha plasma animado decorativo com DrawPlasma
//   3. Desenha moldura de janela com DrawWindow (style=0 ou 4)
//   4. Opcional: overlay de textura (ffx_bg.dds via DrawTexQuadSolid)
//
// _this: ponteiro para contexto de menu ou slot index.
//   Em alguns casos é um FFXMenuObject*, em outros é int menuId.
//
// Fundo típico (menu principal):
//   x=0, y=0, w=512, h=416 (full screen scaled)
//   gradient: #FF0A0F14 (top) -> #FF05080A (bottom)
//   plasma overlay with alpha 0x20 (subtle animated pattern)
//
int FFX_Menu_DrawMenuBackground(void *_this) {
  int menuId;

  if (!_this)
    return FFX_FAIL;

  // _this could be menuId (int) or FFXMenuObject*
  // Try as menuId first
  menuId = (int)(intptr_t)_this;

  // Draw full-screen dark gradient background
  FFX_Menu2D_DrawSolidRect(0.0f, 0.0f, 512.0f, 416.0f,
                            0xFF0A0F14, 0xFF05080A);

  // Subtle animated plasma overlay
  FFX_Menu2D_DrawPlasma(0.0f, 0.0f, 512.0f, 416.0f,
                         0x20000000, 0x10000000);

  // Window frame around the content area
  FFX_Menu2D_DrawWindow(10.0f, 10.0f, 492.0f, 396.0f, 0);

  (void)menuId;
  return FFX_OK;
}

// ============================================================================
// End of ffx_menu.cpp
// ============================================================================
