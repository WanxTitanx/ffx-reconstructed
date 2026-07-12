// Function: sub_A8B215
// Address: 0xa8b215
// Size: 0x51
// Prototype: 

int __cdecl sub_A8B215(__m64 *a1, int a2, __m64 *a3)
{
  __m64 v3; // mm1
  __m64 m64_u64; // mm1
  int result; // eax
  __m64 *v6; // edi

  v3 = _m_pshufw(_m_psrawi(_m_paddw(_m_psadbw((__m64)a3->m64_u64, 0), (__m64)0x4000400040004LL), 3u), 0);
  m64_u64 = _m_packuswb(v3, v3);
  result = 3 * a2;
  a1->m64_u64 = (unsigned __int64)m64_u64;
  *(__m64 *)((char *)a1 + a2) = m64_u64;
  *(__m64 *)((char *)a1 + 2 * a2) = m64_u64;
  *(__m64 *)((char *)a1 + result) = m64_u64;
  v6 = (__m64 *)((char *)a1 + 4 * a2);
  v6->m64_u64 = (unsigned __int64)m64_u64;
  *(__m64 *)((char *)v6 + a2) = m64_u64;
  *(__m64 *)((char *)v6 + 2 * a2) = m64_u64;
  *(__m64 *)((char *)v6 + result) = m64_u64;
  return result;
}

