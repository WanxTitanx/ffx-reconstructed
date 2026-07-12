// Function: FFX_MagicCoreOp_38_ShapeActiveInstanceRTSpace
// Address: 0x809780
// Jarvis-HEAVY H06: Magic VM op 0x38. Consumes active record at ctx+0x220, reads RGBA-ish floats at record+0x40..0x4C, packs/clamps/transforms them through C8F8D0 scratch and writes packed color/RT-space state. Best visual hook candidate, research-only.
int __cdecl FFX_MagicCoreOp_38_ShapeActiveInstanceRTSpace(int a1, int a2)
{
  int v2; // esi
  int v3; // ecx
  unsigned int n20480; // eax
  int v5; // edx
  double v6; // st7
  int v8; // eax
  float v9; // eax
  int v10; // eax
  float v11; // eax
  int j; // esi
  double v13; // st7
  float v14; // eax
  int i; // esi
  float v16; // [esp+0h] [ebp-48h]
  int v17; // [esp+20h] [ebp-28h]
  int v18; // [esp+24h] [ebp-24h]
  __int16 v19; // [esp+2Ch] [ebp-1Ch]
  char *v20; // [esp+2Ch] [ebp-1Ch]
  char *v21; // [esp+2Ch] [ebp-1Ch]
  float v22; // [esp+30h] [ebp-18h]
  float v23; // [esp+30h] [ebp-18h]
  float v24; // [esp+34h] [ebp-14h] BYREF
  float v25; // [esp+38h] [ebp-10h]
  float v26; // [esp+3Ch] [ebp-Ch]
  float v27; // [esp+40h] [ebp-8h]

  v2 = *(_DWORD *)(a1 + 544);
  v3 = LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)]);
  v19 = *(_WORD *)(a1 + 538);
  n20480 = v19 & 0xF000;
  v17 = v2;
  v18 = v3;
  if ( n20480 > 0x3000 )
  {
    if ( n20480 != 0x4000 )
    {
      if ( n20480 == 20480 )
      {
        v5 = (int)*(float *)(*(__int16 *)(a2 + 2) + v2);
        v6 = *(float *)(*(__int16 *)(a2 + 4) + v2);
        v3 = LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)]);
        goto LABEL_23;
      }
      if ( n20480 == 24576 )
      {
        word_C8F980[0] = *(float *)(v2 + 64);
        flt_C8F984 = *(float *)(v2 + 68);
        flt_C8F988 = *(float *)(v2 + 72);
        flt_C8F98C[0] = *(float *)(v2 + 76);
        n1065353216 = 1132396544;
        unk_C8F52C = 0;
        unk_C8F78C[0] = 255.0;
        sub_74BFA0(
          (int)&flt_C8F970,
          (int)&flt_C0A004,
          flt_C0A004,
          *(float *)&dword_C0A008,
          *(float *)&dword_C0A00C,
          flt_C0A010);
        sub_808D80(word_C8F980, word_C8F980, unk_C8F78C[0]);
        sub_808CE0(
          word_C8F980,
          word_C8F980,
          LODWORD(flt_C8F970),
          LODWORD(flt_C8F974),
          LODWORD(flt_C8F978),
          LODWORD(flt_C8F97C));
        sub_808C70((int *)word_C8F980, word_C8F980);
        v24 = word_C8F980[0];
        v25 = flt_C8F984;
        v26 = flt_C8F988;
        v27 = flt_C8F98C[0];
        sub_737760(&v24, word_C8F508, &v24);
        sub_737690(&v24, word_C8F508, &v24);
        return a2 + 2;
      }
      return a2;
    }
    sub_82EB70(v3, a1, a1 + 4, a1 + 8);
    *(float *)(a1 + 12) = sub_82EC20(v18, 0);
    sub_7EA760(a1, a1, 256.0);
    word_C8F980[0] = *(float *)a1;
    flt_C8F984 = *(float *)(a1 + 4);
    flt_C8F988 = *(float *)(a1 + 8);
    v14 = *(float *)(a1 + 12);
    flt_C8F970 = flt_C0A004 - flt_C0A004;
    flt_C8F98C[0] = v14;
    n1065353216 = 1132396544;
    unk_C8F78C[0] = 255.0;
    flt_C8F974 = *(float *)&dword_C0A008 - *(float *)&dword_C0A008;
    flt_C8F978 = *(float *)&dword_C0A00C - *(float *)&dword_C0A00C;
    flt_C8F97C = flt_C0A010 - flt_C0A010;
    sub_42EF00();
    sub_808D80(word_C8F980, word_C8F980, unk_C8F78C[0]);
    sub_808CE0(
      word_C8F980,
      word_C8F980,
      LODWORD(flt_C8F970),
      LODWORD(flt_C8F974),
      LODWORD(flt_C8F978),
      LODWORD(flt_C8F97C));
    v24 = word_C8F980[0];
    v25 = flt_C8F984;
    v26 = flt_C8F988;
    v27 = flt_C8F98C[0];
    for ( i = 0; i < 4; ++i )
      LODWORD(word_C8F980[i]) = (int)*(float *)((char *)&v24 + i * 4);
    LOWORD(n1065353216) = LOWORD(word_C8F980[0]);
    unk_C8F52A = LOWORD(flt_C8F984);
    LOWORD(unk_C8F52C) = LOWORD(flt_C8F988);
    unk_C8F52E = LOWORD(flt_C8F98C[0]);
    LOWORD(unk_C8F530) = word_C8F508[0];
    unk_C8F532 = LOWORD(word_C8F50C);
    unk_C8F534 = LOWORD(word_C8F510);
    unk_C8F536 = LOWORD(word_C8F514[0]);
    sub_737690(&n1065353216, word_C8F508, &n1065353216);
    *(_DWORD *)(v17 + 200) = n1065353216;
    return a2 + 2;
  }
  if ( (v19 & 0xF000) == 0x3000 )
  {
    v10 = sub_7FE890(v3, 0, 0);
    word_C8F980[0] = *(float *)(v2 + 64);
    v21 = (char *)&unk_12A2280 + 32 * v10;
    flt_C8F984 = *(float *)(v2 + 68);
    flt_C8F988 = *(float *)(v2 + 72);
    v11 = *(float *)(v2 + 76);
    flt_C8F970 = flt_C0A004 - flt_C0A004;
    flt_C8F98C[0] = v11;
    n1065353216 = 1132396544;
    unk_C8F78C[0] = 255.0;
    flt_C8F974 = *(float *)&dword_C0A008 - *(float *)&dword_C0A008;
    flt_C8F978 = *(float *)&dword_C0A00C - *(float *)&dword_C0A00C;
    flt_C8F97C = flt_C0A010 - flt_C0A010;
    sub_42EF00();
    sub_808D80(word_C8F980, word_C8F980, unk_C8F78C[0]);
    sub_808CE0(
      word_C8F980,
      word_C8F980,
      LODWORD(flt_C8F970),
      LODWORD(flt_C8F974),
      LODWORD(flt_C8F978),
      LODWORD(flt_C8F97C));
    v24 = word_C8F980[0];
    v25 = flt_C8F984;
    v26 = flt_C8F988;
    v27 = flt_C8F98C[0];
    for ( j = 0; j < 4; ++j )
      LODWORD(word_C8F980[j]) = (int)*(float *)((char *)&v24 + j * 4);
    LOWORD(n1065353216) = LOWORD(word_C8F980[0]);
    unk_C8F52A = LOWORD(flt_C8F984);
    LOWORD(unk_C8F52C) = LOWORD(flt_C8F988);
    unk_C8F52E = LOWORD(flt_C8F98C[0]);
    LOWORD(unk_C8F530) = word_C8F508[0];
    unk_C8F532 = LOWORD(word_C8F50C);
    unk_C8F534 = LOWORD(word_C8F510);
    unk_C8F536 = LOWORD(word_C8F514[0]);
    sub_737690(&n1065353216, word_C8F508, &n1065353216);
    *((_DWORD *)v21 + 6) = n1065353216;
LABEL_17:
    sub_80AB60(v18, *(char *)(a1 + 542));
    return a2 + 2;
  }
  if ( (v19 & 0xF000) == 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 || *(_WORD *)(a1 + 768) == 1 )
    {
      word_C8F980[0] = *(float *)(v2 + 64);
      flt_C8F984 = *(float *)(v2 + 68);
      flt_C8F988 = *(float *)(v2 + 72);
      v9 = *(float *)(v2 + 76);
      flt_C8F970 = flt_C0A004 - flt_C0A004;
      flt_C8F98C[0] = v9;
      n1065353216 = 1132396544;
      unk_C8F52C = 0;
      unk_C8F78C[0] = 255.0;
      flt_C8F974 = *(float *)&dword_C0A008 - *(float *)&dword_C0A008;
      flt_C8F978 = *(float *)&dword_C0A00C - *(float *)&dword_C0A00C;
      flt_C8F97C = flt_C0A010 - flt_C0A010;
      sub_42EF00();
      sub_808D80(word_C8F980, word_C8F980, unk_C8F78C[0]);
      sub_808CE0(
        word_C8F980,
        word_C8F980,
        LODWORD(flt_C8F970),
        LODWORD(flt_C8F974),
        LODWORD(flt_C8F978),
        LODWORD(flt_C8F97C));
      sub_808C70((int *)word_C8F980, word_C8F980);
      LOWORD(v24) = LOWORD(word_C8F980[0]);
      HIWORD(v24) = LOWORD(flt_C8F984);
      LOWORD(v25) = LOWORD(flt_C8F988);
      HIWORD(v25) = LOWORD(flt_C8F98C[0]);
      LOWORD(v26) = word_C8F508[0];
      HIWORD(v26) = LOWORD(word_C8F50C);
      LOWORD(v27) = LOWORD(word_C8F510);
      HIWORD(v27) = LOWORD(word_C8F514[0]);
      sub_737690(&v24, word_C8F508, &v24);
      if ( FFX_Btl_GetCurrentBattleFormationId() != 323 )
        sub_80A6C0(v18, LODWORD(v24), *(char *)(a1 + 542));
      return a2 + 2;
    }
    v8 = sub_7FE890(v3, 0, 0);
    word_C8F980[0] = *(float *)(v2 + 64);
    v20 = (char *)&unk_12A2280 + 32 * v8;
    flt_C8F984 = *(float *)(v2 + 68);
    flt_C8F988 = *(float *)(v2 + 72);
    flt_C8F98C[0] = *(float *)(v2 + 76);
    n1065353216 = 1132396544;
    unk_C8F78C[0] = 255.0;
    sub_74BFA0(
      (int)&flt_C8F970,
      (int)&flt_C0A004,
      flt_C0A004,
      *(float *)&dword_C0A008,
      *(float *)&dword_C0A00C,
      flt_C0A010);
    sub_808D80(word_C8F980, word_C8F980, unk_C8F78C[0]);
    sub_808CE0(
      word_C8F980,
      word_C8F980,
      LODWORD(flt_C8F970),
      LODWORD(flt_C8F974),
      LODWORD(flt_C8F978),
      LODWORD(flt_C8F97C));
    sub_808C70((int *)word_C8F980, word_C8F980);
    LOWORD(n1065353216) = LOWORD(word_C8F980[0]);
    unk_C8F52A = LOWORD(flt_C8F984);
    LOWORD(unk_C8F52C) = LOWORD(flt_C8F988);
    unk_C8F52E = LOWORD(flt_C8F98C[0]);
    LOWORD(unk_C8F530) = word_C8F508[0];
    unk_C8F532 = LOWORD(word_C8F50C);
    unk_C8F534 = LOWORD(word_C8F510);
    unk_C8F536 = LOWORD(word_C8F514[0]);
    sub_737690(&n1065353216, word_C8F508, &n1065353216);
    *((_DWORD *)v20 + 4) = n1065353216;
    goto LABEL_17;
  }
  if ( n20480 == 4096 )
  {
    v5 = *(__int16 *)(a2 + 2);
    v6 = (double)*(__int16 *)(a2 + 4);
    goto LABEL_23;
  }
  if ( n20480 != 0x2000 )
    return a2;
  v5 = *(__int16 *)(a2 + 2);
  v6 = *(float *)(*(__int16 *)(a2 + 4) + v2);
LABEL_23:
  v22 = v6;
  v23 = v22 * 0.0078125;
  if ( v23 >= 0.0 )
    v13 = v23;
  else
    v13 = (float)0.0;
  if ( v13 > 1.990000009536743 )
    v13 = (float)1.99;
  v16 = v13;
  sub_82AEB0(v3, v5, v16);
  return a2 + 6;
}
