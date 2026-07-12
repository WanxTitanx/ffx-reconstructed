// Function: sub_A8BB70
// Address: 0xa8bb70
// Size: 0x150
// Prototype: 

unsigned int __cdecl sub_A8BB70(__m64 *a1, _WORD *a2)
{
  __m64 v2; // mm7
  __m64 v3; // mm2
  __m64 v4; // mm3
  __m64 v5; // mm7
  __m64 v6; // mm5
  __m64 v7; // mm6
  __m64 v8; // mm4
  __m64 v9; // mm6
  __m64 v10; // mm1
  __m64 v11; // mm5
  __m64 v12; // mm0
  __m64 v13; // mm5
  __m64 v14; // mm3
  __m64 v15; // mm4
  __m64 v16; // mm3
  __m64 v17; // mm1
  __m64 v18; // mm6
  __m64 v19; // mm1
  __m64 v20; // mm0
  __m64 v21; // mm4
  __m64 v22; // mm2
  __m64 v23; // mm3
  __m64 v24; // mm5
  __m64 v25; // mm6
  __m64 v26; // mm1
  __m64 v27; // mm6
  __m64 v28; // mm4
  __m64 v29; // mm5
  __m64 v30; // mm0
  __m64 v31; // mm5
  int v32; // eax
  int v33; // ecx
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // ecx
  unsigned int v38; // eax
  int v39; // ecx
  unsigned int result; // eax

  v2 = _mm_cvtsi32_si64(0x30003u);
  v3 = a1[2];
  v4 = a1[3];
  v5 = _m_punpcklwd(v2, v2);
  v6 = _m_paddw(a1[1], v3);
  v7 = _m_paddw((__m64)a1->m64_u64, v4);
  v8 = _m_paddw(v7, v6);
  v9 = _m_psubw(v7, v6);
  v10 = _m_psubw(a1[1], v3);
  v11 = _m_psubw((__m64)a1->m64_u64, v4);
  v12 = _m_paddw(v11, v10);
  v13 = _m_psubw(v11, v10);
  v14 = v8;
  v15 = _m_punpcklwd(v8, v12);
  v16 = _m_punpckhwd(v14, v12);
  v17 = v9;
  v18 = _m_punpcklwd(v9, v13);
  v19 = _m_punpckhwd(v17, v13);
  v20 = _m_punpckldq(v15, v18);
  v21 = _m_punpckhdq(v15, v18);
  v22 = _m_punpckldq(v16, v19);
  v23 = _m_punpckhdq(v16, v19);
  v24 = _m_paddw(v21, v22);
  v25 = _m_paddw(v20, v23);
  v26 = _m_psrawi(_m_paddw(_m_paddw(v25, v24), v5), 3u);
  v27 = _m_psrawi(_m_paddw(_m_psubw(v25, v24), v5), 3u);
  v28 = _m_psubw(v21, v22);
  v29 = _m_psubw(v20, v23);
  v30 = _m_psrawi(_m_paddw(_m_paddw(v29, v28), v5), 3u);
  v31 = _m_psrawi(_m_paddw(_m_psubw(v29, v28), v5), 3u);
  v32 = _mm_cvtsi64_si32(v26);
  v33 = _mm_cvtsi64_si32(v30);
  *a2 = v32;
  a2[16] = v33;
  a2[64] = HIWORD(v32);
  a2[80] = HIWORD(v33);
  v34 = _mm_cvtsi64_si32(_m_psrlqi(v26, 0x20u));
  v35 = _mm_cvtsi64_si32(_m_psrlqi(v30, 0x20u));
  a2[128] = v34;
  a2[144] = v35;
  a2[192] = HIWORD(v34);
  a2[208] = HIWORD(v35);
  v36 = _mm_cvtsi64_si32(v27);
  v37 = _mm_cvtsi64_si32(v31);
  a2[32] = v36;
  a2[48] = v37;
  a2[96] = HIWORD(v36);
  a2[112] = HIWORD(v37);
  v38 = _mm_cvtsi64_si32(_m_psrlqi(v27, 0x20u));
  v39 = _mm_cvtsi64_si32(_m_psrlqi(v31, 0x20u));
  a2[160] = v38;
  a2[176] = v39;
  result = HIWORD(v38);
  a2[224] = result;
  a2[240] = HIWORD(v39);
  return result;
}

