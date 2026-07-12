// Function: sub_A8B534
// Address: 0xa8b534
// Size: 0xea
// Prototype: 

int __cdecl sub_A8B534(__m128i *a1, int a2, const __m128i *a3, unsigned __int8 *a4, int a5)
{
  __m128i v5; // xmm1
  unsigned __int8 *v6; // esi
  int v7; // ecx
  unsigned __int8 *v8; // esi
  __m128i v9; // xmm1
  __m128i v10; // xmm1
  __m128i v11; // xmm1
  int n2; // esi
  int result; // eax
  __m128i *v15; // edi

  v5 = _mm_sad_epu8(_mm_load_si128(a3), (__m128i)0LL);
  v6 = &a4[4 * a5];
  v7 = v6[3 * a5] + v6[2 * a5] + v6[a5] + *v6 + a4[3 * a5] + a4[2 * a5] + a4[a5] + *a4;
  v8 = &v6[4 * a5];
  v9 = _mm_shufflelo_epi16(
         _mm_cvtsi32_si128((_mm_extract_epi16(_mm_add_epi16(_mm_unpackhi_epi64(v5, v5), _mm_move_epi64(v5)), 0)
                          + v8[4 * a5 + 3 * a5]
                          + v8[4 * a5 + 2 * a5]
                          + v8[4 * a5 + a5]
                          + v8[4 * a5]
                          + v8[3 * a5]
                          + v8[2 * a5]
                          + v8[a5]
                          + *v8
                          + v7
                          + 16) >> 5),
         0);
  v10 = _mm_unpacklo_epi64(v9, v9);
  v11 = _mm_packus_epi16(v10, v10);
  n2 = 2;
  result = 3 * a2;
  do
  {
    *a1 = v11;
    *(__m128i *)((char *)a1 + a2) = v11;
    *(__m128i *)((char *)a1 + 2 * a2) = v11;
    *(__m128i *)((char *)a1 + 3 * a2) = v11;
    v15 = (__m128i *)((char *)a1 + 4 * a2);
    *v15 = v11;
    *(__m128i *)((char *)v15 + a2) = v11;
    *(__m128i *)((char *)v15 + 2 * a2) = v11;
    *(__m128i *)((char *)v15 + 3 * a2) = v11;
    a1 = (__m128i *)((char *)v15 + 4 * a2);
    --n2;
  }
  while ( n2 );
  return result;
}

