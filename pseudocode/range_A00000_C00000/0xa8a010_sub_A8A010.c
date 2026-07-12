// Function: sub_A8A010
// Address: 0xa8a010
// Size: 0x211
// Prototype: 

int __cdecl sub_A8A010(__m64 *a1, int a2, __m64 *a3, __m64 *a4, __m64 *a5, int a6)
{
  int result; // eax
  __m64 *v9; // edi
  __m64 v10; // mm3
  __m64 v11; // mm1
  int v12; // eax
  __m64 v13; // mm3
  __m64 v14; // mm5
  __m64 v15; // mm6
  __m64 v16; // mm5
  __m64 v17; // mm1
  __m64 v18; // mm4
  __m64 v19; // mm7
  __m64 v20; // mm6
  __m64 v21; // mm3
  __m64 v22; // mm0
  __m64 v23; // mm2
  __m64 v24; // mm1
  __m64 v25; // mm2
  __m64 v26; // mm0
  __m64 v27; // mm1
  __m64 v28; // mm4
  __m64 v29; // [esp+0h] [ebp-38h]
  __m64 v30; // [esp+10h] [ebp-28h]

  result = a2;
  do
  {
    v9 = (__m64 *)((char *)a1 + result);
    v10 = *(__m64 *)((char *)a1 + result);
    v29 = _m_por(_m_psubusb((__m64)a1->m64_u64, v10), _m_psubusb(v10, (__m64)a1->m64_u64));
    v11 = _m_por(
            _m_por(
              _m_psubusb(
                _m_por(
                  _m_psubusb(*(__m64 *)((char *)a1 + 2 * result), *(__m64 *)((char *)a1 + 2 * result + result)),
                  _m_psubusb(*(__m64 *)((char *)a1 + 2 * result + result), *(__m64 *)((char *)a1 + 2 * result))),
                (__m64)a4->m64_u64),
              _m_psubusb(
                _m_por(
                  _m_psubusb(v10, *(__m64 *)((char *)a1 + 2 * result)),
                  _m_psubusb(*(__m64 *)((char *)a1 + 2 * result), v10)),
                (__m64)a4->m64_u64)),
            _m_psubusb(v29, (__m64)a4->m64_u64));
    v12 = -result;
    v13 = *(__m64 *)((char *)a1 + 2 * v12);
    v14 = *(__m64 *)((char *)a1 + v12);
    v30 = _m_por(_m_psubusb(v14, v13), _m_psubusb(v13, v14));
    v15 = v14;
    v16 = _m_por(_m_psubusb(v14, (__m64)a1->m64_u64), _m_psubusb((__m64)a1->m64_u64, v14));
    v17 = _m_pcmpeqb(
            _m_por(
              _m_por(
                _m_por(
                  _m_por(
                    v11,
                    _m_psubusb(
                      _m_por(
                        _m_psubusb(*(__m64 *)((char *)v9 + 4 * v12), *(__m64 *)((char *)a1 + 4 * v12)),
                        _m_psubusb(*(__m64 *)((char *)a1 + 4 * v12), *(__m64 *)((char *)v9 + 4 * v12))),
                      (__m64)a4->m64_u64)),
                  _m_psubusb(
                    _m_por(
                      _m_psubusb(v13, *(__m64 *)((char *)v9 + 4 * v12)),
                      _m_psubusb(*(__m64 *)((char *)v9 + 4 * v12), v13)),
                    (__m64)a4->m64_u64)),
                _m_psubusb(v30, (__m64)a4->m64_u64)),
              _m_psubusb(
                _m_paddusb(
                  _m_paddusb(v16, v16),
                  _m_psrlwi(
                    _m_pand(
                      _m_por(_m_psubusb(v13, (__m64)v9->m64_u64), _m_psubusb((__m64)v9->m64_u64, v13)),
                      (__m64)0xFEFEFEFEFEFEFEFEuLL),
                    1u)),
                (__m64)a3->m64_u64)),
            0);
    v18 = _m_pxor(
            _m_pcmpeqb(_m_paddb(_m_psubusb(v29, (__m64)a5->m64_u64), _m_psubusb(v30, (__m64)a5->m64_u64)), 0),
            (__m64)-1LL);
    v19 = _m_pxor((__m64)v9->m64_u64, (__m64)0x8080808080808080uLL);
    v20 = _m_pxor(v15, (__m64)0x8080808080808080uLL);
    v21 = _m_pxor((__m64)a1->m64_u64, (__m64)0x8080808080808080uLL);
    v22 = _m_psubsb(v21, v20);
    v23 = _m_pand(
            v17,
            _m_paddsb(
              _m_paddsb(
                _m_paddsb(
                  _m_pand(_m_psubsb(_m_pxor(*(__m64 *)((char *)a1 + 2 * v12), (__m64)0x8080808080808080uLL), v19), v18),
                  v22),
                v22),
              v22));
    v24 = _m_paddsb(v23, (__m64)0x404040404040404LL);
    v25 = _m_paddsb(v23, (__m64)0x303030303030303LL);
    v26 = _m_psrawi(_m_punpcklbw(0, v24), 0xBu);
    v27 = _m_psrawi(_m_punpckhbw(0, v24), 0xBu);
    v28 = _m_pandn(
            v18,
            _m_packsswb(
              _m_psrawi(_m_paddsw(v26, (__m64)0x1000100010001LL), 1u),
              _m_psrawi(_m_paddsw(v27, (__m64)0x1000100010001LL), 1u)));
    *(__m64 *)((char *)a1 + v12) = _m_pxor(
                                     _m_paddsb(
                                       v20,
                                       _m_packsswb(
                                         _m_psrawi(_m_punpcklbw(0, v25), 0xBu),
                                         _m_psrawi(_m_punpckhbw(0, v25), 0xBu))),
                                     (__m64)0x8080808080808080uLL);
    *(__m64 *)((char *)a1 + 2 * v12) = _m_pxor(
                                         _m_paddsb(
                                           _m_pxor(*(__m64 *)((char *)a1 + 2 * v12), (__m64)0x8080808080808080uLL),
                                           v28),
                                         (__m64)0x8080808080808080uLL);
    a1->m64_u64 = (unsigned __int64)_m_pxor(_m_psubsb(v21, _m_packsswb(v26, v27)), (__m64)0x8080808080808080uLL);
    v9->m64_u64 = (unsigned __int64)_m_pxor(_m_psubsb(v19, v28), (__m64)0x8080808080808080uLL);
    ++a1;
    result = -v12;
    --a6;
  }
  while ( a6 );
  return result;
}

