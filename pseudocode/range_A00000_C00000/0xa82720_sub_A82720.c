// Function: sub_A82720
// Address: 0xa82720
// Size: 0x99
// Prototype: 

const __m128i *__cdecl sub_A82720(const __m128i *a1, int a2, __m128i *a3, int a4, unsigned int a5)
{
  __m128i v5; // xmm0
  __m128i v6; // xmm0
  __m128i v7; // xmm1
  const __m128i *result; // eax
  int n16; // ecx
  __m128i si128; // xmm2
  __m128i v12; // xmm5

  v5 = _mm_shufflelo_epi16(_mm_cvtsi32_si128(a5), 0);
  v6 = _mm_unpacklo_epi64(v5, v5);
  v7 = _mm_sub_epi16(_mm_load_si128((const __m128i *)&xmmword_25D7670), v6);
  result = a1;
  n16 = 16;
  do
  {
    si128 = _mm_load_si128(result);
    result = (const __m128i *)((char *)result + a2);
    v12 = _mm_load_si128(a3);
    *a3 = _mm_packus_epi16(
            _mm_srli_epi16(
              _mm_add_epi16(
                _mm_add_epi16(
                  _mm_mullo_epi16(_mm_unpacklo_epi8(si128, (__m128i)0LL), v6),
                  _mm_mullo_epi16(_mm_unpacklo_epi8(v12, (__m128i)0LL), v7)),
                (__m128i)xmmword_25D7680),
              4u),
            _mm_srli_epi16(
              _mm_add_epi16(
                _mm_add_epi16(
                  _mm_mullo_epi16(_mm_unpackhi_epi8(si128, (__m128i)0LL), v6),
                  _mm_mullo_epi16(_mm_unpackhi_epi8(v12, (__m128i)0LL), v7)),
                (__m128i)xmmword_25D7680),
              4u));
    a3 = (__m128i *)((char *)a3 + a4);
    --n16;
  }
  while ( n16 );
  return result;
}

