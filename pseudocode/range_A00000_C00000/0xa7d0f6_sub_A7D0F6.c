// Function: sub_A7D0F6
// Address: 0xa7d0f6
// Size: 0x354
// Prototype: 

int __cdecl sub_A7D0F6(int a1, int a2, const __m128i *a3, const __m128i *a4, const __m128i *a5, const double *a6)
{
  int result; // eax
  __m128i v7; // xmm2
  __m128i v8; // xmm4
  __m128i v9; // xmm5
  const double *v10; // edi
  __m128i si128; // xmm7
  __m128i v12; // xmm0
  __m128i v13; // xmm1
  __m128i v14; // xmm2
  __m128i v15; // xmm6
  __m128i v16; // xmm3
  __m128i v17; // xmm5
  __m128i v18; // xmm1
  __m128i v19; // xmm2
  __m128i v20; // xmm6
  __m128i v21; // xmm5
  __m128i v22; // xmm5
  __m128i v23; // xmm2
  __m128i v24; // xmm5
  __m128i v25; // xmm4
  __m128i v26; // xmm3
  __m128i v27; // xmm7
  __m128i v28; // xmm6
  __m128i v29; // xmm2
  __m128i v30; // xmm3
  __m128i v31; // xmm0
  __m128i v32; // xmm1
  __m128i v33; // xmm2
  __m128i v34; // xmm4
  __m128i v35; // xmm0
  __m128i v36; // xmm1
  __m128i v37; // xmm4
  __m128i v38; // xmm5
  __m128i v39; // xmm2
  __m128i v40; // xmm0
  __m128i v41; // xmm6
  __m128i v42; // xmm3
  __m128i v43; // xmm7
  __m128i v44; // xmm4
  __m128i v45; // xmm2
  __m128i v46; // xmm0
  __m128i v47; // xmm1
  __m128i v48; // xmm5
  __m128i v49; // xmm2
  __m128i v50; // xmm0
  __m128i v51; // xmm5
  __m128i v52; // xmm2
  __m128i v53; // xmm7
  _QWORD *v54; // esi
  double *v55; // edi
  __m128i v56; // xmm3
  __m128i v57; // xmm6
  __m128 v58; // xmm1
  __m128 v59; // xmm4
  __m128 v60; // xmm2
  __m128 v61; // xmm5
  __m128 v62; // xmm3
  __m128 v63; // xmm6
  __m128i v64; // [esp+0h] [ebp-B8h] BYREF
  __m128i v65[2]; // [esp+10h] [ebp-A8h] BYREF
  __m128i v66; // [esp+30h] [ebp-88h] BYREF
  __m128i v67[3]; // [esp+40h] [ebp-78h] BYREF
  __m128i v68; // [esp+70h] [ebp-48h] BYREF
  __m128i v69[2]; // [esp+80h] [ebp-38h] BYREF
  int *v70; // [esp+A0h] [ebp-18h]
  int v71; // [esp+B0h] [ebp-8h] BYREF

  v70 = &v71;
  result = -a2;
  v7 = (__m128i)_mm_loadh_ps((const double *)((char *)a6 + 2 * a2 + a2));
  v8 = (__m128i)_mm_loadh_ps((const double *)((char *)a6 + a2));
  v9 = (__m128i)_mm_loadh_ps(a6);
  v10 = (const double *)((char *)a6 + a2 + -4 * a2);
  v69[0] = (__m128i)_mm_loadh_ps((const double *)((char *)a6 + a2 + a2));
  v68 = v8;
  si128 = _mm_load_si128(a4);
  v12 = v9;
  v64 = _mm_or_si128(_mm_subs_epu8(v9, v8), _mm_subs_epu8(v8, v9));
  v13 = _mm_max_epu8(
          _mm_max_epu8(
            _mm_or_si128(_mm_subs_epu8(v69[0], v7), _mm_subs_epu8(v7, v69[0])),
            _mm_or_si128(_mm_subs_epu8(v8, v69[0]), _mm_subs_epu8(v69[0], v8))),
          v64);
  v14 = (__m128i)_mm_loadh_ps((const double *)((char *)a6 - 4 * a2));
  v15 = (__m128i)_mm_loadh_ps((const double *)((char *)v10 + a2));
  v66 = (__m128i)_mm_loadh_ps(v10);
  v67[0] = v15;
  v16 = _mm_load_si128(&v68);
  v17 = (__m128i)_mm_loadh_ps((const double *)((char *)v10 + 2 * a2));
  v65[0] = _mm_or_si128(_mm_subs_epu8(v15, v17), _mm_subs_epu8(v17, v15));
  v18 = _mm_subs_epu8(
          _mm_max_epu8(
            _mm_max_epu8(
              _mm_max_epu8(
                _mm_max_epu8(_mm_max_epu8(v13, _mm_subs_epu8(v66, v14)), _mm_subs_epu8(v14, v66)),
                _mm_subs_epu8(v66, v15)),
              _mm_subs_epu8(v15, v66)),
            v65[0]),
          si128);
  v19 = _mm_and_si128(_mm_or_si128(_mm_subs_epu8(v15, v16), _mm_subs_epu8(v16, v15)), (__m128i)xmmword_25D7000);
  v20 = v17;
  v21 = _mm_or_si128(_mm_subs_epu8(v17, v12), _mm_subs_epu8(v12, v17));
  v22 = _mm_adds_epu8(_mm_adds_epu8(v21, v21), _mm_srli_epi16(v19, 1u));
  v23 = _mm_load_si128(a5);
  v24 = _mm_subs_epu8(v22, _mm_load_si128(a3));
  v25 = _mm_xor_si128(
          _mm_cmpeq_epi8(
            _mm_add_epi8(_mm_subs_epu8(_mm_load_si128(&v64), v23), _mm_subs_epu8(_mm_load_si128(v65), v23)),
            v24),
          (__m128i)-1LL);
  v26 = _mm_load_si128(xmmword_25D7010);
  v27 = _mm_xor_si128(_mm_load_si128(&v68), v26);
  v28 = _mm_xor_si128(v20, v26);
  v29 = _mm_subs_epi8(_mm_xor_si128(_mm_load_si128(v67), v26), v27);
  v30 = _mm_xor_si128(v12, v26);
  v31 = _mm_subs_epi8(v30, v28);
  v32 = _mm_and_si128(
          _mm_cmpeq_epi8(_mm_or_si128(v18, v24), (__m128i)0LL),
          _mm_adds_epi8(_mm_adds_epi8(_mm_adds_epi8(v29, v31), v31), v31));
  v33 = _mm_and_si128(v32, v25);
  v34 = _mm_andnot_si128(v25, v32);
  v35 = _mm_unpacklo_epi8((__m128i)0LL, v34);
  v36 = _mm_unpackhi_epi8((__m128i)0LL, v34);
  v37 = _mm_load_si128((const __m128i *)&xmmword_25D7060);
  v38 = _mm_adds_epi8(v33, (__m128i)xmmword_25D7030);
  v39 = _mm_adds_epi8(v33, (__m128i)xmmword_25D7040);
  v40 = _mm_mulhi_epi16(v35, v37);
  v41 = _mm_adds_epi8(
          v28,
          _mm_packs_epi16(
            _mm_srai_epi16(_mm_unpacklo_epi8(v38, v38), 0xBu),
            _mm_srai_epi16(_mm_unpackhi_epi8(v27, v38), 0xBu)));
  v42 = _mm_subs_epi8(
          v30,
          _mm_packs_epi16(
            _mm_srai_epi16(_mm_unpacklo_epi8(v39, v39), 0xBu),
            _mm_srai_epi16(_mm_unpackhi_epi8(v37, v39), 0xBu)));
  v43 = _mm_mulhi_epi16(v36, v37);
  v44 = _mm_load_si128((const __m128i *)&xmmword_25D7070);
  v45 = v40;
  v46 = _mm_add_epi16(v40, v44);
  v47 = _mm_add_epi16(v43, v44);
  v48 = _mm_add_epi16(_mm_add_epi16(v45, v45), v46);
  v49 = _mm_add_epi16(v45, v46);
  v50 = _mm_packs_epi16(_mm_srai_epi16(v46, 7u), _mm_srai_epi16(v47, 7u));
  v51 = _mm_packs_epi16(_mm_srai_epi16(v48, 7u), _mm_srai_epi16(_mm_add_epi16(_mm_add_epi16(v43, v43), v47), 7u));
  v52 = _mm_packs_epi16(_mm_srai_epi16(v49, 7u), _mm_srai_epi16(_mm_add_epi16(v43, v47), 7u));
  v53 = _mm_load_si128(xmmword_25D7010);
  v54 = (_QWORD *)(a1 + a2 - 4 * a2 + 2 * a2);
  v55 = (double *)((char *)v10 + 2 * a2);
  v56 = _mm_subs_epi8(v42, v51);
  v57 = _mm_adds_epi8(v41, v51);
  v58 = (__m128)_mm_xor_si128(_mm_subs_epi8(_mm_xor_si128(_mm_load_si128(&v68), v53), v52), v53);
  v59 = (__m128)_mm_xor_si128(_mm_adds_epi8(_mm_xor_si128(_mm_load_si128(v67), v53), v52), v53);
  v60 = (__m128)_mm_xor_si128(_mm_adds_epi8(_mm_xor_si128(_mm_load_si128(&v66), v53), v50), v53);
  v61 = (__m128)_mm_xor_si128(_mm_subs_epi8(_mm_xor_si128(_mm_load_si128(v69), v53), v50), v53);
  v62 = (__m128)_mm_xor_si128(v56, v53);
  v63 = (__m128)_mm_xor_si128(v57, v53);
  *v54 = v63.m128_u64[0];
  _mm_storeh_ps(v55, v63);
  *(_QWORD *)((char *)v54 + a2) = v62.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v55 + a2), v62);
  *(_QWORD *)((char *)v54 + 2 * a2) = v58.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v55 + 2 * a2), v58);
  *(_QWORD *)((char *)v54 + result) = v59.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v55 - a2), v59);
  *(_QWORD *)((char *)v54 + 2 * result) = v60.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v55 - 2 * a2), v60);
  *(_QWORD *)((char *)v54 + 3 * a2) = v61.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v55 + 3 * a2), v61);
  return result;
}

