// Function: sub_81C000
// Address: 0x81c000
int __cdecl sub_81C000(int a1, int a2)
{
  int v2; // edx
  int n0x2000; // eax
  float v5; // eax
  int i; // esi
  __int64 n964689920; // [esp+24h] [ebp-14h] BYREF
  float v8; // [esp+2Ch] [ebp-Ch]
  float v9; // [esp+30h] [ebp-8h]

  v2 = *(_DWORD *)(a1 + 544);
  *(_WORD *)(v2 + 168) = *(_WORD *)(a2 + 2);
  n0x2000 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
  {
    *(_BYTE *)(v2 + 187) = 4;
    sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
    return a2 + 4;
  }
  if ( n0x2000 != 4096 )
  {
    if ( n0x2000 == 0x2000 )
    {
      sub_7EB320(sub_81C3B0, v2, a2, 1);
      return a2 + 4;
    }
    return a2 + 4;
  }
  n964689920 = *(_QWORD *)(v2 + 64);
  flt_C8F988 = *(float *)(v2 + 72);
  v5 = *(float *)(v2 + 76);
  flt_C8F970 = flt_C0A004 - flt_C0A004;
  flt_C8F98C[0] = v5;
  *(_QWORD *)&n1065353216 = 1132396544;
  unk_C8F78C[0] = 255.0;
  flt_C8F974 = *(float *)&dword_C0A008 - *(float *)&dword_C0A008;
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
  sub_7EA9E0(n964689920, *(unsigned __int8 *)(a2 + 2), *(_BYTE *)(a2 + 3));
  return a2 + 4;
}
