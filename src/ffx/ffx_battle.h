// ============================================================================
// ffx_battle.h — FFX Battle System Header
// Phase 3-E: FFX Game Stubs
// ============================================================================

#ifndef FFX_BATTLE_H
#define FFX_BATTLE_H

#include "ffx_types.h"

// ============================================================================
// FFX_BtlUI — Battle HUD System
// ============================================================================

void FFX_BtlUI_FreeCursorRingAllocation(void* pAlloc);
void FFX_BtlUI_DestroyCursorRingArray(void* pArray);
void FFX_BtlUI_SetHudDrawParam(void* pHudDrawParam);
void* FFX_BtlUI_GetOverlayIfNotInitialized(void* pOverlayCtx);
void FFX_BtlUI_ReadActorPositionFromInstance(void* pInstance, void* pOutPos);
void* FFX_BtlUI_GetHudDrawParam(void* pContext);
void FFX_BtlUI_HudTarget_InitRender(void* pTarget);
int FFX_BtlUI_GetMpConditional(void* pActor);
void FFX_BtlUI_HudBar_ResetScale(void* pHudBar);
void FFX_BtlUI_SetHudElementOverlayId(void* pElement, int overlayId);
void FFX_BtlUI_SetCharHudBorderParam(void* pHud, int borderParam);
void FFX_BtlUI_InitHudPairString(void* pHudPair);
void FFX_BtlUI_ClearHudActorBuffer(void* pBuffer);
void FFX_BtlUI_HudTarget_Render(void* pTarget);
void FFX_BtlUI_HudGaugeRegister(void* pGaugeCtx);
void FFX_BtlUI_RenderHudGauges(void* pRenderCtx);
void FFX_BtlUI_HudGaugeDrawParty(void* pPartyGauge);
void FFX_BtlUI_MagicSlotInitByType(void* pSlot, int typeId);

// --- HUD Gauge helpers ---
void FFX_BtlUI_HudGauge_InitCircleDraw(void* pGauge);
void FFX_BtlUI_HudGauge_ComputeCircularPattern(void* pGauge, void* pOutVertices, int count);
void FFX_BtlUI_HudGaugeScaleVec4(void* pVec, float sx, float sy, float sz, float sw);
void FFX_BtlUI_HudGaugeDrawEnemy(void* pGaugeCtx);
void FFX_BtlUI_HudGaugeDrawOverdrive(void* pOdGauge);
void FFX_BtlUI_HudGaugeDrawStatusIcons(void* pIconGroup);
void FFX_BtlUI_HudGaugeAnimateIn(void* pGauge);
void FFX_BtlUI_HudGaugeAnimateOut(void* pGauge);
void FFX_BtlUI_HudGaugeUpdatePosition(void* pGauge, float x, float y);

// --- HUD slot / node system ---
void FFX_BtlUI_InitSlotStruct(void* pSlot, int slotType);
void FFX_BtlUI_TransformHudElement(void* pElement, void* pTransform);
void FFX_BtlUI_UpdateNodeTransform(void* pNode);
void FFX_BtlUI_SlotSetPosition(void* pSlot, float x, float y);
void FFX_BtlUI_SlotSetScale(void* pSlot, float sx, float sy);
void FFX_BtlUI_SlotSetColor(void* pSlot, int color);
void FFX_BtlUI_SlotSetVisibility(void* pSlot, int visible);
void* FFX_BtlUI_NodeAllocate(void* pNodePool, int type);
void FFX_BtlUI_NodeFree(void* pNodePool, void* pNode);

// ============================================================================
// FFX_Battle — Battle State / Action Queue System
// ============================================================================

int FFX_Battle_IsEncounterActive(void);
int FFX_Battle_QueueAction(void* pAction);
void FFX_Battle_SetTargetPosition(void* pTarget, float x, float y, float z);
void FFX_Battle_SetInputMode(int mode);
int FFX_Battle_GetInputMode(void);
void FFX_Battle_ClearEncounterState(void);
int FFX_Battle_GetCurrentCommand(void* pActor);
void FFX_Battle_SetCurrentCommand(void* pActor, int cmdId);
int FFX_Battle_GetTargetCount(void* pAction);
void* FFX_Battle_AllocateTargetList(int maxTargets);
void FFX_Battle_FreeTargetList(void* pTargetList);
void* FFX_Battle_ResolveTarget(void* pAction, int slot);
int FFX_Battle_ProcessActionQueue(void);
int FFX_Battle_ValidateAction(void* pAction);
int FFX_Battle_ComputeActionCost(void* pAction);

// ============================================================================
// FFX_Encounter — Encounter/Event Trigger System
// ============================================================================

int FFX_Encounter_CheckAnyInstancePassesTrigger(void* pTrigger, void** ppInstances, int count);
int FFX_Encounter_IsEventEncounterType(void* pEncounter, int type);
int FFX_Encounter_EvaluateDistanceTrigger(void* pEncounter, void* pPlayerPos);
void FFX_Encounter_ReleaseInstanceAttachments(void* pInstance);
void FFX_Encounter_UpdateEncounterMode(void* pEncounter, int mode);
int FFX_Encounter_FindAndFlagInstance(void* pEncounter, int instanceId);

// --- Encounter field overrides ---
int FFX_Encounter_ResolveFieldOverrideOrDefault(void* pEncounter);
int FFX_Encounter_GetFieldOverride(void* pEncounter);
void FFX_Encounter_SetFieldOverride(void* pEncounter, int fieldOverride);
int FFX_Encounter_GetCurrentField(void* pEncounter);
void FFX_Encounter_SetCurrentField(void* pEncounter, int fieldId);
int FFX_Encounter_GetFormationOverride(void* pEncounter);
int FFX_Encounter_GetMusicOverride(void* pEncounter);
void FFX_Encounter_SetMusicOverride(void* pEncounter, int trackOverride);

#endif // FFX_BATTLE_H
