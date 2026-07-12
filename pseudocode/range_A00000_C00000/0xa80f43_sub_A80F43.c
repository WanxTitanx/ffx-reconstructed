// Function: sub_A80F43
// Address: 0xa80f43
// Size: 0x71
// Prototype: 

_DWORD *__cdecl sub_A80F43(unsigned int a1, unsigned int *a2, int a3, _DWORD *a4, int a5)
{
  __m64 v5; // mm5
  __m64 v6; // mm5
  __m64 v7; // mm5
  __m64 v9; // mm2
  __m64 v10; // mm3
  __m64 v11; // mm4

  v5 = _m_psrawi(_m_paddw(_mm_cvtsi32_si64(a1), (__m64)0x4000400040004LL), 3u);
  v6 = _m_punpcklwd(v5, v5);
  v7 = _m_punpckldq(v6, v6);
  v9 = _m_packuswb(_m_paddsw(_m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)a2 + a3)), 0), v7), 0);
  v10 = _m_packuswb(_m_paddsw(_m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)a2 + 2 * a3)), 0), v7), 0);
  v11 = _m_packuswb(_m_paddsw(_m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)a2 + 3 * a3)), 0), v7), 0);
  *a4 = _mm_cvtsi64_si32(_m_packuswb(_m_paddsw(_m_punpcklbw(_mm_cvtsi32_si64(*a2), 0), v7), 0));
  *(_DWORD *)((char *)a4 + a5) = _mm_cvtsi64_si32(v9);
  *(_DWORD *)((char *)a4 + 2 * a5) = _mm_cvtsi64_si32(v10);
  *(_DWORD *)((char *)a4 + 3 * a5) = _mm_cvtsi64_si32(v11);
  return a4;
}

