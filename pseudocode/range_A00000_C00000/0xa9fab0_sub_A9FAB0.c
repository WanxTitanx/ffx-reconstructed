// Function: sub_A9FAB0
// Address: 0xa9fab0
// Size: 0x3e8
// Prototype: int __fastcall(_DWORD, _DWORD)

int __fastcall sub_A9FAB0(int *a1, __m128i *a2)
{
  int v3; // ecx
  int n4_8; // edx
  int n4_10; // ebx
  int n4; // edi
  int v8; // edx
  int n4_5; // esi
  char *v10; // eax
  int v11; // edi
  int v12; // eax
  int v13; // ecx
  int n4_7; // eax
  bool v15; // zf
  __m128i *v16; // eax
  int v17; // esi
  int n4_15; // eax
  _DWORD *v19; // edi
  int v20; // ecx
  int n4_16; // eax
  int n4_9; // edx
  int n4_17; // eax
  int n4_13; // ecx
  int i_1; // eax
  int v26; // edx
  int n4_1; // ecx
  char *v28; // ebx
  __m128i v29; // xmm2
  unsigned int v30; // eax
  const __m128i *v31; // eax
  __m128i v32; // xmm1
  __m128i v33; // xmm2
  int *v34; // ebx
  unsigned int v35; // edx
  __int32 *v36; // ebx
  char *v37; // esi
  int v38; // eax
  int v39; // eax
  int v40; // edx
  int v41; // eax
  int v42; // eax
  int *p_n4; // ecx
  int *v44; // ecx
  int n4_2; // edx
  const __m128i *p_n4_1; // eax
  _BYTE v48[4]; // [esp+8h] [ebp-78h] BYREF
  __int64 n4_18; // [esp+Ch] [ebp-74h] BYREF
  __int64 v50; // [esp+14h] [ebp-6Ch]
  __int64 v51; // [esp+1Ch] [ebp-64h]
  __int64 v52; // [esp+24h] [ebp-5Ch] BYREF
  __int64 n4_12; // [esp+2Ch] [ebp-54h] BYREF
  __int64 v54; // [esp+34h] [ebp-4Ch]
  __int64 v55; // [esp+3Ch] [ebp-44h]
  __int64 v56; // [esp+44h] [ebp-3Ch]
  int i; // [esp+4Ch] [ebp-34h]
  int n4_14; // [esp+50h] [ebp-30h]
  int v59; // [esp+54h] [ebp-2Ch]
  int v60; // [esp+58h] [ebp-28h]
  int n4_4; // [esp+5Ch] [ebp-24h]
  int n4_6; // [esp+60h] [ebp-20h]
  int n4_3; // [esp+64h] [ebp-1Ch]
  int *v64; // [esp+68h] [ebp-18h]
  int v65; // [esp+6Ch] [ebp-14h]
  __m128i *v66; // [esp+70h] [ebp-10h]
  int v67; // [esp+74h] [ebp-Ch]
  int n4_11; // [esp+78h] [ebp-8h]
  int v69; // [esp+7Ch] [ebp-4h]

  v3 = a1[12];
  v67 = a1[13];
  n4_8 = a1[11];
  v64 = a1;
  n4_10 = 0;
  n4 = *a1;
  v60 = n4_8 >> 1;
  v66 = a2;
  n4_3 = n4;
  v69 = v3;
  n4_4 = n4_8;
  n4_11 = 0;
  n4_18 = 0;
  v50 = 0;
  v51 = 0;
  v52 = 0;
  if ( v67 == 1 )
  {
    if ( n4 > 0 )
    {
      v59 = (int)&n4_18 + 4 * n4;
      v16 = a2;
      v17 = v60;
      n4_15 = (char *)v16 - (char *)&n4_18;
      n4_4 = n4;
      v19 = (_DWORD *)v59;
      n4_6 = n4_15;
      do
      {
        v20 = *(_DWORD *)((char *)v19-- + n4_15 - 4) - v69;
        if ( v20 >= v17 )
          n4_16 = 2 * (v20 - v17);
        else
          n4_16 = 2 * (v17 - v20) - 1;
        if ( n4_16 >= 0 )
        {
          if ( n4_16 >= n4_8 )
            n4_16 = n4_8 - 1;
        }
        else
        {
          n4_16 = 0;
        }
        n4_10 = n4_16 + n4_8 * n4_10;
        v15 = n4_4-- == 1;
        *v19 = v20 + v69;
        n4_15 = n4_6;
      }
      while ( !v15 );
      goto LABEL_23;
    }
  }
  else if ( n4 > 0 )
  {
    v8 = v67 >> 1;
    v65 = (char *)a2 - (char *)&n4_18;
    n4_5 = n4_4;
    v10 = (char *)&n4_18 + 4 * n4;
    n4_6 = n4;
    v11 = v60;
    v59 = v67 >> 1;
    do
    {
      v60 = (int)(v10 - 4);
      v12 = (v8 + *(_DWORD *)&v10[v65 - 4] - v69) / v67;
      v13 = v12;
      if ( v12 >= v11 )
        n4_7 = 2 * (v12 - v11);
      else
        n4_7 = 2 * (v11 - v12) - 1;
      if ( n4_7 >= 0 )
      {
        if ( n4_7 >= n4_5 )
          n4_7 = n4_5 - 1;
      }
      else
      {
        n4_7 = 0;
      }
      v8 = v59;
      n4_10 = n4_7 + n4_5 * n4_10;
      v15 = n4_6-- == 1;
      v10 = (char *)v60;
      *(_DWORD *)v60 = v69 + v67 * v13;
    }
    while ( !v15 );
    n4_8 = n4_4;
LABEL_23:
    v3 = v69;
    n4 = n4_3;
    a2 = v66;
    n4_11 = n4_10;
  }
  if ( *(char *)(n4_10 + *(_DWORD *)(v64[3] + 8)) <= 0 )
  {
    v60 = -1;
    n4_9 = v3 + v67 * (n4_8 - 1);
    n4_17 = v64[1];
    n4_13 = 0;
    n4_12 = 0;
    v54 = 0;
    v55 = 0;
    v56 = 0;
    n4_4 = n4_9;
    n4_6 = 0;
    n4_14 = n4_17;
    if ( n4_17 > 0 )
    {
      a2 = v66;
      i_1 = *(_DWORD *)(v64[3] + 8);
      for ( i = i_1; ; i_1 = i )
      {
        if ( *(char *)(i_1 + n4_13) > 0 )
        {
          v26 = 0;
          n4_1 = 0;
          v65 = 0;
          if ( n4 >= 4 && n2_9 >= 2 )
          {
            v28 = (char *)&v52 + 4 * n4 + 4;
            v29 = 0;
            v30 = (unsigned int)a2 + 4 * n4 - 4;
            n4 = n4_3;
            if ( (unsigned int)&n4_12 > v30 || v28 < (char *)a2 )
            {
              v31 = a2;
              do
              {
                n4_1 += 4;
                v32 = _mm_sub_epi32(
                        _mm_loadu_si128((const __m128i *)((char *)v31 + (char *)&n4_12 - (char *)a2)),
                        _mm_loadu_si128(v31));
                v29 = _mm_add_epi32(v29, _mm_mullo_epi32(v32, v32));
                ++v31;
              }
              while ( n4_1 < n4_3 - n4_3 % 4 );
              v33 = _mm_add_epi32(v29, _mm_srli_si128(v29, 8));
              v26 = _mm_cvtsi128_si32(_mm_add_epi32(v33, _mm_srli_si128(v33, 4)));
              v65 = v26;
            }
          }
          v34 = 0;
          v64 = 0;
          v69 = 0;
          if ( n4_1 < n4 )
          {
            if ( n4 - n4_1 >= 2 )
            {
              v35 = ((unsigned int)(n4 - n4_1 - 2) >> 1) + 1;
              v36 = &a2->m128i_i32[n4_1];
              v59 = (char *)&n4_12 + 4 - (char *)a2;
              n4_1 += 2 * v35;
              v37 = (char *)((char *)&n4_12 + 4 - (char *)a2);
              do
              {
                v38 = *(__int32 *)((char *)v36 + (_DWORD)v37 - 4) - *v36;
                v36 += 2;
                v64 = (int *)((char *)v64 + v38 * v38);
                v39 = *(__int32 *)((char *)v36 + (_DWORD)v37 - 8) - *(v36 - 1);
                v69 += v39 * v39;
                --v35;
              }
              while ( v35 );
              a2 = v66;
              v34 = v64;
            }
            v40 = v65;
            if ( n4_1 < n4 )
            {
              v41 = *((_DWORD *)&n4_12 + n4_1) - a2->m128i_i32[n4_1];
              v40 = v41 * v41 + v65;
            }
            v26 = (int)v34 + v69 + v40;
          }
          if ( v60 == -1 || v26 < v60 )
          {
            n4_10 = n4_6;
            n4_18 = n4_12;
            v50 = v54;
            v51 = v55;
            v52 = v56;
            v60 = v26;
            n4_11 = n4_6;
          }
          else
          {
            n4_10 = n4_11;
          }
          n4_9 = n4_4;
        }
        v42 = 0;
        if ( (int)n4_12 >= n4_9 )
        {
          p_n4 = (int *)&n4_12;
          do
          {
            *p_n4 = 0;
            ++v42;
            p_n4 = (int *)&n4_12 + v42;
          }
          while ( *p_n4 >= n4_9 );
        }
        v44 = (int *)&n4_12 + v42;
        if ( *v44 >= 0 )
        {
          a2 = v66;
          *v44 += v67;
        }
        *v44 = -*v44;
        n4_13 = n4_6 + 1;
        n4_6 = n4_13;
        if ( n4_13 >= n4_14 )
          break;
      }
    }
  }
  if ( n4_10 > -1 )
  {
    n4_2 = 0;
    if ( n4 > 0 )
    {
      if ( (unsigned int)n4 >= 4 && (a2 > (__m128i *)&v48[4 * n4] || (char *)a2 + 4 * n4 - 4 < (char *)&n4_18) )
      {
        p_n4_1 = (const __m128i *)&n4_18;
        do
        {
          n4_2 += 4;
          *a2 = _mm_sub_epi32(_mm_loadu_si128(a2), _mm_loadu_si128(p_n4_1));
          ++a2;
          ++p_n4_1;
        }
        while ( n4_2 < n4 - (n4 & 3) );
      }
      for ( ; n4_2 < n4; a2 = (__m128i *)((char *)a2 + 4) )
        a2->m128i_i32[0] -= *((_DWORD *)&n4_18 + n4_2++);
    }
  }
  return n4_10;
}

