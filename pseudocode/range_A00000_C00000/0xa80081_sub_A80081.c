// Function: sub_A80081
// Address: 0xa80081
// Size: 0x86
// Prototype: 

int __cdecl sub_A80081(const __m128i *a1, int a2, const __m128i *a3, int a4)
{
  int n4; // ecx
  __m128i v7; // xmm7
  __m128i si128; // xmm0
  __m128i v9; // xmm1
  __m128i v10; // xmm2
  __m128i v11; // xmm3
  const __m128i *v12; // esi
  const __m128i *v13; // edi
  __m128i v14; // xmm4
  __m128i v15; // xmm6

  n4 = 4;
  v7 = 0;
  do
  {
    si128 = _mm_load_si128(a1);
    v9 = _mm_loadu_si128(a3);
    v10 = _mm_load_si128((const __m128i *)((char *)a1 + a2));
    v11 = _mm_loadu_si128((const __m128i *)((char *)a3 + a4));
    v12 = (const __m128i *)((char *)a1 + 2 * a2);
    v13 = (const __m128i *)((char *)a3 + 2 * a4);
    v14 = _mm_sad_epu8(_mm_load_si128(v12), _mm_loadu_si128(v13));
    v15 = _mm_sad_epu8(
            _mm_load_si128((const __m128i *)((char *)v12 + a2)),
            _mm_loadu_si128((const __m128i *)((char *)v13 + a4)));
    a1 = (const __m128i *)((char *)v12 + 2 * a2);
    a3 = (const __m128i *)((char *)v13 + 2 * a4);
    v7 = _mm_add_epi16(
           _mm_add_epi16(_mm_add_epi16(_mm_add_epi16(v7, _mm_sad_epu8(si128, v9)), _mm_sad_epu8(v10, v11)), v14),
           v15);
    --n4;
  }
  while ( n4 );
  return _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v7), _mm_srli_si128(v7, 8)));
}

