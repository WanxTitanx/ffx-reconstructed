// ============================================================================
// ffx_save.h — FFX Save/Load System Header
// Phase 3-E: FFX Game Stubs
// ============================================================================

#ifndef FFX_SAVE_H
#define FFX_SAVE_H

#include "ffx_types.h"
#include <stdint.h>

// ============================================================================
// Save System Constants
// ============================================================================

#define FFX_SAVE_PAYLOAD_SIZE       25848   // 0x6998 — total save payload bytes
#define FFX_SAVE_CRC_REGION_SIZE    25784   // 0x64B8 — bytes covered by CRC
#define FFX_SAVE_CRC_REGION_START   64      // first byte of CRC region
#define FFX_SAVE_CRC_PRIMARY_OFF    26      // u16 LE CRC at offset 26-27
#define FFX_SAVE_CRC_REDUNDANT_OFF  25844   // u32 LE redundant CRC at 25844-25847
#define FFX_SAVE_SLOT_COUNT         7       // slots 0..6
#define FFX_SAVE_HEADER_MARKER      0x01    // byte 0 for minimal saves
#define FFX_SAVE_TAMPER_TAG_OFF     32      // FFXED "Tamper Tag" at offset 32

// ============================================================================
// FFX_Save — Core Save/Load System
// ============================================================================

int  FFX_Save_LoadOrchestrator(int slotId, int loadFlags);
int  FFX_Save_SaveOrchestrator(int slotId, int saveFlags);
void FFX_Save_LoadOrchestrator_PostHydrateScenes(void);
int  FFX_Save_ComputeChecksum(const unsigned char* data, int size);
int  FFX_Save_ValidateChecksum(unsigned char* saveBuffer);
int  FFX_Save_ReadFromDisk(int slotId, unsigned char* outBuffer, int bufferSize);
int  FFX_Save_WriteToDisk(int slotId, const unsigned char* saveBuffer, int bufferSize);
int  FFX_Save_ReadThunk(int slotId);
int  FFX_Save_WriteThunk(int slotId);
int  FFX_Save_LoadSaveDataFromBuf(unsigned char* saveBuffer, int bufferSize);
void FFX_Save_SwapEndianStruct(void* pStruct, int structSize);
void FFX_Save_EnqueueFrameBufferClear(void);
const char* FFX_Save_ParseBytecodeToString(const unsigned char* bytecode, int bytecodeLen, char* outString, int outMaxLen);
int  FFX_Save_InitializeSlot(int slotId);
int  FFX_Save_EraseSlot(int slotId);
unsigned char* FFX_Save_GetSaveDataPtr(void);
int  FFX_Save_GetSaveSize(void);
int  FFX_Save_GetSlotCount(void);
int  FFX_Save_GetCurrentSlot(void);
void FFX_Save_SetCurrentSlot(int slotId);
int  FFX_Save_GetTimer(void);
void FFX_Save_SetTimer(int ticks);
int  FFX_Save_GetPlayTime(void);
void FFX_Save_EncodeSlotName(int slotId, char* outName, int maxLen);
void FFX_Save_FormatTimestamp(int ticks, char* outStr, int maxLen);

// ============================================================================
// FFX_Save — File I/O Helpers
// ============================================================================

int         FFX_Save_LoadFile(int slot, void* buffer);
int         FFX_Save_SaveFile(int slot, const void* buffer);
const char* FFX_Save_ResolveSlotPath(int slotId, char* outPath, int maxLen);
const char* FFX_Save_GetSaveDirectoryPath(char* outDir, int maxLen);
int         FFX_Save_EnsureSaveDir(void);

// ============================================================================
// FFX_Save — Slot Metadata / Validation
// ============================================================================

int         FFX_Save_GetSlotInfo(int slotId, void* outInfo);
int         FFX_Save_IsSlotEmpty(int slotId);
int         FFX_Save_IsSlotCorrupted(int slotId);
void        FFX_Save_FormatSlotName(int slotId, char* outName, int maxLen);
long long   FFX_Save_GetSlotTimestamp(int slotId);

// ============================================================================
// FFX_Save — Party / Character Data Accessors
// ============================================================================

int         FFX_Save_GetLevel(void);
int         FFX_Save_GetGil(void);
const char* FFX_Save_GetLocationName(char* outName, int maxLen);
int         FFX_Save_GetPartyMembers(int* outPartyIds, int maxCount);
const char* FFX_Save_GetCharacterName(int charId, char* outName, int maxLen);
int         FFX_Save_GetCharacterHp(int charId);
int         FFX_Save_GetCharacterMp(int charId);
int         FFX_Save_GetCharacterMaxHp(int charId);
int         FFX_Save_GetCharacterMaxMp(int charId);
int         FFX_Save_GetCharacterStrength(int charId);
int         FFX_Save_GetCharacterDefense(int charId);
int         FFX_Save_GetCharacterMagic(int charId);
int         FFX_Save_GetCharacterMagicDef(int charId);
int         FFX_Save_GetCharacterAgility(int charId);
int         FFX_Save_GetCharacterLuck(int charId);
int         FFX_Save_GetCharacterEvasion(int charId);
int         FFX_Save_GetCharacterAccuracy(int charId);
int         FFX_Save_GetOverdriveType(int charId);
int         FFX_Save_GetOverdriveGauge(int charId);
int         FFX_Save_GetEquippedWeapon(int charId);
int         FFX_Save_GetEquippedArmor(int charId);

// ============================================================================
// FFX_Save — Aeon Data Accessors
// ============================================================================

const char* FFX_Save_GetAeonName(int aeonId, char* outName, int maxLen);
int         FFX_Save_GetAeonHp(int aeonId);
int         FFX_Save_GetAeonMp(int aeonId);

// ============================================================================
// FFX_Save — Sphere Grid / Progress
// ============================================================================

int         FFX_Save_GetSphereGridProgress(int charId);

// ============================================================================
// FFX_Save — Game State Flags
// ============================================================================

int         FFX_Save_GetClearData(void);

#endif // FFX_SAVE_H
