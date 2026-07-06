// ============================================================================
// ffx_menu.h — FFX Menu System Header
// Phase 3-E: FFX Game Stubs
// ============================================================================

#ifndef FFX_MENU_H
#define FFX_MENU_H

#include "ffx_types.h"

// ============================================================================
// Menu object pool constants
// ============================================================================
#define FFX_MENU2D_MAX_SLOTS      32
#define FFX_MENU2D_SLOT_STRIDE    152
#define FFX_MENU2D_POOL_ADDR      0x18408C0

// Window mode constants
#define FFX_MENU_WMODE_LIST       1
#define FFX_MENU_WMODE_POPUP      2
#define FFX_MENU_WMODE_FULLSCREEN 3

// Menu object layout (152 bytes, stride per slot in g_FFX_MenuObjPool)
typedef struct FFXMenuObject {
    int*            vfptr;              // +0x00 PhyrePObject base
    int             refCount;           // +0x04
    void*           enterCb;            // +0x08 init/enter callback
    void*           updateCb;           // +0x0C per-frame update/input callback
    void*           drawCb;             // +0x10 per-frame draw/render callback
    void*           exitCb;             // +0x14 exit/auxiliary callback
    void*           finalizer;          // +0x18 cleanup (default sub_8AA3A0)
    void*           validatorCb;        // +0x1C confirm validator
    int             field20;            // +0x20
    void*           textPayload;        // +0x24 text/id/payload
    int             stateMachine;       // +0x28 internal state machine
    unsigned short  confirmedBuf[2];    // +0x2C confirmed selections buffer
    unsigned short  totalRows;          // +0x30
    unsigned short  topRow;             // +0x32 current scroll top
    unsigned short  targetTopRow;       // +0x34 target scroll animation
    unsigned char   field36;            // +0x36
    unsigned char   noCloseOnLast;      // +0x37
    unsigned short  field38;            // +0x38
    unsigned short  pageSize;           // +0x3A visible rows per page
    unsigned char   field3C;            // +0x3C
    unsigned char   field3D;            // +0x3D
    unsigned char   windowMode;         // +0x3E 1=list, 2/3=popup
    unsigned char   groupId;            // +0x3F group for tick filtering
    unsigned char   activeFlag;         // +0x40
    unsigned char   closeFlag;          // +0x41 close/dispose
    unsigned char   slotCount;          // +0x42
    unsigned char   padding43[2];       // +0x43
    signed char     result;             // +0x45 >=0 confirmed, <0 cancelled
    short           scrollAccum;        // +0x46 scroll animation accumulator
    short           selectedRow;        // +0x48 cursor/selected row
    unsigned short  pad4A[7];           // +0x4A..+0x56
    int             optionalContext;    // +0x58 user context
    int             pad5C[14];          // +0x5C..+0x94
} FFXMenuObject; // total 0x98 = 152 bytes

// Texture atlas IDs
#define FFX_ATLAS_BATTLE_KUANG   16000
#define FFX_ATLAS_FFX_BG         16002
#define FFX_ATLAS_MENU_NEW       16003
#define FFX_ATLAS_STONE_TEXTURE  16004
#define FFX_ATLAS_SUMMON_BG      16006
#define FFX_ATLAS_MESWIN_BASE    15872  // + area_idx (200..398)
#define FFX_ATLAS_BATTLE_BASE    16128  // + area_idx (400..598)
#define FFX_ATLAS_ICON_BASE      15808  // + area_idx (600..649)

// Global menu state gates (from research doc)
#define FFX_MENU_GATE_ACTIVE     0x13407E4
#define FFX_MENU_SCREEN_ID       0x12FBBF0
#define FFX_MENU_READY           0x1840838
#define FFX_MENU_DRAW_SUPPRESS   0x13407E0

// ============================================================================
// FFX_FFEscMenu — Escape Menu (Pause/Config Menu)
// ============================================================================

void FFX_FFEscMenu_Ctor(void* pThis);
void FFX_FFEscMenu_GetParams(void* pThis, void* pOutParams);
void FFX_FFEscMenu_Dtor(void* pThis);
int FFX_FFEscMenu_InitSingleton(void);
void FFX_FFEscMenu_FreeSingleton(void);
int FFX_FFEscMenu_VtableDispatch(void* pThis, int methodId, void* pArg);
void FFX_FFEscMenu_SetStringValue(void* pThis, int key, const char* value);
void FFX_FFEscMenu_HandleEvent(void* pThis, int eventId, void* pEventData);
void FFX_FFEscMenu_BuildMenu(void* pThis);
void FFX_FFEscMenu_SetLanguage(int languageId);
void FFX_FFEscMenu_HandleNavigate(void* pThis, int direction);
void FFX_FFEscMenu_ShowPopUp(void* pThis, int popUpId);
void FFX_FFEscMenu_OnPopUpConfirm(void* pThis, int result);
void FFX_FFEscMenu_InitSubsystems(void* pThis);
void FFX_FFEscMenu_DispatchEvent(void* pThis, const char* eventType, void* pData);
void FFX_FFEscMenu_ShowGamePopUp(void* pThis, int popUpId, int arg);
void FFX_FFEscMenu_CloseMenu(void* pThis);
void FFX_FFEscMenu_RegisterCallbacks(void* pThis);
void FFX_FFEscMenu_OnResume(void* pThis);
void FFX_FFEscMenu_SetDimensions(void* pThis, int width, int height);
int FFX_FFEscMenu_ProcessSubmenuInputBlock(void* pThis, int blockId);

// ============================================================================
// FFX_Menu2D — 2D Menu Rendering System
// ============================================================================

float FFX_Menu2D_GetScaleFactor(void);
int FFX_Menu2D_ScaleCoord416Over720(int coord);
void FFX_Menu2D_SetSmoothRectVertexAlpha(void* pRect, float alpha);
int FFX_Menu2D_InitBlendStateArrays(void* pDevice);
void FFX_Menu2D_ComputeViewProjection(void* pCtx, void* pOutMatrix);
void FFX_Menu2D_InvokeSlotCallbacks_24(void* pSlot, int arg);
void FFX_Menu2D_InvokeSlotCallbacks_20(void* pSlot, int arg);
void FFX_Menu2D_DrawTexQuadSolid(void* pCtx, void* pQuad);
void FFX_Menu2D_DrawTexQuadAtlas(void* pCtx, void* pQuad);
void FFX_Menu2D_ScaleCoord(int* pX, int* pY);

// ============================================================================
// FFX_Menu — General Menu Utilities
// ============================================================================

int FFX_Menu_LoadMenuBin(const char* filePath, void* pOutData);
void FFX_Menu_LoadWaterTextureBridge(void* pMenu);

// ============================================================================
// FFX_EscMenu — Escape Menu System (high-level wrappers)
// ============================================================================

extern struct FFXMenuObject *g_EscMenuRoot;

int  FFX_EscMenu_Init(void);
int  FFX_EscMenu_ProcessInput(void);
int  FFX_EscMenu_Draw(void);

// ============================================================================
// FFX_Menu2D — Slot Allocation / Pool
// ============================================================================

void* FFX_Menu2D_AllocSlot(void);
int   FFX_Menu2D_FreeSlot(void* pSlot);

// ============================================================================
// FFX_Menu2D — Drawing Primitives (deferred quad batch)
// ============================================================================

void FFX_Menu2D_DrawSolidRect(float x, float y, float w, float h,
                              unsigned int color0, unsigned int color1);
void FFX_Menu2D_DrawPlasma(float x, float y, float w, float h,
                           unsigned int color0, unsigned int color1);
void FFX_Menu2D_DrawWindow(float x, float y, float w, float h, int style);
void FFX_Menu2D_DrawString(float x, float y, const char* text,
                           unsigned int color, int fontSize);
int  FFX_Menu2D_SetFontByName(const char* fontName);

// ============================================================================
// FFX_Menu2D — Texture / Font / Viewport
// ============================================================================

int  FFX_Menu2D_LoadTextures(void);
void FFX_Menu2D_GetNativeViewportSize1920x1080(int* pWidth, int* pHeight);
void* FFX_Menu2D_ResolveCaptureCtxCore(void);

// ============================================================================
// FFX_Menu — Utilities / Subsystems
// ============================================================================

const char* FFX_Menu_ResolveIndexedTextByTable(int tableId, int index);
void FFX_Menu_DrawHeaderTabStyle(float x, float y, float w, float h,
                                  int activeTab, int tabCount);
void FFX_Menu_DrawScrollbar(float x, float y, float h,
                            int totalRows, int pageSize, int topRow);
int  FFX_Menu_Group106_ShowModularMenu(int menuId, void* pParams);
int  FFX_Menu_List_ConfirmValidatorCb(struct FFXMenuObject* pMenu);
int  FFX_Menu_ProcessSubmenuInputBlock(int blockId,
                                       unsigned int inputBits);
void FFX_Menu_SetTransparencyMode(int mode);

// ============================================================================
// FFX_Menu — High-Level Menu API (Generic)
// ============================================================================

int  FFX_Menu_Init(void);
int  FFX_Menu_Open(int menuId, void* pParams);
int  FFX_Menu_Close(int menuId);
int  FFX_Menu_IsOpen(int menuId);
int  FFX_Menu_ProcessInput(int menuId, unsigned int inputBits);
int  FFX_Menu_Draw(int menuId);
int  FFX_Menu_GetSelectedIndex(int menuId);
int  FFX_Menu_SetSelectedIndex(int menuId, int index);
int  FFX_Menu_GetItemCount(int menuId);
int  FFX_Menu_SetItemCount(int menuId, int count);
const char* FFX_Menu_GetItemText(int menuId, int itemIndex);
int  FFX_Menu_SetItemText(int menuId, int itemIndex, const char* text);
void FFX_Menu_ShowCursor(int menuId);
void FFX_Menu_HideCursor(int menuId);
int  FFX_Menu_SetCursorPosition(int menuId, int x, int y);
int  FFX_Menu_GetCursorPosition(int menuId, int* pX, int* pY);
int  FFX_Menu_ScrollUp(int menuId);
int  FFX_Menu_ScrollDown(int menuId);
int  FFX_Menu_PageUp(int menuId);
int  FFX_Menu_PageDown(int menuId);
int  FFX_Menu_Confirm(int menuId);
int  FFX_Menu_Cancel(int menuId);
void FFX_Menu_PlaySound(int menuId, int soundId);
int  FFX_Menu_SetTitle(int menuId, const char* title);
int  FFX_Menu_SetHelpText(int menuId, const char* helpText);
int  FFX_Menu_SetIcon(int menuId, int iconId);
int  FFX_Menu_SetEnabled(int menuId, int enabled);
int  FFX_Menu_GetEnabled(int menuId);
int  FFX_Menu_SetVisible(int menuId, int visible);
int  FFX_Menu_GetVisible(int menuId);
void FFX_Menu_Reset(int menuId);
int  FFX_Menu_SetWindowPosition(int menuId, int x, int y);
int  FFX_Menu_SetWindowSize(int menuId, int width, int height);
int  FFX_Menu_SetWindowColor(int menuId, unsigned int color);

// ============================================================================
// FFX_Menu — Menu Navigation / Submenu Openers
// ============================================================================

int  FFX_Menu_OpenSaveMenu(void* this_);
int  FFX_Menu_OpenSphereGrid(void* this_);
int  FFX_Menu_OpenCustomize(void* this_);
int  FFX_Menu_OpenKeyItems(void* this_);
int  FFX_Menu_OpenStatus(void* this_);
int  FFX_Menu_OpenFormation(void* this_);
int  FFX_Menu_GetMenuResult(void* this_);
int  FFX_Menu_SetMenuResult(void* this_, int result);
int  FFX_Menu_GetSelectedPartyMember(void* this_);
int  FFX_Menu_SetSelectedPartyMember(void* this_, int memberIndex);

// Guards (already in ffx_types.h, but repeated here for standalone inclusion)
#ifndef FFX_OK
#define FFX_OK 0
#define FFX_FAIL -1
#endif

#endif // FFX_MENU_H
