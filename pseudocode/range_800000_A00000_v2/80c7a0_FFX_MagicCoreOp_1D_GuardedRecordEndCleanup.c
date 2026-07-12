// Function: FFX_MagicCoreOp_1D_GuardedRecordEndCleanup
// Address: 0x80c7a0
// [Jarvis naming goal 2026-06-17 pass2] Magic core opcode 0x1D: guarded cleanup; validates record relation with sub_800F80 before delegating to opcode 0x00.
int __cdecl FFX_MagicCoreOp_1D_GuardedRecordEndCleanup(int a1, int a2)
{
  if ( sub_800F80((_DWORD *)(a1 + 768), *(_DWORD *)(a1 + 544), *(_WORD *)(a2 + 2)) == *(_DWORD *)(a1 + 800) )
    return FFX_MagicCoreOp_00_RecordEndCleanup(a1, a2);
  *(_BYTE *)(a1 + 528) = 1;
  return a2;
}
