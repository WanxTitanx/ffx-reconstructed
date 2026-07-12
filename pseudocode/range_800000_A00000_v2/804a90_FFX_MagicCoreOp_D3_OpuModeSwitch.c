// Function: FFX_MagicCoreOp_D3_OpuModeSwitch
// Address: 0x804a90
// [Jarvis naming goal 2026-06-17 pass2] Magic core opcode 0xD3: OPU mode switch for draw/enable paths through sub_8301E0, sub_8269D0, sub_82AAB0.
int __usercall FFX_MagicCoreOp_D3_OpuModeSwitch@<eax>(int a1@<ebp>, int a2, int a3)
{
  int v3; // ecx
  unsigned int n4096; // eax
  _DWORD v6[263]; // [esp-410h] [ebp-41Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v6[260] = a1;
  v6[261] = retaddr;
  v3 = *(_DWORD *)(a2 + 544);
  n4096 = *(_WORD *)(a2 + 538) & 0xF000;
  if ( n4096 <= 0x2000 )
  {
    if ( n4096 != 0x2000 )
    {
      if ( (*(_WORD *)(a2 + 538) & 0xF000) == 0 )
      {
        sub_8301E0(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v3 + 24)]), *(__int16 *)(a3 + 2));
        return a3 + 4;
      }
      if ( n4096 == 4096 )
      {
        sub_800A10((_DWORD *)a2, (int)v6);
        sub_8269D0(*(__int16 *)(a3 + 2));
        sub_8009D0(a2, v6);
        return a3 + 4;
      }
      return a3;
    }
    sub_82AAB0(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v3 + 24)]), 1);
    return a3 + 2;
  }
  if ( n4096 == 12288 )
  {
    sub_82AAB0(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v3 + 24)]), 0);
    return a3 + 2;
  }
  return a3;
}
