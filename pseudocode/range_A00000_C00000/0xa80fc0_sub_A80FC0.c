// Function: sub_A80FC0
// Address: 0xa80fc0
// Size: 0xcc
// Prototype: 

int __cdecl sub_A80FC0(int a1, __m128i *a2, int a3, int a4, int a5, int a6, __m128i *a7)
{
  int result; // eax
  __m128i v11; // xmm3
  __m128i v12; // xmm1
  __m128i v13; // xmm1

  result = a3;
  do
  {
    v11 = _mm_loadl_epi64((const __m128i *)(a1 - 2));
    v12 = _mm_loadl_epi64((const __m128i *)(a1 + 6));
    _mm_prefetch((const char *)(a1 + a3 - 2), 3);
    v13 = _mm_or_si128(_mm_slli_si128(v12, 8), v11);
    *a2 = _mm_unpacklo_epi8(
            _mm_packus_epi16(
              _mm_srai_epi16(
                _mm_adds_epi16(
                  _mm_adds_epi16(
                    _mm_adds_epi16(
                      _mm_adds_epi16(
                        _mm_adds_epi16(
                          _mm_adds_epi16(
                            _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_srli_si128(v13, 1), (__m128i)0LL), a7[1]),
                            _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_srli_si128(v13, 4), (__m128i)0LL), a7[4])),
                          _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_srli_si128(v13, 2), (__m128i)0LL), a7[2])),
                        _mm_mullo_epi16(_mm_unpacklo_epi8(v11, (__m128i)0LL), *a7)),
                      _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_srli_si128(v13, 3), (__m128i)0LL), a7[3])),
                    _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_srli_si128(v13, 5), (__m128i)0LL), a7[5])),
                  (__m128i)xmmword_25D73F0),
                7u),
              (__m128i)0LL),
            (__m128i)0LL);
    a1 += a3;
    a2 = (__m128i *)((char *)a2 + a6);
    --a5;
  }
  while ( a5 );
  return result;
}

