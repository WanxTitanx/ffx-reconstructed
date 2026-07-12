// Function: FFX_MagicCoreOp_41_RuntimeAssetBind
// Address: 0x8046d0
// [Jarvis naming goal 2026-06-17 pass2] Magic core opcode 0x41: binds runtime asset/resource via record mode nibble and OPU/resource helpers.
int __cdecl FFX_MagicCoreOp_41_RuntimeAssetBind(int a1, int a2)
{
  int v2; // edx
  int n0x2000; // eax

  v2 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 544) + 24);
  n0x2000 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( n0x2000 == 4096 )
    {
      FFX_BtlMenu_ResetActorCommandFlags(v2, 0);
      return a2 + 2;
    }
    else if ( n0x2000 == 0x2000 )
    {
      FFX_BtlMenu_ResetActorCommandFlags(v2, dword_C48E28[*(unsigned __int16 *)(a2 + 2)]);
      return a2 + 4;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    sub_82B400(LODWORD(flt_12A80C0[v2]), *(_WORD *)(a2 + 2));
    return a2 + 4;
  }
}
