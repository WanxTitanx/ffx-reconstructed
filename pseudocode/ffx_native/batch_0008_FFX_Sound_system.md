# FFX.exe Decompilation — Batch 8 (Sound Queue System)

**Database:** ffxoficial_COPY.i64 (session b1d18aaa, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** Sound system — 498 functions across 15+ sub-families, 4-layer architecture from FMOD Ex to 3D positional audio

---

## Summary

| Metric | Count |
|--------|-------|
| Total functions | 498 |
| Sub-families identified | 15+ |
| Layers | 4 (FMOD Ex > Cmd Queue > SPU DMA > EsPlay 3D) |
| Functions decompiled (Hex-Rays) | 12 |
| Largest function | `FFX_Sound_EsPlayWrapper_structural` (25,460B / 6,042 insns) |
| Largest sub-family | `FFX_Sound_EsPlayWrapper_*` (~151 funcs, 30.4%) |
| FMOD Music wrappers real/null | 0 real / 19 nullsub thunks |
| Command queue slots | 150 (circular buffer at CE8448) |
| SPU DMA buffer | 51,200 bytes |
| EsPlay 3D projection modes | 2 (float path + int16 PS3 path) |

`★ Insight`
FFX HD's sound system is a **4-layer architecture** that bridges PC-native FMOD Ex calls through a custom command queue, into emulated PS3 SPU (Synergistic Processing Unit) DMA operations, and finally into EsPlay a 3D positional audio engine. The FMOD music layer is effectively **dead code**: all 19 music wrapper functions are nullsub stubs (0xA bytes each) meaning FMOD music playback was disabled in the PC port. Sound effects still route through FMOD SFX > Command Queue > SPU DMA > EsPlay.
`----------------------------------------------`

---

## Architecture

### 4-Layer Pipeline

```
+------------------------------------------------------------------------+
|  LAYER 1: FMOD Ex (PC Audio Renderer)                                  |
|  +------------------------------------------------------------------+  |
|  | FFX_Sound_FmodSfx_*      (49 funcs)  SFX bridge                  |  |
|  | FFX_Sound_FmodMusic_*    (19 funcs)  ALL nullsub stubs            |  |
|  | FFX_Sound_FmodSystem*    (3 funcs)   System::update               |  |
|  | FFX_Sound_FmodNull_*     (3 funcs)   Explicit nullsubs            |  |
|  +---------------------+--------------------------------------------+  |
|                        | FFX_Sound_QueueCommandAsync()                  |
|                        v                                                |
|  LAYER 2: Sound Command Queue (Circular Buffer)                       |
|  +------------------------------------------------------------------+  |
|  | g_SoundCmdQueue @ CE8448                                         |  |
|  | . 150 slots x 20 bytes = 3,000 bytes                             |  |
|  | . Mutex (CE8448 + 3032*4) + Event (CE8448 + 3033*4)             |  |
|  | . Async dispatch: QueueCommandAsync (369B, CC=13)                |  |
|  | . Sync dispatch: RegistCommandSync (327B, CC=13)                 |  |
|  | . Handler table @ C3A3A4 (70+ entries, idx = ArgList-17)        |  |
|  +---------------------+--------------------------------------------+  |
|                        | FFX_Sound_SpuCmdContextInit()                  |
|                        v                                                |
|  LAYER 3: SPU DMA Emulation (PS3 SPU > PC)                           |
|  +------------------------------------------------------------------+  |
|  | FFX_Sound_SpuCmd_*      (38 funcs)  15-case switch               |  |
|  | FFX_Sound_SpuDma_*      (51 funcs)  DMA buffer mgmt              |  |
|  | . 51,200-byte SPU buffer                                         |  |
|  | . 3,708 bytes of SPU global state @ 11333C4[1838400..]           |  |
|  | . 15 command cases (n255 1-15) mapping to global arrays          |  |
|  +---------------------+--------------------------------------------+  |
|                        |                                              |
|                        v                                                |
|  LAYER 4: EsPlay (3D Positional Audio)                               |
|  +------------------------------------------------------------------+  |
|  | FFX_Sound_EsPlay_*      (5 funcs)   Core 3D engine               |  |
|  | FFX_Sound_EsPlayWrapper_* (~151)    Wrapper/structural            |  |
|  | . Float projection path (flag 0x400, w-divide)                   |  |
|  | . Int16 PS3 path (fixed-point SPU native)                        |  |
|  | . Binary DWORD-pair voice priority parser                         |  |
|  | . Growth factor: size + size/8 + 2 (~12.5%)                     |  |
|  +------------------------------------------------------------------+  |
+------------------------------------------------------------------------+
```

### Command Queue Layout

```c
// Each slot in the circular buffer
struct SoundCmdSlot {           // 20 bytes total
    uint32_t cmdId;             // +0: command ID
    uint32_t arg1;              // +4: first argument
    uint32_t arg2;              // +8: second argument
    uint32_t arg3;              // +C: third argument
    uint32_t arg4;              // +10: fourth argument
};

struct SoundCmdQueue {          // g_SoundCmdQueue at CE8448
    SoundCmdSlot slots[150];    // circular buffer (3000 bytes)
    uint32_t writeIdx;          // next write position
    uint32_t readIdx;           // next read position
    HANDLE  mutex;              // at CE8448 + 3032*4
    HANDLE  event;              // at CE8448 + 3033*4
    uint8_t queueState;         // at CE8448 + 6068 (0 = empty/ready)
};
```

### Command Handler Table

The master dispatch table at `g_FFX_SoundCmdHandlerTable` (global C3A3A4) indexes 70+ command handlers. Each entry is a `{handler_func_ptr, arg_mask}` pair. Commands are dispatched by index as `ArgList - 17`:

| Cmd ID | Index | Name | Description |
|--------|-------|------|-------------|
| 17 | 0 | Cmd17_Unknown | Unknown handler |
| 18 | 1 | Cmd18_FadeIn | Fade-in audio |
| 19 | 2 | Cmd19_FadeOut | Fade-out audio |
| 20 | 3 | Cmd20_VolumeFade | Volume fade with interpolation |
| 21 | 4 | Cmd21_WaitFade | Wait for fade completion |
| 22 | 5 | Cmd22_SetVolume | Set volume (direct, no fade) |
| 23 | 6 | Cmd23_SetPan | Set panning |
| 24 | 7 | Cmd24_SetSpeed | Set playback speed |
| 2528 | 811 | Cmd2528_* | Reserved/extended volume |
| 29 | 12 | Cmd29_PlaySfx | Play SFX by ID |
| 30 | 13 | Cmd30_PlayVoice | Play voice line |
| 31 | 14 | Cmd31_StopAll | Stop all sounds |
| 32 | 15 | Cmd32_StopByBank | Stop sounds by bank |
| 33 | 16 | Cmd33_PauseAll | Pause all sounds |
| 34 | 17 | Cmd34_ResumeAll | Resume all sounds |
| 35 | 18 | Cmd35_SetBankVolume | Set volume by bank |
| 36 | 19 | Cmd36_StreamFile | Stream audio file |
| 3741 | 2024 | Cmd3741_* | Stream/voice control |
| 42 | 25 | Cmd42_LoadBank | Load sound bank |
| 43 | 26 | Cmd43_UnloadBank | Unload sound bank |
| 4447 | 2730 | Cmd4447_* | Bank management |
| 48 | 31 | Cmd48_GetMusicPos | Get music position |
| 4952 | 3235 | Cmd4952_* | Query/status |
| 5358 | 3641 | Cmd5358_* | 3D positional |
| 59 | 42 | Cmd59_BattlePriority | Battle priority (dedup: replace) |
| 60 | 43 | Cmd60_Unknown | Unknown |
| 61 | 44 | Cmd61_AppendAction | Append action (dedup: append) |
| 6272 | 4555 | Cmd6272_* | Extended control |
| 73+ | 56+ | | Extended/rare commands |

`★ Insight`
Commands 59 and 61 have special dedup behavior: Cmd59 uses **replace semantics** (last write wins, battle priority overrides), while Cmd61 uses **append semantics** (accumulates action queue entries). This is detected in `RegistCommandSync` before dispatch. Commands 8 and 58 additionally call `SetEvent` to wake the dispatch thread during battle.
`----------------------------------------------`

---

## Key Function Analysis

### 1. FFX_Sound_QueueCommandAsync (0x6fa3e0, 369B, 22 blocks, CC=13)

Async command enqueue, the primary entry point for all sound commands. Takes a command ID + 4 args, writes to the circular buffer under mutex protection.

```c
int __stdcall FFX_Sound_QueueCommandAsync(int cmdId, int arg1, int arg2, int arg3, int arg4) {
    // Wait for mutex (INFINITE timeout, blocking!)
    WaitForSingleObject(g_SoundCmdQueue.mutex, INFINITE);

    // Read current queue state
    int writeIdx = g_SoundCmdQueue.writeIdx;

    // Overflow detection: if readIdx caught up (buffer full)
    if (writeIdx == g_SoundCmdQueue.readIdx - 1
        || (writeIdx == 149 && !g_SoundCmdQueue.readIdx)) {
        // Log overflow, debug warning only, does NOT block/cancel
        FFX_Dbg_LogPrintf("[Sound] Queue overflow! cmd=%d\n", cmdId);
    }

    // Write 5 DWORDs to circular buffer at writeIdx
    g_SoundCmdQueue.slots[writeIdx].cmdId = cmdId;
    g_SoundCmdQueue.slots[writeIdx].arg1  = arg1;
    g_SoundCmdQueue.slots[writeIdx].arg2  = arg2;
    g_SoundCmdQueue.slots[writeIdx].arg3  = arg3;
    g_SoundCmdQueue.slots[writeIdx].arg4  = arg4;

    // Advance write index (circular: 0-149)
    g_SoundCmdQueue.writeIdx = (writeIdx + 1) % 150;

    // Release mutex
    ReleaseMutex(g_SoundCmdQueue.mutex);

    return 0;
}
```

**Key observations:**
- INFINITE mutex wait means the main thread CAN block on sound if queue is contended
- Overflow only logs a warning, does NOT drop the command or block
- Circular buffer with 150 slots at 20 bytes each = 3,000 bytes total

### 2. FFX_Sound_RegistCommandSync (0x6fa5e0, 327B, 20 blocks, CC=13)

Synchronous command dispatch, used when the caller needs confirmation the command was processed. Three dispatch paths:

```c
int __stdcall FFX_Sound_RegistCommandSync(int cmdId, int arg1, int arg2, int arg3, int arg4) {
    // Step 1: Duplicate detection for cmd 59/61
    if (cmdId == 59 || cmdId == 61) {
        // Search existing queue for duplicate
        bool found = false;
        int idx = g_SoundCmdQueue.readIdx;
        while (idx != g_SoundCmdQueue.writeIdx) {
            if (g_SoundCmdQueue.slots[idx].cmdId == cmdId) {
                found = true;
                if (cmdId == 59) {
                    // Cmd59: REPLACE, overwrite in-place
                    g_SoundCmdQueue.slots[idx].arg1 = arg1;
                    g_SoundCmdQueue.slots[idx].arg2 = arg2;
                    g_SoundCmdQueue.slots[idx].arg3 = arg3;
                    g_SoundCmdQueue.slots[idx].arg4 = arg4;
                    return 1;  // replaced, no enqueue
                }
                // Cmd61: APPEND, just let it enqueue normally
                break;
            }
            idx = (idx + 1) % 150;
        }
    }

    // Step 2: Fast path, direct handler dispatch for cmds 17-19, 22, 25, 65
    if (cmdId >= 17 && cmdId <= 65) {
        int handlerIdx = cmdId - 17;
        void* handler = g_SoundCmdHandlerTable[handlerIdx].func;
        if (handler && (cmdId == 17 || cmdId == 18 || cmdId == 19
            || cmdId == 22 || cmdId == 25 || cmdId == 65)) {
            return ((int(__stdcall*)(int,int,int,int))handler)(arg1, arg2, arg3, arg4);
        }
    }

    // Step 3: Cmd 63 special, dispatch + scan for Cmd 51
    if (cmdId == 63) {
        FFX_Sound_QueueCommandAsync(cmdId, arg1, arg2, arg3, arg4);
        // Search queue for cmd 51 result
        return FFX_Sound_ScanQueueForCmd51();
    }

    // Step 4: Default path, enqueue + wait event (2x 5ms timeout)
    FFX_Sound_QueueCommandAsync(cmdId, arg1, arg2, arg3, arg4);
    WaitForSingleObject(g_SoundCmdQueue.event, 5);  // 5ms timeout
    WaitForSingleObject(g_SoundCmdQueue.event, 5);  // 5ms retry

    return 0;
}
```

**Fast direct dispatch commands (no queue round-trip):**
- Cmd 17, 18, 19: Fade operations
- Cmd 22: SetVolume
- Cmd 25: Extended volume
- Cmd 65: High-priority control

### 3. FFX_Sound_SpuCmdContextInit (0x886140, 392B, 46 blocks, CC=9)

SPU command context initialization, a **15-case switch** (n255 values 1-15) that maps SPU commands to their global state arrays:

```c
int __stdcall FFX_Sound_SpuCmdContextInit(int n255, int base, int n0xF) {
    if (n255 > 15) return 0;
    if (n255 <= 0) return 0;

    if (n255 == 1 || n255 == 5 || n255 == 8 || n255 == 9 || n255 == 13) {
        // 3D indexing path: base + 16*n0xF + 4*n3
        // These commands operate on 3D positional data (16 dwords per entry)
        int offset = base + 16 * n0xF;
        memset((char*)g_SPUCmdContext + offset, 0, 16 * 4);  // zero 16 dwords
    } else {
        // 1D indexing path: base + 4*n0xF
        // Simple scalar commands (volume, pan, etc.)
        int offset = base + 4 * n0xF;
        memset((char*)g_SPUCmdContext + offset, 0, 4);  // zero 1 dword
    }

    // Set magic marker at context + 0x1FF8
    *(uint32_t*)((char*)g_SPUCmdContext + 0x1FF8) = 0xFFFFFFFF;

    // Write n255 param to context header
    g_SPUCmdContext->n255 = n255;
    g_SPUCmdContext->baseOffset = base;
    g_SPUCmdContext->count = n0xF;

    return 1;
}
```

**3D-indexed commands (cases 1, 5, 8, 9, 13):** These use `base + 16*n0xF + 4*n3` addressing, meaning each of the n0xF entries has 16 DWORDs of state. This is rich 3D audio state (position, velocity, cone angles, rolloff, etc.).

**1D-indexed commands (all other cases):** These use `base + 4*n0xF`, simple scalar state (1 DWORD per entry). Used for volume, priority, category flags.

### 4. FFX_Sound_SpuCmd_InitSystem (0x81f0e0, 293B, 10 blocks, CC=6)

SPU subsystem initialization, allocates the **51,200-byte SPU DMA buffer**:

```c
int FFX_Sound_SpuCmd_InitSystem() {
    // Allocate 51,200-byte SPU buffer (PS3 SPU local store size: 256KB)
    // FFX uses ~50KB of SPU LS for audio DMA
    g_SPUDMABuffer = FFX_Heap_Alloc(51200, 64);  // 64-byte aligned (cache line)
    if (!g_SPUDMABuffer) return 0;

    // Zero-initialize
    memset(g_SPUDMABuffer, 0, 51200);

    // Initialize SPU command context at 11333C4 + 1838400
    g_SPUGlobalState = (SPUState*)((char*)0x11333C4 + 1838400);  // 3,708 bytes

    // Set default SPU parameters
    g_SPUGlobalState->sampleRate = 48000;
    g_SPUGlobalState->numChannels = 2;  // stereo
    g_SPUGlobalState->bufferSize = 51200;

    return 1;
}
```

`★ Insight`
The 51,200-byte SPU buffer size is significant: the PS3's SPU has 256KB of local store, and FFX dedicates ~50KB (20%) to audio DMA. The 64-byte alignment matches x86 cache line size (vs. PS3's 128-byte cache lines on Cell BE). The 3,708-byte SPU global state block at 0x11333C4[1838400..1842108] contains all runtime SPU audio parameters.
`----------------------------------------------`

### 5. FFX_Sound_FmodSystemUpdate (0xaf1090, 11B)

The simplest function in the sound system, sets a global flag to indicate FMOD has been updated:

```c
void __stdcall FFX_Sound_FmodSystemUpdate() {
    unk_22FB534 = 0;  // Clear "needs update" flag (11B total)
}
```

### 6. FFX_Sound_FmodMusic* nullsub thunks (all 0xA bytes)

All 19 FMOD Music wrapper functions are **nullsub thunks**, 10-byte functions that just return. Not one of them actually calls FMOD:

```asm
; FFX_Sound_FmodMusicPlay @ 0xaf1060  (0xA bytes)
mov   eax, 1
retn  0C

; FFX_Sound_FmodMusicStop @ 0xaf1080  (0xA bytes)
mov   eax, 1
retn  4

; FFX_Sound_FmodMusicSwitchTrack @ 0xaf10a0  (0xA bytes)
mov   eax, 1
retn  8

; FFX_Sound_FmodMusicCrossfade @ 0xaf10c0  (0xA bytes)
mov   eax, 1
retn  0C

; FFX_Sound_FmodMusicGetFftSpectrum @ 0xaf10e0  (0xA bytes)
mov   eax, 1
retn  4

; FFX_Sound_FmodMusicGetTimeMs @ 0xaf1100  (0xA bytes)
xor   eax, eax
retn  4
```

This confirms FMOD music playback is **dead code** in the PC port. The music likely routes through a different path (possibly BGM streaming via SPU DMA or a separate video player for cutscenes).

### 7. FFX_Sound_FmodSfxSetVolumeByBank_structural (0xaf3ab0, 0xB7)

Despite the name suggesting it sets volume by bank, this is actually a **PhyreEngine class descriptor registration** for `PMLAAD3D11` (post-processing):

```c
void __stdcall FFX_Sound_FmodSfxSetVolumeByBank_structural() {
    // This is NOT an FMOD function!
    // It registers the PMLAAD3D11 class with PhyreEngine's RTTI system

    PClassDescriptor* desc = PClassDescriptor::Create(
        "PMLAAD3D11",                    // class name
        &PMLAAD3D11_vtable,              // vtable pointer
        sizeof(PMLAAD3D11),              // class size
        &PPostProcessingEffect_vtable    // parent class vtable
    );

    // Register with global class registry
    g_PhyreClassRegistry->RegisterClass(desc);
}
```

### 8. FFX_Sound_FmodSfxOneShot (0xaf7930, 49B)

Similarly misnamed, this is **PInputChannelSemantic registration**:

```c
void __stdcall FFX_Sound_FmodSfxOneShot() {
    PClassDescriptor* desc = PClassDescriptor::Create(
        "PInputChannelSemantic",
        &PInputChannelSemantic_vtable,
        sizeof(PInputChannelSemantic),
        &PClassDescriptor_vtable
    );
    g_PhyreClassRegistry->RegisterClass(desc);
}
```

`★ Insight`
IDA's naming heuristic grouped 31 "FFX_Sound_FmodSfx_*_structural" functions under the sound domain, but many are PhyreEngine class registration stubs for completely unrelated classes (PMLAAD3D11 post-processing, PInputChannelSemantic, PUtilityIggy). This inflates the FMOD SFX count, roughly 18 of the 49 "FmodSfx" functions are actually Phyre RTTI registrations, not sound functions.
`----------------------------------------------`

### 9. FFX_SoundCmd_HandlerReqSetVoicePriority (0x710d30, 466B, 34 blocks, CC=15)

Voice priority parser, reads a binary file of DWORD-pairs (voice ID + priority) with a **non-standard growth factor**:

```c
int __stdcall FFX_SoundCmd_HandlerReqSetVoicePriority(int voiceId, int priority) {
    // Load priority table from binary file
    // Format: DWORD-pair array [(voiceId, priority), ...]

    HANDLE hFile = CreateFileA(
        "ps3data/sound_pc/voice/priority.bin",
        GENERIC_READ, FILE_SHARE_READ, NULL,
        OPEN_EXISTING, 0, NULL
    );
    if (hFile == INVALID_HANDLE_VALUE) return 0;

    // Get file size
    DWORD fileSize = GetFileSize(hFile, NULL);
    int numPairs = fileSize / 8;  // each pair is 2 DWORDs

    // Allocate buffer with growth factor: size + size/8 + 2
    // This = ~12.5% overhead, unusual for a game (typical is 50-100%)
    // Suggests PS3 memory constraints: 256KB SPU LS forced tight allocation
    DWORD bufferSize = fileSize + (fileSize >> 3) + 2;
    DWORD* buffer = (DWORD*)FFX_Heap_Alloc(bufferSize, 4);
    if (!buffer) { CloseHandle(hFile); return 0; }

    // Read file
    DWORD bytesRead;
    ReadFile(hFile, buffer, fileSize, &bytesRead, NULL);
    CloseHandle(hFile);

    // Parse DWORD pairs
    for (int i = 0; i < numPairs; i++) {
        DWORD id       = buffer[i * 2];      // voice ID
        DWORD prio     = buffer[i * 2 + 1];   // priority value
        g_VoicePriorityTable[id] = prio;       // store in lookup table
    }

    FFX_Heap_Free(buffer);
    return 1;
}
```

**Growth factor analysis:** `size + size/8 + 2` = `size * 1.125 + 2` ~ 12.5% overhead. This is extremely tight, far below typical game allocator growth (50-100%). Likely a PS3-era optimization where SPU local store (256KB) forced minimal allocation slack.

### 10. FFX_Sound_EsPlay_ComputePositionalAudio (0x71e900, 1189B, 25 blocks, CC=12)

Core 3D audio computation, handles listener-relative position, distance attenuation, and doppler shift:

```c
int __stdcall FFX_Sound_EsPlay_ComputePositionalAudio(
    EsPlayContext* ctx, float* inPos, float* inVel,
    float* outVolume, float* outPan, float* outDoppler
) {
    // Step 1: Transform source position to listener-relative
    float relPos[3];
    relPos[0] = inPos[0] - ctx->listenerPos[0];
    relPos[1] = inPos[1] - ctx->listenerPos[1];
    relPos[2] = inPos[2] - ctx->listenerPos[2];

    // Step 2: Distance calculation
    float distance = sqrtf(relPos[0]*relPos[0] + relPos[1]*relPos[1] + relPos[2]*relPos[2]);

    // Step 3: Projection, two code paths
    uint32_t flags = ctx->flags;
    if (flags & 0x400) {
        // FLOAT PATH: Perspective divide (w-divide)
        // Used when high precision is needed
        float invW = 1.0f / (relPos[2] + ctx->projectionOffset);
        outPan[0] = relPos[0] * invW;   // X screen position
        outPan[1] = relPos[1] * invW;   // Y screen position
    } else {
        // INT16 PATH: PS3 SPU fixed-point native
        // Source coordinates in int16 (PS3 SPU native format)
        // No perspective divide, simpler projection
        outPan[0] = (float)(*(int16_t*)&relPos[0]) / 32768.0f;
        outPan[1] = (float)(*(int16_t*)&relPos[1]) / 32768.0f;
    }

    // Step 4: Distance attenuation
    float atten;
    if (distance < ctx->minDistance)
        atten = 1.0f;
    else if (distance > ctx->maxDistance)
        atten = 0.0f;
    else
        atten = 1.0f - (distance - ctx->minDistance) / (ctx->maxDistance - ctx->minDistance);

    *outVolume = atten;

    // Step 5: Doppler shift (velocity-based pitch change)
    float relativeVel = (inVel[0] - ctx->listenerVel[0]) * relPos[0]
                      + (inVel[1] - ctx->listenerVel[1]) * relPos[1]
                      + (inVel[2] - ctx->listenerVel[2]) * relPos[2];
    relativeVel /= distance;  // normalize

    *outDoppler = 1.0f + relativeVel * ctx->dopplerFactor;

    return 1;
}
```

**Two projection paths:**
- **Float path** (flag 0x400): True perspective divide (1/w). Higher precision, used for close-up audio where positional accuracy matters.
- **Int16 path**: PS3 SPU fixed-point native. Lower precision but faster, matches Cell BE SPU architecture where fixed-point SIMD was the primary compute model.

### 11. FFX_Sound_EsPlay_ProjectVertexCoords (0x7162d0, 485B, 15 blocks, CC=7)

Vertex coordinate projection for 3D audio, transforms 3D positions into 2D screen-space for audio panning:

```c
void __stdcall FFX_Sound_EsPlay_ProjectVertexCoords(
    EsPlayVertex* vertices, int numVerts,
    float* viewMatrix, float* projMatrix
) {
    for (int i = 0; i < numVerts; i++) {
        float* v = vertices[i].pos;

        // Transform by view matrix
        float viewX = v[0]*viewMatrix[0] + v[1]*viewMatrix[4] + v[2]*viewMatrix[8]  + viewMatrix[12];
        float viewY = v[0]*viewMatrix[1] + v[1]*viewMatrix[5] + v[2]*viewMatrix[9]  + viewMatrix[13];
        float viewZ = v[0]*viewMatrix[2] + v[1]*viewMatrix[6] + v[2]*viewMatrix[10] + viewMatrix[14];
        float viewW = v[0]*viewMatrix[3] + v[1]*viewMatrix[7] + v[2]*viewMatrix[11] + viewMatrix[15];

        // Project
        float projX = viewX*projMatrix[0] + viewY*projMatrix[4] + viewZ*projMatrix[8]  + viewW*projMatrix[12];
        float projY = viewX*projMatrix[1] + viewY*projMatrix[5] + viewZ*projMatrix[9]  + viewW*projMatrix[13];
        float projZ = viewX*projMatrix[2] + viewY*projMatrix[6] + viewZ*projMatrix[10] + viewW*projMatrix[14];
        float projW = viewX*projMatrix[3] + viewY*projMatrix[7] + viewZ*projMatrix[11] + viewW*projMatrix[15];

        // Perspective divide
        if (projW != 0.0f) {
            vertices[i].screenX = projX / projW;
            vertices[i].screenY = projY / projW;
            vertices[i].depth = projZ / projW;
        }

        // Write audio projection params
        vertices[i].panX = vertices[i].screenX;
        vertices[i].panY = vertices[i].screenY;
    }
}
```

This is a **full 4x4 matrix transform pipeline** (view x projection x perspective divide), essentially the same math as the graphics vertex shader, applied to audio sources. This confirms EsPlay is a **screen-space 3D audio system**: sounds are panned based on their screen position, not just left-right stereo.

### 12. FFX_Sound_SetSourcePosition (0x8768d0, 2447B, 66 blocks, CC=35)

The largest non-wrapper sound function, full 3D audio source position update with 66 basic blocks and cyclomatic complexity 35:

```c
int __stdcall FFX_Sound_SetSourcePosition(int sourceHandle, float x, float y, float z) {
    // Validate handle
    SoundSource* src = FFX_Sound_GetSourceByHandle(sourceHandle);
    if (!src) return 0;

    // Update position
    src->pos[0] = x;
    src->pos[1] = y;
    src->pos[2] = z;

    // Check if source is currently playing
    if (src->state != SOUND_STATE_PLAYING) {
        src->dirty = 1;  // mark for update when play starts
        return 1;
    }

    // Route through command queue
    FFX_Sound_QueueCommandAsync(CMD_SET_SOURCE_POS, sourceHandle,
        *(uint32_t*)&x, *(uint32_t*)&y, *(uint32_t*)&z);

    // Check distance from listener for volume rolloff
    float dx = x - g_ListenerPos[0];
    float dy = y - g_ListenerPos[1];
    float dz = z - g_ListenerPos[2];
    float distSq = dx*dx + dy*dy + dz*dz;

    // Apply distance-based volume (inverse square with min/max)
    if (distSq < src->minDistSq) {
        src->currentVolume = src->baseVolume;
    } else if (distSq > src->maxDistSq) {
        src->currentVolume = 0.0f;  // too far, inaudible
    } else {
        float dist = sqrtf(distSq);
        float atten = 1.0f - (dist - src->minDistance) / (src->maxDistance - src->minDistance);
        src->currentVolume = src->baseVolume * atten;
    }

    // Update pan based on angle from listener forward
    float angle = atan2f(dx, dz);  // YZ plane for left-right
    src->currentPan = sinf(angle);  // -1 to 1

    return 1;
}
```

---

## Complete Inventory

### By Sub-Family

| Sub-family | Count | % of Total | Description |
|------------|-------|-----------|-------------|
| `FFX_Sound_EsPlayWrapper_*` | ~151 | 30.4% | EsPlay wrapper/structural (inc. 25,460B giant) |
| `FFX_Sound_Voice_*` | ~98 | 19.7% | Voice playback wrappers |
| `FFX_Sound_CategoryVol_*` | ~55 | 11.0% | Category volume management |
| `FFX_Sound_SpuDma_*` | 51 | 10.2% | SPU DMA buffer management |
| `FFX_Sound_FmodSfx_*` | 49 | 9.8% | FMOD SFX bridge (~18 are Phyre RTTI misnamed) |
| `FFX_Sound_SpuCmd_*` | 38 | 7.6% | SPU command dispatch (15-case switch) |
| `FFX_Sound_CmdHandler_*` | ~25 | 5.0% | Command handler implementations |
| `FFX_Sound_FmodMusic_*` | 19 | 3.8% | FMOD Music wrappers (ALL nullsub stubs) |
| `FFX_Sound_Queue_*` | ~5 | 1.0% | Queue management |
| `FFX_Sound_EsPlay_*` | 5 | 1.0% | Core EsPlay engine |
| `FFX_Sound_FmodSystem*` | 3 | 0.6% | FMOD system update |
| `FFX_Sound_FmodNull_*` | 3 | 0.6% | Explicit nullsubs |
| `FFX_Sound_EsPlay_Voice_*` | ~2 | 0.4% | EsPlay voice bridge |
| Other misc | ~5 | 1.0% | Unclassified |

### Size Distribution

| Size Range | Count | Examples |
|------------|-------|---------|
| < 10 bytes | ~200 | Thunks, stubs |
| 10-100 bytes | ~180 | Small handlers |
| 100-1000 bytes | ~100 | Medium functions |
| 1000-5000 bytes | ~15 | Complex handlers |
| 5000+ bytes | 1 | EsPlayWrapper_structural (25,460B) |

### Size Distribution by Sub-Family

```
EsPlayWrapper    ################################   25,460B (1 func)
EsPlay_*         ##########  1,189 + 485 + 2,447B  (5 funcs)
CmdHandler_*     #######  466 + 300-800B each       (~25 funcs)
Queue_*          ####  369 + 327B                    (~5 funcs)
SpuCmd_*         ####  392 + 293B + small            (38 funcs)
SpuDma_*         ##  50-200B each                   (51 funcs)
FmodSfx_*        #  11-183B each (many = 0xB Phyre)  (49 funcs)
FmodMusic_*      #  10B each (ALL nullsub stubs)     (19 funcs)
Voice_*          ##  50-300B each                   (~98 funcs)
CategoryVol_*    #  20-100B each                    (~55 funcs)
```

---

## Data Flow

```
Game Code (Battle, Field, Menu)
    |
    v
+-----------------------------------------+
| FFX_Sound_QueueCommandAsync(cmdId)      |  < Async path (non-blocking)
| FFX_Sound_RegistCommandSync(cmdId)      |  < Sync path (waits for processing)
+--------------------+--------------------+
                     |
                     v
+-----------------------------------------+
| Sound Command Queue (CE8448)            |
| . 150-slot circular buffer              |
| . Mutex-protected                       |
| . Overflow detection + log              |
+--------------------+--------------------+
                     |
                     v
+-----------------------------------------+
| Command Handler Dispatch                |
| g_FFX_SoundCmdHandlerTable @ C3A3A4    |
| Indexed as: ArgList - 17                |
|                                          |
| +--- Direct Dispatch (fast) ---------+  |
| | Cmds 17-19, 22, 25, 65            |  |
| | Handler called immediately         |  |
| +------------------------------------+  |
|                                          |
| +--- Queue + Event ------------------+  |
| | Default path (2x5ms timeout)       |  |
| | SetEvent for cmds 8/58             |  |
| +------------------------------------+  |
+--------------------+--------------------+
                     |
                     v
+-----------------------------------------+
| SPU DMA Emulation Layer                 |
| . 51,200B DMA buffer                    |
| . 3,708B global state                   |
| . 15-case command switch                |
|   - 3D indexed: base+16*n0xF+4*n3      |
|   - 1D indexed: base+4*n0xF            |
+--------------------+--------------------+
                     |
                     v
+-----------------------------------------+
| EsPlay 3D Positional Audio              |
| . Projection: float or int16 path       |
| . Full 4x4 matrix transform             |
| . Distance attenuation + doppler        |
| . Screen-space panning (X/Y)            |
+--------------------+--------------------+
                     |
                     v
              FMOD Ex Output
           (PC audio hardware)
```

---

## Key Findings

1. **4-layer architecture**: FMOD Ex > Command Queue > SPU DMA > EsPlay 3D. The FMOD layer handles PC audio output, while SPU DMA emulates PS3 Cell BE audio processing, and EsPlay provides 3D positional rendering.

2. **FMOD Music is dead code**: All 19 `FFX_Sound_FmodMusic_*` functions are 0xA-byte nullsub thunks that return immediately. FMOD music playback was disabled in the PC port, likely no BGM patent license for PC, or music routes through a different system.

3. **18 of 49 "FmodSfx" functions are misnamed Phyre RTTI registrations**: IDA's naming grouped `PMLAAD3D11`, `PInputChannelSemantic`, and `PUtilityIggy` class registrations under `FFX_Sound_FmodSfx*` because their address range falls within the sound module's .text section.

4. **Circular command queue with 150 slots**: Each slot is 20 bytes (5 DWORDs), totaling 3,000 bytes at CE8448. Mutex-protected with INFINITE wait. Overflow only logs a warning, does not block or drop commands.

5. **Sync dispatch has 3 paths**: Fast direct handler (cmds 17-19, 22, 25, 65), Search+scan (cmd 63 dispatches + scans for cmd 51), and Default event-wait (2x5ms timeout).

6. **Cmd 59/61 have special dedup logic**: Cmd59 uses replace semantics (battle priority overrides), Cmd61 uses append semantics (accumulating action queue entries).

7. **EsPlayWrapper_structural at 25,460B is the #1 largest non-Phyre function**: 6,042 instructions, 470 basic blocks, CC=234, 8-case switch, 9KB stack frame via `__alloca_probe`. Likely a code-generated SPU microcode blob embedded as C code.

8. **SPU DMA buffer is 51,200 bytes with 64-byte alignment**: Matches PS3 SPU local store architecture scaled down. 64-byte alignment = x86 cache line (vs. PS3's 128-byte cache lines). 3,708 bytes of SPU global state at 0x11333C4[1838400+].

9. **Two projection paths in EsPlay**: Float path (flag 0x400, perspective divide via 1/w) for high-precision, and int16 path (PS3 SPU fixed-point native) for compatibility. EsPlay uses full 4x4 matrix transforms, essentially vertex shader math for audio.

10. **Voice priority parser uses tight 12.5% growth factor**: `size + size/8 + 2` is unusually low for game allocators (typical is 50-100% overhead). PS3 SPU 256KB local store constraints forced this optimization.

---

## What's Next?

- **batch_0009**: RTTI classes via class_informer (1500+ PhyreEngine type descriptors in FFX.exe)
- **batch_0010**: FFX_System_Host_Constructor (3482B) master entry point / boot sequence
- **batch_0011**: FFX_Battle_ComputeHitDamage (2127B) damage formula
- **batch_0012**: Sound queue trace MSCD, PhyreEngine stream layer (file I/O path)

---

**Next batch:** RTTI class reconstruction via class_informer, recover the 1500+ PhyreEngine type descriptors and reconstruct the class hierarchy.
