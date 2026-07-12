// Function: sub_A7EA70
// Address: 0xa7ea70
// Size: 0x82
// Prototype: 

int __cdecl sub_A7EA70(int a1, int a2, int a3, int a4)
{
  int v4; // esi
  __m128i v6; // xmm6
  __m128i v7; // xmm4
  __m128i v8; // xmm5
  __m128i v9; // xmm0
  __m128i v10; // xmm2
  __m128i v11; // xmm3

  v4 = a1;
  v6 = 0;
  do
  {
    v7 = _mm_loadl_epi64((const __m128i *)(v4 + a2));
    v8 = _mm_loadl_epi64((const __m128i *)(a3 + a4));
    v9 = _mm_sad_epu8(
           _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)v4), _mm_loadl_epi64((const __m128i *)(v4 + 8))),
           _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)a3), _mm_loadl_epi64((const __m128i *)(a3 + 8))));
    v10 = _mm_loadl_epi64((const __m128i *)(v4 + a2 + 8));
    v11 = _mm_loadl_epi64((const __m128i *)(a3 + a4 + 8));
    v4 += 2 * a2;
    a3 += 2 * a4;
    v6 = _mm_add_epi16(_mm_add_epi16(v6, v9), _mm_sad_epu8(_mm_unpacklo_epi8(v7, v10), _mm_unpacklo_epi8(v8, v11)));
  }
  while ( v4 != a1 + 8 * a2 + 8 * a2 );
  return _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v6), _mm_srli_si128(v6, 8)));
}

