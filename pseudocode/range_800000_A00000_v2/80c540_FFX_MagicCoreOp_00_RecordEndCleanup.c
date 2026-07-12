// Function: FFX_MagicCoreOp_00_RecordEndCleanup
// Address: 0x80c540
// [Jarvis naming goal 2026-06-17 pass2] Magic core opcode 0x00: record-end cleanup invoked by main interpreter and finalize handlers.
int __cdecl FFX_MagicCoreOp_00_RecordEndCleanup(int a1, int a2)
{
  int v2; // eax
  _DWORD *v3; // ecx

  v2 = *(_DWORD *)(a1 + 544);
  if ( !*(_WORD *)(a1 + 534) )
  {
    *(_DWORD *)v2 = 0;
    *(_DWORD *)(v2 + 4) = 0;
    *(_DWORD *)(v2 + 8) = 0;
    *(_DWORD *)(v2 + 12) = 0;
    v3 = (_DWORD *)((char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(v2 + 20));
    if ( v3[1] == v2 && (*v3 & 0xF0000000) == 0x40000000 )
    {
      *(_BYTE *)(a1 + 528) = 120;
      return a2;
    }
    sub_8013E0(a1 + 768, *(_WORD *)(a1 + 532));
    sub_800C30(a1 + 768, *(_WORD *)(a1 + 532));
    nullsub_105(*(__int16 *)(a1 + 532));
    --*(_WORD *)(a1 + 536);
  }
  *(_BYTE *)(a1 + 528) = 1;
  return 0;
}
