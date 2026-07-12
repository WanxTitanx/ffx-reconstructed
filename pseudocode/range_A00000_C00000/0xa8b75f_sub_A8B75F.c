// Function: sub_A8B75F
// Address: 0xa8b75f
// Size: 0x4c
// Prototype: 

__m128i *__cdecl sub_A8B75F(__m128i *a1, int a2)
{
  int n2; // esi
  __m128i si128; // xmm1
  __m128i *result; // eax
  __m128i *v5; // eax

  n2 = 2;
  si128 = _mm_load_si128((const __m128i *)&xmmword_25D77A0);
  result = a1;
  do
  {
    *result = si128;
    *(__m128i *)((char *)result + a2) = si128;
    *(__m128i *)((char *)result + 2 * a2) = si128;
    *(__m128i *)((char *)result + 3 * a2) = si128;
    v5 = (__m128i *)((char *)result + 4 * a2);
    *v5 = si128;
    *(__m128i *)((char *)v5 + a2) = si128;
    *(__m128i *)((char *)v5 + 2 * a2) = si128;
    *(__m128i *)((char *)v5 + 3 * a2) = si128;
    result = (__m128i *)((char *)v5 + 4 * a2);
    --n2;
  }
  while ( n2 );
  return result;
}

