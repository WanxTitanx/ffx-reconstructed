// Function: FFX_MagicPostProc_06_LerpBetweenRecordTransforms
// Address: 0x815270
int __cdecl FFX_MagicPostProc_06_LerpBetweenRecordTransforms(int a1, int a2)
{
  int v2; // edx
  float *v3; // ebx
  int v4; // eax
  float v5; // eax
  __int16 v7; // [esp-10h] [ebp-20h]
  int v8; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 544);
  v8 = v2;
  v7 = *(_WORD *)(v2 + 162);
  v3 = (float *)sub_800F80((_DWORD *)(a1 + 768), v2, *(_WORD *)(v2 + 160));
  v4 = sub_800F80((_DWORD *)(a1 + 768), v8, v7);
  n1065353216 = 998244352;
  unk_C8F8D0[0] = *(float *)(v8 + 64);
  unk_C8F8D4 = *(float *)(v8 + 68);
  unk_C8F8D8 = *(float *)(v8 + 72);
  unk_C8F8DC[0] = *(float *)(v8 + 76);
  unk_C8F8F0[0] = v3[36];
  flt_C8F8F4 = v3[37];
  flt_C8F8F8 = v3[38];
  flt_C8F8FC = v3[39];
  flt_C8F900 = *(float *)(v4 + 144);
  flt_C8F904 = *(float *)(v4 + 148);
  flt_C8F908 = *(float *)(v4 + 152);
  v5 = *(float *)(v4 + 156);
  flt_C8F970 = flt_C8F900 - unk_C8F8F0[0];
  flt_C8F90C = v5;
  LODWORD(flt_C8F984) = unk_C8F52C;
  flt_C8F974 = flt_C8F904 - flt_C8F8F4;
  LODWORD(flt_C8F988) = unk_C8F530;
  word_C8F980[0] = 0.00390625;
  LODWORD(flt_C8F98C[0]) = unk_C8F534;
  flt_C8F978 = flt_C8F908 - flt_C8F8F8;
  sub_42EF00();
  flt_C8F970 = unk_C8F8D0[0] * flt_C8F970;
  flt_C8F974 = unk_C8F8D0[0] * flt_C8F974;
  flt_C8F978 = unk_C8F8D0[0] * flt_C8F978;
  flt_C8F970 = word_C8F980[0] * flt_C8F970;
  flt_C8F974 = word_C8F980[0] * flt_C8F974;
  flt_C8F978 = word_C8F980[0] * flt_C8F978;
  flt_C8F970 = flt_C8F970 + unk_C8F8F0[0];
  n1065353216 = LODWORD(flt_C8F970);
  flt_C8F974 = flt_C8F974 + flt_C8F8F4;
  unk_C8F52C = LODWORD(flt_C8F974);
  flt_C8F978 = flt_C8F978 + flt_C8F8F8;
  unk_C8F530 = LODWORD(flt_C8F978);
  unk_C8F534 = LODWORD(flt_C8F97C);
  *(float *)(dword_C8B500 + v8 + 144) = flt_C8F970;
  *(_DWORD *)(dword_C8B500 + v8 + 148) = unk_C8F52C;
  dword_C8B500 = 0;
  *(_DWORD *)(v8 + 152) = unk_C8F530;
  return a2;
}
