// Function: sub_A8390F
// Address: 0xa8390f
// Size: 0x63
// Prototype: 

int __cdecl sub_A8390F(__m64 *a1, int a2, __m64 *a3, int a4)
{
  __m64 *v4; // esi
  __m64 v6; // mm7
  __m64 v7; // mm2
  __m64 v8; // mm7

  v4 = a1;
  v6.m64_u64 = 0;
  do
  {
    v7 = _m_por(_m_psubusb((__m64)v4->m64_u64, (__m64)a3->m64_u64), _m_psubusb((__m64)a3->m64_u64, (__m64)v4->m64_u64));
    v4 = (__m64 *)((char *)v4 + a2);
    a3 = (__m64 *)((char *)a3 + a4);
    v6 = _m_paddw(v6, _m_paddw(_m_punpcklbw(v7, 0), _m_punpckhbw(v7, 0)));
  }
  while ( v4 != &a1[a2] );
  v8 = _m_paddw(_m_punpcklwd(v6, 0), _m_punpckhwd(v6, 0));
  return _mm_cvtsi64_si32(_m_paddw(v8, _m_psrlqi(v8, 0x20u)));
}

