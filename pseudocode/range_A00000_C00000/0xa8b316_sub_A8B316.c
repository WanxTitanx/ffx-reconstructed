// Function: sub_A8B316
// Address: 0xa8b316
// Size: 0x85
// Prototype: 

int __cdecl sub_A8B316(_QWORD *a1, int a2, const __m128i *a3, _BYTE *a4, int a5)
{
  int n4; // edx
  int result; // eax
  __m128i v8; // xmm3
  __m128i v9; // xmm1
  __m128i v11; // xmm3
  __m128i v12; // xmm5
  __m128 v13; // xmm3

  n4 = 4;
  result = a5;
  v8 = _mm_shufflelo_epi16(
         _mm_unpacklo_epi8(_mm_cvtsi32_si128(*(unsigned __int32 *)((char *)&a3[-1].m128i_u32[3] + 3)), (__m128i)0LL),
         0);
  v9 = _mm_sub_epi16(_mm_unpacklo_epi8(_mm_loadl_epi64(a3), (__m128i)0LL), _mm_unpacklo_epi64(v8, v8));
  do
  {
    v11 = _mm_shufflelo_epi16(_mm_unpacklo_epi8(_mm_cvtsi32_si128(*a4), (__m128i)0LL), 0);
    v12 = _mm_shufflelo_epi16(_mm_unpacklo_epi8(_mm_cvtsi32_si128(a4[a5]), (__m128i)0LL), 0);
    v13 = (__m128)_mm_packus_epi16(
                    _mm_add_epi16(_mm_unpacklo_epi64(v11, v11), v9),
                    _mm_add_epi16(_mm_unpacklo_epi64(v12, v12), v9));
    *a1 = v13.m128_u64[0];
    _mm_storeh_ps((double *)((char *)a1 + a2), v13);
    a4 += 2 * a5;
    a1 = (_QWORD *)((char *)a1 + 2 * a2);
    --n4;
  }
  while ( n4 );
  return result;
}

