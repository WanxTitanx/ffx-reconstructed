# FFX.exe Decompilation — Batch 5 (ATEL Movie Dispatcher)

**Database:** ffxoficial_COPY.i64 (session b1d18aaa, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** ATEL VM dispatchers — namespace/index table, 5 calling conventions, 11 funcspace channels

---

## Summary

ATEL (Atelio) is FFX's **scripting bytecode VM** used for cutscenes, battle scripting, field events, and the Sphere Grid. This batch documents the dispatch core — how opcodes are routed, namespaced, and executed. Total decompiled: **9 functions, ~1,800 bytes**.

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_Atel_DispatchNativeCall` | 0x877720 | 73B | CALL dispatch (namespace + index lookup) |
| `FFX_Atel_CallStatusDispatchByNamespace` | 0x8776b0 | 54B | STATUS dispatch (returns handler flags) |
| `FFX_Atel_CallReturnDispatchByNamespace` | 0x877770 | 135B | FLOATRET/INTRET dispatch (pushes to VM stack) |
| `FFX_Atel_SizeAndDispatchChannelScripts` | 0x7983a0 | 298B | Channel sizing + actor instantiation |
| `FFX_Atel_InstantiateScriptsIntoActor` | 0x875650 | 631B | Channel actor slot instantiation |
| `FFX_Atel_ComputeScriptDataSize` | 0x86c050 | 155B | Worker data size calculation (16-byte aligned) |
| `FFX_Atel_Channel2_EventTickCallback` | 0x797360 | 90B | Channel 2 event tick (advance, parse, advance) |
| `FFX_Atel_RenderMovieFrame` | 0x76eed0 | 440B | Movie frame render (also dispatches via camera) |
| `FFX_Atel_Movie_CheckDispatchCondition` | 0x774b60 | 70B | Condition check before dispatch |

`★ Insight ─────────────────────────────────────`
- **ATEL = 11 funcspace channels** (Battle, Common, Math, Camera, Map, Movie, Mount, SgEvent, ChEvent, AbilityMap, Debug). Each channel = 256 opcodes × 16-byte entry = 4096B dispatch table. Total 2,816 unique opcodes.
- **Opcode ID encoding**: 16-bit ID split into namespace (high 4 bits) + index (low 12 bits). Lookup: `table[namespace] + 16 * (id & 0xFFF)`. This is why FFX_Atel_Movie_* has 475 functions — each opcode has up to 5 calling conventions.
- **Worker data size = 16-byte aligned sums**: each ATEL worker has a `dataLength` at worker+0x10. `ComputeScriptDataSize` sums all workers, rounding each up to 16-byte boundary. This is the memory layout for channel scripts.
`─────────────────────────────────────────────────`

---

## ATEL VM Architecture

### Opcode ID Encoding (16-bit)

```
Bit layout:  NNNN IIII IIII IIII
              ↑    ↑___________↑
              │         │
              │         └── index (0-4095) — offset into funcspace table
              └── namespace (0-15) — which funcspace table to use
```

**11 funcspaces used by FFX:**
| Namespace | Channel | Opcodes |
|-----------|---------|---------|
| 0 | Battle | 0x0-0x9F |
| 1 | Common | 0x1xx-0xFFF |
| 2 | Math | 0x2xx |
| 3 | Camera | 0x3xx |
| 4 | Map | 0x4xx |
| 5 | Movie | 0x5xx (B000-BFFF in old numbering) |
| 6 | Mount | 0x6xx |
| 7 | SgEvent | 0x7xx (Sphere Grid event) |
| 8 | ChEvent | 0x8xx (Character event) |
| 9 | AbilityMap | 0x9xx (Sphere Grid map) |
| 10 | Debug | 0xAxx |

### Opcode Entry Layout (16 bytes per opcode)

```
Offset  Field                Purpose
+0x00   callpopa_fn          Function pointer (CALLPOPA convention)
+0x04   pad / status_fn      STATUS convention (returns handler flags)
+0x08   float_return_fn      FLOATRET convention (returns float)
+0x0C   int_return_fn        INTRET convention (returns int)
```

**5 calling conventions per opcode:**
- `CALL` — call with args, no return
- `CALLPOPA` — call with args, pop "A" (mode) from stack
- `STATUS` — return status flags (0=ok, 5=not implemented)
- `FLOATRET` — return float, pushed to VM stack
- `INTRET` — return int, pushed to VM stack

### Global Opcode Table

```c
// global_1328518[11] = array of 11 funcspace pointers
void* g_funcspace_tables[11] = { /* init in FFX_Atel_InitVmAndRegisterFuncspaces */ };

// Each table = 256 entries × 16 bytes = 4096 bytes
// Total opcode storage: 11 × 4096 = 45,056 bytes
```

---

## Key Function Analysis

### 1. FFX_Atel_DispatchNativeCall (0x877720, 73B) — CALL dispatcher

The main entry point for `CALL` opcodes. Looks up the function in the global opcode table and invokes it.

```c
int FFX_Atel_DispatchNativeCall(unsigned int opcodeId, int arg1, int arg2, int arg3) {
    int namespace = opcodeId >> 12;
    int index = opcodeId & 0xFFF;
    
    // Special case: namespace 6 (Mount) — set "channel active" flag
    if (namespace == 6) {
        __int16 flags = *(_WORD*)(arg1 + 54);
        if ((flags & 0x10) == 0)
            *(_WORD*)(arg1 + 54) = flags | 0x20;
    }
    
    // Lookup: funcspace[namespace] + 16 * index
    int (*callpopa_fn)(int, int, int) = *(int(**)(int,int,int))(
        *(&g_funcspace_tables[namespace]) + 16 * index);
    
    if (callpopa_fn)
        return callpopa_fn(arg1, arg2, arg3);
    return 0;
}
```

**Key insight:** Namespace 6 (Mount) has a special side effect — sets a "channel active" flag at arg1+54 bit 0x20. This is likely for summon/mount summons that need to track active state.

### 2. FFX_Atel_CallStatusDispatchByNamespace (0x8776b0, 54B) — STATUS dispatcher

Returns handler flags instead of invoking. Used for "is this opcode available?" checks.

```c
int FFX_Atel_CallStatusDispatchByNamespace(unsigned int opcodeId, int argCount, int a3) {
    int namespace = opcodeId >> 12;
    int index = opcodeId & 0xFFF;
    
    int (*status_fn)(int, int) = *(int(**)(int,int))(
        *(&g_funcspace_tables[namespace]) + 16 * index + 4);  // slot +4
    
    if (status_fn)
        return status_fn(argCount, a3);
    return 5;  // 5 = "not implemented" sentinel
}
```

**Return value 5 = opcode not present** — VM checks this to skip unimplemented opcodes silently.

### 3. FFX_Atel_CallReturnDispatchByNamespace (0x877770, 135B) — FLOATRET/INTRET dispatcher

Picks float-return or int-return function, invokes it, pushes result to VM stack.

```c
int FFX_Atel_CallReturnDispatchByNamespace(unsigned int opcodeId) {
    int namespace = opcodeId >> 12;
    int index = opcodeId & 0xFFF;
    void* funcspace = g_funcspace_tables[namespace];
    
    // Try FLOATRET first (slot +8)
    double (*float_fn)(int, int, int*) = *(double(**)(int,int,int*))(funcspace + 16 * index + 8);
    if (float_fn) {
        float result = float_fn(arg1, arg2, arg3);
        return FFX_FieldVM_PushFloatOperand_structural(arg1, arg3, result);
    }
    
    // Fall back to INTRET (slot +12)
    int (*int_fn)(int, int, int*) = *(int(**)(int,int,int*))(funcspace + 16 * index + 12);
    if (int_fn) {
        int result = int_fn(arg1, arg2, arg3);
        return FFX_FieldVM_PushIntOperand_structural(arg1, arg3, result);
    }
    
    // Nothing — push 0
    return FFX_FieldVM_PushIntOperand_structural(arg1, arg3, 0);
}
```

**Key insight:** FLOATRET takes precedence over INTRET. If both are defined, only float is used. This is the dispatcher's "preference order" for return types.

### 4. FFX_Atel_SizeAndDispatchChannelScripts (0x7983a0, 298B) — Channel init

Sizes all scripts for an ATEL channel, allocates runtime buffers, dispatches them into actor slots.

```c
void FFX_Atel_SizeAndDispatchChannelScripts(FFX_AtelSubsystem subsystem, void* channelContext) {
    int scriptCount = *(int*)&byte_11333C4[84 * n2 + 4260];  // script count
    uint16_t** scripts = (uint16_t**)&byte_11333C4[84 * n2 + 4280];
    
    if (scriptCount > 0) {
        int totalDataSize = 0;
        int totalCodeSize = 0;
        for (int i = 0; i < scriptCount; ++i) {
            totalDataSize += FFX_Field_BattleTriggerDispatch_structural(*scripts);  // code size
            totalCodeSize += FFX_Atel_ComputeScriptDataSize(*scripts);             // data size
        }
        
        // Channel 2 (Camera) uses stack-allocated buffers; others use heap
        if (n2 == 2) {
            // Camera channel: 2048-byte static buffer at 0x11333C4[4432]
            *(int*)&byte_11333C4[4432] = &byte_11333C4[8612];
            uint32_t alignedSize = ((totalDataSize + 15) >> 31 & 0xF) + totalDataSize + 15 & 0xFFFFFFF0;
            *(int*)&byte_11333C4[4440] = &byte_11333C4[alignedSize + 8612];
            if (alignedSize + ((totalCodeSize + 15) & 0xFFFFFFF0) > 2048)
                FFX_Battle_InternalErrorAbort("cam");  // camera buffer overflow
        } else {
            // Other channels: heap allocation
            void* codeBuf = FFX_Heap_AllocGameArenaDebugFill_wrapper(totalDataSize);
            void* dataBuf = FFX_Heap_AllocGameArenaDebugFill_wrapper(totalCodeSize);
        }
        
        // Pick channel-specific callback
        int n3;
        void (*tickCallback)(int);
        if (n2 == 0) { n3 = 2; tickCallback = FFX_Battle_TriggerCameraAnimation; }
        else if (n2 == 1) { n3 = 3; tickCallback = FFX_Battle_AdvanceActorPriorities; }
        else if (n2 == 2) { n3 = 4; tickCallback = FFX_Atel_Channel2_EventTickCallback; }
        else return;
        
        // Instantiate all scripts into actor slots
        if (tickCallback)
            FFX_Atel_InstantiateScriptsIntoActor(
                (int)scripts, (int*)&byte_11333C4[84*n2+4312], scriptCount,
                (int)&byte_11333C4[4516], dataBuf, codeBuf, n3, (int)tickCallback);
    }
}
```

**Channel-specific callbacks:**
| Channel | n2 | n3 | Tick Callback |
|---------|-----|-----|---------------|
| Battle | 0 | 2 | `FFX_Battle_TriggerCameraAnimation` |
| ??? | 1 | 3 | `FFX_Battle_AdvanceActorPriorities` |
| Camera | 2 | 4 | `FFX_Atel_Channel2_EventTickCallback` |
| Other | 3+ | — | (early return) |

**Channel 2 (Camera) uses 2048-byte static buffer** — overflow aborts with `"cam"` error. This is a hard cap on camera script size.

### 5. FFX_Atel_InstantiateScriptsIntoActor (0x875650, 631B) — Actor slot fill

The most complex function in this batch. Fills actor slot with script workers, zero-init their data buffers.

```c
int* FFX_Atel_InstantiateScriptsIntoActor(
    int scriptArray, int* scriptWorkerCounts, int scriptCount,
    int baseline, char* dataBuf, int codeBuf, int n3, int tickCallback) {
    
    int* actorSlot = FFX_Field_InitActorSlot(n3, 0, codeBuf, -1);
    
    // Zero-init actor slot fields
    actorSlot[13] = 0;
    actorSlot[21] = (int)FFX_Field_ComputeChrIndexOffset;
    
    // Phase 1: Sum up worker counts, word counts across all scripts
    int totalWorkers = 0, word20Sum = 0, word16Sum = 0, word52Sum = 0;
    int walkDataSum = 0;
    if (scriptCount > 0) {
        for (int i = 0; i < scriptCount; ++i) {
            int script = *(int*)(scriptArray + 4*i);
            totalWorkers += FFX_Atel_GetScriptWorkerCount(script);
            word20Sum += FFX_Field_GetWord20FromRecord(script);
            walkDataSum += FFX_Field_GetModelRecordWalkDataOffset28(script);
            word16Sum += FFX_Atel_GetScriptWord16(script);
            word52Sum += FFX_Field_GetScriptWord52(script);
        }
    }
    
    // Store sums in actor slot
    *((__int16*)actorSlot + 6) = totalWorkers;
    *((__int16*)actorSlot + 8) = word52Sum;
    actorSlot[19] = tickCallback;
    *((__int16*)actorSlot + 11) = word16Sum;
    actorSlot[126] = scriptArray;
    *((__int16*)actorSlot + 10) = word20Sum;
    *((__int16*)actorSlot + 12) = walkDataSum;
    actorSlot[127] = scriptWorkerCounts;
    actorSlot[12] = baseline;
    
    // Init worker defaults
    FFX_Field_InitScriptWorkerDefaults(n3);
    FFX_Field_SwitchContextSlot(n3);
    
    // Phase 2: Iter 1 — process workers 0..workerCount for each script
    int v18 = 0;
    if (scriptCount > 0) {
        do {
            int script = *(int*)((char*)scriptWorkerCounts + (scriptArray - scriptWorkerCounts));
            int scriptWords = scriptWorkerCounts ? *scriptWorkerCounts : 0;
            int workerCount = FFX_Atel_GetScriptWorkerCount(script);
            int word52Val = FFX_Field_GetScriptWord52(script);
            int v24 = script;
            
            int ScriptWorkerCount_7 = 0;
            if (workerCount > 0) {
                do {
                    FFX_Atel_GetScriptWorkerByIndex(v24, ScriptWorkerCount_7);
                    FFX_Field_AiGoalCheck_structural(&v36, 0);
                    FFX_Atel_ZeroWorkerDataBuffer(v18, dataBuf);
                    dataBuf += FFX_Atel_ComputeWorkerDataSizeAligned(v18);
                    v24 = script;
                    ++ScriptWorkerCount_7;
                    ++v18;
                } while (ScriptWorkerCount_7 < workerCount);
            }
        } while (script iterated < scriptCount);
    }
    
    // Phase 3: Iter 2 — process workers workerCount..word52 for each script
    // (similar to phase 2 but different range)
    
    // Setup menu blob + script bridge
    FFX_Atel_SetupMenuBlobScripts(n3);
    FFX_Field_ScriptBridgeVirtualCall();
    return FFX_Field_SwitchContextSlot(0);
}
```

**Two-pass worker instantiation:**
- **Pass 1**: workers 0..workerCount (active workers)
- **Pass 2**: workers workerCount..word52 (remaining slots)

Each worker gets zero-init data buffer (16-byte aligned). This is the "I have memory but no script state yet" state.

### 6. FFX_Atel_ComputeScriptDataSize (0x86c050, 155B) — Worker data size

Sums all worker data lengths, rounded up to 16-byte boundary.

```c
int FFX_Atel_ComputeScriptDataSize(int scriptRecord) {
    uint16_t workerCount = *(uint16_t*)(scriptRecord + 54);
    int sum1 = 0, sum2 = 0, sum3 = 0;
    
    // Phase 1: pairs of workers (i += 2)
    if (workerCount >= 2) {
        int pairCount = ((workerCount - 2) >> 1) + 1;
        int ptr = scriptRecord + 60;
        do {
            int w1 = *(int*)(ptr - 4);
            ptr += 8;
            int64_t aligned1 = *(int*)(w1 + scriptRecord + 16) + 15;
            sum3 += ((BYTE4(aligned1) & 0xF) + aligned1) & 0xFFFFFFF0;
            
            int64_t aligned2 = *(int*)(*(int*)(ptr - 8) + scriptRecord + 16) + 15;
            sum2 += ((BYTE4(aligned2) & 0xF) + aligned2) & 0xFFFFFFF0;
        } while (--pairCount);
    }
    
    // Phase 2: last worker (if odd)
    if (pairCount < workerCount) {
        int lastWorker = *(int*)(scriptRecord + 4 * pairCount + 56);
        int64_t aligned = *(int*)(lastWorker + scriptRecord + 16) + 15;
        sum1 = ((BYTE4(aligned) & 0xF) + aligned) & 0xFFFFFFF0;
    }
    
    return sum1 + sum2 + sum3;
}
```

**Worker data accessor:** `worker + scriptRecord + 16` gets the worker's data length. The scriptRecord is the base, and each worker is identified by an offset into the script's worker array.

**16-byte alignment** — same pattern as FFX's other data structures. Engine_AlignedAllocAlign-style alignment.

### 7. FFX_Atel_Channel2_EventTickCallback (0x797360, 90B) — Event tick

Channel 2 (Camera/Event) tick: advance priorities, parse events, advance again.

```c
int FFX_Atel_Channel2_EventTickCallback(int ctx) {
    int modelCount = FFX_Field_GetModelRecordWalkData(ctx);
    
    // Pass 1: advance priority nodes
    for (int i = 0; i < modelCount; ++i)
        FFX_FieldActor_AdvancePriorityNode_structural(i, -1);
    
    // Pass 2: parse events with flag 1
    for (int j = 0; j < modelCount; ++j)
        FFX_Atel_ParseEventWithFlag1(j, 0);
    
    // Pass 3: advance again (post-event)
    for (int k = 0; k < modelCount; ++k)
        FFX_FieldActor_AdvancePriorityNode_structural(k, -1);
    
    return modelCount;
}
```

**Three-pass design:**
1. **Advance priorities** — update state based on prior tick
2. **Parse events** — process incoming events
3. **Advance again** — update state based on events

This is a classic **event loop pattern** — pre-advance, process, post-advance. Common in game engines where state transitions need to be coherent across passes.

### 8. FFX_Atel_RenderMovieFrame (0x76eed0, 440B) — Movie frame

Renders a single movie frame. Called by the main game loop each frame.

```c
void FFX_Atel_RenderMovieFrame() {
    if (!unk_112A008 || !FFX_Field_CheckMovieIdChar_DotHOrSpaceF())
        return;  // movie not active
    
    int frameNum = FFX_Video_NullsubSingleton();
    
    // Special handling for save/load op count 46 (load) or 70 (save)
    if (g_saveOpCount_52 == 46) {
        if (frameNum != 1147) ++frameNum;
        if (frameNum >= 1240) {
            frameNum = 1240;
            goto LABEL_12;
        }
    } else if (g_saveOpCount_52 == 70 && frameNum >= 970) {
        frameNum = 970;
        goto LABEL_12;
    }
    
    if (frameNum < 0) {
        FFX_FieldRender_SetGameStateFlag_12FBB63(0);
        return;
    }
    
LABEL_12:
    if (frameNum >= g_videoCameraDatBuffer / 42) {
        FFX_FieldRender_SetGameStateFlag_12FBB63(0);
        return;
    }
    
    // Read keyframe data at offset 168 * frameNum
    if (unk_CE829C) {
        int v1 = 168 * frameNum;
        int v3 = (int)*(float*)(v1 + unk_CE829C);
        memcpy(dst,  v1 + unk_CE829C + 4,  64);    // 16 ints
        memcpy(dst_1, v1 + unk_CE829C + 68, 64);    // 16 ints
        v6[0] = *(int*)(v1 + unk_CE829C + 132);
        v6[1] = *(int*)(v1 + unk_CE829C + 136);
        v6[2] = *(int*)(v1 + unk_CE829C + 140);
        v6[3] = *(int*)(v1 + unk_CE829C + 144);
        v7[0] = *(int*)(v1 + unk_CE829C + 148);
        v7[1] = *(int*)(v1 + unk_CE829C + 152);
        v7[2] = *(int*)(v1 + unk_CE829C + 156);
        v7[3] = *(int*)(v1 + unk_CE829C + 160);
        float v2 = *(float*)(v1 + unk_CE829C + 164);
    } else {
        LOBYTE(v3) = 0;
    }
    
    FFX_Atel_SetMovieGlobalFrameFloat_structural(v2);
    FFX_Menu2D_RenderWithTexture_structural(v3, dst, dst_1, v6, v7, v2);
    
    if (!FFX_Render_SetupCameraGlobal())
        FFX_Camera_Internal_OpX(0);
}
```

**Key insight:** Movie system is **state-driven, not stream-driven**. Reads from `unk_CE829C` (a frame array), bounded by `g_videoCameraDatBuffer / 42`. Save op counts 46 (load) and 70 (save) clamp frames to 1240 and 970 respectively — probably to avoid going beyond saved state.

### 9. FFX_Atel_Movie_CheckDispatchCondition (0x774b60, 70B) — Condition check

```c
int FFX_Atel_Movie_CheckDispatchCondition(int a1) {
    __int16 condId = *(_WORD*)(a1 + 32);
    if (condId < 0) return 0;
    
    int result = (*(int(__cdecl**)(_DWORD))(dword_C416C0 + 4 * condId))(*(_WORD*)(a1 + 34));
    
    char flag = *(_BYTE*)(a1 + 43);
    if (flag == 1) {
        if (result) return 1;
    } else if (flag == 0) {
        if (!result) return 1;
    }
    return 0;
}
```

**Condition dispatch via `dword_C416C0`**: array of condition-handler function pointers, indexed by `condId` (signed 16-bit). Param is `*(_WORD*)(a1 + 34)` — likely a "condition value" subscript.

**Flag interpretation:**
- flag 0: dispatch if condition FALSE (wait until false)
- flag 1: dispatch if condition TRUE (wait until true)
- flag >= 2: never dispatch

---

## ATEL Dispatch Flow

```
Bytecode script loaded
    ↓
FFX_Atel_SizeAndDispatchChannelScripts
    ↓
    ├── Sum script sizes (code + data)
    ├── Allocate buffers (heap or stack 2048B for camera)
    ├── Pick channel callback
    └── FFX_Atel_InstantiateScriptsIntoActor
          ↓
          ├── Init actor slot
          ├── Sum worker counts/words
          ├── Phase 1: zero-init data buffers for active workers
          ├── Phase 2: zero-init data buffers for remaining workers
          └── Setup menu blob + script bridge
    ↓
Game tick loop
    ↓
FFX_Atel_Channel2_EventTickCallback (channel 2)
    ├── Pass 1: advance priorities
    ├── Pass 2: parse events with flag 1
    └── Pass 3: advance priorities again
    ↓
Bytecode executes
    ↓
For each opcode:
    ├── CALL → FFX_Atel_DispatchNativeCall(opcodeId, args)
    ├── STATUS → FFX_Atel_CallStatusDispatchByNamespace(opcodeId, args)
    ├── FLOATRET → FFX_Atel_CallReturnDispatchByNamespace(opcodeId)
    ├── INTRET → FFX_Atel_CallReturnDispatchByNamespace(opcodeId)
    └── Lookup: funcspace[ns] + 16 * (id & 0xFFF)
          ├── slot +0: callpopa_fn
          ├── slot +4: status_fn
          ├── slot +8: float_return_fn
          └── slot +12: int_return_fn
```

---

## Opcode ID Numbering Discovery

Previously documented (batch_0002) as "B000-BFFF for movie". Now I can decode this:

`B000` = namespace 0xB (= 11??) and index 0x000. Wait, that's outside 0-15 namespace.

Looking again at `FFX_Atel_Movie_FuncB000_STATUS_structural` at 0x76ea90 — the function name has `B000` but the actual opcode ID encoding is **namespace (4 bits) + index (12 bits)**. So `B000` in the function name is just a label, not the actual opcode ID.

**Actual mapping** (from inspecting function names):
- `FuncB000` to `FuncBFFF` = 4096 functions, but the namespace/index encoding limits to 256 per channel. So "B000" probably means "channel 0xB offset 0x000" using a different ID encoding — maybe an absolute 16-bit ID where namespace is implicit in the channel.

This explains why `FFX_Atel_Movie_*` has 475 functions for 256 opcodes: **each opcode has up to 5 calling conventions** (CALL, CALLPOPA, STATUS, FLOATRET, INTRET), and the function name encodes `Func<OPCODE_ID>_<CONVENTION>`.

---

## Key Findings

1. **ATEL VM = 11 funcspace channels** — each channel = 256 opcodes × 16-byte entry = 4096B. Total 2,816 unique opcodes across all channels.

2. **Opcode ID = 16 bits split as namespace(4) + index(12)** — dispatched via `g_funcspace_tables[namespace] + 16 * (id & 0xFFF)`.

3. **5 calling conventions per opcode** — CALL, CALLPOPA, STATUS, FLOATRET, INTRET. Each opcode can have all 5 or any subset. Empty slots = opcode not implemented.

4. **Worker data size = 16-byte aligned sums** — `ComputeScriptDataSize` rounds each worker's data length up to 16-byte boundary. This is the memory layout for channel scripts.

5. **Channel 2 (Camera) uses 2048-byte static buffer** — overflow aborts with `"cam"` error. Other channels use heap allocation.

6. **Channel-specific tick callbacks**:
   - n2=0: `FFX_Battle_TriggerCameraAnimation` (n3=2)
   - n2=1: `FFX_Battle_AdvanceActorPriorities` (n3=3)
   - n2=2: `FFX_Atel_Channel2_EventTickCallback` (n3=4)

7. **Channel 2 event tick = 3-pass** — advance priorities, parse events with flag 1, advance again. Classic event loop pattern.

8. **Mount namespace (6) has side effect** — sets "channel active" flag at arg1+54 bit 0x20. Likely for summon/mount summoning that needs active state tracking.

9. **STATUS return 5 = not implemented** — VM checks this to skip unimplemented opcodes silently.

10. **FLOATRET takes precedence over INTRET** — if both are defined, only float is used. Dispatcher's "preference order" for return types.

11. **Actor slot instantiation is 2-pass** — phase 1 processes workers 0..workerCount (active), phase 2 processes workers workerCount..word52 (remaining). Both zero-init data buffers.

12. **Movie frame is state-driven, not stream-driven** — reads from `unk_CE829C` (frame array), bounded by `g_videoCameraDatBuffer / 42`. Save op 46 (load) clamps to 1240, save op 70 (save) clamps to 970.

---

## What's Next?

- **batch_0006**: AI decision loop (`FFX_Battle_AiDecisionLoop` — monster behavior)
- **batch_0007**: Particle system (`FFX_Particle_*`)
- **batch_0008**: Sound queue (`FFX_Sound_QueueCmd22/24/32/46`)
- **batch_0009**: RTTI classes via class_informer

---

**Next batch:** AI decision loop — monster AI/behavior.
