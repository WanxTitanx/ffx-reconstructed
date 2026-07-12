// Function: FFX_MagicCoreOp_7F_OneShotRecordFinalize
// Address: 0x80c5e0
// [Jarvis naming goal 2026-06-17 pass2] Magic core opcode 0x7F: one-shot finalize/evict path through sub_7889E0/sub_7FE840, then opcode 0x00 cleanup.
int __cdecl FFX_MagicCoreOp_7F_OneShotRecordFinalize(int a1, int a2)
{
  char *v2; // eax
  int v3; // esi
  int v5; // [esp-4h] [ebp-Ch]

  v2 = (char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 544) + 20);
  v3 = *(_DWORD *)v2;
  if ( *(int *)v2 >= 0 && !v2[29] && (v3 & 0xF0000000) == 0 )
  {
    v5 = *(_DWORD *)v2;
    v2[29] = 1;
    FFX_BtlActor_FSM_ValidateCommandResult(v5);
  }
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
    return a2 + 4;
  sub_7FE840(v3);
  return FFX_MagicCoreOp_00_RecordEndCleanup(a1, a2);
}
