// Function: sub_8109F0
// Address: 0x8109f0
__int16 *__cdecl sub_8109F0(int a1, int a2, int a3, int a4)
{
  unsigned __int16 v4; // bx
  char *v5; // eax
  __int16 *v6; // esi
  float *v7; // edi
  double v8; // st7
  int v9; // ecx
  double v10; // st3
  double v11; // st7
  double v12; // st4
  double v13; // st7
  int v14; // eax
  int v16; // [esp+Ch] [ebp-24h]
  float v17; // [esp+Ch] [ebp-24h]
  int v18; // [esp+10h] [ebp-20h]
  float v19; // [esp+10h] [ebp-20h]
  float v20; // [esp+10h] [ebp-20h]
  int v21; // [esp+14h] [ebp-1Ch]
  int v22; // [esp+14h] [ebp-1Ch]
  float v23; // [esp+14h] [ebp-1Ch]
  float v24; // [esp+14h] [ebp-1Ch]
  float v25; // [esp+14h] [ebp-1Ch]
  float v26; // [esp+18h] [ebp-18h]
  float v27; // [esp+18h] [ebp-18h]
  float v28; // [esp+18h] [ebp-18h]
  float v29; // [esp+20h] [ebp-10h]
  unsigned int v30; // [esp+24h] [ebp-Ch]
  float v31; // [esp+28h] [ebp-8h]

  v4 = *(_WORD *)(a1 + 538);
  v5 = (char *)&unk_C49398 + 16 * (((int)v4 >> 7) & 0xE);
  v21 = *(_DWORD *)v5;
  v18 = *((_DWORD *)v5 + 1);
  v16 = *((_DWORD *)v5 + 2);
  v6 = (__int16 *)(a3 + 2);
  v7 = (float *)(a4 + word_C49300[((int)v4 >> 7) & 0xE]);
  v31 = *((float *)v5 + 3);
  if ( unk_C8F728 )
    LODWORD(v26) = (2 * (dword_C0A000 & 0x3FFFFF | 0x1FC00000))
                 | ((dword_C0A000 ^ ((unsigned int)dword_C0A000 >> 18)) >> 4) & 1;
  else
    v26 = 1.0;
  v8 = v26;
  unk_C8F728 = 1;
  v29 = v26;
  v27 = v26 - 1.887241363525391;
  v30 = (2 * (LODWORD(v27) & 0x3FFFFF | 0x1FC00000)) | ((unsigned int)(LODWORD(v27) ^ (LODWORD(v27) >> 18)) >> 4) & 1;
  v28 = *(float *)&v30 - 1.887241363525391;
  LODWORD(v31) = (2 * (LODWORD(v28) & 0x3FFFFF | 0x1FC00000))
               | ((unsigned int)(LODWORD(v28) ^ (LODWORD(v28) >> 18)) >> 4) & 1;
  *(float *)&dword_C0A000 = v31 - 1.887241363525391;
  if ( (v4 & 0x1000) != 0 )
  {
    v22 = v21 * *v6;
    v6 = (__int16 *)(a3 + 4);
    v9 = 1;
    v23 = (float)v22;
    v10 = v8;
    v11 = v23 * 0.000244140625;
    v24 = v10 * 2.0 - 3.0;
    v12 = v11 * v24 + *v7;
    v13 = 3.0;
    *v7 = v12;
  }
  else
  {
    v13 = 3.0;
    v9 = 0;
  }
  if ( (v4 & 0x2000) != 0 )
  {
    v14 = v18 * *v6;
    v25 = *(&v29 + v9) * 2.0 - v13;
    ++v6;
    ++v9;
    v19 = (float)v14;
    v7[1] = v25 * (v19 * 0.000244140625) + v7[1];
  }
  if ( (v4 & 0x4000) == 0 )
    return v6;
  v20 = 2.0 * *(&v29 + v9) - v13;
  v17 = (float)(v16 * *v6);
  v7[2] = 0.000244140625 * v17 * v20 + v7[2];
  return v6 + 1;
}
