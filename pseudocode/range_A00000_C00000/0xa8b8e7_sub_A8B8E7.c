// Function: sub_A8B8E7
// Address: 0xa8b8e7
// Size: 0x4b
// Prototype: 

__m128i *__cdecl sub_A8B8E7(__m128i *a1, int a2, const __m128i *a3)
{
  int n2; // esi
  __m128i si128; // xmm1
  __m128i *result; // eax
  __m128i *v6; // eax

  n2 = 2;
  si128 = _mm_load_si128(a3);
  result = a1;
  do
  {
    *result = si128;
    *(__m128i *)((char *)result + a2) = si128;
    *(__m128i *)((char *)result + 2 * a2) = si128;
    *(__m128i *)((char *)result + 3 * a2) = si128;
    v6 = (__m128i *)((char *)result + 4 * a2);
    *v6 = si128;
    *(__m128i *)((char *)v6 + a2) = si128;
    *(__m128i *)((char *)v6 + 2 * a2) = si128;
    *(__m128i *)((char *)v6 + 3 * a2) = si128;
    result = (__m128i *)((char *)v6 + 4 * a2);
    --n2;
  }
  while ( n2 );
  return result;
}

