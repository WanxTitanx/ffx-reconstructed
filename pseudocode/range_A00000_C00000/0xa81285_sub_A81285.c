// Function: sub_A81285
// Address: 0xa81285
// Size: 0xf0
// Prototype: 

__m128i *__cdecl sub_A81285(int a1, __m128i *a2, int a3, int a4, int a5, int a6, int a7, __m128i *a8)
{
  __m128i *result; // eax
  const __m128i *v10; // esi
  __m128i v12; // xmm1
  __m128i v13; // xmm2
  __m128i si128; // xmm7

  result = a8;
  v10 = (const __m128i *)(a1 - a4 - a4);
  do
  {
    v12 = _mm_adds_epi16(
            _mm_adds_epi16(
              _mm_adds_epi16(
                _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + a4)), a8[1]),
                _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + 4 * a4)), a8[4])),
              _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + 2 * a4)), a8[2])),
            _mm_mullo_epi16(_mm_load_si128(v10), *a8));
    v13 = _mm_adds_epi16(
            _mm_adds_epi16(
              _mm_adds_epi16(
                _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + a4 + 16)), a8[1]),
                _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + 4 * a4 + 16)), a8[4])),
              _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + 2 * a4 + 16)), a8[2])),
            _mm_mullo_epi16(_mm_load_si128(v10 + 1), *a8));
    v10 = (const __m128i *)((char *)v10 + a4);
    si128 = _mm_load_si128((const __m128i *)&xmmword_25D73F0);
    *a2 = _mm_packus_epi16(
            _mm_srai_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(
                  _mm_adds_epi16(v12, _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + 2 * a4)), a8[3])),
                  _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + 4 * a4)), a8[5])),
                si128),
              7u),
            _mm_srai_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(
                  _mm_adds_epi16(
                    v13,
                    _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + 2 * a4 + 16)), a8[3])),
                  _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + 4 * a4 + 16)), a8[5])),
                si128),
              7u));
    a2 = (__m128i *)((char *)a2 + a3);
    --a6;
  }
  while ( a6 );
  return result;
}

