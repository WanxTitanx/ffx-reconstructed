// Function: sub_818340
// Address: 0x818340
int __cdecl sub_818340(int a1, int a2)
{
  int v4; // edi
  int v5; // eax
  double v6; // st7
  unsigned __int8 v7; // cl
  unsigned __int8 v9; // [esp+2Bh] [ebp+Bh]
  float v10; // [esp+2Ch] [ebp+Ch]
  float v11; // [esp+2Ch] [ebp+Ch]

  v4 = *(_DWORD *)(a1 + 544);
  v5 = sub_800F80((_DWORD *)(a1 + 768), v4, *(_WORD *)(a2 + 2));
  v6 = *(float *)(v4 + 144);
  sub_7E7DE0(*(float *)(v4 + 144), *(float *)(v4 + 152), *(float *)(v5 + 144), *(float *)(v5 + 152), a1);
  v10 = v6;
  v7 = *(_BYTE *)(a2 + 4);
  v9 = *(_BYTE *)(a2 + 5);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0x1000 )
    {
      if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
        v10 = v10 + 2048.0;
      *(float *)(v7 + v4) = v10;
      v11 = *(float *)a1 * 16.0;
      *(float *)(v9 + v4) = v11;
      return a2 + 6;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
      v10 = v10 + 2048.0;
    *(float *)(v7 + v4) = v10;
    return a2 + 6;
  }
}
