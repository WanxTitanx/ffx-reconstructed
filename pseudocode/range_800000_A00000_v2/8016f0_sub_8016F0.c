// Function: sub_8016F0
// Address: 0x8016f0
int __cdecl sub_8016F0(int a1, int a2)
{
  __int16 v2; // si
  int v3; // ebx
  int v4; // eax
  float v5; // eax
  int v7; // [esp+18h] [ebp-18h]

  v2 = *(_WORD *)(a2 + 4);
  v7 = *(_DWORD *)(a1 + 544);
  v3 = sub_800F80((_DWORD *)(a1 + 768), v7, *(_WORD *)(a2 + 2));
  v4 = sub_800F80((_DWORD *)(a1 + 768), v7, v2);
  n1065353216 = 1065353216;
  unk_C8F52C = 0;
  unk_C8F980[0] = *(float *)(v3 + 144);
  flt_C8F984 = *(float *)(v3 + 148);
  flt_C8F988 = *(float *)(v3 + 152);
  flt_C8F98C[0] = *(float *)(v3 + 156);
  flt_C8F970 = *(float *)(v4 + 144);
  flt_C8F974 = *(float *)(v4 + 148);
  flt_C8F978 = *(float *)(v4 + 152);
  v5 = *(float *)(v4 + 156);
  unk_C8F980[0] = flt_C8F970 - unk_C8F980[0];
  unk_C8F97C = LODWORD(v5);
  flt_C8F984 = flt_C8F974 - flt_C8F984;
  flt_C8F988 = flt_C8F978 - flt_C8F988;
  flt_C8F98C[0] = v5 - flt_C8F98C[0];
  sub_42EF00();
  *(float *)a1 = unk_C8F980[0];
  *(float *)(a1 + 4) = flt_C8F984;
  *(float *)(a1 + 8) = flt_C8F988;
  *(float *)(a1 + 12) = flt_C8F98C[0];
  *(_DWORD *)(dword_C8B500 + a1 + 12) = n1065353216;
  dword_C8B500 = 0;
  if ( (*(_WORD *)(a1 + 538) & 0x400) != 0 )
  {
    *(_DWORD *)(a1 + 16) = unk_C8F508[0];
    *(_DWORD *)(a1 + 20) = unk_C8F50C;
    *(_DWORD *)(a1 + 24) = unk_C8F510;
    *(_DWORD *)(a1 + 28) = unk_C8F514;
    sub_7EA670(a1 + 64, a1 + 16, a1);
  }
  else
  {
    sub_7EA670(a1 + 64, v7 + 144, a1);
    n1065353216 = 1065353216;
    unk_C8F52C = 0;
    unk_C8F980[0] = *(float *)(v7 + 144);
    flt_C8F984 = *(float *)(v7 + 148);
    flt_C8F988 = *(float *)(v7 + 152);
    flt_C8F98C[0] = *(float *)(v7 + 156);
    *(float *)(a1 + 112) = unk_C8F980[0];
    *(float *)(a1 + 116) = flt_C8F984;
    *(float *)(a1 + 120) = flt_C8F988;
    *(float *)(a1 + 124) = flt_C8F98C[0];
    *(_DWORD *)(dword_C8B500 + a1 + 124) = n1065353216;
    dword_C8B500 = 0;
  }
  if ( (*(_WORD *)(a1 + 538) & 0x8000) != 0 )
  {
    sub_7E82C0(v7 + 192, a1 + 640, a1 + 64);
  }
  else if ( (*(_WORD *)(a1 + 538) & 0x200) != 0 )
  {
    nullsub_49(v7 + 192, v7 + 144, a1, &unk_C48CA0);
  }
  else
  {
    sub_7E7F20(v7 + 192, a1 + 64);
  }
  return a2 + 6;
}
