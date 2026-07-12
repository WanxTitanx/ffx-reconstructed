// Function: sub_818430
// Address: 0x818430
int __cdecl sub_818430(int a1, int a2)
{
  float *v3; // ecx
  __int16 v4; // ax
  double v5; // st7
  double v7; // st7
  float v8; // [esp+10h] [ebp+8h]

  v3 = *(float **)(a1 + 544);
  v4 = *(_WORD *)(a1 + 538);
  v8 = (float)*(unsigned __int16 *)(a2 + 2);
  if ( (v4 & 0xE00) != 0 )
  {
    if ( (v4 & 0xE00) == 0x200 )
    {
      v5 = v8;
      if ( (v4 & 0x1000) != 0 )
        v3[32] = -(v3[24] / v5);
      if ( (*(_WORD *)(a1 + 538) & 0x2000) != 0 )
        v3[33] = -(v3[25] / v5);
      if ( (*(_WORD *)(a1 + 538) & 0x4000) != 0 )
        v3[34] = -(v3[26] / v5);
      if ( *(__int16 *)(a1 + 538) < 0 )
      {
        v3[35] = -(v3[27] / v5);
        return a2 + 4;
      }
    }
  }
  else
  {
    v7 = v8;
    if ( (v4 & 0x1000) != 0 )
      v3[28] = -(v3[20] / v7);
    if ( (*(_WORD *)(a1 + 538) & 0x2000) != 0 )
      v3[29] = -(v3[21] / v7);
    if ( (*(_WORD *)(a1 + 538) & 0x4000) != 0 )
      v3[30] = -(v3[22] / v7);
    if ( *(__int16 *)(a1 + 538) < 0 )
    {
      v3[31] = -(v3[23] / v7);
      return a2 + 4;
    }
  }
  return a2 + 4;
}
