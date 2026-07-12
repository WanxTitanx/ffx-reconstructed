// Function: sub_AA2700
// Address: 0xaa2700
// Size: 0x2e6
// Prototype: 

_DWORD *__cdecl sub_AA2700(int a1, int *a2)
{
  int v2; // esi
  int v3; // edi
  _DWORD *v4; // ebx
  int n2; // edx
  int v6; // ecx
  int n2_1; // eax
  _DWORD *v8; // ecx
  unsigned int v9; // edx
  int v10; // eax
  signed int n4; // esi
  signed int n4_1; // ecx
  __m128i si128; // xmm2
  int *v14; // edi
  __m128i v15; // xmm3
  __m128i v16; // xmm1
  __m128i *Base_1; // eax
  __m128i v18; // xmm0
  int *v19; // eax
  int *v20; // edi
  signed int n4_2; // ecx
  int *v22; // edx
  int v23; // eax
  signed int n4_3; // ecx
  int *v25; // edx
  int v26; // eax
  signed int i; // ecx
  int v28; // eax
  int *n2_8; // edx
  int n2_2; // esi
  int v31; // eax
  int n2_3; // ecx
  int *v33; // edx
  int v34; // ebx
  int v35; // eax
  bool v36; // zf
  _DWORD Base[66]; // [esp+Ch] [ebp-124h] BYREF
  _DWORD *v39; // [esp+114h] [ebp-1Ch]
  int v40; // [esp+118h] [ebp-18h]
  int n2_6; // [esp+11Ch] [ebp-14h]
  int n2_7; // [esp+120h] [ebp-10h]
  _DWORD *v43; // [esp+124h] [ebp-Ch]
  int n2_5; // [esp+128h] [ebp-8h]
  int *n2_4; // [esp+12Ch] [ebp-4h]

  v2 = 0;
  v3 = 0;
  v4 = calloc_0(1u, 0x520u);
  v39 = v4;
  memset(v4, 0, 0x520u);
  v4[324] = a2;
  v4[322] = a2[210];
  n2 = *a2;
  v6 = 0;
  n2_1 = 0;
  n2_4 = (int *)n2;
  if ( n2 >= 2 )
  {
    v8 = a2 + 2;
    v9 = ((unsigned int)(n2 - 2) >> 1) + 1;
    n2_5 = 2 * v9;
    do
    {
      v10 = *(v8 - 1);
      v8 += 2;
      v2 += a2[v10 + 32];
      v3 += a2[*(v8 - 2) + 32];
      --v9;
    }
    while ( v9 );
    v4 = v39;
    n2_1 = n2_5;
    n2 = (int)n2_4;
    v6 = 0;
  }
  if ( n2_1 < n2 )
    v6 = a2[a2[n2_1 + 1] + 32];
  n4 = v6 + v3 + v2 + 2;
  n4_1 = 0;
  v4[321] = n4;
  if ( n4 > 0 )
  {
    if ( (unsigned int)n4 < 4 || n2_9 < 2 )
    {
      v14 = a2;
    }
    else
    {
      si128 = _mm_load_si128((const __m128i *)&xmmword_B92360);
      v14 = a2;
      v15 = _mm_load_si128((const __m128i *)&xmmword_B92370);
      v16 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128((unsigned int)a2), 0), (__m128i)xmmword_B92380);
      Base_1 = (__m128i *)Base;
      do
      {
        v18 = _mm_add_epi32(
                _mm_mullo_epi32(_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(n4_1), 0), si128), v15),
                v16);
        n4_1 += 4;
        *Base_1++ = v18;
      }
      while ( n4_1 < (int)(n4 - (n4 & 0x80000003)) );
    }
    if ( n4_1 < n4 )
    {
      v19 = &v14[n4_1 + 209];
      do
        Base[n4_1++] = v19++;
      while ( n4_1 < n4 );
    }
  }
  qsort(Base, n4, 4u, sub_AA2D60);
  v20 = a2;
  n4_2 = 0;
  if ( n4 > 0 )
  {
    v22 = v4 + 65;
    do
    {
      v23 = (Base[n4_2++] - (int)a2 - 836) >> 2;
      *v22++ = v23;
    }
    while ( n4_2 < n4 );
  }
  n4_3 = 0;
  if ( n4 > 0 )
  {
    v25 = v4 + 65;
    do
    {
      v26 = *v25++;
      v4[v26 + 130] = n4_3++;
    }
    while ( n4_3 < n4 );
  }
  for ( i = 0; i < n4; v4[i - 1] = a2[v28 + 209] )
    v28 = v4[i++ + 65];
  switch ( a2[208] )
  {
    case 1:
      v4[323] = 256;
      break;
    case 2:
      v4[323] = 128;
      break;
    case 3:
      v4[323] = 86;
      break;
    case 4:
      v4[323] = 64;
      break;
    default:
      break;
  }
  n2_5 = n4 - 2;
  if ( n4 - 2 > 0 )
  {
    n2_8 = v4 + 195;
    n2_2 = 2;
    n2_4 = v4 + 195;
    v43 = a2 + 211;
    do
    {
      v31 = v4[322];
      n2_3 = 0;
      n2_6 = 0;
      n2_7 = 1;
      v40 = 0;
      Base[65] = v31;
      if ( n2_2 > 0 )
      {
        v33 = v20 + 209;
        v34 = v31;
        do
        {
          v35 = *v33;
          if ( *v33 > v40 && v35 < *v43 )
          {
            n2_6 = n2_3;
            v40 = v35;
          }
          if ( v35 < v34 && v35 > *v43 )
          {
            n2_7 = n2_3;
            v34 = v35;
          }
          ++n2_3;
          ++v33;
        }
        while ( n2_3 < n2_2 );
        v4 = v39;
        v20 = a2;
        n2_8 = n2_4;
      }
      ++v43;
      n2_8[63] = n2_6;
      *n2_8++ = n2_7;
      ++n2_2;
      v36 = n2_5-- == 1;
      n2_4 = n2_8;
    }
    while ( !v36 );
  }
  return v4;
}

