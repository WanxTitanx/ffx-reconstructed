// Function: sub_A91B30
// Address: 0xa91b30
// Size: 0x505
// Prototype: int __usercall@<eax>(void *@<ecx>, int)

int __fastcall sub_A91B30(void **a1, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  void **v4; // ebx
  _DWORD *v5; // edi
  int v6; // ecx
  unsigned int v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _QWORD *v10; // eax
  _QWORD *v11; // eax
  unsigned int v12; // eax
  int i; // ecx
  unsigned int v14; // eax
  int j; // ecx
  int v16; // eax
  bool v17; // cc
  int v18; // edi
  _DWORD *v19; // ebx
  size_t Count; // edi
  void *v21; // ebx
  _DWORD *v22; // ecx
  _DWORD **v23; // eax
  int v24; // ebx
  size_t Count_1; // edi
  void *v26; // ebx
  int v27; // eax
  int v28; // eax
  size_t Count_2; // edi
  void *v30; // ebx
  size_t Count_3; // edi
  void *v32; // ebx
  _DWORD *v33; // ebx
  int v34; // eax
  _DWORD *v35; // ebx
  int v37; // eax
  void **v38; // edi
  int v39; // edx
  _DWORD *v40; // eax
  int k_1; // eax
  _DWORD *v42; // [esp+Ch] [ebp-1Ch]
  int v45; // [esp+18h] [ebp-10h]
  int v46; // [esp+18h] [ebp-10h]
  int v47; // [esp+18h] [ebp-10h]
  void **v48; // [esp+18h] [ebp-10h]
  _DWORD *v49; // [esp+1Ch] [ebp-Ch]
  int v50; // [esp+1Ch] [ebp-Ch]
  int v51; // [esp+20h] [ebp-8h]
  int v52; // [esp+20h] [ebp-8h]
  int v53; // [esp+20h] [ebp-8h]
  int v54; // [esp+20h] [ebp-8h]
  int k; // [esp+20h] [ebp-8h]

  v3 = (_DWORD *)a2[7];
  v4 = a1;
  if ( !v3 || (int)v3[2] <= 0 || (int)*v3 < 64 || v3[1] < *v3 )
    return 1;
  v45 = v3[914];
  memset(a1, 0, 0x70u);
  v5 = calloc_0(1u, 0x88u);
  v42 = v5;
  memset(v5, 0, 0x88u);
  v4[1] = a2;
  v4[26] = v5;
  v6 = 0;
  v7 = v3[2] - 1;
  if ( v3[2] != 1 )
  {
    do
    {
      ++v6;
      v7 >>= 1;
    }
    while ( v7 );
  }
  v5[11] = v6;
  v8 = calloc_0(1u, 4u);
  *v8 = 0;
  v5[3] = v8;
  v9 = calloc_0(1u, 4u);
  *v9 = 0;
  v5[4] = v9;
  v10 = calloc_0(1u, 0x14u);
  *v10 = 0;
  v10[1] = 0;
  *((_DWORD *)v10 + 4) = 0;
  *(_DWORD *)v5[3] = v10;
  v11 = calloc_0(1u, 0x14u);
  *v11 = 0;
  v11[1] = 0;
  *((_DWORD *)v11 + 4) = 0;
  *(_DWORD *)v5[4] = v11;
  sub_A9D680(*(_DWORD *)v5[3], (int)*v3 >> v45);
  sub_A9D680(*(_DWORD *)v5[4], (int)v3[1] >> v45);
  v12 = *v3;
  for ( i = 0; v12; v12 >>= 1 )
    ++i;
  v5[1] = i - 7;
  v14 = v3[1];
  for ( j = 0; v14; v14 >>= 1 )
    ++j;
  v5[2] = j - 7;
  if ( a3 )
  {
    sub_A9B190(v5 + 5, *v3);
    sub_A9B190(v5 + 8, v3[1]);
    if ( !v3[712] )
    {
      v16 = sub_A97DD0(v3[6], 0x38u);
      v17 = v3[6] <= 0;
      v3[712] = v16;
      v46 = 0;
      if ( !v17 )
      {
        v18 = 0;
        v19 = v3 + 456;
        do
        {
          sub_A93410((void *)(v18 + v3[712]));
          v18 += 56;
          ++v46;
          ++v19;
        }
        while ( v46 < v3[6] );
      }
    }
    Count = v3[7];
    v21 = calloc_0(Count, 0x34u);
    memset(v21, 0, 52 * Count);
    v22 = v42;
    v42[14] = v21;
    v47 = 0;
    if ( (int)v3[7] > 0 )
    {
      v23 = (_DWORD **)(v3 + 713);
      v24 = 0;
      v49 = v3 + 713;
      do
      {
        sub_A974B0((void *)(v24 + v22[14]), (int)(v3 + 717), v3[**v23] / 2, a2[2]);
        v23 = (_DWORD **)(v49 + 1);
        v24 += 52;
        v17 = ++v47 < v3[7];
        v22 = v42;
        ++v49;
      }
      while ( v17 );
    }
    v4 = a1;
    *a1 = (void *)1;
    goto LABEL_20;
  }
  if ( v3[712] || (v37 = sub_A97DD0(v3[6], 0x38u), v17 = v3[6] <= 0, v3[712] = v37, v50 = 0, v17) )
  {
LABEL_20:
    v4[4] = (void *)v3[1];
    v4[2] = malloc_0(4 * a2[1]);
    v4[3] = malloc_0(4 * a2[1]);
    v51 = 0;
    if ( (int)a2[1] > 0 )
    {
      do
      {
        Count_1 = (size_t)a1[4];
        v26 = calloc_0(Count_1, 4u);
        memset(v26, 0, 4 * Count_1);
        v27 = v51 + 1;
        *((_DWORD *)a1[2] + v27 - 1) = v26;
        ++v51;
      }
      while ( v27 < a2[1] );
      v4 = a1;
    }
    v4[9] = 0;
    v4[10] = 0;
    v28 = v3[1] / 2;
    v4[12] = (void *)v28;
    v4[5] = (void *)v28;
    Count_2 = v3[4];
    v30 = calloc_0(Count_2, 4u);
    memset(v30, 0, 4 * Count_2);
    v42[12] = v30;
    Count_3 = v3[5];
    v32 = calloc_0(Count_3, 4u);
    memset(v32, 0, 4 * Count_3);
    v42[13] = v32;
    v52 = 0;
    if ( (int)v3[4] > 0 )
    {
      v33 = v3 + 200;
      do
      {
        v34 = (*((int (__cdecl **)(void **, _DWORD))*(&off_B81500 + *v33) + 2))(a1, v33[64]);
        *(_DWORD *)((char *)++v33 + -800 - (_DWORD)v3 + v42[12] - 4) = v34;
        ++v52;
      }
      while ( v52 < v3[4] );
    }
    v53 = 0;
    if ( (int)v3[5] > 0 )
    {
      v35 = v3 + 328;
      do
      {
        *(_DWORD *)((char *)v35 + v42[13] - (_DWORD)v3 - 1312) = (*((int (__cdecl **)(void **, _DWORD))*(&off_B814F0 + *v35)
                                                                  + 2))(
                                                                   a1,
                                                                   v35[64]);
        ++v35;
        ++v53;
      }
      while ( v53 < v3[5] );
    }
    return 0;
  }
  v38 = (void **)(v3 + 456);
  v39 = 0;
  v54 = 0;
  v40 = v3 + 456;
  v48 = (void **)(v3 + 456);
  while ( *v40 && !sub_A92D50((void *)(v39 + v3[712])) )
  {
    sub_A93550(*v48);
    *v48 = 0;
    v40 = v48 + 1;
    v39 = v54 + 56;
    ++v50;
    ++v48;
    v54 += 56;
    if ( v50 >= v3[6] )
      goto LABEL_20;
  }
  k_1 = 0;
  for ( k = 0; k_1 < v3[6]; k = k_1 )
  {
    if ( *v38 )
    {
      sub_A93550(*v38);
      k_1 = k;
      *v38 = 0;
    }
    ++k_1;
    ++v38;
  }
  sub_A917A0(v4);
  return -1;
}

