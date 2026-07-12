// Function: sub_A7E6A0
// Address: 0xa7e6a0
// Size: 0x115
// Prototype: 

int __cdecl sub_A7E6A0(__m128i *a1, int a2, const __m128i *a3)
{
  __m128i si128; // xmm2
  __m128i v5; // xmm3
  __m128i v6; // xmm0
  __m128i v7; // xmm6
  __m128i v8; // xmm5
  __m128i v9; // xmm4
  __m128i v10; // xmm5
  __m128i v11; // xmm2
  __m128i v12; // xmm6
  __m128i v13; // xmm3
  __m128i v14; // xmm0
  __m128i v15; // xmm0
  __m128i v16; // xmm5
  __m128i v17; // xmm0
  __m128i v18; // xmm1
  __m128i v19; // xmm2

  si128 = _mm_load_si128((__m128i *)((char *)a1 - 2 * a2));
  v5 = _mm_load_si128((__m128i *)((char *)a1 + a2));
  v6 = _mm_load_si128(a1);
  v7 = _mm_load_si128((__m128i *)((char *)a1 - a2));
  v8 = _mm_or_si128(_mm_subs_epu8(v7, v6), _mm_subs_epu8(v6, v7));
  v9 = _mm_load_si128(xmmword_25D7010);
  v10 = _mm_cmpeq_epi8(
          _mm_subs_epu8(
            _mm_adds_epu8(
              _mm_adds_epu8(v8, v8),
              _mm_srli_epi16(
                _mm_and_si128(
                  _mm_or_si128(_mm_subs_epu8(si128, v5), _mm_subs_epu8(v5, si128)),
                  _mm_load_si128((const __m128i *)&xmmword_25D7000)),
                1u)),
            _mm_load_si128(a3)),
          (__m128i)0LL);
  v11 = _mm_subs_epi8(_mm_xor_si128(si128, v9), _mm_xor_si128(v5, v9));
  v12 = _mm_xor_si128(v7, v9);
  v13 = _mm_xor_si128(v6, v9);
  v14 = _mm_subs_epi8(v13, v12);
  v15 = _mm_and_si128(v10, _mm_adds_epi8(_mm_adds_epi8(_mm_adds_epi8(v11, v14), v14), v14));
  v16 = _mm_adds_epi8(v15, (__m128i)xmmword_25D7030);
  v17 = _mm_adds_epi8(v15, (__m128i)xmmword_25D7040);
  v18 = _mm_load_si128((const __m128i *)&xmmword_25D7080);
  v19 = _mm_load_si128((const __m128i *)&xmmword_25D7090);
  *a1 = _mm_xor_si128(
          _mm_subs_epi8(
            v13,
            _mm_or_si128(
              _mm_and_si128(_mm_srli_epi16(v17, 3u), v19),
              _mm_and_si128(_mm_cmpgt_epi8((__m128i)0LL, v17), v18))),
          v9);
  *(__m128i *)((char *)a1 - a2) = _mm_xor_si128(
                                    _mm_adds_epi8(
                                      v12,
                                      _mm_or_si128(
                                        _mm_and_si128(_mm_srli_epi16(v16, 3u), v19),
                                        _mm_and_si128(_mm_cmpgt_epi8((__m128i)0LL, v16), v18))),
                                    v9);
  return -a2;
}

