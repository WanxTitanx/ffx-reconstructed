// Function: sub_8188F0
// Address: 0x8188f0
int __cdecl sub_8188F0(int a1, int a2)
{
  float *v2; // ebx
  int v3; // eax
  float v4; // eax
  int n1065353216; // ecx
  int n1065353216_1; // eax
  __int16 v8; // [esp-10h] [ebp-34h]
  int v9; // [esp+20h] [ebp-4h]

  v9 = *(_DWORD *)(a1 + 544);
  v8 = *(_WORD *)(a2 + 4);
  v2 = (float *)sub_800F80((_DWORD *)(a1 + 768), v9, *(_WORD *)(a2 + 2));
  v3 = sub_800F80((_DWORD *)(a1 + 768), v9, v8);
  *(_QWORD *)&n1065353216 = 998244352;
  unk_C8F8D0[0] = *(float *)(v9 + 64);
  unk_C8F8D4 = *(float *)(v9 + 68);
  unk_C8F8D8 = *(float *)(v9 + 72);
  unk_C8F8DC[0] = *(float *)(v9 + 76);
  unk_C8F8F0[0] = v2[36];
  flt_C8F8F4 = v2[37];
  flt_C8F8F8 = v2[38];
  flt_C8F8FC = v2[39];
  flt_C8F900 = *(float *)(v3 + 144);
  flt_C8F904 = *(float *)(v3 + 148);
  flt_C8F908 = *(float *)(v3 + 152);
  v4 = *(float *)(v3 + 156);
  flt_C8F970 = flt_C8F900 - unk_C8F8F0[0];
  flt_C8F90C = v4;
  LODWORD(flt_C8F988) = n1065353216_2;
  flt_C8F974 = flt_C8F904 - flt_C8F8F4;
  word_C8F980[0] = 0.00390625;
  flt_C8F984 = 0.0;
  LODWORD(flt_C8F98C[0]) = n1065353216_3;
  flt_C8F978 = flt_C8F908 - flt_C8F8F8;
  sub_42EF00();
  flt_C8F970 = unk_C8F8D0[0] * flt_C8F970;
  flt_C8F974 = unk_C8F8D0[0] * flt_C8F974;
  flt_C8F978 = unk_C8F8D0[0] * flt_C8F978;
  flt_C8F970 = word_C8F980[0] * flt_C8F970;
  flt_C8F974 = word_C8F980[0] * flt_C8F974;
  flt_C8F978 = word_C8F980[0] * flt_C8F978;
  flt_C8F970 = flt_C8F970 + unk_C8F8F0[0];
  flt_C8F974 = flt_C8F974 + flt_C8F8F4;
  *(&n1065353216 + 1) = LODWORD(flt_C8F974);
  flt_C8F978 = flt_C8F978 + flt_C8F8F8;
  n1065353216_2 = LODWORD(flt_C8F978);
  n1065353216_3 = LODWORD(flt_C8F97C);
  *(float *)(dword_C8B500 + v9 + 144) = flt_C8F970;
  *(_DWORD *)(dword_C8B500 + v9 + 148) = *(&n1065353216 + 1);
  n1065353216 = n1065353216_2;
  n1065353216_1 = n1065353216_3;
  n1065353216_3 = LODWORD(word_C8F514[0]);
  n1065353216_2 = n1065353216_1;
  *(&n1065353216 + 1) = LODWORD(word_C8F510);
  n1065353216 = n1065353216;
  *(_DWORD *)(v9 + 152) = n1065353216;
  dword_C8B500 = 0;
  return a2 + 6;
}
