// Function: sub_A7EAF2
// Address: 0xa7eaf2
// Size: 0x4f
// Prototype: 

unsigned int __cdecl sub_A7EAF2(__m64 *a1, int a2, __m64 *a3, int a4, unsigned int a5)
{
  __m64 *v5; // esi
  __m64 v7; // mm7
  unsigned int result; // eax
  __m64 v9; // mm0
  __m64 v10; // mm2

  v5 = a1;
  v7.m64_u64 = 0;
  while ( 1 )
  {
    result = _mm_cvtsi64_si32(v7);
    if ( result > a5 )
      break;
    v9 = _m_psadbw((__m64)v5->m64_u64, (__m64)a3->m64_u64);
    v10 = _m_psadbw(*(__m64 *)((char *)v5 + a2), *(__m64 *)((char *)a3 + a4));
    v5 = (__m64 *)((char *)v5 + 2 * a2);
    a3 = (__m64 *)((char *)a3 + 2 * a4);
    v7 = _m_paddw(_m_paddw(v7, v9), v10);
    if ( v5 == &a1[a2 + a2] )
      return _mm_cvtsi64_si32(v7);
  }
  return result;
}

