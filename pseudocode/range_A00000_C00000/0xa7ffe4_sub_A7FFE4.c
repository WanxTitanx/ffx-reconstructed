// Function: sub_A7FFE4
// Address: 0xa7ffe4
// Size: 0x9d
// Prototype: 

int __cdecl sub_A7FFE4(unsigned int *a1, int a2, unsigned int *a3, int a4, __m64 *a5)
{
  __m64 v6; // mm0
  __m64 v7; // mm1
  __m64 v8; // mm4
  __m64 v9; // mm5
  unsigned int *v10; // edi
  __m64 v11; // mm0
  __m64 v12; // mm7

  v6 = _m_punpcklbw(_mm_cvtsi32_si64(*a1), _mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + a2)));
  v7 = _m_psadbw(_m_punpcklbw(_mm_cvtsi32_si64(*a3), _mm_cvtsi32_si64(*(unsigned int *)((char *)a3 + a4))), v6);
  v8 = _m_psadbw(
         _m_punpcklbw(
           _mm_cvtsi32_si64(*(unsigned int *)((char *)a3 + 1)),
           _mm_cvtsi32_si64(*(unsigned int *)((char *)a3 + a4 + 1))),
         v6);
  v9 = _m_psadbw(
         _m_punpcklbw(
           _mm_cvtsi32_si64(*(unsigned int *)((char *)a3 + 2)),
           _mm_cvtsi32_si64(*(unsigned int *)((char *)a3 + a4 + 2))),
         v6);
  v10 = (unsigned int *)((char *)a3 + 2 * a4);
  v11 = _m_punpcklbw(
          _mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + 2 * a2)),
          _mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + 2 * a2 + a2)));
  v12 = _m_paddw(
          _m_psadbw(
            _m_punpcklbw(
              _mm_cvtsi32_si64(*(unsigned int *)((char *)v10 + 2)),
              _mm_cvtsi32_si64(*(unsigned int *)((char *)v10 + a4 + 2))),
            v11),
          v9);
  a5->m64_u64 = (unsigned __int64)_m_punpckldq(
                                    _m_paddw(
                                      v7,
                                      _m_psadbw(
                                        _m_punpcklbw(
                                          _mm_cvtsi32_si64(*v10),
                                          _mm_cvtsi32_si64(*(unsigned int *)((char *)v10 + a4))),
                                        v11)),
                                    _m_paddw(
                                      _m_psadbw(
                                        _m_punpcklbw(
                                          _mm_cvtsi32_si64(*(unsigned int *)((char *)v10 + 1)),
                                          _mm_cvtsi32_si64(*(unsigned int *)((char *)v10 + a4 + 1))),
                                        v11),
                                      v8));
  a5[1].m64_i32[0] = _mm_cvtsi64_si32(v12);
  return a2;
}

