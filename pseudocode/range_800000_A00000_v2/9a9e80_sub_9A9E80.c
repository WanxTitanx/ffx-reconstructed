// Function: sub_9A9E80
// Address: 0x9a9e80
// bad sp value at call has been detected, the output may be wrong!
int __usercall sub_9A9E80@<eax>(
        int a1@<ebp>,
        float *a2,
        float *a3,
        float *a4,
        float *a5,
        float *a6,
        float *a7,
        float *a8,
        int a9,
        int *a10,
        signed int n2_8,
        int a12,
        int a13,
        int *a14)
{
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st4
  double v20; // st3
  double v21; // st5
  double v22; // st6
  double v23; // st2
  double v24; // st1
  double v25; // st7
  double v26; // st1
  double v27; // st4
  double v28; // st2
  double v29; // st3
  double v30; // st0
  double v31; // st6
  double v32; // st5
  double v34; // st7
  double v35; // st4
  double v36; // st3
  double v37; // st6
  float v38; // edx
  double v39; // st6
  double v40; // st6
  double v41; // st6
  double v42; // st6
  double v43; // st6
  double v44; // st6
  double v45; // st6
  double v46; // st6
  double v47; // st6
  double v48; // st6
  double v49; // st6
  double v50; // st6
  double v51; // st6
  double v52; // st6
  double v53; // st6
  double v54; // st6
  double v55; // st7
  int n2_1; // edx
  double v57; // st7
  bool v58; // zf
  float *v59; // edx
  int v60; // edx
  double v61; // st7
  double v62; // st7
  float *v63; // edx
  int n3; // esi
  int v65; // edx
  double v66; // st7
  double v67; // st7
  int v68; // eax
  int v69; // edx
  double v70; // st7
  float v71; // xmm0_4
  double v72; // st6
  int v73; // eax
  float v74; // xmm0_4
  double v75; // st7
  float v76; // eax
  int n2_2; // esi
  float *v78; // edx
  float *v79; // eax
  float *v80; // ecx
  float v81; // xmm0_4
  float v82; // xmm0_4
  float *v83; // edx
  int n2_4; // ecx
  bool v85; // cc
  double v86; // st7
  float v87; // eax
  int n2_5; // esi
  float v89; // eax
  float *v90; // esi
  int v91; // edx
  int v92; // edx
  double v93; // st7
  double v94; // st7
  double v95; // st4
  double v96; // st1
  double v97; // st6
  double v98; // st4
  signed int n2_6; // esi
  int v100; // edx
  double v101; // st7
  double v102; // st6
  double v103; // st5
  double v104; // st4
  float v105; // eax
  float *v106; // edi
  double v107; // st3
  double v108; // st2
  double v109; // st4
  int v110; // edx
  double v111; // st7
  double v112; // st7
  float v113; // eax
  float *v114; // edi
  int n2_7; // ecx
  float v116; // edx
  float *v117; // ecx
  double v118; // st7
  float v119; // xmm0_4
  double v120; // st7
  float v121; // xmm0_4
  int v122; // eax
  float v123; // xmm0_4
  float v124; // eax
  float *v125; // ecx
  float v126; // xmm1_4
  double v127; // st7
  double v128; // st6
  int v129; // eax
  int n2_12; // edx
  int n2_10; // ecx
  int n2_11; // esi
  float v133; // eax
  int v134; // edx
  int v135; // eax
  float v136; // xmm0_4
  int v137; // eax
  float v138; // xmm0_4
  float v139; // [esp+10h] [ebp-200h]
  float v140; // [esp+10h] [ebp-200h]
  float v141; // [esp+18h] [ebp-1F8h] BYREF
  float v142; // [esp+1Ch] [ebp-1F4h]
  float v143; // [esp+20h] [ebp-1F0h]
  float v144; // [esp+24h] [ebp-1ECh]
  float v145; // [esp+28h] [ebp-1E8h]
  float v146; // [esp+2Ch] [ebp-1E4h]
  float v147; // [esp+30h] [ebp-1E0h]
  float v148; // [esp+34h] [ebp-1DCh]
  float v149; // [esp+38h] [ebp-1D8h]
  float v150; // [esp+3Ch] [ebp-1D4h]
  float v151; // [esp+40h] [ebp-1D0h]
  float v152; // [esp+44h] [ebp-1CCh] BYREF
  float v153; // [esp+48h] [ebp-1C8h]
  float v154; // [esp+4Ch] [ebp-1C4h]
  int v155; // [esp+50h] [ebp-1C0h]
  float v156; // [esp+54h] [ebp-1BCh] BYREF
  float v157; // [esp+58h] [ebp-1B8h]
  float v158; // [esp+5Ch] [ebp-1B4h]
  int v159; // [esp+60h] [ebp-1B0h]
  float v160; // [esp+68h] [ebp-1A8h]
  double v161; // [esp+6Ch] [ebp-1A4h]
  float v162; // [esp+74h] [ebp-19Ch] BYREF
  float v163; // [esp+78h] [ebp-198h]
  float v164; // [esp+7Ch] [ebp-194h]
  int v165; // [esp+80h] [ebp-190h]
  float v166; // [esp+90h] [ebp-180h]
  float v167; // [esp+94h] [ebp-17Ch]
  float v168; // [esp+98h] [ebp-178h]
  int n2_3; // [esp+9Ch] [ebp-174h]
  float v170; // [esp+A0h] [ebp-170h]
  double v171; // [esp+A4h] [ebp-16Ch] BYREF
  float v172; // [esp+B0h] [ebp-160h]
  float v173; // [esp+B4h] [ebp-15Ch] BYREF
  float v174; // [esp+B8h] [ebp-158h]
  float v175; // [esp+BCh] [ebp-154h]
  int v176; // [esp+C0h] [ebp-150h]
  float v177; // [esp+C8h] [ebp-148h]
  float v178; // [esp+CCh] [ebp-144h]
  float v179; // [esp+D0h] [ebp-140h]
  float v180; // [esp+D4h] [ebp-13Ch]
  float v181; // [esp+D8h] [ebp-138h]
  int n2; // [esp+DCh] [ebp-134h]
  float v183; // [esp+E0h] [ebp-130h]
  float v184; // [esp+E4h] [ebp-12Ch]
  float v185; // [esp+E8h] [ebp-128h]
  float v186; // [esp+ECh] [ebp-124h]
  BOOL v187; // [esp+F0h] [ebp-120h]
  float v188; // [esp+F4h] [ebp-11Ch]
  float v189; // [esp+F8h] [ebp-118h]
  float v190; // [esp+FCh] [ebp-114h]
  float v191; // [esp+100h] [ebp-110h]
  int v192[8]; // [esp+104h] [ebp-10Ch] BYREF
  int v193; // [esp+124h] [ebp-ECh] BYREF
  _BYTE v194[92]; // [esp+128h] [ebp-E8h] BYREF
  float v195[16]; // [esp+184h] [ebp-8Ch] BYREF
  float v196; // [esp+1C4h] [ebp-4Ch] BYREF
  float v197; // [esp+1C8h] [ebp-48h]
  float v198; // [esp+1CCh] [ebp-44h]
  float v199[5]; // [esp+1D0h] [ebp-40h]
  float v200; // [esp+1E4h] [ebp-2Ch] BYREF
  unsigned int v201; // [esp+1E8h] [ebp-28h] BYREF
  unsigned int v202; // [esp+1ECh] [ebp-24h]
  float v203; // [esp+1F0h] [ebp-20h]
  float v204; // [esp+1F4h] [ebp-1Ch] BYREF
  float v205; // [esp+1F8h] [ebp-18h]
  float v206; // [esp+1FCh] [ebp-14h]
  int v207; // [esp+204h] [ebp-Ch]
  void *v208; // [esp+208h] [ebp-8h]
  void *retaddr; // [esp+210h] [ebp+0h]
  int n2_9; // [esp+238h] [ebp+28h]

  v207 = a1;
  v208 = retaddr;
  HIDWORD(v171) = a9;
  v176 = 0;
  v173 = *a5 - *a2;
  v178 = *(float *)&a8;
  v14 = a5[1] - a2[1];
  v156 = 0.0;
  v157 = 0.0;
  v158 = 0.0;
  v174 = v14;
  v159 = 0;
  v15 = a5[2] - a2[2];
  v152 = v173;
  v153 = v174;
  v175 = v15;
  v16 = a3[4];
  v154 = v175;
  v185 = v16;
  v17 = *a3;
  v155 = 0;
  v189 = v17;
  v179 = a3[8];
  v18 = v189;
  v183 = 0.0;
  LODWORD(v141) = a3 + 8;
  v19 = v185;
  v20 = v179;
  v162 = v185 * v174 + v189 * v173 + v179 * v175;
  v189 = a3[5];
  v181 = a3[1];
  v185 = a3[9];
  v21 = v189;
  v22 = v185;
  v163 = v175 * v185 + v174 * v189 + v173 * v181;
  v167 = a3[6];
  v188 = a3[2];
  v170 = a3[10];
  v164 = v173 * v188 + v174 * v167 + v175 * v170;
  *(float *)&v201 = *a4 * 0.5;
  *(float *)&v202 = a4[1] * 0.5;
  v203 = a4[2] * 0.5;
  v204 = *a7 * 0.5;
  v205 = a7[1] * 0.5;
  v23 = 0.5 * a7[2];
  HIDWORD(v161) = a6 + 1;
  v206 = v23;
  v180 = a6[4];
  v142 = *a6;
  v166 = a6[8];
  v151 = v18 * v142 + v19 * v180 + v179 * v166;
  v145 = a6[5];
  v150 = a6[1];
  v186 = a6[9];
  LODWORD(v191) = a6 + 2;
  v179 = v18 * v150 + v19 * v145 + v179 * v186;
  v185 = a6[6];
  v189 = a6[2];
  v24 = v18 * v189;
  v25 = v185;
  v26 = v19 * v185 + v24;
  v27 = a6[10];
  v28 = v20 * v27 + v26;
  v29 = v189;
  v189 = v28;
  v168 = v142 * v181 + v180 * v21 + v166 * v22;
  v172 = v150 * v181 + v145 * v21 + v186 * v22;
  v185 = v22 * v27 + v21 * v185 + v29 * v181;
  v30 = v170;
  v181 = v166 * v170 + v180 * v167 + v142 * v188;
  v170 = v150 * v188 + v145 * v167 + v186 * v170;
  v167 = v30 * v27 + v29 * v188 + v167 * v25;
  v188 = fabs(v151);
  v144 = v188;
  v177 = -3.4028235e38;
  v188 = fabs(v179);
  v184 = -3.4028235e38;
  v187 = 0;
  v146 = v188;
  n2 = 0;
  v188 = fabs(v189);
  v148 = v188;
  v188 = fabs(v168);
  v147 = v188;
  v188 = fabs(v172);
  v143 = v188;
  v188 = fabs(v185);
  v149 = v188;
  v188 = fabs(v181);
  *(float *)&n2_3 = v188;
  v188 = fabs(v170);
  v160 = v188;
  v188 = fabs(v167);
  v190 = fabs(v162);
  v31 = v204;
  v190 = v190 - (v204 * v144 + *(float *)&v201 + v205 * v146 + v206 * v148);
  v32 = 0.0;
  if ( v190 > 0.0 )
    return 0;
  if ( v190 > -3.402823466385289e38 )
  {
    v177 = v190;
    v184 = v190;
    v183 = *(float *)&a3;
    v187 = v162 < 0.0;
    n2 = 1;
  }
  v190 = fabs(v163);
  v34 = *(float *)&v202;
  v190 = v190 - (v206 * v149 + v31 * v147 + *(float *)&v202 + v205 * v143);
  if ( v190 > 0.0 )
    return 0;
  v35 = v184;
  if ( v190 > (double)v184 )
  {
    v177 = v190;
    v184 = v190;
    LODWORD(v183) = a3 + 1;
    v187 = v163 < 0.0;
    v35 = v190;
    n2 = 2;
  }
  v190 = fabs(v164);
  v36 = v190 - (v31 * *(float *)&n2_3 + v203 + v205 * v160 + v206 * v188);
  v37 = v203;
  v190 = v36;
  if ( v190 > 0.0 )
    return 0;
  if ( v190 > v35 )
  {
    v177 = v190;
    v184 = v190;
    LODWORD(v183) = a3 + 2;
    v187 = v164 < 0.0;
    v35 = v190;
    n2 = 3;
  }
  v166 = v174 * v180 + v173 * v142 + v175 * v166;
  v166 = fabs(v166);
  v190 = v166 - (v34 * v147 + *(float *)&v201 * v144 + v37 * *(float *)&n2_3 + v204);
  if ( v190 > 0.0 )
    return 0;
  if ( v190 > v35 )
  {
    v177 = v190;
    v184 = v190;
    v183 = *(float *)&a6;
    v187 = sub_9AC660(a6, &v152) < 0.0;
    n2 = 4;
    v34 = *(float *)&v202;
    v32 = 0.0;
    v35 = v184;
    v37 = v203;
  }
  v186 = v173 * v150 + v174 * v145 + v175 * v186;
  v186 = fabs(v186);
  v190 = v186 - (v37 * v160 + v34 * v143 + *(float *)&v201 * v146 + v205);
  if ( v190 > v32 )
    return 0;
  if ( v190 > v35 )
  {
    v177 = v190;
    v184 = v190;
    v183 = *((float *)&v161 + 1);
    v187 = sub_9AC660(HIDWORD(v161), &v152) < 0.0;
    n2 = 5;
  }
  v186 = sub_9AC660(LODWORD(v191), &v152);
  v191 = fabs(v186);
  v190 = v191 - (v203 * v188 + *(float *)&v202 * v149 + *(float *)&v201 * v148 + v206);
  if ( v190 > 0.0 )
    return 0;
  if ( v190 > (double)v184 )
  {
    v177 = v190;
    v184 = v190;
    v183 = v38;
    v187 = v186 < 0.0;
    n2 = 6;
  }
  v144 = v144 + 0.000009999999747378752;
  v146 = v146 + 0.000009999999747378752;
  v148 = v148 + 0.000009999999747378752;
  v147 = v147 + 0.000009999999747378752;
  v143 = v143 + 0.000009999999747378752;
  v149 = v149 + 0.000009999999747378752;
  *(float *)&n2_3 = *(float *)&n2_3 + 0.000009999999747378752;
  v160 = v160 + 0.000009999999747378752;
  v188 = v188 + 0.000009999999747378752;
  v161 = v164 * v168 - v163 * v181;
  v191 = v161;
  v191 = fabs(v191);
  v190 = v191 - (v206 * v146 + v203 * v147 + *(float *)&v202 * *(float *)&n2_3 + v205 * v148);
  if ( v190 > 0.00000011920929 )
    return 0;
  v186 = -v181;
  v191 = v186 * v186 + 0.0 + v168 * v168;
  v191 = sqrt(v191);
  v180 = v191;
  v39 = v191;
  if ( v191 <= 0.00000011920929 || (v190 = v190 / v39, 1.049999952316284 * v190 <= v184) )
  {
    v40 = 0.0;
  }
  else
  {
    v177 = v190;
    v184 = v190;
    v183 = 0.0;
    v156 = 0.0 / v39;
    v157 = v186 / v39;
    v158 = v168 / v39;
    v40 = 0.0;
    v187 = v161 < 0.0;
    n2 = 7;
  }
  v161 = v164 * v172 - v163 * v170;
  v191 = v161;
  v191 = fabs(v191);
  v190 = v191 - (*(float *)&v202 * v160 + v203 * v143 + v204 * v148 + v206 * v144);
  if ( v190 > 0.00000011920929 )
    return 0;
  v186 = -v170;
  v191 = v40 + v186 * v186 + v172 * v172;
  v191 = sqrt(v191);
  v180 = v191;
  v41 = v191;
  if ( v191 <= 0.00000011920929 || (v190 = v190 / v41, v190 * 1.049999952316284 <= v184) )
  {
    v42 = 0.0;
  }
  else
  {
    v177 = v190;
    v184 = v190;
    v183 = 0.0;
    v156 = 0.0 / v41;
    v157 = v186 / v41;
    v158 = v172 / v41;
    v42 = 0.0;
    v187 = v161 < 0.0;
    n2 = 8;
  }
  v161 = v164 * v185 - v163 * v167;
  v191 = v161;
  v191 = fabs(v191);
  v190 = v191 - (*(float *)&v202 * v188 + v203 * v149 + v204 * v146 + v205 * v144);
  if ( v190 > 0.00000011920929 )
    return 0;
  v186 = -v167;
  v191 = v42 + v186 * v186 + v185 * v185;
  v191 = sqrt(v191);
  v180 = v191;
  v43 = v191;
  if ( v191 <= 0.00000011920929 || (v190 = v190 / v43, v190 * 1.049999952316284 <= v184) )
  {
    v44 = 0.0;
  }
  else
  {
    v177 = v190;
    v184 = v190;
    v183 = 0.0;
    v156 = 0.0 / v43;
    v157 = v186 / v43;
    v158 = v185 / v43;
    v44 = 0.0;
    v187 = v161 < 0.0;
    n2 = 9;
  }
  v161 = v162 * v181 - v164 * v151;
  v191 = v161;
  v191 = fabs(v191);
  v190 = v191 - (*(float *)&v201 * *(float *)&n2_3 + v203 * v144 + v205 * v149 + v206 * v143);
  if ( v190 > 0.00000011920929 )
    return 0;
  v186 = -v151;
  v191 = v44 + v181 * v181 + v186 * v186;
  v191 = sqrt(v191);
  v180 = v191;
  v45 = v191;
  if ( v191 <= 0.00000011920929 || (v190 = v190 / v45, v190 * 1.049999952316284 <= v184) )
  {
    v46 = 0.0;
  }
  else
  {
    v177 = v190;
    v184 = v190;
    v183 = 0.0;
    v156 = v181 / v45;
    v157 = 0.0 / v45;
    v158 = v186 / v45;
    v46 = 0.0;
    v187 = v161 < 0.0;
    n2 = 10;
  }
  v161 = v162 * v170 - v164 * v179;
  v191 = v161;
  v191 = fabs(v191);
  v190 = v191 - (*(float *)&v201 * v160 + v203 * v146 + v204 * v149 + v206 * v147);
  if ( v190 > 0.00000011920929 )
    return 0;
  v186 = -v179;
  v191 = v46 + v170 * v170 + v186 * v186;
  v191 = sqrt(v191);
  v180 = v191;
  v47 = v191;
  if ( v191 <= 0.00000011920929 || (v190 = v190 / v47, v190 * 1.049999952316284 <= v184) )
  {
    v48 = 0.0;
  }
  else
  {
    v177 = v190;
    v184 = v190;
    v183 = 0.0;
    v156 = v170 / v47;
    v157 = 0.0 / v47;
    v158 = v186 / v47;
    v48 = 0.0;
    v187 = v161 < 0.0;
    n2 = 11;
  }
  v161 = v162 * v167 - v164 * v189;
  v191 = v161;
  v191 = fabs(v191);
  v190 = v191 - (*(float *)&v201 * v188 + v203 * v148 + v204 * v143 + v205 * v147);
  if ( v190 > 0.00000011920929 )
    return 0;
  v170 = -v189;
  v191 = v48 + v167 * v167 + v170 * v170;
  v191 = sqrt(v191);
  v180 = v191;
  v49 = v191;
  if ( v191 <= 0.00000011920929 || (v190 = v190 / v49, v190 * 1.049999952316284 <= v184) )
  {
    v50 = 0.0;
  }
  else
  {
    v177 = v190;
    v184 = v190;
    v183 = 0.0;
    v156 = v167 / v49;
    v157 = 0.0 / v49;
    v158 = v170 / v49;
    v50 = 0.0;
    v187 = v161 < 0.0;
    n2 = 12;
  }
  v161 = v163 * v151 - v162 * v168;
  v191 = v161;
  v191 = fabs(v191);
  v190 = v191 - (*(float *)&v201 * v147 + *(float *)&v202 * v144 + v205 * v188 + v206 * v160);
  if ( v190 > 0.00000011920929 )
    return 0;
  v168 = -v168;
  v191 = v151 * v151 + v168 * v168 + v50;
  v191 = sqrt(v191);
  v180 = v191;
  v51 = v191;
  if ( v191 <= 0.00000011920929 || (v190 = v190 / v51, v190 * 1.049999952316284 <= v184) )
  {
    v52 = 0.0;
  }
  else
  {
    v177 = v190;
    v184 = v190;
    v183 = 0.0;
    v156 = v168 / v51;
    v157 = v151 / v51;
    v158 = 0.0 / v51;
    v52 = 0.0;
    v187 = v161 < 0.0;
    n2 = 13;
  }
  v161 = v163 * v179 - v162 * v172;
  v191 = v161;
  v191 = fabs(v191);
  v190 = v191 - (*(float *)&v201 * v143 + *(float *)&v202 * v146 + v204 * v188 + v206 * *(float *)&n2_3);
  if ( v190 > 0.00000011920929 )
    return 0;
  v172 = -v172;
  v191 = v179 * v179 + v172 * v172 + v52;
  v191 = sqrt(v191);
  v180 = v191;
  v53 = v191;
  if ( v191 <= 0.00000011920929 || (v190 = v190 / v53, v190 * 1.049999952316284 <= v184) )
  {
    v54 = 0.0;
  }
  else
  {
    v177 = v190;
    v184 = v190;
    v183 = 0.0;
    v156 = v172 / v53;
    v157 = v179 / v53;
    v158 = 0.0 / v53;
    v54 = 0.0;
    v187 = v161 < 0.0;
    n2 = 14;
  }
  v161 = v163 * v189 - v162 * v185;
  v191 = v161;
  v191 = fabs(v191);
  v190 = v191 - (*(float *)&v201 * v149 + *(float *)&v202 * v148 + v204 * v160 + v205 * *(float *)&n2_3);
  if ( v190 > 0.00000011920929 )
    return 0;
  v185 = -v185;
  v191 = v189 * v189 + v185 * v185 + v54;
  v191 = sqrt(v191);
  v180 = v191;
  v55 = v191;
  if ( v191 > 0.00000011920929 )
  {
    v190 = v190 / v55;
    if ( v190 * 1.049999952316284 > v184 )
    {
      v177 = v190;
      v156 = v185 / v55;
      v157 = v189 / v55;
      v158 = 0.0 / v55;
      v187 = v161 < 0.0;
      n2 = 15;
LABEL_64:
      *a8 = sub_9AC6C0(a3, &v156);
      a8[1] = sub_9AC6C0(a3 + 4, &v156);
      v57 = sub_9AC6C0(LODWORD(v141), &v156);
      goto LABEL_65;
    }
  }
  n2_1 = n2;
  if ( !n2 )
    return 0;
  v76 = v183;
  if ( v183 == 0.0 )
    goto LABEL_64;
  *a8 = *(float *)LODWORD(v183);
  a8[1] = *(float *)(LODWORD(v76) + 16);
  v57 = *(float *)(LODWORD(v76) + 32);
LABEL_65:
  v58 = !v187;
  a8[2] = v57;
  if ( !v58 )
  {
    *a8 = -*a8;
    a8[1] = -a8[1];
    a8[2] = -a8[2];
  }
  v177 = -v177;
  *(float *)HIDWORD(v171) = v177;
  if ( n2_1 > 6 )
  {
    v59 = a3;
    v162 = *a2;
    v163 = a2[1];
    v164 = a2[2];
    HIDWORD(v171) = (char *)&v201 - (char *)a3;
    LODWORD(v178) = 3;
    do
    {
      v61 = sub_9AC630(a8, v59);
      v181 = 1.0;
      if ( v61 <= 0.0 )
        v181 = -1.0;
      v59 = (float *)(v60 + 4);
      v58 = LODWORD(v178)-- == 1;
      v62 = *(float *)((char *)v59 + HIDWORD(v171) - 4) * v181;
      v162 = *(v59 - 1) * v62 + v162;
      v163 = v59[3] * v62 + v163;
      v164 = v62 * v59[7] + v164;
    }
    while ( !v58 );
    v63 = a6;
    v173 = *a5;
    v174 = a5[1];
    v175 = a5[2];
    HIDWORD(v171) = (char *)&v204 - (char *)a6;
    n3 = 3;
    do
    {
      v66 = sub_9AC630(a8, v63);
      v181 = -1.0;
      if ( v66 <= 0.0 )
        v181 = 1.0;
      v63 = (float *)(v65 + 4);
      v67 = *(float *)((char *)v63 + HIDWORD(v171) - 4) * v181;
      v173 = *(v63 - 1) * v67 + v173;
      v174 = v63[3] * v67 + v174;
      v175 = v67 * v63[7] + v175;
      --n3;
    }
    while ( n3 );
    v68 = (n2 - 7) / 3;
    v69 = (n2 - 7) % 3;
    v156 = a3[v68];
    v157 = a3[v68 + 4];
    v158 = a3[v68 + 8];
    v152 = a6[v69];
    v153 = a6[v69 + 4];
    v154 = a6[v69 + 8];
    sub_9AC6F0(&v162, &v156, &v173, &v152, &v141, (char *)&v171 + 4);
    v70 = v152 * *((float *)&v171 + 1);
    v152 = -*a8;
    v71 = -a8[1];
    v173 = v70 + v173;
    v155 = 0;
    v72 = v153 * *((float *)&v171 + 1);
    v153 = v71;
    v73 = *a14;
    v74 = -a8[2];
    v174 = v72 + v174;
    v75 = *((float *)&v171 + 1) * v154;
    v154 = v74;
    v175 = v75 + v175;
    (*(void (__thiscall **)(int *, float *, float *, _DWORD))(v73 + 12))(a14, &v152, &v173, -v177);
    *a10 = n2;
    return 1;
  }
  n2_2 = n2;
  if ( n2 > 3 )
  {
    v78 = a5;
    a5 = a2;
    v179 = *(float *)&a6;
    v79 = a3;
    v170 = COERCE_FLOAT(&v204);
    a6 = a3;
    *(float *)&v80 = COERCE_FLOAT(&v201);
  }
  else
  {
    v78 = a2;
    v179 = *(float *)&a3;
    v170 = COERCE_FLOAT(&v201);
    v79 = a6;
    *(float *)&v80 = COERCE_FLOAT(&v204);
  }
  v81 = *a8;
  v189 = *(float *)&v80;
  v151 = *(float *)&v78;
  if ( n2 > 3 )
  {
    v162 = -v81;
    v163 = -a8[1];
    v82 = -a8[2];
  }
  else
  {
    v162 = v81;
    v163 = a8[1];
    v82 = a8[2];
  }
  v164 = v82;
  v173 = sub_9AC660(v79, &v162);
  v174 = sub_9AC660(a6 + 1, &v162);
  v175 = sub_9AC660(a6 + 2, &v162);
  *((float *)&v171 + 1) = fabs(v173);
  v152 = *((float *)&v171 + 1);
  *((float *)&v171 + 1) = fabs(v174);
  v153 = *((float *)&v171 + 1);
  *((float *)&v171 + 1) = fabs(v175);
  v154 = *((float *)&v171 + 1);
  if ( v153 <= (double)v152 )
  {
    if ( v152 > (double)v154 )
    {
      n2_4 = 0;
      LODWORD(v188) = 1;
      n2_3 = 2;
      goto LABEL_93;
    }
    v188 = 0.0;
  }
  else
  {
    v188 = 0.0;
    if ( v153 > (double)v154 )
    {
      n2_4 = 1;
      n2_3 = 2;
      goto LABEL_93;
    }
  }
  n2_4 = 2;
  n2_3 = 1;
LABEL_93:
  v85 = *(&v173 + n2_4) >= 0.0;
  v185 = *(float *)(LODWORD(v189) + 4 * n2_4);
  if ( v85 )
  {
    v173 = *a5 - *v83 - a6[n2_4] * v185;
    v174 = a5[1] - v83[1] - a6[n2_4 + 4] * v185;
    v86 = a5[2] - v83[2] - v185 * a6[n2_4 + 8];
  }
  else
  {
    v173 = a6[n2_4] * v185 + *a5 - *v83;
    v174 = a6[n2_4 + 4] * v185 + a5[1] - v83[1];
    v86 = v185 * a6[n2_4 + 8] + a5[2] - v83[2];
  }
  v175 = v86;
  LODWORD(v87) = n2_2 - 1;
  if ( n2_2 > 3 )
    LODWORD(v87) = n2_2 - 4;
  v142 = v87;
  n2_5 = 2;
  if ( v87 == 0.0 )
  {
    LODWORD(v89) = 1;
  }
  else
  {
    if ( LODWORD(v87) != 1 )
      n2_5 = 1;
    v89 = 0.0;
  }
  v168 = v89;
  v167 = *(float *)&n2_5;
  v186 = sub_9AC630(&v173, (float *)(LODWORD(v179) + 4 * LODWORD(v89)));
  v90 = (float *)(LODWORD(v179) + 4 * n2_5);
  v145 = sub_9AC630(&v173, v90);
  LODWORD(v150) = &a6[LODWORD(v188)];
  v181 = sub_9AC690(v91, LODWORD(v150));
  LODWORD(v166) = &a6[n2_3];
  v179 = sub_9AC690(v92, LODWORD(v166));
  v172 = sub_9AC690(v90, LODWORD(v150));
  v185 = sub_9AC690(v90, LODWORD(v166));
  *((float *)&v171 + 1) = *(float *)(LODWORD(v189) + 4 * LODWORD(v188));
  v141 = v181 * *((float *)&v171 + 1);
  v139 = *((float *)&v171 + 1) * v172;
  *((float *)&v171 + 1) = *(float *)(LODWORD(v189) + 4 * n2_3);
  v93 = *((float *)&v171 + 1);
  *((float *)&v171 + 1) = v179 * *((float *)&v171 + 1);
  v191 = v93 * v185;
  v94 = v186 - v141;
  v196 = v94 - *((float *)&v171 + 1);
  v95 = v145 - v139;
  v197 = v95 - v191;
  v96 = *((float *)&v171 + 1);
  v198 = v94 + *((float *)&v171 + 1);
  LODWORD(v171) = *(_DWORD *)(LODWORD(v170) + 4 * LODWORD(v168));
  v199[0] = v95 + v191;
  v97 = v141 + v186;
  HIDWORD(v171) = *(_DWORD *)(LODWORD(v170) + 4 * LODWORD(v167));
  v199[1] = v96 + v97;
  v98 = v139 + v145;
  v199[2] = v191 + v98;
  v199[3] = v97 - v96;
  v199[4] = v98 - v191;
  v160 = COERCE_FLOAT(sub_9ACAC0((int)&v171, &v196, v195));
  if ( SLODWORD(v160) < 1 )
    return 0;
  n2_6 = 0;
  v100 = 0;
  *((float *)&v171 + 1) = 1.0 / (v185 * v181 - v172 * v179);
  v181 = v181 * *((float *)&v171 + 1);
  v179 = v179 * *((float *)&v171 + 1);
  v172 = v172 * *((float *)&v171 + 1);
  v185 = v185 * *((float *)&v171 + 1);
  v101 = v175;
  v102 = v174;
  v103 = v173;
  v104 = v181;
  v141 = *(float *)LODWORD(v150);
  v191 = *(float *)LODWORD(v166);
  *((float *)&v161 + 1) = a6[LODWORD(v188) + 4];
  v167 = a6[n2_3 + 4];
  v150 = a6[LODWORD(v188) + 8];
  v166 = a6[n2_3 + 8];
  v105 = COERCE_FLOAT(&v193);
  v170 = *(float *)(LODWORD(v170) + 4 * LODWORD(v142));
  v189 = COERCE_FLOAT(&v193);
  v106 = (float *)v194;
  do
  {
    v168 = v195[2 * v100];
    v107 = v168 - v186;
    v108 = v195[2 * v100 + 1] - v145;
    *((float *)&v171 + 1) = v185 * v107 - v179 * v108;
    v140 = v104 * v108 - v107 * v172;
    v109 = *((float *)&v171 + 1);
    *(v106 - 1) = v103 + *((float *)&v171 + 1) * v141 + v140 * v191;
    *v106 = v102 + v109 * *((float *)&v161 + 1) + v167 * v140;
    v106[1] = v101 + v109 * v150 + v140 * v166;
    v171 = v170;
    v111 = sub_9AC6C0(&v162, LODWORD(v105));
    *((float *)&v171 + 1) = v171 - v111;
    v112 = *((float *)&v171 + 1);
    *(&v196 + n2_6) = *((float *)&v171 + 1);
    if ( v112 < 0.0 )
    {
      v105 = v189;
    }
    else
    {
      ++n2_6;
      v195[2 * n2_6 - 2] = v168;
      v113 = v189;
      *(float *)&v194[8 * n2_6 + 88] = v195[2 * v110 + 1];
      v106 += 3;
      LODWORD(v105) = LODWORD(v113) + 12;
      v189 = v105;
    }
    v101 = v175;
    v100 = v110 + 1;
    v102 = v174;
    v103 = v173;
    v104 = v181;
  }
  while ( v100 < SLODWORD(v160) );
  v114 = (float *)LODWORD(v178);
  if ( n2_6 < 1 )
    return 0;
  n2_7 = n2_8;
  if ( n2_8 > n2_6 )
    n2_7 = n2_6;
  if ( n2_7 < 1 )
    n2_7 = 1;
  n2_9 = n2_7;
  if ( n2_6 > n2_7 )
  {
    n2_12 = 0;
    v183 = v196;
    n2_10 = 1;
    if ( n2_6 > 1 )
    {
      if ( n2_6 - 1 >= 4 )
      {
        do
        {
          v189 = *(&v196 + n2_10);
          if ( v189 > (double)v183 )
          {
            v183 = v189;
            n2_12 = n2_10;
          }
          v189 = *(&v197 + n2_10);
          if ( v189 > (double)v183 )
          {
            v183 = v189;
            n2_12 = n2_10 + 1;
          }
          v189 = v199[n2_10 - 1];
          if ( v189 > (double)v183 )
          {
            v183 = v189;
            n2_12 = n2_10 + 2;
          }
          v189 = v199[n2_10];
          if ( v189 > (double)v183 )
          {
            v183 = v189;
            n2_12 = n2_10 + 3;
          }
          n2_10 += 4;
        }
        while ( n2_10 < n2_6 - 3 );
        v114 = (float *)LODWORD(v178);
      }
      for ( ; n2_10 < n2_6; ++n2_10 )
      {
        v178 = *(&v196 + n2_10);
        if ( v178 > (double)v183 )
        {
          v183 = v178;
          n2_12 = n2_10;
        }
      }
    }
    sub_9A9BB0(n2_6, v195, n2_9, n2_12, v192);
    n2_11 = n2_9;
    v133 = 0.0;
    v179 = 0.0;
    do
    {
      v134 = v192[LODWORD(v133)];
      v152 = *(float *)&v194[12 * v134 - 4] + *(float *)LODWORD(v151);
      v153 = *(float *)&v194[12 * v134] + *(float *)(LODWORD(v151) + 4);
      v154 = *(float *)&v194[12 * v134 + 4] + *(float *)(LODWORD(v151) + 8);
      if ( n2 >= 4 )
      {
        v178 = *v114;
        *((float *)&v171 + 1) = *(&v196 + v134);
        v137 = *a14;
        v200 = -v178;
        v159 = 0;
        v203 = 0.0;
        v173 = *((float *)&v171 + 1) * v178;
        v189 = v114[1];
        v201 = LODWORD(v189) ^ 0x80000000;
        v174 = *((float *)&v171 + 1) * v189;
        v185 = v114[2];
        v202 = LODWORD(v185) ^ 0x80000000;
        v138 = *(&v196 + v134);
        v175 = *((float *)&v171 + 1) * v185;
        v156 = v152 - v173;
        v157 = v153 - v174;
        v158 = v154 - v175;
        (*(void (__thiscall **)(int *, float *, float *, _DWORD))(v137 + 12))(a14, &v200, &v156, -v138);
      }
      else
      {
        v135 = *a14;
        v162 = -*v114;
        v163 = -v114[1];
        v164 = -v114[2];
        v136 = -*(&v196 + v134);
        v165 = 0;
        (*(void (__thiscall **)(int *, float *, float *, _DWORD))(v135 + 12))(a14, &v162, &v152, LODWORD(v136));
        n2_11 = n2_9;
      }
      LODWORD(v133) = LODWORD(v179) + 1;
      v179 = v133;
    }
    while ( SLODWORD(v133) < n2_11 );
    *a10 = n2;
    return n2_11;
  }
  else if ( n2 >= 4 )
  {
    v124 = 0.0;
    v179 = 0.0;
    v125 = (float *)v194;
    v172 = COERCE_FLOAT(v194);
    do
    {
      v178 = *v114;
      v126 = v114[2];
      v185 = *(&v196 + LODWORD(v124));
      v127 = *(v125 - 1) + *(float *)LODWORD(v151);
      v152 = -v178;
      *((float *)&v171 + 1) = v126;
      v154 = -v126;
      v155 = 0;
      v173 = v127 - v185 * v178;
      v189 = v114[1];
      v128 = *v125 + *(float *)(LODWORD(v151) + 4);
      v153 = -v189;
      v174 = v128 - v185 * v189;
      v129 = *a14;
      v175 = v125[1] + *(float *)(LODWORD(v151) + 8) - v185 * v126;
      (*(void (__thiscall **)(int *, float *, float *, _DWORD))(v129 + 12))(a14, &v152, &v173, -v185);
      LODWORD(v124) = LODWORD(v179) + 1;
      v125 = (float *)(LODWORD(v172) + 12);
      v179 = v124;
      LODWORD(v172) += 12;
    }
    while ( SLODWORD(v124) < n2_6 );
    *a10 = n2;
    return n2_6;
  }
  else
  {
    v116 = 0.0;
    v178 = 0.0;
    v117 = (float *)v194;
    v189 = COERCE_FLOAT(v194);
    do
    {
      v118 = *(v117 - 1) + *(float *)LODWORD(v151);
      v152 = -*v114;
      v119 = v114[1];
      v173 = v118;
      v120 = *v117 + *(float *)(LODWORD(v151) + 4);
      v153 = -v119;
      v121 = -v114[2];
      v174 = v120;
      v154 = v121;
      v122 = *a14;
      v123 = -*(&v196 + LODWORD(v116));
      v175 = v117[1] + *(float *)(LODWORD(v151) + 8);
      v155 = 0;
      (*(void (__stdcall **)(float *, float *, _DWORD))(v122 + 12))(&v152, &v173, LODWORD(v123));
      LODWORD(v116) = LODWORD(v178) + 1;
      v117 = (float *)(LODWORD(v189) + 12);
      v178 = v116;
      LODWORD(v189) += 12;
    }
    while ( SLODWORD(v116) < n2_6 );
    *a10 = n2;
    return n2_6;
  }
}
