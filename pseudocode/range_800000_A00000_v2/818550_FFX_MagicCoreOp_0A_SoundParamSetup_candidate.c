// Function: FFX_MagicCoreOp_0A_SoundParamSetup_candidate
// Address: 0x818550
__int16 *__cdecl FFX_MagicCoreOp_0A_SoundParamSetup_candidate(int a1, __int16 *a2)
{
  int *v2; // eax
  int v3; // ebx
  int v4; // esi
  int v5; // ecx
  int v6; // edx
  int v7; // edi
  float v8; // edi
  float *v9; // ecx
  __int16 *n1065353216_1; // ebx
  unsigned int v11; // esi
  float *v12; // ecx
  int v13; // esi
  __int64 v15; // rt0
  int v16; // [esp+10h] [ebp-40h]
  __int16 v17; // [esp+20h] [ebp-30h]
  float *v18; // [esp+24h] [ebp-2Ch]
  float v19; // [esp+28h] [ebp-28h]
  float v20; // [esp+28h] [ebp-28h]
  float n1065353216; // [esp+28h] [ebp-28h]
  float v22; // [esp+28h] [ebp-28h]
  int v23; // [esp+30h] [ebp-20h]
  float v24; // [esp+3Ch] [ebp-14h]
  float v25; // [esp+3Ch] [ebp-14h]
  float v26; // [esp+3Ch] [ebp-14h]

  v17 = *(_WORD *)(a1 + 538);
  v2 = (int *)((char *)&unk_C49398 + 16 * (__int16)((v17 & 0x1FF) - 10));
  v3 = v2[3];
  v23 = v2[1];
  v4 = v2[2];
  v16 = *(_DWORD *)(a1 + 544);
  v5 = *v2;
  v18 = (float *)(v16 + word_C49388[(__int16)((v17 & 0x1FF) - 10)]);
  n1065353216 = a2[1];
  v6 = a2[2];
  *(&n1065353216 + 1) = v6;
  n1065353216_2 = a2[3];
  v7 = a2[4];
  *(&n1065353216 + 1) = v6 * v23;
  n1065353216 *= v5;
  n1065353216_2 *= v4;
  n1065353216_3 = v7 * v3;
  v19 = (float)(int)n1065353216;
  word_C8F980[0] = v19 * 0.000244140625;
  v20 = (float)(v6 * v23);
  flt_C8F984 = v20 * 0.000244140625;
  n1065353216 = (float)n1065353216_2;
  flt_C8F988 = n1065353216 * 0.000244140625;
  v22 = (float)(v7 * v3);
  flt_C8F98C[0] = 0.000244140625 * v22;
  if ( (v17 & 0x1000) == word_C8F508[0] && (v8 = word_C8F50C, !LODWORD(word_C8F50C)) )
  {
    n1065353216_1 = a2 + 1;
    v9 = v18;
  }
  else
  {
    v9 = v18;
    n1065353216_1 = a2 + 2;
    *v18 = word_C8F980[0];
    v8 = word_C8F50C;
    v24 = word_C8F980[0];
    word_C8F980[0] = flt_C8F984;
    flt_C8F984 = flt_C8F988;
    flt_C8F988 = flt_C8F98C[0];
    flt_C8F98C[0] = v24;
  }
  v11 = word_C8F508[0];
  if ( __PAIR64__(v17 & 0x2000, 0) != __PAIR64__(word_C8F508[0], LODWORD(v8)) )
  {
    v9[1] = word_C8F980[0];
    v8 = word_C8F50C;
    v11 = word_C8F508[0];
    v25 = word_C8F980[0];
    word_C8F980[0] = flt_C8F984;
    flt_C8F984 = flt_C8F988;
    flt_C8F988 = flt_C8F98C[0];
    ++n1065353216_1;
    flt_C8F98C[0] = v25;
  }
  v12 = v9 + 2;
  if ( (v17 & 0x4000) != v11 || LODWORD(v8) )
  {
    *v12 = word_C8F980[0];
    v8 = word_C8F50C;
    v26 = word_C8F980[0];
    word_C8F980[0] = flt_C8F984;
    flt_C8F984 = flt_C8F988;
    flt_C8F988 = flt_C8F98C[0];
    ++n1065353216_1;
    flt_C8F98C[0] = v26;
  }
  unk_C8F55C = LODWORD(flt_C8F984);
  unk_C8F560 = LODWORD(flt_C8F988);
  *(&n1065353216 + 1) = 0;
  n1065353216_4 = LODWORD(word_C8F980[0]);
  unk_C8F564 = LODWORD(flt_C8F98C[0]);
  if ( (v17 & 0x8000) != word_C8F508[0] || (v13 = 0, LODWORD(v8)) )
  {
    ++n1065353216_1;
    v12[1] = word_C8F980[0];
    v13 = *(&n1065353216 + 1);
    v8 = word_C8F50C;
  }
  n1065353216 = n1065353216_1;
  *(_QWORD *)&n3_11 = v17 & 0x200;
  unk_C8F548 = a1;
  if ( n3_11 == word_C8F508[0] && !LODWORD(v8) )
    return n1065353216_1;
  n1065353216_4 = n1065353216_1;
  HIDWORD(v15) = v13;
  LODWORD(v15) = *(unsigned __int8 *)(v16 + 186);
  *(_QWORD *)&n1065353216 = &g_FFX_MagicPostProcTable[v15];
  n1065353216 = *(_DWORD *)n1065353216;
  return (__int16 *)g_FFX_MagicPostProcTable[*(unsigned __int8 *)(v16 + 186)](a1, (int)n1065353216_1);
}
