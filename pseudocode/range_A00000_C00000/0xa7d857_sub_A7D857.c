// Function: sub_A7D857
// Address: 0xa7d857
// Size: 0x413
// Prototype: 

int __cdecl sub_A7D857(int a1, int a2, const __m128i *a3, __m128i *a4, const __m128i *a5, int a6)
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
  int v16; // esi
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
  __m128i v34; // xmm6
  __m128i v35; // xmm7
  __m128i si128; // xmm2
  __m128i v37; // xmm1
  __m128i v38; // xmm2
  __m128i v39; // xmm0
  __m128i v40; // xmm2
  __m128i v41; // xmm0
  __m128i v42; // xmm1
  __m128i v43; // xmm2
  __m128i v44; // xmm6
  __m128i v45; // xmm4
  __m128i v46; // xmm7
  __m128i v47; // xmm0
  __m128i v48; // xmm5
  __m128i v49; // xmm1
  __m128i v50; // xmm3
  __m128i v51; // xmm1
  __m128i v52; // xmm4
  __m128i v53; // xmm3
  __m128i v54; // xmm7
  __m128i v55; // xmm6
  __m128i v56; // xmm2
  __m128i v57; // xmm3
  __m128i v58; // xmm0
  __m128i v59; // xmm2
  __m128i v60; // xmm1
  __m128i v61; // xmm2
  __m128i v62; // xmm0
  __m128i v63; // xmm2
  __m128i v64; // xmm1
  __m128i v65; // xmm5
  __m128i v66; // xmm0
  __m128i v67; // xmm6
  __m128i v68; // xmm2
  __m128i v69; // xmm5
  __m128i v70; // xmm2
  __m128i v71; // xmm4
  __m128i v72; // xmm6
  __m128i v73; // xmm3
  __m128i v74; // xmm1
  __m128i v75; // xmm7
  __m128i v76; // xmm2
  __m128i v77; // xmm1
  __m128i v78; // xmm4
  __m128i v79; // xmm3
  __m128i v80; // xmm6
  __m128i v81; // xmm2
  __m128i v82; // xmm6
  __m128i v83; // xmm5
  __m128i v84; // xmm1
  __m128i v85; // xmm5
  int v86; // edi
  __m128i v87; // xmm1
  __m128i v88; // xmm5
  __m128i v89; // xmm1
  __m128i v90; // xmm5
  int v91; // esi
  int v92; // edi
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
  v16 = a6 - 4;
  v17 = _mm_unpacklo_epi16(v9, v10);
  v18 = _mm_unpackhi_epi16(v9, v10);
  v19 = _mm_unpackhi_epi32(v17, v13);
  v20 = _mm_unpackhi_epi32(v18, v14);
  v21 = _mm_unpacklo_epi32(v18, v14);
  v97[0] = _mm_unpacklo_epi32(v17, v13);
  v22 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(a6 - 4)), _mm_loadl_epi64(v15));
  v23 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(a6 - 4 + 2 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v15 + 2 * a2)));
  v24 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(a6 - 4 + 4 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v15 + 4 * a2)));
  v25 = _mm_unpacklo_epi8(
          _mm_loadl_epi64((const __m128i *)(a6 - 4 + 6 * a2)),
          _mm_loadl_epi64((const __m128i *)((char *)v15 + 6 * a2)));
  v26 = _mm_unpackhi_epi16(v24, v25);
  v27 = _mm_unpacklo_epi16(v24, v25);
  v28 = _mm_unpacklo_epi16(v22, v23);
  v29 = _mm_unpackhi_epi16(v22, v23);
  v30 = _mm_unpacklo_epi32(v28, v27);
  v31 = _mm_unpackhi_epi32(v28, v27);
  v32 = _mm_unpacklo_epi32(v29, v26);
  v33 = _mm_unpackhi_epi32(v29, v26);
  v34 = _mm_unpacklo_epi64(v20, v33);
  v35 = _mm_unpackhi_epi64(v20, v33);
  v98 = _mm_unpacklo_epi64(v19, v31);
  v99 = _mm_unpackhi_epi64(v19, v31);
  v100 = _mm_unpacklo_epi64(v21, v32);
  v101[0] = _mm_unpackhi_epi64(v21, v32);
  si128 = _mm_load_si128(v97);
  v37 = _mm_unpackhi_epi64(si128, v30);
  v38 = _mm_unpacklo_epi64(si128, v30);
  v39 = _mm_max_epu8(
          _mm_or_si128(_mm_subs_epu8(v37, v38), _mm_subs_epu8(v38, v37)),
          _mm_or_si128(_mm_subs_epu8(v35, v34), _mm_subs_epu8(v34, v35)));
  v40 = _mm_load_si128(&v98);
  v41 = _mm_max_epu8(
          _mm_max_epu8(v39, _mm_or_si128(_mm_subs_epu8(v34, v101[0]), _mm_subs_epu8(v101[0], v34))),
          _mm_or_si128(_mm_subs_epu8(v37, v40), _mm_subs_epu8(v40, v37)));
  v42 = v40;
  v43 = _mm_or_si128(_mm_subs_epu8(v40, v99), _mm_subs_epu8(v99, v40));
  v44 = _mm_load_si128(&v100);
  v45 = _mm_load_si128(v101);
  v46 = _mm_or_si128(_mm_subs_epu8(v45, v44), _mm_subs_epu8(v44, v45));
  v47 = _mm_subs_epu8(_mm_max_epu8(_mm_max_epu8(v41, v43), v46), *a4);
  v48 = _mm_srli_epi16(
          _mm_and_si128(_mm_or_si128(_mm_subs_epu8(v45, v42), _mm_subs_epu8(v42, v45)), (__m128i)xmmword_25D7000),
          1u);
  v49 = _mm_or_si128(_mm_subs_epu8(v99, v44), _mm_subs_epu8(v44, v99));
  v50 = _mm_load_si128(a5);
  v51 = _mm_cmpeq_epi8(
          _mm_or_si128(_mm_subs_epu8(_mm_adds_epu8(_mm_adds_epu8(v49, v49), v48), _mm_load_si128(a3)), v47),
          (__m128i)0LL);
  v52 = _mm_xor_si128(
          (__m128i)-1LL,
          _mm_cmpeq_epi8(_mm_or_si128(_mm_subs_epu8(v43, v50), _mm_subs_epu8(v46, v50)), v47));
  v53 = _mm_load_si128(xmmword_25D7010);
  v54 = _mm_xor_si128(_mm_load_si128(v101), v53);
  v55 = _mm_xor_si128(_mm_load_si128(&v99), v53);
  v56 = _mm_and_si128(_mm_subs_epi8(_mm_xor_si128(_mm_load_si128(&v98), v53), v54), v52);
  v57 = _mm_xor_si128(_mm_load_si128(&v100), v53);
  v58 = _mm_subs_epi8(v57, v55);
  v59 = _mm_and_si128(v51, _mm_adds_epi8(_mm_adds_epi8(_mm_adds_epi8(v56, v58), v58), v58));
  v60 = _mm_adds_epi8(v59, (__m128i)xmmword_25D7040);
  v61 = _mm_adds_epi8(v59, (__m128i)xmmword_25D7030);
  v62 = _mm_unpacklo_epi8(v58, v60);
  v63 = _mm_packs_epi16(
          _mm_srai_epi16(_mm_unpacklo_epi8(v61, v61), 0xBu),
          _mm_srai_epi16(_mm_unpackhi_epi8(v48, v61), 0xBu));
  v64 = _mm_srai_epi16(_mm_unpackhi_epi8(v60, v60), 0xBu);
  v65 = _mm_srai_epi16(v62, 0xBu);
  v66 = _mm_packs_epi16(v65, v64);
  v67 = _mm_adds_epi8(v55, v63);
  v68 = _mm_load_si128((const __m128i *)&xmmword_25D7050);
  v69 = _mm_packs_epi16(_mm_srai_epi16(_mm_adds_epi16(v65, v68), 1u), _mm_srai_epi16(_mm_adds_epi16(v64, v68), 1u));
  v70 = _mm_load_si128(xmmword_25D7010);
  v71 = _mm_andnot_si128(v52, v69);
  v72 = _mm_xor_si128(v67, v70);
  v73 = _mm_xor_si128(_mm_subs_epi8(v57, v66), v70);
  v74 = _mm_xor_si128(_mm_adds_epi8(_mm_xor_si128(_mm_load_si128(&v98), v70), v71), v70);
  v75 = _mm_xor_si128(_mm_subs_epi8(v54, v71), v70);
  v76 = _mm_unpacklo_epi8(v74, v72);
  v77 = _mm_unpackhi_epi8(v74, v72);
  v78 = _mm_unpacklo_epi8(v73, v75);
  v79 = _mm_unpackhi_epi8(v73, v75);
  v80 = v76;
  v81 = _mm_unpacklo_epi16(v76, v78);
  v82 = _mm_unpackhi_epi16(v80, v78);
  v83 = v77;
  v84 = _mm_unpacklo_epi16(v77, v79);
  v85 = _mm_unpackhi_epi16(v83, v79);
  v86 = a6 - 4 + a2;
  *(_DWORD *)(v16 + 2) = _mm_cvtsi128_si32(v84);
  *(_DWORD *)(v16 + 4 * a2 + 2) = _mm_cvtsi128_si32(v85);
  v87 = _mm_srli_si128(v84, 4);
  v88 = _mm_srli_si128(v85, 4);
  *(_DWORD *)(v86 + 2) = _mm_cvtsi128_si32(v87);
  *(_DWORD *)(v86 + 4 * a2 + 2) = _mm_cvtsi128_si32(v88);
  v89 = _mm_srli_si128(v87, 4);
  v90 = _mm_srli_si128(v88, 4);
  *(_DWORD *)(v16 + 2 * a2 + 2) = _mm_cvtsi128_si32(v89);
  *(_DWORD *)(v16 + 2 * v8 + 2) = _mm_cvtsi128_si32(v90);
  *(_DWORD *)(v86 + 2 * a2 + 2) = v89.m128i_i32[1];
  *(_DWORD *)(v86 + 2 * v8 + 2) = v90.m128i_i32[1];
  v91 = a1 - 4;
  v92 = a1 - 4 + a2;
  *(_DWORD *)(v91 + 2) = _mm_cvtsi128_si32(v81);
  *(_DWORD *)(v91 + 4 * a2 + 2) = _mm_cvtsi128_si32(v82);
  v93 = _mm_srli_si128(v81, 4);
  v94 = _mm_srli_si128(v82, 4);
  *(_DWORD *)(v92 + 2) = _mm_cvtsi128_si32(v93);
  *(_DWORD *)(v92 + 4 * a2 + 2) = _mm_cvtsi128_si32(v94);
  v95 = _mm_srli_si128(v93, 4);
  v96 = _mm_srli_si128(v94, 4);
  *(_DWORD *)(v91 + 2 * a2 + 2) = _mm_cvtsi128_si32(v95);
  *(_DWORD *)(v91 + 2 * v8 + 2) = _mm_cvtsi128_si32(v96);
  *(_DWORD *)(v92 + 2 * a2 + 2) = v95.m128i_i32[1];
  *(_DWORD *)(v92 + 2 * v8 + 2) = v96.m128i_i32[1];
  return a2;
}

