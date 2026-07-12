// Function: sub_8154A0
// Address: 0x8154a0
int __cdecl sub_8154A0(int a1, int a2)
{
  int v2; // edi
  int v3; // eax
  float v4; // eax
  int n1065353216; // ecx

  v2 = *(_DWORD *)(a1 + 544);
  v3 = sub_800F80((_DWORD *)(a1 + 768), v2, *(_WORD *)(v2 + 160));
  *(float *)a1 = *(float *)(v2 + 164);
  *(float *)(a1 + 4) = *(float *)(v2 + 68);
  *(float *)(a1 + 8) = *(float *)(v2 + 72);
  n1065353216 = 998244352;
  unk_C8F52C = 0;
  unk_C8F8D0[0] = *(float *)(v2 + 64);
  unk_C8F8D4 = *(float *)(v2 + 68);
  unk_C8F8D8 = *(float *)(v2 + 72);
  unk_C8F8DC[0] = *(float *)(v2 + 76);
  unk_C8F8F0[0] = *(float *)a1;
  flt_C8F8F4 = *(float *)(a1 + 4);
  flt_C8F8F8 = *(float *)(a1 + 8);
  flt_C8F8FC = *(float *)(a1 + 12);
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
  unk_C8F52C = LODWORD(flt_C8F974);
  flt_C8F978 = flt_C8F978 + flt_C8F8F8;
  n1065353216_2 = LODWORD(flt_C8F978);
  n1065353216_3 = LODWORD(flt_C8F97C);
  *(float *)(dword_C8B500 + v2 + 144) = flt_C8F970;
  *(_DWORD *)(dword_C8B500 + v2 + 148) = unk_C8F52C;
  n1065353216 = n1065353216_2;
  n1065353216_2 = n1065353216_3;
  unk_C8F52C = LODWORD(word_C8F510);
  n1065353216_3 = LODWORD(word_C8F514[0]);
  n1065353216 = n1065353216;
  *(_DWORD *)(v2 + 152) = n1065353216;
  dword_C8B500 = 0;
  return a2;
}
