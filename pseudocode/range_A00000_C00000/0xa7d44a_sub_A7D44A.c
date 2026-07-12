// Function: sub_A7D44A
// Address: 0xa7d44a
// Size: 0x40d
// Prototype: 

int __cdecl sub_A7D44A(int a1, int a2, const __m128i *a3, __m128i *a4, const __m128i *a5)
{
  const __m128i *v6; // edi
  int v7; // ecx
  __m128i v8; // xmm4
  __m128i v9; // xmm1
  __m128i v10; // xmm0
  __m128i v11; // xmm5
  int v12; // esi
  __int8 *v13; // edi
  __m128i v14; // xmm6
  __m128i v15; // xmm7
  __m128i v16; // xmm5
  __m128i v17; // xmm6
  __m128i v18; // xmm2
  __m128i v19; // xmm4
  __m128i v20; // xmm3
  __m128i v21; // xmm7
  __m128i v22; // xmm4
  __m128i v23; // xmm2
  __m128i v24; // xmm0
  __m128i v25; // xmm1
  __m128i v26; // xmm5
  __m128i v27; // xmm6
  __m128i v28; // xmm1
  __m128i v29; // xmm5
  __m128i v30; // xmm2
  __m128i v31; // xmm0
  __m128i v32; // xmm5
  __m128i v33; // xmm1
  __m128i v34; // xmm2
  __m128i v35; // xmm6
  __m128i v36; // xmm7
  __m128i si128; // xmm2
  __m128i v38; // xmm1
  __m128i v39; // xmm2
  __m128i v40; // xmm0
  __m128i v41; // xmm2
  __m128i v42; // xmm0
  __m128i v43; // xmm1
  __m128i v44; // xmm2
  __m128i v45; // xmm6
  __m128i v46; // xmm4
  __m128i v47; // xmm7
  __m128i v48; // xmm0
  __m128i v49; // xmm5
  __m128i v50; // xmm1
  __m128i v51; // xmm3
  __m128i v52; // xmm1
  __m128i v53; // xmm4
  __m128i v54; // xmm3
  __m128i v55; // xmm7
  __m128i v56; // xmm6
  __m128i v57; // xmm2
  __m128i v58; // xmm3
  __m128i v59; // xmm0
  __m128i v60; // xmm2
  __m128i v61; // xmm1
  __m128i v62; // xmm2
  __m128i v63; // xmm0
  __m128i v64; // xmm2
  __m128i v65; // xmm1
  __m128i v66; // xmm5
  __m128i v67; // xmm0
  __m128i v68; // xmm6
  __m128i v69; // xmm2
  __m128i v70; // xmm5
  __m128i v71; // xmm2
  __m128i v72; // xmm4
  __m128i v73; // xmm6
  __m128i v74; // xmm3
  __m128i v75; // xmm1
  __m128i v76; // xmm7
  __m128i v77; // xmm2
  __m128i v78; // xmm1
  __m128i v79; // xmm4
  __m128i v80; // xmm3
  __m128i v81; // xmm6
  __m128i v82; // xmm2
  __m128i v83; // xmm6
  __m128i v84; // xmm5
  __m128i v85; // xmm1
  __m128i v86; // xmm5
  __m128i v87; // xmm1
  __m128i v88; // xmm5
  __m128i v89; // xmm1
  __m128i v90; // xmm5
  int v91; // esi
  char *v92; // edi
  __m128i v93; // xmm2
  __m128i v94; // xmm6
  __m128i v95; // xmm2
  __m128i v96; // xmm6
  __m128i v97[4]; // [esp+0h] [ebp-B8h] BYREF
  __m128i v98; // [esp+40h] [ebp-78h] BYREF
  __m128i v99; // [esp+50h] [ebp-68h] BYREF
  __m128i v100; // [esp+60h] [ebp-58h] BYREF
  __m128i v101[3]; // [esp+70h] [ebp-48h] BYREF
  int *v102; // [esp+A0h] [ebp-18h]
  int v103; // [esp+B0h] [ebp-8h] BYREF

  v102 = &v103;
  v6 = (const __m128i *)(a1 - 4 + a2);
  v7 = 3 * a2;
  v8 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(a1 - 4)), _mm_loadl_epi64(v6));
  v9 = _mm_loadl_epi64((const __m128i *)((char *)v6 + 6 * a2));
  v10 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(a1 - 4 + 2 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v6 + 2 * a2)));
  v11 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(a1 - 4 + 4 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v6 + 4 * a2)));
  v12 = a1 - 4 + 8 * a2;
  v13 = &v6->m128i_i8[8 * a2];
  v14 = v11;
  v15 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(a1 - 4 + 6 * a2)), v9);
  v16 = _mm_unpacklo_epi16(v11, v15);
  v17 = _mm_unpackhi_epi16(v14, v15);
  v18 = _mm_unpacklo_epi16(v8, v10);
  v19 = _mm_unpackhi_epi16(v8, v10);
  v20 = _mm_unpackhi_epi32(v18, v16);
  v21 = _mm_unpackhi_epi32(v19, v17);
  v22 = _mm_unpacklo_epi32(v19, v17);
  v97[0] = _mm_unpacklo_epi32(v18, v16);
  v23 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)v12), _mm_loadl_epi64((const __m128i *)v13));
  v24 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(v12 + 2 * a2)),
          _mm_loadl_epi64((const __m128i *)&v13[2 * a2]));
  v25 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(v12 + 4 * a2)),
          _mm_loadl_epi64((const __m128i *)&v13[4 * a2]));
  v26 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(v12 + 6 * a2)),
          _mm_loadl_epi64((const __m128i *)&v13[6 * a2]));
  v27 = _mm_unpackhi_epi16(v25, v26);
  v28 = _mm_unpacklo_epi16(v25, v26);
  v29 = _mm_unpacklo_epi16(v23, v24);
  v30 = _mm_unpackhi_epi16(v23, v24);
  v31 = _mm_unpacklo_epi32(v29, v28);
  v32 = _mm_unpackhi_epi32(v29, v28);
  v33 = _mm_unpacklo_epi32(v30, v27);
  v34 = _mm_unpackhi_epi32(v30, v27);
  v35 = _mm_unpacklo_epi64(v21, v34);
  v36 = _mm_unpackhi_epi64(v21, v34);
  v98 = _mm_unpacklo_epi64(v20, v32);
  v99 = _mm_unpackhi_epi64(v20, v32);
  v100 = _mm_unpacklo_epi64(v22, v33);
  v101[0] = _mm_unpackhi_epi64(v22, v33);
  si128 = _mm_load_si128(v97);
  v38 = _mm_unpackhi_epi64(si128, v31);
  v39 = _mm_unpacklo_epi64(si128, v31);
  v40 = _mm_max_epu8(
          _mm_or_si128(_mm_subs_epu8(v38, v39), _mm_subs_epu8(v39, v38)),
          _mm_or_si128(_mm_subs_epu8(v36, v35), _mm_subs_epu8(v35, v36)));
  v41 = _mm_load_si128(&v98);
  v42 = _mm_max_epu8(
          _mm_max_epu8(v40, _mm_or_si128(_mm_subs_epu8(v35, v101[0]), _mm_subs_epu8(v101[0], v35))),
          _mm_or_si128(_mm_subs_epu8(v38, v41), _mm_subs_epu8(v41, v38)));
  v43 = v41;
  v44 = _mm_or_si128(_mm_subs_epu8(v41, v99), _mm_subs_epu8(v99, v41));
  v45 = _mm_load_si128(&v100);
  v46 = _mm_load_si128(v101);
  v47 = _mm_or_si128(_mm_subs_epu8(v46, v45), _mm_subs_epu8(v45, v46));
  v48 = _mm_subs_epu8(_mm_max_epu8(_mm_max_epu8(v42, v44), v47), *a4);
  v49 = _mm_srli_epi16(
          _mm_and_si128(_mm_or_si128(_mm_subs_epu8(v46, v43), _mm_subs_epu8(v43, v46)), (__m128i)xmmword_25D7000),
          1u);
  v50 = _mm_or_si128(_mm_subs_epu8(v99, v45), _mm_subs_epu8(v45, v99));
  v51 = _mm_load_si128(a5);
  v52 = _mm_cmpeq_epi8(
          _mm_or_si128(_mm_subs_epu8(_mm_adds_epu8(_mm_adds_epu8(v50, v50), v49), _mm_load_si128(a3)), v48),
          (__m128i)0LL);
  v53 = _mm_xor_si128(
          (__m128i)-1LL,
          _mm_cmpeq_epi8(_mm_or_si128(_mm_subs_epu8(v44, v51), _mm_subs_epu8(v47, v51)), v48));
  v54 = _mm_load_si128(xmmword_25D7010);
  v55 = _mm_xor_si128(_mm_load_si128(v101), v54);
  v56 = _mm_xor_si128(_mm_load_si128(&v99), v54);
  v57 = _mm_and_si128(_mm_subs_epi8(_mm_xor_si128(_mm_load_si128(&v98), v54), v55), v53);
  v58 = _mm_xor_si128(_mm_load_si128(&v100), v54);
  v59 = _mm_subs_epi8(v58, v56);
  v60 = _mm_and_si128(v52, _mm_adds_epi8(_mm_adds_epi8(_mm_adds_epi8(v57, v59), v59), v59));
  v61 = _mm_adds_epi8(v60, (__m128i)xmmword_25D7040);
  v62 = _mm_adds_epi8(v60, (__m128i)xmmword_25D7030);
  v63 = _mm_unpacklo_epi8(v59, v61);
  v64 = _mm_packs_epi16(
          _mm_srai_epi16(_mm_unpacklo_epi8(v62, v62), 0xBu),
          _mm_srai_epi16(_mm_unpackhi_epi8(v49, v62), 0xBu));
  v65 = _mm_srai_epi16(_mm_unpackhi_epi8(v61, v61), 0xBu);
  v66 = _mm_srai_epi16(v63, 0xBu);
  v67 = _mm_packs_epi16(v66, v65);
  v68 = _mm_adds_epi8(v56, v64);
  v69 = _mm_load_si128((const __m128i *)&xmmword_25D7050);
  v70 = _mm_packs_epi16(_mm_srai_epi16(_mm_adds_epi16(v66, v69), 1u), _mm_srai_epi16(_mm_adds_epi16(v65, v69), 1u));
  v71 = _mm_load_si128(xmmword_25D7010);
  v72 = _mm_andnot_si128(v53, v70);
  v73 = _mm_xor_si128(v68, v71);
  v74 = _mm_xor_si128(_mm_subs_epi8(v58, v67), v71);
  v75 = _mm_xor_si128(_mm_adds_epi8(_mm_xor_si128(_mm_load_si128(&v98), v71), v72), v71);
  v76 = _mm_xor_si128(_mm_subs_epi8(v55, v72), v71);
  v77 = _mm_unpacklo_epi8(v75, v73);
  v78 = _mm_unpackhi_epi8(v75, v73);
  v79 = _mm_unpacklo_epi8(v74, v76);
  v80 = _mm_unpackhi_epi8(v74, v76);
  v81 = v77;
  v82 = _mm_unpacklo_epi16(v77, v79);
  v83 = _mm_unpackhi_epi16(v81, v79);
  v84 = v78;
  v85 = _mm_unpacklo_epi16(v78, v80);
  v86 = _mm_unpackhi_epi16(v84, v80);
  *(_DWORD *)(v12 + 2) = _mm_cvtsi128_si32(v85);
  *(_DWORD *)(v12 + 4 * a2 + 2) = _mm_cvtsi128_si32(v86);
  v87 = _mm_srli_si128(v85, 4);
  v88 = _mm_srli_si128(v86, 4);
  *(_DWORD *)(v13 + 2) = _mm_cvtsi128_si32(v87);
  *(_DWORD *)&v13[4 * a2 + 2] = _mm_cvtsi128_si32(v88);
  v89 = _mm_srli_si128(v87, 4);
  v90 = _mm_srli_si128(v88, 4);
  *(_DWORD *)(v12 + 2 * a2 + 2) = _mm_cvtsi128_si32(v89);
  *(_DWORD *)(v12 + 2 * v7 + 2) = _mm_cvtsi128_si32(v90);
  *(_DWORD *)&v13[2 * a2 + 2] = v89.m128i_i32[1];
  *(_DWORD *)&v13[2 * v7 + 2] = v90.m128i_i32[1];
  v91 = a1 - 4;
  v92 = &v13[-8 * a2];
  *(_DWORD *)(v91 + 2) = _mm_cvtsi128_si32(v82);
  *(_DWORD *)(v91 + 4 * a2 + 2) = _mm_cvtsi128_si32(v83);
  v93 = _mm_srli_si128(v82, 4);
  v94 = _mm_srli_si128(v83, 4);
  *(_DWORD *)(v92 + 2) = _mm_cvtsi128_si32(v93);
  *(_DWORD *)&v92[4 * a2 + 2] = _mm_cvtsi128_si32(v94);
  v95 = _mm_srli_si128(v93, 4);
  v96 = _mm_srli_si128(v94, 4);
  *(_DWORD *)(v91 + 2 * a2 + 2) = _mm_cvtsi128_si32(v95);
  *(_DWORD *)(v91 + 2 * v7 + 2) = _mm_cvtsi128_si32(v96);
  *(_DWORD *)&v92[2 * a2 + 2] = v95.m128i_i32[1];
  *(_DWORD *)&v92[2 * v7 + 2] = v96.m128i_i32[1];
  return a2;
}

