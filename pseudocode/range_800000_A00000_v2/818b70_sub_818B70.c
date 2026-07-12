// Function: sub_818B70
// Address: 0x818b70
int __cdecl sub_818B70(int a1, __int16 *a2)
{
  int *v2; // eax
  int v3; // ebx
  int v4; // esi
  int v5; // ecx
  int v6; // edx
  int v7; // edi
  float v8; // edi
  float *v9; // ecx
  int n1065353216_1; // ebx
  unsigned int v11; // esi
  float *v12; // ecx
  int v14; // [esp+14h] [ebp-3Ch]
  int v15; // [esp+20h] [ebp-30h]
  float *v16; // [esp+24h] [ebp-2Ch]
  float v17; // [esp+28h] [ebp-28h]
  float v18; // [esp+28h] [ebp-28h]
  float n1065353216; // [esp+28h] [ebp-28h]
  float v20; // [esp+28h] [ebp-28h]
  int v21; // [esp+30h] [ebp-20h]
  float v22; // [esp+3Ch] [ebp-14h]
  float v23; // [esp+3Ch] [ebp-14h]
  float v24; // [esp+3Ch] [ebp-14h]

  v15 = *(unsigned __int16 *)(a1 + 538);
  v2 = (int *)((char *)&unk_C493F8 + 16 * ((v15 >> 9) & 7));
  v3 = v2[3];
  v21 = v2[1];
  v4 = v2[2];
  v14 = *(_DWORD *)(a1 + 544);
  v5 = *v2;
  v16 = (float *)(v14 + word_C49388[(v15 >> 9) & 7]);
  n1065353216 = a2[1];
  v6 = a2[2];
  *(&n1065353216 + 1) = v6;
  n1065353216_2 = a2[3];
  v7 = a2[4];
  *(&n1065353216 + 1) = v6 * v21;
  n1065353216 *= v5;
  n1065353216_2 *= v4;
  n1065353216_3 = v7 * v3;
  v17 = (float)(int)n1065353216;
  word_C8F980[0] = v17 * 0.000244140625;
  v18 = (float)(v6 * v21);
  flt_C8F984 = v18 * 0.000244140625;
  n1065353216 = (float)n1065353216_2;
  flt_C8F988 = n1065353216 * 0.000244140625;
  v20 = (float)(v7 * v3);
  flt_C8F98C[0] = 0.000244140625 * v20;
  if ( (v15 & 0x1000) == word_C8F508[0] && (v8 = word_C8F50C, !LODWORD(word_C8F50C)) )
  {
    n1065353216_1 = (int)(a2 + 1);
    v9 = v16;
  }
  else
  {
    v9 = v16;
    n1065353216_1 = (int)(a2 + 2);
    *v16 = word_C8F980[0];
    v8 = word_C8F50C;
    v22 = word_C8F980[0];
    word_C8F980[0] = flt_C8F984;
    flt_C8F984 = flt_C8F988;
    flt_C8F988 = flt_C8F98C[0];
    flt_C8F98C[0] = v22;
  }
  v11 = word_C8F508[0];
  if ( __PAIR64__(v15 & 0x2000, 0) != __PAIR64__(word_C8F508[0], LODWORD(v8)) )
  {
    v9[1] = word_C8F980[0];
    v8 = word_C8F50C;
    v11 = word_C8F508[0];
    v23 = word_C8F980[0];
    word_C8F980[0] = flt_C8F984;
    flt_C8F984 = flt_C8F988;
    flt_C8F988 = flt_C8F98C[0];
    n1065353216_1 += 2;
    flt_C8F98C[0] = v23;
  }
  v12 = v9 + 2;
  if ( (v15 & 0x4000) != v11 || LODWORD(v8) )
  {
    *v12 = word_C8F980[0];
    v8 = word_C8F50C;
    v24 = word_C8F980[0];
    word_C8F980[0] = flt_C8F984;
    flt_C8F984 = flt_C8F988;
    flt_C8F988 = flt_C8F98C[0];
    n1065353216_1 += 2;
    flt_C8F98C[0] = v24;
  }
  unk_C8F55C = LODWORD(flt_C8F984);
  unk_C8F560 = LODWORD(flt_C8F988);
  n1065353216_4 = LODWORD(word_C8F980[0]);
  unk_C8F564 = LODWORD(flt_C8F98C[0]);
  if ( (v15 & 0x8000) != word_C8F508[0] || LODWORD(v8) )
  {
    n1065353216_1 += 2;
    v12[1] = word_C8F980[0];
    v8 = word_C8F50C;
  }
  *(_QWORD *)&n1065353216 = v15 & 0x200;
  unk_C8F548 = a1;
  if ( *(_QWORD *)&n3_11 == __PAIR64__(LODWORD(v8), word_C8F508[0]) )
    return n1065353216_1;
  n1065353216_4 = n1065353216_1;
  *(_QWORD *)&n1065353216 = &g_FFX_MagicPostProcTable[*(unsigned __int8 *)(v14 + 186)];
  n1065353216 = *(_DWORD *)n1065353216;
  return g_FFX_MagicPostProcTable[*(unsigned __int8 *)(v14 + 186)](a1, n1065353216_1);
}
