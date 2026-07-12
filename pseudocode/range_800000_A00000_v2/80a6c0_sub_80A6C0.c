// Function: sub_80A6C0
// Address: 0x80a6c0
int __cdecl sub_80A6C0(int a1, int a2, int a3)
{
  int v3; // edx
  double n1065353216; // st7
  int result; // eax
  int v6; // eax
  int v7; // esi
  int v8; // esi
  int n32; // [esp+1Ch] [ebp-440h]
  __int64 n964689920; // [esp+20h] [ebp-43Ch]
  float n1065353216_1; // [esp+28h] [ebp-434h]
  float v12; // [esp+2Ch] [ebp-430h]

  n32 = *((unsigned __int16 *)&unk_12A2280 + 16 * sub_7FE890(a1, 0, 0) + 7);
  HIBYTE(n1065353216) = BYTE1(word_C8F508[0]);
  BYTE1(n1065353216) = word_C8F508[0];
  *((_BYTE *)&n1065353216 + 7) = HIBYTE(word_C8F50A);
  *((_BYTE *)&n1065353216 + 5) = word_C8F50A;
  LOBYTE(n1065353216) = a2;
  *((_BYTE *)&n1065353216 + 4) = BYTE2(a2);
  *((_BYTE *)&n1065353216 + 6) = HIBYTE(a2);
  BYTE2(n1065353216) = BYTE1(a2);
  v3 = *(&n1065353216 + 1);
  *((_WORD *)&n1065353216 + 3) = word_C8F50A;
  unk_C8F536 = unk_C8F50E;
  *((_WORD *)&n1065353216 + 2) = HIWORD(n1065353216);
  HIWORD(n1065353216) = word_C8F508[0];
  n1065353216_3 = HIWORD(v3);
  unk_C8F532 = LOWORD(word_C8F50C);
  LOWORD(n1065353216_2) = v3;
  *(float *)&n964689920 = (float)(int)n1065353216;
  *((float *)&n964689920 + 1) = (float)(int)*(&n1065353216 + 1);
  n3_11 = 1006632960;
  n1065353216_13 = (float)n1065353216_2;
  flt_C8F98C[0] = (float)n1065353216_3;
  LODWORD(flt_C8F968) = unk_C8F540;
  *(float *)&n964689920 = *(float *)&n964689920 * 0.0078125;
  n1065353216 = 1132396544;
  unk_C8F78C[0] = 255.0;
  qword_C8F960 = __PAIR64__(*(&n3_11 + 1), 1006632960);
  LODWORD(flt_C8F96C) = unk_C8F544;
  *((float *)&n964689920 + 1) = 0.0078125 * *((float *)&n964689920 + 1);
  n1065353216_13 = 0.0078125 * n1065353216_13;
  flt_C8F98C[0] = 0.0078125 * flt_C8F98C[0];
  flt_C8F970 = flt_C0A004 - flt_C0A004;
  flt_C8F974 = *(float *)&dword_C0A008 - *(float *)&dword_C0A008;
  flt_C8F978 = *(float *)&dword_C0A00C - *(float *)&dword_C0A00C;
  flt_C8F97C = flt_C0A010 - flt_C0A010;
  sub_42EF00();
  n1065353216 = unk_C8F78C[0];
  if ( unk_C8F78C[0] <= (double)*(float *)&n964689920 )
    *(float *)&n964689920 = unk_C8F78C[0];
  if ( *((float *)&n964689920 + 1) >= n1065353216 )
    *((float *)&n964689920 + 1) = unk_C8F78C[0];
  if ( n1065353216_13 >= n1065353216 )
    n1065353216_13 = unk_C8F78C[0];
  if ( flt_C8F98C[0] >= n1065353216 )
    flt_C8F98C[0] = unk_C8F78C[0];
  sub_808CE0((float *)&n964689920, (float *)&n964689920, flt_C8F970, flt_C8F974, flt_C8F978, flt_C8F97C);
  n964689920 = n964689920;
  n1065353216_1 = n1065353216_13;
  v12 = flt_C8F98C[0];
  sub_82B650(a1, *(float *)&n964689920, *((float *)&n964689920 + 1), n1065353216_13, 0);
  result = FFX_BtlChr_SetHPValueFloatTransition(a1, v12, 0);
  if ( a3 && n32 < 32 )
  {
    v6 = sub_795B50(n32, 0);
    v7 = v6;
    if ( v6 )
    {
      sub_82B650(v6, *(float *)&n964689920, *((float *)&n964689920 + 1), n1065353216_1, 0);
      FFX_BtlChr_SetHPValueFloatTransition(v7, v12, 0);
    }
    result = sub_795B50(n32, 1);
    v8 = result;
    if ( result )
    {
      sub_82B650(result, *(float *)&n964689920, *((float *)&n964689920 + 1), n1065353216_1, 0);
      return FFX_BtlChr_SetHPValueFloatTransition(v8, v12, 0);
    }
  }
  return result;
}
