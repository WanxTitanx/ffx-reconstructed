// Function: sub_A68140
// Address: 0xa68140
// Size: 0xb4c
// Prototype: 

int __cdecl sub_A68140(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  float *v5; // eax
  double v6; // st7
  double v7; // st6
  float v8; // eax
  double v9; // st7
  float v10; // eax
  double v11; // st7
  int v12; // eax
  double v13; // st7
  double v14; // st7
  int v15; // eax
  double v16; // st5
  int v17; // eax
  _DWORD *v18; // edi
  int v19; // esi
  double v20; // st7
  int v21; // eax
  double v22; // st7
  int v23; // eax
  double v24; // st7
  int v25; // eax
  double v26; // st7
  int v27; // eax
  double v28; // st7
  int v29; // eax
  double v30; // st7
  int v31; // eax
  double v32; // st7
  int v33; // eax
  double v34; // st7
  double v35; // st6
  double v36; // st5
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // ecx
  double v53; // st6
  double v54; // rt0
  double v55; // st6
  double v56; // st7
  int v57; // esi
  int v58; // edx
  int v59; // eax
  double v60; // st6
  double v61; // st7
  int v62; // eax
  double v63; // st4
  double v64; // st5
  double v65; // st3
  int v66; // eax
  double v67; // st2
  int v68; // eax
  int v69; // eax
  int v70; // eax
  int v71; // eax
  __int16 v72; // bx
  __int16 v73; // dx
  double v75; // st7
  int v76; // eax
  double v77; // st7
  int v78; // eax
  double v79; // st7
  int v80; // eax
  double v81; // st7
  int v82; // eax
  double v83; // st7
  int v84; // eax
  double v85; // st7
  int v86; // eax
  double v87; // st7
  int v88; // eax
  int v89; // edi
  double v90; // st7
  double v91; // st6
  double v92; // st5
  int v93; // ecx
  int v94; // eax
  int v95; // edx
  int v96; // eax
  double v97; // st6
  int v98; // esi
  int v99; // edi
  int v100; // ecx
  double v101; // st6
  double v102; // st7
  double v103; // st4
  double v104; // st5
  double v105; // st3
  double v106; // st2
  int v107; // [esp+0h] [ebp-A4h] BYREF
  int v108; // [esp+4h] [ebp-A0h] BYREF
  float v109; // [esp+8h] [ebp-9Ch]
  int v110; // [esp+Ch] [ebp-98h]
  float v111; // [esp+10h] [ebp-94h]
  float v112; // [esp+14h] [ebp-90h]
  int v113; // [esp+18h] [ebp-8Ch]
  int v114; // [esp+1Ch] [ebp-88h]
  float v115; // [esp+20h] [ebp-84h]
  float v116; // [esp+24h] [ebp-80h]
  float v117; // [esp+28h] [ebp-7Ch]
  float v118; // [esp+2Ch] [ebp-78h]
  float v119; // [esp+30h] [ebp-74h]
  float v120; // [esp+34h] [ebp-70h]
  double v121; // [esp+38h] [ebp-6Ch]
  float v122[4]; // [esp+40h] [ebp-64h] BYREF
  float v123; // [esp+50h] [ebp-54h] BYREF
  float v124; // [esp+54h] [ebp-50h]
  float v125; // [esp+58h] [ebp-4Ch]
  float v126; // [esp+5Ch] [ebp-48h]
  float v127; // [esp+60h] [ebp-44h] BYREF
  float v128; // [esp+64h] [ebp-40h]
  float v129; // [esp+68h] [ebp-3Ch]
  float v130; // [esp+6Ch] [ebp-38h]
  float v131; // [esp+70h] [ebp-34h] BYREF
  float v132; // [esp+74h] [ebp-30h]
  float v133; // [esp+78h] [ebp-2Ch]
  float v134; // [esp+7Ch] [ebp-28h]
  float v135; // [esp+80h] [ebp-24h] BYREF
  float v136; // [esp+84h] [ebp-20h]
  float v137; // [esp+88h] [ebp-1Ch]
  float v138; // [esp+8Ch] [ebp-18h]
  float v139; // [esp+90h] [ebp-14h] BYREF
  float v140; // [esp+94h] [ebp-10h]
  float v141; // [esp+98h] [ebp-Ch]
  float v142; // [esp+9Ch] [ebp-8h]
  int v143; // [esp+B4h] [ebp+10h]

  v123 = 1.0;
  v124 = 1.0;
  v125 = 1.0;
  v4 = *(_DWORD *)(a2 + 68);
  v126 = 1.0;
  v122[0] = 0.0078125;
  v122[1] = 0.0078125;
  v122[2] = 0.0078125;
  v122[3] = 0.0078125;
  v115 = *(float *)(v4 + 56);
  if ( unk_12FB790 )
    return 0;
  v110 = a1 + *(_DWORD *)(a1 + 8);
  v5 = *(float **)(a2 + 32);
  v6 = v5[12];
  v113 = *(_DWORD *)(a1 + 4);
  v112 = v6 / v5[15] - 2048.0 + 256.0;
  v7 = v5[13] / v5[15];
  LODWORD(v120) = *(unsigned __int8 *)(a2 + 24);
  LODWORD(v8) = *(unsigned __int8 *)(a2 + 25);
  v111 = v7 - 2048.0 + 208.0;
  v9 = (double)SLODWORD(v120);
  v120 = v8;
  LODWORD(v10) = *(unsigned __int8 *)(a2 + 26);
  v123 = v9;
  v11 = (double)SLODWORD(v120);
  v120 = v10;
  v12 = *(unsigned __int8 *)(a2 + 27);
  v124 = v11;
  v13 = (double)SLODWORD(v120);
  v120 = *(float *)&v12;
  v125 = v13;
  v126 = (float)v12;
  sub_6ED710(&v123, v122, &v123);
  sub_640F60(&v107, &v108);
  v120 = (float)v107;
  v14 = v120;
  v118 = 0.001953125 * v120;
  v120 = (float)v108;
  v15 = *(_DWORD *)(a2 + 32);
  v116 = v120 / 416.0;
  v119 = *(float *)(v15 + 44);
  v16 = v119;
  if ( 0.0 == v119 )
  {
    v119 = 1.0;
    v16 = (float)1.0;
  }
  v117 = v16 * (v116 * 4.0) / (v118 * 3.0);
  v109 = v14 * 0.5;
  v120 = 0.5 * v120;
  v17 = sub_639180("NoTexture", 7);
  if ( a4 < 0 )
  {
    v114 = *(_DWORD *)(v17 + 148);
    HIDWORD(v121) = *(unsigned __int8 *)(v113 + a1 + 16);
    v75 = (double)SHIDWORD(v121);
    HIDWORD(v121) = *(unsigned __int8 *)(v113 + a1 + 17);
    v76 = *(unsigned __int8 *)(v113 + a1 + 18);
    v127 = v75;
    v77 = (double)SHIDWORD(v121);
    HIDWORD(v121) = v76;
    v78 = *(unsigned __int8 *)(v113 + a1 + 19);
    v128 = v77;
    v79 = (double)SHIDWORD(v121);
    HIDWORD(v121) = v78;
    v80 = *(unsigned __int8 *)(v113 + a1 + 20);
    v129 = v79;
    v81 = (double)SHIDWORD(v121);
    HIDWORD(v121) = v80;
    v82 = *(unsigned __int8 *)(v113 + a1 + 21);
    v130 = v81;
    v83 = (double)SHIDWORD(v121);
    HIDWORD(v121) = v82;
    v84 = *(unsigned __int8 *)(v113 + a1 + 22);
    v131 = v83;
    v85 = (double)SHIDWORD(v121);
    HIDWORD(v121) = v84;
    v86 = *(unsigned __int8 *)(v113 + a1 + 23);
    v132 = v85;
    v87 = (double)SHIDWORD(v121);
    HIDWORD(v121) = v86;
    v88 = *(unsigned __int8 *)(v113 + a1 + 24);
    v133 = v87;
    v89 = 4 * (7 * a3 - a4) - 4;
    v134 = (float)SHIDWORD(v121);
    *((float *)&v121 + 1) = (float)v88;
    v90 = *((float *)&v121 + 1);
    HIDWORD(v121) = *(unsigned __int8 *)(v113 + a1 + 25);
    v135 = v90;
    *((float *)&v121 + 1) = (float)SHIDWORD(v121);
    v91 = *((float *)&v121 + 1);
    HIDWORD(v121) = *(unsigned __int8 *)(v113 + a1 + 26);
    v136 = v91;
    *((float *)&v121 + 1) = (float)SHIDWORD(v121);
    v92 = *((float *)&v121 + 1);
    HIDWORD(v121) = *(unsigned __int8 *)(v113 + a1 + 27);
    v137 = v92;
    *((float *)&v121 + 1) = (float)SHIDWORD(v121);
    v138 = *((float *)&v121 + 1);
    v142 = *((float *)&v121 + 1);
    v139 = v90;
    v140 = v91;
    v141 = v92;
    sub_6ED710(&v127, &v123, &v127);
    sub_6ED710(&v131, &v123, &v131);
    sub_6ED710(&v135, &v123, &v135);
    sub_6ED710(&v139, &v123, &v139);
    v93 = v114;
    v94 = *(_DWORD *)(v114 + 20);
    v95 = 3 * v89;
    *(float *)(v94 + 16 * v89) = v127 / 255.0;
    *(float *)(v94 + 16 * v89 + 4) = v128 / 255.0;
    *(float *)(v94 + 16 * v89 + 8) = v129 / 255.0;
    *(float *)(v94 + 16 * v89 + 12) = v130 / 255.0;
    *(float *)(v94 + 16 * v89 + 16) = v131 / 255.0;
    *(float *)(v94 + 16 * v89 + 20) = v132 / 255.0;
    *(float *)(v94 + 16 * v89 + 24) = v133 / 255.0;
    *(float *)(v94 + 16 * v89 + 28) = v134 / 255.0;
    *(float *)(v94 + 16 * v89 + 32) = v135 / 255.0;
    *(float *)(v94 + 16 * v89 + 36) = v136 / 255.0;
    *(float *)(v94 + 16 * v89 + 40) = v137 / 255.0;
    *(float *)(v94 + 16 * v89 + 44) = v138 / 255.0;
    *(float *)(v94 + 16 * v89 + 48) = v139 / 255.0;
    *(float *)(v94 + 16 * v89 + 52) = v140 / 255.0;
    *(float *)(v94 + 16 * v89 + 56) = v141 / 255.0;
    *(float *)(v94 + 16 * v89 + 60) = v142 / 255.0;
    if ( !*(_BYTE *)(a2 + 27) )
    {
      v96 = *(_DWORD *)(v93 + 12);
      *(float *)(v96 + 12 * v89) = -10000.0;
      *(float *)(v96 + 12 * v89 + 4) = -10000.0;
      v97 = v115;
      *(float *)(v96 + 12 * v89 + 8) = v115;
      *(float *)(v96 + 12 * v89 + 12) = -10000.0;
      *(float *)(v96 + 12 * v89 + 16) = -10000.0;
      *(float *)(v96 + 12 * v89 + 20) = v97;
      *(float *)(v96 + 12 * v89 + 24) = -10000.0;
      *(float *)(v96 + 12 * v89 + 28) = -10000.0;
      *(float *)(v96 + 12 * v89 + 32) = v97;
      *(float *)(v96 + 12 * v89 + 36) = -10000.0;
      *(float *)(v96 + 12 * v89 + 40) = -10000.0;
      *(float *)(v96 + 12 * v89 + 44) = v97;
      return 0;
    }
    v98 = v113;
    v99 = v110;
    v100 = *(_DWORD *)(v93 + 12);
    HIDWORD(v121) = *(__int16 *)(v110 + 6 * *(unsigned __int16 *)(v113 + a1 + 30));
    v121 = (double)SHIDWORD(v121);
    v101 = v112;
    v102 = v109;
    *(float *)(v100 + 4 * v95) = (v121 * v117 + v112) * v118 - v109;
    HIDWORD(v121) = *(__int16 *)(v99 + 6 * *(unsigned __int16 *)(v98 + a1 + 30) + 2);
    v121 = (double)SHIDWORD(v121);
    v103 = v111;
    v104 = v120;
    *(float *)(v100 + 4 * v95 + 4) = (v121 * v119 + v111) * v116 - v120;
    v105 = v115;
    *(float *)(v100 + 4 * v95 + 8) = v115;
    HIDWORD(v121) = *(__int16 *)(v99 + 6 * *(unsigned __int16 *)(v98 + a1 + 32));
    v121 = (double)SHIDWORD(v121);
    *(float *)(v100 + 4 * v95 + 12) = (v101 - v121 * v117) * v118 - v102;
    HIDWORD(v121) = *(__int16 *)(v99 + 6 * *(unsigned __int16 *)(v98 + a1 + 32) + 2);
    v121 = (double)SHIDWORD(v121);
    v106 = v116;
    *(float *)(v100 + 4 * v95 + 16) = (v103 - v121 * v119) * v116 - v104;
    *(float *)(v100 + 4 * v95 + 20) = v105;
    HIDWORD(v121) = *(__int16 *)(v99 + 6 * *(unsigned __int16 *)(v98 + a1 + 32));
    v121 = (double)SHIDWORD(v121);
    *(float *)(v100 + 4 * v95 + 24) = (v121 * v117 + v101) * v118 - v102;
    HIDWORD(v121) = *(__int16 *)(v99 + 6 * *(unsigned __int16 *)(v98 + a1 + 32) + 2);
    v121 = (double)SHIDWORD(v121);
    *(float *)(v100 + 4 * v95 + 28) = v106 * (v121 * v119 + v103) - v104;
    *(float *)(v100 + 4 * v95 + 32) = v105;
    HIDWORD(v121) = *(__int16 *)(v99 + 6 * *(unsigned __int16 *)(v98 + a1 + 30));
    v121 = (double)SHIDWORD(v121);
    *(float *)(v100 + 4 * v95 + 36) = (v101 - v121 * v117) * v118 - v102;
    v121 = (double)*(__int16 *)(v99 + 6 * *(unsigned __int16 *)(v98 + a1 + 30) + 2);
    *(float *)(v100 + 4 * v95 + 40) = (v103 - v121 * v119) * v116 - v104;
    *(float *)(v100 + 4 * v95 + 44) = v105;
    return 0;
  }
  v18 = *(_DWORD **)(v17 + 148);
  v143 = 4 * (a4 + 7 * a3);
  v114 = v143;
  v19 = 4 * v143;
  HIDWORD(v121) = *(unsigned __int8 *)(v113 + a1 + 16);
  v20 = (double)SHIDWORD(v121);
  HIDWORD(v121) = *(unsigned __int8 *)(v113 + a1 + 17);
  v21 = *(unsigned __int8 *)(v113 + a1 + 18);
  v127 = v20;
  v22 = (double)SHIDWORD(v121);
  HIDWORD(v121) = v21;
  v23 = *(unsigned __int8 *)(v113 + a1 + 19);
  v128 = v22;
  v24 = (double)SHIDWORD(v121);
  HIDWORD(v121) = v23;
  v25 = *(unsigned __int8 *)(v113 + a1 + 20);
  v129 = v24;
  v26 = (double)SHIDWORD(v121);
  HIDWORD(v121) = v25;
  v27 = *(unsigned __int8 *)(v113 + a1 + 21);
  v130 = v26;
  v28 = (double)SHIDWORD(v121);
  HIDWORD(v121) = v27;
  v29 = *(unsigned __int8 *)(v113 + a1 + 22);
  v131 = v28;
  v30 = (double)SHIDWORD(v121);
  HIDWORD(v121) = v29;
  v31 = *(unsigned __int8 *)(v113 + a1 + 23);
  v132 = v30;
  v32 = (double)SHIDWORD(v121);
  HIDWORD(v121) = v31;
  v33 = *(unsigned __int8 *)(v113 + a1 + 24);
  v133 = v32;
  v134 = (float)SHIDWORD(v121);
  *((float *)&v121 + 1) = (float)v33;
  v34 = *((float *)&v121 + 1);
  HIDWORD(v121) = *(unsigned __int8 *)(v113 + a1 + 25);
  v135 = v34;
  *((float *)&v121 + 1) = (float)SHIDWORD(v121);
  v35 = *((float *)&v121 + 1);
  HIDWORD(v121) = *(unsigned __int8 *)(v113 + a1 + 26);
  v136 = v35;
  *((float *)&v121 + 1) = (float)SHIDWORD(v121);
  v36 = *((float *)&v121 + 1);
  HIDWORD(v121) = *(unsigned __int8 *)(v113 + a1 + 27);
  v137 = v36;
  *((float *)&v121 + 1) = (float)SHIDWORD(v121);
  v138 = *((float *)&v121 + 1);
  v142 = *((float *)&v121 + 1);
  v139 = v34;
  v140 = v35;
  v141 = v36;
  sub_6ED710(&v127, &v123, &v127);
  sub_6ED710(&v131, &v123, &v131);
  sub_6ED710(&v135, &v123, &v135);
  sub_6ED710(&v139, &v123, &v139);
  v37 = v18[5];
  *((float *)&v121 + 1) = v127 / 255.0;
  *(float *)(v37 + 4 * v19) = *((float *)&v121 + 1);
  v38 = v18[5];
  *((float *)&v121 + 1) = v128 / 255.0;
  *(float *)(v38 + 4 * v19 + 4) = *((float *)&v121 + 1);
  v39 = v18[5];
  *((float *)&v121 + 1) = v129 / 255.0;
  *(float *)(v39 + 4 * v19 + 8) = *((float *)&v121 + 1);
  v40 = v18[5];
  *((float *)&v121 + 1) = v130 / 255.0;
  *(float *)(v40 + 4 * v19 + 12) = *((float *)&v121 + 1);
  v41 = v18[5];
  *((float *)&v121 + 1) = v131 / 255.0;
  *(float *)(v41 + 4 * v19 + 16) = *((float *)&v121 + 1);
  v42 = v18[5];
  *((float *)&v121 + 1) = v132 / 255.0;
  *(float *)(v42 + 4 * v19 + 20) = *((float *)&v121 + 1);
  v43 = v18[5];
  *((float *)&v121 + 1) = v133 / 255.0;
  *(float *)(v43 + 4 * v19 + 24) = *((float *)&v121 + 1);
  v44 = v18[5];
  *((float *)&v121 + 1) = v134 / 255.0;
  *(float *)(v44 + 4 * v19 + 28) = *((float *)&v121 + 1);
  *((float *)&v121 + 1) = v135 / 255.0;
  *(float *)(v18[5] + 4 * v19 + 32) = *((float *)&v121 + 1);
  v45 = v18[5];
  *((float *)&v121 + 1) = v136 / 255.0;
  *(float *)(v45 + 4 * v19 + 36) = *((float *)&v121 + 1);
  v46 = v18[5];
  *((float *)&v121 + 1) = v137 / 255.0;
  *(float *)(v46 + 4 * v19 + 40) = *((float *)&v121 + 1);
  v47 = v18[5];
  *((float *)&v121 + 1) = v138 / 255.0;
  *(float *)(v47 + 4 * v19 + 44) = *((float *)&v121 + 1);
  v48 = v18[5];
  *((float *)&v121 + 1) = v139 / 255.0;
  *(float *)(v48 + 4 * v19 + 48) = *((float *)&v121 + 1);
  v49 = v18[5];
  *((float *)&v121 + 1) = v140 / 255.0;
  *(float *)(v49 + 4 * v19 + 52) = *((float *)&v121 + 1);
  v50 = v18[5];
  *((float *)&v121 + 1) = v141 / 255.0;
  *(float *)(v50 + 4 * v19 + 56) = *((float *)&v121 + 1);
  v51 = v18[5];
  *((float *)&v121 + 1) = v142 / 255.0;
  *(float *)(v51 + 4 * v19 + 60) = *((float *)&v121 + 1);
  v52 = 3 * v114;
  if ( *(_BYTE *)(a2 + 27) )
  {
    v57 = v113;
    v58 = v110;
    HIDWORD(v121) = *(__int16 *)(v110 + 6 * *(unsigned __int16 *)(v113 + a1 + 30));
    v121 = (double)SHIDWORD(v121);
    v59 = v18[3];
    v60 = v112;
    v61 = v109;
    *((float *)&v121 + 1) = (v121 * v117 + v112) * v118 - v109;
    *(float *)(v59 + 12 * v114) = *((float *)&v121 + 1);
    HIDWORD(v121) = *(__int16 *)(v58 + 6 * *(unsigned __int16 *)(v57 + a1 + 30) + 2);
    v121 = (double)SHIDWORD(v121);
    v62 = v18[3];
    v63 = v111;
    v64 = v120;
    *((float *)&v121 + 1) = (v121 * v119 + v111) * v116 - v120;
    *(float *)(v62 + 4 * v52 + 4) = *((float *)&v121 + 1);
    v65 = v115;
    *(float *)(v18[3] + 4 * v52 + 8) = v115;
    HIDWORD(v121) = *(__int16 *)(v58 + 6 * *(unsigned __int16 *)(v57 + a1 + 32));
    v121 = (double)SHIDWORD(v121);
    v66 = v18[3];
    *((float *)&v121 + 1) = (v60 - v121 * v117) * v118 - v61;
    *(float *)(v66 + 4 * v52 + 12) = *((float *)&v121 + 1);
    HIDWORD(v121) = *(__int16 *)(v58 + 6 * *(unsigned __int16 *)(v57 + a1 + 32) + 2);
    v121 = (double)SHIDWORD(v121);
    v67 = v116;
    *((float *)&v121 + 1) = (v63 - v121 * v119) * v116 - v64;
    *(float *)(v18[3] + 4 * v52 + 16) = *((float *)&v121 + 1);
    *(float *)(v18[3] + 4 * v52 + 20) = v65;
    HIDWORD(v121) = *(__int16 *)(v58 + 6 * *(unsigned __int16 *)(v57 + a1 + 32));
    v121 = (double)SHIDWORD(v121);
    v68 = v18[3];
    *((float *)&v121 + 1) = (v121 * v117 + v60) * v118 - v61;
    *(float *)(v68 + 4 * v52 + 24) = *((float *)&v121 + 1);
    HIDWORD(v121) = *(__int16 *)(v58 + 6 * *(unsigned __int16 *)(v57 + a1 + 32) + 2);
    v121 = (double)SHIDWORD(v121);
    v69 = v18[3];
    *((float *)&v121 + 1) = v67 * (v121 * v119 + v63) - v64;
    *(float *)(v69 + 4 * v52 + 28) = *((float *)&v121 + 1);
    *(float *)(v18[3] + 4 * v52 + 32) = v65;
    HIDWORD(v121) = *(__int16 *)(v58 + 6 * *(unsigned __int16 *)(v57 + a1 + 30));
    v121 = (double)SHIDWORD(v121);
    v70 = v18[3];
    *((float *)&v121 + 1) = (v60 - v121 * v117) * v118 - v61;
    *(float *)(v70 + 4 * v52 + 36) = *((float *)&v121 + 1);
    HIDWORD(v121) = *(__int16 *)(v58 + 6 * *(unsigned __int16 *)(v57 + a1 + 30) + 2);
    v121 = (double)SHIDWORD(v121);
    v56 = v65;
    *((float *)&v121 + 1) = (v63 - v121 * v119) * v116 - v64;
    v55 = *((float *)&v121 + 1);
  }
  else
  {
    *(float *)(v18[3] + 12 * v114) = -10000.0;
    *(float *)(v18[3] + 4 * v52 + 4) = -10000.0;
    v53 = v115;
    *(float *)(v18[3] + 4 * v52 + 8) = v115;
    *(float *)(v18[3] + 4 * v52 + 12) = -10000.0;
    *(float *)(v18[3] + 4 * v52 + 16) = -10000.0;
    *(float *)(v18[3] + 4 * v52 + 20) = v53;
    *(float *)(v18[3] + 4 * v52 + 24) = -10000.0;
    *(float *)(v18[3] + 4 * v52 + 28) = -10000.0;
    *(float *)(v18[3] + 4 * v52 + 32) = v53;
    v54 = v53;
    v55 = -10000.0;
    v56 = v54;
    *(float *)(v18[3] + 4 * v52 + 36) = -10000.0;
  }
  *(float *)(v18[3] + 4 * v52 + 40) = v55;
  *(float *)(v18[3] + 4 * v52 + 44) = v56;
  *(float *)(v18[4] + 4 * v52) = 0.0;
  *(float *)(v18[4] + 4 * v52 + 4) = 0.0;
  *(float *)(v18[4] + 4 * v52 + 8) = 1.0;
  *(float *)(v18[4] + 4 * v52 + 12) = 0.0;
  *(float *)(v18[4] + 4 * v52 + 16) = 0.0;
  *(float *)(v18[4] + 4 * v52 + 20) = 1.0;
  *(float *)(v18[4] + 4 * v52 + 24) = 0.0;
  *(float *)(v18[4] + 4 * v52 + 28) = 0.0;
  *(float *)(v18[4] + 4 * v52 + 32) = 1.0;
  *(float *)(v18[4] + 4 * v52 + 36) = 0.0;
  *(float *)(v18[4] + 4 * v52 + 40) = 0.0;
  *(float *)(v18[4] + 4 * v52 + 44) = 1.0;
  *((float *)&v121 + 1) = (float)v143;
  v71 = (int)(*((float *)&v121 + 1) * 1.5);
  v72 = v114;
  v73 = v114 + 1;
  *(_WORD *)(v18[7] + 2 * v71) = v114;
  *(_WORD *)(v18[7] + 2 * v71 + 2) = v73;
  *(_WORD *)(v18[7] + 2 * v71 + 4) = v72 + 2;
  *(_WORD *)(v18[7] + 2 * v71 + 6) = v72 + 2;
  *(_WORD *)(v18[7] + 2 * v71 + 8) = v73;
  *(_WORD *)(v18[7] + 2 * v71 + 10) = v72 + 3;
  v18[1] += 4;
  v18[2] += 6;
  return 0;
}

