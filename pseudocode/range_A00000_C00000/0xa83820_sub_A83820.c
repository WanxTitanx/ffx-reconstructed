// Function: sub_A83820
// Address: 0xa83820
// Size: 0x89
// Prototype: 

int __cdecl sub_A83820(__m64 *a1, int a2, __m64 *a3, int a4)
{
  __m64 *v4; // esi
  __m64 v6; // mm7
  __m64 v7; // mm1
  __m64 v8; // mm3
  __m64 v9; // mm7

  v4 = a1;
  v6.m64_u64 = 0;
  do
  {
    v7 = _m_por(_m_psubusb((__m64)v4->m64_u64, (__m64)a3->m64_u64), _m_psubusb((__m64)a3->m64_u64, (__m64)v4->m64_u64));
    v8 = _m_por(_m_psubusb(v4[1], a3[1]), _m_psubusb(a3[1], v4[1]));
    v4 = (__m64 *)((char *)v4 + a2);
    a3 = (__m64 *)((char *)a3 + a4);
    v6 = _m_paddw(
           _m_paddw(v6, _m_paddw(_m_punpcklbw(v7, 0), _m_punpcklbw(v8, 0))),
           _m_paddw(_m_punpckhbw(v7, 0), _m_punpckhbw(v8, 0)));
  }
  while ( v4 != &a1[a2 + a2] );
  v9 = _m_paddw(_m_punpcklwd(v6, 0), _m_punpckhwd(v6, 0));
  return _mm_cvtsi64_si32(_m_paddw(v9, _m_psrlqi(v9, 0x20u)));
}

