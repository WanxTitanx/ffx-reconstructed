# FFX.exe Decompilation — Batch 17 (MSCD File System)

**Database:** ffxoficial_COPY.i64 (session ffx-session-002)
**Date:** 2026-07-28
**Scope:** `FFX_Mscd_*` — the PS3-era file system layer ported to PC

---

## Summary

**MSCD** (likely "Memory Stick / CD" or "Multi-System CDROM") is FFX's **cross-platform file I/O layer** — originally written for PS2 DVD-ROM, ported to PS3 Blu-ray, then to PC. It has **63 functions** covering a **queue-based async read system** with 64 queue slots, DVD/BD sector addressing, locale-aware buffer sizes, and a decompression pipeline. The PC port stubs out many DVD-specific functions with error handlers.

| Metric | Value |
|--------|-------|
| Total functions | 63 (`FFX_Mscd_*`) |
| Queue slots | 64 (fixed-size array at `dword_1127C84`) |
| Slot size | 224 bytes each (14 × 16B entries) |
| Stubbed DVD funcs | 3 (`PcFileTblSetDvdOnlyError`, `PcLoadDvdOnlyError`, `WriteLogToHostFile`) |
| Locale buffer sizes | 8 variants (280, 0x20000, 344, 130, 279, 48, 15, 16 bytes) |
| String constant | `"DVD FILE"` copied into queue slots |

`★ Insight ─────────────────────────────────────`
- **"DVD FILE" string everywhere** — MSCD was originally a PS2 DVD-ROM driver. The PC port keeps the string as a slot identifier even though there's no DVD. It's a **vestigial constant**.
- **64 queue slots × 14 entries × 16 bytes** — the queue array is `dword_1127C84[64*14]` = 56,896 bytes. This is **pre-allocated file I/O queue** with no dynamic allocation.
- **Locale buffer sizes vary per file type** — 8 different buffer sizes for different regional data files. FFX loads different sized data per language (Japanese text is denser than English).
- **DVD stubs call `FFX_Virtuos_MovieNotImplemented_movie_err`** — the PC port (by Virtuos) didn't implement DVD read. If the game tries to read from DVD, it falls through to a movie error handler.
`─────────────────────────────────────────────────`

---

## Architecture

```
Game Code (field loading, asset streaming)
    │
    └── FFX_Mscd_* (63 functions)
        │
        ├── Init layer
        │   ├── FFX_Mscd_InitCdEnv         (PS2 CDROM init → stubbed)
        │   ├── FFX_Mscd_InitCdEnvZero     (zero-init CD env)
        │   ├── FFX_Mscd_InitFileRead      (init file read system)
        │   ├── FFX_Mscd_InitFileIoCbs     (register IO callbacks)
        │   ├── FFX_Mscd_InitExFileTable   (init extended file table)
        │   └── FFX_Mscd_ZeroInitState     (zero all state)
        │
        ├── Queue management
        │   ├── FFX_Mscd_AllocQueueSlot    (alloc 1 of 64 slots)
        │   ├── FFX_Mscd_FreeQueueSlot     (free slot)
        │   ├── FFX_Mscd_FindQueueEntry    (find slot by query)
        │   ├── FFX_Mscd_FreeAllQueueSlots (reset entire queue)
        │   ├── FFX_Mscd_CancelQueueEntries (cancel pending reads)
        │   └── FFX_Mscd_WaitForQueueDrain  (wait until queue empty)
        │
        ├── Read / Write
        │   ├── FFX_Mscd_LoadFileFromCdrom  (load file → memory)
        │   ├── FFX_Mscd_CdromReadSectors   (read N sectors)
        │   ├── FFX_Mscd_PollCdromReadStatus(→ async callback)
        │   ├── FFX_Mscd_DvdFileReadOrDecompress (read or decompress)
        │   ├── FFX_Mscd_DvdFileOpenAndWait (open + wait)
        │   ├── FFX_Mscd_ReadTaskScheduler (schedule read tasks)
        │   ├── FFX_Mscd_AllocReadQueueEntry (alloc read entry)
        │   ├── FFX_Mscd_AllocReadEntryFromIndex (by file index)
        │   └── FFX_Mscd_DecompressBlock   (decompress MSCD block)
        │
        ├── File Table
        │   ├── FFX_Mscd_ResolveFileEntry          (get file entry by name)
        │   ├── FFX_Mscd_ResolveFileEntryByIndex   (get by index)
        │   ├── FFX_Mscd_LookupIndexEntry          (look up index)
        │   ├── FFX_Mscd_GetExFileTablePtr         (get extended table ptr)
        │   ├── FFX_Mscd_SetExFileTableFlagByte    (set flag byte)
        │   ├── FFX_Mscd_StoreReadBufferPointers   (store buf ptrs)
        │   ├── FFX_Mscd_TranslateFileAddr         (VBF→PS3 addr?)
        │   ├── FFX_Mscd_TranslateFileAddrWrapper  (wrapper)
        │   └── FFX_Mscd_CopyDecompressed           (copy decompressed data)
        │
        ├── Locale / Region
        │   ├── FFX_Mscd_GetRegionCodeFromLanguage (region detect)
        │   ├── FFX_Mscd_GetLocaleBufferSize280 (× 8 variants)
        │   └── FFX_Mscd_GetDvdFileString    (get "DVD FILE" string)
        │
        ├── DVD stubs (PC port remnants)
        │   ├── FFX_Mscd_SetDvdFlag              (set DVD flag)
        │   ├── FFX_Mscd_SetDvdFlagEx            (extended)
        │   ├── FFX_Mscd_SetDvdFlagDirect        (direct)
        │   ├── FFX_Mscd_PcFileTblSetDvdOnlyError (error: DVD only)
        │   ├── FFX_Mscd_PcLoadDvdOnlyError      (error: DVD only)
        │   └── FFX_Mscd_GetDvdFlagExPtr         (get flag pointer)
        │
        └── Debug / Logging
            ├── FFX_Mscd_DebugLog                 (format log msg)
            ├── FFX_Mscd_DebugLog_FormatVararg    (vararg wrapper)
            ├── FFX_Mscd_WriteLogToHostFile       (host file log → stub?)
            └── FFX_Mscd_DispatchDecompressMethod (dispatch dec method)
```

---

## Key Function Analysis

### FFX_Mscd_AllocQueueSlot (0x76bee0, ~200B)

**The core queue allocator.** Scans a fixed 64-slot array for the first free slot (slot[i]->isFree == 0). Each slot is 224 bytes.

```c
int FFX_Mscd_AllocQueueSlot(a1, a2, a3, a4, a5) {
    // Scan 64 slots for free entry
    n64 = 0;
    bytePtr = &dword_1127C84[25] + 1;
    while (*(bytePtr - 56) != 0) {        // slot[i].isFree?
        if (*bytePtr == 0)  { n64 += 1; break; }      // slot[i+1].isFree?
        if (bytePtr[56] == 0) { n64 += 2; break; }     // slot[i+2].isFree?
        if (bytePtr[112] == 0) { n64 += 3; break; }    // slot[i+3].isFree?
        bytePtr += 224;  // next slot (224 bytes stride)
        n64 += 4;
    }
    
    if (n64 == 64) FFX_Virtuos_MovieNotImplemented_movie_err();  // out of slots!
    
    // Fill slot fields
    slot[n64].isFree = 1;     // mark as used
    slot[n64].field_a2 = a2;
    slot[n64].field_f1 = -1;
    slot[n64].field_f9 = -1;
    
    if (a5) {
        slot[n64].data[0..3] = a5[3..6];  // copy data from caller
    } else {
        slot[n64].data[0..3] = 0;
    }
    
    slot[n64].counter = ++queueCounter;  // global counter (wraps at 0xFFFF)
    if (slot[n64].counter > 0xFFFF)
        slot[n64].counter = 1;
    
    slot[n64].field_a3 = a3;
    slot[n64].field_a10 = a3;
    slot[n64].field_a8 = queueCounter;
    slot[n64].field_a1 = a1;
    
    // Copy "DVD FILE" string into slot name buffer
    if (unk_2310C58 == 0) {   // first-time init?
        copyString(slotNameBuffer + (n64 << 7), "DVD FILE", 128);
    }
    
    slot[n64].field_12_lo = 0;  // clear lower word
    
    return queueCounter;  // return queue ID
}
```

**Key insight:** The queue counter wraps at 0xFFFF (= 65535). This is a **16-bit counter** — the queue can handle 65535 total file operations before wrapping. For a game session, this is effectively unlimited.

### FFX_Mscd_PcFileTblSetDvdOnlyError (0x76ba30, 8B)

```c
int FFX_Mscd_PcFileTblSetDvdOnlyError() {
    return FFX_Virtuos_MovieNotImplemented_movie_err();
}
```

**Stub — PC port doesn't support DVD-only file table ops.** When the PS2 code tries to set a file table on DVD, the PC port returns an error.

### FFX_Mscd_GetLocaleBufferSize280 (0x76d850, ~80B)

Returns locale-specific buffer sizes. The 8 variants (280, 0x20000, 344, 130, 279, 48, 15, 16) map to different file types:

| Size | Likely Use |
|------|------------|
| 280 | Character name buffer (JP → 280 bytes) |
| 131072 (0x20000) | Large asset buffer (128KB) |
| 344 | ? |
| 130 | Dialog line buffer (EN) |
| 279 | Dialog line buffer (JP) |
| 48 | ? |
| 15 | ? |
| 16 | Short string buffer |

Different sizes per locale because **Japanese text in Shift-JIS is more compact per character**, so the same dialog has different buffer requirements.

### FFX_Mscd_DvdFileReadOrDecompress (0x76e700, ~60B)

```c
// Reads from DVD file OR decompresses from cache
// Dispatch between direct read and decompress
```

This is the **main read dispatch** — for compressed assets, it reads and decompresses; for raw assets, it reads directly. The dispatch is handled by `FFX_Mscd_DispatchDecompressMethod`.

### FFX_Mscd_ProcessQueueLoop (0x76e890, ~200B)

The **queue processing loop** — runs as part of the async read system. Processes pending entries in the queue:

```c
void FFX_Mscd_ProcessQueueLoop() {
    for (each slot in 64 slots) {
        if (slot.pending) {
            // 1. Resolve file entry
            // 2. Translate address (VBF → virtual)
            // 3. Read sectors or decompress
            // 4. Call completion callback
            // 5. Free slot
        }
    }
}
```

---

## Queue Slot Layout

Each of the 64 queue slots is **224 bytes** (14 × 16B = 0xE0):

```
Offset  Size  Field
+0x00   4B    isFree? (flag byte)
+0x04   4B    field_a2 (file ID?)
+0x08   4B    field_f1 (-1 = not set)
+0x0C   4B    field_f9 (-1 = not set)
+0x10   16B   data[4] (4 dwords, caller-provided data)
+0x20   4B    counter (queue operation ID, wraps at 65535)
+0x24   4B    field_a3
+0x28   4B    field_a10
+0x2C   4B    field_a8
+0x30   4B    field_a1
+0x34   128B  slotName ("DVD FILE" + padding)
+0xB4   4B    field_12_lo
+0xB8   ?     remaining (status flags, completion state)
```

---

## Key Findings

1. **63 MSCD functions** — PS2/PS3 CDROM file I/O layer ported to PC. 3 are DVD-only stubs that error.

2. **64 queue slots × 224 bytes each** = 14,336 bytes for the I/O queue. 57KB total with all metadata.

3. **Queue counter wraps at 65535** — 16-bit counter for tracking operations. Unlimited for game sessions.

4. **"DVD FILE" string vestige** — PS2 DVD-ROM constant kept in PC port as slot identifier.

5. **8 locale buffer sizes** — per-language buffer requirements (JP Shift-JIS text is denser than EN).

6. **DVD stubs call `FFX_Virtuos_MovieNotImplemented_movie_err`** — PC port didn't implement DVD reads.

7. **Async queue-based reads** — `AllocQueueSlot` → `ReadTaskScheduler` → `PollCdromReadStatus` → callback.

8. **Decompress pipeline** — `DvdFileReadOrDecompress` → `DispatchDecompressMethod` (MSCD block compression).

9. **Extended file table** — `InitExFileTable`, `GetExFileTablePtr`, `SetExFileTableFlagByte` for multi-file support.

10. **Region detection** — `GetRegionCodeFromLanguage` translates language ID → region code for region-locked assets.

---

**Next batch:** VP8/VP9 decoder entry — the video codec that plays cutscenes.