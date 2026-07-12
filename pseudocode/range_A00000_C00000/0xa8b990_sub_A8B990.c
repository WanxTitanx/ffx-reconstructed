// Function: sub_A8B990
// Address: 0xa8b990
// Size: 0x3f
// Prototype: 

__m64 *__cdecl sub_A8B990(__m64 *a1, __m64 *a2, __m64 *a3)
{
  a2->m64_u64 = (unsigned __int64)_m_pmullw((__m64)a1->m64_u64, (__m64)a3->m64_u64);
  a2[1].m64_u64 = (unsigned __int64)_m_pmullw(a1[1], a3[1]);
  a2[2].m64_u64 = (unsigned __int64)_m_pmullw(a1[2], a3[2]);
  a2[3].m64_u64 = (unsigned __int64)_m_pmullw(a1[3], a3[3]);
  return a3;
}

