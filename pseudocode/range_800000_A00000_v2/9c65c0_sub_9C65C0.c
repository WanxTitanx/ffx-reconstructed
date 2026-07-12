// Function: sub_9C65C0
// Address: 0x9c65c0
// bad sp value at call has been detected, the output may be wrong!
void __userpurge sub_9C65C0(int a1@<ecx>, int a2@<ebp>, float *a3, float *a4, float *a5, float *a6)
{
  bool v7; // zf
  double v8; // st7
  double v9; // st3
  double v10; // st7
  double v11; // st5
  double v12; // st6
  double v13; // st3
  double v14; // st6
  double v15; // st3
  double v16; // st7
  double v17; // st3
  double v18; // st4
  double v19; // st7
  double v20; // st5
  double v21; // st6
  double v22; // st3
  double v23; // st7
  double v24; // st3
  double v25; // st5
  double v26; // st4
  double v27; // st6
  double v28; // st4
  double v29; // st2
  double v30; // st6
  double v31; // st3
  double v32; // st5
  float *v33; // eax
  double v34; // st7
  double v35; // st7
  double v36; // st4
  double v37; // st6
  double v38; // st7
  float v39; // xmm0_4
  double v40; // st7
  long double v41; // st7
  float *v42; // esi
  double v43; // st5
  double v44; // st4
  double v45; // st2
  double v46; // st7
  double v47; // st3
  double v48; // st6
  double v49; // st4
  long double v50; // st6
  float v51; // xmm0_4
  float v52; // xmm1_4
  double v53; // st7
  double v54; // st7
  double v55; // st6
  double v56; // st4
  double v57; // st5
  double v58; // st7
  double v59; // st7
  double v60; // st4
  double v61; // st3
  double v63; // st6
  double v64; // st4
  double v66; // st7
  double v68; // st6
  double v69; // st7
  double v70; // st7
  double v71; // st5
  double v72; // st4
  double v73; // st6
  double v74; // st3
  double v75; // st2
  double v76; // st7
  double v77; // st5
  double v78; // st4
  double v79; // st3
  double v80; // st2
  double v81; // st6
  double v82; // st2
  double v83; // st6
  double v84; // st3
  double v85; // st4
  double v86; // st7
  double v87; // st6
  long double v88; // st7
  long double v89; // st7
  double v90; // st5
  double v91; // st4
  double v92; // st6
  double v93; // st3
  double v94; // st7
  double v95; // st7
  double v96; // st7
  float v97; // xmm0_4
  double v98; // st7
  double v99; // st4
  double v100; // st6
  double v101; // st3
  float v102; // xmm0_4
  double v104; // st6
  double v105; // st4
  double v107; // st7
  double v108; // st7
  double v109; // st5
  double v110; // st6
  double v111; // st7
  double v112; // st4
  double v113; // st6
  double v114; // st3
  float v115; // xmm0_4
  float v116; // [esp-1B0h] [ebp-1BCh] BYREF
  float v117; // [esp-1ACh] [ebp-1B8h]
  float v118; // [esp-1A8h] [ebp-1B4h]
  float v119; // [esp-1A0h] [ebp-1ACh]
  float v120; // [esp-19Ch] [ebp-1A8h]
  float v121; // [esp-198h] [ebp-1A4h]
  float v122; // [esp-194h] [ebp-1A0h]
  float v123; // [esp-190h] [ebp-19Ch]
  float v124; // [esp-18Ch] [ebp-198h]
  float v125; // [esp-188h] [ebp-194h]
  float v126; // [esp-184h] [ebp-190h]
  float v127; // [esp-174h] [ebp-180h]
  float v128; // [esp-170h] [ebp-17Ch]
  float v129; // [esp-16Ch] [ebp-178h]
  float v130; // [esp-168h] [ebp-174h]
  float v131; // [esp-164h] [ebp-170h]
  float v132; // [esp-160h] [ebp-16Ch] BYREF
  float v133; // [esp-15Ch] [ebp-168h]
  float v134; // [esp-158h] [ebp-164h]
  float v135; // [esp-154h] [ebp-160h]
  float v136; // [esp-14Ch] [ebp-158h]
  float v137; // [esp-148h] [ebp-154h]
  float v138; // [esp-144h] [ebp-150h]
  float v139; // [esp-140h] [ebp-14Ch] BYREF
  float v140; // [esp-13Ch] [ebp-148h]
  float v141; // [esp-138h] [ebp-144h]
  float v142; // [esp-134h] [ebp-140h]
  float v143; // [esp-12Ch] [ebp-138h]
  float v144; // [esp-128h] [ebp-134h]
  float v145; // [esp-124h] [ebp-130h]
  float v146; // [esp-120h] [ebp-12Ch] BYREF
  float v147; // [esp-11Ch] [ebp-128h]
  __int64 v148; // [esp-118h] [ebp-124h]
  float v149; // [esp-10Ch] [ebp-118h]
  float v150; // [esp-108h] [ebp-114h]
  float v151; // [esp-104h] [ebp-110h]
  float v152; // [esp-100h] [ebp-10Ch]
  float v153; // [esp-FCh] [ebp-108h]
  float v154; // [esp-F8h] [ebp-104h]
  float v155; // [esp-F4h] [ebp-100h]
  float v156; // [esp-F0h] [ebp-FCh]
  float v157; // [esp-ECh] [ebp-F8h]
  float v158; // [esp-E8h] [ebp-F4h] BYREF
  float v159; // [esp-E4h] [ebp-F0h]
  float v160; // [esp-E0h] [ebp-ECh] BYREF
  float v161; // [esp-DCh] [ebp-E8h]
  unsigned int v162; // [esp-D8h] [ebp-E4h]
  float v163; // [esp-D4h] [ebp-E0h]
  float v164; // [esp-C8h] [ebp-D4h]
  float v165; // [esp-C4h] [ebp-D0h] BYREF
  float v166; // [esp-C0h] [ebp-CCh] BYREF
  float v167; // [esp-BCh] [ebp-C8h]
  float v168; // [esp-B8h] [ebp-C4h]
  float v169; // [esp-B0h] [ebp-BCh]
  float v170; // [esp-ACh] [ebp-B8h]
  float v171; // [esp-A8h] [ebp-B4h]
  float v172; // [esp-A0h] [ebp-ACh]
  float v173; // [esp-9Ch] [ebp-A8h]
  float v174; // [esp-98h] [ebp-A4h]
  float v175; // [esp-80h] [ebp-8Ch] BYREF
  float v176; // [esp-7Ch] [ebp-88h]
  float v177; // [esp-78h] [ebp-84h]
  int v178; // [esp-74h] [ebp-80h]
  float v179; // [esp-70h] [ebp-7Ch]
  float v180; // [esp-6Ch] [ebp-78h]
  float v181; // [esp-68h] [ebp-74h]
  int v182; // [esp-64h] [ebp-70h]
  float v183; // [esp-60h] [ebp-6Ch]
  float v184; // [esp-5Ch] [ebp-68h]
  __int64 v185; // [esp-58h] [ebp-64h]
  float v186; // [esp-50h] [ebp-5Ch]
  float v187; // [esp-4Ch] [ebp-58h]
  unsigned int v188; // [esp-48h] [ebp-54h]
  int v189; // [esp-44h] [ebp-50h]
  float v190; // [esp-40h] [ebp-4Ch]
  float v191; // [esp-3Ch] [ebp-48h]
  float v192; // [esp-38h] [ebp-44h]
  int v193; // [esp-34h] [ebp-40h]
  float v194; // [esp-30h] [ebp-3Ch]
  float v195; // [esp-2Ch] [ebp-38h]
  float v196; // [esp-28h] [ebp-34h]
  int v197; // [esp-24h] [ebp-30h]
  float v198; // [esp-20h] [ebp-2Ch]
  float v199; // [esp-1Ch] [ebp-28h]
  __int64 v200; // [esp-18h] [ebp-24h]
  float *v201; // [esp-8h] [ebp-14h]
  int v202; // [esp+0h] [ebp-Ch]
  void *v203; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v202 = a2;
  v203 = retaddr;
  v7 = *(_BYTE *)(a1 + 592) == 0;
  *(_DWORD *)(a1 + 540) = 0;
  *(_DWORD *)(a1 + 536) = 0;
  *(_WORD *)(a1 + 561) = 0;
  if ( v7 || *(_BYTE *)(a1 + 563) )
  {
    v42 = (float *)(a1 + 336);
    sub_5FE290(&v139);
    sub_5FE290(&v160);
    v123 = v141 * v161 + v139 * v163 + v142 * v160 - v140 * *(float *)&v162;
    v124 = v161 * v142 + v140 * v163 + *(float *)&v162 * v139 - v141 * v160;
    v125 = *(float *)&v162 * v142 + v141 * v163 + v140 * v160 - v161 * v139;
    v126 = v163 * v142 - v139 * v160 - v161 * v140 - *(float *)&v162 * v141;
    sub_5FE290(&v139);
    sub_5FE290(&v160);
    v43 = v161;
    v44 = *(float *)&v162;
    v119 = v141 * v161 + v139 * v163 + v142 * v160 - v140 * *(float *)&v162;
    v136 = -v119;
    v149 = -v119;
    v120 = v161 * v142 + v140 * v163 + *(float *)&v162 * v139 - v141 * v160;
    v121 = *(float *)&v162 * v142 + v141 * v163 + v140 * v160 - v161 * v139;
    v45 = v160;
    v160 = -v119;
    v161 = -v120;
    v137 = -v120;
    v152 = -v121;
    *(float *)&v162 = -v121;
    v122 = v163 * v142 - v139 * v45 - v43 * v140 - v44 * v141;
    v46 = (float)-v119;
    v47 = (float)-v120;
    v48 = (float)-v121;
    v128 = v46 * v126 + v122 * v123 + v47 * v125 - v48 * v124;
    v129 = v47 * v126 + v122 * v124 + v48 * v123 - v46 * v125;
    v130 = v48 * v126 + v122 * v125 + v46 * v124 - v47 * v123;
    v131 = v126 * v122 - v46 * v123 - v47 * v124 - v48 * v125;
    v139 = v129 * flt_C64B48 + v131 * flt_C64B40 - v130 * flt_C64B44;
    v140 = v131 * flt_C64B44 + v130 * flt_C64B40 - v128 * flt_C64B48;
    v141 = v131 * flt_C64B48 + v128 * flt_C64B44 - v129 * flt_C64B40;
    v165 = -v128;
    v132 = -v128;
    v133 = -v129;
    v134 = -v130;
    v135 = v131;
    v142 = flt_C64B40 * (float)-v128 - flt_C64B44 * v129 - flt_C64B48 * v130;
    sub_9C5A60(&v132);
    v165 = v139 * v139 + v140 * v140 + v141 * v141;
    v165 = sqrt(v165);
    v165 = 1.0 / v165;
    v160 = v139 * v165;
    v161 = v140 * v165;
    *(float *)&v162 = v165 * v141;
    v49 = flt_C64B44;
    v146 = *(float *)&v162 * flt_C64B44 - v161 * flt_C64B48;
    v147 = v160 * flt_C64B48 - *(float *)&v162 * flt_C64B40;
    *(float *)&v148 = v161 * flt_C64B40 - v160 * flt_C64B44;
    v50 = flt_C64B48;
    v165 = *(float *)&v162 * flt_C64B48 + v160 * flt_C64B40 + v161 * flt_C64B44;
    if ( v165 >= -0.9999998807907104 )
    {
      v165 = v165 + 1.0 + v165 + 1.0;
      v165 = sqrt(v165);
      v53 = v165;
      v165 = 1.0 / v165;
      v139 = v146 * v165;
      v140 = v147 * v165;
      v141 = v165 * *(float *)&v148;
      v142 = v53 * 0.5;
    }
    else
    {
      v165 = fabs(v50);
      if ( v165 <= 0.70710677 )
      {
        v165 = v49 * v49 + flt_C64B40 * flt_C64B40;
        v165 = sqrt(v165);
        v52 = 0.0;
        v165 = 1.0 / v165;
        v160 = -flt_C64B44 * v165;
        v51 = v160;
        v161 = v165 * flt_C64B40;
      }
      else
      {
        v165 = v49 * v49 + v50 * v50;
        v165 = sqrt(v165);
        v51 = 0.0;
        v165 = 1.0 / v165;
        v161 = -flt_C64B48 * v165;
        *(float *)&v162 = v165 * flt_C64B44;
        v52 = *(float *)&v162;
      }
      v139 = v51;
      v140 = v161;
      v141 = v52;
      v142 = 0.0;
    }
    sub_982BB0(&v139);
    v160 = -v139;
    v161 = -v140;
    *(float *)&v162 = -v141;
    v132 = v160 * v131 + v142 * v128 + v161 * v130 - *(float *)&v162 * v129;
    v133 = v161 * v131 + v142 * v129 + *(float *)&v162 * v128 - v160 * v130;
    v134 = *(float *)&v162 * v131 + v142 * v130 + v160 * v129 - v161 * v128;
    v135 = v131 * v142 - v160 * v128 - v161 * v129 - *(float *)&v162 * v130;
    sub_982BB0(&v132);
    v159 = *(float *)(a1 + 480);
    v154 = *(float *)(a1 + 492);
    if ( v159 < (double)v154 || *(float *)(a1 + 484) < (double)v154 )
    {
      v160 = *v42;
      v161 = *(float *)(a1 + 352);
      v162 = *(unsigned int *)(a1 + 368);
      v145 = a3[1];
      v143 = *a3;
      v157 = a3[2];
      v139 = v160 * v143 + v161 * v145 + *(float *)&v162 * v157;
      v155 = a3[5];
      v156 = a3[4];
      v144 = a3[6];
      v140 = v160 * v156 + v161 * v155 + *(float *)&v162 * v144;
      v158 = a3[9];
      v150 = a3[8];
      v153 = a3[10];
      v141 = *(float *)&v162 * v153 + v161 * v158 + v160 * v150;
      v160 = *(float *)(a1 + 340);
      v161 = *(float *)(a1 + 356);
      v162 = *(unsigned int *)(a1 + 372);
      v116 = v160 * v143 + v161 * v145 + *(float *)&v162 * v157;
      v117 = v160 * v156 + v161 * v155 + *(float *)&v162 * v144;
      v118 = v160 * v150 + v161 * v158 + *(float *)&v162 * v153;
      v160 = *(float *)(a1 + 344);
      v161 = *(float *)(a1 + 360);
      v162 = *(unsigned int *)(a1 + 376);
      v146 = v160 * v143 + v161 * v145 + *(float *)&v162 * v157;
      v147 = v160 * v156 + v161 * v155 + *(float *)&v162 * v144;
      *(float *)&v148 = v158 * v161 + v160 * v150 + v153 * *(float *)&v162;
      v160 = *(float *)(a1 + 400);
      v161 = *(float *)(a1 + 416);
      v162 = *(unsigned int *)(a1 + 432);
      v68 = v161;
      v69 = v160;
      v160 = a4[2] * *(float *)&v162 + *a4 * v160 + a4[1] * v161;
      v161 = a4[5] * v161 + v69 * a4[4] + a4[6] * *(float *)&v162;
      *(float *)&v162 = v69 * a4[8] + v68 * a4[9] + *(float *)&v162 * a4[10];
      v70 = v161;
      v71 = v160;
      v72 = *(float *)&v162;
      v73 = v141;
      v156 = *(float *)&v162 * v141 + v161 * v140 + v160 * v139;
      v155 = v161 * v117 + v160 * v116 + *(float *)&v162 * v118;
      v157 = v161 * v147 + v160 * v146 + *(float *)&v162 * *(float *)&v148;
      v74 = v159;
      v75 = v154;
      if ( v154 <= (double)v159 || (v75 = v154, v154 <= (double)*(float *)(a1 + 484)) )
      {
        if ( v75 <= v74 )
        {
          v165 = fabs(v157);
          if ( v165 >= 0.00000011920929 )
          {
            *(_BYTE *)(a1 + 562) = 1;
            if ( v74 >= v75 )
            {
              v157 = 0.0;
              v165 = atan2(v155, v156);
              v89 = v159;
              if ( v165 <= (double)v159 )
              {
                if ( -v89 > v165 )
                {
                  v165 = cos(v89);
                  v156 = v165;
                  v165 = sin(v159);
                  v155 = -v165;
                }
              }
              else
              {
                v165 = cos(v89);
                v156 = v165;
                v165 = sin(v159);
                v155 = v165;
              }
            }
          }
        }
        else
        {
          v165 = fabs(v155);
          if ( v165 >= 0.00000011920929 )
          {
            v87 = *(float *)(a1 + 484);
            *(_BYTE *)(a1 + 562) = 1;
            v159 = v87;
            if ( v159 >= v75 )
            {
              v155 = 0.0;
              v165 = atan2(v157, v156);
              v88 = v159;
              if ( v165 <= (double)v159 )
              {
                if ( -v88 > v165 )
                {
                  v165 = cos(v88);
                  v156 = v165;
                  v165 = sin(v159);
                  v157 = -v165;
                }
              }
              else
              {
                v165 = cos(v88);
                v156 = v165;
                v165 = sin(v159);
                v157 = v165;
              }
            }
          }
        }
        v128 = v146 * v157 + v139 * v156 + v116 * v155;
        v129 = v117 * v155 + v140 * v156 + v147 * v157;
        v130 = v156 * v141 + v155 * v118 + v157 * *(float *)&v148;
        v165 = v128 * v128 + v129 * v129 + v130 * v130;
        v165 = sqrt(v165);
        v165 = 1.0 / v165;
        v128 = v165 * v128;
        v129 = v165 * v129;
        v130 = v165 * v130;
        v90 = v161;
        v91 = v129;
        v146 = v130 * v161 - v129 * *(float *)&v162;
        v92 = v160;
        v93 = *(float *)&v162 * v128 - v130 * v160;
        v94 = v128;
        v160 = -v146;
        v147 = v93;
        *(float *)(a1 + 496) = -v146;
        v163 = 0.0;
        *(float *)&v148 = v92 * v91 - v94 * v90;
        v161 = -v147;
        v95 = *(float *)&v148;
        *(float *)(a1 + 500) = v161;
        *(float *)&v162 = -v95;
        *(float *)(a1 + 504) = *(float *)&v162;
        *(float *)(a1 + 508) = v163;
        v165 = *(float *)(a1 + 496) * *(float *)(a1 + 496)
             + *(float *)(a1 + 500) * *(float *)(a1 + 500)
             + *(float *)(a1 + 504) * *(float *)(a1 + 504);
        v165 = sqrt(v165);
        *(float *)(a1 + 540) = v165;
        v153 = *(float *)(a1 + 500);
        v158 = *(float *)(a1 + 496);
        v154 = *(float *)(a1 + 504);
        v165 = v158 * v158 + v153 * v153 + v154 * v154;
        v165 = sqrt(v165);
        v165 = 1.0 / v165;
        v96 = v165;
        *(float *)(a1 + 496) = v165 * v158;
        *(float *)(a1 + 500) = v96 * v153;
        *(float *)(a1 + 504) = v96 * v154;
      }
      else
      {
        v165 = fabs(v155);
        if ( v165 >= 0.00000011920929 || (v165 = fabs(v157), v165 >= 0.00000011920929) )
        {
          v163 = 0.0;
          *(_BYTE *)(a1 + 562) = 1;
          v82 = v73 * v70;
          v83 = v140;
          v146 = v82 - v72 * v140;
          v84 = v139;
          v160 = -v146;
          v85 = v72 * v139;
          *(float *)(a1 + 496) = -v146;
          v147 = v85 - v71 * v141;
          *(float *)&v148 = v83 * v71 - v70 * v84;
          v161 = -v147;
          v86 = *(float *)&v148;
          *(float *)(a1 + 500) = v161;
          *(float *)&v162 = -v86;
          *(float *)(a1 + 504) = *(float *)&v162;
          *(float *)(a1 + 508) = v163;
        }
      }
    }
    else
    {
      v158 = 0.0;
      sub_9C9C30(&v139, &v165, &v146, &v158);
      v159 = *(float *)(a1 + 464);
      v54 = v159;
      v55 = v159 * v158;
      if ( v165 > v55 )
      {
        v56 = v158;
        v57 = v165;
        *(_BYTE *)(a1 + 562) = 1;
        *(_DWORD *)(a1 + 564) = 1065353216;
        if ( v56 <= v57 || v54 >= 0.9999998807907104 )
        {
          v58 = v57;
        }
        else
        {
          v58 = v57;
          *(float *)(a1 + 564) = (v57 - v55) / (v56 - v55);
        }
        v201 = &v146;
        *(float *)(a1 + 540) = v58 - v55;
        sub_9C5D70((float *)a1, v201);
        v160 = -v146;
        v161 = -v147;
        *(float *)&v162 = -*(float *)&v148;
        v59 = v160;
        v60 = *(float *)&v162;
        v61 = v161;
        v160 = v160 * v122 + *(float *)&v162 * v120 - v161 * v121;
        v161 = v161 * v122 + v59 * v121 - *(float *)&v162 * v119;
        *(float *)&v162 = v122 * *(float *)&v162 + v61 * v119 - v59 * v120;
        v163 = v59 * v149 - v120 * v61 - v121 * v60;
        sub_9C5A60(&v146);
        v146 = v160;
        v147 = v161;
        v148 = v162;
        *(float *)(a1 + 496) = v160;
        *(float *)(a1 + 500) = v147;
        *(_QWORD *)(a1 + 504) = v148;
        *(_DWORD *)(a1 + 576) = 0;
        *(_DWORD *)(a1 + 580) = 0;
        *(_DWORD *)(a1 + 584) = 0;
        *(_DWORD *)(a1 + 588) = 0;
        v165 = *(float *)(a1 + 500);
        v164 = *(float *)(a1 + 496);
        v151 = *(float *)(a1 + 504);
        v63 = v165;
        v146 = a5[8] * v151 + a5[4] * v165 + v164 * *a5;
        v147 = a5[1] * v164 + a5[5] * v165 + a5[9] * v151;
        v64 = a5[2] * v164 + a5[6] * v165;
        *(float *)&v148 = v64 + a5[10] * v151;
        v160 = a6[4] * v165 + v164 * *a6 + a6[8] * v151;
        v161 = a6[1] * v164 + a6[5] * v165 + a6[9] * v151;
        *(float *)&v162 = a6[2] * v164 + a6[6] * v165 + a6[10] * v151;
        v165 = v164 * v160 + v165 * v161 + v151 * *(float *)&v162;
        v66 = v165;
        v165 = v151 * *(float *)&v148 + v63 * v147 + v164 * v146;
        *(float *)(a1 + 528) = 1.0 / (v66 + v165);
      }
    }
    if ( *(float *)(a1 + 488) < 0.0 )
    {
      *(_DWORD *)(a1 + 548) = 0;
    }
    else
    {
      sub_9C9DF0(&v132, a1 + 548, &v116);
      v164 = *(float *)(a1 + 548);
      v165 = *(float *)(a1 + 488);
      v159 = *(float *)(a1 + 464);
      v76 = v159 * v165;
      v77 = v164;
      v78 = v118;
      v79 = v117;
      if ( v164 <= v76 )
      {
        v109 = v116;
        v108 = v117;
        v110 = v118;
      }
      else
      {
        v80 = v165;
        v81 = v116;
        *(_BYTE *)(a1 + 561) = 1;
        *(_DWORD *)(a1 + 568) = 1065353216;
        if ( v80 > v77 && v159 < 0.9999998807907104 )
          *(float *)(a1 + 568) = (v77 - v76) / (v80 - v76);
        v97 = v136;
        v201 = &v132;
        *(float *)(a1 + 544) = v77 - v76;
        v132 = -v81;
        v133 = -v79;
        v134 = -v78;
        v98 = v132;
        v132 = v97;
        v99 = v134;
        v100 = v98 * v122 + v134 * v120;
        v101 = v133;
        v133 = v137;
        v134 = v152;
        v135 = v122;
        v160 = v100 - v101 * v121;
        v161 = v101 * v122 + v98 * v121 - v99 * v119;
        *(float *)&v162 = v122 * v99 + v101 * v119 - v98 * v120;
        v163 = v98 * v149 - v120 * v101 - v121 * v99;
        sub_9C5A60(v201);
        v146 = v160;
        v147 = v161;
        v102 = *(float *)&v162;
        *(float *)(a1 + 512) = v160;
        v148 = LODWORD(v102);
        *(float *)(a1 + 516) = v147;
        *(_QWORD *)(a1 + 520) = v148;
        v165 = *(float *)(a1 + 516);
        v164 = *(float *)(a1 + 512);
        v151 = *(float *)(a1 + 520);
        v104 = v165;
        v160 = a5[8] * v151 + *a5 * v164 + a5[4] * v165;
        v161 = a5[1] * v164 + a5[5] * v165 + a5[9] * v151;
        v105 = a5[2] * v164 + a5[6] * v165;
        *(float *)&v162 = v105 + a5[10] * v151;
        v132 = a6[4] * v165 + *a6 * v164 + a6[8] * v151;
        v133 = a6[1] * v164 + a6[5] * v165 + a6[9] * v151;
        v134 = a6[2] * v164 + a6[6] * v165 + a6[10] * v151;
        v165 = v132 * v164 + v133 * v165 + v134 * v151;
        v107 = v165;
        v165 = v104 * v161 + v164 * v160 + v151 * *(float *)&v162;
        *(float *)(a1 + 532) = 1.0 / (v107 + v165);
        v108 = v117;
        v109 = v116;
        v110 = v118;
      }
      if ( *(_BYTE *)(a1 + 562) )
      {
        v132 = -v109;
        v165 = -v123;
        v133 = -v108;
        v134 = -v110;
        v111 = v132;
        v132 = -v123;
        v112 = v134;
        v113 = v111 * v126 + v134 * v124;
        v114 = v133;
        v133 = -v124;
        v134 = -v125;
        v135 = v126;
        v160 = v113 - v114 * v125;
        v161 = v114 * v126 + v111 * v125 - v112 * v123;
        *(float *)&v162 = v126 * v112 + v114 * v123 - v111 * v124;
        v163 = v111 * (float)-v123 - v124 * v114 - v125 * v112;
        sub_9C5A60(&v132);
        v146 = v160;
        v147 = v161;
        v115 = *(float *)&v162;
        *(float *)(a1 + 576) = v160;
        v148 = LODWORD(v115);
        *(float *)(a1 + 580) = v147;
        *(_QWORD *)(a1 + 584) = v148;
      }
    }
  }
  else
  {
    sub_603C50(a1 + 608);
    v163 = 0.0;
    v145 = a3[1];
    v137 = *(float *)(a1 + 388);
    v143 = *a3;
    v152 = *(float *)(a1 + 384);
    v157 = a3[2];
    v136 = *(float *)(a1 + 392);
    v8 = v152;
    v152 = v152 * v143 + v137 * v145 + v136 * v157;
    v160 = v152 + a3[12];
    v155 = a3[5];
    v156 = a3[4];
    v144 = a3[6];
    v152 = v156 * v8 + v155 * v137 + v144 * v136;
    v161 = v152 + a3[13];
    v158 = a3[9];
    v150 = a3[8];
    v153 = a3[10];
    v9 = v8 * v150;
    v10 = v158;
    v11 = v153;
    v12 = v150;
    v152 = v136 * v153 + v137 * v158 + v9;
    *(float *)&v162 = v152 + a3[14];
    v150 = *(float *)(a1 + 360);
    v159 = *(float *)(a1 + 344);
    v149 = *(float *)(a1 + 376);
    v164 = v159 * v12 + v150 * v158 + v149 * v153;
    v158 = *(float *)(a1 + 356);
    v154 = *(float *)(a1 + 340);
    v153 = *(float *)(a1 + 372);
    v151 = v154 * v12 + v158 * v10 + v153 * v11;
    v137 = *(float *)(a1 + 352);
    v152 = *(float *)(a1 + 336);
    v13 = v12 * v152;
    v14 = v137;
    v15 = v10 * v137 + v13;
    v16 = *(float *)(a1 + 368);
    v138 = v11 * v16 + v15;
    v127 = v150 * v155 + v159 * v156 + v149 * v144;
    v17 = v158;
    v18 = v153;
    v153 = v155 * v158 + v156 * v154 + v153 * v144;
    v158 = v152 * v156 + v137 * v155 + v16 * v144;
    v193 = 0;
    v197 = 0;
    v136 = v159 * v143 + v150 * v145 + v149 * v157;
    v192 = v136;
    v194 = v158;
    v195 = v153;
    v196 = v127;
    v198 = v138;
    v199 = v151;
    v200 = LODWORD(v164);
    v137 = v18 * v157 + v17 * v145 + v154 * v143;
    v152 = v152 * v143 + v145 * v14 + v157 * v16;
    v190 = v152;
    v175 = v152;
    v191 = v137;
    v176 = v137;
    v177 = v136;
    v178 = 0;
    v179 = v158;
    v180 = v153;
    v181 = v127;
    v182 = 0;
    v183 = v138;
    v184 = v151;
    v185 = LODWORD(v164);
    v186 = v160;
    v187 = v161;
    v188 = v162;
    v189 = 0;
    v153 = a4[1];
    v151 = *(float *)(a1 + 452);
    v155 = *a4;
    v164 = *(float *)(a1 + 448);
    v156 = a4[2];
    v138 = *(float *)(a1 + 456);
    v19 = v164;
    v20 = v151;
    v21 = v138;
    v164 = v164 * v155 + v151 * v153 + v138 * v156;
    v160 = v164 + a4[12];
    v150 = a4[5];
    v159 = a4[4];
    v154 = a4[6];
    v164 = v159 * v19 + v150 * v151 + v154 * v138;
    v161 = v164 + a4[13];
    v151 = a4[9];
    v164 = a4[8];
    v138 = a4[10];
    v22 = v19 * v164;
    v23 = v151;
    v24 = v20 * v151 + v22;
    v25 = v138;
    v26 = v21 * v138 + v24;
    v27 = v164;
    v164 = v26;
    *(float *)&v162 = v164 + a4[14];
    v144 = *(float *)(a1 + 424);
    v149 = *(float *)(a1 + 408);
    v143 = *(float *)(a1 + 440);
    v152 = v149 * v27 + v144 * v151 + v138 * v143;
    v158 = *(float *)(a1 + 420);
    v164 = *(float *)(a1 + 404);
    v157 = *(float *)(a1 + 436);
    v28 = v164;
    v127 = v27 * v164 + v151 * v158 + v138 * v157;
    v151 = *(float *)(a1 + 416);
    v164 = *(float *)(a1 + 400);
    v138 = *(float *)(a1 + 432);
    v29 = v27 * v164;
    v30 = v151;
    v151 = v25 * v138 + v23 * v151 + v29;
    v145 = v149 * v159 + v144 * v150 + v154 * v143;
    v31 = v157;
    v157 = v154 * v157 + v159 * v28 + v150 * v158;
    v154 = v159 * v164 + v150 * v30 + v154 * v138;
    v149 = v149 * v155 + v144 * v153 + v156 * v143;
    v158 = v31 * v156 + v28 * v155 + v153 * v158;
    v159 = v138 * v156 + v30 * v153 + v164 * v155;
    v164 = v159 * 0.0 + v158 * 0.0 + v149 * 0.0;
    v146 = v164 + v160;
    v164 = v154 * 0.0 + v157 * 0.0 + v145 * 0.0;
    v147 = v164 + v161;
    v32 = v152;
    v164 = 0.0 * v152 + v127 * 0.0 + v151 * 0.0;
    *(float *)&v148 = v164 + *(float *)&v162;
    v137 = v171 * v127 + v168 * v151 + v174 * v152;
    v152 = v170 * v127 + v167 * v151 + v173 * v152;
    v127 = v32 * v172 + v151 * v166 + v127 * v169;
    v155 = v168 * v154 + v171 * v157 + v174 * v145;
    v153 = v154 * v167 + v170 * v157 + v173 * v145;
    v150 = v166 * v154 + v169 * v157 + v172 * v145;
    v145 = v171 * v158 + v159 * v168 + v174 * v149;
    v156 = v173 * v149 + v170 * v158 + v159 * v167;
    v159 = v172 * v149 + v166 * v159 + v158 * v169;
    v33 = (float *)sub_982990(&v175, (int)&v166);
    v34 = v33[13];
    v163 = 0.0;
    v151 = v34;
    v164 = v33[12];
    v138 = v33[14];
    v35 = v164;
    v164 = v164 * v159 + v151 * v156 + v138 * v145;
    v160 = v164 + v146;
    v164 = v35 * v150 + v151 * v153 + v138 * v155;
    v161 = v164 + v147;
    v164 = v138 * v137 + v151 * v152 + v35 * v127;
    *(float *)&v162 = v164 + *(float *)&v148;
    v154 = v33[6];
    v158 = v33[2];
    v149 = v33[10];
    v165 = v158 * v127 + v154 * v152 + v137 * v149;
    v144 = v33[5];
    v157 = v33[1];
    v164 = v33[9];
    v36 = v164;
    v143 = v137 * v164 + v127 * v157 + v152 * v144;
    v151 = v33[4];
    v164 = *v33;
    v138 = v33[8];
    v37 = v151;
    v38 = v138;
    v136 = v137 * v138 + v152 * v151 + v127 * v164;
    v137 = v154 * v153 + v158 * v150 + v155 * v149;
    v152 = v153 * v144 + v150 * v157 + v155 * v36;
    v127 = v164 * v150 + v151 * v153 + v155 * v138;
    v138 = v158 * v159 + v154 * v156 + v145 * v149;
    v192 = v138;
    v194 = v127;
    v193 = 0;
    v151 = v36 * v145 + v144 * v156 + v159 * v157;
    v195 = v152;
    v196 = v137;
    v197 = 0;
    v198 = v136;
    v199 = v143;
    v200 = LODWORD(v165);
    v164 = v38 * v145 + v37 * v156 + v164 * v159;
    v190 = v164;
    v175 = v164;
    v191 = v151;
    v176 = v151;
    v177 = v138;
    v178 = 0;
    v179 = v127;
    v180 = v152;
    v181 = v137;
    v182 = 0;
    v183 = v136;
    v184 = v143;
    v185 = LODWORD(v165);
    v186 = v160;
    v187 = v161;
    v188 = v162;
    v189 = 0;
    sub_5FE290(&v132);
    v160 = v132;
    v161 = v133;
    v39 = v134;
    *(float *)(a1 + 496) = v132;
    *(float *)&v162 = v39;
    v163 = 0.0;
    *(float *)(a1 + 500) = v161;
    *(float *)(a1 + 504) = *(float *)&v162;
    *(float *)(a1 + 508) = v163;
    v153 = *(float *)(a1 + 500);
    v158 = *(float *)(a1 + 496);
    v154 = *(float *)(a1 + 504);
    v165 = v153 * v153 + v158 * v158 + v154 * v154;
    v165 = sqrt(v165);
    v165 = 1.0 / v165;
    v40 = v165;
    *(float *)(a1 + 496) = v165 * v158;
    *(float *)(a1 + 500) = v40 * v153;
    *(float *)(a1 + 504) = v40 * v154;
    v165 = sub_982040(&v132);
    v41 = v165;
    *(float *)(a1 + 540) = v165;
    v165 = fabs(v41);
    if ( v165 >= 0.00000011920929 )
      *(_BYTE *)(a1 + 562) = 1;
  }
}
