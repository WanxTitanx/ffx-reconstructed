// Function: sub_819DD0
// Address: 0x819dd0
int __cdecl sub_819DD0(int a1, int a2)
{
  int v2; // ebx
  int v3; // esi
  int v4; // eax
  unsigned __int8 v5; // cl
  int v6; // edx
  double v7; // st7
  float v8; // eax
  int n1065353216; // edx
  int n1065353216_1; // ecx
  __int16 v12; // [esp-10h] [ebp-3Ch]
  __int16 v13; // [esp-10h] [ebp-3Ch]
  float v14; // [esp+1Ch] [ebp-10h]
  float *v15; // [esp+20h] [ebp-Ch]
  float v16; // [esp+24h] [ebp-8h]
  int v17; // [esp+28h] [ebp-4h]

  v2 = a2;
  v3 = *(_DWORD *)(a1 + 544);
  v17 = v3;
  if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
  {
    v13 = *(_WORD *)(a2 + 6);
    v3 = *(_DWORD *)(a1 + 544);
    v15 = (float *)sub_800F80((_DWORD *)(a1 + 768), v17, *(_WORD *)(a2 + 4));
    v6 = sub_800F80((_DWORD *)(a1 + 768), v17, v13);
    v16 = *(float *)(v17 + 4 * *(__int16 *)(a2 + 2) + 48);
    goto LABEL_7;
  }
  if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0x1000 )
  {
    v12 = *(_WORD *)(a2 + 4);
    v3 = *(_DWORD *)(a1 + 544);
    v15 = (float *)sub_800F80((_DWORD *)(a1 + 768), v17, *(_WORD *)(a2 + 2));
    v4 = sub_800F80((_DWORD *)(a1 + 768), v17, v12);
    v5 = *(_BYTE *)(a2 + 7);
    v6 = v4;
    v16 = *(float *)(*(unsigned __int8 *)(a2 + 6) + v17);
    if ( v5 )
    {
      v7 = *(float *)(v5 + v17) * 0.0625;
LABEL_8:
      v14 = v7;
      v2 = a2 + 8;
      goto LABEL_9;
    }
LABEL_7:
    v7 = 0.0;
    goto LABEL_8;
  }
  v6 = LODWORD(v16);
  v15 = (float *)LODWORD(v16);
LABEL_9:
  n3_11 = LODWORD(v16);
  *(_QWORD *)qword_C8F8D0 = __PAIR64__(*(&n3_11 + 1), LODWORD(v16));
  LODWORD(unk_C8F8D8) = unk_C8F540;
  LODWORD(unk_C8F8DC[0]) = unk_C8F544;
  LODWORD(flt_C8F8E4) = unk_C8F54C;
  LODWORD(flt_C8F8E8) = unk_C8F550;
  unk_C8F548 = LODWORD(v14);
  flt_C8F8E0 = v14;
  LODWORD(flt_C8F8EC) = unk_C8F554;
  *(_QWORD *)&n1065353216 = 964689920;
  unk_C8F8F0[0] = v15[36];
  flt_C8F8F4 = v15[37];
  flt_C8F8F8 = v15[38];
  flt_C8F8FC = v15[39];
  flt_C8F900 = *(float *)(v6 + 144);
  flt_C8F904 = *(float *)(v6 + 148);
  flt_C8F908 = *(float *)(v6 + 152);
  v8 = *(float *)(v6 + 156);
  flt_C8F970 = flt_C8F900 - unk_C8F8F0[0];
  flt_C8F90C = v8;
  LODWORD(flt_C8F988) = n1065353216_2;
  flt_C8F974 = flt_C8F904 - flt_C8F8F4;
  n964689920 = 964689920;
  LODWORD(flt_C8F98C[0]) = n1065353216_3;
  flt_C8F978 = flt_C8F908 - flt_C8F8F8;
  sub_42EF00();
  flt_C8F970 = qword_C8F8D0[0] * flt_C8F970;
  flt_C8F974 = qword_C8F8D0[0] * flt_C8F974;
  flt_C8F978 = qword_C8F8D0[0] * flt_C8F978;
  flt_C8F970 = *(float *)&n964689920 * flt_C8F970;
  flt_C8F974 = *(float *)&n964689920 * flt_C8F974;
  flt_C8F978 = *(float *)&n964689920 * flt_C8F978;
  flt_C8F970 = flt_C8F970 + unk_C8F8F0[0];
  flt_C8F974 = flt_C8F8F4 + flt_C8F974;
  flt_C8F978 = flt_C8F978 + flt_C8F8F8;
  flt_C8F974 = flt_C8F8E0 + flt_C8F974;
  *(&n1065353216 + 1) = LODWORD(flt_C8F974);
  n1065353216_2 = LODWORD(flt_C8F978);
  n1065353216_3 = LODWORD(flt_C8F97C);
  *(float *)(dword_C8B500 + v3 + 144) = flt_C8F970;
  *(_DWORD *)(dword_C8B500 + v3 + 148) = *(&n1065353216 + 1);
  n1065353216 = n1065353216_2;
  n1065353216_1 = n1065353216_3;
  *(&n1065353216 + 1) = LODWORD(word_C8F510);
  n1065353216_3 = LODWORD(word_C8F514[0]);
  n1065353216_2 = n1065353216_1;
  n1065353216 = n1065353216;
  *(_DWORD *)(v17 + 152) = n1065353216;
  dword_C8B500 = 0;
  return v2;
}
