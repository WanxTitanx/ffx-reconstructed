// Function: sub_A827B9
// Address: 0xa827b9
// Size: 0x70
// Prototype: 

const __m128i *__cdecl sub_A827B9(const __m128i *a1, int a2, __m128i *a3, int a4, unsigned int a5)
{
  __m128i v5; // xmm0
  __m128i v6; // xmm0
  __m128i v7; // xmm1
  const __m128i *result; // eax
  int n8; // ecx
  __m128i v11; // xmm2

  v5 = _mm_shufflelo_epi16(_mm_cvtsi32_si128(a5), 0);
  v6 = _mm_unpacklo_epi64(v5, v5);
  v7 = _mm_sub_epi16(_mm_load_si128((const __m128i *)&xmmword_25D7670), v6);
  result = a1;
  n8 = 8;
  do
  {
    v11 = _mm_loadl_epi64(result);
    result = (const __m128i *)((char *)result + a2);
    a3->m128i_i64[0] = _mm_packus_epi16(
                         _mm_srli_epi16(
                           _mm_add_epi16(
                             _mm_add_epi16(
                               _mm_mullo_epi16(_mm_unpacklo_epi8(v11, (__m128i)0LL), v6),
                               _mm_mullo_epi16(_mm_unpacklo_epi8(_mm_loadl_epi64(a3), (__m128i)0LL), v7)),
                             (__m128i)xmmword_25D7680),
                           4u),
                         (__m128i)0LL).m128i_u64[0];
    a3 = (__m128i *)((char *)a3 + a4);
    --n8;
  }
  while ( n8 );
  return result;
}

