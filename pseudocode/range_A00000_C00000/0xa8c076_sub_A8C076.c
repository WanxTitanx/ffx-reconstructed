// Function: sub_A8C076
// Address: 0xa8c076
// Size: 0xde
// Prototype: 

__int64 __cdecl sub_A8C076(unsigned int *a1, int a2, unsigned int *a3, int a4, __int64 a5, _DWORD *a6, _DWORD *a7)
{
  __m64 v7; // mm6
  __m64 v8; // mm7
  __int64 result; // rax
  int n4; // ecx
  __m64 v12; // mm5
  unsigned int *v13; // esi
  __m64 v14; // mm3
  __m64 v15; // mm1
  __m64 v16; // mm2

  v7.m64_u64 = 0;
  v8.m64_u64 = 0;
  result = a5;
  n4 = 4;
  v12 = _m_psrawi(
          _m_paddw(
            _m_paddw(
              _m_pmullw(_m_punpcklbw(_mm_cvtsi32_si64(*a1), 0), *(__m64 *)a5),
              _m_pmullw(_m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + 1)), 0), *(__m64 *)(a5 + 8))),
            (__m64)0x40004000400040LL),
          7u);
  v13 = (unsigned int *)((char *)a1 + a2);
  do
  {
    v14 = v12;
    v12 = _m_psrawi(
            _m_paddw(
              _m_paddw(
                _m_pmullw(_m_punpcklbw(_mm_cvtsi32_si64(*v13), 0), *(__m64 *)a5),
                _m_pmullw(_m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)v13 + 1)), 0), *(__m64 *)(a5 + 8))),
              (__m64)0x40004000400040LL),
            7u);
    v15 = _m_psubw(
            _m_psrawi(
              _m_paddw(
                _m_paddw(
                  _m_pmullw(v12, *(__m64 *)(HIDWORD(a5) + 8)),
                  _m_pmullw(v14, (__m64)((__m64 *)HIDWORD(a5))->m64_u64)),
                (__m64)0x40004000400040LL),
              7u),
            _m_punpcklbw(_mm_cvtsi32_si64(*a3), 0));
    v7 = _m_paddw(v7, v15);
    v8 = _m_paddd(v8, _m_pmaddwd(v15, v15));
    v13 = (unsigned int *)((char *)v13 + a2);
    a3 = (unsigned int *)((char *)a3 + a4);
    --n4;
  }
  while ( n4 );
  v16 = _m_paddd(_m_punpcklwd(0, v7), _m_punpckhwd(0, v7));
  *a6 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(v16, _m_psrlqi(v16, 0x20u)), 0x10u));
  *a7 = _mm_cvtsi64_si32(_m_paddd(_m_psrlqi(v8, 0x20u), v8));
  return result;
}

