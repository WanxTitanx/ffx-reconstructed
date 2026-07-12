// Function: sub_A8AD02
// Address: 0xa8ad02
// Size: 0x1bb
// Prototype: 

int __cdecl sub_A8AD02(int a1, int a2, __m64 *a3)
{
  int result; // eax
  unsigned int *v4; // esi
  int n2; // ecx
  _DWORD *v6; // edi
  __m64 v7; // mm6
  __m64 v8; // mm5
  __m64 v9; // mm4
  __m64 v10; // mm5
  int v11; // eax
  __m64 v12; // mm6
  __m64 v13; // mm2
  __m64 v14; // mm1
  __m64 v15; // mm0
  __m64 v16; // mm3
  __m64 v17; // mm1
  __m64 v18; // mm2
  __m64 v19; // mm3
  __m64 v20; // mm5
  __m64 v21; // mm5
  __m64 v22; // mm0
  __m64 v23; // mm6
  __m64 v24; // mm3
  __m64 v25; // mm7
  __m64 v26; // mm5
  __m64 v27; // mm3
  __m64 v28; // mm5
  __m64 v29; // mm6
  __m64 v30; // mm2
  __m64 v31; // mm5
  __m64 v32; // mm3
  __m64 v33; // mm6
  __m64 v34; // mm0
  __m64 v35; // mm6
  __m64 v36; // mm1
  __m64 v37; // mm5
  __m64 v38; // [esp+0h] [ebp-38h]
  __m64 v39; // [esp+10h] [ebp-28h]

  result = a2;
  v4 = (unsigned int *)(a1 + 4 * a2 - 2);
  n2 = 2;
  do
  {
    v6 = (unsigned int *)((char *)v4 + result);
    v7 = _m_punpcklbw(
           _mm_cvtsi32_si64(*(unsigned int *)((char *)v4 + 2 * result)),
           _mm_cvtsi32_si64(*(unsigned int *)((char *)v4 + 2 * result + result)));
    v8 = _m_punpcklbw(_mm_cvtsi32_si64(*v4), _mm_cvtsi32_si64(*(unsigned int *)((char *)v4 + result)));
    v9 = _m_punpcklwd(v8, v7);
    v10 = _m_punpckhwd(v8, v7);
    v11 = -result;
    v12 = _m_punpcklbw(
            _mm_cvtsi32_si64(*(unsigned int *)((char *)v4 + 2 * v11)),
            _mm_cvtsi32_si64(*(unsigned int *)((char *)v4 + v11)));
    v13 = _m_punpcklbw(_mm_cvtsi32_si64(v4[v11]), _mm_cvtsi32_si64(v6[v11]));
    v14 = _m_punpcklwd(v13, v12);
    v15 = _m_punpckldq(v14, v9);
    v16 = _m_punpckhwd(v13, v12);
    v17 = _m_punpckhdq(v14, v9);
    v18 = _m_punpckldq(v16, v10);
    v19 = _m_punpckhdq(v16, v10);
    v20 = _m_por(_m_psubusb(v17, v18), _m_psubusb(v18, v17));
    v21 = _m_pcmpeqb(
            _m_psubusb(
              _m_paddusb(
                _m_paddusb(v20, v20),
                _m_psrlwi(_m_pand(_m_por(_m_psubusb(v15, v19), _m_psubusb(v19, v15)), (__m64)0xFEFEFEFEFEFEFEFEuLL), 1u)),
              (__m64)a3->m64_u64),
            0);
    v38 = v15;
    v39 = v19;
    v22 = _m_psubsb(_m_pxor(v15, (__m64)0x8080808080808080uLL), _m_pxor(v19, (__m64)0x8080808080808080uLL));
    v23 = _m_pxor(v17, (__m64)0x8080808080808080uLL);
    v24 = _m_pxor(v18, (__m64)0x8080808080808080uLL);
    v25 = _m_psubsb(v24, v23);
    v26 = _m_paddsb(_m_pand(v21, _m_paddsb(_m_paddsb(_m_paddsb(v22, v25), v25), v25)), (__m64)0x404040404040404LL);
    v27 = _m_pxor(
            _m_psubsb(
              v24,
              _m_por(_m_psrlwi(_m_psrawi(_m_psllwi(v26, 8u), 3u), 8u), _m_psllwi(_m_psrawi(v26, 0xBu), 8u))),
            (__m64)0x8080808080808080uLL);
    v28 = _m_psubsb(v26, (__m64)0x101010101010101LL);
    v29 = _m_pxor(
            _m_paddsb(
              v23,
              _m_por(_m_psrlwi(_m_psrawi(_m_psllwi(v28, 8u), 3u), 8u), _m_psllwi(_m_psrawi(v28, 0xBu), 8u))),
            (__m64)0x8080808080808080uLL);
    v30 = _m_punpcklbw(v27, v39);
    v31 = _m_punpckhbw(v38, v29);
    v32 = _m_punpckhbw(v27, v39);
    v33 = _m_punpcklbw(v38, v29);
    v34 = _m_punpcklwd(v33, v30);
    v35 = _m_punpckhwd(v33, v30);
    v4[v11] = _mm_cvtsi64_si32(v34);
    v36 = _m_punpcklwd(v31, v32);
    v37 = _m_punpckhwd(v31, v32);
    v6[v11] = _mm_cvtsi64_si32(_m_psrlqi(v34, 0x20u));
    *(unsigned int *)((char *)v4 + 2 * v11) = _mm_cvtsi64_si32(v35);
    *v4 = _mm_cvtsi64_si32(v36);
    *(unsigned int *)((char *)v4 + v11) = _mm_cvtsi64_si32(_m_psrlqi(v35, 0x20u));
    result = -v11;
    *(unsigned int *)((char *)v4 + 2 * result) = _mm_cvtsi64_si32(v37);
    *v6 = _mm_cvtsi64_si32(_m_psrlqi(v36, 0x20u));
    *(_DWORD *)((char *)v6 + 2 * result) = _mm_cvtsi64_si32(_m_psrlqi(v37, 0x20u));
    v4 += 2 * result;
    --n2;
  }
  while ( n2 );
  return result;
}

