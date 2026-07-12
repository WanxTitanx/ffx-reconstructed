// Function: sub_A8B39B
// Address: 0xa8b39b
// Size: 0x75
// Prototype: 

int __cdecl sub_A8B39B(_QWORD *a1, int a2, const __m128i *a3, _BYTE *a4, int a5)
{
  int n4; // edx
  int result; // eax
  __m128i si128; // xmm2
  __m128i v9; // xmm1
  __m128 v11; // xmm3

  n4 = 4;
  result = a5;
  si128 = _mm_load_si128((const __m128i *)&xmmword_25D77D0);
  v9 = _mm_sub_epi16(
         _mm_unpacklo_epi8(_mm_loadl_epi64(a3), (__m128i)0LL),
         _mm_shuffle_epi8(_mm_cvtsi32_si128(*(unsigned __int32 *)((char *)&a3[-1].m128i_u32[3] + 3)), si128));
  do
  {
    v11 = (__m128)_mm_packus_epi16(
                    _mm_add_epi16(_mm_shuffle_epi8(_mm_cvtsi32_si128(*a4), si128), v9),
                    _mm_add_epi16(_mm_shuffle_epi8(_mm_cvtsi32_si128(a4[a5]), si128), v9));
    *a1 = v11.m128_u64[0];
    _mm_storeh_ps((double *)((char *)a1 + a2), v11);
    a4 += 2 * a5;
    a1 = (_QWORD *)((char *)a1 + 2 * a2);
    --n4;
  }
  while ( n4 );
  return result;
}

