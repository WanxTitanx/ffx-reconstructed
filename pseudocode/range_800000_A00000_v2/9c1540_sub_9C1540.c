// Function: sub_9C1540
// Address: 0x9c1540
double __userpurge sub_9C1540@<st0>(
        int a1@<ecx>,
        int a2@<ebp>,
        char a3@<efl>,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12)
{
  int v12; // esi
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  float *v16; // edi
  double v17; // st7
  int v18; // edx
  unsigned int v19; // ecx
  int n4; // edi
  int n4_1; // eax
  int v22; // edx
  unsigned int v23; // edi
  int v24; // eax
  int v25; // ecx
  double v26; // st7
  int v27; // edx
  int v28; // edi
  int v29; // edi
  int v30; // eax
  int v31; // ecx
  char v32; // cf
  bool v33; // zf
  char v34; // sf
  char v35; // of
  bool v36; // pf
  int v37; // ecx
  char v38; // cf
  bool v39; // zf
  char v40; // sf
  char v41; // of
  bool v42; // pf
  int n4_4; // edi
  int v44; // eax
  void *dst; // edi
  int n4_5; // edi
  int v47; // eax
  void *src_1; // edi
  int n4_6; // edi
  int v50; // eax
  void *src_2; // edi
  _BYTE src[192]; // [esp+44h] [ebp-10Ch] BYREF
  int n4_2; // [esp+130h] [ebp-20h]
  unsigned int v55; // [esp+134h] [ebp-1Ch]
  int v56; // [esp+138h] [ebp-18h]
  int n4_3; // [esp+13Ch] [ebp-14h]
  int v58; // [esp+140h] [ebp-10h]
  _DWORD v59[3]; // [esp+144h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+150h] [ebp+0h]

  v59[0] = a2;
  v59[1] = retaddr;
  v12 = a1;
  v13 = *(_DWORD *)(a1 + 8);
  v58 = v12;
  v55 = v13;
  if ( v13 > 0 )
  {
    v14 = 0;
    v56 = 0;
    do
    {
      v15 = *(_DWORD *)(v12 + 16);
      v16 = *(float **)(v15 + v14 + 136);
      v17 = *(float *)(v15 + v14 + 96);
      v18 = v14 + v15;
      v16[28] = v17;
      v19 = v55;
      if ( (*(_BYTE *)(a10 + 60) & 8) != 0 )
      {
        v16[30] = *(float *)(192 * *(_DWORD *)(v18 + 124) + *(_DWORD *)(v12 + 56) + 96);
        v14 = v56;
        v19 = v55;
        v16[31] = *(float *)(192 * *(_DWORD *)(v18 + 124) + *(_DWORD *)(v12 + 56) + 288);
      }
      v14 += 192;
      v56 = v14;
      v55 = v19 - 1;
    }
    while ( v19 != 1 );
  }
  n4 = *(_DWORD *)(v12 + 28);
  n4_1 = 0;
  n4_2 = n4;
  if ( n4 >= 4 )
  {
    v22 = 0;
    v23 = ((unsigned int)(n4 - 4) >> 2) + 1;
    v55 = v23;
    v56 = 0;
    n4_3 = 4 * v23;
    do
    {
      *(float *)(*(_DWORD *)(*(_DWORD *)(v12 + 36) + v22 + 136) + 28) = *(float *)(*(_DWORD *)(v12 + 36) + v22 + 96)
                                                                      + *(float *)(*(_DWORD *)(*(_DWORD *)(v12 + 36)
                                                                                             + v22
                                                                                             + 136)
                                                                                 + 28);
      *(float *)(*(_DWORD *)(*(_DWORD *)(v12 + 36) + v22 + 328) + 28) = *(float *)(*(_DWORD *)(v12 + 36) + v22 + 288)
                                                                      + *(float *)(*(_DWORD *)(*(_DWORD *)(v12 + 36)
                                                                                             + v22
                                                                                             + 328)
                                                                                 + 28);
      *(float *)(*(_DWORD *)(*(_DWORD *)(v12 + 36) + v22 + 520) + 28) = *(float *)(*(_DWORD *)(v12 + 36) + v22 + 480)
                                                                      + *(float *)(*(_DWORD *)(*(_DWORD *)(v12 + 36)
                                                                                             + v22
                                                                                             + 520)
                                                                                 + 28);
      v24 = *(_DWORD *)(v12 + 36);
      v25 = *(_DWORD *)(v24 + v22 + 712);
      v26 = *(float *)(v24 + v22 + 672) + *(float *)(v25 + 28);
      v22 = v56 + 768;
      v56 += 768;
      *(float *)(v25 + 28) = v26;
      --v23;
    }
    while ( v23 );
    n4 = n4_2;
    n4_1 = n4_3;
  }
  if ( n4_1 < n4 )
  {
    v27 = 192 * n4_1;
    v28 = n4 - n4_1;
    do
    {
      v27 += 192;
      *(float *)(*(_DWORD *)(*(_DWORD *)(v12 + 36) + v27 - 56) + 28) = *(float *)(*(_DWORD *)(v12 + 36) + v27 - 96)
                                                                     + *(float *)(*(_DWORD *)(*(_DWORD *)(v12 + 36)
                                                                                            + v27
                                                                                            - 56)
                                                                                + 28);
      --v28;
    }
    while ( v28 );
  }
  v29 = 0;
  v30 = a5;
  if ( *(_DWORD *)(a10 + 44) )
  {
    if ( a5 <= 0 )
      goto LABEL_24;
    do
    {
      v31 = *(_DWORD *)(a4 + 4 * v29);
      v32 = 0;
      v35 = 0;
      v33 = (*(_BYTE *)(v31 + 244) & 2) == 0;
      v36 = __SETP__(*(_BYTE *)(v31 + 244) & 2, 0);
      v34 = 0;
      if ( (*(_BYTE *)(v31 + 244) & 2) != 0 )
      {
        sub_9B51F0(v31, (int)v59, a3, *(float *)(a10 + 12));
        v30 = a5;
      }
      ++v29;
    }
    while ( v29 < v30 );
  }
  else
  {
    if ( a5 <= 0 )
      goto LABEL_24;
    do
    {
      v37 = *(_DWORD *)(a4 + 4 * v29);
      v38 = 0;
      v41 = 0;
      v39 = (*(_BYTE *)(v37 + 244) & 2) == 0;
      v42 = __SETP__(*(_BYTE *)(v37 + 244) & 2, 0);
      v40 = 0;
      if ( (*(_BYTE *)(v37 + 244) & 2) != 0 )
      {
        sub_9BE1E0(v37, a3);
        v30 = a5;
      }
      ++v29;
    }
    while ( v29 < v30 );
  }
  v12 = v58;
LABEL_24:
  n4_4 = *(_DWORD *)(v12 + 8);
  n4_3 = n4_4;
  if ( n4_4 < 0 )
  {
    if ( *(int *)(v12 + 12) < 0 )
    {
      if ( *(_DWORD *)(v12 + 16) )
      {
        if ( *(_BYTE *)(v12 + 20) )
          sub_9D4D50(*(_DWORD *)(v12 + 16));
        *(_DWORD *)(v12 + 16) = 0;
      }
      *(_BYTE *)(v12 + 20) = 1;
      *(_DWORD *)(v12 + 16) = 0;
      *(_DWORD *)(v12 + 12) = 0;
    }
    v44 = 192 * n4_4;
    do
    {
      dst = (void *)(v44 + *(_DWORD *)(v12 + 16));
      if ( dst )
      {
        qmemcpy(dst, src, 0xC0u);
        v12 = v58;
      }
      v44 += 192;
    }
    while ( v44 < 0 );
  }
  *(_DWORD *)(v12 + 8) = 0;
  n4_5 = *(_DWORD *)(v12 + 28);
  n4_3 = n4_5;
  if ( n4_5 < 0 )
  {
    if ( *(int *)(v12 + 32) < 0 )
    {
      if ( *(_DWORD *)(v12 + 36) )
      {
        if ( *(_BYTE *)(v12 + 40) )
          sub_9D4D50(*(_DWORD *)(v12 + 36));
        *(_DWORD *)(v12 + 36) = 0;
      }
      *(_BYTE *)(v12 + 40) = 1;
      *(_DWORD *)(v12 + 36) = 0;
      *(_DWORD *)(v12 + 32) = 0;
    }
    v47 = 192 * n4_5;
    do
    {
      src_1 = (void *)(v47 + *(_DWORD *)(v12 + 36));
      if ( src_1 )
      {
        qmemcpy(src_1, src, 0xC0u);
        v12 = v58;
      }
      v47 += 192;
    }
    while ( v47 < 0 );
  }
  *(_DWORD *)(v12 + 28) = 0;
  n4_6 = *(_DWORD *)(v12 + 48);
  n4_3 = n4_6;
  if ( n4_6 < 0 )
  {
    if ( *(int *)(v12 + 52) < 0 )
    {
      if ( *(_DWORD *)(v12 + 56) )
      {
        if ( *(_BYTE *)(v12 + 60) )
          sub_9D4D50(*(_DWORD *)(v12 + 56));
        *(_DWORD *)(v12 + 56) = 0;
      }
      *(_BYTE *)(v12 + 60) = 1;
      *(_DWORD *)(v12 + 56) = 0;
      *(_DWORD *)(v12 + 52) = 0;
    }
    v50 = 192 * n4_6;
    do
    {
      src_2 = (void *)(v50 + *(_DWORD *)(v12 + 56));
      if ( src_2 )
      {
        qmemcpy(src_2, src, 0xC0u);
        v12 = v58;
      }
      v50 += 192;
    }
    while ( v50 < 0 );
  }
  *(_DWORD *)(v12 + 48) = 0;
  return 0.0;
}
