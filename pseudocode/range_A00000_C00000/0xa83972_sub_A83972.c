// Function: sub_A83972
// Address: 0xa83972
// Size: 0x94
// Prototype: 

int __cdecl sub_A83972(unsigned int *a1, int a2, unsigned int *a3, int a4)
{
  __m64 v4; // mm1
  __m64 v5; // mm2
  __m64 v6; // mm2
  __m64 v7; // mm5
  __m64 v8; // mm6
  __m64 v9; // mm5
  __m64 v10; // mm1
  __m64 v11; // mm1

  v4 = _m_punpcklbw(_mm_cvtsi32_si64(*a3), _mm_cvtsi32_si64(*(unsigned int *)((char *)a3 + a4)));
  v5 = _m_punpcklbw(_mm_cvtsi32_si64(*a1), _mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + a2)));
  v6 = _m_por(_m_psubusb(v5, v4), _m_psubusb(v4, v5));
  v7 = _m_punpcklbw(
         _mm_cvtsi32_si64(*(unsigned int *)((char *)a3 + 2 * a4)),
         _mm_cvtsi32_si64(*(unsigned int *)((char *)a3 + 2 * a4 + a4)));
  v8 = _m_punpcklbw(
         _mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + 2 * a2)),
         _mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + 2 * a2 + a2)));
  v9 = _m_por(_m_psubusb(v8, v7), _m_psubusb(v7, v8));
  v10 = _m_paddw(_m_paddw(_m_punpcklbw(v6, 0), _m_punpckhbw(v6, 0)), _m_paddw(_m_punpcklbw(v9, 0), _m_punpckhbw(v9, 0)));
  v11 = _m_paddw(_m_punpcklwd(v10, 0), _m_punpckhwd(v10, 0));
  return _mm_cvtsi64_si32(_m_paddw(_m_psrlqi(v11, 0x20u), v11));
}

