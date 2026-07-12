// Function: sub_A7DC6A
// Address: 0xa7dc6a
// Size: 0x518
// Prototype: 

int __cdecl sub_A7DC6A(int a1, int a2, const __m128i *a3, __m128i *a4, const __m128i *a5)
{
  const __m128i *v5; // edi
  int v6; // ecx
  __m128i v7; // xmm4
  __m128i v8; // xmm1
  __m128i v9; // xmm0
  __m128i v10; // xmm5
  const __m128i *v11; // esi
  const __m128i *v12; // edi
  __m128i v13; // xmm6
  __m128i v14; // xmm7
  __m128i v15; // xmm5
  __m128i v16; // xmm6
  __m128i v17; // xmm2
  __m128i v18; // xmm4
  __m128i v19; // xmm3
  __m128i v20; // xmm7
  __m128i v21; // xmm4
  __m128i v22; // xmm2
  __m128i v23; // xmm0
  __m128i v24; // xmm1
  __m128i v25; // xmm5
  __m128i v26; // xmm6
  __m128i v27; // xmm1
  __m128i v28; // xmm5
  __m128i v29; // xmm2
  __m128i v30; // xmm0
  __m128i v31; // xmm5
  __m128i v32; // xmm1
  __m128i v33; // xmm2
  __m128i si128; // xmm2
  __m128i v35; // xmm2
  __m128i v36; // xmm0
  __m128i v37; // xmm1
  __m128i v38; // xmm2
  __m128i v39; // xmm6
  __m128i v40; // xmm4
  __m128i v41; // xmm7
  __m128i v42; // xmm0
  __m128i v43; // xmm5
  __m128i v44; // xmm1
  __m128i v45; // xmm3
  __m128i v46; // xmm1
  __m128i v47; // xmm4
  __m128i v48; // xmm3
  __m128i v49; // xmm7
  __m128i v50; // xmm6
  __m128i v51; // xmm2
  __m128i v52; // xmm3
  __m128i v53; // xmm0
  __m128i v54; // xmm1
  __m128i v55; // xmm2
  __m128i v56; // xmm4
  __m128i v57; // xmm0
  __m128i v58; // xmm1
  __m128i v59; // xmm4
  __m128i v60; // xmm5
  __m128i v61; // xmm2
  __m128i v62; // xmm0
  __m128i v63; // xmm6
  __m128i v64; // xmm3
  __m128i v65; // xmm7
  __m128i v66; // xmm4
  __m128i v67; // xmm2
  __m128i v68; // xmm0
  __m128i v69; // xmm1
  __m128i v70; // xmm5
  __m128i v71; // xmm2
  __m128i v72; // xmm0
  __m128i v73; // xmm5
  __m128i v74; // xmm2
  __m128i v75; // xmm7
  __m128i v76; // xmm3
  __m128i v77; // xmm6
  __m128i v78; // xmm1
  __m128i v79; // xmm4
  __m128i v80; // xmm2
  __m128i v81; // xmm5
  _QWORD *v82; // esi
  double *v83; // edi
  __m128i v84; // xmm1
  __m128i v85; // xmm6
  __m128i v86; // xmm7
  __m128i v87; // xmm6
  __m128i v88; // xmm3
  __m128i v89; // xmm0
  __m128i v90; // xmm3
  __m128i v91; // xmm4
  __m128i v92; // xmm1
  __m128i v93; // xmm4
  __m128i v94; // xmm6
  __m128i v95; // xmm2
  __m128i v96; // xmm7
  __m128i v97; // xmm2
  __m128i v98; // xmm6
  __m128 v99; // xmm0
  __m128 v100; // xmm6
  __m128 v102; // xmm0
  __m128 v103; // xmm3
  __m128i v104; // xmm7
  __m128i v105; // xmm5
  __m128i v106; // xmm0
  __m128i v107; // xmm7
  __m128i v108; // xmm5
  __m128 v109; // xmm1
  __m128 v110; // xmm5
  _QWORD *v111; // esi
  double *v112; // edi
  __m128 v113; // xmm1
  __m128 v114; // xmm4
  __m128i v115[2]; // [esp+0h] [ebp-B8h] BYREF
  __m128i v116; // [esp+20h] [ebp-98h] BYREF
  __m128i v117; // [esp+30h] [ebp-88h] BYREF
  __m128i v118; // [esp+40h] [ebp-78h] BYREF
  __m128i v119; // [esp+50h] [ebp-68h] BYREF
  __m128i v120; // [esp+60h] [ebp-58h] BYREF
  __m128i v121; // [esp+70h] [ebp-48h] BYREF
  __m128i v122; // [esp+80h] [ebp-38h] BYREF
  __m128i v123; // [esp+90h] [ebp-28h]
  int *v124; // [esp+A0h] [ebp-18h]
  int v125; // [esp+B0h] [ebp-8h] BYREF

  v124 = &v125;
  v5 = (const __m128i *)(a1 - 4 + a2);
  v6 = 3 * a2;
  v7 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(a1 - 4)), _mm_loadl_epi64(v5));
  v8 = _mm_loadl_epi64((const __m128i *)((char *)v5 + 6 * a2));
  v9 = _mm_unpacklo_epi8(
         _mm_loadl_epi64((const __m128i *)(a1 - 4 + 2 * a2)),
         _mm_loadl_epi64((const __m128i *)((char *)v5 + 2 * a2)));
  v10 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(a1 - 4 + 4 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v5 + 4 * a2)));
  v11 = (const __m128i *)(a1 - 4 + 8 * a2);
  v12 = (const __m128i *)((char *)v5 + 8 * a2);
  v13 = v10;
  v14 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(a1 - 4 + 6 * a2)), v8);
  v15 = _mm_unpacklo_epi16(v10, v14);
  v16 = _mm_unpackhi_epi16(v13, v14);
  v17 = _mm_unpacklo_epi16(v7, v9);
  v18 = _mm_unpackhi_epi16(v7, v9);
  v19 = _mm_unpackhi_epi32(v17, v15);
  v20 = _mm_unpackhi_epi32(v18, v16);
  v21 = _mm_unpacklo_epi32(v18, v16);
  v115[0] = _mm_unpacklo_epi32(v17, v15);
  v22 = _mm_unpacklo_epi8(_mm_loadl_epi64(v11), _mm_loadl_epi64(v12));
  v23 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)((char *)v11 + 2 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v12 + 2 * a2)));
  v24 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)((char *)v11 + 4 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v12 + 4 * a2)));
  v25 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)((char *)v11 + 6 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v12 + 6 * a2)));
  v26 = _mm_unpackhi_epi16(v24, v25);
  v27 = _mm_unpacklo_epi16(v24, v25);
  v28 = _mm_unpacklo_epi16(v22, v23);
  v29 = _mm_unpackhi_epi16(v22, v23);
  v30 = _mm_unpacklo_epi32(v28, v27);
  v31 = _mm_unpackhi_epi32(v28, v27);
  v32 = _mm_unpacklo_epi32(v29, v26);
  v33 = _mm_unpackhi_epi32(v29, v26);
  v123 = _mm_unpackhi_epi64(v20, v33);
  v122 = _mm_unpacklo_epi64(v20, v33);
  v118 = _mm_unpacklo_epi64(v19, v31);
  v119 = _mm_unpackhi_epi64(v19, v31);
  v120 = _mm_unpacklo_epi64(v21, v32);
  v121 = _mm_unpackhi_epi64(v21, v32);
  si128 = _mm_load_si128(v115);
  v117 = _mm_unpackhi_epi64(si128, v30);
  v116 = _mm_unpacklo_epi64(si128, v30);
  v35 = _mm_load_si128(&v118);
  v36 = _mm_max_epu8(
          _mm_max_epu8(
            _mm_max_epu8(
              _mm_or_si128(_mm_subs_epu8(v117, v116), _mm_subs_epu8(v116, v117)),
              _mm_or_si128(_mm_subs_epu8(v123, v122), _mm_subs_epu8(v122, v123))),
            _mm_or_si128(_mm_subs_epu8(v122, v121), _mm_subs_epu8(v121, v122))),
          _mm_or_si128(_mm_subs_epu8(v117, v35), _mm_subs_epu8(v35, v117)));
  v37 = v35;
  v38 = _mm_or_si128(_mm_subs_epu8(v35, v119), _mm_subs_epu8(v119, v35));
  v39 = _mm_load_si128(&v120);
  v40 = _mm_load_si128(&v121);
  v41 = _mm_or_si128(_mm_subs_epu8(v40, v39), _mm_subs_epu8(v39, v40));
  v42 = _mm_subs_epu8(_mm_max_epu8(_mm_max_epu8(v36, v38), v41), *a4);
  v43 = _mm_and_si128(_mm_or_si128(_mm_subs_epu8(v40, v37), _mm_subs_epu8(v37, v40)), (__m128i)xmmword_25D7000);
  v44 = _mm_or_si128(_mm_subs_epu8(v119, v39), _mm_subs_epu8(v39, v119));
  v45 = _mm_load_si128(a5);
  v46 = _mm_cmpeq_epi8(
          _mm_or_si128(
            _mm_subs_epu8(_mm_adds_epu8(_mm_adds_epu8(v44, v44), _mm_srli_epi16(v43, 1u)), _mm_load_si128(a3)),
            v42),
          (__m128i)0LL);
  v47 = _mm_xor_si128(
          (__m128i)-1LL,
          _mm_cmpeq_epi8(_mm_or_si128(_mm_subs_epu8(v38, v45), _mm_subs_epu8(v41, v45)), v42));
  v48 = _mm_load_si128(xmmword_25D7010);
  v49 = _mm_xor_si128(_mm_load_si128(&v121), v48);
  v50 = _mm_xor_si128(_mm_load_si128(&v119), v48);
  v51 = _mm_subs_epi8(_mm_xor_si128(_mm_load_si128(&v118), v48), v49);
  v52 = _mm_xor_si128(_mm_load_si128(&v120), v48);
  v53 = _mm_subs_epi8(v52, v50);
  v54 = _mm_and_si128(v46, _mm_adds_epi8(_mm_adds_epi8(_mm_adds_epi8(v51, v53), v53), v53));
  v55 = _mm_and_si128(v54, v47);
  v56 = _mm_andnot_si128(v47, v54);
  v57 = _mm_unpacklo_epi8((__m128i)0LL, v56);
  v58 = _mm_unpackhi_epi8((__m128i)0LL, v56);
  v59 = _mm_load_si128((const __m128i *)&xmmword_25D7060);
  v60 = _mm_adds_epi8(v55, (__m128i)xmmword_25D7030);
  v61 = _mm_adds_epi8(v55, (__m128i)xmmword_25D7040);
  v62 = _mm_mulhi_epi16(v57, v59);
  v63 = _mm_adds_epi8(
          v50,
          _mm_packs_epi16(
            _mm_srai_epi16(_mm_unpacklo_epi8(v60, v60), 0xBu),
            _mm_srai_epi16(_mm_unpackhi_epi8(v49, v60), 0xBu)));
  v64 = _mm_subs_epi8(
          v52,
          _mm_packs_epi16(
            _mm_srai_epi16(_mm_unpacklo_epi8(v61, v61), 0xBu),
            _mm_srai_epi16(_mm_unpackhi_epi8(v59, v61), 0xBu)));
  v65 = _mm_mulhi_epi16(v58, v59);
  v66 = _mm_load_si128((const __m128i *)&xmmword_25D7070);
  v67 = v62;
  v68 = _mm_add_epi16(v62, v66);
  v69 = _mm_add_epi16(v65, v66);
  v70 = _mm_add_epi16(_mm_add_epi16(v67, v67), v68);
  v71 = _mm_add_epi16(v67, v68);
  v72 = _mm_packs_epi16(_mm_srai_epi16(v68, 7u), _mm_srai_epi16(v69, 7u));
  v73 = _mm_packs_epi16(_mm_srai_epi16(v70, 7u), _mm_srai_epi16(_mm_add_epi16(_mm_add_epi16(v65, v65), v69), 7u));
  v74 = _mm_packs_epi16(_mm_srai_epi16(v71, 7u), _mm_srai_epi16(_mm_add_epi16(v65, v69), 7u));
  v75 = _mm_load_si128(xmmword_25D7010);
  v76 = _mm_subs_epi8(v64, v73);
  v77 = _mm_adds_epi8(v63, v73);
  v78 = _mm_subs_epi8(_mm_xor_si128(_mm_load_si128(&v121), v75), v74);
  v79 = _mm_adds_epi8(_mm_xor_si128(_mm_load_si128(&v118), v75), v74);
  v80 = _mm_xor_si128(_mm_adds_epi8(_mm_xor_si128(_mm_load_si128(&v117), v75), v72), v75);
  v81 = _mm_xor_si128(_mm_subs_epi8(_mm_xor_si128(_mm_load_si128(&v122), v75), v72), v75);
  v118 = _mm_xor_si128(v79, v75);
  v119 = _mm_xor_si128(v77, v75);
  v120 = _mm_xor_si128(v76, v75);
  v121 = _mm_xor_si128(v78, v75);
  v82 = (_QWORD *)(a1 - 4);
  v83 = (double *)&v12->m128i_i64[-a2];
  v84 = _mm_load_si128(&v116);
  v85 = _mm_load_si128(&v118);
  v86 = _mm_unpacklo_epi8(v85, v119);
  v87 = _mm_unpackhi_epi8(v85, v119);
  v88 = _mm_unpacklo_epi8(v84, v80);
  v89 = _mm_unpacklo_epi16(v88, v86);
  v90 = _mm_unpackhi_epi16(v88, v86);
  v91 = _mm_unpackhi_epi8(v84, v80);
  v92 = _mm_unpacklo_epi16(v91, v87);
  v93 = _mm_unpackhi_epi16(v91, v87);
  v94 = _mm_unpacklo_epi8(v81, v123);
  v95 = _mm_unpacklo_epi8(_mm_load_si128(&v120), v121);
  v96 = _mm_unpacklo_epi16(v95, v94);
  v97 = _mm_unpackhi_epi16(v95, v94);
  v98 = v89;
  v99 = (__m128)_mm_unpacklo_epi32(v89, v96);
  v100 = (__m128)_mm_unpackhi_epi32(v98, v96);
  *v82 = v99.m128_u64[0];
  _mm_storeh_ps(v83, v99);
  *(_QWORD *)((char *)v82 + 2 * a2) = v100.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v83 + 2 * a2), v100);
  v102 = (__m128)_mm_unpacklo_epi32(v90, v97);
  v103 = (__m128)_mm_unpackhi_epi32(v90, v97);
  *(_QWORD *)((char *)v82 + 4 * a2) = v102.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v83 + 4 * a2), v102);
  *(_QWORD *)((char *)v82 + 2 * v6) = v103.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v83 + 6 * a2), v103);
  v104 = _mm_unpackhi_epi8(_mm_load_si128(&v120), v121);
  v105 = _mm_unpackhi_epi8(v81, v123);
  v106 = _mm_unpacklo_epi16(v104, v105);
  v107 = _mm_unpackhi_epi16(v104, v105);
  v108 = v92;
  v109 = (__m128)_mm_unpacklo_epi32(v92, v106);
  v110 = (__m128)_mm_unpackhi_epi32(v108, v106);
  v111 = (_QWORD *)(a1 - 4 + 8 * a2);
  v112 = &v83[a2];
  *v111 = v109.m128_u64[0];
  _mm_storeh_ps(v112, v109);
  *(_QWORD *)((char *)v111 + 2 * a2) = v110.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v112 + 2 * a2), v110);
  v113 = (__m128)_mm_unpacklo_epi32(v93, v107);
  v114 = (__m128)_mm_unpackhi_epi32(v93, v107);
  *(_QWORD *)((char *)v111 + 4 * a2) = v113.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v112 + 4 * a2), v113);
  *(_QWORD *)((char *)v111 + 2 * v6) = v114.m128_u64[0];
  _mm_storeh_ps((double *)((char *)v112 + 6 * a2), v114);
  return a2;
}

