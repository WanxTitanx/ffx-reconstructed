// Function: sub_A7F026
// Address: 0xa7f026
// Size: 0xb2
// Prototype: 

__m64 *__cdecl sub_A7F026(unsigned int *a1, int a2, int a3, int a4, _DWORD *a5, int a6)
{
  _DWORD *v6; // edi
  __m64 *v7; // eax
  __m64 m64_u64; // mm1
  __m64 v9; // mm2
  __m64 *result; // eax
  __m64 v11; // mm7
  unsigned int *v12; // esi
  __m64 v13; // mm5
  __m64 v14; // mm3

  v6 = a5;
  v7 = (__m64 *)((char *)&unk_B81350 + 32 * a3);
  m64_u64 = (__m64)v7->m64_u64;
  v9 = v7[2];
  result = (__m64 *)((char *)&unk_B81350 + 32 * a4);
  v11 = _m_packuswb(
          _m_psrawi(
            _m_paddw(
              _m_paddw(
                _m_pmullw(_m_punpcklbw(_mm_cvtsi32_si64(*a1), 0), m64_u64),
                _m_pmullw(_m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + 1)), 0), v9)),
              (__m64)0x40004000400040LL),
            7u),
          0);
  v12 = (unsigned int *)((char *)a1 + a2);
  do
  {
    v13 = _m_pmullw(_m_punpcklbw(v11, 0), (__m64)result->m64_u64);
    v14 = _m_psrawi(
            _m_paddw(
              _m_paddw(
                _m_pmullw(_m_punpcklbw(_mm_cvtsi32_si64(*v12), 0), m64_u64),
                _m_pmullw(_m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)v12 + 1)), 0), v9)),
              (__m64)0x40004000400040LL),
            7u);
    v11 = _m_packuswb(v14, 0);
    *v6 = _mm_cvtsi64_si32(_m_packuswb(_m_psrawi(_m_paddw(_m_paddw(_m_pmullw(v14, result[2]), v13), (__m64)0x40004000400040LL), 7u), 0));
    v12 = (unsigned int *)((char *)v12 + a2);
    v6 = (_DWORD *)((char *)v6 + a6);
  }
  while ( v6 != &a5[a6] );
  return result;
}

