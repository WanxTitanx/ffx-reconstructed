// Function: sub_801970
// Address: 0x801970
int __cdecl sub_801970(int a1, int a2)
{
  int v2; // edx
  __int16 v3; // ax
  __int16 v5; // ax

  v2 = *(_DWORD *)(a1 + 544);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0x1000 )
    {
      v3 = *(_WORD *)(a2 + 2);
      *(_BYTE *)(v2 + 25) |= 0x80u;
      *(_WORD *)(v2 + 184) = v3;
    }
    return a2 + 4;
  }
  else
  {
    v5 = *(_WORD *)(a2 + 2);
    *(_BYTE *)(v2 + 25) &= ~0x80u;
    *(_WORD *)(v2 + 184) = v5;
    return a2 + 4;
  }
}
