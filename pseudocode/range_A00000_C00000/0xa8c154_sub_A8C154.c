// Function: sub_A8C154
// Address: 0xa8c154
// Size: 0x158
// Prototype: 

__int64 __cdecl sub_A8C154(int a1, int a2, __m64 *a3, int a4, int a5, __int64 a6, _DWORD *a7, _DWORD *a8)
{
  __m64 v8; // mm6
  __m64 v9; // mm7
  __int64 result; // rax
  __m64 v13; // mm5
  int v14; // esi
  __m64 v15; // mm4
  __m64 v16; // mm1
  __m64 v17; // mm2
  __m64 v18; // mm3
  __m64 v19; // mm4
  __m64 v20; // mm1
  __m64 v21; // mm2
  __m64 v22; // mm2

  v8.m64_u64 = 0;
  v9.m64_u64 = 0;
  result = a6;
  v13 = _m_packuswb(
          _m_psrawi(
            _m_paddw(
              _m_paddw(
                _m_pmullw(_m_punpcklbw(*(__m64 *)a1, 0), *(__m64 *)a6),
                _m_pmullw(_m_punpcklbw(*(__m64 *)(a1 + 1), 0), *(__m64 *)(a6 + 8))),
              (__m64)0x40004000400040LL),
            7u),
          _m_psrawi(
            _m_paddw(
              _m_paddw(
                _m_pmullw(_m_punpckhbw(*(__m64 *)a1, 0), *(__m64 *)a6),
                _m_pmullw(_m_punpckhbw(*(__m64 *)(a1 + 1), 0), *(__m64 *)(a6 + 8))),
              (__m64)0x40004000400040LL),
            7u));
  v14 = a2 + a1;
  do
  {
    v15 = *(__m64 *)(v14 + 1);
    v16 = _m_psrawi(
            _m_paddw(
              _m_paddw(
                _m_pmullw(_m_punpcklbw(*(__m64 *)v14, 0), *(__m64 *)a6),
                _m_pmullw(_m_punpcklbw(v15, 0), *(__m64 *)(a6 + 8))),
              (__m64)0x40004000400040LL),
            7u);
    v17 = _m_psrawi(
            _m_paddw(
              _m_paddw(
                _m_pmullw(_m_punpckhbw(*(__m64 *)v14, 0), *(__m64 *)a6),
                _m_pmullw(_m_punpckhbw(v15, 0), *(__m64 *)(a6 + 8))),
              (__m64)0x40004000400040LL),
            7u);
    v18 = _m_punpcklbw(v13, 0);
    v19 = _m_punpckhbw(v13, 0);
    v13 = _m_packuswb(v16, v17);
    v20 = _m_psubw(
            _m_psrawi(
              _m_paddw(
                _m_paddw(
                  _m_pmullw(v16, *(__m64 *)(HIDWORD(a6) + 8)),
                  _m_pmullw(v18, (__m64)((__m64 *)HIDWORD(a6))->m64_u64)),
                (__m64)0x40004000400040LL),
              7u),
            _m_punpcklbw((__m64)a3->m64_u64, 0));
    v21 = _m_psubw(
            _m_psrawi(
              _m_paddw(
                _m_paddw(
                  _m_pmullw(v17, *(__m64 *)(HIDWORD(a6) + 8)),
                  _m_pmullw(v19, (__m64)((__m64 *)HIDWORD(a6))->m64_u64)),
                (__m64)0x40004000400040LL),
              7u),
            _m_punpckhbw((__m64)a3->m64_u64, 0));
    v8 = _m_paddw(_m_paddw(v8, v20), v21);
    v9 = _m_paddd(_m_paddd(v9, _m_pmaddwd(v20, v20)), _m_pmaddwd(v21, v21));
    v14 += a2;
    a3 = (__m64 *)((char *)a3 + a4);
    --a5;
  }
  while ( a5 );
  v22 = _m_paddd(_m_punpcklwd(0, v8), _m_punpckhwd(0, v8));
  *a7 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(v22, _m_psrlqi(v22, 0x20u)), 0x10u));
  *a8 = _mm_cvtsi64_si32(_m_paddd(_m_psrlqi(v9, 0x20u), v9));
  return result;
}

