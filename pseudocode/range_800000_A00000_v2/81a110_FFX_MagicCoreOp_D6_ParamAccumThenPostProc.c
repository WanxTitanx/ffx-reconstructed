// Function: FFX_MagicCoreOp_D6_ParamAccumThenPostProc
// Address: 0x81a110
__int16 *__cdecl FFX_MagicCoreOp_D6_ParamAccumThenPostProc(int a1, __int16 *a2)
{
  int *v2; // eax
  int v3; // ebx
  int v4; // esi
  int v5; // ecx
  int v6; // edx
  float v7; // ecx
  float v8; // esi
  float *v9; // ebx
  __int16 *n1065353216_3; // edi
  float *v12; // [esp+18h] [ebp-38h]
  int v13; // [esp+1Ch] [ebp-34h]
  unsigned __int16 v14; // [esp+24h] [ebp-2Ch]
  float v15; // [esp+28h] [ebp-28h]
  float v16; // [esp+28h] [ebp-28h]
  float n1065353216_1; // [esp+28h] [ebp-28h]
  float n1065353216_2; // [esp+28h] [ebp-28h]
  int v19; // [esp+30h] [ebp-20h]
  float v20; // [esp+3Ch] [ebp-14h]
  float v21; // [esp+3Ch] [ebp-14h]
  float v22; // [esp+3Ch] [ebp-14h]
  int n1065353216; // [esp+48h] [ebp-8h]

  v14 = *(_WORD *)(a1 + 538);
  v2 = (int *)((char *)&unk_C49398 + 16 * (__int16)((v14 & 0x1FF) - 214));
  v3 = v2[3];
  v19 = v2[1];
  v4 = v2[2];
  v13 = *(_DWORD *)(a1 + 544);
  v5 = *v2;
  v12 = (float *)(v13 + word_C49388[(__int16)((v14 & 0x1FF) - 214)]);
  n1065353216 = a2[1];
  v6 = a2[2];
  *(&n1065353216 + 1) = v6;
  n1065353216_2 = a2[3];
  n1065353216 = a2[4] * v3;
  n1065353216_2 *= v4;
  n1065353216_3 = n1065353216;
  v15 = (float)(n1065353216 * v5);
  *(float *)&n964689920 = v15 * 0.000244140625;
  v16 = (float)(v6 * v19);
  *((float *)&n964689920 + 1) = v16 * 0.000244140625;
  n1065353216_1 = (float)n1065353216_2;
  flt_C8F988 = n1065353216_1 * 0.000244140625;
  n1065353216_2 = (float)n1065353216;
  flt_C8F98C[0] = 0.000244140625 * n1065353216_2;
  v7 = *(float *)&n964689920;
  unk_C8F560 = LODWORD(flt_C8F988);
  *(_QWORD *)&n1065353216 = v14 & 0x1000;
  n1065353216_4 = n964689920;
  unk_C8F564 = LODWORD(flt_C8F98C[0]);
  if ( (v14 & 0x1000) == word_C8F508[0] && (v8 = word_C8F50C, !LODWORD(word_C8F50C)) )
  {
    v9 = v12;
    n1065353216_3 = a2 + 1;
  }
  else
  {
    v9 = v12;
    LODWORD(unk_C8F75C[0]) = n964689920;
    flt_C8F760 = *v12;
    n1065353216_3 = a2 + 2;
    unk_C8F75C[0] = flt_C8F760 + *(float *)&n964689920;
    *v12 = unk_C8F75C[0];
    v8 = word_C8F50C;
    v20 = *(float *)&n964689920;
    *(float *)&n964689920 = *((float *)&n964689920 + 1);
    v7 = *((float *)&n964689920 + 1);
    *((float *)&n964689920 + 1) = flt_C8F988;
    flt_C8F988 = flt_C8F98C[0];
    flt_C8F98C[0] = v20;
  }
  HIDWORD(n1065353216_4) = HIDWORD(n964689920);
  unk_C8F560 = LODWORD(flt_C8F988);
  *(_QWORD *)&n1065353216 = v14 & 0x2000;
  *(float *)&n1065353216_4 = v7;
  unk_C8F564 = LODWORD(flt_C8F98C[0]);
  if ( (v14 & 0x2000) != __PAIR64__(LODWORD(v8), word_C8F508[0]) )
  {
    unk_C8F75C[0] = v7;
    flt_C8F760 = v9[1];
    ++n1065353216_3;
    unk_C8F75C[0] = flt_C8F760 + v7;
    v9[1] = unk_C8F75C[0];
    v8 = word_C8F50C;
    v21 = *(float *)&n964689920;
    *(float *)&n964689920 = *((float *)&n964689920 + 1);
    v7 = *((float *)&n964689920 + 1);
    *((float *)&n964689920 + 1) = flt_C8F988;
    flt_C8F988 = flt_C8F98C[0];
    flt_C8F98C[0] = v21;
  }
  HIDWORD(n1065353216_4) = HIDWORD(n964689920);
  unk_C8F560 = LODWORD(flt_C8F988);
  *(_QWORD *)&n1065353216 = v14 & 0x4000;
  *(float *)&n1065353216_4 = v7;
  unk_C8F564 = LODWORD(flt_C8F98C[0]);
  if ( (v14 & 0x4000) != __PAIR64__(LODWORD(v8), word_C8F508[0]) )
  {
    unk_C8F75C[0] = v7;
    flt_C8F760 = v9[2];
    ++n1065353216_3;
    unk_C8F75C[0] = flt_C8F760 + v7;
    v9[2] = unk_C8F75C[0];
    v8 = word_C8F50C;
    v22 = *(float *)&n964689920;
    *(float *)&n964689920 = *((float *)&n964689920 + 1);
    v7 = *((float *)&n964689920 + 1);
    *((float *)&n964689920 + 1) = flt_C8F988;
    flt_C8F988 = flt_C8F98C[0];
    flt_C8F98C[0] = v22;
  }
  HIDWORD(n1065353216_4) = HIDWORD(n964689920);
  unk_C8F560 = LODWORD(flt_C8F988);
  *(_QWORD *)&n1065353216 = v14 & 0x8000;
  *(float *)&n1065353216_4 = v7;
  unk_C8F564 = LODWORD(flt_C8F98C[0]);
  if ( (v14 & 0x8000) != __PAIR64__(LODWORD(v8), word_C8F508[0]) )
  {
    unk_C8F75C[0] = v7;
    flt_C8F760 = v9[3];
    ++n1065353216_3;
    unk_C8F75C[0] = flt_C8F760 + v7;
    v9[3] = unk_C8F75C[0];
    v8 = word_C8F50C;
  }
  n1065353216 = n1065353216_3;
  *(_QWORD *)&n3_11 = v14 & 0x200;
  unk_C8F548 = a1;
  if ( n3_11 == word_C8F508[0] && !LODWORD(v8) )
    return n1065353216_3;
  LODWORD(n1065353216_4) = n1065353216_3;
  *(_QWORD *)&n1065353216 = &g_FFX_MagicPostProcTable[*(unsigned __int8 *)(v13 + 186)];
  n1065353216 = *(_DWORD *)n1065353216;
  return (__int16 *)g_FFX_MagicPostProcTable[*(unsigned __int8 *)(v13 + 186)](a1, (int)n1065353216_3);
}
