// Function: sub_A8B445
// Address: 0xa8b445
// Size: 0x45
// Prototype: 

int __cdecl sub_A8B445(__m64 *a1, int a2, int a3, _BYTE *a4, int a5)
{
  int n4; // edx
  int result; // eax
  __m64 v9; // mm0
  __m64 v10; // mm1

  n4 = 4;
  result = a5;
  do
  {
    v9 = _mm_cvtsi32_si64(*a4);
    v10 = _mm_cvtsi32_si64(a4[a5]);
    a1->m64_u64 = (unsigned __int64)_m_pshufw(_m_punpcklbw(v9, v9), 0);
    *(__m64 *)((char *)a1 + a2) = _m_pshufw(_m_punpcklbw(v10, v10), 0);
    a4 += 2 * a5;
    a1 = (__m64 *)((char *)a1 + 2 * a2);
    --n4;
  }
  while ( n4 );
  return result;
}

