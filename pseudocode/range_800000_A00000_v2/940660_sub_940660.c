// Function: sub_940660
// Address: 0x940660
int __cdecl sub_940660(char a1)
{
  int v1; // esi
  int v2; // ebx
  int result; // eax
  double v4; // st7
  _DWORD *v5; // edi
  float *v6; // esi
  float v7; // eax
  int v8; // ebx
  int v9; // ecx
  int v10; // esi
  int v11; // edx
  int v12; // eax
  int v13; // edi
  int v14; // ecx
  double v15; // st7
  int v16; // edx
  int v17; // eax
  double v18; // st6
  int v19; // eax
  int v20; // eax
  double v21; // st6
  double v22; // st7
  double v23; // st7
  float v24; // [esp+4h] [ebp-5Ch]
  float v25[3]; // [esp+18h] [ebp-48h] BYREF
  float v26; // [esp+24h] [ebp-3Ch]
  float v27; // [esp+28h] [ebp-38h]
  float v28; // [esp+2Ch] [ebp-34h]
  float v29; // [esp+30h] [ebp-30h]
  float v30; // [esp+34h] [ebp-2Ch]
  float v31; // [esp+38h] [ebp-28h]
  _DWORD v32[4]; // [esp+3Ch] [ebp-24h] BYREF
  float v33; // [esp+4Ch] [ebp-14h] BYREF
  float v34; // [esp+50h] [ebp-10h]
  float v35; // [esp+54h] [ebp-Ch]
  float v36; // [esp+58h] [ebp-8h]

  *(float *)&v1 = COERCE_FLOAT(sub_849AE0());
  v30 = *(float *)&v1;
  v2 = 2 * sub_849AF0();
  v28 = *(float *)&v2;
  sub_7BD3F0(0, &flt_25D5EF4);
  sub_7BD3F0(1, &flt_25D5EE4);
  result = *(_DWORD *)&word_23CBC10;
  v27 = flt_25D5EF4 - flt_25D5EE4;
  v31 = unk_25D5EF8 - unk_25D5EE8;
  v26 = unk_25D5EFC - unk_25D5EEC;
  if ( (word_23CBC10 & 0x100) != 0 && (word_23CBC10 & 1) != 0 )
  {
    result = unk_25D5F90;
    if ( !dword_25D5F64[unk_25D5F90] )
    {
      if ( !unk_25D5F2B )
      {
        sub_7BD3F0(0, &flt_25D5F14);
        result = sub_7BD3F0(1, &flt_25D5F04);
        word_25D5F34 = v1;
        word_25D5F36 = v2;
      }
      n256_1 = 256;
      unk_25D5F29 = 0;
    }
  }
  v4 = 1.0;
  if ( (word_23CBC10 & 2) == 0 || unk_25D5F2B )
    goto LABEL_20;
  dword_25D5F64[unk_25D5F90] = 0;
  v5 = (_DWORD *)dword_25D5F44[unk_25D5F90];
  v6 = (float *)dword_25D5F54[unk_25D5F90];
  v29 = *(float *)&dword_25D5F4C[unk_25D5F90];
  v7 = v29;
  v8 = 0;
  if ( SLODWORD(v29) <= 0 )
    goto LABEL_15;
  while ( !*v5 )
  {
LABEL_14:
    ++v8;
    v6 += 4;
    v5 += 3;
    if ( v8 >= SLODWORD(v7) )
      goto LABEL_15;
  }
  v33 = *v6;
  v34 = v6[1];
  v35 = v6[2];
  v36 = v4;
  sub_93FD60(&v33, v32);
  if ( (int)abs32(LODWORD(v30) - v32[0]) >= 8 || (int)abs32(LODWORD(v28) - v32[1]) >= 8 )
  {
    v7 = v29;
    v4 = 1.0;
    goto LABEL_14;
  }
  dword_25D5F64[unk_25D5F90] = v5;
  *((_DWORD *)&unk_25D5F6C + unk_25D5F90) = v6;
  result = unk_25D5F90;
  dword_25D5F74[unk_25D5F90] = v8;
  if ( (a1 & 0x40) != 0 )
  {
    *v5 |= 2u;
    unk_25D5F7C = v8;
    return result;
  }
LABEL_15:
  result = unk_25D5F90;
  v9 = unk_25D5F90;
  if ( dword_25D5F64[unk_25D5F90] )
  {
    unk_25D5F29 = 1;
    v10 = 0;
    unk_25D5F38 = **((float **)&unk_25D5F6C + unk_25D5F90);
    unk_25D5F3C = *(float *)(*((_DWORD *)&unk_25D5F6C + unk_25D5F90) + 4);
    result = *((_DWORD *)&unk_25D5F6C + unk_25D5F90);
    unk_25D5F40 = *(float *)(result + 8);
    if ( dword_25D5F4C[unk_25D5F90] > 0 )
    {
      v11 = 0;
      do
      {
        ++v10;
        *(float *)(v11 + dword_25D5F5C[v9]) = *(float *)(v11 + dword_25D5F54[v9]);
        v11 += 16;
        *(float *)(dword_25D5F5C[unk_25D5F90] + v11 - 12) = *(float *)(dword_25D5F54[unk_25D5F90] + v11 - 12);
        *(float *)(dword_25D5F5C[unk_25D5F90] + v11 - 8) = *(float *)(dword_25D5F54[unk_25D5F90] + v11 - 8);
        *(float *)(dword_25D5F5C[unk_25D5F90] + v11 - 4) = *(float *)(dword_25D5F54[unk_25D5F90] + v11 - 4);
        result = unk_25D5F90;
        v9 = unk_25D5F90;
      }
      while ( v10 < dword_25D5F4C[unk_25D5F90] );
    }
  }
  v4 = 1.0;
  *(float *)&v2 = v28;
  *(float *)&v1 = v30;
LABEL_20:
  if ( (a1 & 0x40) != 0 )
  {
    if ( (word_23CBC10 & 0x100) != 0 )
      result = sub_942320();
    unk_25D5F29 = 0;
    unk_25D5F2B = 0;
    return result;
  }
  if ( (word_23CBC10 & 4) != 0 )
  {
    unk_25D5F29 = 0;
    unk_25D5F2B = 0;
    dword_25D5F64[unk_25D5F90] = 0;
    *((_DWORD *)&unk_25D5F6C + unk_25D5F90) = 0;
  }
  if ( (word_23CBC10 & 0x400) != 0 )
  {
    n256_1 = 0;
    dword_25D5F64[unk_25D5F90] = 0;
    *((_DWORD *)&unk_25D5F6C + unk_25D5F90) = 0;
    dword_25D5F74[unk_25D5F90] = 0;
  }
  if ( !unk_25D5F29 )
  {
LABEL_32:
    if ( !unk_25D5F2B )
      goto LABEL_34;
LABEL_33:
    v31 = (float)(int)((v2 - word_25D5F36) * abs32(v2 - word_25D5F36));
    v31 = v31 / 100.0;
    flt_25D5EF4 = flt_25D5F14;
    unk_25D5EF8 = unk_25D5F18 - v31;
    unk_25D5EFC = unk_25D5F1C;
    flt_25D5EE4 = flt_25D5F04;
    unk_25D5EE8 = unk_25D5F08 - v31;
    unk_25D5EEC = unk_25D5F0C;
    FFX_BtlPool_WriteEntryTransform(SLODWORD(flt_25D5EE0), 0, (int)&flt_25D5EF4);
    FFX_BtlPool_WriteEntryTransform(SLODWORD(flt_25D5EE0), 1, (int)&flt_25D5EE4);
    goto LABEL_34;
  }
  if ( unk_25D5F2B )
    goto LABEL_33;
  if ( dword_25D5F64[unk_25D5F90] )
  {
    v33 = unk_25D5F38;
    v34 = unk_25D5F3C;
    v35 = unk_25D5F40;
    v36 = v4;
    v25[0] = v27;
    v25[1] = v31;
    v25[2] = v26;
    v12 = sub_7C0430();
    sub_940F30(v1, v2, v12, &v33, v25);
    **((float **)&unk_25D5F6C + unk_25D5F90) = v33;
    *(float *)(*((_DWORD *)&unk_25D5F6C + unk_25D5F90) + 4) = v34;
    *(float *)(*((_DWORD *)&unk_25D5F6C + unk_25D5F90) + 8) = v35;
    if ( unk_25D5F8C == 1 )
    {
      v13 = 0;
      v14 = unk_25D5F90;
      v27 = v33 - unk_25D5F38;
      v31 = v34 - unk_25D5F3C;
      v26 = v35 - unk_25D5F40;
      if ( dword_25D5F4C[unk_25D5F90] > 0 )
      {
        v15 = v31;
        v16 = 0;
        do
        {
          ++v13;
          v17 = dword_25D5F54[v14];
          v18 = *(float *)(dword_25D5F5C[v14] + v16) + v27;
          v16 += 16;
          v31 = v18;
          *(float *)(v16 + v17 - 16) = v31;
          v19 = dword_25D5F54[unk_25D5F90];
          v31 = *(float *)(dword_25D5F5C[unk_25D5F90] + v16 - 12) + v15;
          *(float *)(v19 + v16 - 12) = v31;
          v20 = dword_25D5F54[unk_25D5F90];
          v31 = *(float *)(dword_25D5F5C[unk_25D5F90] + v16 - 8) + v26;
          *(float *)(v20 + v16 - 8) = v31;
          *(float *)(dword_25D5F54[unk_25D5F90] + v16 - 4) = *(float *)(dword_25D5F5C[unk_25D5F90] + v16 - 4);
          v14 = unk_25D5F90;
        }
        while ( v13 < dword_25D5F4C[unk_25D5F90] );
      }
    }
    goto LABEL_32;
  }
LABEL_34:
  if ( !dword_25D5F64[unk_25D5F90] && !unk_25D5F2B )
  {
    if ( (word_23CBC10 & 2) != 0 )
    {
      sub_7BD250(&flt_25D5F80, &flt_25D5F84, &flt_25D5F88);
      if ( 0.0 != v27 || v26 != 0.0 )
        flt_25D5F84 = flt_25D5F84 + 3.141592741012573;
      word_25D5F34 = v1;
      word_25D5F36 = v2;
      unk_25D5F29 = 1;
LABEL_45:
      LODWORD(v31) = v2 - word_25D5F36;
      v31 = (float)SLODWORD(v31);
      v31 = v31 / 400.0 + flt_25D5F84;
      v21 = v31;
      LODWORD(v31) = v1 - word_25D5F34;
      v24 = v21;
      v31 = (float)SLODWORD(v31);
      v31 = flt_25D5F80 - v31 / 400.0;
      sub_7BF680(SLODWORD(flt_25D5EE0), 1, v31, v24, flt_25D5F88);
    }
    else if ( unk_25D5F29 )
    {
      goto LABEL_45;
    }
  }
  result = unk_25D5F90;
  if ( !dword_25D5F64[unk_25D5F90] && !unk_25D5F2B )
  {
    if ( (word_23CBC10 & 0x200) != 0 )
    {
      word_25D5F34 = v1;
      word_25D5F36 = v2;
      sub_7BD3F0(0, &flt_25D5F14);
      sub_7BD3F0(1, &flt_25D5F04);
      n256_1 = 1;
      goto LABEL_51;
    }
    if ( n256_1 )
    {
LABEL_51:
      v27 = flt_25D5F14 - flt_25D5F04;
      LODWORD(v29) = v1 - word_25D5F34;
      LODWORD(v31) = v2 - word_25D5F36;
      v26 = unk_25D5F1C - unk_25D5F0C;
      v30 = sqrt(v26 * v26 + v27 * v27);
      if ( v30 > 10.0 )
      {
        v31 = (float)SLODWORD(v31);
        v30 = v31;
        v31 = (float)SLODWORD(v29);
        v29 = v31;
        v23 = v30;
        v31 = v30 * v27;
        v30 = v31 - v29 * v26;
        v31 = v26 * v23;
        v28 = v31 + v27 * v29;
        v30 = v30 * fabs(v30) / 400000.0;
        v22 = v28 * fabs(v28) / 400000.0;
      }
      else
      {
        v29 = (float)SLODWORD(v29);
        v30 = -v29 / 10.0;
        v31 = (float)SLODWORD(v31);
        v22 = v31 / 10.0;
      }
      v28 = v22;
      flt_25D5EF4 = flt_25D5F14 + v30;
      unk_25D5EF8 = unk_25D5F18;
      unk_25D5EFC = unk_25D5F1C + v28;
      flt_25D5EE4 = v30 + flt_25D5F04;
      unk_25D5EE8 = unk_25D5F08;
      unk_25D5EEC = v28 + unk_25D5F0C;
      FFX_BtlPool_WriteEntryTransform(SLODWORD(flt_25D5EE0), 0, (int)&flt_25D5EF4);
      return FFX_BtlPool_WriteEntryTransform(SLODWORD(flt_25D5EE0), 1, (int)&flt_25D5EE4);
    }
  }
  return result;
}
