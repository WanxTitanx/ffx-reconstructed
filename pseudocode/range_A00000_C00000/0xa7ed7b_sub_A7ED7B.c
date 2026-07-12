// Function: sub_A7ED7B
// Address: 0xa7ed7b
// Size: 0x89
// Prototype: 

int __cdecl sub_A7ED7B(int a1, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, __m64 *a8)
{
  __m64 v8; // mm1
  __m64 v9; // mm2
  __m64 v10; // mm6
  __m64 v11; // mm7
  __m64 *v13; // esi
  int result; // eax
  __m64 v16; // mm3

  v8 = a8[2];
  v9 = a8[4];
  v10 = a8[6];
  v11 = a8[8];
  v13 = (__m64 *)(a1 - a4 - a4);
  result = a3;
  do
  {
    v16 = _m_paddsw(
            _m_paddsw(
              _m_paddsw(_m_pmullw(*(__m64 *)((char *)v13 + a4), v8), _m_pmullw(*(__m64 *)((char *)v13 + 4 * a4), v11)),
              _m_pmullw(*(__m64 *)((char *)v13 + 2 * a4), v9)),
            _m_pmullw((__m64)v13->m64_u64, (__m64)a8->m64_u64));
    v13 = (__m64 *)((char *)v13 + a4);
    *a2 = _mm_cvtsi64_si32(
            _m_packuswb(
              _m_psrawi(
                _m_paddsw(
                  _m_paddsw(
                    _m_paddsw(v16, _m_pmullw(*(__m64 *)((char *)v13 + 2 * a4), v10)),
                    _m_pmullw(*(__m64 *)((char *)v13 + 4 * a4), a8[10])),
                  (__m64)0x40004000400040LL),
                7u),
              0));
    a2 = (_DWORD *)((char *)a2 + a3);
    --a6;
  }
  while ( a6 );
  return result;
}

