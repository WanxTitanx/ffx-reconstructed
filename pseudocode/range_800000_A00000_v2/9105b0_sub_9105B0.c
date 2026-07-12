// Function: sub_9105B0
// Address: 0x9105b0
int __usercall sub_9105B0@<eax>(int a1@<ebp>, int a2, int i_1, int dst, int *a5, int a6, float *a7, float *a8, int a9)
{
  int i; // eax
  int v10; // eax
  int i_2; // edx
  int dst_1; // eax
  _DWORD *src_1; // edi
  int v14; // esi
  int v15; // eax
  int v16; // edx
  _DWORD *v17; // esi
  int v18; // eax
  int *v19; // ecx
  int v20; // eax
  bool v21; // zf
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // edx
  unsigned int v26; // eax
  int v27; // eax
  int n3; // edx
  unsigned int *v29; // ecx
  _DWORD *src_2; // edx
  int v31; // eax
  int n3_1; // edx
  unsigned int *v33; // ecx
  int dst_2; // edi
  char *v35; // esi
  int v36; // edx
  int *v37; // ecx
  char *v38; // edx
  _DWORD *v39; // edi
  int v40; // eax
  _WORD src_4[16]; // [esp-94h] [ebp-A0h] BYREF
  _DWORD v43[3]; // [esp-74h] [ebp-80h] BYREF
  int v44; // [esp-68h] [ebp-74h]
  int v45; // [esp-64h] [ebp-70h]
  int v46; // [esp-60h] [ebp-6Ch]
  int v47; // [esp-5Ch] [ebp-68h]
  _DWORD *src_3; // [esp-58h] [ebp-64h]
  int v49; // [esp-54h] [ebp-60h]
  _DWORD src[8]; // [esp-50h] [ebp-5Ch] BYREF
  char *v51; // [esp-28h] [ebp-34h]
  int v52; // [esp-24h] [ebp-30h]
  _DWORD *v53; // [esp-20h] [ebp-2Ch]
  int *v54; // [esp-1Ch] [ebp-28h]
  int v55; // [esp-18h] [ebp-24h]
  unsigned int v56; // [esp-14h] [ebp-20h]
  int v57; // [esp-10h] [ebp-1Ch]
  _DWORD *src_5; // [esp-Ch] [ebp-18h]
  unsigned int *v59; // [esp-8h] [ebp-14h]
  unsigned int *v60; // [esp-4h] [ebp-10h]
  int v61; // [esp+0h] [ebp-Ch]
  void *v62; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v61 = a1;
  v62 = retaddr;
  for ( i = i_1; i; i = *(_DWORD *)(i + 84) )
    ;
  sub_911970(&unk_25D1800);
  v10 = sub_83B6D0();
  i_2 = i_1;
  v53 = (_DWORD *)v10;
  v51 = (char *)v10;
  src[7] = 0;
  dst_1 = dst;
  src[0] = 1024;
  memset(&src[2], 0, 14);
  src[1] = 32;
  qmemcpy((void *)dst, src, 0x20u);
  src_1 = (_DWORD *)(dst + 32);
  src_5 = (_DWORD *)(dst + 32);
  if ( i_1 )
  {
    LOBYTE(src[0]) = 0;
    HIWORD(src[0]) = 0;
    do
    {
      v14 = *(_DWORD *)(i_2 + 68);
      v55 = 4 * *(_DWORD *)(i_2 + 72);
      v15 = sub_9113A0(&unk_25D1800, &unk_C5DB80, 4);
      v16 = v55 - v15;
      v47 = v14 + 4 * v15;
      dst_1 = dst;
      src_3 = src_1;
      ++*(_WORD *)(dst + 16);
      BYTE1(src[0]) = 32;
      memset(&src[2], 0, 16);
      qmemcpy(src_1, src, 0x20u);
      src_1 = src_5 + 8;
      v55 = v16;
      src_5 += 8;
      v49 = 0;
      v52 = 0;
      if ( v16 > 0 )
      {
        do
        {
          if ( a9 )
          {
            v17 = v53;
          }
          else
          {
            if ( (unsigned int)(4 * ((((int)src_1 - dst_1) >> 2) + 428 + 4 * *(__int16 *)(dst_1 + 18))) >> 2 >= *a5 )
              break;
            v17 = v53;
            if ( (unsigned int)((((char *)v53 - v51) >> 4) + 1008) >= 0x10000 )
              break;
          }
          v18 = sub_9113A0(&unk_25D1800, v47, v16);
          v55 -= v18;
          v47 += 4 * v18;
          v19 = (int *)((char *)&unk_25D1800 + 16 * unk_25D586C);
          v20 = *v19;
          v21 = v19[8] == 0;
          v54 = v19;
          v57 = v20;
          if ( !v21 )
          {
            src[2] = v19[12];
            v22 = v19[13];
            v21 = v19[18] == 0;
            BYTE1(src[0]) = 34;
            src[3] = v22;
            if ( v21 )
            {
              src[4] = v19[12];
              v23 = v19[13];
            }
            else
            {
              src[4] = v19[16];
              v23 = v19[17];
            }
            src[5] = v23;
            src[6] = v19[20];
            v20 = v57;
            src[7] = 0;
            v52 = 1;
            v49 = 0;
          }
          v24 = 3 * v20;
          v56 = v19[1];
          v25 = v24 + v56;
          v26 = v24 + v56 + v24;
          v46 = v25;
          if ( v52 )
          {
            if ( v57 > 0 )
            {
              v60 = (unsigned int *)&v19[4 * v26];
              v59 = v60 + 2;
              do
              {
                sub_9103E0((int)src_4, (int)v19, v56, v25);
                v56 += 3;
                v46 += 3;
                v27 = sub_910070(v60, a6, a7, a8);
                v60 += 12;
                if ( v27 )
                {
                  n3 = 3;
                  src_4[6] = *(_WORD *)(dst + 18);
                  src_4[7] = src_4[6] + 1;
                  src_4[8] = src_4[6] + 2;
                  *(_WORD *)(dst + 18) = src_4[6] + 3;
                  v29 = v59;
                  v59 += 12;
                  do
                  {
                    *v17 = *(v29 - 2);
                    v17[1] = *(v29 - 1);
                    v17[2] = *v29;
                    v17[3] = v29[1];
                    v17 += 4;
                    v29 += 4;
                    --n3;
                  }
                  while ( n3 );
                  v53 = v17;
                  if ( v49 )
                  {
                    src_2 = src_3;
                  }
                  else
                  {
                    ++*(_WORD *)(dst + 16);
                    src_2 = src_1;
                    qmemcpy(src_1, src, 0x20u);
                    src_1 = src_5 + 8;
                    src_3 = src_2;
                    src_5 += 8;
                    v49 = 1;
                  }
                  ++*(_WORD *)(dst + 16);
                  ++*((_WORD *)src_2 + 1);
                  qmemcpy(src_1, src_4, 0x20u);
                  src_1 = src_5 + 8;
                  src_5 += 8;
                }
                else
                {
                  v59 += 12;
                }
                v21 = v57-- == 1;
                v17 = v53;
                v19 = v54;
                v25 = v46;
              }
              while ( !v21 );
            }
          }
          else if ( v57 > 0 )
          {
            v60 = (unsigned int *)&v19[4 * v26];
            v59 = v60 + 2;
            do
            {
              sub_910340((int)v43, (int)v19, v56);
              v56 += 3;
              v31 = sub_910070(v60, a6, a7, a8);
              v60 += 12;
              if ( v31 )
              {
                n3_1 = 3;
                LOWORD(v44) = *(_WORD *)(dst + 18);
                HIWORD(v44) = v44 + 1;
                LOWORD(v45) = v44 + 2;
                *(_WORD *)(dst + 18) = v44 + 3;
                v33 = v59;
                v59 += 12;
                do
                {
                  *v17 = *(v33 - 2);
                  v17[1] = *(v33 - 1);
                  v17[2] = *v33;
                  v17[3] = v33[1];
                  v17 += 4;
                  v33 += 4;
                  --n3_1;
                }
                while ( n3_1 );
                v53 = v17;
                ++*(_WORD *)(dst + 16);
                ++*((_WORD *)src_3 + 1);
                *src_1 = v43[0];
                src_1[1] = v43[1];
                src_1[2] = v43[2];
                src_1[3] = v44;
                src_1[4] = v45;
                src_1 += 5;
              }
              else
              {
                v59 += 12;
              }
              v21 = v57-- == 1;
              v19 = v54;
            }
            while ( !v21 );
            src_5 = src_1;
          }
          v16 = v55;
          dst_1 = dst;
        }
        while ( v55 > 0 );
        dst_1 = dst;
      }
      i_2 = *(_DWORD *)(i_1 + 84);
      i_1 = i_2;
    }
    while ( i_2 );
  }
  ++*(_WORD *)(dst_1 + 16);
  HIWORD(src[0]) = 0;
  memset(&src[2], 0, 16);
  BYTE1(src[0]) = -1;
  qmemcpy(src_1, src, 0x20u);
  dst_2 = dst;
  v35 = (char *)(src_5 + 8);
  v36 = ((int)src_5 - dst_1 + 32) >> 2;
  v37 = 0;
  *(_DWORD *)(dst + 8) = 4 * v36;
  v52 = v36;
  v54 = 0;
  if ( *(__int16 *)(dst + 18) > 0 )
  {
    v38 = (char *)(v35 - v51);
    v39 = v51 + 8;
    v51 = (char *)(v35 - v51);
    do
    {
      *(_DWORD *)v35 = *(v39 - 2);
      *((_DWORD *)v35 + 1) = *(v39 - 1);
      *(_DWORD *)((char *)v39 + (_DWORD)v38) = *v39;
      *((_DWORD *)v35 + 3) = 1065353216;
      if ( a6 )
      {
        sub_6ED420(v35, a6, v35);
        v37 = v54;
        v38 = v51;
      }
      v37 = (int *)((char *)v37 + 1);
      v40 = *(__int16 *)(dst + 18);
      v35 += 16;
      v39 += 4;
      v54 = v37;
    }
    while ( (int)v37 < v40 );
    v36 = v52;
    dst_2 = dst;
  }
  *a5 = v36;
  *a5 = v36 + 4 * *(__int16 *)(dst_2 + 18);
  return 0;
}
