// Function: sub_81C3B0
// Address: 0x81c3b0
int __cdecl sub_81C3B0(int a1, int a2)
{
  float v2; // eax
  int i; // esi
  __int64 n964689920_1; // [esp-14h] [ebp-4Ch]
  char v6; // [esp-8h] [ebp-40h]
  __int64 n964689920; // [esp+24h] [ebp-14h] BYREF
  float v8; // [esp+2Ch] [ebp-Ch]
  float v9; // [esp+30h] [ebp-8h]

  n964689920 = *(_QWORD *)(a1 + 64);
  flt_C8F988 = *(float *)(a1 + 72);
  v2 = *(float *)(a1 + 76);
  flt_C8F970 = flt_C0A004 - flt_C0A004;
  flt_C8F98C[0] = v2;
  flt_C8F974 = *(float *)&dword_C0A008 - *(float *)&dword_C0A008;
  *(_QWORD *)&n1065353216 = 1132396544;
  unk_C8F78C[0] = 255.0;
  flt_C8F978 = *(float *)&dword_C0A00C - *(float *)&dword_C0A00C;
  flt_C8F97C = flt_C0A010 - flt_C0A010;
  sub_42EF00();
  sub_808D80((float *)&n964689920, (float *)&n964689920, unk_C8F78C[0]);
  sub_808CE0(
    &n964689920,
    &n964689920,
    LODWORD(flt_C8F970),
    LODWORD(flt_C8F974),
    LODWORD(flt_C8F978),
    LODWORD(flt_C8F97C));
  n964689920 = n964689920;
  v8 = flt_C8F988;
  v9 = flt_C8F98C[0];
  for ( i = 0; i < 16; i += 4 )
    *(_DWORD *)((char *)&n964689920 + i) = (int)*(float *)((char *)&n964689920 + i);
  LOWORD(n964689920) = n964689920;
  WORD1(n964689920) = WORD2(n964689920);
  WORD2(n964689920) = LOWORD(flt_C8F988);
  HIWORD(n964689920) = LOWORD(flt_C8F98C[0]);
  LOWORD(v8) = word_C8F508[0];
  HIWORD(v8) = LOWORD(word_C8F50C);
  LOWORD(v9) = LOWORD(word_C8F510);
  HIWORD(v9) = LOWORD(word_C8F514[0]);
  sub_737690(&n964689920, word_C8F508, &n964689920);
  HIDWORD(n964689920_1) = *(unsigned __int8 *)(a2 + 2);
  LODWORD(n964689920_1) = n964689920;
  return sub_7EA9E0(n964689920_1, *(unsigned __int8 *)(a2 + 3), v6);
}
