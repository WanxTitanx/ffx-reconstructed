// Function: sub_A8B61E
// Address: 0xa8b61e
// Size: 0x79
// Prototype: 

int __cdecl sub_A8B61E(__m128i *a1, int a2, const __m128i *a3)
{
  __m128i v3; // xmm2
  __m128i v4; // xmm1
  __m128i v5; // xmm1
  __m128i v6; // xmm1
  int n2; // esi
  int result; // eax
  __m128i *v10; // edx

  v3 = _mm_sad_epu8(_mm_load_si128(a3), (__m128i)0LL);
  v4 = _mm_shufflelo_epi16(
         _mm_srai_epi16(_mm_add_epi16(_mm_add_epi16(_mm_unpackhi_epi64(v3, v3), v3), (__m128i)xmmword_25D77C0), 4u),
         0);
  v5 = _mm_unpacklo_epi64(v4, v4);
  v6 = _mm_packus_epi16(v5, v5);
  n2 = 2;
  result = 3 * a2;
  do
  {
    *a1 = v6;
    *(__m128i *)((char *)a1 + a2) = v6;
    *(__m128i *)((char *)a1 + 2 * a2) = v6;
    *(__m128i *)((char *)a1 + 3 * a2) = v6;
    v10 = (__m128i *)((char *)a1 + 4 * a2);
    *v10 = v6;
    *(__m128i *)((char *)v10 + a2) = v6;
    *(__m128i *)((char *)v10 + 2 * a2) = v6;
    *(__m128i *)((char *)v10 + 3 * a2) = v6;
    a1 = (__m128i *)((char *)v10 + 4 * a2);
    --n2;
  }
  while ( n2 );
  return result;
}

