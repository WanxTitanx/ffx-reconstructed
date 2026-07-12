// Function: sub_A7F6FA
// Address: 0xa7f6fa
// Size: 0x59
// Prototype: 

int __cdecl sub_A7F6FA(int a1, int a2, __m128i *a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // edi
  int v9; // eax
  int result; // eax

  do
  {
    v8 = (unsigned __int8)rand_0() + a2;
    v9 = 0;
    do
    {
      *(__m128i *)(a1 + v9) = _mm_add_epi8(
                                _mm_subs_epu8(
                                  _mm_adds_epu8(_mm_subs_epu8(_mm_loadu_si128((const __m128i *)(a1 + v9)), *a3), a3[2]),
                                  a3[1]),
                                _mm_loadu_si128((const __m128i *)(v8 + v9)));
      v9 += 16;
    }
    while ( v9 < a6 );
    result = a8;
    a1 += a8;
  }
  while ( a7-- > 1 );
  return result;
}

