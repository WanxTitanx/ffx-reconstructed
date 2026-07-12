// Function: sub_910A90
// Address: 0x910a90
int __usercall sub_910A90@<eax>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3,
        int a4,
        int dst,
        int src_1,
        int *a7,
        int *a8,
        int a9,
        float *a10,
        float *a11,
        int a12)
{
  int v12; // eax
  int i; // esi
  int v14; // esi
  char *src_8; // edx
  int v17; // edi
  void *src_9; // eax
  int v19; // esi
  int v20; // edi
  int v21; // eax
  char *dst_1; // edx
  _DWORD *src_3; // eax
  int v24; // edi
  _DWORD *src_12; // esi
  int v26; // eax
  _DWORD *v27; // edi
  bool v28; // zf
  int v29; // eax
  int v30; // ecx
  int v31; // edx
  unsigned int n10; // ecx
  int v33; // eax
  unsigned int *v34; // esi
  int v35; // eax
  unsigned int *v36; // edi
  unsigned int *v37; // ecx
  char *dst_3; // eax
  char *dst_4; // ecx
  void *dst_5; // edi
  unsigned int *v41; // ecx
  char *src_6; // eax
  char *src_7; // ecx
  int v44; // eax
  unsigned int *v45; // edx
  unsigned int *v46; // ecx
  unsigned int *src_13; // eax
  char *dst_8; // ecx
  int v49; // edx
  unsigned int *v50; // ecx
  _DWORD *src_14; // eax
  char *dst_9; // edx
  int dst_6; // edi
  int v54; // ecx
  _DWORD *src_15; // esi
  unsigned int *v56; // ecx
  int v57; // esi
  _DWORD *v58; // edi
  int v59; // eax
  int v60; // eax
  int src_10; // edi
  int j_1; // ecx
  int v63; // edx
  unsigned int *v64; // ecx
  _DWORD *v65; // edi
  int v66; // eax
  int v67; // [esp-C4h] [ebp-D0h]
  int v68; // [esp-C4h] [ebp-D0h]
  _WORD src_5[16]; // [esp-B4h] [ebp-C0h] BYREF
  unsigned int *v71; // [esp-94h] [ebp-A0h]
  _DWORD src_2[8]; // [esp-90h] [ebp-9Ch] BYREF
  int v73; // [esp-6Ch] [ebp-78h]
  int v74; // [esp-68h] [ebp-74h]
  int v75; // [esp-64h] [ebp-70h]
  char *src_4; // [esp-60h] [ebp-6Ch]
  int v77; // [esp-5Ch] [ebp-68h]
  int v78; // [esp-58h] [ebp-64h]
  int v79; // [esp-54h] [ebp-60h]
  char *dst_2; // [esp-50h] [ebp-5Ch]
  unsigned int *v81; // [esp-4Ch] [ebp-58h]
  int j; // [esp-48h] [ebp-54h]
  int v83; // [esp-44h] [ebp-50h]
  _DWORD src[9]; // [esp-40h] [ebp-4Ch] BYREF
  _DWORD *v85; // [esp-1Ch] [ebp-28h]
  int n10_1; // [esp-18h] [ebp-24h]
  int v87; // [esp-14h] [ebp-20h]
  unsigned int *v88; // [esp-10h] [ebp-1Ch]
  unsigned int *v89; // [esp-Ch] [ebp-18h]
  char *dst_7; // [esp-8h] [ebp-14h]
  _DWORD *src_11; // [esp-4h] [ebp-10h]
  int v92; // [esp+0h] [ebp-Ch]
  void *v93; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v92 = a1;
  v93 = retaddr;
  v12 = a4;
  for ( i = 0; v12; v12 = *(_DWORD *)(v12 + 84) )
    i += *(_DWORD *)(v12 + 72);
  v14 = 16 * i;
  v83 = sub_90BC10(v14);
  v75 = v83;
  if ( v83 && (v81 = (unsigned int *)sub_90BC10(v14), (v71 = v81) != 0) )
  {
    sub_911970(&unk_25D1800);
    src[7] = 0;
    src_8 = (char *)(dst + 32);
    src[0] = 1024;
    memset(&src[2], 0, 14);
    src[1] = 32;
    qmemcpy((void *)dst, src, 0x20u);
    qmemcpy((void *)src_1, src, 0x20u);
    v17 = a4;
    src_9 = (void *)(src_1 + 32);
    dst_7 = (char *)(dst + 32);
    src_11 = (_DWORD *)(src_1 + 32);
    if ( a4 )
    {
      LOBYTE(src_2[0]) = 0;
      HIWORD(src_2[0]) = 0;
      do
      {
        v19 = *(_DWORD *)(v17 + 68);
        v20 = 4 * *(_DWORD *)(v17 + 72);
        v21 = sub_9113A0(&unk_25D1800, &unk_C5DB80, 4);
        dst_1 = dst_7;
        v78 = v20 - v21;
        v73 = v19 + 4 * v21;
        ++*(_WORD *)(dst + 16);
        src_3 = src_11;
        BYTE1(src_2[0]) = 32;
        memset(&src_2[2], 0, 16);
        qmemcpy(dst_1, src_2, 0x20u);
        ++*(_WORD *)(src_1 + 16);
        qmemcpy(src_3, src_2, 0x20u);
        v24 = v78;
        dst_2 = dst_1;
        src_8 = dst_1 + 32;
        src_12 = src_3 + 8;
        dst_7 = src_8;
        src_4 = (char *)src_3;
        src_11 = src_3 + 8;
        v74 = 0;
        v79 = 0;
        for ( j = 0; v78 > 0; src_8 = dst_7 )
        {
          if ( !a12
            && ((unsigned int)(4 * (((int)&src_8[-dst] >> 2) + 4 * (*(__int16 *)(dst + 18) + 107))) >> 2 >= *a7
             || (unsigned int)(4 * ((((int)src_12 - src_1) >> 2) + 4 * (*(__int16 *)(src_1 + 18) + 107))) >> 2 >= *a8) )
          {
            break;
          }
          v26 = sub_9113A0(&unk_25D1800, v73, v24);
          v78 = v24 - v26;
          v27 = (_DWORD *)((char *)&unk_25D1800 + 16 * unk_25D586C);
          v28 = v27[8] == 0;
          v73 += 4 * v26;
          v85 = v27;
          if ( !v28 )
          {
            v28 = v27[18] == 0;
            v29 = v27[12];
            v30 = v27[13];
            BYTE1(src_2[0]) = 34;
            src_2[2] = v29;
            src_2[3] = v30;
            if ( v28 )
            {
              src_2[4] = v29;
              src_2[5] = v30;
            }
            else
            {
              src_2[4] = v27[16];
              src_2[5] = v27[17];
            }
            src_2[6] = v27[20];
            src_2[7] = 0;
            j = 1;
            v74 = 0;
            v79 = 0;
          }
          v31 = *v27;
          n10 = 10;
          v33 = *v27 + 5;
          n10_1 = 10;
          v77 = v31 + 2 * v33;
          v87 = 6 * v31 + 10;
          if ( j )
          {
            v87 = 0;
            if ( v31 )
            {
              v34 = &v27[24 * v31 + 40];
              v88 = &v27[24 * v31 + 48];
              do
              {
                sub_9103E0((int)src_5, (int)v27, n10, v77);
                n10_1 += 3;
                v77 += 3;
                v35 = sub_910070(v34, a9, a10, a11);
                v36 = v88;
                if ( v35 )
                {
                  v37 = v81;
                  src_5[6] = *(_WORD *)(dst + 18);
                  src_5[7] = src_5[6] + 1;
                  src_5[8] = src_5[6] + 2;
                  *(_WORD *)(dst + 18) = src_5[6] + 3;
                  *v37 = *v34;
                  v37[1] = v34[1];
                  v37[2] = v34[2];
                  v37[4] = v34[4];
                  v37[5] = v34[5];
                  v37[6] = v34[6];
                  v37[8] = *v36;
                  v37[9] = v34[9];
                  v37[10] = v34[10];
                  dst_3 = dst_7;
                  v81 = v37 + 12;
                  v88 = v36 + 12;
                  v89 = v34 + 12;
                  if ( !v74 )
                  {
                    ++*(_WORD *)(dst + 16);
                    dst_2 = dst_3;
                    qmemcpy(dst_3, src_2, 0x20u);
                    dst_3 += 32;
                    v74 = 1;
                  }
                  dst_4 = dst_2;
                  ++*(_WORD *)(dst + 16);
                  ++*((_WORD *)dst_4 + 1);
                  dst_5 = dst_3;
                  dst_7 = dst_3 + 32;
                }
                else
                {
                  v41 = (unsigned int *)v83;
                  src_5[6] = *(_WORD *)(src_1 + 18);
                  src_5[7] = src_5[6] + 1;
                  src_5[8] = src_5[6] + 2;
                  *(_WORD *)(src_1 + 18) = src_5[6] + 3;
                  *v41 = *v34;
                  v41[1] = v34[1];
                  v41[2] = v34[2];
                  v41[4] = v34[4];
                  v41[5] = v34[5];
                  v41[6] = v34[6];
                  v41[8] = *v36;
                  v41[9] = v34[9];
                  v41[10] = v34[10];
                  src_6 = (char *)src_11;
                  v83 = (int)(v41 + 12);
                  v88 = v36 + 12;
                  v89 = v34 + 12;
                  if ( !v79 )
                  {
                    ++*(_WORD *)(src_1 + 16);
                    src_4 = src_6;
                    qmemcpy(src_6, src_2, 0x20u);
                    src_6 += 32;
                    v79 = 1;
                  }
                  src_7 = src_4;
                  ++*(_WORD *)(src_1 + 16);
                  ++*((_WORD *)src_7 + 1);
                  dst_5 = src_6;
                  src_11 = src_6 + 32;
                }
                v44 = v87;
                qmemcpy(dst_5, src_5, 0x20u);
                v27 = v85;
                v34 = v89;
                n10 = n10_1;
                v87 = v44 + 1;
              }
              while ( (unsigned int)(v44 + 1) < *v85 );
              src_12 = src_11;
            }
          }
          else
          {
            v89 = 0;
            if ( v31 )
            {
              v88 = &v27[24 * v31 + 40];
              src_11 = &v27[4 * v87 + 8];
              do
              {
                sub_910340((int)&src[3], (int)v27, n10);
                n10_1 += 3;
                if ( sub_910070(v88, a9, a10, a11) )
                {
                  v45 = v88;
                  LOWORD(src[6]) = *(_WORD *)(dst + 18);
                  HIWORD(src[6]) = LOWORD(src[6]) + 1;
                  LOWORD(src[7]) = LOWORD(src[6]) + 2;
                  *(_WORD *)(dst + 18) = LOWORD(src[6]) + 3;
                  v46 = v81 + 12;
                  *v81 = *v45;
                  *(v46 - 11) = v45[1];
                  *(v46 - 10) = v45[2];
                  *(v46 - 8) = v45[4];
                  *(v46 - 7) = v45[5];
                  *(v46 - 6) = v45[6];
                  src_13 = src_11;
                  src_11 += 12;
                  *(v46 - 4) = *src_13;
                  *(v46 - 3) = v45[9];
                  *(v46 - 2) = v45[10];
                  v81 = v46;
                  ++*(_WORD *)(dst + 16);
                  dst_8 = dst_7;
                  ++*((_WORD *)dst_2 + 1);
                  *(_DWORD *)dst_8 = src[3];
                  *((_DWORD *)dst_8 + 1) = src[4];
                  *((_DWORD *)dst_8 + 2) = src[5];
                  *((_DWORD *)dst_8 + 3) = src[6];
                  *((_DWORD *)dst_8 + 4) = src[7];
                  v88 = v45 + 12;
                  dst_7 = dst_8 + 20;
                }
                else
                {
                  v49 = v83;
                  LOWORD(src[6]) = *(_WORD *)(src_1 + 18);
                  HIWORD(src[6]) = LOWORD(src[6]) + 1;
                  LOWORD(src[7]) = LOWORD(src[6]) + 2;
                  *(_WORD *)(src_1 + 18) = LOWORD(src[6]) + 3;
                  v50 = v88;
                  v49 += 48;
                  *(_DWORD *)(v49 - 48) = *v88;
                  *(_DWORD *)(v49 - 44) = v50[1];
                  *(_DWORD *)(v49 - 40) = v50[2];
                  *(_DWORD *)(v49 - 32) = v50[4];
                  *(_DWORD *)(v49 - 28) = v50[5];
                  *(_DWORD *)(v49 - 24) = v50[6];
                  src_14 = src_11;
                  src_11 += 12;
                  *(_DWORD *)(v49 - 16) = *src_14;
                  *(_DWORD *)(v49 - 12) = v50[9];
                  *(_DWORD *)(v49 - 8) = v50[10];
                  ++*(_WORD *)(src_1 + 16);
                  v83 = v49;
                  ++*((_WORD *)src_4 + 1);
                  *src_12 = src[3];
                  src_12[1] = src[4];
                  src_12[2] = src[5];
                  src_12[3] = src[6];
                  src_12[4] = src[7];
                  v88 = v50 + 12;
                  src_12 += 5;
                }
                n10 = n10_1;
                v89 = (unsigned int *)((char *)v89 + 1);
              }
              while ( (unsigned int)v89 < *v27 );
              src_11 = src_12;
            }
          }
          v24 = v78;
        }
        v17 = *(_DWORD *)(a4 + 84);
        a4 = v17;
      }
      while ( v17 );
      src_9 = src_11;
    }
    HIWORD(src_2[0]) = 0;
    memset(&src_2[2], 0, 16);
    ++*(_WORD *)(dst + 16);
    BYTE1(src_2[0]) = -1;
    qmemcpy(src_8, src_2, 0x20u);
    ++*(_WORD *)(src_1 + 16);
    dst_9 = src_8 + 32;
    qmemcpy(src_9, src_2, 0x20u);
    dst_6 = dst;
    v54 = (int)&dst_9[-dst] >> 2;
    src_15 = src_11 + 8;
    *(_DWORD *)(dst + 8) = 4 * v54;
    dst_7 = dst_9;
    src_11 = src_15;
    v87 = v54;
    if ( *(__int16 *)(dst + 18) > 0 )
    {
      v56 = v71 + 2;
      v89 = v71 + 2;
      v85 = (_DWORD *)(dst_9 - (char *)v71);
      v57 = 0;
      do
      {
        v58 = v85;
        *(_DWORD *)dst_9 = *(v56 - 2);
        *((_DWORD *)dst_9 + 1) = *(v56 - 1);
        *(unsigned int *)((char *)v56 + (_DWORD)v58) = *v56;
        dst_6 = dst;
        *((_DWORD *)dst_9 + 3) = 1065353216;
        if ( a9 )
        {
          sub_6ED420(dst_9, a9, dst_9);
          dst_9 = dst_7;
          v56 = v89;
        }
        v59 = *(__int16 *)(dst + 18);
        dst_9 += 16;
        v56 += 4;
        ++v57;
        dst_7 = dst_9;
        v89 = v56;
      }
      while ( v57 < v59 );
      src_15 = src_11;
      v54 = v87;
    }
    *a7 = v54;
    v60 = *(__int16 *)(dst_6 + 18);
    src_10 = src_1;
    *a7 = v54 + 4 * v60;
    j_1 = ((int)src_15 - src_1) >> 2;
    v63 = 0;
    *(_DWORD *)(src_1 + 8) = 4 * j_1;
    j = j_1;
    v87 = 0;
    if ( *(__int16 *)(src_1 + 18) > 0 )
    {
      v64 = (unsigned int *)(v75 + 8);
      v89 = (unsigned int *)(v75 + 8);
      v85 = (_DWORD *)((char *)src_15 - v75);
      do
      {
        v65 = v85;
        *src_15 = *(v64 - 2);
        src_15[1] = *(v64 - 1);
        *(unsigned int *)((char *)v64 + (_DWORD)v65) = *v64;
        src_10 = src_1;
        src_15[3] = 1065353216;
        if ( a9 )
        {
          sub_6ED420(src_15, a9, src_15);
          v64 = v89;
          v63 = v87;
        }
        v66 = *(__int16 *)(src_1 + 18);
        ++v63;
        v64 += 4;
        src_15 += 4;
        v89 = v64;
        v87 = v63;
      }
      while ( v63 < v66 );
      j_1 = j;
    }
    v67 = v75;
    *a8 = j_1;
    *a8 = j_1 + 4 * *(__int16 *)(src_10 + 18);
    j_FFX_Memory_Delete_1(v67, a2);
    j_FFX_Memory_Delete_1((int)v71, v68);
    return 0;
  }
  else
  {
    src[0] = 1024;
    memset(&src[1], 0, 18);
    src[7] = 0;
    qmemcpy((void *)dst, src, 0x20u);
    qmemcpy((void *)src_1, src, 0x20u);
    return 0;
  }
}
