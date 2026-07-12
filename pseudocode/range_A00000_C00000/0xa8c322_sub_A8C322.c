// Function: sub_A8C322
// Address: 0xa8c322
// Size: 0x12b
// Prototype: 

_DWORD *__cdecl sub_A8C322(const char *a1, int a2, const __m128i *a3, int a4, _DWORD *a5, _DWORD *a6)
{
  const __m128i *v6; // esi
  int v10; // ecx
  const char *v12; // ebx
  const char *v13; // ebx
  __m128i v14; // xmm7
  __m128i v15; // xmm6
  int n16; // ecx
  __m128i v17; // xmm1
  __m128i v18; // xmm2
  __m128i v19; // xmm3
  __m128i v20; // xmm1
  __m128i v21; // xmm3
  __m128i v22; // xmm7
  __m128i v23; // xmm1
  __m128i v24; // xmm7

  v6 = (const __m128i *)a1;
  v10 = 3 * a2;
  _mm_prefetch(a1, 1);
  _mm_prefetch(&a1[a2], 1);
  _mm_prefetch(&v6->m128i_i8[2 * a2], 1);
  _mm_prefetch(&v6->m128i_i8[v10], 1);
  v12 = &v6->m128i_i8[4 * a2];
  _mm_prefetch(v12, 1);
  _mm_prefetch(&v12[a2], 1);
  _mm_prefetch(&v12[2 * a2], 1);
  _mm_prefetch(&v12[v10], 1);
  _mm_prefetch(a3->m128i_i8, 1);
  _mm_prefetch(&a3->m128i_i8[a4], 1);
  _mm_prefetch(&a3->m128i_i8[2 * a4], 1);
  _mm_prefetch(&a3->m128i_i8[3 * a4], 1);
  v13 = &a3->m128i_i8[4 * a4];
  _mm_prefetch(v13, 1);
  _mm_prefetch(&v13[a4], 1);
  _mm_prefetch(&v13[2 * a4], 1);
  _mm_prefetch(&v13[3 * a4], 1);
  v14 = 0;
  v15 = 0;
  n16 = 16;
  do
  {
    v17 = _mm_loadu_si128(v6);
    v18 = _mm_loadu_si128(a3);
    _mm_prefetch(&v6->m128i_i8[8 * a2], 1);
    _mm_prefetch(&a3->m128i_i8[8 * a4], 1);
    v19 = v17;
    v20 = _mm_sub_epi16(_mm_unpacklo_epi8(v17, (__m128i)0LL), _mm_unpacklo_epi8(v18, (__m128i)0LL));
    v21 = _mm_sub_epi16(_mm_unpackhi_epi8(v19, (__m128i)0LL), _mm_unpackhi_epi8(v18, (__m128i)0LL));
    v14 = _mm_add_epi16(_mm_add_epi16(v14, v20), v21);
    v15 = _mm_add_epi32(_mm_add_epi32(v15, _mm_madd_epi16(v20, v20)), _mm_madd_epi16(v21, v21));
    v6 = (const __m128i *)((char *)v6 + a2);
    a3 = (const __m128i *)((char *)a3 + a4);
    --n16;
  }
  while ( n16 );
  v22 = _mm_add_epi32(
          _mm_srai_epi32(_mm_unpacklo_epi16((__m128i)0LL, v14), 0x10u),
          _mm_srai_epi32(_mm_unpackhi_epi16((__m128i)0LL, v14), 0x10u));
  v23 = _mm_add_epi32(_mm_unpacklo_epi32(v15, (__m128i)0LL), _mm_unpackhi_epi32(v15, (__m128i)0LL));
  v24 = _mm_add_epi32(_mm_unpacklo_epi32(v22, (__m128i)0LL), _mm_unpackhi_epi32(v22, (__m128i)0LL));
  *a6 = _mm_cvtsi128_si32(_mm_add_epi32(v24, _mm_srli_si128(v24, 8)));
  *a5 = _mm_cvtsi128_si32(_mm_add_epi32(_mm_srli_si128(v23, 8), v23));
  return a6;
}

