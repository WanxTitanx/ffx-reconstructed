# IDA Session Info for Continuation

**IDA DB:** `C:\Users\wande\Documents\ffx-editor-main\ffx_exe_copy.i64`
**IDA Session ID:** `76b991e4` (headless)
**Image Base:** 0x400000
**Binary:** FFX.exe (Steam International)
**Architecture:** x86 32-bit

## Range: 0x800000 - 0xA00000

### Already Extracted (20 functions)
- 0x800000-0x8008E0: First 20 functions (magic system core)

### Remaining: ~10,780 functions

## Next Steps

### Option A: Run IDAPython script inside IDA Pro
Script location: `batch_decompile_all.py`
In IDA Pro: File > Script file... > select batch_decompile_all.py

### Option B: Continue via MCP
- Re-open DB: `idalib_idb_open(input_path="ffx_exe_copy.i64")` 
- New session will have a different ID
- Use `idalib_decompile(db, addr)` for individual functions
- Can do parallel batches of 20 per turn

### Key Addresses of Interest
- 0x800090: FFX_Magic_ProcessPendingQueue_structural
- 0x800530: FFX_Magic_RunPhase0Wrapper_structural
- 0x800590: FFX_Magic_RunPhase1Wrapper_structural
- 0x80CD60: FFX_Magic_RunRuntimeRootPhase_structural (0x12f5 bytes - huge)
- 0x80BEA0: FFX_Magic_RunAuxRuntimeRootPass_structural (0x699 bytes)
- 0x864180: FFX_Atel_InterpretWorkerOpcodes (0x1070 bytes)
- 0x868450: sub_868450 (0x43f bytes)
- 0x8694B0: sub_8694B0 (0x80b bytes)
- 0x8939A0: FFX_BtlUI_DrawScanTargetInfoPanel (0xd8f bytes)
- 0x8963C0: FFX_BtlUI_RenderPartyStatusDetail (0xd9a bytes)
- 0x8F5F70: sub_8F5F70 (0x28be bytes - largest in range)
- 0x8F41B0: FFX_Menu2D_DrawRoundedPanel9Slice (0x96c bytes)
- 0x95AA10: LuaVM_Dispatch (0x106a bytes)
