// Function: sub_A8B7AB
// Address: 0xa8b7ab
// Size: 0xa6
// Prototype: 

int __cdecl sub_A8B7AB(__m128i *a1, int a2, const __m128i *a3, _BYTE *a4, int a5)
{
  int n8; // edx
  int result; // eax
  __m128i si128; // xmm2
  __m128i v9; // xmm4
  __m128i v10; // xmm4
  __m128i v11; // xmm1
  __m128i v12; // xmm2
  __m128i v14; // xmm4
  __m128i v15; // xmm5
  __m128i v16; // xmm6
  __m128i v17; // xmm7

  n8 = 8;
  result = a5;
  si128 = _mm_load_si128(a3);
  v9 = _mm_shufflelo_epi16(
         _mm_unpacklo_epi8(_mm_cvtsi32_si128(*(unsigned __int32 *)((char *)&a3[-1].m128i_u32[3] + 3)), (__m128i)0LL),
         0);
  v10 = _mm_unpacklo_epi64(v9, v9);
  v11 = _mm_sub_epi16(_mm_unpacklo_epi8(si128, (__m128i)0LL), v10);
  v12 = _mm_sub_epi16(_mm_unpackhi_epi8(si128, (__m128i)0LL), v10);
  do
  {
    v14 = _mm_shufflelo_epi16(_mm_unpacklo_epi8(_mm_cvtsi32_si128(*a4), (__m128i)0LL), 0);
    v15 = _mm_shufflelo_epi16(_mm_unpacklo_epi8(_mm_cvtsi32_si128(a4[a5]), (__m128i)0LL), 0);
    v16 = _mm_unpacklo_epi64(v14, v14);
    v17 = _mm_unpacklo_epi64(v15, v15);
    *a1 = _mm_packus_epi16(_mm_add_epi16(v16, v11), _mm_add_epi16(v16, v12));
    *(__m128i *)((char *)a1 + a2) = _mm_packus_epi16(_mm_add_epi16(v17, v11), _mm_add_epi16(v17, v12));
    a4 += 2 * a5;
    a1 = (__m128i *)((char *)a1 + 2 * a2);
    --n8;
  }
  while ( n8 );
  return result;
}

