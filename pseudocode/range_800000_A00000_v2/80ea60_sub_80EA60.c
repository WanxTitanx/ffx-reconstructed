// Function: sub_80EA60
// Address: 0x80ea60
int __cdecl sub_80EA60(int a1, int a2, _DWORD *a3, int a4, int a5)
{
  int v5; // ecx
  int v6; // esi
  float *v7; // edi
  int n4; // ecx
  __int16 *v9; // ebx
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  double v13; // st7
  int n128; // ecx
  char v15; // al
  double v16; // st7
  int result; // eax
  int n128_1; // ecx
  int n4_1; // [esp+Ch] [ebp-8h]
  __int16 v20; // [esp+12h] [ebp-2h]
  float v21; // [esp+2Ch] [ebp+18h]
  float v22; // [esp+2Ch] [ebp+18h]
  float v23; // [esp+2Ch] [ebp+18h]
  float v24; // [esp+2Ch] [ebp+18h]

  v5 = *(_DWORD *)(a1 + 36);
  v6 = *(_DWORD *)(a1 + 40);
  *(_DWORD *)v5 = word_C8F508[0];
  *(float *)(v5 + 4) = word_C8F50C;
  *(float *)(v5 + 8) = word_C8F510;
  *(float *)(v5 + 12) = word_C8F514[0];
  *(_DWORD *)(v5 + 16) = word_C8F508[0];
  *(float *)(v5 + 20) = word_C8F50C;
  *(float *)(v5 + 24) = word_C8F510;
  *(float *)(v5 + 28) = word_C8F514[0];
  *(_DWORD *)(v5 + 32) = word_C8F508[0];
  *(float *)(v5 + 36) = word_C8F50C;
  *(float *)(v5 + 40) = word_C8F510;
  *(float *)(v5 + 44) = word_C8F514[0];
  *(_DWORD *)(v5 + 48) = word_C8F508[0];
  *(float *)(v5 + 52) = word_C8F50C;
  *(float *)(v5 + 56) = word_C8F510;
  *(float *)(v5 + 60) = word_C8F514[0];
  *(_DWORD *)v6 = word_C8F508[0];
  *(float *)(v6 + 4) = word_C8F50C;
  *(float *)(v6 + 8) = word_C8F510;
  *(float *)(v6 + 12) = word_C8F514[0];
  *(_DWORD *)(v6 + 16) = word_C8F508[0];
  *(float *)(v6 + 20) = word_C8F50C;
  *(float *)(v6 + 24) = word_C8F510;
  *(float *)(v6 + 28) = word_C8F514[0];
  *(_DWORD *)(v6 + 32) = word_C8F508[0];
  *(float *)(v6 + 36) = word_C8F50C;
  *(float *)(v6 + 40) = word_C8F510;
  *(float *)(v6 + 44) = word_C8F514[0];
  *(_DWORD *)(v6 + 48) = word_C8F508[0];
  *(float *)(v6 + 52) = word_C8F50C;
  *(float *)(v6 + 56) = word_C8F510;
  v7 = (float *)(v5 + 8);
  n4 = 4;
  v9 = (__int16 *)(a5 + 2);
  *(float *)(v6 + 60) = word_C8F514[0];
  n4_1 = 4;
  do
  {
    if ( *v9 )
    {
      v10 = sub_800F80(a3, a4, *v9);
      *(_DWORD *)v6 = *(_DWORD *)(v10 + 144);
      *(_DWORD *)(v6 + 4) = *(_DWORD *)(v10 + 148);
      *(_DWORD *)(v6 + 8) = *(_DWORD *)(v10 + 152);
      *(float *)(v6 + 12) = *(float *)(v10 + 76) * 0.0625;
      v11 = *(_DWORD *)(v10 + 200);
      v12 = BYTE1(v11);
      v13 = (double)(unsigned __int8)v11;
      v20 = HIWORD(v11);
      n4 = n4_1;
      v21 = v13;
      *(v7 - 2) = *(float *)(v10 + 60) * 0.000030517578125 * v21;
      v22 = (float)v12;
      *(v7 - 1) = *(float *)(v10 + 60) * 0.000030517578125 * v22;
      v23 = (float)(unsigned __int8)v20;
      *v7 = 0.000030517578125 * *(float *)(v10 + 60) * v23;
      v24 = (float)HIBYTE(v20);
      v7[1] = v24 * 0.00390625;
    }
    v6 += 16;
    v7 += 4;
    ++v9;
    n4_1 = --n4;
  }
  while ( n4 );
  n128 = (int)*(float *)(a4 + 48) / 2;
  if ( n128 < 128 )
    v15 = n128 < 0 ? 0 : n128;
  else
    v15 = 0x80;
  *(_BYTE *)(a1 + 76) = v15;
  v16 = *(float *)(a4 + 76);
  result = (int)v16 - ((int)v16 >> 31);
  n128_1 = (int)v16 / 2;
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
