// Function: sub_A7F760
// Address: 0xa7f760
// Size: 0x32d
// Prototype: 

int __cdecl sub_A7F760(const __m128i *a1, int a2, int a3, int a4, _DWORD *a5)
{
  __m128i si128; // xmm0
  __m128i v7; // xmm5
  __m128i v8; // xmm6
  __m128i v9; // xmm7
  __m128i v10; // xmm0
  const __m128i *v11; // esi
  int v12; // edi
  __m128i v13; // xmm5
  __m128i v14; // xmm6
  __m128i v15; // xmm7
  __m128i v16; // xmm0
  __m128i v17; // xmm5
  __m128i v18; // xmm6
  __m128i v19; // xmm7
  __m128i v20; // xmm0
  __m128i v21; // xmm1
  __m128i v22; // xmm2
  __m128i v23; // xmm3
  const __m128i *v24; // esi
  int v25; // edi
  __m128i v26; // xmm5
  __m128i v27; // xmm6
  __m128i v28; // xmm7
  __m128i v29; // xmm0
  __m128i v30; // xmm5
  __m128i v31; // xmm6
  __m128i v32; // xmm7
  __m128i v33; // xmm0
  __m128i v34; // xmm1
  __m128i v35; // xmm2
  __m128i v36; // xmm3
  const __m128i *v37; // esi
  int v38; // edi
  __m128i v39; // xmm5
  __m128i v40; // xmm6
  __m128i v41; // xmm7
  __m128i v42; // xmm0
  __m128i v43; // xmm5
  __m128i v44; // xmm6
  __m128i v45; // xmm7
  __m128i v46; // xmm0
  __m128i v47; // xmm1
  __m128i v48; // xmm2
  __m128i v49; // xmm3
  const __m128i *v50; // esi
  int v51; // edi
  __m128i v52; // xmm5
  __m128i v53; // xmm6
  __m128i v54; // xmm7
  __m128i v55; // xmm0
  __m128i v56; // xmm5
  __m128i v57; // xmm6
  __m128i v58; // xmm7
  __m128i v59; // xmm0
  __m128i v60; // xmm1
  __m128i v61; // xmm2
  __m128i v62; // xmm3
  const __m128i *v63; // esi
  int v64; // edi
  __m128i v65; // xmm5
  __m128i v66; // xmm6
  __m128i v67; // xmm7
  __m128i v68; // xmm0
  __m128i v69; // xmm5
  __m128i v70; // xmm6
  __m128i v71; // xmm7
  __m128i v72; // xmm0
  __m128i v73; // xmm1
  __m128i v74; // xmm2
  __m128i v75; // xmm3
  const __m128i *v76; // esi
  int v77; // edi
  __m128i v78; // xmm5
  __m128i v79; // xmm6
  __m128i v80; // xmm7
  __m128i v81; // xmm0
  __m128i v82; // xmm5
  __m128i v83; // xmm6
  __m128i v84; // xmm7
  __m128i v85; // xmm0
  __m128i v86; // xmm1
  __m128i v87; // xmm2
  __m128i v88; // xmm3
  const __m128i *v89; // esi
  int v90; // edi
  __m128i v91; // xmm5
  __m128i v92; // xmm6
  __m128i v93; // xmm7
  __m128i v94; // xmm0
  __m128i v95; // xmm5
  __m128i v96; // xmm6
  __m128i v97; // xmm7
  __m128i v98; // xmm0
  __m128i v99; // xmm5
  __m128i v100; // xmm6
  __m128i v101; // xmm7

  si128 = _mm_load_si128(a1);
  v7 = _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)a3), si128);
  v8 = _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(a3 + 1)), si128);
  v9 = _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(a3 + 2)), si128);
  v10 = _mm_load_si128((const __m128i *)((char *)a1 + a2));
  v11 = (const __m128i *)((char *)a1 + 2 * a2);
  v12 = a3 + 2 * a4;
  v13 = _mm_add_epi16(v7, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(a3 + a4)), v10));
  v14 = _mm_add_epi16(v8, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(a3 + a4 + 1)), v10));
  v15 = _mm_add_epi16(v9, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(a3 + a4 + 2)), v10));
  v16 = _mm_load_si128(v11);
  v17 = _mm_add_epi16(v13, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)v12), v16));
  v18 = _mm_add_epi16(v14, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v12 + 1)), v16));
  v19 = _mm_add_epi16(v15, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v12 + 2)), v16));
  v20 = _mm_load_si128((const __m128i *)((char *)v11 + a2));
  v21 = _mm_lddqu_si128((const __m128i *)(v12 + a4));
  v22 = _mm_lddqu_si128((const __m128i *)(v12 + a4 + 1));
  v23 = _mm_lddqu_si128((const __m128i *)(v12 + a4 + 2));
  v24 = (const __m128i *)((char *)v11 + 2 * a2);
  v25 = v12 + 2 * a4;
  v26 = _mm_add_epi16(v17, _mm_sad_epu8(v21, v20));
  v27 = _mm_add_epi16(v18, _mm_sad_epu8(v22, v20));
  v28 = _mm_add_epi16(v19, _mm_sad_epu8(v23, v20));
  v29 = _mm_load_si128(v24);
  v30 = _mm_add_epi16(v26, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)v25), v29));
  v31 = _mm_add_epi16(v27, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v25 + 1)), v29));
  v32 = _mm_add_epi16(v28, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v25 + 2)), v29));
  v33 = _mm_load_si128((const __m128i *)((char *)v24 + a2));
  v34 = _mm_lddqu_si128((const __m128i *)(v25 + a4));
  v35 = _mm_lddqu_si128((const __m128i *)(v25 + a4 + 1));
  v36 = _mm_lddqu_si128((const __m128i *)(v25 + a4 + 2));
  v37 = (const __m128i *)((char *)v24 + 2 * a2);
  v38 = v25 + 2 * a4;
  v39 = _mm_add_epi16(v30, _mm_sad_epu8(v34, v33));
  v40 = _mm_add_epi16(v31, _mm_sad_epu8(v35, v33));
  v41 = _mm_add_epi16(v32, _mm_sad_epu8(v36, v33));
  v42 = _mm_load_si128(v37);
  v43 = _mm_add_epi16(v39, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)v38), v42));
  v44 = _mm_add_epi16(v40, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v38 + 1)), v42));
  v45 = _mm_add_epi16(v41, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v38 + 2)), v42));
  v46 = _mm_load_si128((const __m128i *)((char *)v37 + a2));
  v47 = _mm_lddqu_si128((const __m128i *)(v38 + a4));
  v48 = _mm_lddqu_si128((const __m128i *)(v38 + a4 + 1));
  v49 = _mm_lddqu_si128((const __m128i *)(v38 + a4 + 2));
  v50 = (const __m128i *)((char *)v37 + 2 * a2);
  v51 = v38 + 2 * a4;
  v52 = _mm_add_epi16(v43, _mm_sad_epu8(v47, v46));
  v53 = _mm_add_epi16(v44, _mm_sad_epu8(v48, v46));
  v54 = _mm_add_epi16(v45, _mm_sad_epu8(v49, v46));
  v55 = _mm_load_si128(v50);
  v56 = _mm_add_epi16(v52, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)v51), v55));
  v57 = _mm_add_epi16(v53, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v51 + 1)), v55));
  v58 = _mm_add_epi16(v54, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v51 + 2)), v55));
  v59 = _mm_load_si128((const __m128i *)((char *)v50 + a2));
  v60 = _mm_lddqu_si128((const __m128i *)(v51 + a4));
  v61 = _mm_lddqu_si128((const __m128i *)(v51 + a4 + 1));
  v62 = _mm_lddqu_si128((const __m128i *)(v51 + a4 + 2));
  v63 = (const __m128i *)((char *)v50 + 2 * a2);
  v64 = v51 + 2 * a4;
  v65 = _mm_add_epi16(v56, _mm_sad_epu8(v60, v59));
  v66 = _mm_add_epi16(v57, _mm_sad_epu8(v61, v59));
  v67 = _mm_add_epi16(v58, _mm_sad_epu8(v62, v59));
  v68 = _mm_load_si128(v63);
  v69 = _mm_add_epi16(v65, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)v64), v68));
  v70 = _mm_add_epi16(v66, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v64 + 1)), v68));
  v71 = _mm_add_epi16(v67, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v64 + 2)), v68));
  v72 = _mm_load_si128((const __m128i *)((char *)v63 + a2));
  v73 = _mm_lddqu_si128((const __m128i *)(v64 + a4));
  v74 = _mm_lddqu_si128((const __m128i *)(v64 + a4 + 1));
  v75 = _mm_lddqu_si128((const __m128i *)(v64 + a4 + 2));
  v76 = (const __m128i *)((char *)v63 + 2 * a2);
  v77 = v64 + 2 * a4;
  v78 = _mm_add_epi16(v69, _mm_sad_epu8(v73, v72));
  v79 = _mm_add_epi16(v70, _mm_sad_epu8(v74, v72));
  v80 = _mm_add_epi16(v71, _mm_sad_epu8(v75, v72));
  v81 = _mm_load_si128(v76);
  v82 = _mm_add_epi16(v78, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)v77), v81));
  v83 = _mm_add_epi16(v79, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v77 + 1)), v81));
  v84 = _mm_add_epi16(v80, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v77 + 2)), v81));
  v85 = _mm_load_si128((const __m128i *)((char *)v76 + a2));
  v86 = _mm_lddqu_si128((const __m128i *)(v77 + a4));
  v87 = _mm_lddqu_si128((const __m128i *)(v77 + a4 + 1));
  v88 = _mm_lddqu_si128((const __m128i *)(v77 + a4 + 2));
  v89 = (const __m128i *)((char *)v76 + 2 * a2);
  v90 = v77 + 2 * a4;
  v91 = _mm_add_epi16(v82, _mm_sad_epu8(v86, v85));
  v92 = _mm_add_epi16(v83, _mm_sad_epu8(v87, v85));
  v93 = _mm_add_epi16(v84, _mm_sad_epu8(v88, v85));
  v94 = _mm_load_si128(v89);
  v95 = _mm_add_epi16(v91, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)v90), v94));
  v96 = _mm_add_epi16(v92, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v90 + 1)), v94));
  v97 = _mm_add_epi16(v93, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v90 + 2)), v94));
  v98 = _mm_load_si128((const __m128i *)((char *)v89 + a2));
  v99 = _mm_add_epi16(v95, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v90 + a4)), v98));
  v100 = _mm_add_epi16(v96, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v90 + a4 + 1)), v98));
  v101 = _mm_add_epi16(v97, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)(v90 + a4 + 2)), v98));
  *a5 = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v99), _mm_srli_si128(v99, 8)));
  a5[1] = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v100), _mm_srli_si128(v100, 8)));
  a5[2] = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v101), _mm_srli_si128(v101, 8)));
  return a2;
}

