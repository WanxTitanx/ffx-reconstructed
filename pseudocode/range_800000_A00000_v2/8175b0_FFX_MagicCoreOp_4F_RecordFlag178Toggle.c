// Function: FFX_MagicCoreOp_4F_RecordFlag178Toggle
// Address: 0x8175b0
int __cdecl FFX_MagicCoreOp_4F_RecordFlag178Toggle(int a1, int a2)
{
  int v2; // esi
  unsigned int n20480; // eax

  v2 = *(_DWORD *)(a1 + 544);
  n20480 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n20480 > 0x3000 )
  {
    if ( n20480 == 0x4000 )
    {
      *(_BYTE *)(v2 + 178) |= 4u;
    }
    else if ( n20480 == 20480 )
    {
      *(_BYTE *)(v2 + 178) &= ~4u;
      return a2 + 2;
    }
  }
  else
  {
    if ( n20480 == 12288 )
    {
      *(_BYTE *)(v2 + 178) &= ~2u;
      return a2 + 2;
    }
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
    {
      sub_788BE0(1);
      *(_BYTE *)(v2 + 178) |= 1u;
      return a2 + 2;
    }
    if ( n20480 == 4096 )
    {
      sub_788BE0(0);
      *(_BYTE *)(v2 + 178) &= ~1u;
      return a2 + 2;
    }
    if ( n20480 == 0x2000 )
    {
      *(_BYTE *)(v2 + 178) |= 2u;
      return a2 + 2;
    }
  }
  return a2 + 2;
}
