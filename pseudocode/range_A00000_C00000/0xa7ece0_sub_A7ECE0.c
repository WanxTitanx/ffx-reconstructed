// Function: sub_A7ECE0
// Address: 0xa7ece0
// Size: 0x9b
// Prototype: 

int __cdecl sub_A7ECE0(int a1, __m64 *a2, int a3, int a4, int a5, int a6, __m64 *a7)
{
  __m64 v7; // mm1
  __m64 v8; // mm2
  __m64 v9; // mm6
  __m64 v10; // mm7
  int result; // eax

  v7 = a7[2];
  v8 = a7[4];
  v9 = a7[6];
  v10 = a7[8];
  result = a6;
  do
  {
    a2->m64_u64 = (unsigned __int64)_m_punpcklbw(
                                      _m_packuswb(
                                        _m_psrawi(
                                          _m_paddsw(
                                            _m_paddsw(
                                              _m_paddsw(
                                                _m_paddsw(
                                                  _m_paddsw(
                                                    _m_paddsw(
                                                      _m_pmullw(_m_punpcklbw(_m_psrlqi(*(__m64 *)(a1 - 2), 8u), 0), v7),
                                                      _m_pmullw(_m_punpckhbw(*(__m64 *)(a1 - 2), 0), v10)),
                                                    _m_pmullw(_m_punpcklbw(_m_psrlqi(*(__m64 *)(a1 - 2), 0x10u), 0), v8)),
                                                  _m_pmullw(_m_punpcklbw(_m_psrlqi(*(__m64 *)(a1 - 2), 0x18u), 0), v9)),
                                                _m_pmullw(
                                                  _m_punpcklbw(_mm_cvtsi32_si64(*(_DWORD *)(a1 + 3)), 0),
                                                  a7[10])),
                                              _m_pmullw(_m_punpcklbw(*(__m64 *)(a1 - 2), 0), (__m64)a7->m64_u64)),
                                            (__m64)0x40004000400040LL),
                                          7u),
                                        0),
                                      0);
    a1 += a3;
    a2 = (__m64 *)((char *)a2 + a6);
    --a5;
  }
  while ( a5 );
  return result;
}

