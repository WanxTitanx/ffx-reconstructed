// Function: sub_A7EF15
// Address: 0xa7ef15
// Size: 0x111
// Prototype: 

__m64 *__cdecl sub_A7EF15(int a1, int a2, int a3, int a4, __m64 *a5, int a6)
{
  __m64 *v6; // edi
  __m64 *v7; // eax
  __m64 m64_u64; // mm1
  __m64 v9; // mm2
  __m64 *result; // eax
  __m64 v11; // mm7
  int v12; // esi
  __m64 v13; // mm6
  __m64 v14; // mm3
  __m64 v15; // mm4
  __m64 v16; // mm5
  __m64 v17; // mm6
  __m64 v18; // mm3
  __m64 v19; // mm4

  v6 = a5;
  v7 = (__m64 *)((char *)&unk_B81350 + 32 * a3);
  m64_u64 = (__m64)v7->m64_u64;
  v9 = v7[2];
  result = (__m64 *)((char *)&unk_B81350 + 32 * a4);
  v11 = _m_packuswb(
          _m_psrawi(
            _m_paddw(
              _m_paddw(
                _m_pmullw(_m_punpcklbw(*(__m64 *)a1, 0), m64_u64),
                _m_pmullw(_m_punpcklbw(*(__m64 *)(a1 + 1), 0), v9)),
              (__m64)0x40004000400040LL),
            7u),
          _m_psrawi(
            _m_paddw(
              _m_paddw(
                _m_pmullw(_m_punpckhbw(*(__m64 *)a1, 0), m64_u64),
                _m_pmullw(_m_punpckhbw(*(__m64 *)(a1 + 1), 0), v9)),
              (__m64)0x40004000400040LL),
            7u));
  v12 = a2 + a1;
  do
  {
    v13 = *(__m64 *)(v12 + 1);
    v14 = _m_paddw(_m_pmullw(_m_punpcklbw(*(__m64 *)v12, 0), m64_u64), _m_pmullw(_m_punpcklbw(v13, 0), v9));
    v15 = _m_paddw(_m_pmullw(_m_punpckhbw(*(__m64 *)v12, 0), m64_u64), _m_pmullw(_m_punpckhbw(v13, 0), v9));
    v16 = _m_pmullw(_m_punpcklbw(v11, 0), (__m64)result->m64_u64);
    v17 = _m_pmullw(_m_punpckhbw(v11, 0), (__m64)result->m64_u64);
    v18 = _m_psrawi(_m_paddw(v14, (__m64)0x40004000400040LL), 7u);
    v19 = _m_psrawi(_m_paddw(v15, (__m64)0x40004000400040LL), 7u);
    v11 = _m_packuswb(v18, v19);
    v6->m64_u64 = (unsigned __int64)_m_packuswb(
                                      _m_psrawi(
                                        _m_paddw(_m_paddw(_m_pmullw(v18, result[2]), v16), (__m64)0x40004000400040LL),
                                        7u),
                                      _m_psrawi(
                                        _m_paddw(_m_paddw(_m_pmullw(v19, result[2]), v17), (__m64)0x40004000400040LL),
                                        7u));
    v12 += a2;
    v6 = (__m64 *)((char *)v6 + a6);
  }
  while ( v6 != (__m64 *)((char *)a5 + 4 * a6) );
  return result;
}

