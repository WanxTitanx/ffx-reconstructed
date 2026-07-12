// Function: sub_A8ABFC
// Address: 0xa8abfc
// Size: 0x106
// Prototype: 

int __cdecl sub_A8ABFC(__m64 *a1, int a2, __m64 *a3)
{
  int result; // eax
  int n2; // ecx
  __m64 *v6; // edi
  int v7; // eax
  __m64 v8; // mm6
  __m64 v9; // mm5
  __m64 v10; // mm6
  __m64 v11; // mm3
  __m64 v12; // mm0
  __m64 v13; // mm5
  __m64 v14; // mm5

  result = a2;
  n2 = 2;
  do
  {
    v6 = (__m64 *)((char *)a1 + result);
    v7 = -result;
    v8 = *(__m64 *)((char *)a1 + v7);
    v9 = _m_por(_m_psubusb(v8, (__m64)a1->m64_u64), _m_psubusb((__m64)a1->m64_u64, v8));
    v10 = _m_pxor(v8, (__m64)0x8080808080808080uLL);
    v11 = _m_pxor((__m64)a1->m64_u64, (__m64)0x8080808080808080uLL);
    v12 = _m_psubsb(v11, v10);
    v13 = _m_paddsb(
            _m_pand(
              _m_pcmpeqb(
                _m_psubusb(
                  _m_paddusb(
                    _m_paddusb(v9, v9),
                    _m_psrlwi(
                      _m_pand(
                        _m_por(
                          _m_psubusb(*(__m64 *)((char *)a1 + 2 * v7), (__m64)v6->m64_u64),
                          _m_psubusb((__m64)v6->m64_u64, *(__m64 *)((char *)a1 + 2 * v7))),
                        (__m64)0xFEFEFEFEFEFEFEFEuLL),
                      1u)),
                  (__m64)a3->m64_u64),
                0),
              _m_paddsb(
                _m_paddsb(
                  _m_paddsb(
                    _m_psubsb(
                      _m_pxor(*(__m64 *)((char *)a1 + 2 * v7), (__m64)0x8080808080808080uLL),
                      _m_pxor((__m64)v6->m64_u64, (__m64)0x8080808080808080uLL)),
                    v12),
                  v12),
                v12)),
            (__m64)0x404040404040404LL);
    a1->m64_u64 = (unsigned __int64)_m_pxor(
                                      _m_psubsb(
                                        v11,
                                        _m_por(
                                          _m_psrlwi(_m_psrawi(_m_psllwi(v13, 8u), 3u), 8u),
                                          _m_psllwi(_m_psrawi(v13, 0xBu), 8u))),
                                      (__m64)0x8080808080808080uLL);
    v14 = _m_psubsb(v13, (__m64)0x101010101010101LL);
    *(__m64 *)((char *)a1++ + v7) = _m_pxor(
                                      _m_paddsb(
                                        v10,
                                        _m_por(
                                          _m_psrlwi(_m_psrawi(_m_psllwi(v14, 8u), 3u), 8u),
                                          _m_psllwi(_m_psrawi(v14, 0xBu), 8u))),
                                      (__m64)0x8080808080808080uLL);
    result = -v7;
    --n2;
  }
  while ( n2 );
  return result;
}

