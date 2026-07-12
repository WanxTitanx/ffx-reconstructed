// Function: sub_A7EB7E
// Address: 0xa7eb7e
// Size: 0x4f
// Prototype: 

int __cdecl sub_A7EB7E(unsigned int *a1, int a2, unsigned int *a3, int a4)
{
  return _mm_cvtsi64_si32(
           _m_paddw(
             _m_psadbw(
               _m_punpcklbw(_mm_cvtsi32_si64(*a1), _mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + a2))),
               _m_punpcklbw(_mm_cvtsi32_si64(*a3), _mm_cvtsi32_si64(*(unsigned int *)((char *)a3 + a4)))),
             _m_psadbw(
               _m_punpcklbw(
                 _mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + 2 * a2)),
                 _mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + 2 * a2 + a2))),
               _m_punpcklbw(
                 _mm_cvtsi32_si64(*(unsigned int *)((char *)a3 + 2 * a4)),
                 _mm_cvtsi32_si64(*(unsigned int *)((char *)a3 + 2 * a4 + a4))))));
}

