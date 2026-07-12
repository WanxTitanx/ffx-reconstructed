// Function: sub_80ECB0
// Address: 0x80ecb0
void __cdecl sub_80ECB0(float *a1)
{
  int **v1; // esi
  float *v2; // edi
  float v3; // eax
  float v4; // eax
  double v5; // st7
  int i; // esi
  int n16; // eax
  bool v8; // cf
  int **v9; // ebx
  int v10; // edi
  int *v11; // ebx
  int v12; // esi
  int v13; // eax
  int v14; // esi
  int *v15; // esi
  _DWORD *v16; // [esp+10h] [ebp-11Ch]
  int *v17; // [esp+14h] [ebp-118h]
  int v18; // [esp+1Ch] [ebp-110h]
  int v19; // [esp+20h] [ebp-10Ch]
  int **v20; // [esp+24h] [ebp-108h]
  int v21; // [esp+28h] [ebp-104h]
  int *v22; // [esp+2Ch] [ebp-100h]
  int v23; // [esp+30h] [ebp-FCh]
  float v24; // [esp+30h] [ebp-FCh]
  int v25; // [esp+34h] [ebp-F8h]
  int v26; // [esp+34h] [ebp-F8h]
  int v27; // [esp+34h] [ebp-F8h]
  _DWORD v28[4]; // [esp+38h] [ebp-F4h]
  _BYTE v29[64]; // [esp+48h] [ebp-E4h] BYREF
  _BYTE v30[64]; // [esp+88h] [ebp-A4h] BYREF
  float v31[5]; // [esp+C8h] [ebp-64h] BYREF
  float v32; // [esp+DCh] [ebp-50h]
  float v33; // [esp+F0h] [ebp-3Ch]
  _WORD v34[16]; // [esp+108h] [ebp-24h] BYREF

  v1 = *(int ***)(*((_DWORD *)a1 + 136) + 188);
  v18 = *((_DWORD *)a1 + 136);
  v20 = v1;
  v21 = **v1;
  v19 = *v1[1];
  if ( sub_82ACD0(v21) )
    *((_BYTE *)v1 + 16) = 0;
  else
    *((_BYTE *)v1 + 16) = 1;
  v22 = (int *)(v1 + 72);
  v2 = (float *)(v1 + 72);
  v25 = 0;
  if ( *((_WORD *)v1 + 7) )
  {
    do
    {
      v3 = *v2;
      v23 = *(_DWORD *)v2;
      if ( *((_BYTE *)v1 + 16) )
        *(float *)(LODWORD(v3) + 52) = v2[7];
      else
        v2[7] = *(float *)(LODWORD(v3) + 52);
      sub_805350((_DWORD *)a1 + 32, **v1, *((unsigned __int16 *)v2 + 3));
      n1065353216 = *((_DWORD *)a1 + 44);
      unk_C8F52C = *((_DWORD *)a1 + 45);
      unk_C8F530 = *((_DWORD *)a1 + 46);
      unk_C8F534 = *((_DWORD *)a1 + 47);
      a1[28] = a1[44];
      a1[29] = a1[45];
      a1[30] = a1[46];
      a1[31] = a1[47];
      sub_7EA5E0(a1 + 32);
      n1065353216 = *((_DWORD *)a1 + 28);
      unk_C8F52C = *((_DWORD *)a1 + 29);
      unk_C8F530 = *((_DWORD *)a1 + 30);
      unk_C8F534 = *((_DWORD *)a1 + 31);
      a1[44] = a1[28];
      a1[45] = a1[29];
      a1[46] = a1[30];
      a1[47] = a1[31];
      ((void (__cdecl *)(_DWORD, _DWORD, _DWORD))sub_7EA760)(a1 + 16, v2 + 4, v2[7]);
      a1[20] = *(float *)word_C8F508;
      a1[21] = word_C8F50C;
      a1[22] = word_C8F510;
      a1[23] = word_C8F514[0];
      v24 = *(float *)(v23 + 60) * 0.00390625;
      sub_7EA610(a1, v24);
      sub_7E9760(a1 + 48, a1, a1 + 16, a1 + 20);
      sub_7E82C0(v2 + 8, a1 + 32, a1 + 48);
      v2 += 24;
      ++v25;
    }
    while ( v25 < *((unsigned __int16 *)v1 + 7) );
  }
  if ( (sub_82AC50(**v1) & 0xFFFFFFF7) == 0 && sub_82EC20(v21, -1) > 0.0 )
  {
    sub_831440(**v1, -1, 15360);
    sub_831410(**v1, -1, 12000);
    sub_831380(**v1, -1);
    sub_831250(**v1, -1);
    sub_82EB70(v21, a1, a1 + 1, a1 + 2);
    a1[3] = sub_82EC20(v21, -1);
    sub_7EA800(a1, a1, 128.0);
    unk_C8F980[0] = *a1;
    flt_C8F984 = a1[1];
    flt_C8F988 = a1[2];
    v4 = a1[3];
    flt_C8F970 = flt_C0A004 - flt_C0A004;
    flt_C8F98C[0] = v4;
    n1065353216 = 1132396544;
    unk_C8F78C[0] = 255.0;
    flt_C8F974 = *(float *)&dword_C0A008 - *(float *)&dword_C0A008;
    flt_C8F978 = *(float *)&dword_C0A00C - *(float *)&dword_C0A00C;
    flt_C8F97C = flt_C0A010 - flt_C0A010;
    sub_42EF00();
    v5 = unk_C8F78C[0];
    if ( unk_C8F78C[0] <= (double)unk_C8F980[0] )
      unk_C8F980[0] = unk_C8F78C[0];
    if ( flt_C8F984 >= v5 )
      flt_C8F984 = unk_C8F78C[0];
    if ( flt_C8F988 >= v5 )
      flt_C8F988 = unk_C8F78C[0];
    if ( flt_C8F98C[0] >= v5 )
      flt_C8F98C[0] = unk_C8F78C[0];
    sub_808CE0(
      unk_C8F980,
      unk_C8F980,
      LODWORD(flt_C8F970),
      LODWORD(flt_C8F974),
      LODWORD(flt_C8F978),
      LODWORD(flt_C8F97C));
    *(float *)v28 = unk_C8F980[0];
    *(float *)&v28[1] = flt_C8F984;
    *(float *)&v28[2] = flt_C8F988;
    *(float *)&v28[3] = flt_C8F98C[0];
    for ( i = 0; i < 4; ++i )
      LODWORD(unk_C8F980[i]) = (int)*(float *)&v28[i];
    LOWORD(n1065353216) = LOWORD(unk_C8F980[0]);
    unk_C8F52A = LOWORD(flt_C8F984);
    LOWORD(unk_C8F52C) = LOWORD(flt_C8F988);
    unk_C8F52E = LOWORD(flt_C8F98C[0]);
    LOWORD(unk_C8F530) = word_C8F508[0];
    unk_C8F532 = LOWORD(word_C8F50C);
    unk_C8F534 = LOWORD(word_C8F510);
    unk_C8F536 = LOWORD(word_C8F514[0]);
    sub_737690(&n1065353216, word_C8F508, &n1065353216);
    *(_DWORD *)(v18 + 200) = n1065353216;
    n16 = 0;
    v8 = 1;
    do
    {
      if ( !v8 )
        __report_rangecheckfailure();
      v34[n16++] = 0;
      v8 = (unsigned int)n16 < 16;
    }
    while ( n16 < 16 );
    v9 = v20;
    v17 = v20[2];
    v10 = 0;
    v26 = sub_830490(v19);
    if ( v26 > 0 )
    {
      v11 = v17 + 4;
      do
      {
        v12 = unknown_libname_741(*v11);
        *(_DWORD *)(v12 + 8) = sub_82AE90(v19, v10) - v12;
        v13 = sub_82AE70(v19, v10++);
        *(_DWORD *)(v12 + 12) = v13 - v12;
        v11 += 4;
      }
      while ( v10 < v26 );
      v9 = v20;
    }
    sub_805320((int)v29, v21);
    sub_6EDAE0(v31);
    v27 = 0;
    v31[0] = v31[0] * 1000.0;
    v32 = v32 * 1000.0;
    v33 = 1000.0 * v33;
    if ( *((_WORD *)v9 + 7) )
    {
      v16 = a1 + 64;
      do
      {
        v14 = *v22;
        sub_80E390(v16, a1, a1 + 192, *v22, -1);
        sub_80EA60((int)v16, (int)a1, (_DWORD *)a1 + 192, v14, (int)v34);
        *v16 = 540;
        a1[70] = *(float *)(v18 + 200);
        a1[71] = 0.0;
        *((_WORD *)a1 + 166) = 128;
        v15 = &v17[4 * *((unsigned __int16 *)v22 + 2) + 4];
        *((_DWORD *)a1 + 72) = a1 + 48;
        *((_DWORD *)a1 + 75) = a1 + 32;
        sub_7E82C0(a1 + 48, v29, v22 + 8);
        sub_6ED700(v30, a1 + 48, v31);
        sub_639320(*(_DWORD *)(v21 + 2096), v30, *((unsigned __int16 *)v15 + 5));
        FFX_Model_SetHideFlag(v21, *((unsigned __int16 *)v15 + 5), 0);
        v22 += 24;
        ++v27;
      }
      while ( v27 < *((unsigned __int16 *)v20 + 7) );
    }
  }
}
