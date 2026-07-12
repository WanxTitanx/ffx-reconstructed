// Function: sub_A801A8
// Address: 0xa801a8
// Size: 0x430
// Prototype: 

int __cdecl sub_A801A8(const __m128i *a1, int a2, const __m128i **a3, int a4)
{
  const __m128i *v4; // edx
  const __m128i *v5; // edi
  const __m128i *v7; // et0
  __m128i si128; // xmm0
  __m128i v9; // xmm4
  __m128i v10; // xmm5
  __m128i v11; // xmm6
  __m128i v12; // xmm7
  __m128i v13; // xmm0
  __m128i v14; // xmm4
  __m128i v15; // xmm1
  __m128i v16; // xmm5
  __m128i v17; // xmm6
  const __m128i *v18; // esi
  const __m128i *v19; // ecx
  const __m128i *v20; // edx
  const __m128i *v21; // ebx
  const __m128i *v22; // edi
  __m128i v23; // xmm7
  __m128i v24; // xmm0
  __m128i v25; // xmm4
  __m128i v26; // xmm5
  __m128i v27; // xmm6
  __m128i v28; // xmm7
  __m128i v29; // xmm0
  __m128i v30; // xmm4
  __m128i v31; // xmm1
  __m128i v32; // xmm5
  __m128i v33; // xmm6
  const __m128i *v34; // esi
  const __m128i *v35; // ecx
  const __m128i *v36; // edx
  const __m128i *v37; // ebx
  const __m128i *v38; // edi
  __m128i v39; // xmm7
  __m128i v40; // xmm0
  __m128i v41; // xmm4
  __m128i v42; // xmm5
  __m128i v43; // xmm6
  __m128i v44; // xmm7
  __m128i v45; // xmm0
  __m128i v46; // xmm4
  __m128i v47; // xmm1
  __m128i v48; // xmm5
  __m128i v49; // xmm6
  const __m128i *v50; // esi
  const __m128i *v51; // ecx
  const __m128i *v52; // edx
  const __m128i *v53; // ebx
  const __m128i *v54; // edi
  __m128i v55; // xmm7
  __m128i v56; // xmm0
  __m128i v57; // xmm4
  __m128i v58; // xmm5
  __m128i v59; // xmm6
  __m128i v60; // xmm7
  __m128i v61; // xmm0
  __m128i v62; // xmm4
  __m128i v63; // xmm1
  __m128i v64; // xmm5
  __m128i v65; // xmm6
  const __m128i *v66; // esi
  const __m128i *v67; // ecx
  const __m128i *v68; // edx
  const __m128i *v69; // ebx
  const __m128i *v70; // edi
  __m128i v71; // xmm7
  __m128i v72; // xmm0
  __m128i v73; // xmm4
  __m128i v74; // xmm5
  __m128i v75; // xmm6
  __m128i v76; // xmm7
  __m128i v77; // xmm0
  __m128i v78; // xmm4
  __m128i v79; // xmm1
  __m128i v80; // xmm5
  __m128i v81; // xmm6
  const __m128i *v82; // esi
  const __m128i *v83; // ecx
  const __m128i *v84; // edx
  const __m128i *v85; // ebx
  const __m128i *v86; // edi
  __m128i v87; // xmm7
  __m128i v88; // xmm0
  __m128i v89; // xmm4
  __m128i v90; // xmm5
  __m128i v91; // xmm6
  __m128i v92; // xmm7
  __m128i v93; // xmm0
  __m128i v94; // xmm4
  __m128i v95; // xmm1
  __m128i v96; // xmm5
  __m128i v97; // xmm6
  const __m128i *v98; // esi
  const __m128i *v99; // ecx
  const __m128i *v100; // edx
  const __m128i *v101; // ebx
  const __m128i *v102; // edi
  __m128i v103; // xmm7
  __m128i v104; // xmm0
  __m128i v105; // xmm4
  __m128i v106; // xmm5
  __m128i v107; // xmm6
  __m128i v108; // xmm7
  __m128i v109; // xmm0
  __m128i v110; // xmm4
  __m128i v111; // xmm1
  __m128i v112; // xmm5
  __m128i v113; // xmm6
  const __m128i *v114; // esi
  const __m128i *v115; // ecx
  const __m128i *v116; // edx
  const __m128i *v117; // ebx
  const __m128i *v118; // edi
  __m128i v119; // xmm7
  __m128i v120; // xmm0
  __m128i v121; // xmm4
  __m128i v122; // xmm5
  __m128i v123; // xmm6
  __m128i v124; // xmm7
  __m128i v125; // xmm0
  __m128i v126; // xmm4
  __m128i v127; // xmm5
  __m128i v128; // xmm6
  __m128i v129; // xmm7
  _DWORD *v130; // ecx
  int v131; // [esp+0h] [ebp-10h]

  v4 = a3[1];
  v5 = a3[3];
  v7 = a3[2];
  si128 = _mm_load_si128(a1);
  v9 = _mm_sad_epu8(_mm_lddqu_si128(*a3), si128);
  v10 = _mm_sad_epu8(_mm_lddqu_si128(v4), si128);
  v11 = _mm_sad_epu8(_mm_lddqu_si128(v7), si128);
  v12 = _mm_sad_epu8(_mm_lddqu_si128(v5), si128);
  v13 = _mm_load_si128((const __m128i *)((char *)a1 + a2));
  v14 = _mm_add_epi16(v9, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)*a3 + a4)), v13));
  v15 = _mm_lddqu_si128((const __m128i *)((char *)v5 + a4));
  v16 = _mm_add_epi16(v10, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v4 + a4)), v13));
  v17 = _mm_add_epi16(v11, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v7 + a4)), v13));
  v18 = (const __m128i *)((char *)a1 + 2 * a2);
  v19 = (const __m128i *)((char *)*a3 + 2 * a4);
  v20 = (const __m128i *)((char *)v4 + 2 * a4);
  v21 = (const __m128i *)((char *)v7 + 2 * a4);
  v22 = (const __m128i *)((char *)v5 + 2 * a4);
  v23 = _mm_add_epi16(v12, _mm_sad_epu8(v15, v13));
  v24 = _mm_load_si128(v18);
  v25 = _mm_add_epi16(v14, _mm_sad_epu8(_mm_lddqu_si128(v19), v24));
  v26 = _mm_add_epi16(v16, _mm_sad_epu8(_mm_lddqu_si128(v20), v24));
  v27 = _mm_add_epi16(v17, _mm_sad_epu8(_mm_lddqu_si128(v21), v24));
  v28 = _mm_add_epi16(v23, _mm_sad_epu8(_mm_lddqu_si128(v22), v24));
  v29 = _mm_load_si128((const __m128i *)((char *)v18 + a2));
  v30 = _mm_add_epi16(v25, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v19 + a4)), v29));
  v31 = _mm_lddqu_si128((const __m128i *)((char *)v22 + a4));
  v32 = _mm_add_epi16(v26, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v20 + a4)), v29));
  v33 = _mm_add_epi16(v27, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v21 + a4)), v29));
  v34 = (const __m128i *)((char *)v18 + 2 * a2);
  v35 = (const __m128i *)((char *)v19 + 2 * a4);
  v36 = (const __m128i *)((char *)v20 + 2 * a4);
  v37 = (const __m128i *)((char *)v21 + 2 * a4);
  v38 = (const __m128i *)((char *)v22 + 2 * a4);
  v39 = _mm_add_epi16(v28, _mm_sad_epu8(v31, v29));
  v40 = _mm_load_si128(v34);
  v41 = _mm_add_epi16(v30, _mm_sad_epu8(_mm_lddqu_si128(v35), v40));
  v42 = _mm_add_epi16(v32, _mm_sad_epu8(_mm_lddqu_si128(v36), v40));
  v43 = _mm_add_epi16(v33, _mm_sad_epu8(_mm_lddqu_si128(v37), v40));
  v44 = _mm_add_epi16(v39, _mm_sad_epu8(_mm_lddqu_si128(v38), v40));
  v45 = _mm_load_si128((const __m128i *)((char *)v34 + a2));
  v46 = _mm_add_epi16(v41, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v35 + a4)), v45));
  v47 = _mm_lddqu_si128((const __m128i *)((char *)v38 + a4));
  v48 = _mm_add_epi16(v42, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v36 + a4)), v45));
  v49 = _mm_add_epi16(v43, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v37 + a4)), v45));
  v50 = (const __m128i *)((char *)v34 + 2 * a2);
  v51 = (const __m128i *)((char *)v35 + 2 * a4);
  v52 = (const __m128i *)((char *)v36 + 2 * a4);
  v53 = (const __m128i *)((char *)v37 + 2 * a4);
  v54 = (const __m128i *)((char *)v38 + 2 * a4);
  v55 = _mm_add_epi16(v44, _mm_sad_epu8(v47, v45));
  v56 = _mm_load_si128(v50);
  v57 = _mm_add_epi16(v46, _mm_sad_epu8(_mm_lddqu_si128(v51), v56));
  v58 = _mm_add_epi16(v48, _mm_sad_epu8(_mm_lddqu_si128(v52), v56));
  v59 = _mm_add_epi16(v49, _mm_sad_epu8(_mm_lddqu_si128(v53), v56));
  v60 = _mm_add_epi16(v55, _mm_sad_epu8(_mm_lddqu_si128(v54), v56));
  v61 = _mm_load_si128((const __m128i *)((char *)v50 + a2));
  v62 = _mm_add_epi16(v57, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v51 + a4)), v61));
  v63 = _mm_lddqu_si128((const __m128i *)((char *)v54 + a4));
  v64 = _mm_add_epi16(v58, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v52 + a4)), v61));
  v65 = _mm_add_epi16(v59, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v53 + a4)), v61));
  v66 = (const __m128i *)((char *)v50 + 2 * a2);
  v67 = (const __m128i *)((char *)v51 + 2 * a4);
  v68 = (const __m128i *)((char *)v52 + 2 * a4);
  v69 = (const __m128i *)((char *)v53 + 2 * a4);
  v70 = (const __m128i *)((char *)v54 + 2 * a4);
  v71 = _mm_add_epi16(v60, _mm_sad_epu8(v63, v61));
  v72 = _mm_load_si128(v66);
  v73 = _mm_add_epi16(v62, _mm_sad_epu8(_mm_lddqu_si128(v67), v72));
  v74 = _mm_add_epi16(v64, _mm_sad_epu8(_mm_lddqu_si128(v68), v72));
  v75 = _mm_add_epi16(v65, _mm_sad_epu8(_mm_lddqu_si128(v69), v72));
  v76 = _mm_add_epi16(v71, _mm_sad_epu8(_mm_lddqu_si128(v70), v72));
  v77 = _mm_load_si128((const __m128i *)((char *)v66 + a2));
  v78 = _mm_add_epi16(v73, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v67 + a4)), v77));
  v79 = _mm_lddqu_si128((const __m128i *)((char *)v70 + a4));
  v80 = _mm_add_epi16(v74, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v68 + a4)), v77));
  v81 = _mm_add_epi16(v75, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v69 + a4)), v77));
  v82 = (const __m128i *)((char *)v66 + 2 * a2);
  v83 = (const __m128i *)((char *)v67 + 2 * a4);
  v84 = (const __m128i *)((char *)v68 + 2 * a4);
  v85 = (const __m128i *)((char *)v69 + 2 * a4);
  v86 = (const __m128i *)((char *)v70 + 2 * a4);
  v87 = _mm_add_epi16(v76, _mm_sad_epu8(v79, v77));
  v88 = _mm_load_si128(v82);
  v89 = _mm_add_epi16(v78, _mm_sad_epu8(_mm_lddqu_si128(v83), v88));
  v90 = _mm_add_epi16(v80, _mm_sad_epu8(_mm_lddqu_si128(v84), v88));
  v91 = _mm_add_epi16(v81, _mm_sad_epu8(_mm_lddqu_si128(v85), v88));
  v92 = _mm_add_epi16(v87, _mm_sad_epu8(_mm_lddqu_si128(v86), v88));
  v93 = _mm_load_si128((const __m128i *)((char *)v82 + a2));
  v94 = _mm_add_epi16(v89, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v83 + a4)), v93));
  v95 = _mm_lddqu_si128((const __m128i *)((char *)v86 + a4));
  v96 = _mm_add_epi16(v90, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v84 + a4)), v93));
  v97 = _mm_add_epi16(v91, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v85 + a4)), v93));
  v98 = (const __m128i *)((char *)v82 + 2 * a2);
  v99 = (const __m128i *)((char *)v83 + 2 * a4);
  v100 = (const __m128i *)((char *)v84 + 2 * a4);
  v101 = (const __m128i *)((char *)v85 + 2 * a4);
  v102 = (const __m128i *)((char *)v86 + 2 * a4);
  v103 = _mm_add_epi16(v92, _mm_sad_epu8(v95, v93));
  v104 = _mm_load_si128(v98);
  v105 = _mm_add_epi16(v94, _mm_sad_epu8(_mm_lddqu_si128(v99), v104));
  v106 = _mm_add_epi16(v96, _mm_sad_epu8(_mm_lddqu_si128(v100), v104));
  v107 = _mm_add_epi16(v97, _mm_sad_epu8(_mm_lddqu_si128(v101), v104));
  v108 = _mm_add_epi16(v103, _mm_sad_epu8(_mm_lddqu_si128(v102), v104));
  v109 = _mm_load_si128((const __m128i *)((char *)v98 + a2));
  v110 = _mm_add_epi16(v105, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v99 + a4)), v109));
  v111 = _mm_lddqu_si128((const __m128i *)((char *)v102 + a4));
  v112 = _mm_add_epi16(v106, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v100 + a4)), v109));
  v113 = _mm_add_epi16(v107, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v101 + a4)), v109));
  v114 = (const __m128i *)((char *)v98 + 2 * a2);
  v115 = (const __m128i *)((char *)v99 + 2 * a4);
  v116 = (const __m128i *)((char *)v100 + 2 * a4);
  v117 = (const __m128i *)((char *)v101 + 2 * a4);
  v118 = (const __m128i *)((char *)v102 + 2 * a4);
  v119 = _mm_add_epi16(v108, _mm_sad_epu8(v111, v109));
  v120 = _mm_load_si128(v114);
  v121 = _mm_add_epi16(v110, _mm_sad_epu8(_mm_lddqu_si128(v115), v120));
  v122 = _mm_add_epi16(v112, _mm_sad_epu8(_mm_lddqu_si128(v116), v120));
  v123 = _mm_add_epi16(v113, _mm_sad_epu8(_mm_lddqu_si128(v117), v120));
  v124 = _mm_add_epi16(v119, _mm_sad_epu8(_mm_lddqu_si128(v118), v120));
  v125 = _mm_load_si128((const __m128i *)((char *)v114 + a2));
  v126 = _mm_add_epi16(v121, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v115 + a4)), v125));
  v127 = _mm_add_epi16(v122, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v116 + a4)), v125));
  v128 = _mm_add_epi16(v123, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v117 + a4)), v125));
  v129 = _mm_add_epi16(v124, _mm_sad_epu8(_mm_lddqu_si128((const __m128i *)((char *)v118 + a4)), v125));
  v130 = *(_DWORD **)(v131 + 24);
  *v130 = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v126), _mm_srli_si128(v126, 8)));
  v130[1] = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v127), _mm_srli_si128(v127, 8)));
  v130[2] = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v128), _mm_srli_si128(v128, 8)));
  v130[3] = _mm_cvtsi128_si32(_mm_add_epi16(_mm_move_epi64(v129), _mm_srli_si128(v129, 8)));
  return a2;
}

