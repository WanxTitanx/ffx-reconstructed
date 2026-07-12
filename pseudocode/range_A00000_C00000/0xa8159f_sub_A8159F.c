// Function: sub_A8159F
// Address: 0xa8159f
// Size: 0xa3
// Prototype: 

__m128i *__cdecl sub_A8159F(const __m128i *a1, int a2, _QWORD *a3, int a4, int a5, __m128i *a6)
{
  __m128i *result; // eax
  __m128i si128; // xmm7
  __m128i v11; // xmm1
  __m128i v12; // xmm2
  __m128i v13; // xmm3
  __m128i v14; // xmm5

  result = a6;
  si128 = _mm_load_si128((const __m128i *)&xmmword_25D73F0);
  do
  {
    v11 = _mm_loadl_epi64(a1);
    v12 = _mm_loadl_epi64((const __m128i *)((char *)a1 + a2));
    v13 = _mm_loadl_epi64((const __m128i *)((char *)a1 + 2 * a2));
    v14 = _mm_loadl_epi64((const __m128i *)((char *)a1 + 4 * a2));
    a1 = (const __m128i *)((char *)a1 + a2);
    *a3 = _mm_packus_epi16(
            _mm_srai_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(
                  _mm_adds_epi16(
                    _mm_adds_epi16(
                      _mm_adds_epi16(
                        _mm_adds_epi16(
                          _mm_mullo_epi16(_mm_unpacklo_epi8(v12, (__m128i)0LL), a6[1]),
                          _mm_mullo_epi16(_mm_unpacklo_epi8(v14, (__m128i)0LL), a6[4])),
                        _mm_mullo_epi16(_mm_unpacklo_epi8(v13, (__m128i)0LL), a6[2])),
                      _mm_mullo_epi16(_mm_unpacklo_epi8(v11, (__m128i)0LL), *a6)),
                    _mm_mullo_epi16(
                      _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)((char *)a1 + 2 * a2)), (__m128i)0LL),
                      a6[3])),
                  _mm_mullo_epi16(
                    _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)((char *)a1 + 4 * a2)), (__m128i)0LL),
                    a6[5])),
                si128),
              7u),
            (__m128i)0LL).m128i_u64[0];
    a3 = (_QWORD *)((char *)a3 + a4);
    --a5;
  }
  while ( a5 );
  return result;
}

