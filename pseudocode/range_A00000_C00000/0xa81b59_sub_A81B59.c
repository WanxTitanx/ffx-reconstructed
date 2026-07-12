// Function: sub_A81B59
// Address: 0xa81b59
// Size: 0xf1
// Prototype: 

int __cdecl sub_A81B59(int a1, int a2, __m128i *a3, int a4, int a5, int a6)
{
  const __m128i *v6; // eax
  __m128i si128; // xmm4
  __m128i v10; // xmm5
  __m128i v11; // xmm6
  int result; // eax
  __m128i v14; // xmm2
  __m128i v15; // xmm1
  __m128i v16; // xmm0
  __m128i v17; // xmm3

  v6 = (const __m128i *)((char *)&unk_25D7460 + 16 * a6);
  si128 = _mm_load_si128(v6);
  v10 = _mm_load_si128(v6 + 16);
  v11 = _mm_load_si128(v6 + 8);
  result = a2;
  do
  {
    v14 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(a1 - 2)), _mm_loadl_epi64((const __m128i *)(a1 + 3)));
    v15 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(a1 + 6)), _mm_loadl_epi64((const __m128i *)(a1 + 11)));
    v16 = _mm_srai_epi16(
            _mm_adds_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(
                  _mm_maddubs_epi16(v14, si128),
                  _mm_maddubs_epi16(_mm_shuffle_epi8(v14, (__m128i)xmmword_25D7430), v10)),
                _mm_maddubs_epi16(_mm_shuffle_epi8(v14, (__m128i)xmmword_25D7440), v11)),
              (__m128i)xmmword_25D7450),
            7u);
    a1 += a2;
    v17 = _mm_srai_epi16(
            _mm_adds_epi16(
              _mm_adds_epi16(
                _mm_adds_epi16(
                  _mm_maddubs_epi16(v15, si128),
                  _mm_maddubs_epi16(_mm_shuffle_epi8(v15, (__m128i)xmmword_25D7430), v10)),
                _mm_maddubs_epi16(_mm_shuffle_epi8(v15, (__m128i)xmmword_25D7440), v11)),
              (__m128i)xmmword_25D7450),
            7u);
    *a3 = _mm_unpacklo_epi64(_mm_packus_epi16(v16, v16), _mm_packus_epi16(v17, v17));
    a3 = (__m128i *)((char *)a3 + a4);
    --a5;
  }
  while ( a5 );
  return result;
}

