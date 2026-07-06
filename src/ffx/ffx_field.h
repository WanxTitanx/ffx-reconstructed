// ============================================================================
// ffx_field.h — FFX Field System Header
// Phase 3-E: FFX Game Stubs
// ============================================================================

#ifndef FFX_FIELD_H
#define FFX_FIELD_H

#include "ffx_types.h"

// ============================================================================
// FFX_FieldMap — Field Map/Scene Management
// ============================================================================

void FFX_FieldMap_ActivateSceneBridge(void* pScene);
void FFX_FieldMap_ClearSceneLightingFlag(void* pScene);
int FFX_FieldMap_SetupSceneNodesAndMaterials_True(void* pScene);
void FFX_FieldMap_ResetState_Full(void* pFieldMap);
int FFX_FieldMap_ProcessLevelName_inner(void* pBuffer, const char* levelName);
void FFX_FieldMap_LoadColorCorrectionForLevel(const char* levelName);
void FFX_FieldMap_SetAsyncLoadInProgress(int inProgress);
int FFX_FieldMap_LoadTexAndShaderData(void* pFieldMap, const char* levelName);
void FFX_FieldMap_Iter_Ctor(void* pIterator);
void FFX_FieldMap_LazyInitWrapper(void* pApp);

// ============================================================================
// FFX_Field — Field Engine Core
// ============================================================================

void FFX_Field_UpdateAndRender(void* pApp, float deltaTime);
void FFX_Field_ProcessInputAndEvents(void* pField, float deltaTime);
void FFX_Field_EnablePostProcessOnFadeInit(void* pField);
void FFX_Field_TerminatePostProcessFade(void* pField);
int FFX_Field_CheckRenderEngineActive(void* pField);
void FFX_Field_ReleaseRefCountedPtr(void** ppPtr);
void FFX_Field_UpdateModelViewMatrices(void* pField);
void FFX_Field_TerminateOrchestratorAndReleaseClusters(void* pField);
void FFX_Field_TerminatePostProcessAndFramebuffers(void* pField);
void FFX_Field_ResetRenderEngineFlag(void* pField);
void FFX_Field_OnResolutionChanged_SetupAllEffects(void* pField, int width, int height);
void FFX_Field_ClampInput(void* pField);
int FFX_Field_CopySaveBlock(void* pDst, const void* pSrc, int size);
void FFX_Field_PreInitSubsystems(void* pApp);
void FFX_Field_TerminateSubsystems(void* pApp);

#endif // FFX_FIELD_H
