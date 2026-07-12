// Function: sub_A8A221
// Address: 0xa8a221
// Size: 0x2f0
// Prototype: 

int __cdecl sub_A8A221(int a1, int a2, __m64 *a3, __m64 *a4, __m64 *a5, int a6)
{
  int result; // eax
  int v7; // esi
  int v9; // edi
  __m64 v10; // mm7
  __m64 v11; // mm6
  __m64 v12; // mm3
  __m64 v13; // mm5
  __m64 v14; // mm3
  __m64 v15; // mm2
  __m64 v16; // mm4
  __m64 v17; // mm2
  int v18; // eax
  __m64 v19; // mm1
  __m64 v20; // mm6
  __m64 v21; // mm1
  __m64 v22; // mm0
  __m64 v23; // mm7
  __m64 v24; // mm0
  __m64 v25; // mm6
  __m64 v26; // mm7
  __m64 v27; // mm6
  __m64 v28; // mm3
  __m64 v29; // mm0
  __m64 v30; // mm3
  __m64 v31; // mm1
  __m64 v32; // mm0
  __m64 v33; // mm1
  __m64 v34; // mm0
  __m64 v35; // mm1
  __m64 v36; // mm1
  __m64 v37; // mm4
  __m64 v38; // mm7
  __m64 v39; // mm6
  __m64 v40; // mm3
  __m64 v41; // mm0
  __m64 v42; // mm2
  __m64 v43; // mm1
  __m64 v44; // mm2
  __m64 v45; // mm0
  __m64 v46; // mm1
  __m64 v47; // mm5
  __m64 v48; // mm0
  __m64 v49; // mm4
  __m64 v50; // mm6
  __m64 v51; // mm1
  __m64 v52; // mm3
  __m64 v53; // mm7
  __m64 v54; // mm2
  __m64 v55; // mm1
  __m64 v56; // mm4
  __m64 v57; // mm3
  __m64 v58; // mm6
  __m64 v59; // mm2
  __m64 v60; // mm6
  __m64 v61; // mm5
  __m64 v62; // mm1
  __m64 v63; // mm5
  __m64 v64; // [esp+0h] [ebp-58h]
  __m64 v65; // [esp+10h] [ebp-48h]
  __m64 v66; // [esp+20h] [ebp-38h]
  __m64 v67; // [esp+28h] [ebp-30h]
  __m64 v68; // [esp+30h] [ebp-28h]
  __m64 v69; // [esp+38h] [ebp-20h]

  result = a2;
  v7 = a1 + 4 * a2 - 4;
  do
  {
    v9 = result + v7;
    v10 = _m_punpckhbw(*(__m64 *)(v7 + 2 * result), *(__m64 *)(result + v7 + 2 * result));
    v11 = _m_punpcklbw(*(__m64 *)(v7 + 2 * result), (__m64)*(unsigned int *)(result + v7 + 2 * result));
    v12 = _m_punpckhbw(*(__m64 *)v7, *(__m64 *)(v7 + result));
    v13 = _m_punpckhwd(v12, v10);
    v14 = _m_punpcklwd(v12, v10);
    v15 = _m_punpcklbw(*(__m64 *)v7, (__m64)*(unsigned int *)(v7 + result));
    v16 = _m_punpckhwd(v15, v11);
    v17 = _m_punpcklwd(v15, v11);
    v18 = -result;
    v19 = *(__m64 *)(v7 + 2 * v18);
    v20 = _m_punpckhbw(v19, *(__m64 *)(v7 + v18));
    v21 = _m_punpcklbw(v19, (__m64)*(unsigned int *)(v7 + v18));
    v22 = _m_punpckhbw(*(__m64 *)(v7 + 4 * v18), *(__m64 *)(v9 + 4 * v18));
    v23 = _m_punpckhwd(v22, v20);
    v24 = _m_punpcklwd(v22, v20);
    v25 = v23;
    v26 = _m_punpckhdq(v23, v13);
    v27 = _m_punpckldq(v25, v13);
    v69 = _m_punpckhdq(v24, v14);
    v68 = _m_punpckldq(v24, v14);
    v28 = _m_punpcklbw(*(__m64 *)(v7 + 4 * v18), (__m64)*(unsigned int *)(v9 + 4 * v18));
    v29 = _m_punpcklwd(v28, v21);
    v30 = _m_punpckhwd(v28, v21);
    v31 = v29;
    v32 = _m_punpckldq(v29, v17);
    v33 = _m_punpckhdq(v31, v17);
    v67 = _m_punpckhdq(v30, v16);
    v66 = _m_punpckldq(v30, v16);
    v34 = _m_por(
            _m_por(
              _m_psubusb(_m_por(_m_psubusb(v32, v33), _m_psubusb(v33, v32)), (__m64)a4->m64_u64),
              _m_psubusb(_m_por(_m_psubusb(v33, v66), _m_psubusb(v66, v33)), (__m64)a4->m64_u64)),
            _m_por(
              _m_psubusb(_m_por(_m_psubusb(v26, v27), _m_psubusb(v27, v26)), (__m64)a4->m64_u64),
              _m_psubusb(_m_por(_m_psubusb(v27, v69), _m_psubusb(v69, v27)), (__m64)a4->m64_u64)));
    v64 = _m_por(_m_psubusb(v66, v67), _m_psubusb(v67, v66));
    v65 = _m_por(_m_psubusb(v69, v68), _m_psubusb(v68, v69));
    v35 = _m_por(_m_psubusb(v67, v68), _m_psubusb(v68, v67));
    v36 = _m_pcmpeqb(
            _m_por(
              _m_psubusb(
                _m_paddusb(
                  _m_paddusb(v35, v35),
                  _m_psrlwi(
                    _m_pand(_m_por(_m_psubusb(v69, v66), _m_psubusb(v66, v69)), (__m64)0xFEFEFEFEFEFEFEFEuLL),
                    1u)),
                (__m64)a3->m64_u64),
              _m_por(_m_por(v34, _m_psubusb(v64, (__m64)a4->m64_u64)), _m_psubusb(v65, (__m64)a4->m64_u64))),
            0);
    v37 = _m_pxor(
            _m_pcmpeqb(_m_por(_m_psubusb(v64, (__m64)a5->m64_u64), _m_psubusb(v65, (__m64)a5->m64_u64)), 0),
            (__m64)-1LL);
    v38 = _m_pxor(v69, (__m64)0x8080808080808080uLL);
    v39 = _m_pxor(v67, (__m64)0x8080808080808080uLL);
    v40 = _m_pxor(v68, (__m64)0x8080808080808080uLL);
    v41 = _m_psubsb(v40, v39);
    v42 = _m_pand(
            v36,
            _m_paddsb(
              _m_paddsb(_m_paddsb(_m_pand(_m_psubsb(_m_pxor(v66, (__m64)0x8080808080808080uLL), v38), v37), v41), v41),
              v41));
    v43 = _m_paddsb(v42, (__m64)0x404040404040404LL);
    v44 = _m_paddsb(v42, (__m64)0x303030303030303LL);
    v45 = _m_psrawi(_m_punpcklbw(0, v43), 0xBu);
    v46 = _m_psrawi(_m_punpckhbw(0, v43), 0xBu);
    v47 = v45;
    v48 = _m_packsswb(v45, v46);
    v49 = _m_pandn(
            v37,
            _m_packsswb(
              _m_psrawi(_m_paddsw(v47, (__m64)0x1000100010001LL), 1u),
              _m_psrawi(_m_paddsw(v46, (__m64)0x1000100010001LL), 1u)));
    v50 = _m_pxor(
            _m_paddsb(v39, _m_packsswb(_m_psrawi(_m_punpcklbw(0, v44), 0xBu), _m_psrawi(_m_punpckhbw(0, v44), 0xBu))),
            (__m64)0x8080808080808080uLL);
    v51 = _m_pxor(_m_paddsb(_m_pxor(v66, (__m64)0x8080808080808080uLL), v49), (__m64)0x8080808080808080uLL);
    v52 = _m_pxor(_m_psubsb(v40, v48), (__m64)0x8080808080808080uLL);
    v53 = _m_pxor(_m_psubsb(v38, v49), (__m64)0x8080808080808080uLL);
    v54 = _m_punpcklbw(v51, v50);
    v55 = _m_punpckhbw(v51, v50);
    v56 = _m_punpcklbw(v52, v53);
    v57 = _m_punpckhbw(v52, v53);
    v58 = v54;
    v59 = _m_punpcklwd(v54, v56);
    v60 = _m_punpckhwd(v58, v56);
    v61 = v55;
    v62 = _m_punpcklwd(v55, v57);
    v63 = _m_punpckhwd(v61, v57);
    *(_DWORD *)(v7 + 4 * v18 + 2) = _mm_cvtsi64_si32(v59);
    *(_DWORD *)(v9 + 4 * v18 + 2) = _mm_cvtsi64_si32(_m_psrlqi(v59, 0x20u));
    *(_DWORD *)(v7 + 2 * v18 + 2) = _mm_cvtsi64_si32(v60);
    *(_DWORD *)(v7 + v18 + 2) = _mm_cvtsi64_si32(_m_psrlqi(v60, 0x20u));
    *(_DWORD *)(v7 + 2) = _mm_cvtsi64_si32(v62);
    *(_DWORD *)(v9 + 2) = _mm_cvtsi64_si32(_m_psrlqi(v62, 0x20u));
    result = -v18;
    *(_DWORD *)(v9 + result + 2) = _mm_cvtsi64_si32(v63);
    *(_DWORD *)(v9 + 2 * result + 2) = _mm_cvtsi64_si32(_m_psrlqi(v63, 0x20u));
    v7 += 8 * result;
    --a6;
  }
  while ( a6 );
  return result;
}

