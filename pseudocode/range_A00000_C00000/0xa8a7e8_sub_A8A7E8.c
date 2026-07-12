// Function: sub_A8A7E8
// Address: 0xa8a7e8
// Size: 0x414
// Prototype: 

int __cdecl sub_A8A7E8(int a1, int a2, __m64 *a3, __m64 *a4, __m64 *a5, int a6)
{
  int result; // eax
  __m64 *v7; // esi
  __m64 *v9; // edi
  __m64 v10; // mm0
  __m64 v11; // mm7
  __m64 v12; // mm6
  __m64 v13; // mm0
  __m64 v14; // mm3
  __m64 v15; // mm5
  __m64 v16; // mm3
  __m64 v17; // mm2
  __m64 v18; // mm4
  __m64 v19; // mm2
  int v20; // eax
  __m64 v21; // mm7
  __m64 v22; // mm1
  __m64 v23; // mm6
  __m64 v24; // mm1
  __m64 v25; // mm0
  __m64 v26; // mm7
  __m64 v27; // mm0
  __m64 v28; // mm3
  __m64 v29; // mm0
  __m64 v30; // mm3
  __m64 v31; // mm1
  __m64 v32; // mm4
  __m64 v33; // mm6
  __m64 v34; // mm3
  __m64 v35; // mm0
  __m64 v36; // mm1
  __m64 v37; // mm2
  __m64 v38; // mm5
  __m64 v39; // mm2
  __m64 v40; // mm4
  __m64 v41; // mm1
  __m64 v42; // mm1
  __m64 v43; // mm1
  __m64 v44; // mm6
  __m64 v45; // mm3
  __m64 v46; // mm0
  __m64 v47; // mm1
  __m64 v48; // mm2
  __m64 v49; // mm6
  __m64 v50; // mm5
  __m64 v51; // mm0
  __m64 v52; // mm5
  __m64 v53; // mm4
  __m64 v54; // mm1
  __m64 v55; // mm4
  __m64 v56; // mm6
  __m64 v57; // mm7
  __m64 v58; // mm2
  __m64 v59; // mm7
  __m64 v60; // mm3
  __m64 v61; // mm5
  __m64 v62; // mm2
  __m64 v63; // mm5
  __m64 v64; // [esp+0h] [ebp-78h]
  __m64 v65; // [esp+10h] [ebp-68h]
  __m64 v66; // [esp+20h] [ebp-58h]
  __m64 v67; // [esp+28h] [ebp-50h]
  __m64 v68; // [esp+30h] [ebp-48h]
  __m64 v69; // [esp+30h] [ebp-48h]
  __m64 v70; // [esp+38h] [ebp-40h]
  __m64 v71; // [esp+38h] [ebp-40h]
  __m64 v72; // [esp+40h] [ebp-38h]
  __m64 v73; // [esp+40h] [ebp-38h]
  __m64 v74; // [esp+48h] [ebp-30h]
  __m64 v75; // [esp+48h] [ebp-30h]
  __m64 v76; // [esp+50h] [ebp-28h]
  __m64 v77; // [esp+58h] [ebp-20h]

  result = a2;
  v7 = (__m64 *)(a1 + 4 * a2 - 4);
  do
  {
    v9 = (__m64 *)((char *)v7 + result);
    v10 = *(__m64 *)((char *)v7 + 2 * result + result);
    v11 = _m_punpckhbw(*(__m64 *)((char *)v7 + 2 * result), v10);
    v12 = _m_punpcklbw(*(__m64 *)((char *)v7 + 2 * result), v10);
    v13 = *(__m64 *)((char *)v7 + result);
    v14 = _m_punpckhbw((__m64)v7->m64_u64, v13);
    v15 = _m_punpckhwd(v14, v11);
    v16 = _m_punpcklwd(v14, v11);
    v17 = _m_punpcklbw((__m64)v7->m64_u64, v13);
    v18 = _m_punpckhwd(v17, v12);
    v19 = _m_punpcklwd(v17, v12);
    v20 = -result;
    v21 = *(__m64 *)((char *)v7 + v20);
    v22 = *(__m64 *)((char *)v7 + 2 * v20);
    v23 = _m_punpckhbw(v22, v21);
    v24 = _m_punpcklbw(v22, v21);
    v25 = _m_punpckhbw(*(__m64 *)((char *)v7 + 4 * v20), *(__m64 *)((char *)v9 + 4 * v20));
    v26 = _m_punpckhwd(v25, v23);
    v27 = _m_punpcklwd(v25, v23);
    v77 = _m_punpckhdq(v26, v15);
    v76 = _m_punpckldq(v26, v15);
    v74 = _m_punpckhdq(v27, v16);
    v72 = _m_punpckldq(v27, v16);
    v28 = _m_punpcklbw(*(__m64 *)((char *)v7 + 4 * v20), (__m64)v9->m64_u32[v20]);
    v29 = _m_punpcklwd(v28, v24);
    v30 = _m_punpckhwd(v28, v24);
    v66 = _m_punpckldq(v29, v19);
    v67 = _m_punpckhdq(v29, v19);
    v70 = _m_punpckhdq(v30, v18);
    v68 = _m_punpckldq(v30, v18);
    v64 = _m_por(_m_psubusb(v68, v70), _m_psubusb(v70, v68));
    v65 = _m_por(_m_psubusb(v74, v72), _m_psubusb(v72, v74));
    v31 = _m_por(_m_psubusb(v70, v72), _m_psubusb(v72, v70));
    v32 = _m_pxor(
            _m_pcmpeqb(_m_por(_m_psubusb(v64, (__m64)a5->m64_u64), _m_psubusb(v65, (__m64)a5->m64_u64)), 0),
            (__m64)-1LL);
    v33 = _m_pxor(v70, (__m64)0x8080808080808080uLL);
    v34 = _m_pxor(v72, (__m64)0x8080808080808080uLL);
    v35 = _m_psubsb(v34, v33);
    v36 = _m_pand(
            _m_pcmpeqb(
              _m_por(
                _m_psubusb(
                  _m_paddusb(
                    _m_paddusb(v31, v31),
                    _m_psrlwi(
                      _m_pand(_m_por(_m_psubusb(v74, v68), _m_psubusb(v68, v74)), (__m64)0xFEFEFEFEFEFEFEFEuLL),
                      1u)),
                  (__m64)a3->m64_u64),
                _m_por(
                  _m_por(
                    _m_por(
                      _m_por(
                        _m_psubusb(_m_por(_m_psubusb(v66, v67), _m_psubusb(v67, v66)), (__m64)a4->m64_u64),
                        _m_psubusb(_m_por(_m_psubusb(v67, v68), _m_psubusb(v68, v67)), (__m64)a4->m64_u64)),
                      _m_por(
                        _m_psubusb(_m_por(_m_psubusb(v77, v76), _m_psubusb(v76, v77)), (__m64)a4->m64_u64),
                        _m_psubusb(_m_por(_m_psubusb(v76, v74), _m_psubusb(v74, v76)), (__m64)a4->m64_u64))),
                    _m_psubusb(v64, (__m64)a4->m64_u64)),
                  _m_psubusb(v65, (__m64)a4->m64_u64))),
              0),
            _m_paddsb(
              _m_paddsb(
                _m_paddsb(
                  _m_psubsb(_m_pxor(v68, (__m64)0x8080808080808080uLL), _m_pxor(v74, (__m64)0x8080808080808080uLL)),
                  v35),
                v35),
              v35));
    v37 = _m_pand(v36, v32);
    v38 = _m_paddsb(v37, (__m64)0x303030303030303LL);
    v39 = _m_paddsb(v37, (__m64)0x404040404040404LL);
    v40 = _m_pandn(v32, v36);
    v41 = _m_packsswb(
            _m_psrawi(
              _m_paddw(_m_pmulhw(_m_punpcklbw(0, v40), (__m64)0x1B001B001B001B00LL), (__m64)0x3F003F003F003FLL),
              7u),
            _m_psrawi(
              _m_paddw(_m_pmulhw(_m_punpckhbw(0, v40), (__m64)0x1B001B001B001B00LL), (__m64)0x3F003F003F003FLL),
              7u));
    v71 = _m_pxor(
            _m_paddsb(
              _m_paddsb(v33, _m_packsswb(_m_psrawi(_m_punpcklbw(0, v38), 0xBu), _m_psrawi(_m_punpckhbw(0, v38), 0xBu))),
              v41),
            (__m64)0x8080808080808080uLL);
    v73 = _m_pxor(
            _m_psubsb(
              _m_psubsb(v34, _m_packsswb(_m_psrawi(_m_punpcklbw(0, v39), 0xBu), _m_psrawi(_m_punpckhbw(0, v39), 0xBu))),
              v41),
            (__m64)0x8080808080808080uLL);
    v42 = _m_packsswb(
            _m_psrawi(
              _m_paddw(_m_pmulhw(_m_punpcklbw(0, v40), (__m64)0x1200120012001200LL), (__m64)0x3F003F003F003FLL),
              7u),
            _m_psrawi(
              _m_paddw(_m_pmulhw(_m_punpckhbw(0, v40), (__m64)0x1200120012001200LL), (__m64)0x3F003F003F003FLL),
              7u));
    v75 = _m_pxor(_m_psubsb(_m_pxor(v74, (__m64)0x8080808080808080uLL), v42), (__m64)0x8080808080808080uLL);
    v69 = _m_pxor(_m_paddsb(_m_pxor(v68, (__m64)0x8080808080808080uLL), v42), (__m64)0x8080808080808080uLL);
    v43 = _m_packsswb(
            _m_psrawi(
              _m_paddw(_m_pmulhw(_m_punpcklbw(0, v40), (__m64)0x900090009000900LL), (__m64)0x3F003F003F003FLL),
              7u),
            _m_psrawi(
              _m_paddw(_m_pmulhw(_m_punpckhbw(0, v40), (__m64)0x900090009000900LL), (__m64)0x3F003F003F003FLL),
              7u));
    v44 = _m_pxor(_m_paddsb(_m_pxor(v67, (__m64)0x8080808080808080uLL), v43), (__m64)0x8080808080808080uLL);
    v45 = _m_pxor(_m_psubsb(_m_pxor(v76, (__m64)0x8080808080808080uLL), v43), (__m64)0x8080808080808080uLL);
    v46 = _m_punpcklbw(v66, v44);
    v47 = _m_punpckhbw(v66, v44);
    v48 = _m_punpcklbw(v69, (__m64)v71.m64_u32[0]);
    v49 = _m_punpckhbw(v69, v71);
    v50 = v46;
    v51 = _m_punpcklwd(v46, v48);
    v52 = _m_punpckhwd(v50, v48);
    v53 = v47;
    v54 = _m_punpcklwd(v47, v49);
    v55 = _m_punpckhwd(v53, v49);
    v56 = _m_punpcklbw(v45, (__m64)v77.m64_u32[0]);
    v57 = _m_punpcklbw(v73, (__m64)v75.m64_u32[0]);
    v58 = _m_punpcklwd(v57, v56);
    v59 = _m_punpckhwd(v57, v56);
    *(__m64 *)((char *)v7 + 4 * v20) = _m_punpckldq(v51, v58);
    *(__m64 *)((char *)v9 + 4 * v20) = _m_punpckhdq(v51, v58);
    *(__m64 *)((char *)v7 + 2 * v20) = _m_punpckldq(v52, v59);
    *(__m64 *)((char *)v9 + 2 * v20) = _m_punpckhdq(v52, v59);
    v60 = _m_punpckhbw(v45, v77);
    v61 = _m_punpckhbw(v73, v75);
    v62 = _m_punpcklwd(v61, v60);
    v63 = _m_punpckhwd(v61, v60);
    v7->m64_u64 = (unsigned __int64)_m_punpckldq(v54, v62);
    v9->m64_u64 = (unsigned __int64)_m_punpckhdq(v54, v62);
    result = -v20;
    *(__m64 *)((char *)v7 + 2 * result) = _m_punpckldq(v55, v63);
    *(__m64 *)((char *)v9 + 2 * result) = _m_punpckhdq(v55, v63);
    v7 += result;
    --a6;
  }
  while ( a6 );
  return result;
}

