// Function: sub_A80DC0
// Address: 0xa80dc0
// Size: 0x183
// Prototype: 

int __cdecl sub_A80DC0(__m64 *a1, unsigned int *a2, int a3, _DWORD *a4, int a5)
{
  __m64 v5; // mm1
  __m64 v6; // mm2
  __m64 v7; // mm3
  __m64 v9; // mm0
  __m64 v10; // mm7
  __m64 v11; // mm3
  __m64 v12; // mm6
  __m64 v13; // mm2
  __m64 v14; // mm4
  __m64 v15; // mm0
  __m64 v16; // mm6
  __m64 v17; // mm1
  __m64 v18; // mm3
  __m64 v19; // mm4
  __m64 v20; // mm5
  __m64 v21; // mm0
  __m64 v22; // mm1
  __m64 v23; // mm2
  __m64 v24; // mm3
  __m64 v25; // mm0
  __m64 v26; // mm2
  __m64 v27; // mm7
  __m64 v28; // mm3
  __m64 v29; // mm0
  __m64 v30; // mm6
  __m64 v31; // mm4
  __m64 v32; // mm2
  __m64 v33; // mm0
  __m64 v34; // mm4
  __m64 v35; // mm6
  __m64 v36; // mm1
  __m64 v37; // mm3
  __m64 v38; // mm4
  __m64 v39; // mm5

  v5 = a1[1];
  v6 = a1[2];
  v7 = a1[3];
  v9 = _m_psubw((__m64)a1->m64_u64, v6);
  v10 = _m_psubw(
          _m_paddw(_m_pmulhw(v7, (__m64)0x4E7B4E7B4E7B4E7BLL), v7),
          _m_paddw(_m_pmulhw(v5, (__m64)0x8A8C8A8C8A8C8A8CuLL), v5));
  v11 = _m_paddw(
          _m_paddw(_m_pmulhw(v7, (__m64)0x8A8C8A8C8A8C8A8CuLL), v7),
          _m_paddw(_m_pmulhw(v5, (__m64)0x4E7B4E7B4E7B4E7BLL), v5));
  v12 = _m_paddw(_m_paddw(v6, v6), v9);
  v13 = _m_paddw(v12, v11);
  v14 = _m_paddw(v9, v10);
  v15 = _m_psubw(v9, v10);
  v16 = _m_psubw(v12, v11);
  v17 = _m_punpcklwd(v13, v15);
  v18 = _m_punpcklwd(v14, v16);
  v19 = _m_punpckhwd(v14, v16);
  v20 = _m_punpckhwd(v13, v15);
  v21 = _m_punpckldq(v17, v18);
  v22 = _m_punpckhdq(v17, v18);
  v23 = _m_punpckldq(v20, v19);
  v24 = _m_punpckhdq(v20, v19);
  v25 = _m_psubw(v21, v23);
  v26 = _m_paddw(_m_paddw(v23, v23), v25);
  v27 = _m_psubw(
          _m_paddw(_m_pmulhw(v24, (__m64)0x4E7B4E7B4E7B4E7BLL), v24),
          _m_paddw(_m_pmulhw(v22, (__m64)0x8A8C8A8C8A8C8A8CuLL), v22));
  v28 = _m_paddw(
          _m_paddw(_m_pmulhw(v24, (__m64)0x8A8C8A8C8A8C8A8CuLL), v24),
          _m_paddw(_m_pmulhw(v22, (__m64)0x4E7B4E7B4E7B4E7BLL), v22));
  v29 = _m_paddw(v25, (__m64)0x4000400040004LL);
  v30 = _m_paddw(v26, (__m64)0x4000400040004LL);
  v31 = _m_paddw(v29, v27);
  v32 = _m_psrawi(_m_paddw(v30, v28), 3u);
  v33 = _m_psrawi(_m_psubw(v29, v27), 3u);
  v34 = _m_psrawi(v31, 3u);
  v35 = _m_psrawi(_m_psubw(v30, v28), 3u);
  v36 = _m_punpcklwd(v32, v33);
  v37 = _m_punpcklwd(v34, v35);
  v38 = _m_punpckhwd(v34, v35);
  v39 = _m_punpckhwd(v32, v33);
  *a4 = _mm_cvtsi64_si32(_m_packuswb(_m_paddsw(_m_punpckldq(v36, v37), _m_punpcklbw(_mm_cvtsi32_si64(*a2), 0)), 0));
  *(_DWORD *)((char *)a4 + a5) = _mm_cvtsi64_si32(
                                   _m_packuswb(
                                     _m_paddsw(
                                       _m_punpckhdq(v36, v37),
                                       _m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)a2 + a3)), 0)),
                                     0));
  *(_DWORD *)((char *)a4 + 2 * a5) = _mm_cvtsi64_si32(
                                       _m_packuswb(
                                         _m_paddsw(
                                           _m_punpckldq(v39, v38),
                                           _m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)a2 + 2 * a3)), 0)),
                                         0));
  *(_DWORD *)((char *)a4 + 2 * a5 + a5) = _mm_cvtsi64_si32(
                                            _m_packuswb(
                                              _m_paddsw(
                                                _m_punpckhdq(v39, v38),
                                                _m_punpcklbw(
                                                  _mm_cvtsi32_si64(*(unsigned int *)((char *)a2 + 2 * a3 + a3)),
                                                  0)),
                                              0));
  return a3;
}

