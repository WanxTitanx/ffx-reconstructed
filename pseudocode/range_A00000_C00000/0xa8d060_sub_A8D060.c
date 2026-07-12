// Function: sub_A8D060
// Address: 0xa8d060
// Size: 0xa7
// Prototype: 

unsigned __int64 *__cdecl sub_A8D060(int a1, unsigned int *a2, __m128i *a3, int a4)
{
  __m128i v4; // xmm4
  __m128i v5; // xmm4
  unsigned __int64 v6; // xmm1_8
  unsigned __int64 v7; // xmm2_8
  unsigned __int64 v8; // xmm3_8
  unsigned __int64 *result; // eax

  v4 = _mm_mullo_epi16(
         _mm_insert_epi16(_mm_cvtsi32_si128(*(_DWORD *)a1), *(unsigned __int16 *)(a1 + 32), 4),
         _mm_insert_epi16(_mm_cvtsi32_si128(*a2), *(unsigned __int16 *)a2, 4));
  *(_DWORD *)a1 = _mm_cvtsi128_si32((__m128i)0LL);
  *(_DWORD *)(a1 + 32) = _mm_cvtsi128_si32((__m128i)0LL);
  v5 = _mm_srai_epi16(_mm_add_epi16(_mm_shufflehi_epi16(_mm_shufflelo_epi16(v4, 0), 0), (__m128i)xmmword_25D79D0), 3u);
  v6 = _mm_packus_epi16(
         _mm_add_epi16(_mm_unpacklo_epi8(_mm_loadl_epi64((__m128i *)((char *)a3 + a4)), (__m128i)0LL), v5),
         (__m128i)0LL).m128i_u64[0];
  v7 = _mm_packus_epi16(
         _mm_add_epi16(_mm_unpacklo_epi8(_mm_loadl_epi64((__m128i *)((char *)a3 + 2 * a4)), (__m128i)0LL), v5),
         (__m128i)0LL).m128i_u64[0];
  v8 = _mm_packus_epi16(
         _mm_add_epi16(_mm_unpacklo_epi8(_mm_loadl_epi64((__m128i *)((char *)a3 + 3 * a4)), (__m128i)0LL), v5),
         (__m128i)0LL).m128i_u64[0];
  a3->m128i_i64[0] = _mm_packus_epi16(
                       _mm_add_epi16(_mm_unpacklo_epi8(_mm_loadl_epi64(a3), (__m128i)0LL), v5),
                       (__m128i)0LL).m128i_u64[0];
  *(__int64 *)((char *)a3->m128i_i64 + a4) = v6;
  result = (unsigned __int64 *)((char *)a3 + 2 * a4);
  *result = v7;
  *(unsigned __int64 *)((char *)result + a4) = v8;
  return result;
}

