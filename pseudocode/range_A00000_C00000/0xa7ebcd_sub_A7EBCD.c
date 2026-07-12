// Function: sub_A7EBCD
// Address: 0xa7ebcd
// Size: 0x6a
// Prototype: 

unsigned int __cdecl sub_A7EBCD(__m64 *a1, int a2, __m64 *a3, int a4, unsigned int a5)
{
  __m64 *v5; // esi
  __m64 v7; // mm7
  unsigned int result; // eax
  __m64 v9; // mm0
  __m64 v10; // mm2
  __m64 v11; // mm4
  __m64 v12; // mm1

  v5 = a1;
  v7.m64_u64 = 0;
  while ( 1 )
  {
    result = _mm_cvtsi64_si32(v7);
    if ( result > a5 )
      break;
    v9 = _m_psadbw((__m64)v5->m64_u64, (__m64)a3->m64_u64);
    v10 = _m_psadbw(v5[1], a3[1]);
    v11 = _m_psadbw(*(__m64 *)((char *)v5 + a2), *(__m64 *)((char *)a3 + a4));
    v12 = _m_psadbw(*(__m64 *)((char *)v5 + a2 + 8), *(__m64 *)((char *)a3 + a4 + 8));
    v5 = (__m64 *)((char *)v5 + 2 * a2);
    a3 = (__m64 *)((char *)a3 + 2 * a4);
    v7 = _m_paddw(_m_paddw(v7, _m_paddw(v9, v10)), _m_paddw(v11, v12));
    if ( v5 == &a1[a2] )
      return _mm_cvtsi64_si32(v7);
  }
  return result;
}

