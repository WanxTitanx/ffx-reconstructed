// Function: sub_802AF0
// Address: 0x802af0
int __cdecl sub_802AF0(int a1, int a2, _DWORD *a3, int a4, int a5)
{
  _DWORD *v5; // ecx
  float *v6; // esi
  float *v7; // edi
  int n4; // ecx
  __int16 *v9; // ebx
  int v10; // eax
  int n128; // ecx
  char v12; // al
  double v13; // st7
  int result; // eax
  int n128_1; // ecx
  int n4_1; // [esp+2Ch] [ebp+18h]

  v5 = *(_DWORD **)(a1 + 36);
  v6 = *(float **)(a1 + 40);
  *v5 = unk_C8F508[0];
  v5[1] = unk_C8F50C;
  v5[2] = unk_C8F510;
  v5[3] = unk_C8F514;
  v5[4] = unk_C8F508[0];
  v5[5] = unk_C8F50C;
  v5[6] = unk_C8F510;
  v5[7] = unk_C8F514;
  v5[8] = unk_C8F508[0];
  v5[9] = unk_C8F50C;
  v5[10] = unk_C8F510;
  v5[11] = unk_C8F514;
  v5[12] = unk_C8F508[0];
  v5[13] = unk_C8F50C;
  v5[14] = unk_C8F510;
  v5[15] = unk_C8F514;
  *v6 = *(float *)unk_C8F508;
  *((_DWORD *)v6 + 1) = unk_C8F50C;
  *((_DWORD *)v6 + 2) = unk_C8F510;
  *((_DWORD *)v6 + 3) = unk_C8F514;
  v6[4] = *(float *)unk_C8F508;
  *((_DWORD *)v6 + 5) = unk_C8F50C;
  *((_DWORD *)v6 + 6) = unk_C8F510;
  *((_DWORD *)v6 + 7) = unk_C8F514;
  v6[8] = *(float *)unk_C8F508;
  *((_DWORD *)v6 + 9) = unk_C8F50C;
  *((_DWORD *)v6 + 10) = unk_C8F510;
  *((_DWORD *)v6 + 11) = unk_C8F514;
  v6[12] = *(float *)unk_C8F508;
  *((_DWORD *)v6 + 13) = unk_C8F50C;
  *((_DWORD *)v6 + 14) = unk_C8F510;
  v7 = (float *)(v5 + 2);
  n4 = 4;
  v9 = (__int16 *)(a5 + 2);
  *((_DWORD *)v6 + 15) = unk_C8F514;
  n4_1 = 4;
  do
  {
    if ( *v9 )
    {
      v10 = sub_800F80(a3, a4, *v9);
      *v6 = *(float *)(v10 + 144);
      v6[1] = *(float *)(v10 + 148);
      v6[2] = *(float *)(v10 + 152);
      n4 = n4_1;
      v6[3] = *(float *)(v10 + 76) * 0.0625;
      *(v7 - 2) = (double)*(unsigned __int8 *)(v10 + 200) * 0.0078125;
      *(v7 - 1) = (double)*(unsigned __int8 *)(v10 + 201) * 0.0078125;
      *v7 = (double)*(unsigned __int8 *)(v10 + 202) * 0.0078125;
      v7[1] = 0.0078125 * (double)*(unsigned __int8 *)(v10 + 203);
    }
    v6 += 4;
    v7 += 4;
    ++v9;
    n4_1 = --n4;
  }
  while ( n4 );
  n128 = (int)*(float *)(a4 + 48) / 2;
  if ( n128 < 128 )
    v12 = n128 < 0 ? 0 : n128;
  else
    v12 = 0x80;
  *(_BYTE *)(a1 + 76) = v12;
  v13 = *(float *)(a4 + 76);
  result = (int)v13 - ((int)v13 >> 31);
  n128_1 = (int)v13 / 2;
  if ( n128_1 < 128 )
  {
    result = n128_1 < 0 ? 0 : n128_1;
    *(_BYTE *)(a1 + 77) = result;
  }
  else
  {
    *(_BYTE *)(a1 + 77) = 0x80;
  }
  return result;
}
