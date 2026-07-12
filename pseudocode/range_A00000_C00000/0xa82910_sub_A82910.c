// Function: sub_A82910
// Address: 0xa82910
// Size: 0x558
// Prototype: 

int __cdecl sub_A82910(const __m128i *a1, int a2, int a3, int a4, __m128i *a5)
{
  __m128i si128; // xmm0
  __m128i v7; // xmm3
  __m128i v8; // xmm2
  __m128i v9; // xmm1
  __m128i v10; // xmm2
  __m128i v11; // xmm0
  __m128i v12; // xmm4
  __m128i v13; // xmm1
  __m128i v14; // xmm0
  __m128i v15; // xmm3
  const __m128i *v16; // esi
  int v17; // edi
  __m128i v18; // xmm2
  __m128i v19; // xmm5
  __m128i v20; // xmm2
  __m128i v21; // xmm0
  __m128i v22; // xmm4
  __m128i v23; // xmm1
  __m128i v24; // xmm0
  __m128i v25; // xmm3
  __m128i v26; // xmm2
  __m128i v27; // xmm5
  __m128i v28; // xmm2
  __m128i v29; // xmm0
  __m128i v30; // xmm4
  __m128i v31; // xmm1
  __m128i v32; // xmm0
  __m128i v33; // xmm3
  __m128i v34; // xmm5
  __m128i v35; // xmm3
  const __m128i *v36; // esi
  int v37; // edi
  __m128i v38; // xmm2
  __m128i v39; // xmm5
  __m128i v40; // xmm2
  __m128i v41; // xmm0
  __m128i v42; // xmm1
  __m128i v43; // xmm0
  __m128i v44; // xmm3
  __m128i v45; // xmm2
  __m128i v46; // xmm5
  __m128i v47; // xmm2
  __m128i v48; // xmm0
  __m128i v49; // xmm4
  __m128i v50; // xmm1
  __m128i v51; // xmm0
  __m128i v52; // xmm3
  __m128i v53; // xmm5
  __m128i v54; // xmm3
  const __m128i *v55; // esi
  int v56; // edi
  __m128i v57; // xmm2
  __m128i v58; // xmm5
  __m128i v59; // xmm2
  __m128i v60; // xmm0
  __m128i v61; // xmm1
  __m128i v62; // xmm0
  __m128i v63; // xmm3
  __m128i v64; // xmm2
  __m128i v65; // xmm5
  __m128i v66; // xmm2
  __m128i v67; // xmm0
  __m128i v68; // xmm4
  __m128i v69; // xmm1
  __m128i v70; // xmm0
  __m128i v71; // xmm3
  __m128i v72; // xmm5
  __m128i v73; // xmm3
  const __m128i *v74; // esi
  int v75; // edi
  __m128i v76; // xmm2
  __m128i v77; // xmm5
  __m128i v78; // xmm2
  __m128i v79; // xmm0
  __m128i v80; // xmm1
  __m128i v81; // xmm0
  __m128i v82; // xmm3
  __m128i v83; // xmm2
  __m128i v84; // xmm5
  __m128i v85; // xmm2
  __m128i v86; // xmm0
  __m128i v87; // xmm4
  __m128i v88; // xmm1
  __m128i v89; // xmm0
  __m128i v90; // xmm3
  __m128i v91; // xmm5
  __m128i v92; // xmm3
  const __m128i *v93; // esi
  int v94; // edi
  __m128i v95; // xmm2
  __m128i v96; // xmm5
  __m128i v97; // xmm2
  __m128i v98; // xmm0
  __m128i v99; // xmm1
  __m128i v100; // xmm0
  __m128i v101; // xmm3
  __m128i v102; // xmm2
  __m128i v103; // xmm5
  __m128i v104; // xmm2
  __m128i v105; // xmm0
  __m128i v106; // xmm4
  __m128i v107; // xmm1
  __m128i v108; // xmm0
  __m128i v109; // xmm3
  __m128i v110; // xmm5
  __m128i v111; // xmm3
  const __m128i *v112; // esi
  int v113; // edi
  __m128i v114; // xmm2
  __m128i v115; // xmm5
  __m128i v116; // xmm2
  __m128i v117; // xmm0
  __m128i v118; // xmm1
  __m128i v119; // xmm0
  __m128i v120; // xmm3
  __m128i v121; // xmm2
  __m128i v122; // xmm5
  __m128i v123; // xmm2
  __m128i v124; // xmm0
  __m128i v125; // xmm4
  __m128i v126; // xmm1
  __m128i v127; // xmm0
  __m128i v128; // xmm3
  __m128i v129; // xmm5
  __m128i v130; // xmm3
  const __m128i *v131; // esi
  int v132; // edi
  __m128i v133; // xmm2
  __m128i v134; // xmm5
  __m128i v135; // xmm2
  __m128i v136; // xmm0
  __m128i v137; // xmm1
  __m128i v138; // xmm0
  __m128i v139; // xmm3
  __m128i v140; // xmm2
  __m128i v141; // xmm5
  __m128i v142; // xmm2
  __m128i v143; // xmm0
  __m128i v144; // xmm4
  __m128i v145; // xmm1
  __m128i v146; // xmm0
  __m128i v147; // xmm3
  __m128i v148; // xmm2
  __m128i v149; // xmm5
  __m128i v150; // xmm2
  __m128i v151; // xmm0
  __m128i v152; // xmm4

  si128 = _mm_load_si128(a1);
  v7 = _mm_loadl_epi64((const __m128i *)(a3 + 8));
  v8 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)a3), v7);
  v9 = _mm_mpsadbw_epu8(v8, si128, 0);
  v10 = _mm_mpsadbw_epu8(v8, si128, 5);
  v11 = _mm_srli_si128(si128, 8);
  v12 = _mm_unpacklo_epi64(v7, _mm_loadl_epi64((const __m128i *)(a3 + 16)));
  v13 = _mm_add_epi16(
          _mm_add_epi16(_mm_add_epi16(v9, v10), _mm_mpsadbw_epu8(v12, v11, 0)),
          _mm_mpsadbw_epu8(v12, v11, 5));
  v14 = _mm_load_si128((const __m128i *)((char *)a1 + a2));
  v15 = _mm_loadl_epi64((const __m128i *)(a3 + a4 + 8));
  v16 = (const __m128i *)((char *)a1 + 2 * a2);
  v17 = a3 + 2 * a4;
  v18 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(a3 + a4)), v15);
  v19 = _mm_mpsadbw_epu8(v18, v14, 0);
  v20 = _mm_mpsadbw_epu8(v18, v14, 5);
  v21 = _mm_srli_si128(v14, 8);
  v22 = _mm_unpacklo_epi64(v15, _mm_loadl_epi64((const __m128i *)(a3 + a4 + 16)));
  v23 = _mm_add_epi16(
          v13,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v19, v20), _mm_mpsadbw_epu8(v22, v21, 0)),
            _mm_mpsadbw_epu8(v22, v21, 5)));
  v24 = _mm_load_si128(v16);
  v25 = _mm_loadl_epi64((const __m128i *)(v17 + 8));
  v26 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v17), v25);
  v27 = _mm_mpsadbw_epu8(v26, v24, 0);
  v28 = _mm_mpsadbw_epu8(v26, v24, 5);
  v29 = _mm_srli_si128(v24, 8);
  v30 = _mm_unpacklo_epi64(v25, _mm_loadl_epi64((const __m128i *)(v17 + 16)));
  v31 = _mm_add_epi16(
          v23,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v27, v28), _mm_mpsadbw_epu8(v30, v29, 0)),
            _mm_mpsadbw_epu8(v30, v29, 5)));
  v32 = _mm_load_si128((const __m128i *)((char *)v16 + a2));
  v33 = _mm_loadl_epi64((const __m128i *)(v17 + a4 + 8));
  v34 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(v17 + a4)), v33);
  v35 = _mm_unpacklo_epi64(v33, _mm_loadl_epi64((const __m128i *)(v17 + a4 + 16)));
  v36 = (const __m128i *)((char *)v16 + 2 * a2);
  v37 = v17 + 2 * a4;
  v38 = v34;
  v39 = _mm_mpsadbw_epu8(v34, v32, 0);
  v40 = _mm_mpsadbw_epu8(v38, v32, 5);
  v41 = _mm_srli_si128(v32, 8);
  v42 = _mm_add_epi16(
          v31,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v39, v40), _mm_mpsadbw_epu8(v35, v41, 0)),
            _mm_mpsadbw_epu8(v35, v41, 5)));
  v43 = _mm_load_si128(v36);
  v44 = _mm_loadl_epi64((const __m128i *)(v37 + 8));
  v45 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v37), v44);
  v46 = _mm_mpsadbw_epu8(v45, v43, 0);
  v47 = _mm_mpsadbw_epu8(v45, v43, 5);
  v48 = _mm_srli_si128(v43, 8);
  v49 = _mm_unpacklo_epi64(v44, _mm_loadl_epi64((const __m128i *)(v37 + 16)));
  v50 = _mm_add_epi16(
          v42,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v46, v47), _mm_mpsadbw_epu8(v49, v48, 0)),
            _mm_mpsadbw_epu8(v49, v48, 5)));
  v51 = _mm_load_si128((const __m128i *)((char *)v36 + a2));
  v52 = _mm_loadl_epi64((const __m128i *)(v37 + a4 + 8));
  v53 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(v37 + a4)), v52);
  v54 = _mm_unpacklo_epi64(v52, _mm_loadl_epi64((const __m128i *)(v37 + a4 + 16)));
  v55 = (const __m128i *)((char *)v36 + 2 * a2);
  v56 = v37 + 2 * a4;
  v57 = v53;
  v58 = _mm_mpsadbw_epu8(v53, v51, 0);
  v59 = _mm_mpsadbw_epu8(v57, v51, 5);
  v60 = _mm_srli_si128(v51, 8);
  v61 = _mm_add_epi16(
          v50,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v58, v59), _mm_mpsadbw_epu8(v54, v60, 0)),
            _mm_mpsadbw_epu8(v54, v60, 5)));
  v62 = _mm_load_si128(v55);
  v63 = _mm_loadl_epi64((const __m128i *)(v56 + 8));
  v64 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v56), v63);
  v65 = _mm_mpsadbw_epu8(v64, v62, 0);
  v66 = _mm_mpsadbw_epu8(v64, v62, 5);
  v67 = _mm_srli_si128(v62, 8);
  v68 = _mm_unpacklo_epi64(v63, _mm_loadl_epi64((const __m128i *)(v56 + 16)));
  v69 = _mm_add_epi16(
          v61,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v65, v66), _mm_mpsadbw_epu8(v68, v67, 0)),
            _mm_mpsadbw_epu8(v68, v67, 5)));
  v70 = _mm_load_si128((const __m128i *)((char *)v55 + a2));
  v71 = _mm_loadl_epi64((const __m128i *)(v56 + a4 + 8));
  v72 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(v56 + a4)), v71);
  v73 = _mm_unpacklo_epi64(v71, _mm_loadl_epi64((const __m128i *)(v56 + a4 + 16)));
  v74 = (const __m128i *)((char *)v55 + 2 * a2);
  v75 = v56 + 2 * a4;
  v76 = v72;
  v77 = _mm_mpsadbw_epu8(v72, v70, 0);
  v78 = _mm_mpsadbw_epu8(v76, v70, 5);
  v79 = _mm_srli_si128(v70, 8);
  v80 = _mm_add_epi16(
          v69,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v77, v78), _mm_mpsadbw_epu8(v73, v79, 0)),
            _mm_mpsadbw_epu8(v73, v79, 5)));
  v81 = _mm_load_si128(v74);
  v82 = _mm_loadl_epi64((const __m128i *)(v75 + 8));
  v83 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v75), v82);
  v84 = _mm_mpsadbw_epu8(v83, v81, 0);
  v85 = _mm_mpsadbw_epu8(v83, v81, 5);
  v86 = _mm_srli_si128(v81, 8);
  v87 = _mm_unpacklo_epi64(v82, _mm_loadl_epi64((const __m128i *)(v75 + 16)));
  v88 = _mm_add_epi16(
          v80,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v84, v85), _mm_mpsadbw_epu8(v87, v86, 0)),
            _mm_mpsadbw_epu8(v87, v86, 5)));
  v89 = _mm_load_si128((const __m128i *)((char *)v74 + a2));
  v90 = _mm_loadl_epi64((const __m128i *)(v75 + a4 + 8));
  v91 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(v75 + a4)), v90);
  v92 = _mm_unpacklo_epi64(v90, _mm_loadl_epi64((const __m128i *)(v75 + a4 + 16)));
  v93 = (const __m128i *)((char *)v74 + 2 * a2);
  v94 = v75 + 2 * a4;
  v95 = v91;
  v96 = _mm_mpsadbw_epu8(v91, v89, 0);
  v97 = _mm_mpsadbw_epu8(v95, v89, 5);
  v98 = _mm_srli_si128(v89, 8);
  v99 = _mm_add_epi16(
          v88,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v96, v97), _mm_mpsadbw_epu8(v92, v98, 0)),
            _mm_mpsadbw_epu8(v92, v98, 5)));
  v100 = _mm_load_si128(v93);
  v101 = _mm_loadl_epi64((const __m128i *)(v94 + 8));
  v102 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v94), v101);
  v103 = _mm_mpsadbw_epu8(v102, v100, 0);
  v104 = _mm_mpsadbw_epu8(v102, v100, 5);
  v105 = _mm_srli_si128(v100, 8);
  v106 = _mm_unpacklo_epi64(v101, _mm_loadl_epi64((const __m128i *)(v94 + 16)));
  v107 = _mm_add_epi16(
           v99,
           _mm_add_epi16(
             _mm_add_epi16(_mm_add_epi16(v103, v104), _mm_mpsadbw_epu8(v106, v105, 0)),
             _mm_mpsadbw_epu8(v106, v105, 5)));
  v108 = _mm_load_si128((const __m128i *)((char *)v93 + a2));
  v109 = _mm_loadl_epi64((const __m128i *)(v94 + a4 + 8));
  v110 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(v94 + a4)), v109);
  v111 = _mm_unpacklo_epi64(v109, _mm_loadl_epi64((const __m128i *)(v94 + a4 + 16)));
  v112 = (const __m128i *)((char *)v93 + 2 * a2);
  v113 = v94 + 2 * a4;
  v114 = v110;
  v115 = _mm_mpsadbw_epu8(v110, v108, 0);
  v116 = _mm_mpsadbw_epu8(v114, v108, 5);
  v117 = _mm_srli_si128(v108, 8);
  v118 = _mm_add_epi16(
           v107,
           _mm_add_epi16(
             _mm_add_epi16(_mm_add_epi16(v115, v116), _mm_mpsadbw_epu8(v111, v117, 0)),
             _mm_mpsadbw_epu8(v111, v117, 5)));
  v119 = _mm_load_si128(v112);
  v120 = _mm_loadl_epi64((const __m128i *)(v113 + 8));
  v121 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v113), v120);
  v122 = _mm_mpsadbw_epu8(v121, v119, 0);
  v123 = _mm_mpsadbw_epu8(v121, v119, 5);
  v124 = _mm_srli_si128(v119, 8);
  v125 = _mm_unpacklo_epi64(v120, _mm_loadl_epi64((const __m128i *)(v113 + 16)));
  v126 = _mm_add_epi16(
           v118,
           _mm_add_epi16(
             _mm_add_epi16(_mm_add_epi16(v122, v123), _mm_mpsadbw_epu8(v125, v124, 0)),
             _mm_mpsadbw_epu8(v125, v124, 5)));
  v127 = _mm_load_si128((const __m128i *)((char *)v112 + a2));
  v128 = _mm_loadl_epi64((const __m128i *)(v113 + a4 + 8));
  v129 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(v113 + a4)), v128);
  v130 = _mm_unpacklo_epi64(v128, _mm_loadl_epi64((const __m128i *)(v113 + a4 + 16)));
  v131 = (const __m128i *)((char *)v112 + 2 * a2);
  v132 = v113 + 2 * a4;
  v133 = v129;
  v134 = _mm_mpsadbw_epu8(v129, v127, 0);
  v135 = _mm_mpsadbw_epu8(v133, v127, 5);
  v136 = _mm_srli_si128(v127, 8);
  v137 = _mm_add_epi16(
           v126,
           _mm_add_epi16(
             _mm_add_epi16(_mm_add_epi16(v134, v135), _mm_mpsadbw_epu8(v130, v136, 0)),
             _mm_mpsadbw_epu8(v130, v136, 5)));
  v138 = _mm_load_si128(v131);
  v139 = _mm_loadl_epi64((const __m128i *)(v132 + 8));
  v140 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)v132), v139);
  v141 = _mm_mpsadbw_epu8(v140, v138, 0);
  v142 = _mm_mpsadbw_epu8(v140, v138, 5);
  v143 = _mm_srli_si128(v138, 8);
  v144 = _mm_unpacklo_epi64(v139, _mm_loadl_epi64((const __m128i *)(v132 + 16)));
  v145 = _mm_add_epi16(
           v137,
           _mm_add_epi16(
             _mm_add_epi16(_mm_add_epi16(v141, v142), _mm_mpsadbw_epu8(v144, v143, 0)),
             _mm_mpsadbw_epu8(v144, v143, 5)));
  v146 = _mm_load_si128((const __m128i *)((char *)v131 + a2));
  v147 = _mm_loadl_epi64((const __m128i *)(v132 + a4 + 8));
  v148 = _mm_unpacklo_epi64(_mm_loadl_epi64((const __m128i *)(v132 + a4)), v147);
  v149 = _mm_mpsadbw_epu8(v148, v146, 0);
  v150 = _mm_mpsadbw_epu8(v148, v146, 5);
  v151 = _mm_srli_si128(v146, 8);
  v152 = _mm_unpacklo_epi64(v147, _mm_loadl_epi64((const __m128i *)(v132 + a4 + 16)));
  *a5 = _mm_add_epi16(
          v145,
          _mm_add_epi16(
            _mm_add_epi16(_mm_add_epi16(v149, v150), _mm_mpsadbw_epu8(v152, v151, 0)),
            _mm_mpsadbw_epu8(v152, v151, 5)));
  return a2;
}

