// Function: sub_A81375
// Address: 0xa81375
// Size: 0xc8
// Prototype: 

int __cdecl sub_A81375(int a1, int a2, _QWORD *a3, int a4, int a5, __m128i *a6)
{
  int result; // eax
  __m128i v10; // xmm3
  __m128i v11; // xmm1
  __m128i v12; // xmm1

  result = a2;
  do
  {
    v10 = _mm_loadl_epi64((const __m128i *)(a1 - 2));
    v11 = _mm_loadl_epi64((const __m128i *)(a1 + 6));
    _mm_prefetch((const char *)(a1 + a2 - 2), 3);
    v12 = _mm_or_si128(_mm_slli_si128(v11, 8), v10);
    *a3 = _mm_packus_epi16(
            _mm_srai_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(
                  _mm_adds_epi16(
                    _mm_adds_epi16(
                      _mm_adds_epi16(
                        _mm_adds_epi16(
                          _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_srli_si128(v12, 1), (__m128i)0LL), a6[1]),
                          _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_srli_si128(v12, 4), (__m128i)0LL), a6[4])),
                        _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_srli_si128(v12, 2), (__m128i)0LL), a6[2])),
                      _mm_mullo_epi16(_mm_unpacklo_epi8(v10, (__m128i)0LL), *a6)),
                    _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_srli_si128(v12, 3), (__m128i)0LL), a6[3])),
                  _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_srli_si128(v12, 5), (__m128i)0LL), a6[5])),
                (__m128i)xmmword_25D73F0),
              7u),
            (__m128i)0LL).m128i_u64[0];
    a1 += a2;
    a3 = (_QWORD *)((char *)a3 + a4);
    --a5;
  }
  while ( a5 );
  return result;
}

