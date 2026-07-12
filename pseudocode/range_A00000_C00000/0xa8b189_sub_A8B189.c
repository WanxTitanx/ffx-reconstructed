// Function: sub_A8B189
// Address: 0xa8b189
// Size: 0x8c
// Prototype: 

int __cdecl sub_A8B189(__m64 *a1, int a2, __m64 *a3, unsigned __int8 *a4, int a5)
{
  unsigned __int8 *v5; // esi
  __m64 v6; // mm1
  __m64 m64_u64; // mm1
  int result; // eax
  __m64 *v9; // edx

  v5 = &a4[4 * a5];
  v6 = _m_pshufw(
         _mm_cvtsi32_si64((_m_pextrw(_m_psadbw((__m64)a3->m64_u64, 0), 0)
                         + v5[3 * a5]
                         + v5[2 * a5]
                         + v5[a5]
                         + *v5
                         + a4[3 * a5]
                         + a4[2 * a5]
                         + a4[a5]
                         + *a4
                         + 8) >> 4),
         0);
  m64_u64 = _m_packuswb(v6, v6);
  result = 3 * a2;
  v9 = (__m64 *)((char *)a1 + 4 * a2);
  a1->m64_u64 = (unsigned __int64)m64_u64;
  *(__m64 *)((char *)a1 + a2) = m64_u64;
  *(__m64 *)((char *)a1 + 2 * a2) = m64_u64;
  *(__m64 *)((char *)a1 + result) = m64_u64;
  v9->m64_u64 = (unsigned __int64)m64_u64;
  *(__m64 *)((char *)v9 + a2) = m64_u64;
  *(__m64 *)((char *)v9 + 2 * a2) = m64_u64;
  *(__m64 *)((char *)v9 + result) = m64_u64;
  return result;
}

