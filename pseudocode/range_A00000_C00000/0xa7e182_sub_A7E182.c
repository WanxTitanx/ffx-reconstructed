// Function: sub_A7E182
// Address: 0xa7e182
// Size: 0x51e
// Prototype: 

int __cdecl sub_A7E182(int a1, int a2, const __m128i *a3, __m128i *a4, const __m128i *a5, int a6)
{
  const __m128i *v7; // edi
  int v8; // ecx
  __m128i v9; // xmm4
  __m128i v10; // xmm0
  __m128i v11; // xmm6
  __m128i v12; // xmm7
  __m128i v13; // xmm5
  __m128i v14; // xmm6
  const __m128i *v15; // edi
  __m128i v16; // xmm2
  __m128i v17; // xmm4
  __m128i v18; // xmm3
  __m128i v19; // xmm7
  __m128i v20; // xmm4
  __m128i v21; // xmm2
  __m128i v22; // xmm0
  __m128i v23; // xmm1
  __m128i v24; // xmm5
  __m128i v25; // xmm6
  __m128i v26; // xmm1
  __m128i v27; // xmm5
  __m128i v28; // xmm2
  __m128i v29; // xmm0
  __m128i v30; // xmm5
  __m128i v31; // xmm1
  __m128i v32; // xmm2
  __m128i si128; // xmm2
  __m128i v34; // xmm2
  __m128i v35; // xmm0
  __m128i v36; // xmm1
  __m128i v37; // xmm2
  __m128i v38; // xmm6
  __m128i v39; // xmm4
  __m128i v40; // xmm7
  __m128i v41; // xmm0
  __m128i v42; // xmm5
  __m128i v43; // xmm1
  __m128i v44; // xmm3
  __m128i v45; // xmm1
  __m128i v46; // xmm4
  __m128i v47; // xmm3
  __m128i v48; // xmm7
  __m128i v49; // xmm6
  __m128i v50; // xmm2
  __m128i v51; // xmm3
  __m128i v52; // xmm0
  __m128i v53; // xmm1
  __m128i v54; // xmm2
  __m128i v55; // xmm4
  __m128i v56; // xmm0
  __m128i v57; // xmm1
  __m128i v58; // xmm4
  __m128i v59; // xmm5
  __m128i v60; // xmm2
  __m128i v61; // xmm0
  __m128i v62; // xmm6
  __m128i v63; // xmm3
  __m128i v64; // xmm7
  __m128i v65; // xmm4
  __m128i v66; // xmm2
  __m128i v67; // xmm0
  __m128i v68; // xmm1
  __m128i v69; // xmm5
  __m128i v70; // xmm2
  __m128i v71; // xmm0
  __m128i v72; // xmm5
  __m128i v73; // xmm2
  __m128i v74; // xmm7
  __m128i v75; // xmm3
  __m128i v76; // xmm6
  __m128i v77; // xmm1
  __m128i v78; // xmm4
  __m128i v79; // xmm2
  __m128i v80; // xmm5
  __m128i v81; // xmm1
  __m128i v82; // xmm6
  __m128i v83; // xmm7
  __m128i v84; // xmm6
  __m128i v85; // xmm3
  __m128i v86; // xmm0
  __m128i v87; // xmm3
  __m128i v88; // xmm4
  __m128i v89; // xmm1
  __m128i v90; // xmm4
  __m128i v91; // xmm6
  __m128i v92; // xmm2
  __m128i v93; // xmm7
  __m128i v94; // xmm2
  __m128i v95; // xmm6
  __m128 v96; // xmm0
  __m128 v97; // xmm6
  _QWORD *v98; // esi
  double *v99; // edi
  __m128 v100; // xmm0
  __m128 v101; // xmm3
  __m128i v102; // xmm7
  __m128i v103; // xmm5
  __m128i v104; // xmm0
  __m128i v105; // xmm7
  __m128i v106; // xmm5
  __m128 v107; // xmm1
  __m128 v108; // xmm5
  _QWORD *v109; // esi
  double *v110; // edi
  __m128 v111; // xmm1
  __m128 v112; // xmm4
  __m128i v113[2]; // [esp+0h] [ebp-B8h] BYREF
  __m128i v114; // [esp+20h] [ebp-98h] BYREF
  __m128i v115; // [esp+30h] [ebp-88h] BYREF
  __m128i v116; // [esp+40h] [ebp-78h] BYREF
  __m128i v117; // [esp+50h] [ebp-68h] BYREF
  __m128i v118; // [esp+60h] [ebp-58h] BYREF
  __m128i v119; // [esp+70h] [ebp-48h] BYREF
  __m128i v120; // [esp+80h] [ebp-38h] BYREF
  __m128i v121; // [esp+90h] [ebp-28h]
  int *v122; // [esp+A0h] [ebp-18h]
  int v123; // [esp+B0h] [ebp-8h] BYREF

  v122 = &v123;
  v7 = (const __m128i *)(a1 - 4 + a2);
  v8 = 3 * a2;
  v9 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(a1 - 4)), _mm_loadl_epi64(v7));
  v10 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(a1 - 4 + 2 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v7 + 2 * a2)));
  v11 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(a1 - 4 + 4 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v7 + 4 * a2)));
  v12 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(a1 - 4 + 6 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v7 + 6 * a2)));
  v13 = _mm_unpacklo_epi16(v11, v12);
  v14 = _mm_unpackhi_epi16(v11, v12);
  v15 = (const __m128i *)(a6 + a2 - 4);
  v16 = _mm_unpacklo_epi16(v9, v10);
  v17 = _mm_unpackhi_epi16(v9, v10);
  v18 = _mm_unpackhi_epi32(v16, v13);
  v19 = _mm_unpackhi_epi32(v17, v14);
  v20 = _mm_unpacklo_epi32(v17, v14);
  v113[0] = _mm_unpacklo_epi32(v16, v13);
  v21 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(a6 - 4)), _mm_loadl_epi64(v15));
  v22 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(a6 - 4 + 2 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v15 + 2 * a2)));
  v23 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(a6 - 4 + 4 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v15 + 4 * a2)));
  v24 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(a6 - 4 + 6 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v15 + 6 * a2)));
  v25 = _mm_unpackhi_epi16(v23, v24);
  v26 = _mm_unpacklo_epi16(v23, v24);
  v27 = _mm_unpacklo_epi16(v21, v22);
  v28 = _mm_unpackhi_epi16(v21, v22);
  v29 = _mm_unpacklo_epi32(v27, v26);
  v30 = _mm_unpackhi_epi32(v27, v26);
  v31 = _mm_unpacklo_epi32(v28, v25);
  v32 = _mm_unpackhi_epi32(v28, v25);
  v121 = _mm_unpackhi_epi64(v19, v32);
  v120 = _mm_unpacklo_epi64(v19, v32);
  v116 = _mm_unpacklo_epi64(v18, v30);
  v117 = _mm_unpackhi_epi64(v18, v30);
  v118 = _mm_unpacklo_epi64(v20, v31);
  v119 = _mm_unpackhi_epi64(v20, v31);
  si128 = _mm_load_si128(v113);
  v115 = _mm_unpackhi_epi64(si128, v29);
  v114 = _mm_unpacklo_epi64(si128, v29);
  v34 = _mm_load_si128(&v116);
  v35 = _mm_max_epu8(
          _mm_max_epu8(
            _mm_max_epu8(
              _mm_or_si128(_mm_subs_epu8(v115, v114), _mm_subs_epu8(v114, v115)),
              _mm_or_si128(_mm_subs_epu8(v121, v120), _mm_subs_epu8(v120, v121))),
            _mm_or_si128(_mm_subs_epu8(v120, v119), _mm_subs_epu8(v119, v120))),
          _mm_or_si128(_mm_subs_epu8(v115, v34), _mm_subs_epu8(v34, v115)));
  v36 = v34;
  v37 = _mm_or_si128(_mm_subs_epu8(v34, v117), _mm_subs_epu8(v117, v34));
  v38 = _mm_load_si128(&v118);
  v39 = _mm_load_si128(&v119);
  v40 = _mm_or_si128(_mm_subs_epu8(v39, v38), _mm_subs_epu8(v38, v39));
  v41 = _mm_subs_epu8(_mm_max_epu8(_mm_max_epu8(v35, v37), v40), *a4);
  v42 = _mm_and_si128(_mm_or_si128(_mm_subs_epu8(v39, v36), _mm_subs_epu8(v36, v39)), (__m128i)xmmword_25D7000);
  v43 = _mm_or_si128(_mm_subs_epu8(v117, v38), _mm_subs_epu8(v38, v117));
  v44 = _mm_load_si128(a5);
  v45 = _mm_cmpeq_epi8(
          _mm_or_si128(
            _mm_subs_epu8(_mm_adds_epu8(_mm_adds_epu8(v43, v43), _mm_srli_epi16(v42, 1u)), _mm_load_si128(a3)),
            v41),
          (__m128i)0LL);
  v46 = _mm_xor_si128(
          (__m128i)-1LL,
          _mm_cmpeq_epi8(_mm_or_si128(_mm_subs_epu8(v37, v44), _mm_subs_epu8(v40, v44)), v41));
  v47 = _mm_load_si128(xmmword_25D7010);
  v48 = _mm_xor_si128(_mm_load_si128(&v119), v47);
  v49 = _mm_xor_si128(_mm_load_si128(&v117), v47);
  v50 = _mm_subs_epi8(_mm_xor_si128(_mm_load_si128(&v116), v47), v48);
  v51 = _mm_xor_si128(_mm_load_si128(&v118), v47);
  v52 = _mm_subs_epi8(v51, v49);
  v53 = _mm_and_si128(v45, _mm_adds_epi8(_mm_adds_epi8(_mm_adds_epi8(v50, v52), v52), v52));
  v54 = _mm_and_si128(v53, v46);
  v55 = _mm_andnot_si128(v46, v53);
  v56 = _mm_unpacklo_epi8((__m128i)0LL, v55);
  v57 = _mm_unpackhi_epi8((__m128i)0LL, v55);
  v58 = _mm_load_si128((const __m128i *)&xmmword_25D7060);
  v59 = _mm_adds_epi8(v54, (__m128i)xmmword_25D7030);
  v60 = _mm_adds_epi8(v54, (__m128i)xmmword_25D7040);
  v61 = _mm_mulhi_epi16(v56, v58);
  v62 = _mm_adds_epi8(
          v49,
          _mm_packs_epi16(
            _mm_srai_epi16(_mm_unpacklo_epi8(v59, v59), 0xBu),
            _mm_srai_epi16(_mm_unpackhi_epi8(v48, v59), 0xBu)));
  v63 = _mm_subs_epi8(
          v51,
          _mm_packs_epi16(
            _mm_srai_epi16(_mm_unpacklo_epi8(v60, v60), 0xBu),
            _mm_srai_epi16(_mm_unpackhi_epi8(v58, v60), 0xBu)));
  v64 = _mm_mulhi_epi16(v57, v58);
  v65 = _mm_load_si128((const __m128i *)&xmmword_25D7070);
  v66 = v61;
  v67 = _mm_add_epi16(v61, v65);
  v68 = _mm_add_epi16(v64, v65);
  v69 = _mm_add_epi16(_mm_add_epi16(v66, v66), v67);
  v70 = _mm_add_epi16(v66, v67);
  v71 = _mm_packs_epi16(_mm_srai_epi16(v67, 7u), _mm_srai_epi16(v68, 7u));
  v72 = _mm_packs_epi16(_mm_srai_epi16(v69, 7u), _mm_srai_epi16(_mm_add_epi16(_mm_add_epi16(v64, v64), v68), 7u));
  v73 = _mm_packs_epi16(_mm_srai_epi16(v70, 7u), _mm_srai_epi16(_mm_add_epi16(v64, v68), 7u));
  v74 = _mm_load_si128(xmmword_25D7010);
  v75 = _mm_subs_epi8(v63, v72);
  v76 = _mm_adds_epi8(v62, v72);
  v77 = _mm_subs_epi8(_mm_xor_si128(_mm_load_si128(&v119), v74), v73);
  v78 = _mm_adds_epi8(_mm_xor_si128(_mm_load_si128(&v116), v74), v73);
  v79 = _mm_xor_si128(_mm_adds_epi8(_mm_xor_si128(_mm_load_si128(&v115), v74), v71), v74);
  v80 = _mm_xor_si128(_mm_subs_epi8(_mm_xor_si128(_mm_load_si128(&v120), v74), v71), v74);
  v116 = _mm_xor_si128(v78, v74);
  v117 = _mm_xor_si128(v76, v74);
  v118 = _mm_xor_si128(v75, v74);
  v119 = _mm_xor_si128(v77, v74);
  v81 = _mm_load_si128(&v114);
  v82 = _mm_load_si128(&v116);
  v83 = _mm_unpacklo_epi8(v82, v117);
  v84 = _mm_unpackhi_epi8(v82, v117);
  v85 = _mm_unpacklo_epi8(v81, v79);
  v86 = _mm_unpacklo_epi16(v85, v83);
  v87 = _mm_unpackhi_epi16(v85, v83);
  v88 = _mm_unpackhi_epi8(v81, v79);
  v89 = _mm_unpacklo_epi16(v88, v84);
  v90 = _mm_unpackhi_epi16(v88, v84);
  v91 = _mm_unpacklo_epi8(v80, v121);
  v92 = _mm_unpacklo_epi8(_mm_load_si128(&v118), v119);
  v93 = _mm_unpacklo_epi16(v92, v91);
  v94 = _mm_unpackhi_epi16(v92, v91);
  v95 = v86;
  v96 = (__m128)_mm_unpacklo_epi32(v86, v93);
  v97 = (__m128)_mm_unpackhi_epi32(v95, v93);
  v98 = (_QWORD *)(a1 - 4);
  v99 = (double *)(a1 - 4 + a2);
  *v98 = v96.m128_u64[0];
  _mm_storeh_ps(v99, v96);
  *(_QWORD *)((char *)v98 + 2 * a2) = v97.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v99 + 2 * a2), v97);
  v100 = (__m128)_mm_unpacklo_epi32(v87, v94);
  v101 = (__m128)_mm_unpackhi_epi32(v87, v94);
  *(_QWORD *)((char *)v98 + 4 * a2) = v100.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v99 + 4 * a2), v100);
  *(_QWORD *)((char *)v98 + 2 * v8) = v101.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v99 + 6 * a2), v101);
  v102 = _mm_unpackhi_epi8(_mm_load_si128(&v118), v119);
  v103 = _mm_unpackhi_epi8(v80, v121);
  v104 = _mm_unpacklo_epi16(v102, v103);
  v105 = _mm_unpackhi_epi16(v102, v103);
  v106 = v89;
  v107 = (__m128)_mm_unpacklo_epi32(v89, v104);
  v108 = (__m128)_mm_unpackhi_epi32(v106, v104);
  v109 = (_QWORD *)(a6 - 4);
  v110 = (double *)(a6 - 4 + a2);
  *v109 = v107.m128_u64[0];
  _mm_storeh_ps(v110, v107);
  *(_QWORD *)((char *)v109 + 2 * a2) = v108.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v110 + 2 * a2), v108);
  v111 = (__m128)_mm_unpacklo_epi32(v90, v105);
  v112 = (__m128)_mm_unpackhi_epi32(v90, v105);
  *(_QWORD *)((char *)v109 + 4 * a2) = v111.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v110 + 4 * a2), v111);
  *(_QWORD *)((char *)v109 + 2 * v8) = v112.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v110 + 6 * a2), v112);
  return a2;
}

