// Function: sub_9BFD90
// Address: 0x9bfd90
float *__userpurge sub_9BFD90@<eax>(
        int a1@<ebp>,
        int a2,
        float a3,
        int a4,
        int a5,
        int a6,
        int a7,
        float *a8,
        float *a9,
        int a10,
        int a11)
{
  float v11; // edx
  double v12; // st7
  bool v13; // zf
  double v14; // st7
  int v15; // edi
  double v16; // st7
  double v17; // st7
  double v18; // st5
  double v19; // st4
  float *v20; // edx
  double v21; // st7
  float *v22; // eax
  double v23; // st7
  double v24; // st5
  float *v25; // eax
  double v26; // st7
  double v27; // st6
  float v28; // xmm0_4
  double v29; // st7
  double v30; // st6
  double v31; // st7
  double v32; // st5
  double v33; // st4
  double v34; // st6
  double v35; // st2
  double v36; // st4
  double v37; // st3
  double v38; // st5
  float v39; // xmm0_4
  double v40; // st7
  double v41; // st7
  double v42; // st5
  double v43; // st4
  double v44; // st6
  double v45; // st2
  double v46; // st6
  double v47; // st3
  double v48; // st7
  float *v49; // ecx
  __m128 *v50; // ecx
  float v51; // eax
  double v52; // st7
  double v53; // st7
  int v54; // edx
  float v55; // ecx
  double v56; // st7
  float v57; // xmm0_4
  double v58; // st6
  double v59; // st7
  double v60; // st6
  double v61; // st7
  double v62; // st7
  float v63; // xmm0_4
  float v64; // xmm0_4
  double v65; // st7
  float v66; // xmm0_4
  double v67; // st7
  double v68; // st7
  float *v69; // ecx
  float *v70; // eax
  double v71; // st7
  double v72; // st6
  double v73; // st7
  double v74; // st6
  double v75; // st7
  float *v76; // ecx
  float *result; // eax
  double v78; // st5
  double v79; // st3
  double v80; // st7
  double v81; // st7
  int v82; // [esp-2D0h] [ebp-2DCh] BYREF
  int v83; // [esp-2C0h] [ebp-2CCh] BYREF
  _DWORD v84[4]; // [esp-2B0h] [ebp-2BCh] BYREF
  float v85[4]; // [esp-2A0h] [ebp-2ACh] BYREF
  _BYTE v86[16]; // [esp-290h] [ebp-29Ch] BYREF
  _BYTE v87[16]; // [esp-280h] [ebp-28Ch] BYREF
  _BYTE v88[16]; // [esp-270h] [ebp-27Ch] BYREF
  _DWORD v89[4]; // [esp-260h] [ebp-26Ch] BYREF
  _DWORD v90[4]; // [esp-250h] [ebp-25Ch] BYREF
  _BYTE v91[16]; // [esp-240h] [ebp-24Ch] BYREF
  _DWORD v92[4]; // [esp-230h] [ebp-23Ch] BYREF
  _BYTE v93[16]; // [esp-220h] [ebp-22Ch] BYREF
  _BYTE v94[16]; // [esp-210h] [ebp-21Ch] BYREF
  _BYTE v95[16]; // [esp-200h] [ebp-20Ch] BYREF
  float v96[4]; // [esp-1F0h] [ebp-1FCh] BYREF
  float v97; // [esp-1E0h] [ebp-1ECh]
  float v98; // [esp-1DCh] [ebp-1E8h]
  float v99; // [esp-1D8h] [ebp-1E4h]
  float v100; // [esp-1D0h] [ebp-1DCh]
  float v101; // [esp-1CCh] [ebp-1D8h]
  float v102; // [esp-1C8h] [ebp-1D4h]
  float v103; // [esp-1C0h] [ebp-1CCh]
  float v104; // [esp-1BCh] [ebp-1C8h]
  float v105; // [esp-1B8h] [ebp-1C4h]
  float v106; // [esp-1B0h] [ebp-1BCh]
  float v107; // [esp-1ACh] [ebp-1B8h]
  float v108; // [esp-1A8h] [ebp-1B4h]
  float v109; // [esp-1A0h] [ebp-1ACh]
  float v110; // [esp-19Ch] [ebp-1A8h]
  float v111; // [esp-198h] [ebp-1A4h]
  float v112; // [esp-190h] [ebp-19Ch]
  float v113; // [esp-18Ch] [ebp-198h]
  float v114; // [esp-188h] [ebp-194h]
  float v115; // [esp-180h] [ebp-18Ch]
  float v116; // [esp-17Ch] [ebp-188h]
  float v117; // [esp-178h] [ebp-184h]
  float v118; // [esp-170h] [ebp-17Ch]
  float v119; // [esp-16Ch] [ebp-178h]
  float v120; // [esp-168h] [ebp-174h]
  float v121; // [esp-160h] [ebp-16Ch]
  float v122; // [esp-15Ch] [ebp-168h]
  float v123; // [esp-158h] [ebp-164h]
  float v124; // [esp-150h] [ebp-15Ch]
  float v125; // [esp-14Ch] [ebp-158h]
  float v126; // [esp-148h] [ebp-154h]
  float v127; // [esp-140h] [ebp-14Ch]
  float v128; // [esp-13Ch] [ebp-148h]
  float v129; // [esp-138h] [ebp-144h]
  float v130; // [esp-130h] [ebp-13Ch]
  float v131; // [esp-12Ch] [ebp-138h]
  float v132; // [esp-128h] [ebp-134h]
  float v133; // [esp-120h] [ebp-12Ch]
  float v134; // [esp-11Ch] [ebp-128h]
  float v135; // [esp-118h] [ebp-124h]
  float v136; // [esp-110h] [ebp-11Ch]
  float v137; // [esp-10Ch] [ebp-118h]
  float v138; // [esp-108h] [ebp-114h]
  float v139; // [esp-100h] [ebp-10Ch]
  float v140; // [esp-FCh] [ebp-108h]
  float v141; // [esp-F8h] [ebp-104h]
  float v142; // [esp-F0h] [ebp-FCh]
  float v143; // [esp-ECh] [ebp-F8h]
  float v144; // [esp-E8h] [ebp-F4h]
  float v145; // [esp-E0h] [ebp-ECh]
  float v146; // [esp-DCh] [ebp-E8h]
  float v147; // [esp-D8h] [ebp-E4h]
  float v148; // [esp-D0h] [ebp-DCh]
  float v149; // [esp-CCh] [ebp-D8h]
  float v150; // [esp-C8h] [ebp-D4h]
  float v151; // [esp-C0h] [ebp-CCh]
  float v152; // [esp-BCh] [ebp-C8h]
  float v153; // [esp-B8h] [ebp-C4h]
  float v154; // [esp-B0h] [ebp-BCh]
  float v155; // [esp-ACh] [ebp-B8h]
  float v156; // [esp-A8h] [ebp-B4h]
  float v157; // [esp-A0h] [ebp-ACh]
  float v158; // [esp-9Ch] [ebp-A8h]
  float v159; // [esp-98h] [ebp-A4h]
  __int32 v160; // [esp-94h] [ebp-A0h]
  float v161; // [esp-90h] [ebp-9Ch]
  float v162; // [esp-8Ch] [ebp-98h]
  float v163; // [esp-88h] [ebp-94h]
  int v164; // [esp-84h] [ebp-90h]
  float v165; // [esp-80h] [ebp-8Ch]
  float v166; // [esp-7Ch] [ebp-88h]
  float v167; // [esp-78h] [ebp-84h]
  int v168; // [esp-74h] [ebp-80h]
  float v169; // [esp-70h] [ebp-7Ch]
  float v170; // [esp-6Ch] [ebp-78h]
  float v171; // [esp-68h] [ebp-74h]
  int v172; // [esp-64h] [ebp-70h]
  float v173; // [esp-60h] [ebp-6Ch]
  float v174; // [esp-5Ch] [ebp-68h]
  float v175; // [esp-58h] [ebp-64h]
  int v176; // [esp-54h] [ebp-60h]
  float v177; // [esp-50h] [ebp-5Ch]
  float v178; // [esp-4Ch] [ebp-58h]
  float v179; // [esp-48h] [ebp-54h]
  int v180; // [esp-44h] [ebp-50h]
  float v181; // [esp-40h] [ebp-4Ch]
  float v182; // [esp-3Ch] [ebp-48h]
  float v183; // [esp-38h] [ebp-44h]
  int v184; // [esp-34h] [ebp-40h]
  __m128 v185; // [esp-30h] [ebp-3Ch] BYREF
  float v186; // [esp-1Ch] [ebp-28h]
  float v187; // [esp-18h] [ebp-24h]
  float v188; // [esp-14h] [ebp-20h]
  float v189; // [esp-10h] [ebp-1Ch]
  float v190; // [esp-Ch] [ebp-18h]
  unsigned int v191; // [esp-8h] [ebp-14h]
  float v192; // [esp-4h] [ebp-10h]
  int v193; // [esp+0h] [ebp-Ch]
  void *v194; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v193 = a1;
  v194 = retaddr;
  v11 = 0.0;
  if ( (*(_BYTE *)(LODWORD(a3) + 244) & 2) != 0 )
    v11 = a3;
  v12 = *(float *)(a5 + 48) - *(float *)(LODWORD(a3) + 64);
  v13 = (*(_BYTE *)(a4 + 244) & 2) == 0;
  v188 = v11;
  v181 = v12;
  v184 = 0;
  v14 = *(float *)(a5 + 52) - *(float *)(LODWORD(a3) + 68);
  v15 = 0;
  if ( !v13 )
    v15 = a4;
  v172 = 0;
  v182 = v14;
  v16 = *(float *)(a5 + 56) - *(float *)(LODWORD(a3) + 72);
  *(float *)a10 = v181;
  v183 = v16;
  *(float *)(a10 + 4) = v182;
  *(float *)(a10 + 8) = v183;
  *(_DWORD *)(a10 + 12) = v184;
  v169 = *(float *)(a5 + 32) - *(float *)(a4 + 64);
  v170 = *(float *)(a5 + 36) - *(float *)(a4 + 68);
  v17 = *(float *)(a5 + 40) - *(float *)(a4 + 72);
  *(float *)a11 = v169;
  v171 = v17;
  *(float *)(a11 + 4) = v170;
  *(float *)(a11 + 8) = v171;
  *(_DWORD *)(a11 + 12) = v172;
  *a9 = 1.0;
  v190 = *(float *)(a5 + 72);
  v189 = *(float *)(a10 + 4);
  v187 = *(float *)(a5 + 68);
  v192 = *(float *)(a10 + 8);
  v18 = v190;
  v19 = v192;
  v124 = v189 * v190 - v192 * v187;
  v190 = *(float *)(a5 + 64);
  v192 = *(float *)a10;
  v20 = (float *)LODWORD(v188);
  v125 = v19 * v190 - v18 * v192;
  v126 = v187 * v192 - v189 * v190;
  if ( v188 == 0.0 )
  {
    memset(v91, 0, sizeof(v91));
    *(float *)&v22 = COERCE_FLOAT(v91);
  }
  else
  {
    v21 = *(float *)(LODWORD(v188) + 276);
    v96[3] = 0.0;
    *(float *)&v22 = COERCE_FLOAT(v96);
    v118 = *(float *)(LODWORD(v188) + 280) * v126 + v21 * v125 + v124 * *(float *)(LODWORD(v188) + 272);
    v119 = *(float *)(LODWORD(v188) + 292) * v125
         + v124 * *(float *)(LODWORD(v188) + 288)
         + *(float *)(LODWORD(v188) + 296) * v126;
    v120 = v126 * *(float *)(LODWORD(v188) + 312)
         + v125 * *(float *)(LODWORD(v188) + 308)
         + v124 * *(float *)(LODWORD(v188) + 304);
    v96[0] = *(float *)(LODWORD(v188) + 608) * v118;
    v96[1] = *(float *)(LODWORD(v188) + 612) * v119;
    v96[2] = *(float *)(LODWORD(v188) + 616) * v120;
  }
  v192 = *(float *)&v22;
  *(float *)(a2 + 48) = *v22;
  *(_DWORD *)(a2 + 52) = *(_DWORD *)(LODWORD(v192) + 4);
  *(_DWORD *)(a2 + 56) = *(_DWORD *)(LODWORD(v192) + 8);
  *(_DWORD *)(a2 + 60) = *(_DWORD *)(LODWORD(v192) + 12);
  v190 = *(float *)(a5 + 72);
  v192 = *(float *)(a11 + 4);
  v187 = *(float *)(a5 + 68);
  v189 = *(float *)(a11 + 8);
  v23 = v190;
  v24 = v192;
  v109 = v190 * v192 - v187 * v189;
  v190 = *(float *)(a5 + 64);
  v192 = *(float *)a11;
  v110 = v189 * v190 - v23 * v192;
  v111 = v192 * v187 - v190 * v24;
  if ( v15 )
  {
    v85[3] = 0.0;
    *(float *)&v25 = COERCE_FLOAT(v85);
    v145 = -v109;
    v146 = -v110;
    v147 = -v111;
    v103 = *(float *)(v15 + 280) * v147 + *(float *)(v15 + 276) * v146 + v145 * *(float *)(v15 + 272);
    v104 = *(float *)(v15 + 292) * v146 + v145 * *(float *)(v15 + 288) + *(float *)(v15 + 296) * v147;
    v105 = v147 * *(float *)(v15 + 312) + v146 * *(float *)(v15 + 308) + v145 * *(float *)(v15 + 304);
    v85[0] = *(float *)(v15 + 608) * v103;
    v85[1] = *(float *)(v15 + 612) * v104;
    v85[2] = *(float *)(v15 + 616) * v105;
  }
  else
  {
    memset(v93, 0, sizeof(v93));
    *(float *)&v25 = COERCE_FLOAT(v93);
  }
  v192 = *(float *)&v25;
  *(float *)(a2 + 64) = *v25;
  v190 = 0.0;
  *(_DWORD *)(a2 + 68) = *(_DWORD *)(LODWORD(v192) + 4);
  v187 = 0.0;
  *(_DWORD *)(a2 + 72) = *(_DWORD *)(LODWORD(v192) + 8);
  *(_DWORD *)(a2 + 76) = *(_DWORD *)(LODWORD(v192) + 12);
  if ( v20 )
  {
    v190 = *(float *)(a2 + 52);
    v192 = *(float *)(a10 + 8);
    v191 = *(unsigned int *)(a2 + 56);
    v189 = *(float *)(a10 + 4);
    v26 = v192;
    v27 = *(float *)&v191;
    v97 = v192 * v190 - v189 * *(float *)&v191;
    v192 = *(float *)a10;
    v191 = *(unsigned int *)(a2 + 48);
    v98 = v27 * v192 - v26 * *(float *)&v191;
    v99 = *(float *)&v191 * v189 - v192 * v190;
    *(float *)&v191 = v97 * *(float *)(a5 + 64) + *(float *)(a5 + 68) * v98 + v99 * *(float *)(a5 + 72);
    v190 = *(float *)&v191 + v20[88];
  }
  if ( v15 )
  {
    v28 = *(float *)(a2 + 64);
    v137 = -*(float *)(a2 + 68);
    v29 = *(float *)(a2 + 72);
    v136 = -v28;
    v138 = -v29;
    v189 = *(float *)(a11 + 8);
    v192 = *(float *)(a11 + 4);
    v30 = v192;
    v106 = v137 * v189 - v138 * v192;
    v192 = *(float *)a11;
    v107 = v138 * v192 - v189 * (float)-v28;
    v108 = v30 * (float)-v28 - v137 * v192;
    *(float *)&v191 = v106 * *(float *)(a5 + 64) + *(float *)(a5 + 68) * v107 + v108 * *(float *)(a5 + 72);
    v187 = *(float *)&v191 + *(float *)(v15 + 352);
  }
  v176 = 0;
  *(float *)(a2 + 116) = *a9 / (v187 + v190);
  *(_DWORD *)(a2 + 16) = *(_DWORD *)(a5 + 64);
  *(_DWORD *)(a2 + 20) = *(_DWORD *)(a5 + 68);
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(a5 + 72);
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(a5 + 76);
  v191 = *(unsigned int *)(a5 + 72);
  v189 = *(float *)(a10 + 4);
  v190 = *(float *)(a5 + 68);
  v192 = *(float *)(a10 + 8);
  v31 = v189;
  v32 = *(float *)&v191;
  v33 = v192;
  v34 = v190;
  v173 = v189 * *(float *)&v191 - v192 * v190;
  v191 = *(unsigned int *)(a5 + 64);
  v192 = *(float *)a10;
  *(float *)a2 = v173;
  v35 = v33 * *(float *)&v191;
  v36 = v192;
  v37 = v35 - v32 * v192;
  v38 = *(float *)&v191;
  v174 = v37;
  *(float *)(a2 + 4) = v174;
  v175 = v34 * v36 - v31 * v38;
  *(float *)(a2 + 8) = v175;
  *(_DWORD *)(a2 + 12) = v176;
  v39 = *(float *)(a5 + 64);
  v131 = -*(float *)(a5 + 68);
  v40 = -*(float *)(a5 + 72);
  v130 = -v39;
  v132 = v40;
  v192 = *(float *)(a11 + 4);
  v189 = *(float *)(a11 + 8);
  v41 = v132;
  v42 = v192;
  v168 = 0;
  v43 = v131;
  v44 = v189;
  v165 = v132 * v192 - v131 * v189;
  v192 = *(float *)a11;
  *(float *)(a2 + 32) = v165;
  v45 = v44 * v130;
  v46 = v192;
  v47 = v45 - v41 * v192;
  v48 = v130;
  v166 = v47;
  *(float *)(a2 + 36) = v166;
  v167 = v46 * v43 - v48 * v42;
  *(float *)(a2 + 40) = v167;
  *(_DWORD *)(a2 + 44) = v168;
  if ( v20 )
  {
    v49 = (float *)sub_9BDE50(v20, (int)&v83, (float *)a10);
  }
  else
  {
    memset(v87, 0, sizeof(v87));
    v49 = (float *)v87;
  }
  v161 = *v49;
  v162 = v49[1];
  v163 = v49[2];
  v164 = *((_DWORD *)v49 + 3);
  if ( v15 )
  {
    v50 = (__m128 *)sub_9BDE50((float *)v15, (int)&v82, (float *)a11);
  }
  else
  {
    v185 = 0u;
    v50 = &v185;
  }
  v157 = v50->m128_f32[0];
  v158 = v50->m128_f32[1];
  v51 = v50->m128_f32[2];
  v177 = v161 - v157;
  v159 = v51;
  v160 = v50->m128_i32[3];
  v178 = v162 - v158;
  v52 = v163;
  *(float *)a7 = v177;
  v53 = v52 - v159;
  *(float *)(a7 + 4) = v178;
  v180 = 0;
  v179 = v53;
  *(float *)(a7 + 8) = v179;
  *(_DWORD *)(a7 + 12) = v180;
  *a8 = *(float *)(a7 + 4) * *(float *)(a5 + 68)
      + *(float *)a7 * *(float *)(a5 + 64)
      + *(float *)(a7 + 8) * *(float *)(a5 + 72);
  v189 = *(float *)(a5 + 80) + *(float *)(a6 + 52);
  *(float *)(a2 + 112) = *(float *)(a5 + 84);
  if ( *(_DWORD *)(a5 + 144) > *(_DWORD *)(a6 + 64) || (v192 = *(float *)(a5 + 88) * -*a8, v192 <= 0.0) )
    v192 = 0.0;
  if ( (*(_BYTE *)(a6 + 60) & 4) != 0 )
  {
    v54 = a6;
    v55 = v188;
    *(float *)&v191 = *(float *)(a5 + 112) * *(float *)(a6 + 56);
    v185 = _mm_shuffle_ps((__m128)v191, (__m128)v191, 0);
    *(__m128 *)(a2 + 96) = v185;
    if ( v55 != 0.0 )
    {
      v56 = *(float *)(a2 + 16);
      v191 = *(unsigned int *)(LODWORD(v55) + 352);
      v57 = *(float *)(a2 + 96);
      v13 = *(float *)&v191 == 0.0;
      v58 = v56 * *(float *)&v191;
      v59 = *(float *)&v191;
      v112 = v58;
      v60 = *(float *)(a2 + 20) * *(float *)&v191;
      *(float *)&v191 = v57;
      v113 = v60;
      v114 = v59 * *(float *)(a2 + 24);
      v154 = v112 * *(float *)(LODWORD(v55) + 368);
      v155 = *(float *)(LODWORD(v55) + 372) * v113;
      v156 = *(float *)(LODWORD(v55) + 376) * v114;
      if ( !v13 )
      {
        v61 = *(float *)&v191;
        v100 = *(float *)&v191 * v154;
        v101 = *(float *)&v191 * v155;
        v102 = *(float *)&v191 * v156;
        *(float *)(LODWORD(v55) + 576) = *(float *)(LODWORD(v55) + 576) + v100;
        *(float *)(LODWORD(v55) + 580) = *(float *)(LODWORD(v55) + 580) + v101;
        *(float *)(LODWORD(v55) + 584) = *(float *)(LODWORD(v55) + 584) + v102;
        v142 = v61 * *(float *)(LODWORD(v55) + 608);
        v143 = *(float *)(LODWORD(v55) + 612) * v61;
        v144 = v61 * *(float *)(LODWORD(v55) + 616);
        v139 = v142 * *(float *)(a2 + 48);
        v140 = *(float *)(a2 + 52) * v143;
        v141 = *(float *)(a2 + 56) * v144;
        *(float *)(LODWORD(v55) + 592) = v139 + *(float *)(LODWORD(v55) + 592);
        *(float *)(LODWORD(v55) + 596) = *(float *)(LODWORD(v55) + 596) + v140;
        *(float *)(LODWORD(v55) + 600) = *(float *)(LODWORD(v55) + 600) + v141;
      }
    }
    if ( v15 )
    {
      v62 = *(float *)(a2 + 16);
      v63 = *(float *)(a2 + 64);
      v191 = *(unsigned int *)(v15 + 352);
      v151 = -v63;
      v64 = -*(float *)(a2 + 68);
      v13 = *(float *)&v191 == 0.0;
      v133 = v62 * *(float *)&v191;
      v134 = *(float *)(a2 + 20) * *(float *)&v191;
      v152 = v64;
      v65 = *(float *)&v191 * *(float *)(a2 + 24);
      v153 = -*(float *)(a2 + 72);
      v66 = *(float *)(a2 + 96);
      v135 = v65;
      v67 = v133 * *(float *)(v15 + 368);
      *(float *)&v191 = -v66;
      v127 = v67;
      v128 = *(float *)(v15 + 372) * v134;
      v129 = *(float *)(v15 + 376) * v135;
      if ( !v13 )
      {
        v68 = *(float *)&v191;
        v121 = *(float *)&v191 * v127;
        v122 = *(float *)&v191 * v128;
        v123 = *(float *)&v191 * v129;
        *(float *)(v15 + 576) = v121 + *(float *)(v15 + 576);
        *(float *)(v15 + 580) = *(float *)(v15 + 580) + v122;
        *(float *)(v15 + 584) = *(float *)(v15 + 584) + v123;
        v115 = v68 * *(float *)(v15 + 608);
        v116 = *(float *)(v15 + 612) * v68;
        v117 = v68 * *(float *)(v15 + 616);
        v148 = v115 * v151;
        v149 = v116 * v152;
        v150 = v117 * v153;
        *(float *)(v15 + 592) = *(float *)(v15 + 592) + v148;
        *(float *)(v15 + 596) = *(float *)(v15 + 596) + v149;
        *(float *)(v15 + 600) = *(float *)(v15 + 600) + v150;
      }
    }
  }
  else
  {
    v55 = v188;
    v54 = a6;
    v185 = (__m128)xmmword_B700C0;
    *(_QWORD *)(a2 + 96) = 0;
    *(_QWORD *)(a2 + 104) = v185.m128_u64[1];
  }
  v185 = (__m128)xmmword_B700C0;
  *(_QWORD *)(a2 + 80) = 0;
  *(_QWORD *)(a2 + 88) = v185.m128_u64[1];
  if ( v55 == 0.0 )
  {
    memset(v95, 0, sizeof(v95));
    v70 = (float *)v95;
    memset(v94, 0, sizeof(v94));
    v69 = (float *)v94;
  }
  else
  {
    v89[0] = *(_DWORD *)(LODWORD(v55) + 320);
    v89[1] = *(_DWORD *)(LODWORD(v55) + 324);
    v89[2] = *(_DWORD *)(LODWORD(v55) + 328);
    v89[3] = *(_DWORD *)(LODWORD(v55) + 332);
    v84[0] = *(_DWORD *)(LODWORD(v55) + 336);
    v84[1] = *(_DWORD *)(LODWORD(v55) + 340);
    v84[2] = *(_DWORD *)(LODWORD(v55) + 344);
    v84[3] = *(_DWORD *)(LODWORD(v55) + 348);
    v69 = (float *)v84;
    v70 = (float *)v89;
  }
  v71 = v69[1] * *(float *)(a2 + 4);
  v188 = *(float *)(a2 + 20);
  v72 = *v69 * *(float *)a2;
  v190 = *(float *)(a2 + 16);
  v187 = *(float *)(a2 + 24);
  *(float *)&v191 = v71 + v72 + v69[2] * *(float *)(a2 + 8);
  v73 = *(float *)&v191;
  *(float *)&v191 = v70[1] * v188 + v190 * *v70 + v70[2] * v187;
  v74 = v73 + *(float *)&v191;
  v75 = v188;
  v186 = v74;
  if ( v15 )
  {
    v92[0] = *(_DWORD *)(v15 + 320);
    v92[1] = *(_DWORD *)(v15 + 324);
    v92[2] = *(_DWORD *)(v15 + 328);
    v92[3] = *(_DWORD *)(v15 + 332);
    v90[0] = *(_DWORD *)(v15 + 336);
    v90[1] = *(_DWORD *)(v15 + 340);
    v90[2] = *(_DWORD *)(v15 + 344);
    v90[3] = *(_DWORD *)(v15 + 348);
    v76 = (float *)v92;
    result = (float *)v90;
  }
  else
  {
    memset(v88, 0, sizeof(v88));
    v76 = (float *)v88;
    memset(v86, 0, sizeof(v86));
    result = (float *)v86;
  }
  v13 = *(_DWORD *)(v54 + 44) == 0;
  v188 = *(float *)(a2 + 116);
  *(float *)&v191 = *(float *)(v54 + 32) * -v189 / *(float *)(v54 + 12);
  v78 = v188;
  v188 = *(float *)&v191 * v188;
  *(float *)&v191 = *(float *)(a2 + 36) * result[1] + *result * *(float *)(a2 + 32) + *(float *)(a2 + 40) * result[2];
  v79 = v75 * v76[1] + v190 * *v76 + v76[2] * v187;
  v80 = *(float *)&v191;
  *(float *)&v191 = v79;
  *(float *)&v191 = v80 - *(float *)&v191;
  v186 = *(float *)&v191 + v186;
  v186 = v192 - v186;
  v190 = v78 * v186;
  if ( v13 || v189 > (double)*(float *)(v54 + 48) )
  {
    v81 = v190;
    *(_DWORD *)(a2 + 156) = 0;
    *(float *)(a2 + 140) = v81 + v188;
  }
  else
  {
    *(float *)(a2 + 140) = v190;
    *(float *)(a2 + 156) = v188;
  }
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 152) = 1343554297;
  return result;
}
