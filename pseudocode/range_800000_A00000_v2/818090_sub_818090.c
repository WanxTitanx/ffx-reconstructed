// Function: sub_818090
// Address: 0x818090
int __cdecl sub_818090(int a1, int a2)
{
  int v3; // esi
  unsigned int n12288; // eax
  double v6; // st7
  double v7; // st7
  unsigned __int8 v8; // cl
  float v9; // [esp+14h] [ebp-Ch]
  float v10; // [esp+28h] [ebp+8h]
  float v11; // [esp+28h] [ebp+8h]
  float v12; // [esp+28h] [ebp+8h]

  v3 = *(_DWORD *)(a1 + 544);
  if ( LODWORD(flt_12A80C0[*(unsigned __int8 *)(v3 + 24)]) )
    *(float *)a1 = sub_82AD60(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v3 + 24)]));
  v10 = *(float *)a1 * 2048.0 / 3.141592025756836;
  n12288 = *(_WORD *)(a1 + 538) & 0xF000;
  v11 = (float)((1024 - (unsigned __int16)(int)v10) & 0xFFF);
  if ( n12288 <= 0x3000 )
  {
    if ( n12288 == 12288 )
    {
      sub_795EC0(
        *((unsigned __int8 *)&unk_12A40D8 + 32 * *(unsigned __int16 *)(v3 + 20)),
        2,
        0,
        *(_BYTE *)(v3 + 24),
        0,
        0);
      return a2 + 2;
    }
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
    {
      *(float *)(v3 + 48) = 0.0;
      *(float *)(v3 + 52) = v11;
      *(float *)(v3 + 56) = 0.0;
      return a2 + 2;
    }
    if ( n12288 == 4096 )
    {
      *(float *)(v3 + 72) = v11;
      return a2 + 2;
    }
    if ( n12288 == 0x2000 )
    {
      *(float *)(v3 + 52) = v11;
      return a2 + 2;
    }
    return a2;
  }
  if ( n12288 != 0x4000 )
  {
    if ( n12288 != 20480 )
    {
      if ( n12288 != 24576 )
        return a2;
      v6 = sub_7948B0(*(unsigned __int8 *)(v3 + 24));
      v9 = v6;
      sub_81B280(v9);
      v11 = v6;
    }
    *(float *)(*(unsigned __int16 *)(a2 + 2) + v3) = v11;
    return a2 + 4;
  }
  sub_81B4F0((char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(v3 + 20), a1, 0);
  v7 = *(float *)(v3 + 144);
  sub_7E7DE0(*(float *)(v3 + 144), *(float *)(v3 + 152), *(float *)a1, *(float *)(a1 + 8), a1 + 16);
  v12 = v7;
  v8 = *(_BYTE *)(a2 + 3);
  *(float *)(*(unsigned __int8 *)(a2 + 2) + v3) = v12;
  if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
    *(float *)(v8 + v3) = *(float *)(a1 + 16);
  return a2 + 4;
}
