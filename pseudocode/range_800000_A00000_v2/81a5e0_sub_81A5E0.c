// Function: sub_81A5E0
// Address: 0x81a5e0
int __cdecl sub_81A5E0(int a1, _WORD *a2)
{
  int *v2; // eax
  __int16 v3; // si
  __int16 v4; // di
  double v5; // st7
  __int16 v6; // di
  float v7; // eax
  float n1065353216_1; // eax
  bool v9; // zf
  int n1065353216_8; // ebx
  double v11; // st7
  double n1065353216_4; // st6
  double n1065353216_5; // st5
  int n1065353216_7; // eax
  double v15; // st7
  float v16; // eax
  int v18; // [esp+Ch] [ebp-50h]
  int v19; // [esp+10h] [ebp-4Ch]
  int v20; // [esp+14h] [ebp-48h]
  int v21; // [esp+1Ch] [ebp-40h]
  float v22; // [esp+1Ch] [ebp-40h]
  __int16 v23; // [esp+20h] [ebp-3Ch]
  __int16 v24; // [esp+20h] [ebp-3Ch]
  float *v25; // [esp+28h] [ebp-34h]
  float v26; // [esp+2Ch] [ebp-30h]
  float v27; // [esp+2Ch] [ebp-30h]
  float v28; // [esp+2Ch] [ebp-30h]
  float v29; // [esp+2Ch] [ebp-30h]
  float v30; // [esp+30h] [ebp-2Ch]
  float v31; // [esp+30h] [ebp-2Ch]
  int n1065353216; // [esp+30h] [ebp-2Ch]
  float v33; // [esp+30h] [ebp-2Ch]
  int v34; // [esp+34h] [ebp-28h]
  float v35; // [esp+34h] [ebp-28h]
  float v36; // [esp+34h] [ebp-28h]
  float v37; // [esp+34h] [ebp-28h]
  float v38; // [esp+34h] [ebp-28h]
  float v39; // [esp+48h] [ebp-14h]
  float v40; // [esp+48h] [ebp-14h]
  float n1065353216_2; // [esp+48h] [ebp-14h]
  float v42; // [esp+48h] [ebp-14h]
  float n1065353216_3; // [esp+48h] [ebp-14h]
  float n1065353216_6; // [esp+48h] [ebp-14h]
  int v45; // [esp+54h] [ebp-8h]

  v23 = *(_WORD *)(a1 + 538);
  v2 = (int *)((char *)&unk_C49398 + 16 * (__int16)((v23 & 0x1FF) - 18));
  v19 = *v2;
  v20 = v2[1];
  v34 = v2[3];
  v18 = *(_DWORD *)(a1 + 544);
  v21 = v2[2];
  v25 = (float *)(v18 + word_C49388[(__int16)((v23 & 0x1FF) - 18)]);
  unk_C8F568 = a2 + 1;
  if ( unk_C8F728 )
    LODWORD(v26) = (2 * (dword_C0A000 & 0x3FFFFF | 0x1FC00000))
                 | ((dword_C0A000 ^ ((unsigned int)dword_C0A000 >> 18)) >> 4) & 1;
  else
    v26 = 1.0;
  unk_C8F728 = 1;
  v30 = v26 * 2.0 - 3.0;
  n1065353216 = LODWORD(v30);
  flt_C8F970 = v30;
  *(float *)&dword_C0A000 = v26 - 1.887241363525391;
  LODWORD(v27) = (2 * (dword_C0A000 & 0x3FFFFF | 0x1FC00000))
               | ((dword_C0A000 ^ ((unsigned int)dword_C0A000 >> 18)) >> 4) & 1;
  v31 = v27 * 2.0 - 3.0;
  *(&n1065353216 + 1) = LODWORD(v31);
  flt_C8F974 = v31;
  *(float *)&dword_C0A000 = v27 - 1.887241363525391;
  LODWORD(v28) = (2 * (dword_C0A000 & 0x3FFFFF | 0x1FC00000))
               | ((dword_C0A000 ^ ((unsigned int)dword_C0A000 >> 18)) >> 4) & 1;
  *(float *)&n1065353216 = v28 * 2.0 - 3.0;
  n1065353216_2 = n1065353216;
  LODWORD(flt_C8F978) = n1065353216;
  *(float *)&dword_C0A000 = v28 - 1.887241363525391;
  LODWORD(v29) = (2 * (dword_C0A000 & 0x3FFFFF | 0x1FC00000))
               | ((dword_C0A000 ^ ((unsigned int)dword_C0A000 >> 18)) >> 4) & 1;
  v33 = 2.0 * v29 - 3.0;
  n1065353216_3 = LODWORD(v33);
  flt_C8F97C = v33;
  *(float *)&dword_C0A000 = v29 - 1.887241363525391;
  LOWORD(n1065353216) = a2[1];
  n1065353216 = (unsigned __int16)n1065353216;
  *((_WORD *)&n1065353216 + 2) = a2[2];
  *(&n1065353216 + 1) = *((unsigned __int16 *)&n1065353216 + 2);
  v3 = a2[3];
  unk_C8F532 = 0;
  LOWORD(n1065353216_2) = v3;
  v4 = a2[4];
  n1065353216 = (__int16)n1065353216 * (__int16)v19;
  *(&n1065353216 + 1) = (__int16)v20 * *((__int16 *)&n1065353216 + 2);
  n1065353216_2 = (__int16)v21 * v3;
  n1065353216_3 = (__int16)v34 * v4;
  v45 = (__int16)v34 * v4;
  v35 = (float)(int)n1065353216;
  *(float *)&n964689920 = v35 * 0.000244140625;
  v36 = (float)(int)*(&n1065353216 + 1);
  *((float *)&n964689920 + 1) = v36 * 0.000244140625;
  v37 = (float)((__int16)v21 * v3);
  flt_C8F988 = v37 * 0.000244140625;
  v38 = (float)v45;
  flt_C8F98C[0] = 0.000244140625 * v38;
  *(float *)&n964689920 = flt_C8F970 * *(float *)&n964689920;
  *((float *)&n964689920 + 1) = flt_C8F974 * *((float *)&n964689920 + 1);
  flt_C8F988 = flt_C8F978 * flt_C8F988;
  flt_C8F98C[0] = v33 * flt_C8F98C[0];
  v22 = *v25;
  flt_C8F960 = *v25;
  flt_C8F964 = v25[1];
  v5 = *(float *)&n964689920;
  v6 = v23;
  flt_C8F968 = v25[2];
  v7 = v25[3];
  flt_C8F930 = *(float *)&n964689920;
  flt_C8F96C = v7;
  unk_C8F934 = *((float *)&n964689920 + 1);
  n1065353216_1 = 0.0;
  unk_C8F938 = flt_C8F988;
  v9 = (v23 & 0x1000) == 0;
  unk_C8F93C = flt_C8F98C[0];
  v24 = v23 & 0x1000;
  if ( v9 )
  {
    n1065353216_8 = (int)(a2 + 1);
  }
  else
  {
    *(float *)&qword_C8F950 = *(float *)&n964689920;
    n1065353216_8 = (int)(a2 + 2);
    v39 = *(float *)&n964689920;
    *(float *)&n964689920 = *((float *)&n964689920 + 1);
    *((float *)&n964689920 + 1) = flt_C8F988;
    n1065353216_1 = *(float *)&qword_C8F950;
    flt_C8F988 = flt_C8F98C[0];
    flt_C8F98C[0] = v39;
    v5 = *(float *)&n964689920;
  }
  *(float *)&qword_C8F950 = 0.0;
  *((float *)&qword_C8F950 + 1) = 0.0;
  n1065353216_5 = 0.0;
  n1065353216_6 = n1065353216_1;
  if ( (v6 & 0x2000) != 0 )
  {
    *(float *)&qword_C8F950 = v5;
    v40 = *(float *)&n964689920;
    *(float *)&n964689920 = *((float *)&n964689920 + 1);
    *((float *)&n964689920 + 1) = flt_C8F988;
    flt_C8F988 = flt_C8F98C[0];
    n1065353216_8 += 2;
    flt_C8F98C[0] = v40;
    v5 = *(float *)&n964689920;
  }
  n1065353216_2 = *(float *)&qword_C8F950;
  *(float *)&qword_C8F950 = *((float *)&qword_C8F950 + 1);
  *((float *)&qword_C8F950 + 1) = n1065353216_5;
  n1065353216_5 = n1065353216_6;
  n1065353216_6 = n1065353216_2;
  if ( (v6 & 0x4000) != 0 )
  {
    *(float *)&qword_C8F950 = v5;
    v42 = *(float *)&n964689920;
    *(float *)&n964689920 = *((float *)&n964689920 + 1);
    *((float *)&n964689920 + 1) = flt_C8F988;
    flt_C8F988 = flt_C8F98C[0];
    n1065353216_8 += 2;
    flt_C8F98C[0] = v42;
    v5 = *(float *)&n964689920;
  }
  n1065353216_3 = *(float *)&qword_C8F950;
  *(float *)&qword_C8F950 = *((float *)&qword_C8F950 + 1);
  *((float *)&qword_C8F950 + 1) = n1065353216_5;
  n1065353216_5 = n1065353216_6;
  n1065353216_6 = n1065353216_3;
  if ( v6 < 0 )
  {
    *(float *)&qword_C8F950 = v5;
    n1065353216_8 += 2;
  }
  n1065353216_6 = *(float *)&qword_C8F950;
  v11 = *((float *)&qword_C8F950 + 1);
  *(float *)&qword_C8F950 = *((float *)&qword_C8F950 + 1);
  n1065353216_4 = n1065353216_5;
  *((float *)&qword_C8F950 + 1) = n1065353216_5;
  n1065353216_5 = n1065353216_6;
  n1065353216_5 = n1065353216_6;
  n1065353216_6 = n1065353216_6;
  if ( (v6 & 0x800) != 0 )
  {
    v15 = flt_C8F930;
    if ( v24 )
    {
      flt_C8F960 = v15 + flt_C8F960;
      v16 = flt_C8F960;
    }
    else
    {
      v16 = v22;
    }
    while ( (v6 & 0x2000) == 0 )
      ;
    flt_C8F964 = v15 + flt_C8F964;
    while ( (v6 & 0x4000) == 0 )
      ;
    flt_C8F968 = v15 + flt_C8F968;
    if ( v6 < 0 )
      flt_C8F96C = v15 + flt_C8F96C;
    *v25 = v16;
    v25[1] = flt_C8F964;
    v25[2] = flt_C8F968;
    v25[3] = flt_C8F96C;
    n1065353216_7 = unk_C8F568 + 2;
  }
  else
  {
    flt_C8F960 = v11 + flt_C8F960;
    flt_C8F964 = n1065353216_4 + flt_C8F964;
    flt_C8F968 = n1065353216_5 + flt_C8F968;
    flt_C8F96C = n1065353216_6 + flt_C8F96C;
    *v25 = flt_C8F960;
    v25[1] = flt_C8F964;
    v25[2] = flt_C8F968;
    v25[3] = flt_C8F96C;
    n1065353216_7 = n1065353216_8;
  }
  n1065353216 = n1065353216_7;
  unk_C8F548 = a1;
  if ( (v6 & 0x200) == 0 )
    return n1065353216_8;
  LODWORD(n1065353216_4) = n1065353216_7;
  *(_QWORD *)&n1065353216 = &g_FFX_MagicPostProcTable[*(unsigned __int8 *)(v18 + 186)];
  n1065353216 = *(_DWORD *)n1065353216;
  return g_FFX_MagicPostProcTable[*(unsigned __int8 *)(v18 + 186)](a1, n1065353216_8);
}
