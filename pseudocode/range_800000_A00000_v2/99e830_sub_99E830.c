// Function: sub_99E830
// Address: 0x99e830
// bad sp value at call has been detected, the output may be wrong!
char __userpurge sub_99E830@<al>(
        int a1@<ebp>,
        float a2,
        int *a3,
        int a4,
        float *a5,
        float *a6,
        int a7,
        float *a8,
        float *a9,
        float a10,
        int a11)
{
  void *v11; // esp
  int n17; // eax
  int n17_1; // eax
  float *v14; // esi
  float *v15; // edi
  int v16; // eax
  int n672; // edx
  int v18; // eax
  int v19; // eax
  double v20; // st7
  double v21; // st6
  double v22; // st3
  double v23; // st4
  double v24; // st5
  double v25; // st5
  double v26; // st4
  double v27; // st4
  double v28; // st3
  double v29; // st7
  int v30; // eax
  float v31; // edx
  double v32; // st5
  double v33; // st4
  float v34; // esi
  double v35; // st3
  float v36; // edi
  int v37; // eax
  float v38; // edx
  int v39; // ecx
  int v40; // eax
  double v41; // st7
  double v42; // st6
  double v43; // st3
  double v44; // st4
  double v45; // st0
  double v46; // st2
  double v47; // st2
  double v48; // st5
  double v49; // st5
  double v50; // st4
  double v51; // st4
  double v52; // st7
  float v53; // eax
  double v54; // st4
  double v55; // st4
  double v56; // st5
  double v57; // st6
  float v58; // esi
  int v59; // edi
  int v60; // eax
  float v61; // edx
  int v62; // ecx
  int v63; // eax
  double v64; // st7
  double v65; // st6
  double v66; // st5
  double v67; // st4
  double v68; // st0
  double v69; // st2
  double v70; // st5
  double v71; // st5
  double v72; // st4
  double v73; // st4
  double v74; // st7
  int v75; // eax
  int v76; // eax
  float v77; // ecx
  float *v78; // eax
  float v79; // edx
  float v80; // eax
  double v81; // st5
  double v82; // st3
  double v83; // st2
  double v84; // st2
  double v85; // st5
  double v86; // st5
  double v87; // st2
  double v88; // st2
  bool v89; // zf
  int v91; // eax
  int v92; // eax
  int v93; // eax
  double v94; // st7
  int v95; // eax
  double v96; // st7
  double v97; // st7
  char v98; // dl
  float *v99; // ecx
  int v100; // esi
  double v101; // st7
  double v102; // st7
  float *v103; // ecx
  float v104; // eax
  int (__stdcall **p_??_7btIntermediateResult@?1??calcPenDepth@btMinkowskiPenetrat)(char); // [esp-11B0h] [ebp-11BCh] BYREF
  float v106; // [esp-1190h] [ebp-119Ch]
  float v107; // [esp-118Ch] [ebp-1198h]
  float v108; // [esp-1188h] [ebp-1194h]
  int v109; // [esp-1184h] [ebp-1190h]
  float v110; // [esp-1180h] [ebp-118Ch]
  char v111; // [esp-117Ch] [ebp-1188h]
  float v112; // [esp-1170h] [ebp-117Ch]
  float v113; // [esp-1160h] [ebp-116Ch]
  float v114; // [esp-115Ch] [ebp-1168h]
  float v115; // [esp-1158h] [ebp-1164h]
  int v116; // [esp-1154h] [ebp-1160h]
  int v117; // [esp-1144h] [ebp-1150h]
  float *v118; // [esp-1140h] [ebp-114Ch]
  float *v119; // [esp-113Ch] [ebp-1148h]
  float v120; // [esp-1138h] [ebp-1144h]
  float v121; // [esp-1134h] [ebp-1140h]
  float v122; // [esp-1130h] [ebp-113Ch]
  float v123; // [esp-112Ch] [ebp-1138h]
  float v124; // [esp-1128h] [ebp-1134h]
  int v125; // [esp-1124h] [ebp-1130h]
  float v126; // [esp-1120h] [ebp-112Ch]
  float v127; // [esp-1104h] [ebp-1110h]
  float v128; // [esp-1100h] [ebp-110Ch]
  float v129; // [esp-10F0h] [ebp-10FCh]
  float v130; // [esp-10ECh] [ebp-10F8h]
  float v131; // [esp-10E8h] [ebp-10F4h]
  int v132; // [esp-10E4h] [ebp-10F0h]
  float v133; // [esp-10D4h] [ebp-10E0h]
  float v134; // [esp-10D0h] [ebp-10DCh]
  float v135; // [esp-10CCh] [ebp-10D8h]
  float v136; // [esp-10C8h] [ebp-10D4h]
  int v137; // [esp-10C4h] [ebp-10D0h]
  float v138; // [esp-10C0h] [ebp-10CCh]
  float v139; // [esp-10BCh] [ebp-10C8h]
  __int64 v140; // [esp-10B8h] [ebp-10C4h]
  int v141; // [esp-10ACh] [ebp-10B8h]
  float v142; // [esp-10A8h] [ebp-10B4h]
  int *v143; // [esp-10A4h] [ebp-10B0h]
  float v144; // [esp-10A0h] [ebp-10ACh]
  float v145; // [esp-109Ch] [ebp-10A8h]
  float v146; // [esp-1098h] [ebp-10A4h]
  int v147; // [esp-1094h] [ebp-10A0h]
  int n42; // [esp-1084h] [ebp-1090h]
  float v149; // [esp-1080h] [ebp-108Ch]
  float v150; // [esp-107Ch] [ebp-1088h]
  float v151; // [esp-1078h] [ebp-1084h]
  int v152; // [esp-1074h] [ebp-1080h]
  float v153; // [esp-1070h] [ebp-107Ch]
  float v154; // [esp-106Ch] [ebp-1078h]
  double v155; // [esp-1068h] [ebp-1074h]
  float v156; // [esp-1060h] [ebp-106Ch] BYREF
  float v157; // [esp-105Ch] [ebp-1068h]
  float v158; // [esp-1058h] [ebp-1064h]
  int v159; // [esp-1054h] [ebp-1060h]
  float v160; // [esp-1044h] [ebp-1050h]
  bool v161; // [esp-103Dh] [ebp-1049h]
  float v162; // [esp-103Ch] [ebp-1048h]
  float v163; // [esp-1038h] [ebp-1044h]
  float v164; // [esp-1034h] [ebp-1040h]
  _DWORD v165[36]; // [esp-1030h] [ebp-103Ch] BYREF
  _BYTE v166[992]; // [esp-FA0h] [ebp-FACh] BYREF
  _BYTE v167[992]; // [esp-BC0h] [ebp-BCCh] BYREF
  _BYTE v168[992]; // [esp-7E0h] [ebp-7ECh] BYREF
  _DWORD v169[254]; // [esp-400h] [ebp-40Ch] BYREF
  _BYTE *v170; // [esp-8h] [ebp-14h]
  int n42_1; // [esp-4h] [ebp-10h]
  int v172; // [esp+0h] [ebp-Ch]
  void *v173; // [esp+4h] [ebp-8h]
  int v174; // [esp+8h] [ebp-4h] BYREF
  void *retaddr; // [esp+Ch] [ebp+0h]

  v172 = a1;
  v173 = retaddr;
  n42_1 = -1;
  v170 = &loc_AD96C6;
  v169[253] = NtCurrentTeb()->NtTib.ExceptionList;
  v169[252] = &v174;
  v11 = alloca(4616);
  v117 = a7;
  v133 = a2;
  v118 = a8;
  v143 = a3;
  n17 = a3[1];
  v119 = a9;
  v141 = a4;
  v121 = a10;
  v161 = (n17 == 17 || n17 == 18) && ((n17_1 = *(_DWORD *)(a4 + 4), n17_1 == 17) || n17_1 == 18);
  v14 = a6;
  v15 = a5;
  v120 = 9.9999998e17;
  v142 = 9.9999998e17;
  v128 = 0.0;
  v138 = 0.0;
  v127 = 0.0;
  v139 = 0.0;
  v126 = 0.0;
  v140 = 0;
  n42 = 42;
  v152 = 0;
  HIDWORD(v155) = 0;
  v163 = 0.0;
  do
  {
    v16 = sub_99F9A0();
    *(float *)&n672 = v163;
    v18 = LODWORD(v163) + v16;
    v156 = *(float *)v18;
    v157 = *(float *)(v18 + 4);
    v158 = *(float *)(v18 + 8);
    v19 = *(_DWORD *)(v18 + 12);
    v163 = -v158;
    v159 = v19;
    v20 = v157;
    v162 = -v157;
    v21 = v156;
    v122 = -v156;
    v22 = v162;
    v23 = v163;
    v163 = a5[10] * v163 + v122 * a5[2] + v162 * a5[6];
    v151 = v163;
    v162 = v122 * a5[1] + a5[5] * v162 + a5[9] * v23;
    v149 = v122 * *a5 + v22 * a5[4] + v23 * a5[8];
    v24 = v162;
    *(float *)&v168[n672] = v149;
    v150 = v24;
    *(float *)&v168[n672 + 4] = v150;
    v25 = v21 * a6[2];
    *(float *)&v168[n672 + 8] = v151;
    v26 = a6[6] * v20;
    *(_DWORD *)&v168[n672 + 12] = v152;
    v163 = v25 + v26 + v158 * a6[10];
    v27 = a6[1] * v21 + v20 * a6[5];
    v28 = a6[9] * v158;
    *(float *)&v155 = v163;
    n672 += 16;
    v163 = *(float *)&n672;
    v162 = v27 + v28;
    v153 = v20 * a6[4] + v21 * *a6 + v158 * a6[8];
    v29 = v162;
    *(float *)&v168[n672 + 976] = v153;
    v154 = v29;
    *(float *)&v168[n672 + 980] = v154;
    *(_DWORD *)&v168[n672 + 984] = LODWORD(v155);
    *(_DWORD *)&v168[n672 + 988] = HIDWORD(v155);
  }
  while ( n672 < 672 );
  v30 = (*(int (__thiscall **)(int *))(*v143 + 72))(v143);
  HIDWORD(v155) = v30;
  if ( v30 > 0 )
  {
    v31 = 0.0;
    v152 = 0;
    v137 = 0;
    v132 = 0;
    v162 = 0.0;
    v163 = 0.0;
    n42 = v30 + 42;
    do
    {
      (*(void (__thiscall **)(int *, float, float *))(*v143 + 76))(v143, COERCE_FLOAT(LODWORD(v31)), &v156);
      v32 = v158;
      v164 = v15[10] * v158 + v15[8] * v156 + v157 * v15[9];
      v33 = v15[4] * v156;
      v151 = v164;
      v34 = v164;
      v35 = v15[5] * v157;
      v158 = v164;
      v160 = v33 + v35 + v32 * v15[6];
      v149 = v157 * v15[1] + v156 * *v15 + v32 * v15[2];
      v156 = v149;
      v150 = v160;
      v36 = v160;
      v157 = v160;
      v159 = v152;
      v37 = sub_99F9A0();
      v38 = v163;
      *(float *)(v37 + LODWORD(v163) + 672) = v149;
      v39 = v152;
      *(float *)(v37 + LODWORD(v38) + 676) = v36;
      v15 = a5;
      v40 = LODWORD(v38) + v37;
      *(float *)(v40 + 680) = v34;
      *(_DWORD *)(v40 + 684) = v39;
      v160 = -v158;
      v41 = v157;
      v164 = -v157;
      v42 = v156;
      v122 = -v156;
      v43 = v164;
      v44 = v122 * v15[2] + v164 * v15[6];
      v14 = a6;
      v45 = v160;
      LODWORD(v38) += 16;
      v46 = a5[10] * v160;
      v163 = v38;
      v160 = v46 + v44;
      v47 = v122 * a5[1];
      v136 = v160;
      v164 = v47 + a5[5] * v164 + a5[9] * v45;
      v134 = v122 * *a5 + v43 * v15[4] + v45 * v15[8];
      v48 = v164;
      *(float *)&v168[LODWORD(v38) + 656] = v134;
      v135 = v48;
      *(float *)&v168[LODWORD(v38) + 660] = v135;
      v49 = v42 * a6[2];
      *(float *)&v168[LODWORD(v38) + 664] = v136;
      v50 = a6[6] * v41;
      *(_DWORD *)&v168[LODWORD(v38) + 668] = v137;
      v160 = v49 + v50 + v158 * a6[10];
      v51 = a6[1] * v42;
      v131 = v160;
      v164 = v51 + v41 * a6[5] + a6[9] * v158;
      v129 = v41 * a6[4] + v42 * *a6 + v158 * a6[8];
      v52 = v164;
      *(float *)((char *)&v169[164] + LODWORD(v38)) = v129;
      v130 = v52;
      *(float *)((char *)&v169[165] + LODWORD(v38)) = v130;
      *(float *)((char *)&v169[166] + LODWORD(v38)) = v131;
      *(_DWORD *)((char *)&v169[167] + LODWORD(v38)) = v132;
      LODWORD(v31) = LODWORD(v162) + 1;
      v162 = v31;
    }
    while ( SLODWORD(v31) < SHIDWORD(v155) );
  }
  v53 = COERCE_FLOAT((*(int (__thiscall **)(int))(*(_DWORD *)v141 + 72))(v141));
  v160 = v53;
  if ( v53 != 0.0 )
  {
    v163 = 0.0;
    if ( SLODWORD(v53) > 0 )
    {
      v152 = 0;
      v132 = 0;
      v137 = 0;
      LODWORD(v162) = 16 * n42;
      n42 += LODWORD(v53);
      do
      {
        (*(void (__thiscall **)(int, float, float *))(*(_DWORD *)v141 + 76))(v141, COERCE_FLOAT(LODWORD(v163)), &v156);
        v164 = v14[10] * v158 + v14[9] * v157 + v156 * v14[8];
        v54 = v156 * v14[4];
        v151 = v164;
        *((float *)&v155 + 1) = v54 + v157 * v14[5] + v158 * v14[6];
        v55 = *v14;
        v56 = v157 * v14[1];
        v57 = v158 * v14[2];
        v58 = v164;
        v158 = v164;
        v149 = v156 * v55 + v56 + v57;
        v156 = v149;
        v150 = *((float *)&v155 + 1);
        v59 = HIDWORD(v155);
        v157 = *((float *)&v155 + 1);
        v159 = v152;
        v60 = sub_99F9A0();
        v61 = v162;
        *(float *)(v60 + LODWORD(v162)) = v149;
        v62 = v152;
        *(_DWORD *)(v60 + LODWORD(v61) + 4) = v59;
        v15 = a5;
        v63 = LODWORD(v61) + v60;
        *(float *)(v63 + 8) = v58;
        *(_DWORD *)(v63 + 12) = v62;
        v164 = -v158;
        v64 = v157;
        *((float *)&v155 + 1) = -v157;
        v65 = v156;
        v122 = -v156;
        v66 = *((float *)&v155 + 1);
        v67 = *((float *)&v155 + 1) * v15[6] + v122 * v15[2];
        v14 = a6;
        v68 = v164;
        LODWORD(v61) += 16;
        v69 = a5[10] * v164;
        v162 = v61;
        v164 = v69 + v67;
        v131 = v164;
        *((float *)&v155 + 1) = v122 * v15[1] + v15[5] * *((float *)&v155 + 1) + a5[9] * v68;
        v129 = v66 * a5[4] + v122 * *v15 + v68 * v15[8];
        v70 = *((float *)&v155 + 1);
        *(float *)&v167[LODWORD(v61) + 976] = v129;
        v130 = v70;
        *(float *)&v167[LODWORD(v61) + 980] = v130;
        v71 = v65 * a6[2];
        *(float *)&v167[LODWORD(v61) + 984] = v131;
        v72 = a6[6] * v64;
        *(_DWORD *)&v167[LODWORD(v61) + 988] = v132;
        v164 = v71 + v72 + v158 * a6[10];
        v73 = a6[1] * v65;
        v136 = v164;
        *((float *)&v155 + 1) = v73 + v64 * a6[5] + a6[9] * v158;
        v134 = v64 * a6[4] + v65 * *a6 + v158 * a6[8];
        v74 = *((float *)&v155 + 1);
        *(float *)&v168[LODWORD(v61) + 976] = v134;
        v135 = v74;
        *(float *)&v168[LODWORD(v61) + 980] = v135;
        *(float *)&v168[LODWORD(v61) + 984] = v136;
        *(_DWORD *)&v168[LODWORD(v61) + 988] = v137;
        ++LODWORD(v163);
      }
      while ( SLODWORD(v163) < SLODWORD(v160) );
    }
  }
  n42_1 = n42;
  v75 = *v143;
  v170 = v166;
  (*(void (__thiscall **)(int *, _BYTE *))(v75 + 64))(v143, v168);
  (*(void (__thiscall **)(int, _DWORD *, _BYTE *, int))(*(_DWORD *)v141 + 64))(v141, v169, v167, n42);
  v163 = *((float *)&v140 + 1);
  if ( n42 > 0 )
  {
    v162 = 0.0;
    do
    {
      v76 = sub_99F9A0();
      v77 = v162;
      v78 = (float *)(LODWORD(v162) + v76);
      v126 = *v78;
      v149 = v126;
      v127 = v78[1];
      v150 = v127;
      v79 = v78[2];
      v80 = v78[3];
      v151 = v79;
      v128 = v80;
      if ( v161 )
      {
        v151 = 0.0;
        v79 = 0.0;
      }
      *((float *)&v155 + 1) = v149 * v149 + v150 * v150 + v151 * v151;
      if ( *((float *)&v155 + 1) > 0.01 )
      {
        v81 = v15[9];
        v113 = *(float *)&v166[LODWORD(v162)];
        v114 = *(float *)&v166[LODWORD(v162) + 4];
        v115 = *(float *)&v166[LODWORD(v162) + 8];
        v82 = v15[8];
        v116 = *(_DWORD *)&v166[LODWORD(v162) + 12];
        v122 = *(float *)&v167[LODWORD(v162)];
        v123 = *(float *)&v167[LODWORD(v162) + 4];
        v83 = v15[10];
        v124 = *(float *)&v167[LODWORD(v162) + 8];
        v125 = *(_DWORD *)&v167[LODWORD(v162) + 12];
        v132 = 0;
        *((float *)&v155 + 1) = v83 * v115 + v82 * v113 + v81 * v114;
        v160 = *((float *)&v155 + 1) + v15[14];
        v84 = v15[5] * v114;
        v131 = v160;
        *((float *)&v155 + 1) = v84 + v15[4] * v113 + v15[6] * v115;
        v164 = *((float *)&v155 + 1) + v15[13];
        *((float *)&v155 + 1) = v115 * v15[2] + v114 * v15[1] + v113 * *v15;
        v129 = *((float *)&v155 + 1) + v15[12];
        v144 = v129;
        v130 = v164;
        v85 = v14[9];
        v145 = v164;
        v146 = v160;
        v147 = 0;
        v86 = v85 * v123 + v122 * v14[8];
        v87 = v14[10];
        v137 = 0;
        *((float *)&v155 + 1) = v87 * v124 + v86;
        v160 = *((float *)&v155 + 1) + v14[14];
        v88 = v14[5] * v123;
        v136 = v160;
        *((float *)&v155 + 1) = v88 + v122 * v14[4] + v14[6] * v124;
        v164 = *((float *)&v155 + 1) + v14[13];
        *((float *)&v155 + 1) = v124 * v14[2] + v123 * v14[1] + v122 * *v14;
        v134 = *((float *)&v155 + 1) + v14[12];
        v156 = v134;
        v135 = v164;
        v157 = v164;
        v158 = v160;
        v159 = 0;
        if ( v161 )
        {
          v146 = 0.0;
          v158 = 0.0;
        }
        v164 = v158 - v146;
        *((float *)&v155 + 1) = v157 - v145;
        v112 = v156 - v144;
        v162 = v150 * *((float *)&v155 + 1) + v149 * v112 + v164 * v151;
        if ( v142 > (double)v162 )
        {
          v138 = v126;
          v139 = v127;
          v120 = v162;
          v142 = v162;
          *(float *)&v140 = v79;
          v163 = v128;
        }
      }
      v89 = n42-- == 1;
      LODWORD(v162) = LODWORD(v77) + 16;
    }
    while ( !v89 );
    v126 = *(float *)&v140;
    v127 = v139;
    v128 = v138;
  }
  sub_9695E0(v143);
  sub_9695E0(v141);
  if ( v120 < 0.0 )
    return 0;
  v155 = sub_9695E0(v141);
  v142 = sub_9695E0(v143) + v155 + 0.5 + v142;
  sub_9A8350(v143, v141, LODWORD(v133), 0);
  *(float *)v165 = *v15;
  *(float *)&v165[1] = v15[1];
  v91 = *((_DWORD *)v15 + 2);
  v133 = *(float *)&v140 * v142;
  v165[2] = v91;
  *(float *)&v165[3] = v15[3];
  *(float *)&v165[4] = v15[4];
  v92 = *((_DWORD *)v15 + 5);
  *((float *)&v155 + 1) = v139 * v142;
  v165[5] = v92;
  *(float *)&v165[6] = v15[6];
  v93 = *((_DWORD *)v15 + 7);
  v112 = v142 * v138;
  v165[7] = v93;
  v94 = v15[14] + v133;
  *(float *)&v165[8] = v15[8];
  *(float *)&v165[9] = v15[9];
  v95 = *((_DWORD *)v15 + 10);
  v164 = v94;
  v96 = v15[13];
  v165[10] = v95;
  *(float *)&v165[11] = v15[11];
  v147 = 0;
  v133 = v96 + *((float *)&v155 + 1);
  n42_1 = 0;
  v97 = v15[12];
  v165[33] = 0;
  v144 = v97 + v112;
  *(float *)&v165[12] = v144;
  v145 = v133;
  *(float *)&v165[13] = v133;
  v146 = v164;
  *(float *)&v165[14] = v164;
  v165[15] = 0;
  *(float *)&v165[16] = *v14;
  *(float *)&v165[17] = v14[1];
  *(float *)&v165[18] = v14[2];
  *(float *)&v165[19] = v14[3];
  *(float *)&v165[20] = v14[4];
  *(float *)&v165[21] = v14[5];
  *(float *)&v165[22] = v14[6];
  *(float *)&v165[23] = v14[7];
  *(float *)&v165[24] = v14[8];
  *(float *)&v165[25] = v14[9];
  *(float *)&v165[26] = v14[10];
  *(float *)&v165[27] = v14[11];
  *(float *)&v165[28] = v14[12];
  *(float *)&v165[29] = v14[13];
  *(float *)&v165[30] = v14[14];
  *(float *)&v165[31] = v14[15];
  v165[32] = 1566444395;
  p_??_7btIntermediateResult@?1??calcPenDepth@btMinkowskiPenetrat = &`btMinkowskiPenetrationDepthSolver::calcPenDepth'::`2'::btIntermediateResult::`vftable';
  v111 = 0;
  v144 = -v128;
  v145 = -v127;
  v146 = -v126;
  v147 = 0;
  LOBYTE(n42_1) = 1;
  sub_9A8450(v165, &p_??_7btIntermediateResult@?1??calcPenDepth@btMinkowskiPenetrat, LODWORD(v121), 0);
  v98 = v111;
  v121 = v142 - v110;
  if ( v111 )
  {
    v99 = v118;
    v100 = v117;
    v147 = 0;
    v122 = v138 * v121;
    v123 = v139 * v121;
    v124 = v121 * *(float *)&v140;
    v144 = v106 - v122;
    v101 = v107;
    *v118 = v144;
    v145 = v101 - v123;
    v102 = v108;
    v99[1] = v145;
    v146 = v102 - v124;
    v99[2] = v146;
    *((_DWORD *)v99 + 3) = v147;
    v103 = v119;
    *v119 = v106;
    v103[1] = v107;
    v103[2] = v108;
    *((_DWORD *)v103 + 3) = v109;
    v104 = v163;
    *(float *)v100 = v138;
    *(float *)(v100 + 4) = v139;
    *(_DWORD *)(v100 + 8) = v140;
    *(float *)(v100 + 12) = v104;
  }
  return v98;
}
