// Function: sub_A10DD0
// Address: 0xa10dd0
// Size: 0x162f
// Prototype: int __cdecl(int, int, char, char, float, char)

unsigned int __cdecl sub_A10DD0(unsigned int *a1, int a2, char a3, char a4, float a5, char a6)
{
  float *v6; // esi
  unsigned __int8 *v7; // edi
  int n16; // ebx
  double i; // st7
  double v10; // st6
  float *v11; // eax
  float *v12; // eax
  float *v13; // ecx
  int n16_1; // edx
  double v15; // st7
  double v16; // st6
  double v17; // st5
  float *v18; // ecx
  int n16_2; // edx
  double v20; // st7
  double v21; // st6
  float v22; // esi
  float v23; // edi
  float v24; // ecx
  float v25; // eax
  float v26; // eax
  float v27; // eax
  double v28; // st7
  double v29; // st6
  double v30; // st5
  double v31; // st4
  double v32; // st3
  float *v33; // ebx
  int n16_3; // edx
  double v35; // rt1
  double v36; // st3
  double v37; // st6
  int n2_1; // esi
  int n2; // ecx
  double v40; // st3
  double v41; // st3
  char v42; // cl
  float v43; // eax
  _DWORD *v44; // edx
  unsigned int v45; // ebx
  int n4; // esi
  _DWORD *v47; // edi
  int v48; // edx
  int v49; // eax
  int v50; // edx
  int v51; // eax
  char n4_1; // cl
  unsigned int v53; // ecx
  unsigned int v54; // ebx
  int n16_4; // esi
  float *v56; // edx
  double v57; // st7
  double v58; // st6
  double v59; // st4
  int n2_2; // ecx
  double v61; // st3
  unsigned int v62; // edi
  int n33; // ecx
  char *v64; // edx
  int v65; // eax
  double v66; // st5
  double v67; // st7
  double v68; // st2
  double v69; // st4
  double v70; // st7
  unsigned int v71; // esi
  unsigned int v72; // edx
  unsigned int v73; // esi
  unsigned int v74; // ecx
  int v75; // eax
  unsigned int *v76; // edx
  unsigned int result; // eax
  unsigned int *v78; // ecx
  float v79; // [esp+0h] [ebp-310h]
  float v80; // [esp+4h] [ebp-30Ch]
  float v81; // [esp+8h] [ebp-308h]
  float v82; // [esp+14h] [ebp-2FCh]
  float v83; // [esp+18h] [ebp-2F8h]
  float v84; // [esp+20h] [ebp-2F0h]
  float v85; // [esp+24h] [ebp-2ECh]
  float v86; // [esp+28h] [ebp-2E8h]
  float v87; // [esp+30h] [ebp-2E0h] BYREF
  float v88; // [esp+34h] [ebp-2DCh]
  float v89; // [esp+38h] [ebp-2D8h]
  float v90; // [esp+40h] [ebp-2D0h] BYREF
  float v91; // [esp+44h] [ebp-2CCh]
  float v92; // [esp+48h] [ebp-2C8h]
  float v93; // [esp+50h] [ebp-2C0h]
  float v94; // [esp+54h] [ebp-2BCh]
  float v95; // [esp+58h] [ebp-2B8h]
  float v96; // [esp+5Ch] [ebp-2B4h]
  float v97; // [esp+60h] [ebp-2B0h]
  float v98; // [esp+64h] [ebp-2ACh]
  float v99; // [esp+68h] [ebp-2A8h]
  float v100; // [esp+6Ch] [ebp-2A4h]
  float v101; // [esp+70h] [ebp-2A0h]
  float v102; // [esp+74h] [ebp-29Ch] BYREF
  float v103; // [esp+78h] [ebp-298h]
  float v104; // [esp+7Ch] [ebp-294h]
  float v105; // [esp+84h] [ebp-28Ch] BYREF
  float v106; // [esp+88h] [ebp-288h]
  float v107; // [esp+8Ch] [ebp-284h]
  unsigned int *v108; // [esp+94h] [ebp-27Ch]
  float v109; // [esp+98h] [ebp-278h]
  float v110; // [esp+9Ch] [ebp-274h]
  float v111; // [esp+A0h] [ebp-270h]
  float v112; // [esp+A4h] [ebp-26Ch]
  float v113; // [esp+A8h] [ebp-268h]
  float v114; // [esp+ACh] [ebp-264h]
  float v115; // [esp+B0h] [ebp-260h]
  float v116; // [esp+B4h] [ebp-25Ch]
  float v117; // [esp+B8h] [ebp-258h] BYREF
  float v118; // [esp+BCh] [ebp-254h]
  float v119; // [esp+C0h] [ebp-250h]
  float v120; // [esp+C4h] [ebp-24Ch]
  float v121; // [esp+C8h] [ebp-248h]
  float v122; // [esp+CCh] [ebp-244h] BYREF
  float v123; // [esp+D0h] [ebp-240h]
  float v124; // [esp+D4h] [ebp-23Ch]
  float v125; // [esp+D8h] [ebp-238h]
  float v126; // [esp+DCh] [ebp-234h]
  float v127; // [esp+E0h] [ebp-230h]
  float v128; // [esp+E4h] [ebp-22Ch]
  float v129; // [esp+E8h] [ebp-228h]
  float v130; // [esp+ECh] [ebp-224h]
  float v131; // [esp+F0h] [ebp-220h]
  float v132; // [esp+F4h] [ebp-21Ch] BYREF
  float v133; // [esp+F8h] [ebp-218h]
  float v134; // [esp+FCh] [ebp-214h]
  float v135; // [esp+100h] [ebp-210h]
  float v136; // [esp+104h] [ebp-20Ch]
  float v137; // [esp+108h] [ebp-208h]
  float v138; // [esp+10Ch] [ebp-204h]
  float v139; // [esp+110h] [ebp-200h]
  float v140; // [esp+114h] [ebp-1FCh]
  char v141; // [esp+11Bh] [ebp-1F5h]
  float v142; // [esp+11Ch] [ebp-1F4h]
  float v143; // [esp+120h] [ebp-1F0h]
  float v144; // [esp+124h] [ebp-1ECh]
  __int64 v145; // [esp+128h] [ebp-1E8h]
  char v146; // [esp+138h] [ebp-1D8h] BYREF
  char v147; // [esp+13Ch] [ebp-1D4h] BYREF
  _DWORD v148[16]; // [esp+230h] [ebp-E0h] BYREF
  _DWORD v149[16]; // [esp+270h] [ebp-A0h] BYREF
  _DWORD v150[4]; // [esp+2B0h] [ebp-60h]
  int v151; // [esp+2C0h] [ebp-50h]
  char v152; // [esp+2C4h] [ebp-4Ch] BYREF
  float v153[2]; // [esp+2F0h] [ebp-20h]
  float v154; // [esp+2F8h] [ebp-18h]
  float v155[2]; // [esp+2FCh] [ebp-14h]
  float v156; // [esp+304h] [ebp-Ch]
  float v157; // [esp+308h] [ebp-8h]

  v108 = a1;
  if ( !a3 || (v141 = 1, a4) )
    v141 = 0;
  v122 = 3.4028235e38;
  v123 = 3.4028235e38;
  v124 = 3.4028235e38;
  v125 = 3.4028235e38;
  v6 = (float *)&v146;
  v7 = (unsigned __int8 *)(a2 + 2);
  v117 = -3.4028235e38;
  n16 = 16;
  v118 = -3.4028235e38;
  v119 = -3.4028235e38;
  v120 = -3.4028235e38;
  v136 = 0.0;
  v137 = 0.0;
  v138 = 0.0;
  v139 = 0.0;
  for ( i = 0.003921568859368563; ; i = 0.003921568859368563 )
  {
    LODWORD(v144) = *(v7 - 2);
    v144 = (float)SLODWORD(v144);
    v10 = v144 * i;
    LODWORD(v144) = *(v7 - 1);
    v132 = v10;
    *(double *)&v145 = (double)SLODWORD(v144);
    LODWORD(v144) = *v7;
    v133 = *(double *)&v145 * i;
    *(double *)&v145 = (double)SLODWORD(v144);
    LODWORD(v144) = v7[1];
    v134 = *(double *)&v145 * i;
    *(double *)&v145 = (double)SLODWORD(v144);
    v135 = i * *(double *)&v145;
    *(v6 - 2) = v132;
    *(v6 - 1) = v133;
    *v6 = v134;
    v6[1] = v135;
    v11 = (float *)sub_A1B620(&v90, &v122, &v132);
    v122 = *v11;
    v123 = v11[1];
    v124 = v11[2];
    v125 = v11[3];
    v12 = (float *)sub_A1B560(&v87, &v117, &v132);
    v117 = *v12;
    v118 = v12[1];
    v119 = v12[2];
    v120 = v12[3];
    v128 = v132 + v136;
    v129 = v133 + v137;
    v130 = v134 + v138;
    v131 = v135 + v139;
    v136 = v128;
    v137 = v129;
    v6 += 4;
    v7 += 4;
    v138 = v130;
    v139 = v131;
    if ( !--n16 )
      break;
  }
  if ( a6 )
  {
    v132 = v117 - v122;
    v133 = v118 - v123;
    v134 = v119 - v124;
    v144 = v132 * v132;
    v144 = v144 + v133 * v133;
    v144 = v144 + v134 * v134;
    if ( v144 <= 0.00009999999747378752 )
      goto LABEL_19;
    v13 = (float *)&v146;
    n16_1 = 16;
    v144 = v128 * 0.0625;
    v140 = v129 * 0.0625;
    v126 = 0.0625 * v130;
    v136 = v144;
    v137 = v140;
    v138 = v126;
    v126 = 0.0;
    v143 = 0.0;
    v127 = 0.0;
    v140 = 0.0;
    v121 = 0.0;
    v144 = 0.0;
    v15 = v138;
    v16 = v137;
    v17 = v136;
    do
    {
      v128 = *(v13 - 2);
      v129 = *(v13 - 1);
      v130 = *v13;
      v136 = v128 - v17;
      v137 = v129 - v16;
      v138 = v130 - v15;
      v99 = v136;
      v94 = v136;
      v100 = v136;
      v142 = v136 * v136;
      v126 = v142 + v126;
      v95 = v137;
      v93 = v136;
      v96 = v136;
      v142 = v136 * v137;
      v143 = v142 + v143;
      v101 = v138;
      v98 = v136;
      v97 = v136;
      v142 = v136 * v138;
      v127 = v142 + v127;
      v109 = v137;
      v111 = v137;
      v110 = v137;
      v142 = v137 * v137;
      v140 = v142 + v140;
      v113 = v138;
      v116 = v137;
      v112 = v137;
      v142 = v137 * v138;
      v13 += 4;
      v121 = v142 + v121;
      v114 = v138;
      v115 = v138;
      *((float *)&v145 + 1) = v138;
      v142 = v138 * v138;
      v144 = v142 + v144;
      --n16_1;
    }
    while ( n16_1 );
    v136 = v134 * v127 + v132 * v126 + v133 * v143;
    v137 = v134 * v121 + v143 * v132 + v133 * v140;
    v138 = v134 * v144 + v121 * v133 + v132 * v127;
    v132 = v136;
    v133 = v137;
    v136 = v126 * v136 + v137 * v143 + v138 * v127;
    v137 = v138 * v121 + v137 * v140 + v132 * v143;
    v138 = v138 * v144 + v121 * v133 + v132 * v127;
    v132 = v136;
    v133 = v137;
    v136 = v136 * v126 + v137 * v143 + v138 * v127;
    v137 = v138 * v121 + v137 * v140 + v132 * v143;
    v138 = v138 * v144 + v121 * v133 + v132 * v127;
    v132 = v136;
    v133 = v137;
    v136 = v136 * v126 + v137 * v143 + v138 * v127;
    v137 = v138 * v121 + v140 * v137 + v132 * v143;
    v138 = v121 * v133 + v132 * v127 + v144 * v138;
    *((float *)&v145 + 1) = v136 * v136;
    *((float *)&v145 + 1) = *((float *)&v145 + 1) + v137 * v137;
    *((float *)&v145 + 1) = *((float *)&v145 + 1) + v138 * v138;
    *((float *)&v145 + 1) = sqrt(*((float *)&v145 + 1));
    if ( *((float *)&v145 + 1) <= 0.0000000099999999 )
    {
LABEL_19:
      v21 = v122;
      v20 = v123;
      goto LABEL_20;
    }
    v18 = (float *)&v146;
    v140 = -3.4028235e38;
    n16_2 = 16;
    v144 = 3.4028235e38;
    do
    {
      v128 = *(v18 - 2);
      v129 = *(v18 - 1);
      v130 = *v18;
      *((float *)&v145 + 1) = v128 * v136;
      *((float *)&v145 + 1) = *((float *)&v145 + 1) + v129 * v137;
      *((float *)&v145 + 1) = *((float *)&v145 + 1) + v130 * v138;
      if ( v144 > (double)*((float *)&v145 + 1) )
      {
        v144 = *((float *)&v145 + 1);
        v122 = *(v18 - 2);
        v123 = *(v18 - 1);
        v124 = *v18;
        v125 = v18[1];
      }
      if ( v140 < (double)*((float *)&v145 + 1) )
      {
        v140 = *((float *)&v145 + 1);
        v117 = *(v18 - 2);
        v118 = *(v18 - 1);
        v119 = *v18;
        v120 = v18[1];
      }
      v18 += 4;
      --n16_2;
    }
    while ( n16_2 );
  }
  v20 = v123;
  v21 = v122;
LABEL_20:
  v102 = v21;
  v103 = v20;
  v104 = v124;
  v22 = COERCE_FLOAT(sub_A0FC10((int)&v102));
  v105 = v117;
  v106 = v118;
  v127 = v22;
  v107 = v119;
  v23 = COERCE_FLOAT(sub_A0FC10((int)&v105));
  if ( __ROL2__(LOWORD(v22), 8) <= __ROL2__(LOWORD(v23), 8) )
  {
    v30 = v119;
    v32 = v117;
    v28 = v123;
    v29 = v122;
    v31 = v118;
  }
  else
  {
    v24 = v122;
    v122 = v117;
    v25 = v123;
    v123 = v118;
    v129 = v25;
    v26 = v124;
    v124 = v119;
    v130 = v26;
    v27 = v125;
    v125 = v120;
    v128 = v24;
    v131 = v27;
    v117 = v24;
    v118 = v129;
    v127 = v23;
    v23 = v22;
    v119 = v130;
    v120 = v27;
    v28 = v123;
    v29 = v122;
    v30 = v130;
    v31 = v129;
    v32 = v24;
  }
  HIBYTE(v143) = 0;
  v128 = v32 + v29;
  v129 = v31 + v28;
  v130 = v30 + v124;
  v79 = v128 * 0.5;
  v80 = v129 * 0.5;
  v81 = 0.5 * v130;
  v132 = v32 * 0.6666659712791443;
  v133 = v31 * 0.6666659712791443;
  v134 = v30 * 0.6666659712791443;
  v128 = v29 * 0.3333300054073334;
  v129 = v28 * 0.3333300054073334;
  v130 = 0.3333300054073334 * v124;
  v90 = v128 + v132;
  v91 = v129 + v133;
  v92 = v130 + v134;
  v132 = v32 * 0.3333329856395721;
  v133 = v31 * 0.3333329856395721;
  v134 = 0.3333329856395721 * v30;
  v128 = v29 * 0.6666659712791443;
  v129 = v28 * 0.6666659712791443;
  v130 = 0.6666659712791443 * v124;
  v102 = v128 + v132;
  v103 = v129 + v133;
  v104 = v130 + v134;
  v126 = 0.0;
  v121 = 0.0;
  v33 = (float *)&v146;
  n16_3 = 0;
  while ( 1 )
  {
    v128 = *(v33 - 2);
    v129 = *(v33 - 1);
    v130 = *v33;
    v35 = v32;
    v36 = v128 - v29;
    v37 = v35;
    v132 = v36;
    v133 = v129 - v28;
    v134 = v130 - v124;
    *((float *)&v145 + 1) = v132 * v132;
    *((float *)&v145 + 1) = *((float *)&v145 + 1) + v133 * v133;
    v144 = *((float *)&v145 + 1) + v134 * v134;
    v136 = *(v33 - 2);
    v137 = *(v33 - 1);
    v138 = *v33;
    v84 = v136 - v35;
    v85 = v137 - v31;
    v86 = v138 - v30;
    *((float *)&v145 + 1) = v84 * v84;
    *((float *)&v145 + 1) = *((float *)&v145 + 1) + v85 * v85;
    v140 = *((float *)&v145 + 1) + v86 * v86;
    v82 = *(v33 - 1);
    v83 = *v33;
    v110 = *(v33 - 2) - v79;
    v111 = v82 - v80;
    v109 = v83 - v81;
    v87 = *(v33 - 2);
    v88 = *(v33 - 1);
    v89 = *v33;
    *((float *)&v145 + 1) = v87 - v90;
    v115 = v88 - v91;
    v114 = v89 - v92;
    v105 = *(v33 - 2);
    v106 = *(v33 - 1);
    v107 = *v33;
    v112 = v105 - v102;
    v116 = v106 - v103;
    v113 = v107 - v104;
    v155[0] = v140;
    v155[1] = v144;
    *((float *)&v145 + 1) = *((float *)&v145 + 1) * *((float *)&v145 + 1);
    *((float *)&v145 + 1) = *((float *)&v145 + 1) + v115 * v115;
    v156 = *((float *)&v145 + 1) + v114 * v114;
    *((float *)&v145 + 1) = v112 * v112;
    *((float *)&v145 + 1) = *((float *)&v145 + 1) + v116 * v116;
    v157 = *((float *)&v145 + 1) + v113 * v113;
    v153[0] = v144;
    v153[1] = v140;
    *((float *)&v145 + 1) = v110 * v110;
    *((float *)&v145 + 1) = *((float *)&v145 + 1) + v111 * v111;
    n2_1 = 0;
    v154 = *((float *)&v145 + 1) + v109 * v109;
    n2 = v140 > (double)v144;
    if ( v155[n2] > (double)v156 )
      n2 = 2;
    if ( v155[n2] > (double)v157 )
      n2 = 3;
    if ( v140 < (double)v144 )
      n2_1 = 1;
    if ( v153[n2_1] > (double)v154 )
      n2_1 = 2;
    if ( a5 > (double)v33[1] && v141 )
    {
      HIBYTE(v143) = 1;
      v149[n16_3] = 3;
    }
    v40 = v155[n2];
    v148[n16_3] = n2;
    v41 = v40 + v126;
    v149[n16_3++] = n2_1;
    v33 += 4;
    v126 = v41;
    v121 = v153[n2_1] + v121;
    if ( n16_3 >= 16 )
      break;
    v32 = v37;
    v29 = v122;
  }
  v42 = v121 > (double)v126;
  if ( HIBYTE(v143) )
    v42 = v141 != 0 ? 0 : v42;
  v43 = v127;
  if ( LODWORD(v127) == LODWORD(v23) || !v42 )
  {
    v44 = v149;
    LODWORD(v43) = LODWORD(v127) << 16;
  }
  else
  {
    v44 = v148;
    LODWORD(v23) <<= 16;
  }
  LODWORD(v140) = ((((unsigned int)(LODWORD(v43) | LODWORD(v23)) >> 16)
                  | (unsigned int)&unk_FF0000 & (LODWORD(v43) | LODWORD(v23))) >> 8)
                | (((LOWORD(v43) | LOWORD(v23)) & 0xFF00 | ((LODWORD(v43) | LODWORD(v23)) << 16)) << 8);
  v45 = 0;
  n4 = 4;
  v47 = v44 + 2;
  do
  {
    v48 = *(v47 - 2) << (n4 - 4);
    v49 = *(v47 - 1) << (n4 - 2);
    v47 += 4;
    v50 = v49 | v48;
    v51 = *(v47 - 3) << (n4 + 2);
    n4_1 = n4;
    n4 += 8;
    v45 |= (*(v47 - 4) << n4_1) | v51 | v50;
  }
  while ( n4 < 36 );
  v53 = ((HIWORD(v45) | (unsigned int)&unk_FF0000 & v45) >> 8) | ((v45 & 0xFF00 | (v45 << 16)) << 8);
  v54 = ((HIWORD(v53) | (unsigned int)&unk_FF0000 & v53) >> 8)
      | ((((HIWORD(v45) | (unsigned int)&unk_FF0000 & v45) >> 8) & 0xFF00
        | (unsigned __int16)((v45 & 0xFF00) << 8)
        | (v53 << 16)) << 8);
  if ( a4 )
  {
    n16_4 = 0;
    v56 = (float *)&v147;
    v115 = v125 * 0.8571428656578064 + v120 * 0.1428571492433548;
    v114 = v125 * 0.7142857313156128 + v120 * 0.2857142984867096;
    v112 = v125 * 0.5714285969734192 + v120 * 0.4285714328289032;
    v116 = 0.4285714328289032 * v125 + 0.5714285969734192 * v120;
    v57 = v125;
    v113 = 0.2857142984867096 * v125 + 0.7142857313156128 * v120;
    v58 = v120;
    *((float *)&v145 + 1) = 0.1428571492433548 * v125 + 0.8571428656578064 * v120;
    v59 = *((float *)&v145 + 1);
    do
    {
      n2_2 = 0;
      v143 = 3.4028235e38;
      *((float *)&v145 + 1) = *v56 - v57;
      *((float *)&v145 + 1) = fabs(*((float *)&v145 + 1));
      if ( *((float *)&v145 + 1) < 3.402823466385289e38 )
        v143 = *((float *)&v145 + 1);
      *((float *)&v145 + 1) = *v56 - v58;
      *((float *)&v145 + 1) = fabs(*((float *)&v145 + 1));
      if ( v143 <= (double)*((float *)&v145 + 1) )
      {
        v61 = v143;
      }
      else
      {
        n2_2 = 1;
        v143 = *((float *)&v145 + 1);
        v61 = *((float *)&v145 + 1);
      }
      *((float *)&v145 + 1) = *v56 - v115;
      *((float *)&v145 + 1) = fabs(*((float *)&v145 + 1));
      if ( *((float *)&v145 + 1) < v61 )
      {
        n2_2 = 2;
        v143 = *((float *)&v145 + 1);
        v61 = *((float *)&v145 + 1);
      }
      *((float *)&v145 + 1) = *v56 - v114;
      *((float *)&v145 + 1) = fabs(*((float *)&v145 + 1));
      if ( *((float *)&v145 + 1) < v61 )
      {
        n2_2 = 3;
        v143 = *((float *)&v145 + 1);
        v61 = *((float *)&v145 + 1);
      }
      *((float *)&v145 + 1) = *v56 - v112;
      *((float *)&v145 + 1) = fabs(*((float *)&v145 + 1));
      if ( *((float *)&v145 + 1) < v61 )
      {
        n2_2 = 4;
        v143 = *((float *)&v145 + 1);
        v61 = *((float *)&v145 + 1);
      }
      *((float *)&v145 + 1) = *v56 - v116;
      *((float *)&v145 + 1) = fabs(*((float *)&v145 + 1));
      if ( *((float *)&v145 + 1) < v61 )
      {
        n2_2 = 5;
        v143 = *((float *)&v145 + 1);
        v61 = *((float *)&v145 + 1);
      }
      *((float *)&v145 + 1) = *v56 - v113;
      *((float *)&v145 + 1) = fabs(*((float *)&v145 + 1));
      if ( *((float *)&v145 + 1) < v61 )
      {
        n2_2 = 6;
        v143 = *((float *)&v145 + 1);
        v61 = *((float *)&v145 + 1);
      }
      *((float *)&v145 + 1) = *v56 - v59;
      *((float *)&v145 + 1) = fabs(*((float *)&v145 + 1));
      if ( *((float *)&v145 + 1) < v61 )
        n2_2 = 7;
      v150[n16_4++] = n2_2;
      v56 += 4;
    }
    while ( n16_4 < 16 );
    v62 = v151 >> 2;
    n33 = 0;
    v64 = &v152;
    do
    {
      v65 = *(_DWORD *)v64 << n33;
      n33 += 3;
      v64 += 4;
      v62 |= v65;
    }
    while ( n33 < 33 );
    if ( v57 >= 1.0 )
    {
      v144 = 1.0;
      v67 = 1.0;
    }
    else
    {
      v66 = v57;
      v67 = 1.0;
      v144 = v66;
    }
    if ( v144 < 0.0 )
      v144 = 0.0;
    v68 = v144 * 255.0;
    v145 = (__int64)v68;
    if ( v58 < v67 )
      v67 = v58;
    v69 = v67;
    v70 = 0.0;
    v144 = v69;
    if ( v144 >= 0.0 )
      v70 = v144;
    v144 = v70;
    v145 = (__int64)(255.0 * v144);
    v71 = (__int64)v68
        | ((_DWORD)v145 << 8)
        | ((v150[0] | (8 * (v150[1] | (8 * (v150[2] | (8 * v150[3]))))) | (v151 << 12)) << 16);
    v72 = ((v71 & 0xFF00 | (v71 << 16)) << 8) | ((HIWORD(v71) | (unsigned int)&unk_FF0000 & v71) >> 8);
    v73 = ((v62 & 0xFF00 | (v62 << 16)) << 8) | ((HIWORD(v62) | (unsigned int)&unk_FF0000 & v62) >> 8);
    v74 = HIWORD(v72) | (unsigned int)&unk_FF0000 & v72;
    v75 = v72 & 0xFF00 | (v72 << 16);
    v76 = v108;
    *v108 = (v75 << 8) | (v74 >> 8);
    result = LODWORD(v140);
    v76[3] = v54;
    v76[1] = ((v73 & 0xFF00 | (v73 << 16)) << 8) | ((HIWORD(v73) | (unsigned int)&unk_FF0000 & v73) >> 8);
    v76[2] = result;
  }
  else
  {
    v78 = v108;
    result = LODWORD(v140);
    v108[1] = v54;
    *v78 = result;
  }
  return result;
}

