// Function: sub_80C910
// Address: 0x80c910
int __cdecl sub_80C910(int a1, int a2)
{
  int v2; // esi
  int v5; // edx
  __int16 v6; // cx
  double v7; // st7
  unsigned __int8 n6; // dl
  double v9; // st7
  unsigned int n0x4000; // eax
  bool v12; // pf
  float v13; // [esp+14h] [ebp+8h]
  float v14; // [esp+18h] [ebp+Ch]

  v2 = a2;
  if ( (*(_WORD *)(a1 + 538) & 0x400) != 0 )
  {
    v5 = sub_800F80((_DWORD *)(a1 + 768), *(_DWORD *)(a1 + 544), *(_WORD *)(a2 + 4));
    v2 = a2 + 2;
  }
  else
  {
    v5 = *(_DWORD *)(a1 + 544);
  }
  v6 = *(_WORD *)(a1 + 538);
  if ( (v6 & 0x800) != 0 )
  {
    v14 = *(float *)(*(unsigned __int8 *)(v2 + 4) + v5);
    v7 = *(float *)(*(unsigned __int8 *)(v2 + 5) + v5);
    n6 = 6;
    v13 = v7;
  }
  else
  {
    v13 = (float)*(__int16 *)(v2 + 6);
    v9 = *(float *)(*(unsigned __int16 *)(v2 + 4) + v5);
    n6 = 8;
    v14 = v9;
  }
  n0x4000 = v6 & 0xF000;
  if ( n0x4000 > 0x3000 )
  {
    if ( n0x4000 == 0x4000 )
    {
      if ( v13 > (double)v14 )
        return v2 + n6;
      goto LABEL_25;
    }
    if ( n0x4000 != 20480 )
      goto LABEL_25;
    v12 = v13 >= (double)v14;
  }
  else
  {
    if ( n0x4000 == 12288 )
    {
      if ( v13 <= (double)v14 )
        return v2 + n6;
      goto LABEL_25;
    }
    if ( (v6 & 0xF000) == 0 )
    {
      if ( v13 == v14 )
        return v2 + n6;
      goto LABEL_25;
    }
    if ( n0x4000 != 4096 )
    {
      if ( n0x4000 == 0x2000 && v13 < (double)v14 )
        return v2 + n6;
      goto LABEL_25;
    }
    v12 = v13 != v14;
  }
  if ( v12 )
    return v2 + n6;
LABEL_25:
  if ( (v6 & 0x200) == 0 )
    return a2 + *(__int16 *)(a2 + 2);
  *(_BYTE *)(a1 + 528) = 1;
  if ( (v6 & 0x400) != 0 )
    return v2 - 2;
  else
    return v2;
}
