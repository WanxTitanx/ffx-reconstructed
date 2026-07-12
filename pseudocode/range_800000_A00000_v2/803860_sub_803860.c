// Function: sub_803860
// Address: 0x803860
int __cdecl sub_803860(float *n1065353216, int a2)
{
  int v2; // edx
  float v3; // edi
  int v4; // eax
  int v6; // eax
  int v7; // eax
  float *n1065353216_1; // esi
  int v9; // eax
  int v10; // [esp+14h] [ebp-1Ch]
  int v11; // [esp+18h] [ebp-18h]
  float v12; // [esp+18h] [ebp-18h]
  float v13; // [esp+1Ch] [ebp-14h] BYREF
  float v14; // [esp+20h] [ebp-10h]
  float v15; // [esp+24h] [ebp-Ch]
  int v16; // [esp+28h] [ebp-8h]

  v2 = *((_DWORD *)n1065353216 + 136);
  v10 = v2;
  v3 = flt_12A80C0[*(unsigned __int8 *)(v2 + 24)];
  if ( (*((_WORD *)n1065353216 + 269) & 0xF000) != 0 )
  {
    if ( (*((_WORD *)n1065353216 + 269) & 0xF000) != 0x1000 )
      return a2;
    v4 = (int)*(float *)(*(unsigned __int8 *)(a2 + 2) + v2);
  }
  else
  {
    v4 = *(__int16 *)(a2 + 2);
  }
  v11 = v4;
  v6 = sub_82ACE0(LODWORD(v3));
  if ( v6 )
    sub_7E7F20(n1065353216, v6);
  else
    sub_834000(LODWORD(v3), n1065353216);
  if ( (v11 & 0x8000) != 0 )
  {
    v7 = sub_8356E0(LODWORD(v3), (unsigned __int8)v11, &v13);
    sub_833C00(LODWORD(v3), v7, n1065353216 + 16);
    sub_7E78B0(n1065353216 + 28, n1065353216 + 16, &v13);
  }
  else
  {
    sub_833C00(LODWORD(v3), v11, n1065353216 + 16);
    n1065353216[32] = *(float *)unk_C8F508;
    *((_DWORD *)n1065353216 + 33) = unk_C8F50C;
    *((_DWORD *)n1065353216 + 34) = unk_C8F510;
    *((_DWORD *)n1065353216 + 35) = unk_C8F514;
  }
  sub_7E82C0(n1065353216, n1065353216, n1065353216 + 16);
  sub_7EA610(n1065353216 + 32, 999.99994);
  sub_7EA760(n1065353216 + 48, v10 + 144, 999.99994);
  sub_7E9760(n1065353216 + 32, n1065353216 + 32, v10 + 48, n1065353216 + 48);
  sub_7E82C0(n1065353216, n1065353216, n1065353216 + 32);
  n1065353216_1 = n1065353216;
  n1065353216 = n1065353216;
  n3_11 = 3;
  do
  {
    unk_C8F980[0] = *n1065353216_1;
    flt_C8F984 = n1065353216_1[1];
    flt_C8F988 = n1065353216_1[2];
    flt_C8F98C[0] = n1065353216_1[3];
    v13 = *n1065353216_1;
    v14 = n1065353216_1[1];
    v15 = n1065353216_1[2];
    v9 = *((_DWORD *)n1065353216_1 + 3);
    flt_C8F970 = unk_C8F980[0] * v13;
    v16 = v9;
    flt_C8F974 = flt_C8F984 * v14;
    flt_C8F978 = flt_C8F988 * v15;
    flt_C8F970 = flt_C8F974 + flt_C8F970;
    flt_C8F970 = flt_C8F978 + flt_C8F970;
    v12 = sqrt(fabs(flt_C8F970));
    flt_C8F970 = v12 + flt_C0A004;
    unk_C8F788 = flt_C0A010 / flt_C8F970;
    flt_C8F960 = unk_C8F980[0] * unk_C8F788;
    flt_C8F964 = flt_C8F984 * unk_C8F788;
    flt_C8F968 = unk_C8F788 * flt_C8F988;
    *n1065353216_1 = flt_C8F960;
    n1065353216_1[1] = flt_C8F964;
    n1065353216_1[2] = flt_C8F968;
    *((_DWORD *)n1065353216_1 + 3) = unk_C8F96C;
    n1065353216_1 = (float *)(n1065353216 + 16);
    --n3_11;
    n1065353216 += 16;
  }
  while ( n3_11 );
  sub_7E82C0(v10 + 192, n1065353216 + 160, n1065353216);
  return a2 + 4;
}
