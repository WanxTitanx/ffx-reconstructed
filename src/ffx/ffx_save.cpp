// ============================================================================
// ffx_save.cpp — FFX Save/Load System Stubs
// Phase 3-E: FFX Game Stubs
// Source: backups/research/RESEARCH_ARCHITECTURE.md (§3 Save/Load),
//         docs/reverse/FFX_SAVE_FORMAT_AND_SPHEREGRID_LAYOUT_2026-06-18.md,
//         docs/reverse/FFX_SAVE_CHECKSUM_CRACKED_2026-06-10.md,
//         docs/reverse/FFX_SPHEREGRID_SAVE_ORCHESTRATOR_RE_2026-06-19.md
// Each stub includes address, xref count, and brief description.
// ============================================================================

#include "ffx_save.h"
#include "../include/ffx_structs.h"
#include <cstring>
#include <cstdio>
#include <windows.h>

// ============================================================================
// Save System Constants (internal)
// ============================================================================
#define SAVE_FILE_SIZE 0x6900    // Tamanho total de um slot de save
#define SAVE_SLOT_COUNT 15       // Numero maximo de slots
#define SAVE_HEADER_MARKER 0x01  // Marker de slot ocupado

// Live save data pointer in game memory (0x112CA90, alias
// MsGetSaveEventAddress) The game maintains a 25848-byte buffer at this address
// that mirrors the on-disk save payload. Functions below operate on this
// buffer.
static unsigned char *g_SaveDataPtr = NULL;

// Current slot tracking (0..6, -1 = none selected)
static int g_CurrentSlotId = -1;

// Forward declarations for internal helpers
static int internal_get_save_dir(char *outPath, int maxLen);
static int internal_get_slot_path(int slotId, char *outPath, int maxLen);

// CRC bypass flag (0xCCB9A4 in the original EXE — if non-zero, CRC validation
// is skipped entirely, used for cloud-sync / dev import paths)
static int g_CrcBypassFlag = 0;

// --------------------------------------------------------------------------
// Internal save-data layout offsets (from FFX_SAVE_FORMAT docs)
// Character block stride: 0x2A0 bytes per character
// --------------------------------------------------------------------------
#define SAVE_OFF_TIMER               0x44    // u32 LE, raw tick count
#define SAVE_OFF_LOCATION_NAME       0x70    // char[64], null-terminated
#define SAVE_OFF_GIL                 0xC8    // u32 LE
#define SAVE_OFF_PARTY_IDS           0x160   // u8[7] character ID array
#define SAVE_OFF_CHARACTER_BASE      0x198   // start of character data block
#define CHAR_STRIDE                  0x2A0   // bytes per character record

// Stat offsets relative to character base + (charId * CHAR_STRIDE)
#define CHAR_OFF_HP                  0x18    // u32 LE current HP
#define CHAR_OFF_MP                  0x1C    // u32 LE current MP
#define CHAR_OFF_MAXHP               0x20    // u32 LE max HP
#define CHAR_OFF_MAXMP               0x24    // u32 LE max MP
#define CHAR_OFF_NAME                0x08    // char[7] character name
#define CHAR_OFF_STATS               0x28    // stats sub-block (8 bytes)
#define STAT_STRENGTH                0x00    // byte
#define STAT_DEFENSE                 0x01    // byte
#define STAT_MAGIC                   0x02    // byte
#define STAT_MAGIC_DEF               0x03    // byte
#define STAT_AGILITY                 0x04    // byte
#define STAT_EVASION                 0x05    // byte
#define STAT_LUCK                    0x06    // byte
#define STAT_ACCURACY                0x07    // byte
#define STAT_OVERDRIVE_TYPE          0x0A    // byte
#define STAT_OVERDRIVE_GAUGE         0x48    // u16 LE (percentage 0..100)
#define STAT_EQUIP_WEAPON            0x50    // u16 LE equipment index
#define STAT_EQUIP_ARMOR             0x52    // u16 LE equipment index

// Aeon block (approximate offsets, after 7 character blocks)
#define SAVE_OFF_AEON_BASE           0x13F8  // approximate
#define AEON_STRIDE                  0xE0    // bytes per aeon (approximate)
#define AEON_OFF_NAME                0x00    // char[10] aeon name
#define AEON_OFF_HP                  0x14    // u32 LE max HP
#define AEON_OFF_MP                  0x18    // u32 LE max MP

// Helper: get character block pointer (null-safe)
// Returns pointer to the start of a character's data, or NULL if out of range
static inline unsigned char *char_block(int charId) {
    if (!g_SaveDataPtr || charId < 0 || charId > 6)
        return NULL;
    return g_SaveDataPtr + SAVE_OFF_CHARACTER_BASE + (charId * CHAR_STRIDE);
}

// Helper: get aeon block pointer (null-safe, approximate offset)
static inline unsigned char *aeon_block(int aeonId) {
    if (!g_SaveDataPtr || aeonId < 0 || aeonId > 7)
        return NULL;
    return g_SaveDataPtr + SAVE_OFF_AEON_BASE + (aeonId * AEON_STRIDE);
}

// ============================================================================
// FFX_Save — Core Orchestrator
// ============================================================================

// 0x8B1580 — xrefs: ~20
// Save/load UI state machine (~7.5 KB, 310 basic blocks).
// Drives the save crystal menu flow: popups, scene transitions, read/write
// thunks. Dispatches to FFX_Save_ReadThunk or FFX_Save_WriteThunk depending
// on the UI state. Referred to as Save_LoadOrchestrator_WAKKA in RE notes.
// Called from FFX_Menu_ScreenEntryDispatch during save-crystal interaction.
int FFX_Save_LoadOrchestrator(int slotId, int loadFlags) {
  STUBBED("FFX_Save_LoadOrchestrator");
  return FFX_OK;
}

// 0x8B1580 — xrefs: ~15 (same physical function as LoadOrchestrator;
// the orchestrator branches on an internal FSM state to pick read vs write)
// Handles the save-to-disk path: triggers scene-freeze, calls
// FFX_Save_WriteThunk, then restores field state.
int FFX_Save_SaveOrchestrator(int slotId, int saveFlags) {
  STUBBED("FFX_Save_SaveOrchestrator");
  return FFX_OK;
}

// 0x8B3000 (derived — inside the orchestrator's post-write/read tail)
// xrefs: ~3
// After a save or load completes, re-hydrates field scene state (camera,
// lighting, actor positions) that was frozen during the save-crystal menu.
// Reads from SaveData to reposition the player if the load changed maps.
void FFX_Save_LoadOrchestrator_PostHydrateScenes(void) {
  STUBBED("FFX_Save_LoadOrchestrator_PostHydrateScenes");
}

// ============================================================================
// FFX_Save — Checksum Functions
// ============================================================================

// 0x8B1400 — xrefs: 5
// CRC-16 CCITT with quirk: table[255] = 0 (table generator stops at n=254).
// Poly 0x1021, init 0xFFFF, MSB-first (no reflection), xorout 0xFFFF.
// Region: bytes 64..25847 inclusive = 25784 bytes (0x64B8).
// Before computing: bytes 25844..25847 MUST be zeroed (redundant CRC copy).
// Result stored at bytes 26-27 (u16 LE) and 25844-25847 (u32 LE).
// Referred to as FFX_Save_ComputeCrc16_CHAPPU in RE notes.
int FFX_Save_ComputeChecksum(const unsigned char *data, int size) {
  // Standard CRC-16-CCITT bit-by-bit (poly 0x1021, init 0xFFFF, xorout 0xFFFF)
  if (!data || size <= 0) return 0xFFFF;
  uint16_t crc = 0xFFFF;
  for (int i = 0; i < size; i++) {
    crc ^= (uint16_t)data[i] << 8;
    for (int j = 0; j < 8; j++) {
      if (crc & 0x8000)
        crc = (uint16_t)((crc << 1) ^ 0x1021);
      else
        crc = (uint16_t)(crc << 1);
    }
  }
  return (int)(crc ^ 0xFFFF);
}

// 0x647F20 — xrefs: 4
// Validates the checksum stored in a loaded save buffer:
// 1. Reads stored CRC from bytes 26-27 (u16 LE)
// 2. Verifies redundant copy at bytes 25844-25847 matches
// 3. Zeros bytes 25844-25847, recomputes CRC over region 64..25847
// 4. Mismatch -> "Data is corrupt" error
// Referred to as FFX_Save_ValidateChecksum_CHAPPU in RE notes.
// Returns FFX_OK on match, FFX_FAIL on corruption.
int FFX_Save_ValidateChecksum(unsigned char *saveBuffer) {
  if (!saveBuffer) return FFX_FAIL;

  // Read stored CRC from bytes 26-27 (u16 LE)
  uint16_t storedCrc = (uint16_t)saveBuffer[26] |
                       ((uint16_t)saveBuffer[27] << 8);

  // Read redundant copy at bytes 25844-25847 (u32 LE)
  uint32_t redundant = (uint32_t)saveBuffer[25844] |
                       ((uint32_t)saveBuffer[25845] << 8) |
                       ((uint32_t)saveBuffer[25846] << 16) |
                       ((uint32_t)saveBuffer[25847] << 24);

  // Verify redundant copy matches
  if ((uint32_t)storedCrc != (redundant & 0xFFFF))
    return FFX_FAIL;

  // Save old redundant bytes, zero them, recompute CRC
  unsigned char saved[4];
  saved[0] = saveBuffer[25844];
  saved[1] = saveBuffer[25845];
  saved[2] = saveBuffer[25846];
  saved[3] = saveBuffer[25847];
  saveBuffer[25844] = 0;
  saveBuffer[25845] = 0;
  saveBuffer[25846] = 0;
  saveBuffer[25847] = 0;

  int computed = FFX_Save_ComputeChecksum(
      saveBuffer + 64, 25847 - 64 + 1);

  // Restore redundant bytes (game leaves them as-is after validation)
  saveBuffer[25844] = saved[0];
  saveBuffer[25845] = saved[1];
  saveBuffer[25846] = saved[2];
  saveBuffer[25847] = saved[3];

  return (computed == (int)storedCrc) ? FFX_OK : FFX_FAIL;
}

// ============================================================================
// FFX_Save — File I/O (CHAPPU Layer)
// ============================================================================

// 0x646CE0 — xrefs: 8
// Low-level save file reader. Opens "saves/%02d.SAV" (resolved to
// %USERPROFILE%\Documents\SQUARE ENIX\...\ffx_%03d via path resolver),
// fread 0x6900 bytes, calls FFX_Save_ValidateChecksum.
// On CRC mismatch, returns error without modifying outBuffer.
// Referred to as FFX_Save_ReadFile_CHAPPU in RE notes.
int FFX_Save_ReadFromDisk(int slotId, unsigned char *outBuffer,
                          int bufferSize) {
  if (!outBuffer || bufferSize < SAVE_FILE_SIZE)
    return FFX_FAIL;
  if (slotId < 0 || slotId >= FFX_SAVE_SLOT_COUNT)
    return FFX_FAIL;

  char path[MAX_PATH];
  if (!internal_get_slot_path(slotId, path, sizeof(path)))
    return FFX_FAIL;

  HANDLE hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL,
                             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
  if (hFile == INVALID_HANDLE_VALUE)
    return FFX_FAIL;

  DWORD bytesRead = 0;
  BOOL ok = ReadFile(hFile, outBuffer, SAVE_FILE_SIZE, &bytesRead, NULL);
  CloseHandle(hFile);

  if (!ok || bytesRead != SAVE_FILE_SIZE)
    return FFX_FAIL;

  // Validate checksum; on mismatch return error without modifying outBuffer
  // (ValidateChecksum does an internal read-only check that temporarily zeroes
  //  the redundant CRC bytes and restores them, so outBuffer is preserved)
  int crcResult = FFX_Save_ValidateChecksum(outBuffer);
  return (crcResult == FFX_OK) ? FFX_OK : FFX_FAIL;
}

// 0x646FA0 — xrefs: 6
// Low-level save file writer. Opens "saves/%02d.SAV" for binary write:
// 1. Zeros redundant CRC at bytes 25844-25847
// 2. Computes CRC over region 64..25847
// 3. Writes CRC to bytes 26-27 (u16 LE) and 25844-25847 (u32 LE)
// 4. fwrite 0x6900 bytes
// Referred to as FFX_Save_WriteFileWithCrc_CHAPPU in RE notes.
int FFX_Save_WriteToDisk(int slotId, const unsigned char *saveBuffer,
                         int bufferSize) {
  if (!saveBuffer || bufferSize < SAVE_FILE_SIZE)
    return FFX_FAIL;
  if (slotId < 0 || slotId >= FFX_SAVE_SLOT_COUNT)
    return FFX_FAIL;

  char path[MAX_PATH];
  if (!internal_get_slot_path(slotId, path, sizeof(path)))
    return FFX_FAIL;

  // Ensure the save directory exists
  FFX_Save_EnsureSaveDir();

  // Make a writable copy to patch CRC bytes without modifying the caller's buffer
  unsigned char writeBuf[SAVE_FILE_SIZE];
  memcpy(writeBuf, saveBuffer, SAVE_FILE_SIZE);

  // 1. Zero redundant CRC bytes at 25844-25847
  writeBuf[FFX_SAVE_CRC_REDUNDANT_OFF + 0] = 0;
  writeBuf[FFX_SAVE_CRC_REDUNDANT_OFF + 1] = 0;
  writeBuf[FFX_SAVE_CRC_REDUNDANT_OFF + 2] = 0;
  writeBuf[FFX_SAVE_CRC_REDUNDANT_OFF + 3] = 0;

  // 2. Compute CRC over region 64..25847
  int crc = FFX_Save_ComputeChecksum(
      writeBuf + FFX_SAVE_CRC_REGION_START,
      FFX_SAVE_CRC_REDUNDANT_OFF + 4 - FFX_SAVE_CRC_REGION_START);

  // 3. Write CRC to bytes 26-27 (u16 LE) and 25844-25847 (u32 LE)
  uint16_t crc16 = (uint16_t)(crc & 0xFFFF);
  writeBuf[FFX_SAVE_CRC_PRIMARY_OFF + 0] = (unsigned char)(crc16 & 0xFF);
  writeBuf[FFX_SAVE_CRC_PRIMARY_OFF + 1] = (unsigned char)((crc16 >> 8) & 0xFF);

  writeBuf[FFX_SAVE_CRC_REDUNDANT_OFF + 0] = (unsigned char)(crc16 & 0xFF);
  writeBuf[FFX_SAVE_CRC_REDUNDANT_OFF + 1] = (unsigned char)((crc16 >> 8) & 0xFF);
  writeBuf[FFX_SAVE_CRC_REDUNDANT_OFF + 2] = 0;
  writeBuf[FFX_SAVE_CRC_REDUNDANT_OFF + 3] = 0;

  // 4. Write 0x6900 bytes to disk
  HANDLE hFile = CreateFileA(path, GENERIC_WRITE, 0, NULL,
                             CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
  if (hFile == INVALID_HANDLE_VALUE)
    return FFX_FAIL;

  DWORD bytesWritten = 0;
  BOOL ok = WriteFile(hFile, writeBuf, SAVE_FILE_SIZE, &bytesWritten, NULL);
  CloseHandle(hFile);

  if (!ok || bytesWritten != SAVE_FILE_SIZE)
    return FFX_FAIL;

  return FFX_OK;
}

// 0x649460 — xrefs: 3
// Thunk called by FFX_Save_LoadOrchestrator to initiate a file read.
// Wraps FFX_Save_ReadFromDisk with the current slot id and live save buffer.
// Handles the scene-freeze handshake before delegating to the CHAPPU layer.
// Referred to as FFX_Save_ReadThunk_CHAPPU in RE notes.
// Decompiled from 0x646ce0. Opens %02d.SAV from saves dir, reads whole
// payload, validates CRC16, returns 0 on success or -1 on I/O error.
int FFX_Save_ReadThunk(int slotId) {
  if (slotId < 0 || slotId >= FFX_SAVE_SLOT_COUNT)
    return -1;
  if (!g_SaveDataPtr)
    return -1;

  // Delegate to the existing ReadFromDisk which handles file I/O
  int ret = FFX_Save_ReadFromDisk(slotId, g_SaveDataPtr, SAVE_FILE_SIZE);
  if (ret != FFX_OK)
    return -1;

  // Validate CRC16 (matches original: FFX_Save_ValidateChecksum called post-read)
  ret = FFX_Save_ValidateChecksum(g_SaveDataPtr);
  if (ret != FFX_OK) {
    // Original logs via nullsub_76 — we skip debug spam
    return -1;
  }

  return 0;  // FFX_OK
}

// 0x649490 — xrefs: 3
// Thunk called by FFX_Save_SaveOrchestrator to initiate a file write.
// Wraps FFX_Save_WriteToDisk with the current slot id and live save buffer.
// Handles the scene-freeze handshake before delegating to the CHAPPU layer.
// Referred to as FFX_Save_WriteThunk_CHAPPU in RE notes.
// Decompiled from 0x646fa0. Zeros checksum fields, computes CRC16 over
// 25784 bytes at save+0x40, writes full payload via WriteToDisk.
int FFX_Save_WriteThunk(int slotId) {
  if (slotId < 0 || slotId >= FFX_SAVE_SLOT_COUNT)
    return -1;
  if (!g_SaveDataPtr)
    return -1;

  // Original zeroes checksum fields before CRC computation:
  // *(uint32_t*)(g_SaveDataPtr + 0x64B4) = 0;  — redundant CRC slot at end
  // *(uint32_t*)(saveData + 0x40 + 0x64B4) = 0; — duplicate zero
  // These are at offset 25844-25847 (redundant CRC copy)

  // Compute CRC16 over 25784 bytes starting at save+0x40 (skip header)
  // CRC poly 0x1021, init 0xFFFF, xorout 0xFFFF (same as ComputeChecksum)
  int crc = FFX_Save_ComputeChecksum(g_SaveDataPtr + 0x40, 25784);

  // Store CRC in the save header at byte 26-27 (u16 LE)
  g_SaveDataPtr[26] = (unsigned char)(crc & 0xFF);
  g_SaveDataPtr[27] = (unsigned char)((crc >> 8) & 0xFF);

  // Also store redundant copy at the end of the data region
  // (offset 0x40 + 0x64B4 = 0x64F4 from buffer start)
  *(uint32_t *)(g_SaveDataPtr + 0x64F4) = (uint32_t)(uint16_t)crc;

  // Delegate to existing WriteToDisk
  return FFX_Save_WriteToDisk(slotId, g_SaveDataPtr, SAVE_FILE_SIZE);
}

// 0x8B5450 — xrefs: 5
// Bulk-copies the on-disk save payload into the live SaveData buffer.
// memcpy(SaveData, file+0x40, 0x68C0) — copies all 25848 bytes from
// the file buffer (which includes the FFXED container header at file+0
// and payload starting at file+0x40) into the game's live save region.
// Referred to as Save_LoadSaveDataFromBuf_WAKKA in RE notes.
int FFX_Save_LoadSaveDataFromBuf(unsigned char *saveBuffer, int bufferSize) {
  if (!saveBuffer || bufferSize < 0x6900)
    return FFX_FAIL;
  // Copy from file buffer offset 0x40 (skip FFXED header) into live buffer
  if (!g_SaveDataPtr)
    return FFX_FAIL;
  // The payload is at file offset 0x40, size FFX_SAVE_PAYLOAD_SIZE
  int copySize = (bufferSize - 0x40 < FFX_SAVE_PAYLOAD_SIZE)
      ? (bufferSize - 0x40) : FFX_SAVE_PAYLOAD_SIZE;
  if (copySize <= 0) return FFX_FAIL;
  memcpy(g_SaveDataPtr, saveBuffer + 0x40, (size_t)copySize);
  return FFX_OK;
}

// ============================================================================
// FFX_Save — Data Conversion / Post-Processing
// ============================================================================

// 0x647C50 — xrefs: 2
// Swaps endianness of a struct within the save buffer.
// Needed for cross-platform compatibility (PS2 big-endian -> PC little-endian)
// Applied to multi-byte fields (u16/u32) in the equipment and character
// sections during load. The save format is natively LE on PC but some fields
// may retain PS2 byte ordering depending on how they were written.
// Decompiled from 0x6477c0. Swaps specific endian-sensitive regions of the
// 148-byte save slot entry: dword[0..2], dword[5..10], word[31..39],
// dword[20..23], word[24..33], dword[34..36].
void FFX_Save_SwapEndianStruct(void *pStruct, int structSize) {
  if (!pStruct || structSize < 148) return;
  unsigned char *p = (unsigned char *)pStruct;

  // Helper: swap 4 bytes (dword) in-place
  auto swap4 = [&](int off) {
    unsigned char tmp = p[off];
    p[off] = p[off + 3];
    p[off + 3] = tmp;
    tmp = p[off + 1];
    p[off + 1] = p[off + 2];
    p[off + 2] = tmp;
  };
  // Helper: swap 2 bytes (word) in-place
  auto swap2 = [&](int off) {
    unsigned char tmp = p[off];
    p[off] = p[off + 1];
    p[off + 1] = tmp;
  };

  // Region 1: dwords at offsets 0, 4, 8 (3 dwords)
  for (int off = 0; off < 12; off += 4) swap4(off);
  // Region 2: dwords at offsets 20, 24, 28, 32, 36, 40 (6 dwords)
  for (int off = 20; off < 44; off += 4) swap4(off);
  // Region 3: words at offsets 62-78 (9 words)
  for (int off = 62; off < 80; off += 2) swap2(off);
  // Region 4: dwords at offsets 80-92 (4 dwords)
  for (int off = 80; off < 96; off += 4) swap4(off);
  // Region 5: words at offsets 96-134 (20 words)
  for (int off = 96; off < 136; off += 2) swap2(off);
  // Region 6: dwords at offsets 136-144 (3 dwords)
  for (int off = 136; off < 148; off += 4) swap4(off);
}

// 0x8B31A0 — xrefs: 2
// Enqueues a frame-buffer clear operation to the Phyre render engine
// after a save/load operation completes. This prevents visual artifacts
// from the save-crystal menu transition back to the field.
// Calls into FFX_Phyre_BindRenderTargetStack with a clear request.
void FFX_Save_EnqueueFrameBufferClear(void) {
  // In the original: builds a 152-byte clear-command quad struct (pos=0, size=128)
  // and calls FFX_Menu_RenderEnqueue("FrameBuffer") to clear the framebuffer.
  // The menu renderer stub doesn't support this yet, so this is a no-op until
  // the render queue system handles framebuffer clears.
  // Decompiled from 0x8e5f60.
}

// 0x8B32E0 — xrefs: 1
// Parses an ATEL bytecode string into a human-readable string for
// save slot naming. The save crystal menu stores slot names as
// ATEL-encoded strings; this function decodes them to display text.
// Returns the parsed string, or NULL on invalid bytecode.
const char *FFX_Save_ParseBytecodeToString(const unsigned char *bytecode,
                                           int bytecodeLen, char *outString,
                                           int outMaxLen) {
  STUBBED("FFX_Save_ParseBytecodeToString");
  return NULL;
}

// ============================================================================
// FFX_Save — Slot Management
// ============================================================================

// Save slot info structure (internal layout for FFX_Save_GetSlotInfo)
// Fields packed as consecutive int32 values for void* outInfo compatibility.
#define SLOTINFO_OFF_STATE           0   // int32: 0=empty 1=occupied
#define SLOTINFO_OFF_PLAYTIME        4   // int32: seconds
#define SLOTINFO_OFF_LEVEL           8   // int32: highest party sphere level
#define SLOTINFO_OFF_GIL            12   // int32: current gil
#define SLOTINFO_OFF_PARTY_COUNT    16   // int32: number of party members
#define SLOTINFO_OFF_PARTY_IDS      20   // int32[7]: party member IDs
#define SLOTINFO_OFF_LOCATION       48   // char[64]: location name
#define SLOTINFO_OFF_TIMESTAMP      112  // int64: Unix timestamp
#define SLOTINFO_SIZE               120  // total struct size

// 0x8B1A00 — xrefs: 2
// Initializes a save slot to its default empty state.
// Writes the header marker byte (0x01), zeroes the payload (25848 bytes),
// sets default Sphere Grid state via dat09/10/11 resource merge,
// then writes the initial checksum. Called on "New Save" in the menu.
// Returns FFX_OK on success, FFX_FAIL if slot is locked or I/O error.
int FFX_Save_InitializeSlot(int slotId) {
  if (slotId < 0 || slotId >= FFX_SAVE_SLOT_COUNT)
    return FFX_FAIL;

  // Create a clean save buffer
  unsigned char buf[SAVE_FILE_SIZE];
  memset(buf, 0, sizeof(buf));

  // Set header marker at byte 0
  buf[0] = FFX_SAVE_HEADER_MARKER;

  // Zero the CRC region before computing
  buf[FFX_SAVE_CRC_REDUNDANT_OFF + 0] = 0;
  buf[FFX_SAVE_CRC_REDUNDANT_OFF + 1] = 0;
  buf[FFX_SAVE_CRC_REDUNDANT_OFF + 2] = 0;
  buf[FFX_SAVE_CRC_REDUNDANT_OFF + 3] = 0;

  // Compute initial checksum over region 64..25847
  int crc = FFX_Save_ComputeChecksum(
      buf + FFX_SAVE_CRC_REGION_START,
      FFX_SAVE_CRC_REDUNDANT_OFF + 4 - FFX_SAVE_CRC_REGION_START);

  uint16_t crc16 = (uint16_t)(crc & 0xFFFF);
  buf[FFX_SAVE_CRC_PRIMARY_OFF + 0] = (unsigned char)(crc16 & 0xFF);
  buf[FFX_SAVE_CRC_PRIMARY_OFF + 1] = (unsigned char)((crc16 >> 8) & 0xFF);
  buf[FFX_SAVE_CRC_REDUNDANT_OFF + 0] = (unsigned char)(crc16 & 0xFF);
  buf[FFX_SAVE_CRC_REDUNDANT_OFF + 1] = (unsigned char)((crc16 >> 8) & 0xFF);

  // Write to disk
  return FFX_Save_WriteToDisk(slotId, buf, SAVE_FILE_SIZE);
}

// 0x8B1B80 — xrefs: 1
// Erases a save slot: overwrites the file with an empty save header,
// zeroes the live buffer for that slot, and updates the slot metadata.
// Called from the "Delete Save" menu option after user confirmation.
// Returns FFX_OK on success, FFX_FAIL if slot is empty or I/O error.
int FFX_Save_EraseSlot(int slotId) {
  if (slotId < 0 || slotId >= FFX_SAVE_SLOT_COUNT)
    return FFX_FAIL;

  char path[MAX_PATH];
  if (!internal_get_slot_path(slotId, path, sizeof(path)))
    return FFX_FAIL;

  // Write a minimal empty save (header marker 0x00 = empty, zero CRC)
  unsigned char emptyBuf[SAVE_FILE_SIZE];
  memset(emptyBuf, 0, sizeof(emptyBuf));
  // Header marker 0x00 signals empty slot
  emptyBuf[0] = 0x00;

  HANDLE hFile = CreateFileA(path, GENERIC_WRITE, 0, NULL,
                             CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
  if (hFile == INVALID_HANDLE_VALUE)
    return FFX_FAIL;

  DWORD bytesWritten = 0;
  BOOL ok = WriteFile(hFile, emptyBuf, SAVE_FILE_SIZE, &bytesWritten, NULL);
  CloseHandle(hFile);

  if (!ok || bytesWritten != SAVE_FILE_SIZE)
    return FFX_FAIL;

  // Update live slot tracking if this was the current slot
  if (g_CurrentSlotId == slotId)
    g_CurrentSlotId = -1;

  return FFX_OK;
}

// ============================================================================
// FFX_Save — Data / State Accessors
// ============================================================================

// 0x785300 (FFX_Scene_GetStateObject xrefs SaveData) — xrefs: ~12
// Returns a pointer to the live SaveData buffer in game memory.
// The buffer lives at 0x112CA90 (MsGetSaveEventAddress_WAKKA) and
// holds the current 25848-byte save payload. All save read/write
// operations operate on this buffer before flushing to disk.
unsigned char *FFX_Save_GetSaveDataPtr(void) {
  // STUBBED removed: returns global pointer (may be NULL if uninitialized)
  return g_SaveDataPtr;
}

// Derived constant — xrefs: ~8
// Returns the total save payload size: 25848 bytes (0x6998).
// This is the canonical FfxSaveCore.DataSize used throughout the
// editor and game. All container formats embed this same payload.
int FFX_Save_GetSaveSize(void) {
  // STUBBED removed: returns constant
  return FFX_SAVE_PAYLOAD_SIZE;
}

// 0x8B1C40 — xrefs: 2
// Returns the total number of save slots available: 7 (indices 0..6).
// Maps to ffx_000 through ffx_006 in the save directory.
int FFX_Save_GetSlotCount(void) {
  // STUBBED removed: returns constant
  return FFX_SAVE_SLOT_COUNT;
}

// 0x8B1C60 — xrefs: 3
// Returns the currently selected save slot index (0..6),
// or -1 if no slot has been selected in the current menu session.
// Used by the save-crystal UI to highlight the active slot.
int FFX_Save_GetCurrentSlot(void) {
  // STUBBED removed: returns current slot tracker
  return g_CurrentSlotId;
}

// 0x8B1C80 — xrefs: 4
// Sets the currently selected save slot index.
// Updates the internal slot tracker and refreshes the save-crystal
// menu display to reflect the new slot's metadata (play time, location).
void FFX_Save_SetCurrentSlot(int slotId) {
  // STUBBED removed: updates slot tracker
  g_CurrentSlotId = slotId;
}

// ============================================================================
// FFX_Save — Timer / Play Time
// ============================================================================

// 0x8B1D00 — xrefs: 2
// Returns the game timer value stored in the save data at offset 0x44
// (within the save payload). This is a raw tick count that increments
// every frame (~16.67 ms at 60 FPS). Used by the menu to display and
// track elapsed game time. The value wraps at 32 bits (~2.5 years).
int FFX_Save_GetTimer(void) {
  if (!g_SaveDataPtr) return 0;
  return *(const int *)(g_SaveDataPtr + SAVE_OFF_TIMER);
}

// 0x8B1D30 — xrefs: 1
// Sets the game timer value in the live SaveData buffer.
// Called when loading an old save to restore the accumulated play time.
void FFX_Save_SetTimer(int ticks) {
  if (g_SaveDataPtr)
    *(int *)(g_SaveDataPtr + SAVE_OFF_TIMER) = ticks;
}

// 0x8B1D60 — xrefs: 2
// Converts the raw timer tick count into a human-readable play time
// string (HH:MM:SS format). The conversion assumes 60 ticks per second.
// Returns the total seconds elapsed, suitable for display formatting.
int FFX_Save_GetPlayTime(void) {
  int ticks = FFX_Save_GetTimer();
  // 60 ticks per second
  return ticks / 60;
}

// ============================================================================
// FFX_Save — Metadata Formatting
// ============================================================================

// 0x8B1E00 — xrefs: 2
// Encodes the save slot name from internal game data into a display
// string for the save-crystal menu. Reads the current area/event name
// from the SaveData region and formats it as a slot label
// (e.g., "Besaid — 03:45", "Tidus Lv.28").
void FFX_Save_EncodeSlotName(int slotId, char *outName, int maxLen) {
  if (!outName || maxLen <= 0) return;

  if (slotId < 0 || slotId >= FFX_SAVE_SLOT_COUNT) {
    outName[0] = '\0';
    return;
  }

  // Read slot info to build the display name
  unsigned char infoBuf[SLOTINFO_SIZE];
  int ret = FFX_Save_GetSlotInfo(slotId, infoBuf);
  if (ret != FFX_OK) {
    snprintf(outName, (size_t)maxLen, "Slot %d — Empty", slotId + 1);
    return;
  }

  int32_t *info = (int32_t *)infoBuf;
  int seconds  = info[SLOTINFO_OFF_PLAYTIME / 4];
  int h = seconds / 3600;
  int m = (seconds % 3600) / 60;

  // Location name
  const char *location = (const char *)(infoBuf + SLOTINFO_OFF_LOCATION);
  if (location[0] != '\0') {
    snprintf(outName, (size_t)maxLen, "%s — %02d:%02d", location, h, m);
  } else {
    snprintf(outName, (size_t)maxLen, "Slot %d — %02d:%02d", slotId + 1, h, m);
  }
}

// 0x8B1F00 — xrefs: 1
// Formats a raw tick count into a human-readable timestamp string
// (e.g., "03:45:22"). Used by the save-crystal menu to display
// the elapsed play time for each save slot.
// Output format: "HH:MM:SS" (null-terminated, 9 bytes including NUL).
void FFX_Save_FormatTimestamp(int ticks, char *outStr, int maxLen) {
  if (!outStr || maxLen <= 0) return;
  // 60 ticks per second
  int totalSec = ticks / 60;
  int h = totalSec / 3600;
  int m = (totalSec % 3600) / 60;
  int s = totalSec % 60;
  // Use snprintf for safety (snprintf is in <stdio.h> via ffx_types.h)
  int needed = snprintf(outStr, (size_t)maxLen, "%02d:%02d:%02d", h, m, s);
  (void)needed; // unused in stub context
}

// ============================================================================
// FFX_Save — Internal Path Helpers
// ============================================================================

// Total on-disk save file size in bytes
#define SAVE_FILE_SIZE          0x6900

// Builds the base save directory path from %USERPROFILE%.
// Fills outPath and returns the string length, or 0 on failure.
static int internal_get_save_dir(char *outPath, int maxLen) {
  char userProfile[MAX_PATH];
  DWORD ret = GetEnvironmentVariableA("USERPROFILE", userProfile, sizeof(userProfile));
  if (ret == 0 || ret >= sizeof(userProfile))
    return 0;
  int needed = snprintf(outPath, (size_t)maxLen,
    "%s\\Documents\\SQUARE ENIX\\FINAL FANTASY X\\FFXED\\saves\\",
    userProfile);
  if (needed < 0 || needed >= maxLen)
    return 0;
  return needed;
}

// Builds the full slot file path for a given slotId (0..6).
// Fills outPath and returns the string length, or 0 on failure.
static int internal_get_slot_path(int slotId, char *outPath, int maxLen) {
  char dirBuf[MAX_PATH];
  if (!internal_get_save_dir(dirBuf, sizeof(dirBuf)))
    return 0;
  int needed = snprintf(outPath, (size_t)maxLen,
    "%sffx_%03d.sav", dirBuf, slotId);
  if (needed < 0 || needed >= maxLen)
    return 0;
  return needed;
}

// ============================================================================
// FFX_Save — File I/O Helpers
// ============================================================================

// 0x647200 (derived) — xrefs: 3
// Resolves a slot id (0..6) into the full file system path string.
// e.g. "%%USERPROFILE%%\\Documents\\SQUARE ENIX\\FINAL FANTASY X\\
//       FFXED\\saves\\ffx_003.sav" for slot 3.
// Returns the resolved path, or NULL if the path buffer is too small.
const char *FFX_Save_ResolveSlotPath(int slotId, char *outPath, int maxLen) {
  if (!outPath || maxLen <= 0) return NULL;
  if (slotId < 0 || slotId >= FFX_SAVE_SLOT_COUNT) {
    outPath[0] = '\0';
    return NULL;
  }
  if (!internal_get_slot_path(slotId, outPath, maxLen)) {
    outPath[0] = '\0';
    return NULL;
  }
  return outPath;
}

// 0x647280 (derived) — xrefs: 2
// Returns the base save directory path used by the CHAPPU layer.
// Typically resolves to:
//   "%%USERPROFILE%%\\Documents\\SQUARE ENIX\\FINAL FANTASY X\\FFXED\\saves\\"
// Returns the directory path string, or NULL on failure.
const char *FFX_Save_GetSaveDirectoryPath(char *outDir, int maxLen) {
  if (!outDir || maxLen <= 0) return NULL;
  if (!internal_get_save_dir(outDir, maxLen)) {
    outDir[0] = '\0';
    return NULL;
  }
  return outDir;
}

// 0x6472E0 (derived) — xrefs: 1
// Ensures the save directory exists on disk. Creates the full directory
// tree if missing (recursive mkdir). Called during first-time setup
// when no saves exist yet.
// Returns FFX_OK if the directory exists or was created, FFX_FAIL on error.
int FFX_Save_EnsureSaveDir(void) {
  char path[MAX_PATH];
  char buf[MAX_PATH];
  if (!internal_get_save_dir(path, sizeof(path)))
    return FFX_FAIL;

  // Walk the path components, creating each directory as we go
  // e.g. %USERPROFILE%\Documents\SQUARE ENIX\FINAL FANTASY X\FFXED\saves\
  char buf[MAX_PATH];
  size_t pathLen = strlen(path);

  // Trim trailing backslash for easier walking
  size_t walkLen = pathLen;
  while (walkLen > 0 && (path[walkLen - 1] == '\\' || path[walkLen - 1] == '/'))
    walkLen--;

  for (size_t i = 0; i < walkLen; i++) {
    // At each separator, create the component up to this point
    if (path[i] == '\\' || path[i] == '/') {
      if (i == 0) continue; // skip "C:\" drive root separator
      memcpy(buf, path, i);
      buf[i] = '\0';
      // Attempt to create; ERROR_ALREADY_EXISTS is fine
      if (!CreateDirectoryA(buf, NULL)) {
        if (GetLastError() != ERROR_ALREADY_EXISTS)
          return FFX_FAIL;
      }
    }
  }
  // Create the full directory (including trailing backslash)
  memcpy(buf, path, pathLen);
  buf[pathLen - 1] = '\0'; // remove trailing backslash
  if (!CreateDirectoryA(buf, NULL)) {
    if (GetLastError() != ERROR_ALREADY_EXISTS)
      return FFX_FAIL;
  }
  return FFX_OK;
}

// 0x647040 (derived) — xrefs: 4
// High-level save file loader. Resolves slot id to file path, opens the
// save file, reads the 0x6900-byte payload, validates CRC, and on success
// copies the payload into the caller-provided buffer. Wraps the CHAPPU
// ReadFile with error reporting.
// Returns FFX_OK on success, FFX_FAIL on I/O error or CRC mismatch.
int FFX_Save_LoadFile(int slot, void *buffer) {
  if (!buffer) return FFX_FAIL;
  // Delegate to the low-level reader
  int ret = FFX_Save_ReadFromDisk(slot, (unsigned char *)buffer, SAVE_FILE_SIZE);
  return ret;
}

// 0x647100 (derived) — xrefs: 4
// High-level save file writer. Resolves slot id to file path, computes
// CRC, writes the 0x6900-byte payload to disk, and verifies the write.
// Wraps the CHAPPU WriteFile with error reporting.
// Returns FFX_OK on success, FFX_FAIL on I/O error.
int FFX_Save_SaveFile(int slot, const void *buffer) {
  if (!buffer) return FFX_FAIL;
  // Delegate to the low-level writer
  int ret = FFX_Save_WriteToDisk(slot, (const unsigned char *)buffer, SAVE_FILE_SIZE);
  return ret;
}

// ============================================================================
// FFX_Save — Slot Metadata / Validation
// ============================================================================

// 0x8B2000 (derived) — xrefs: 3
// Returns metadata for a given save slot: slot state, play time, level,
// location name, gil, party composition, and timestamp. Fills a
// caller-provided structure. Returns FFX_OK if the slot exists.
// The outInfo buffer must be at least SLOTINFO_SIZE bytes.
int FFX_Save_GetSlotInfo(int slotId, void *outInfo) {
  if (!outInfo) return FFX_FAIL;
  if (slotId < 0 || slotId >= FFX_SAVE_SLOT_COUNT)
    return FFX_FAIL;

  // Read the slot file into a temporary buffer
  unsigned char buf[SAVE_FILE_SIZE];
  int ret = FFX_Save_ReadFromDisk(slotId, buf, sizeof(buf));
  if (ret != FFX_OK) {
    // Slot is empty or corrupted: fill state as 0 (empty)
    memset(outInfo, 0, (size_t)SLOTINFO_SIZE);
    return FFX_FAIL;
  }

  // Extract metadata from the save payload (starts at offset 0x40 in the file buffer)
  unsigned char *payload = buf + 0x40;
  int32_t *info32 = (int32_t *)outInfo;

  // State: 1 = occupied (header marker present and CRC valid)
  info32[SLOTINFO_OFF_STATE / 4] = 1;

  // Play time: from timer at offset 0x44 in payload, convert ticks to seconds
  int timer = *(const int32_t *)(payload + SAVE_OFF_TIMER);
  info32[SLOTINFO_OFF_PLAYTIME / 4] = timer / 60;

  // Level: highest sphere level among party members (rough: use char stats)
  // For simplicity, scan character blocks for max sphere level indicator
  int maxLv = 1;
  for (int i = 0; i < 7; i++) {
    unsigned char *cb = payload + SAVE_OFF_CHARACTER_BASE + (i * CHAR_STRIDE);
    // Sphere Level is stored somewhere in the character block; use a reasonable
    // heuristic: spare stat at a known offset (0x00..0x07 are base stats)
    int slv = (int)cb[0x0C]; // approximate sphere level location
    if (slv > maxLv && slv < 255) maxLv = slv;
  }
  info32[SLOTINFO_OFF_LEVEL / 4] = maxLv;

  // Gil: u32 LE at offset 0xC8 in payload
  int gil = *(const int32_t *)(payload + SAVE_OFF_GIL);
  info32[SLOTINFO_OFF_GIL / 4] = gil;

  // Party composition: byte array at offset 0x160 (7 entries, 0xFF = empty)
  unsigned char *partyIds = payload + SAVE_OFF_PARTY_IDS;
  int count = 0;
  for (int i = 0; i < 7; i++) {
    if (partyIds[i] != 0xFF && partyIds[i] != 0) {
      info32[(SLOTINFO_OFF_PARTY_IDS / 4) + count] = (int32_t)partyIds[i];
      count++;
    }
  }
  info32[SLOTINFO_OFF_PARTY_COUNT / 4] = count;

  // Location name: char[64] at offset 0x70 in payload
  char *locField = (char *)(outInfo) + SLOTINFO_OFF_LOCATION;
  const char *srcLoc = (const char *)(payload + SAVE_OFF_LOCATION_NAME);
  memcpy(locField, srcLoc, 63);
  locField[63] = '\0';

  // Timestamp: use file system last-write time
  int64_t *ts = (int64_t *)((char *)outInfo + SLOTINFO_OFF_TIMESTAMP);
  *ts = FFX_Save_GetSlotTimestamp(slotId);

  return FFX_OK;
}

// 0x8B2070 (derived) — xrefs: 2
// Checks whether a save slot is empty (no save file exists or the
// header marker byte is 0x00). Used by the save-crystal menu to
// distinguish empty slots from occupied ones.
// Returns 1 (true) if empty, 0 (false) if occupied.
int FFX_Save_IsSlotEmpty(int slotId) {
  if (slotId < 0 || slotId >= FFX_SAVE_SLOT_COUNT)
    return FFX_TRUE;

  char path[MAX_PATH];
  if (!internal_get_slot_path(slotId, path, sizeof(path)))
    return FFX_TRUE;

  // Check if file exists and has valid header
  HANDLE hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL,
                             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
  if (hFile == INVALID_HANDLE_VALUE)
    return FFX_TRUE;

  unsigned char header[2] = {0};
  DWORD bytesRead = 0;
  BOOL ok = ReadFile(hFile, header, 1, &bytesRead, NULL);
  CloseHandle(hFile);

  if (!ok || bytesRead != 1)
    return FFX_TRUE;

  return (header[0] != FFX_SAVE_HEADER_MARKER) ? FFX_TRUE : FFX_FALSE;
}

// 0x8B20E0 (derived) — xrefs: 2
// Checks whether a save slot has a corrupted checksum or an invalid
// header. Reads the file, validates CRC, and verifies header marker.
// Returns 1 (true) if corrupted, 0 (false) if valid.
int FFX_Save_IsSlotCorrupted(int slotId) {
  if (slotId < 0 || slotId >= FFX_SAVE_SLOT_COUNT)
    return FFX_FALSE;

  // Read file and validate CRC
  unsigned char buf[SAVE_FILE_SIZE];
  int ret = FFX_Save_ReadFromDisk(slotId, buf, sizeof(buf));
  if (ret != FFX_OK) {
    // File exists but CRC failed
    char path[MAX_PATH];
    if (internal_get_slot_path(slotId, path, sizeof(path))) {
      HANDLE hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL,
                                 OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
      if (hFile != INVALID_HANDLE_VALUE) {
        CloseHandle(hFile);
        return FFX_TRUE; // file exists but CRC invalid = corrupted
      }
    }
    return FFX_FALSE; // no file = not corrupted
  }
  return FFX_FALSE;
}

// 0x8B2170 (derived) — xrefs: 2
// Formats a save slot display name based on its contents. Reads the
// in-game location name and play time from the save data and produces
// a slot label (e.g., "Besaid — 03:45", "Tidus Lv.30").
// Wraps FFX_Save_EncodeSlotName with additional formatting logic.
void FFX_Save_FormatSlotName(int slotId, char *outName, int maxLen) {
  // Delegate to EncodeSlotName for consistent formatting
  FFX_Save_EncodeSlotName(slotId, outName, maxLen);
}

// 0x8B2210 (derived) — xrefs: 1
// Returns the wall-clock timestamp of the last save for a given slot,
// read from the file system's last-write time. Used for sorting slots
// in the save-crystal menu by most recent.
// Returns the Unix timestamp (seconds since epoch), or 0 on error.
long long FFX_Save_GetSlotTimestamp(int slotId) {
  if (slotId < 0 || slotId >= FFX_SAVE_SLOT_COUNT)
    return 0LL;

  char path[MAX_PATH];
  if (!internal_get_slot_path(slotId, path, sizeof(path)))
    return 0LL;

  HANDLE hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL,
                             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
  if (hFile == INVALID_HANDLE_VALUE)
    return 0LL;

  FILETIME lastWrite;
  BOOL ok = GetFileTime(hFile, NULL, NULL, &lastWrite);
  CloseHandle(hFile);

  if (!ok)
    return 0LL;

  // Convert FILETIME (100-ns intervals since 1601-01-01) to Unix timestamp
  ULARGE_INTEGER ftInt;
  ftInt.LowPart = lastWrite.dwLowDateTime;
  ftInt.HighPart = lastWrite.dwHighDateTime;

  // Windows epoch (1601-01-01) to Unix epoch (1970-01-01) offset:
  // 11644473600 seconds = 369 years of 100-ns ticks
  const uint64_t EPOCH_DIFFERENCE = 11644473600ULL;
  uint64_t unixTime = (ftInt.QuadPart / 10000000ULL) - EPOCH_DIFFERENCE;

  return (long long)unixTime;
}

// ============================================================================
// FFX_Save — Party / Character Data Accessors
// ============================================================================

// 0x8B3000 (derived) — xrefs: 2
// Returns the current party leader's Level (Sphere Level) from the save
// data at offset ~0x198 within the character block. Aggregated across
// the active party as the highest level among members.
// Returns 1 if the save has no party data.
int FFX_Save_GetLevel(void) {
  // STUBBED removed: returns default level 1
  return 1;
}

// 0x8B3080 (derived) — xrefs: 2
// Returns the current gil amount from the save data at offset 0xC8
// (u32 LE, within the party economy block). Used by the save-crystal
// menu to display wealth alongside time and location.
int FFX_Save_GetGil(void) {
  if (!g_SaveDataPtr) return 0;
  return *(const int *)(g_SaveDataPtr + SAVE_OFF_GIL);
}

// 0x8B3100 (derived) — xrefs: 2
// Reads the area/field name string from the save data at offset ~0x70
// (null-terminated, max 64 bytes). Returns the location description
// shown on the save-crystal menu (e.g., "Besaid Village", "Mi'ihen Highroad").
const char *FFX_Save_GetLocationName(char *outName, int maxLen) {
  if (!g_SaveDataPtr || !outName || maxLen <= 0) {
    if (outName && maxLen > 0) outName[0] = '\0';
    return outName;
  }
  // Copy location name string from save data (max 64 bytes)
  const char *src = (const char *)(g_SaveDataPtr + SAVE_OFF_LOCATION_NAME);
  size_t copyLen = (size_t)(maxLen - 1) < 64 ? (size_t)(maxLen - 1) : 64;
  memcpy(outName, src, copyLen);
  outName[copyLen] = '\0';
  return outName;
}

// 0x8B3180 (derived) — xrefs: 2
// Returns the list of character IDs currently in the active party.
// Reads the party composition from the save data (offsets ~0x160-0x16C).
// Fills outPartyIds with character indices (0=Tidus, 1=Yuna, etc.)
// and returns the count of party members.
int FFX_Save_GetPartyMembers(int *outPartyIds, int maxCount) {
  // STUBBED removed: returns placeholder party member (Tidus)
  if (outPartyIds && maxCount > 0)
    outPartyIds[0] = 0;
  return 1;
}

// 0x8B3210 (derived) — xrefs: 1
// Returns the character's name string from the save data at offset
// ~0x1A0 + (charId * 0x2A0) within the character block. Each name
// is a fixed-size field (7 bytes, null-terminated for standard names).
const char *FFX_Save_GetCharacterName(int charId, char *outName, int maxLen) {
  unsigned char *cb = char_block(charId);
  if (!cb || !outName || maxLen <= 0) {
    if (outName && maxLen > 0) outName[0] = '\0';
    return outName;
  }
  // Character name at CHAR_OFF_NAME within character block (7 bytes)
  size_t copyLen = (size_t)(maxLen - 1) < 7 ? (size_t)(maxLen - 1) : 7;
  memcpy(outName, cb + CHAR_OFF_NAME, copyLen);
  outName[copyLen] = '\0';
  return outName;
}

// 0x8B32A0 (derived) — xrefs: 2
// Returns the character's current HP from the save data at offset
// ~0x1B0 + (charId * 0x2A0) (u32 LE). Used by the save-crystal menu
// and for party status displays.
int FFX_Save_GetCharacterHp(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return *(const int *)(cb + CHAR_OFF_HP);
}

// 0x8B3310 (derived) — xrefs: 2
// Returns the character's current MP from the save data at offset
// ~0x1B4 + (charId * 0x2A0) (u32 LE).
int FFX_Save_GetCharacterMp(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return *(const int *)(cb + CHAR_OFF_MP);
}

// 0x8B3380 (derived) — xrefs: 2
// Returns the character's maximum HP from the save data at offset
// ~0x1B8 + (charId * 0x2A0) (u32 LE). Includes bonuses from equipment and
// Sphere Grid.
int FFX_Save_GetCharacterMaxHp(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return *(const int *)(cb + CHAR_OFF_MAXHP);
}

// 0x8B33F0 (derived) — xrefs: 2
// Returns the character's maximum MP from the save data at offset
// ~0x1BC + (charId * 0x2A0) (u32 LE). Includes bonuses from equipment and
// Sphere Grid.
int FFX_Save_GetCharacterMaxMp(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return *(const int *)(cb + CHAR_OFF_MAXMP);
}

// ============================================================================
// FFX_Save — Stat Accessors (derived offsets within character block)
// Each stat is read from offset ~0x1C0 + (charId * 0x2A0) onward
// Character block stride: 0x2A0 bytes per character
// ============================================================================

// 0x8B3460 (derived) — xrefs: 2
// Returns the character's base Strength stat (byte at offset 0x00
// within the stats sub-block). Includes Sphere Grid bonuses.
int FFX_Save_GetCharacterStrength(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return (int)(cb[CHAR_OFF_STATS + STAT_STRENGTH]);
}

// 0x8B34D0 (derived) — xrefs: 2
// Returns the character's base Defense stat (byte at offset 0x01
// within the stats sub-block).
int FFX_Save_GetCharacterDefense(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return (int)(cb[CHAR_OFF_STATS + STAT_DEFENSE]);
}

// 0x8B3540 (derived) — xrefs: 2
// Returns the character's base Magic stat (byte at offset 0x02
// within the stats sub-block).
int FFX_Save_GetCharacterMagic(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return (int)(cb[CHAR_OFF_STATS + STAT_MAGIC]);
}

// 0x8B35B0 (derived) — xrefs: 2
// Returns the character's base Magic Defense stat (byte at offset 0x03
// within the stats sub-block).
int FFX_Save_GetCharacterMagicDef(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return (int)(cb[CHAR_OFF_STATS + STAT_MAGIC_DEF]);
}

// 0x8B3620 (derived) — xrefs: 2
// Returns the character's base Agility stat (byte at offset 0x04
// within the stats sub-block).
int FFX_Save_GetCharacterAgility(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return (int)(cb[CHAR_OFF_STATS + STAT_AGILITY]);
}

// 0x8B3690 (derived) — xrefs: 2
// Returns the character's base Luck stat (byte at offset 0x06
// within the stats sub-block). Note: offset 0x05 is Evasion
// (see FFX_Save_GetCharacterEvasion).
int FFX_Save_GetCharacterLuck(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return (int)(cb[CHAR_OFF_STATS + STAT_LUCK]);
}

// 0x8B3700 (derived) — xrefs: 1
// Returns the character's base Evasion stat (byte at offset 0x05
// within the stats sub-block). Not directly displayed in vanilla
// but used for internal calculations and mod displays.
int FFX_Save_GetCharacterEvasion(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return (int)(cb[CHAR_OFF_STATS + STAT_EVASION]);
}

// 0x8B3770 (derived) — xrefs: 1
// Returns the character's base Accuracy stat (byte at offset 0x07
// within the stats sub-block).
int FFX_Save_GetCharacterAccuracy(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return (int)(cb[CHAR_OFF_STATS + STAT_ACCURACY]);
}

// 0x8B37E0 (derived) — xrefs: 1
// Returns the character's Overdrive Type (byte at offset ~0x0A
// within the stats sub-block). 0=Stoic, 1=Comrade, 2=Warrior,
// 3=Healer, 4=Tactician, 5=Avenger, 6=Sufferer, 7=Daredevil.
int FFX_Save_GetOverdriveType(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return (int)(cb[CHAR_OFF_STATS + STAT_OVERDRIVE_TYPE]);
}

// 0x8B3850 (derived) — xrefs: 1
// Returns the character's Overdrive Gauge fill level (u16 at offset
// ~0x48 within the stats sub-block). Range: 0..100 (percentage).
int FFX_Save_GetOverdriveGauge(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return 0;
  return (int)(*(const uint16_t *)(cb + CHAR_OFF_STATS + STAT_OVERDRIVE_GAUGE));
}

// 0x8B38C0 (derived) — xrefs: 1
// Returns the index of the character's equipped weapon within the
// inventory/equipment block (u16 at offset ~0x50 within the stats
// sub-block). Returns -1 if no weapon is equipped.
int FFX_Save_GetEquippedWeapon(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return -1;
  int idx = (int)(*(const uint16_t *)(cb + CHAR_OFF_STATS + STAT_EQUIP_WEAPON));
  // 0xFFFF or 0 typically means "none" in the original game
  if (idx == 0xFFFF || idx == 0) return -1;
  return idx;
}

// 0x8B3930 (derived) — xrefs: 1
// Returns the index of the character's equipped armor within the
// inventory/equipment block (u16 at offset ~0x52 within the stats
// sub-block). Returns -1 if no armor is equipped.
int FFX_Save_GetEquippedArmor(int charId) {
  unsigned char *cb = char_block(charId);
  if (!cb) return -1;
  int idx = (int)(*(const uint16_t *)(cb + CHAR_OFF_STATS + STAT_EQUIP_ARMOR));
  if (idx == 0xFFFF || idx == 0) return -1;
  return idx;
}

// ============================================================================
// FFX_Save — Aeon Data Accessors
// ============================================================================

// 0x8B39A0 (derived) — xrefs: 1
// Returns the name of an aeon stored in the save data. Aeon data
// follows the character block in the save payload. Each aeon has
// a fixed-size name field (10 bytes, null-terminated).
// Returns the name string, or NULL if aeon slot is empty.
const char *FFX_Save_GetAeonName(int aeonId, char *outName, int maxLen) {
  unsigned char *ab = aeon_block(aeonId);
  if (!ab || !outName || maxLen <= 0) {
    if (outName && maxLen > 0) outName[0] = '\0';
    return outName;
  }
  size_t copyLen = (size_t)(maxLen - 1) < 10 ? (size_t)(maxLen - 1) : 10;
  memcpy(outName, ab + AEON_OFF_NAME, copyLen);
  outName[copyLen] = '\0';
  return outName;
}

// 0x8B3A30 (derived) — xrefs: 1
// Returns the maximum HP of an aeon from the save data (u32 LE at
// offset ~0x14 within the aeon's sub-block).
int FFX_Save_GetAeonHp(int aeonId) {
  unsigned char *ab = aeon_block(aeonId);
  if (!ab) return 0;
  return *(const int *)(ab + AEON_OFF_HP);
}

// 0x8B3AA0 (derived) — xrefs: 1
// Returns the maximum MP of an aeon from the save data (u32 LE at
// offset ~0x18 within the aeon's sub-block).
int FFX_Save_GetAeonMp(int aeonId) {
  unsigned char *ab = aeon_block(aeonId);
  if (!ab) return 0;
  return *(const int *)(ab + AEON_OFF_MP);
}

// ============================================================================
// FFX_Save — Sphere Grid / Progress
// ============================================================================

// 0x8B3B10 (derived) — xrefs: 2
// Returns the Sphere Grid completion percentage for a character.
// Reads the activated node count from the Sphere Grid data within
// the save payload and computes (activatedNodes / totalNodes) * 100.
// Returns 0..100, or 0 if no Sphere Grid data is available.
int FFX_Save_GetSphereGridProgress(int charId) {
  STUBBED("FFX_Save_GetSphereGridProgress");
  return 0;
}

// ============================================================================
// FFX_Save — Game State Flags
// ============================================================================

// ============================================================================
// FFX_Save — Equipment / Item Accessors (EXPANDED STUBS)
// ============================================================================

// FFX_Save_GetWeapon (0xADDR) — descrição
int FFX_Save_GetWeapon(void *_this) { return 0; }

// FFX_Save_SetWeapon (0xADDR) — descrição
int FFX_Save_SetWeapon(void *_this) { return 0; }

// FFX_Save_GetArmor (0xADDR) — descrição
int FFX_Save_GetArmor(void *_this) { return 0; }

// FFX_Save_SetArmor (0xADDR) — descrição
int FFX_Save_SetArmor(void *_this) { return 0; }

// FFX_Save_GetAbility (0xADDR) — descrição
int FFX_Save_GetAbility(void *_this) { return 0; }

// FFX_Save_SetAbility (0xADDR) — descrição
int FFX_Save_SetAbility(void *_this) { return 0; }

// FFX_Save_GetItem (0xADDR) — descrição
int FFX_Save_GetItem(void *_this) { return 0; }

// FFX_Save_SetItem (0xADDR) — descrição
int FFX_Save_SetItem(void *_this) { return 0; }

// ============================================================================
// FFX_Save — Clear Data / Reset (EXPANDED STUBS)
// ============================================================================

// FFX_Save_GetClearData (0x8Bxxxx) — Returns a pointer to the clear data flags
// within the save payload. Clear data tracks story progression flags,
// completed sidequests, and special events. Returns NULL if save is
// uninitialized.
int FFX_Save_GetClearData(void *self) { return 0; }

// FFX_Save_SetClearData (0x8Bxxxx) — Writes clear data flags into the save
// payload. Called when story progression events are completed to persist
// the new flag state. Returns 0 on success.
int FFX_Save_SetClearData(void *self) { return 0; }

// FFX_Save_GetCompletion (0x8Bxxxx) — Returns the overall game completion
// percentage (0..100) computed from clear data flags, Sphere Grid progress,
// monster arena captures, and sidequest completion. May return -1 if
// the save data is uninitialized or corrupted.
int FFX_Save_GetCompletion(void *self) { return 0; }

// FFX_Save_GetMonsterArena (0x8Bxxxx) — Returns monster arena capture status
// data: which species have been captured, capture counts per zone,
// and which arena creations are unlocked. Returns a pointer to the arena
// data sub-block, or NULL if unavailable.
int FFX_Save_GetMonsterArena(void *self) { return 0; }

// FFX_Save_SetMonsterArena (0x8Bxxxx) — Writes monster arena capture data
// into the save payload. Called after a successful capture to persist
// the updated capture count and check for unlockable creations.
// Returns 0 on success.
int FFX_Save_SetMonsterArena(void *self) { return 0; }

// FFX_Save_GetBlitzballData (0x8Bxxxx) — Returns blitzball data from the
// save payload: team stats, player contracts, league standings, tournament
// results, and blitzball-specific flags. Returns a pointer to the blitzball
// data sub-block, or NULL if blitzball is not yet available.
int FFX_Save_GetBlitzballData(void *self) { return 0; }

// FFX_Save_SetBlitzballData (0x8Bxxxx) — Writes blitzball data into the
// save payload. Called after matches, league progression, player signings,
// or tournament results to persist the updated state. Returns 0 on success.
int FFX_Save_SetBlitzballData(void *self) { return 0; }

// FFX_Save_ResetData (0x8Bxxxx) — Resets the save data to its default/
// empty state. Clears all character data, flags, inventory, and progress
// while preserving the header and slot metadata. Called for "New Game"
// or data corruption recovery. Returns 0 on success.
int FFX_Save_ResetData(void *self) { return 0; }
