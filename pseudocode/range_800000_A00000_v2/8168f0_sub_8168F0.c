// Function: sub_8168F0
// Address: 0x8168f0
int __cdecl sub_8168F0(int a1, int a2)
{
  int v2; // esi
  int v4; // eax
  double v5; // st7

  v2 = *(_DWORD *)(a1 + 544);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0x1000 )
    {
      *(_BYTE *)(v2 + 186) = 0;
      sub_7EA760(v2 + 64, v2 + 144, 16.0);
      *(_BYTE *)(v2 + 178) &= ~4u;
      return a2 + 4;
    }
    else
    {
      *(_BYTE *)(v2 + 178) &= ~4u;
      return a2;
    }
  }
  else
  {
    v4 = sub_800F80((_DWORD *)(a1 + 768), v2, *(_WORD *)(a2 + 2));
    v5 = *(float *)(v2 + 64);
    sub_7E7DE0(*(float *)(v2 + 64), *(float *)(v2 + 72), *(float *)(v4 + 64), *(float *)(v4 + 72), v2 + 64);
    *(float *)(v2 + 72) = v5;
    *(_BYTE *)(v2 + 178) &= ~4u;
    return a2 + 4;
  }
}
