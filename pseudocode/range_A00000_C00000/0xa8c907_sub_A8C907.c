// Function: sub_A8C907
// Address: 0xa8c907
// Size: 0xf7
// Prototype: 

int __cdecl sub_A8C907(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, _DWORD *a7)
{
  __m128i v7; // xmm6
  __m128i v8; // xmm7
  int result; // eax
  __m128i v12; // xmm5
  int v13; // esi
  __m128i v14; // xmm1
  __m128i v15; // xmm4
  __m128i v16; // xmm5
  __m128i v17; // xmm4
  __m128i v18; // xmm1
  __m128i v19; // xmm6
  __m128i v20; // xmm0

  v7 = 0;
  v8 = 0;
  result = a2;
  v12 = _mm_avg_epu8(_mm_loadu_si128((const __m128i *)a1), _mm_loadu_si128((const __m128i *)(a1 + 1)));
  v13 = a1 + a2;
  do
  {
    v14 = _mm_avg_epu8(_mm_loadu_si128((const __m128i *)v13), _mm_loadu_si128((const __m128i *)(v13 + 1)));
    v15 = _mm_avg_epu8(v12, v14);
    v16 = _mm_sub_epi16(
            _mm_unpacklo_epi8(v15, (__m128i)0LL),
            _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)a3), (__m128i)0LL));
    v17 = _mm_sub_epi16(
            _mm_unpackhi_epi8(v15, (__m128i)0LL),
            _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(a3 + 8)), (__m128i)0LL));
    v7 = _mm_add_epi16(_mm_add_epi16(v7, v16), v17);
    v8 = _mm_add_epi32(_mm_add_epi32(v8, _mm_madd_epi16(v16, v16)), _mm_madd_epi16(v17, v17));
    v12 = v14;
    v13 += a2;
    a3 += a4;
    --a5;
  }
  while ( a5 );
  v18 = _mm_add_epi32(
          _mm_srai_epi32(_mm_unpacklo_epi16((__m128i)0LL, v7), 0x10u),
          _mm_srai_epi32(_mm_unpackhi_epi16((__m128i)0LL, v7), 0x10u));
  v19 = _mm_add_epi32(_mm_unpacklo_epi32(v8, (__m128i)0LL), _mm_unpackhi_epi32(v8, (__m128i)0LL));
  v20 = _mm_add_epi32(_mm_unpacklo_epi32(v18, (__m128i)0LL), _mm_unpackhi_epi32(v18, (__m128i)0LL));
  *a6 = _mm_cvtsi128_si32(_mm_add_epi32(v20, _mm_srli_si128(v20, 8)));
  *a7 = _mm_cvtsi128_si32(_mm_add_epi32(v19, _mm_srli_si128(v19, 8)));
  return result;
}

