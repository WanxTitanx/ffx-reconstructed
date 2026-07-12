// Function: sub_A8B697
// Address: 0xa8b697
// Size: 0xc8
// Prototype: 

int __cdecl sub_A8B697(__m128i *a1, int a2, int a3, unsigned __int8 *a4, int a5)
{
  unsigned __int8 *v5; // esi
  int v6; // ecx
  unsigned __int8 *v7; // esi
  __m128i v8; // xmm1
  __m128i v9; // xmm1
  __m128i v10; // xmm1
  int n2; // esi
  int result; // eax
  __m128i *v14; // edi

  v5 = &a4[4 * a5];
  v6 = v5[3 * a5] + v5[2 * a5] + v5[a5] + *v5 + a4[3 * a5] + a4[2 * a5] + a4[a5] + *a4;
  v7 = &v5[4 * a5];
  v8 = _mm_shufflelo_epi16(
         _mm_cvtsi32_si128((v7[4 * a5 + 2 * a5]
                          + v7[4 * a5 + a5]
                          + v7[4 * a5]
                          + v7[3 * a5]
                          + v7[2 * a5]
                          + v7[a5]
                          + *v7
                          + v6
                          + (unsigned int)v7[4 * a5 + 3 * a5]
                          + 8) >> 4),
         0);
  v9 = _mm_unpacklo_epi64(v8, v8);
  v10 = _mm_packus_epi16(v9, v9);
  n2 = 2;
  result = 3 * a2;
  do
  {
    *a1 = v10;
    *(__m128i *)((char *)a1 + a2) = v10;
    *(__m128i *)((char *)a1 + 2 * a2) = v10;
    *(__m128i *)((char *)a1 + 3 * a2) = v10;
    v14 = (__m128i *)((char *)a1 + 4 * a2);
    *v14 = v10;
    *(__m128i *)((char *)v14 + a2) = v10;
    *(__m128i *)((char *)v14 + 2 * a2) = v10;
    *(__m128i *)((char *)v14 + 3 * a2) = v10;
    a1 = (__m128i *)((char *)v14 + 4 * a2);
    --n2;
  }
  while ( n2 );
  return result;
}

