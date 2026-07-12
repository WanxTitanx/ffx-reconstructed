// Function: sub_A92D50
// Address: 0xa92d50
// Size: 0x6b3
// Prototype: int __thiscall(void *)

int __fastcall sub_A92D50(int *a1, int *i_1)
{
  int n4; // edi
  int *i_2; // ecx
  int v5; // edx
  int v6; // eax
  void *v7; // esp
  _BYTE *n4_16; // ecx
  char *Base; // edx
  int *v11; // esi
  signed int n4_3; // eax
  __m128i si128; // xmm4
  __m128i v14; // xmm3
  int n4_13; // esi
  __m128i v16; // xmm5
  __m128i v17; // xmm6
  __m128i v18; // xmm7
  int v19; // edi
  const __m128i *n4_17; // esi
  __m128i v21; // xmm0
  __m128i v22; // xmm1
  __m128i v23; // xmm1
  __m128i v24; // xmm1
  __m128i v25; // xmm0
  __m128i v26; // xmm2
  __m128i v27; // xmm1
  __m128i v28; // xmm0
  unsigned int *v29; // esi
  int v30; // edi
  unsigned int v31; // ecx
  unsigned int v32; // edx
  unsigned int v33; // ecx
  unsigned int v34; // edx
  unsigned int n0x7FFF_3; // eax
  void *v36; // esp
  void *v37; // eax
  unsigned int n4_6; // edx
  int n4_4; // ecx
  signed int n4_14; // esi
  char *v41; // eax
  int *n4_7; // edi
  bool v43; // zf
  int v44; // edx
  int v45; // eax
  int n4_8; // edx
  int *i_3; // edi
  void *v48; // eax
  size_t Size_1; // ecx
  int v50; // edx
  void *v51; // eax
  int *i_4; // ecx
  int v53; // edx
  int v54; // eax
  _DWORD *v55; // eax
  unsigned int v56; // eax
  int j; // ecx
  int n5; // eax
  void *v59; // edi
  int *i_5; // edi
  unsigned int v61; // ecx
  unsigned int v62; // edx
  unsigned int v63; // ecx
  unsigned int v64; // edx
  int v65; // eax
  int n4_18; // edx
  int n4_19; // eax
  int v68; // ecx
  int n4_11; // edi
  signed int n4_12; // eax
  int *i_6; // eax
  unsigned int v72; // ecx
  unsigned int v73; // edx
  unsigned int v74; // ecx
  unsigned int v75; // edx
  int v76; // ecx
  int v77; // eax
  int n4_9; // ecx
  signed int n4_10; // edx
  _DWORD *v80; // eax
  _DWORD *v81; // edx
  __int16 n0x7FFF; // ax
  unsigned int n0x7FFF_2; // ecx
  _DWORD Base_1[2]; // [esp+0h] [ebp-30h] BYREF
  size_t Size; // [esp+8h] [ebp-28h]
  unsigned int *v86; // [esp+Ch] [ebp-24h]
  int n4_1; // [esp+10h] [ebp-20h]
  int *i; // [esp+14h] [ebp-1Ch]
  signed int n4_5; // [esp+18h] [ebp-18h]
  void *n4_15; // [esp+1Ch] [ebp-14h]
  unsigned int n0x7FFF_1; // [esp+20h] [ebp-10h]
  int *v92; // [esp+24h] [ebp-Ch]
  int n4_2; // [esp+28h] [ebp-8h]
  char v94; // [esp+2Fh] [ebp-1h]

  n4 = 0;
  i = i_1;
  v92 = a1;
  n4_2 = 0;
  memset(a1, 0, 0x38u);
  i_2 = i;
  v5 = i[1];
  v6 = 0;
  if ( v5 > 0 )
  {
    do
    {
      if ( *(char *)(i[2] + v6) > 0 )
        ++n4;
      ++v6;
    }
    while ( v6 < v5 );
    i_2 = i;
    n4_2 = n4;
  }
  a1[1] = v5;
  a1[2] = n4;
  *a1 = *i_2;
  if ( n4 > 0 )
  {
    n4_15 = sub_A92A60(i_2[2], i_2[1], n4);
    Size = 4 * n4;
    v7 = alloca(4 * n4);
    n4_16 = n4_15;
    Base = (char *)Base_1;
    n4_5 = (signed int)Base_1;
    if ( !n4_15 )
    {
      sub_A935B0(a1);
      return -1;
    }
    v11 = v92;
    n4_3 = 0;
    if ( (unsigned int)n4 >= 4 && n2_9 >= 2 )
    {
      si128 = _mm_load_si128((const __m128i *)&xmmword_B92360);
      v14 = _mm_shuffle_epi32(_mm_cvtsi32_si128((unsigned int)n4_15), 0);
      if ( Base_1 <= (_DWORD *)n4_15 + n4 - 1 && &Base_1[n4 - 1] >= n4_15 )
      {
        n4_3 = 0;
      }
      else
      {
        n4_13 = n4 - (n4 & 3);
        v16 = _mm_cvtsi32_si128(0x10u);
        v17 = _mm_cvtsi32_si128(8u);
        v18 = _mm_cvtsi32_si128(4u);
        n0x7FFF_1 = (char *)Base_1 - (_BYTE *)n4_15;
        v19 = (char *)Base_1 - (_BYTE *)n4_15;
        n4_3 = 0;
        n4_1 = n4_13;
        n4_17 = (const __m128i *)n4_15;
        do
        {
          v21 = _mm_loadu_si128(n4_17++);
          v22 = _mm_or_si128(
                  _mm_and_si128(_mm_sll_epi32(v21, v16), (__m128i)xmmword_B92470),
                  _mm_and_si128(_mm_srl_epi32(v21, v16), (__m128i)xmmword_B92390));
          v23 = _mm_or_si128(
                  _mm_and_si128(_mm_sll_epi32(v22, v17), (__m128i)xmmword_B92460),
                  _mm_and_si128(_mm_srl_epi32(v22, v17), (__m128i)xmmword_B923A0));
          v24 = _mm_or_si128(
                  _mm_and_si128(_mm_sll_epi32(v23, v18), (__m128i)xmmword_B92450),
                  _mm_and_si128(_mm_srl_epi32(v23, v18), (__m128i)xmmword_B923B0));
          v25 = _mm_cvtsi32_si128(2u);
          v26 = _mm_or_si128(
                  _mm_and_si128(_mm_sll_epi32(v24, v25), (__m128i)xmmword_B92440),
                  _mm_and_si128(_mm_srl_epi32(v24, v25), (__m128i)xmmword_B923C0));
          v27 = _mm_cvtsi32_si128(1u);
          n4_17[-1] = _mm_or_si128(
                        _mm_and_si128(_mm_sll_epi32(v26, v27), (__m128i)xmmword_B92430),
                        _mm_and_si128(_mm_srl_epi32(v26, v27), (__m128i)xmmword_B923F0));
          v28 = _mm_add_epi32(
                  _mm_mullo_epi32(
                    _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(n4_3), 0), si128),
                    (__m128i)xmmword_B92370),
                  v14);
          n4_3 += 4;
          *(__m128i *)((char *)n4_17 + v19 - 16) = v28;
        }
        while ( n4_3 < n4_1 );
        v11 = v92;
        n4 = n4_2;
        Base = (char *)n4_5;
      }
    }
    if ( n4_3 < n4 )
    {
      n4_1 = n4;
      v29 = (unsigned int *)&n4_16[4 * n4_3];
      n0x7FFF_1 = Base - n4_16;
      v30 = n4 - n4_3;
      do
      {
        v31 = __ROL4__(*v29, 16);
        v32 = (v31 << 8) ^ (unsigned int)&unk_FF00FF & ((v31 << 8) ^ (v31 >> 8));
        v33 = (16 * v32) ^ ((16 * v32) ^ (v32 >> 4)) & 0xF0F0F0F;
        v34 = (4 * v33) ^ ((4 * v33) ^ (v33 >> 2)) & 0x33333333;
        n0x7FFF_3 = n0x7FFF_1;
        *v29 = (2 * v34) ^ ((2 * v34) ^ (v34 >> 1)) & 0x55555555;
        *(unsigned int *)((char *)v29 + n0x7FFF_3) = (unsigned int)v29;
        ++v29;
        --v30;
      }
      while ( v30 );
      v11 = v92;
      n4 = n4_2;
      Base = (char *)n4_5;
    }
    qsort(Base, n4, 4u, (_CoreCrtNonSecureSearchSortCompareFunction)_PAIR64___w);
    v36 = alloca(4 * n4);
    n0x7FFF_1 = (unsigned int)Base_1;
    v37 = malloc_0(4 * n4);
    n4_6 = n0x7FFF_1;
    n4_4 = 0;
    v11[5] = (int)v37;
    if ( n4 > 0 )
    {
      n4_14 = n4_5;
      do
      {
        *(_DWORD *)(n4_6 + 4 * ((*(_DWORD *)(n4_14 + 4 * n4_4) - (int)n4_15) >> 2)) = n4_4;
        ++n4_4;
      }
      while ( n4_4 < n4 );
      v11 = v92;
      v41 = (char *)n4_15 - n4_6;
      n4_5 = n4;
      n4_1 = n4_6;
      v86 = (unsigned int *)((char *)n4_15 - n4_6);
      n4_7 = (int *)n4_6;
      do
      {
        v43 = n4_5-- == 1;
        v44 = *n4_7;
        v45 = *(int *)((char *)n4_7++ + (_DWORD)v41);
        *(_DWORD *)(v11[5] + 4 * v44) = v45;
        v41 = (char *)v86;
      }
      while ( !v43 );
      n4 = n4_2;
    }
    free_1(n4_15);
    n4_8 = n4;
    i_3 = i;
    v11[4] = (int)sub_A926F0(i, n4_8, n0x7FFF_1);
    v48 = malloc_0(Size);
    Size_1 = 0;
    v11[6] = (int)v48;
    v50 = 0;
    for ( i = 0; v50 < i_3[1]; ++v50 )
    {
      if ( *(char *)(v50 + i_3[2]) > 0 )
      {
        *(_DWORD *)(v11[6] + 4 * *(_DWORD *)(n0x7FFF_1 + 4 * Size_1)) = v50;
        Size_1 = (size_t)i + 1;
        i = (int *)((char *)i + 1);
      }
    }
    v51 = malloc_0(Size_1);
    i_4 = 0;
    v53 = 0;
    v11[7] = (int)v51;
    v11[10] = 0;
    n4_2 = 0;
    i = 0;
    if ( i_3[1] > 0 )
    {
      do
      {
        v94 = *((_BYTE *)i_4 + i_3[2]);
        if ( v94 > 0 )
        {
          *(_BYTE *)(*(_DWORD *)(n0x7FFF_1 + 4 * v53) + v11[7]) = v94;
          i_4 = i;
          v54 = *((char *)i + i_3[2]);
          v53 = ++n4_2;
          if ( v54 > v11[10] )
            v11[10] = v54;
        }
        i_4 = (int *)((char *)i_4 + 1);
        i = i_4;
      }
      while ( (int)i_4 < i_3[1] );
      if ( v53 == 1 && v11[10] == 1 )
      {
        v11[9] = 1;
        v55 = calloc_0(2u, 4u);
        *(_QWORD *)v55 = 0;
        v11[8] = (int)v55;
        v55[1] = 1;
        *(_DWORD *)v11[8] = 1;
        return 0;
      }
    }
    v56 = v11[2];
    for ( j = 0; v56; v56 >>= 1 )
      ++j;
    n5 = j - 4;
    if ( j - 4 < 5 )
      n5 = 5;
    v11[9] = n5;
    if ( n5 > 8 )
      n5 = 8;
    v11[9] = n5;
    n4_5 = 1 << v11[9];
    v59 = calloc_0(n4_5, 4u);
    memset(v59, 0, 4 * n4_5);
    v11[8] = (int)v59;
    i_5 = 0;
    for ( i = 0; (int)i_5 < n4_2; i = i_5 )
    {
      v86 = (unsigned int *)*((char *)i_5 + v11[7]);
      if ( (int)v86 <= v11[9] )
      {
        v61 = __ROL4__(*(_DWORD *)(v11[5] + 4 * (_DWORD)i_5), 16);
        v62 = (v61 << 8) ^ (unsigned int)&unk_FF00FF & ((v61 << 8) ^ (v61 >> 8));
        v63 = (16 * v62) ^ ((16 * v62) ^ (v62 >> 4)) & 0xF0F0F0F;
        v64 = (4 * v63) ^ ((4 * v63) ^ (v63 >> 2)) & 0x33333333;
        n4_1 = (2 * v64) ^ ((2 * v64) ^ (v64 >> 1)) & 0x55555555;
        v65 = 1 << (*((_BYTE *)v11 + 36) - (_BYTE)v86);
        n4_18 = 0;
        n4_15 = 0;
        if ( v65 > 0 )
        {
          do
          {
            *(_DWORD *)(v11[8] + 4 * (n4_1 | (n4_18 << *((_BYTE *)i + v11[7])))) = (char *)i_5 + 1;
            i_5 = i;
            n4_19 = 1 << (*((_BYTE *)v11 + 36) - *((_BYTE *)i + v11[7]));
            n4_18 = (int)n4_15 + 1;
            n4_15 = (void *)n4_18;
          }
          while ( n4_18 < n4_19 );
        }
      }
      i_5 = (int *)((char *)i_5 + 1);
    }
    v68 = 31 - v11[9];
    n4_11 = 0;
    n0x7FFF_1 = 0;
    Size = -2 << v68;
    n4_12 = 0;
    for ( n4_15 = 0; n4_12 < n4_5; n4_15 = (void *)n4_12 )
    {
      i_6 = (int *)(n4_12 << (32 - *((_BYTE *)v11 + 36)));
      v72 = __ROL4__(i_6, 16);
      i = i_6;
      v73 = (v72 << 8) ^ (unsigned int)&unk_FF00FF & ((v72 << 8) ^ (v72 >> 8));
      v74 = (16 * v73) ^ ((16 * v73) ^ (v73 >> 4)) & 0xF0F0F0F;
      v75 = (4 * v74) ^ ((4 * v74) ^ (v74 >> 2)) & 0x33333333;
      v76 = (2 * v75) ^ ((2 * v75) ^ (v75 >> 1)) & 0x55555555;
      v77 = v11[8];
      v43 = *(_DWORD *)(v77 + 4 * v76) == 0;
      v86 = (unsigned int *)(v77 + 4 * v76);
      if ( v43 )
      {
        n4_9 = n4_2;
        n4_10 = n0x7FFF_1 + 1;
        if ( (int)(n0x7FFF_1 + 1) < n4_2 )
        {
          n4_9 = n4_2;
          v80 = (_DWORD *)(v11[5] + 4 * n0x7FFF_1 + 4);
          do
          {
            if ( *v80 > (unsigned int)i )
              break;
            ++n0x7FFF_1;
            ++n4_10;
            ++v80;
          }
          while ( n4_10 < n4_2 );
          v11 = v92;
        }
        if ( n4_11 < n4_9 )
        {
          v81 = (_DWORD *)(v11[5] + 4 * n4_11);
          do
          {
            if ( (unsigned int)i < (Size & *v81) )
              break;
            ++n4_11;
            ++v81;
          }
          while ( n4_11 < n4_9 );
        }
        n0x7FFF = n0x7FFF_1;
        n0x7FFF_2 = n4_9 - n4_11;
        if ( n0x7FFF_1 > 0x7FFF )
          n0x7FFF = 0x7FFF;
        if ( n0x7FFF_2 > 0x7FFF )
          n0x7FFF_2 = 0x7FFF;
        *v86 = n0x7FFF_2 | ((*(_DWORD *)&n0x7FFF | 0xFFFF0000) << 15);
      }
      n4_12 = (signed int)n4_15 + 1;
    }
  }
  return 0;
}

