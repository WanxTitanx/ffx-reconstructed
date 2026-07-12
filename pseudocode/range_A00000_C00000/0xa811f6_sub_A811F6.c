// Function: sub_A811F6
// Address: 0xa811f6
// Size: 0x8f
// Prototype: 

__m128i *__cdecl sub_A811F6(int a1, _QWORD *a2, int a3, int a4, int a5, int a6, int a7, __m128i *a8)
{
  __m128i *result; // eax
  const __m128i *v10; // esi
  __m128i si128; // xmm7
  __m128i v13; // xmm1
  __m128i v14; // xmm2
  __m128i v15; // xmm3
  __m128i v16; // xmm5

  result = a8;
  v10 = (const __m128i *)(a1 - a4 - a4);
  si128 = _mm_load_si128((const __m128i *)&xmmword_25D73F0);
  do
  {
    v13 = _mm_mullo_epi16(_mm_load_si128(v10), *a8);
    v14 = _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + a4)), a8[1]);
    v15 = _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + 2 * a4)), a8[2]);
    v16 = _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + 4 * a4)), a8[4]);
    v10 = (const __m128i *)((char *)v10 + a4);
    *a2 = _mm_packus_epi16(
            _mm_srai_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(
                  _mm_adds_epi16(
                    _mm_adds_epi16(_mm_adds_epi16(_mm_adds_epi16(v14, v16), v15), v13),
                    _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + 2 * a4)), a8[3])),
                  _mm_mullo_epi16(_mm_load_si128((const __m128i *)((char *)v10 + 4 * a4)), a8[5])),
                si128),
              7u),
            (__m128i)0LL).m128i_u64[0];
    a2 = (_QWORD *)((char *)a2 + a3);
    --a6;
  }
  while ( a6 );
  return result;
}

