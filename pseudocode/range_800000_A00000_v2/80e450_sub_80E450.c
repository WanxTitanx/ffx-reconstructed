// Function: sub_80E450
// Address: 0x80e450
int __cdecl sub_80E450(int a1, int a2, _DWORD *a3, float *a4, int a5)
{
  float *v5; // ecx
  _DWORD *v6; // ebx
  float *v7; // edi
  __int16 *v8; // edx
  int n4; // esi
  float *v10; // eax
  float *v11; // esi
  float v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // edi
  int v16; // ecx
  int v17; // edx
  int v18; // edx
  int n128; // ecx
  char v20; // al
  double v21; // st7
  int result; // eax
  int n128_1; // ecx
  float v24; // [esp+14h] [ebp-6Ch]
  __int16 *v25; // [esp+1Ch] [ebp-64h]
  int n4_1; // [esp+20h] [ebp-60h]
  float *v27; // [esp+24h] [ebp-5Ch]
  _DWORD *v28; // [esp+28h] [ebp-58h]
  int n1065353216; // [esp+2Ch] [ebp-54h]

  v5 = *(float **)(a1 + 36);
  v6 = *(_DWORD **)(a1 + 40);
  *v5 = *(float *)word_C8F508;
  v5[1] = word_C8F50C;
  v5[2] = word_C8F510;
  v5[3] = word_C8F514[0];
  v5[4] = *(float *)word_C8F508;
  v5[5] = word_C8F50C;
  v5[6] = word_C8F510;
  v5[7] = word_C8F514[0];
  v5[8] = *(float *)word_C8F508;
  v5[9] = word_C8F50C;
  v5[10] = word_C8F510;
  v5[11] = word_C8F514[0];
  v5[12] = *(float *)word_C8F508;
  v5[13] = word_C8F50C;
  v5[14] = word_C8F510;
  v5[15] = word_C8F514[0];
  *v6 = word_C8F508[0];
  v6[1] = LODWORD(word_C8F50C);
  v6[2] = LODWORD(word_C8F510);
  v6[3] = LODWORD(word_C8F514[0]);
  v6[4] = word_C8F508[0];
  v6[5] = LODWORD(word_C8F50C);
  v6[6] = LODWORD(word_C8F510);
  v6[7] = LODWORD(word_C8F514[0]);
  v6[8] = word_C8F508[0];
  v6[9] = LODWORD(word_C8F50C);
  v6[10] = LODWORD(word_C8F510);
  v6[11] = LODWORD(word_C8F514[0]);
  v6[12] = word_C8F508[0];
  v6[13] = LODWORD(word_C8F50C);
  v6[14] = LODWORD(word_C8F510);
  v7 = a4;
  v8 = (__int16 *)(a5 + 2);
  v25 = (__int16 *)(a5 + 2);
  v27 = v5;
  v28 = v6;
  v6[15] = LODWORD(word_C8F514[0]);
  n4 = 4;
  n4_1 = 4;
  do
  {
    if ( *v8 )
    {
      v10 = (float *)sub_800F80(a3, (int)v7, *v8);
      unk_C8F980[0] = v7[36];
      flt_C8F984 = v7[37];
      flt_C8F988 = v7[38];
      v11 = v10;
      flt_C8F98C[0] = v7[39];
      flt_C8F970 = v10[36];
      flt_C8F974 = v10[37];
      flt_C8F978 = v10[38];
      v12 = v10[39];
      flt_C8F960 = flt_C8F970 - unk_C8F980[0];
      flt_C8F97C = v12;
      flt_C8F964 = flt_C8F974 - flt_C8F984;
      flt_C8F968 = flt_C8F978 - flt_C8F988;
      flt_C8F96C = v12 - flt_C8F98C[0];
      sub_42EF00();
      *v6 = LODWORD(flt_C8F960);
      v6[1] = LODWORD(flt_C8F964);
      v6[2] = LODWORD(flt_C8F968);
      v6[3] = LODWORD(flt_C8F96C);
      v13 = *(_DWORD *)((char *)v11 + dword_C8B500 + 76);
      dword_C8B500 = 0;
      if ( v13 == word_C8F508[0] && unk_C8F52C == LODWORD(word_C8F50C) )
      {
        v14 = unk_C8F530;
        v15 = unk_C8F534;
        v16 = 0;
        flt_C8F950 = 1.0;
        unk_C8F954 = 0;
        unk_C8F958 = unk_C8F530;
        unk_C8F95C = unk_C8F534;
      }
      else
      {
        v15 = unk_C8F95C;
        v14 = unk_C8F958;
        v16 = unk_C8F954;
      }
      n1065353216 = 998244352;
      flt_C8F930 = 0.00390625;
      unk_C8F938 = unk_C8F530;
      unk_C8F93C = unk_C8F534;
      v24 = 0.00390625 * flt_C8F950;
      unk_C8F52C = 0;
      unk_C8F934 = 0;
      n1065353216 = *((_DWORD *)v11 + 15);
      LODWORD(unk_C8F920) = n1065353216;
      LODWORD(unk_C8F928) = unk_C8F530;
      flt_C8F950 = v24 * *(float *)&n1065353216;
      LODWORD(unk_C8F92C) = unk_C8F534;
      n1065353216 = LODWORD(flt_C8F950);
      unk_C8F52C = v16;
      unk_C8F534 = v15;
      unk_C8F530 = v14;
      unk_C8F924 = 0.0;
      v6[3] = LODWORD(flt_C8F950);
      dword_C8B500 = 0;
      v17 = *((_DWORD *)v11 + 50);
      unk_C8F52B = BYTE1(word_C8F508[0]);
      unk_C8F529 = word_C8F508[0];
      unk_C8F52D = word_C8F50A;
      unk_C8F52F = HIBYTE(word_C8F50A);
      LOBYTE(unk_C8F52C) = BYTE2(v17);
      unk_C8F52E = HIBYTE(v17);
      unk_C8F52A = BYTE1(v17);
      LOBYTE(n1065353216) = v17;
      dword_C8B500 = 0;
      n1065353216 = n1065353216;
      v18 = unk_C8F52C;
      unk_C8F52A = word_C8F508[0];
      unk_C8F52E = word_C8F50A;
      unk_C8F536 = unk_C8F50E;
      LOWORD(unk_C8F52C) = HIWORD(n1065353216);
      LOWORD(n1065353216) = n1065353216;
      unk_C8F534 = HIWORD(v18);
      LOWORD(unk_C8F530) = v18;
      unk_C8F532 = LOWORD(word_C8F50C);
      unk_C8F980[0] = (float)(int)n1065353216;
      flt_C8F984 = (float)(int)unk_C8F52C;
      n1065353216 = 1015021568;
      v6 = v28;
      v7 = a4;
      flt_C8F988 = (float)unk_C8F530;
      flt_C8F970 = 0.015625;
      unk_C8F52C = 0;
      flt_C8F974 = 0.0;
      flt_C8F98C[0] = (float)unk_C8F534;
      v5 = v27;
      LODWORD(flt_C8F978) = unk_C8F530;
      n4 = n4_1;
      LODWORD(flt_C8F97C) = unk_C8F534;
      v8 = v25;
      unk_C8F980[0] = 0.015625 * unk_C8F980[0];
      flt_C8F984 = 0.015625 * flt_C8F984;
      flt_C8F988 = 0.015625 * flt_C8F988;
      flt_C8F98C[0] = 0.015625 * flt_C8F98C[0];
      *v27 = unk_C8F980[0];
      v27[1] = flt_C8F984;
      v27[2] = flt_C8F988;
      v27[3] = flt_C8F98C[0];
    }
    v6 += 4;
    v5 += 4;
    ++v8;
    --n4;
    v28 = v6;
    v27 = v5;
    v25 = v8;
    n4_1 = n4;
  }
  while ( n4 );
  n128 = (int)v7[12] / 2;
  if ( n128 < 128 )
    v20 = n128 < 0 ? 0 : n128;
  else
    v20 = 0x80;
  *(_BYTE *)(a1 + 76) = v20;
  v21 = v7[19];
  result = (int)v21 - ((int)v21 >> 31);
  n128_1 = (int)v21 / 2;
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
