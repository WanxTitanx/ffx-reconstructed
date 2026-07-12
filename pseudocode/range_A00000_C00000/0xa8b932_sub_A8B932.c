// Function: sub_A8B932
// Address: 0xa8b932
// Size: 0x55
// Prototype: 

int __cdecl sub_A8B932(__m128i *a1, int a2, int a3, _BYTE *a4, int a5)
{
  int n8; // edx
  int result; // eax
  __m128i v9; // xmm0
  __m128i v10; // xmm1
  __m128i v11; // xmm0
  __m128i v12; // xmm1

  n8 = 8;
  result = a5;
  do
  {
    v9 = _mm_cvtsi32_si128(*a4);
    v10 = _mm_cvtsi32_si128(a4[a5]);
    v11 = _mm_shufflelo_epi16(_mm_unpacklo_epi8(v9, v9), 0);
    v12 = _mm_shufflelo_epi16(_mm_unpacklo_epi8(v10, v10), 0);
    *a1 = _mm_unpacklo_epi64(v11, v11);
    *(__m128i *)((char *)a1 + a2) = _mm_unpacklo_epi64(v12, v12);
    a4 += 2 * a5;
    a1 = (__m128i *)((char *)a1 + 2 * a2);
    --n8;
  }
  while ( n8 );
  return result;
}

