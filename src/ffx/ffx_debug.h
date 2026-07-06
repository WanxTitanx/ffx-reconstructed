// ============================================================================
// ffx_debug.h — FFX Debug/Developer Tools Header
// Phase 3-E: FFX Game Stubs
// Source: RESEARCH_ENGINE_TOOLS.md section 4 (Debug/Developer Tools)
// ============================================================================

#ifndef FFX_DEBUG_H
#define FFX_DEBUG_H

#include "ffx_types.h"

// ============================================================================
// FFX_Dbg — PS2-era Field Debug / Guide Map Tools
// ============================================================================

int  FFX_Dbg_ConvertGuideMapData(void* this_ptr, const char* path);
void FFX_Dbg_SceneElementEditorHandler(void* pField, int keyCode);
void FFX_Dbg_LoadGuideRsdFromHost(const char* rsdName);
int  FFX_Dbg_SaveGuideMap(const char* outputPath);
int  FFX_Dbg_ParseRsdBgSections(void* pRsdData, int dataSize);
void FFX_Dbg_ChrInfoPanelInputAndDraw(void* pPanel, float deltaTime);
void FFX_Dbg_SetControlledActorAndOpenInfoPanel(int actorId);
int  FFX_Dbg_TerminalProcessCommand(const char* cmd, void* pOutput);
int  FFX_Dbg_LookupMapIdFromCsv(const char* mapName);
int  FFX_Dbg_UploadMap2dFileToHost(const char* localPath, const char* hostPath);
int  FFX_Dbg_SceWriteWrapper(int fd, const void* buf, int count);

// ============================================================================
// FFX_DebugUI — On-Screen Debug UI (FPS, Status, Config Tree, Model Browser)
// ============================================================================

void FFX_DebugUI_Draw(void* pRenderCtx, float deltaTime);
void FFX_DebugUI_ProcessInput(void* pInputState);
void FFX_DebugUI_ToggleVisibility(void);
int  FFX_DebugUI_IsVisible(void);
void FFX_DebugUI_FpsCounterDraw(void* pRenderCtx);
void FFX_DebugUI_StatusCycleDraw(void* pRenderCtx, int cycleMode);
void FFX_DebugUI_ConfigTreeBrowse(void* pRenderCtx, void* pConfigNode);
void FFX_DebugUI_FlagDisplay(void* pRenderCtx, void* pFlagSet);
void FFX_DebugUI_ModelBrowserDraw(void* pRenderCtx, int selectedModel);

// ============================================================================
// FFX_DebugGrid — Visual Debug Grid Overlay
// ============================================================================

void FFX_DebugGrid_Init(void);
void FFX_DebugGrid_Draw(void* pRenderCtx);
void FFX_DebugGrid_SetEnabled(int enabled);
int  FFX_DebugGrid_IsEnabled(void);

// ============================================================================
// FFX_AutoTestManager — Debug Automation Console
// ============================================================================

void FFX_AutoTestManager_InitSingleton(void* pStorage, int slotCount);
void FFX_AutoTestManager_ProcessCommand(const char* cmd);
void FFX_AutoTestManager_Update(float deltaTime);
int  FFX_AutoTestManager_IsTestRunning(void);
void FFX_AutoTestManager_AbortTest(void);

// ============================================================================
// FFX_StackWalker — Stack Trace Capture / Display
// ============================================================================

int  FFX_StackWalker_Capture(void* pContext, int maxDepth, void** pOutFrames);
void FFX_StackWalker_Display(void* pContext, void** pFrames, int frameCount);

// ============================================================================
// FFX_Debug — General Debug Utilities
// ============================================================================

void FFX_Debug_Sleep(int milliseconds);
void FFX_FieldRender_WriteConsoleString(const char* text);
void FFX_FieldRender_WriteConsoleStringFormatted(const char* fmt, ...);

#endif // FFX_DEBUG_H
