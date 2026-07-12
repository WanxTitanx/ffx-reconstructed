// Function: sub_A8B851
// Address: 0xa8b851
// Size: 0x96
// Prototype: 

int __cdecl sub_A8B851(__m128i *a1, int a2, const __m128i *a3, _BYTE *a4, int a5)
{
  int n8; // edx
  int result; // eax
  __m128i si128; // xmm3
  __m128i v8; // xmm2
  __m128i v10; // xmm4
  __m128i v11; // xmm1
  __m128i v12; // xmm2
  __m128i v14; // xmm6
  __m128i v15; // xmm7

  n8 = 8;
  result = a5;
  si128 = _mm_load_si128((const __m128i *)&xmmword_25D77D0);
  v8 = _mm_load_si128(a3);
  v10 = _mm_shuffle_epi8(_mm_cvtsi32_si128(*(unsigned __int32 *)((char *)&a3[-1].m128i_u32[3] + 3)), si128);
  v11 = _mm_sub_epi16(_mm_unpacklo_epi8(v8, (__m128i)0LL), v10);
  v12 = _mm_sub_epi16(_mm_unpackhi_epi8(v8, (__m128i)0LL), v10);
  do
  {
    v14 = _mm_shuffle_epi8(_mm_cvtsi32_si128(*a4), si128);
    v15 = _mm_shuffle_epi8(_mm_cvtsi32_si128(a4[a5]), si128);
    *a1 = _mm_packus_epi16(_mm_add_epi16(v14, v11), _mm_add_epi16(v14, v12));
    *(__m128i *)((char *)a1 + a2) = _mm_packus_epi16(_mm_add_epi16(v15, v11), _mm_add_epi16(v15, v12));
    a4 += 2 * a5;
    a1 = (__m128i *)((char *)a1 + 2 * a2);
    --n8;
  }
  while ( n8 );
  return result;
}

