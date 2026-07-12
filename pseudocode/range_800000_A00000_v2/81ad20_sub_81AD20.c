// Function: sub_81AD20
// Address: 0x81ad20
int __cdecl sub_81AD20(_DWORD *a1, int a2)
{
  float *v2; // edi
  int n0x2000; // eax
  float v4; // eax
  int n1065353216; // eax
  double v7; // st7
  double v8; // st7
  double v9; // st7
  float *v10; // edi
  int v11; // ecx
  float v12; // [esp+4h] [ebp-44h]
  float v13; // [esp+4h] [ebp-44h]
  float *v14; // [esp+14h] [ebp-34h]
  float v15; // [esp+20h] [ebp-28h]
  float v16; // [esp+24h] [ebp-24h]
  float v17; // [esp+24h] [ebp-24h]
  float v18; // [esp+2Ch] [ebp-1Ch]
  float v19; // [esp+2Ch] [ebp-1Ch]
  float v20; // [esp+2Ch] [ebp-1Ch]
  float v21; // [esp+30h] [ebp-18h]
  float v22; // [esp+30h] [ebp-18h]
  float v23; // [esp+30h] [ebp-18h]

  v2 = (float *)a1[136];
  v14 = v2;
  n0x2000 = *((_WORD *)a1 + 269) & 0xF000;
  if ( (*((_WORD *)a1 + 269) & 0xF000) != 0 )
  {
    if ( n0x2000 == 4096 )
    {
      v7 = v2[12];
      sub_7E6610(v2[12]);
      v21 = v7;
      *(float *)a1 = v2[16] + v21;
      v8 = v2[13];
      sub_7E6610(v2[13]);
      v22 = v8;
      *((float *)a1 + 1) = v2[17] + v22;
      v9 = v2[14];
      sub_7E6610(v2[14]);
      v23 = v9;
      *((float *)a1 + 2) = v2[18] + v23;
      sub_7EA760(v2 + 36, a1, 0.0625);
      return a2 + 2;
    }
    else if ( n0x2000 == 0x2000 )
    {
      v16 = (double)*(__int16 *)(a2 + 8) * 0.00390625;
      v18 = (double)*(__int16 *)(a2 + 10) * 0.00390625;
      v15 = 0.00390625 * (double)*(__int16 *)(a2 + 12);
      v12 = v16;
      v17 = (float)*(__int16 *)(a2 + 2);
      sub_7E6700(v17, v12);
      *(float *)a1 = v17;
      v13 = v18;
      v19 = (float)*(__int16 *)(a2 + 4);
      sub_7E6700(v19, v13);
      *((float *)a1 + 1) = v19;
      v20 = (float)*(__int16 *)(a2 + 6);
      sub_7E6700(v20, v15);
      *((float *)a1 + 2) = v20;
      sub_7E7AF0((int)a1, (int)a1, *(float *)((char *)v2 + *(unsigned __int16 *)(a2 + 14)));
      n964689920 = *((_QWORD *)v2 + 8);
      flt_C8F988 = v2[18];
      flt_C8F98C[0] = v2[19];
      flt_C8F970 = *(float *)a1;
      flt_C8F974 = *((float *)a1 + 1);
      flt_C8F978 = *((float *)a1 + 2);
      v4 = *((float *)a1 + 3);
      *(float *)&n964689920 = flt_C8F970 + *(float *)&n964689920;
      flt_C8F97C = v4;
      *((float *)&n964689920 + 1) = flt_C8F974 + *((float *)&n964689920 + 1);
      *(_QWORD *)&n1065353216 = n964689920;
      n1065353216_3 = LODWORD(flt_C8F98C[0]);
      flt_C8F988 = flt_C8F988 + flt_C8F978;
      n1065353216_2 = LODWORD(flt_C8F988);
      *(_DWORD *)((char *)v2 + dword_C8B500 + 64) = n964689920;
      *(float *)((char *)v2 + dword_C8B500 + 68) = *((float *)&n1065353216 + 1);
      n1065353216 = n1065353216;
      n1065353216 = n1065353216_2;
      n1065353216_2 = n1065353216;
      *((_DWORD *)v2 + 18) = n1065353216;
      dword_C8B500 = 0;
      sub_7EA760(v2 + 36, v2 + 16, 0.0625);
      return a2 + 16;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    sub_7EA5E0(a1);
    sub_7E6610(4096.0);
    *((float *)a1 + 32) = 4096.0;
    sub_7E6610(4096.0);
    *((float *)a1 + 33) = 4096.0;
    sub_7E6610(4096.0);
    v10 = v2 + 16;
    *((float *)a1 + 34) = 4096.0;
    sub_7E9760(a1, a1, a1 + 32, v10);
    v11 = *(_WORD *)(a2 + 2) & 0xF;
    a1[36] = word_C8F508[0];
    a1[37] = LODWORD(word_C8F50C);
    a1[38] = LODWORD(word_C8F510);
    a1[39] = LODWORD(word_C8F514[0]);
    *((float *)a1 + 38) = v14[v11 + 12];
    sub_7E78B0(v10, a1, a1 + 36);
    sub_7EA760(v14 + 36, v10, 0.0625);
    return a2 + 4;
  }
}
