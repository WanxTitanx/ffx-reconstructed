// Function: sub_A81642
// Address: 0xa81642
// Size: 0x3c
// Prototype: 

int __cdecl sub_A81642(int a1, __m128i *a2, int a3, int a4, int a5)
{
  int result; // eax
  __m128i v9; // xmm3

  result = a3;
  do
  {
    v9 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(a1 + 8)), (__m128i)0LL);
    *a2 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)a1), (__m128i)0LL);
    a2[1] = v9;
    a1 += a3;
    a2 = (__m128i *)((char *)a2 + a5);
    --a4;
  }
  while ( a4 );
  return result;
}

