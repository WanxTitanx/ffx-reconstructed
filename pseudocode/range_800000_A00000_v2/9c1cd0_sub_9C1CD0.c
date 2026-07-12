// Function: sub_9C1CD0
// Address: 0x9c1cd0
double __userpurge sub_9C1CD0@<st0>(
        int a1@<ecx>,
        int a2@<ebp>,
        char a3@<efl>,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int i_2,
        int a10,
        int a11,
        int a12)
{
  int i_1; // esi
  int v13; // edi
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int i; // edi
  float v18; // ecx
  float v19; // edx
  int i_12; // ecx
  int j_1; // eax
  _DWORD *i_13; // edx
  int j; // esi
  int v24; // ecx
  int i_14; // eax
  _DWORD *v26; // eax
  int i_3; // ecx
  _DWORD *v28; // esi
  int j_3; // eax
  char *k_1; // eax
  int i_5; // ecx
  int v32; // edx
  int i_6; // ecx
  int k_2; // esi
  void *dst; // eax
  int k_3; // eax
  int i_7; // ecx
  int v38; // edx
  int *v39; // eax
  int v40; // edx
  int v41; // esi
  float v42; // ecx
  int j_4; // esi
  float v44; // eax
  _DWORD *v45; // ecx
  float *v46; // esi
  float v47; // edi
  float v48; // edx
  float v49; // eax
  double v50; // st7
  float v51; // xmm0_4
  float v52; // xmm0_4
  float v53; // ecx
  float *v54; // edi
  float v55; // edx
  int v56; // esi
  float *v57; // eax
  double v58; // st7
  float *v59; // eax
  double v60; // st7
  float *v61; // eax
  double v62; // rt0
  double v63; // st3
  double v64; // st6
  double v65; // st4
  double v66; // st7
  double v67; // st7
  double v68; // st7
  double v69; // st6
  double v70; // st7
  double v71; // st4
  double v72; // st6
  double v73; // st7
  int v74; // eax
  double v75; // st7
  int v76; // esi
  bool v77; // cf
  bool v78; // zf
  bool m; // sf
  bool v80; // of
  bool v81; // pf
  float v82; // ecx
  int v83; // esi
  int k_4; // edx
  float v85; // eax
  int i_9; // eax
  float v87; // edx
  int j_5; // ecx
  int i_8; // ecx
  float v90; // eax
  _DWORD *v91; // eax
  int k_5; // esi
  float v93; // eax
  int i_11; // eax
  float v95; // ecx
  int j_6; // edx
  int i_10; // edx
  float v98; // eax
  _DWORD *v99; // eax
  float v100; // esi
  int v101; // ecx
  int n; // ecx
  _BYTE src[192]; // [esp-200h] [ebp-20Ch] BYREF
  float v105[13]; // [esp-118h] [ebp-124h] BYREF
  float v106; // [esp-E4h] [ebp-F0h]
  __int128 v107; // [esp-E0h] [ebp-ECh]
  __int128 v108; // [esp-D0h] [ebp-DCh]
  float v109; // [esp-C0h] [ebp-CCh]
  float v110; // [esp-BCh] [ebp-C8h]
  float v111; // [esp-B8h] [ebp-C4h]
  float v112; // [esp-B0h] [ebp-BCh]
  float v113; // [esp-ACh] [ebp-B8h]
  float v114; // [esp-A8h] [ebp-B4h]
  float v115; // [esp-A0h] [ebp-ACh]
  float v116; // [esp-9Ch] [ebp-A8h]
  float v117; // [esp-98h] [ebp-A4h]
  float v118; // [esp-90h] [ebp-9Ch]
  float v119; // [esp-8Ch] [ebp-98h]
  float v120; // [esp-88h] [ebp-94h]
  float v121; // [esp-80h] [ebp-8Ch]
  float v122; // [esp-7Ch] [ebp-88h]
  float v123; // [esp-78h] [ebp-84h]
  float v124; // [esp-70h] [ebp-7Ch]
  float v125; // [esp-6Ch] [ebp-78h]
  float v126; // [esp-68h] [ebp-74h]
  float v127; // [esp-60h] [ebp-6Ch]
  float v128; // [esp-5Ch] [ebp-68h]
  float v129; // [esp-58h] [ebp-64h]
  int v130; // [esp-54h] [ebp-60h]
  float v131; // [esp-50h] [ebp-5Ch]
  float v132; // [esp-4Ch] [ebp-58h]
  float v133; // [esp-48h] [ebp-54h]
  int v134; // [esp-44h] [ebp-50h]
  int v135; // [esp-38h] [ebp-44h]
  _DWORD *v136; // [esp-34h] [ebp-40h]
  float v137; // [esp-30h] [ebp-3Ch]
  float v138; // [esp-2Ch] [ebp-38h]
  int v139; // [esp-28h] [ebp-34h]
  float v140; // [esp-24h] [ebp-30h]
  float v141; // [esp-20h] [ebp-2Ch]
  int j_2; // [esp-1Ch] [ebp-28h]
  float v143; // [esp-18h] [ebp-24h]
  int k; // [esp-14h] [ebp-20h]
  float v145; // [esp-10h] [ebp-1Ch]
  float v146; // [esp-Ch] [ebp-18h]
  int i_4; // [esp-8h] [ebp-14h]
  float v148; // [esp-4h] [ebp-10h]
  _DWORD v149[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v149[0] = a2;
  v149[1] = retaddr;
  i_1 = i_2;
  v13 = a1;
  v139 = a1;
  if ( i_2 + a7 )
  {
    v14 = 0;
    if ( *(_DWORD *)(a10 + 44) )
    {
      if ( a5 > 0 )
      {
        do
        {
          v15 = *(_DWORD *)(a4 + 4 * v14);
          if ( (*(_BYTE *)(v15 + 244) & 2) != 0 )
          {
            *(_DWORD *)(v15 + 576) = 0;
            *(_DWORD *)(v15 + 580) = 0;
            *(_DWORD *)(v15 + 584) = 0;
            *(_DWORD *)(v15 + 588) = 0;
            *(_DWORD *)(v15 + 592) = 0;
            *(_DWORD *)(v15 + 596) = 0;
            *(_DWORD *)(v15 + 600) = 0;
            *(_DWORD *)(v15 + 604) = 0;
            *(_DWORD *)(v15 + 640) = 0;
            *(_DWORD *)(v15 + 644) = 0;
            *(_DWORD *)(v15 + 648) = 0;
            *(_DWORD *)(v15 + 652) = 0;
            *(_DWORD *)(v15 + 656) = 0;
            *(_DWORD *)(v15 + 660) = 0;
            *(_DWORD *)(v15 + 664) = 0;
            *(_DWORD *)(v15 + 668) = 0;
          }
          ++v14;
        }
        while ( v14 < a5 );
        i_1 = i_2;
      }
    }
    else if ( a5 > 0 )
    {
      do
      {
        v16 = *(_DWORD *)(a4 + 4 * v14);
        if ( (*(_BYTE *)(v16 + 244) & 2) != 0 )
        {
          *(_DWORD *)(v16 + 576) = 0;
          *(_DWORD *)(v16 + 580) = 0;
          *(_DWORD *)(v16 + 584) = 0;
          *(_DWORD *)(v16 + 588) = 0;
          *(_DWORD *)(v16 + 592) = 0;
          *(_DWORD *)(v16 + 596) = 0;
          *(_DWORD *)(v16 + 600) = 0;
          *(_DWORD *)(v16 + 604) = 0;
        }
        ++v14;
      }
      while ( v14 < a5 );
      v13 = v139;
    }
    if ( i_1 > 0 )
    {
      for ( i = 0; i < i_1; ++i )
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a8 + 4 * i) + 4))(*(_DWORD *)(a8 + 4 * i));
      v13 = v139;
    }
    v18 = *(float *)(v13 + 108);
    v19 = 0.0;
    v143 = 0.0;
    v141 = v18;
    if ( i_1 >= SLODWORD(v18) )
    {
      if ( i_1 > SLODWORD(v18) && *(_DWORD *)(v13 + 112) < i_1 )
      {
        if ( i_1 )
        {
          i_12 = sub_9D4CE0(8 * i_1, 16);
          i_4 = i_12;
        }
        else
        {
          i_12 = 0;
          i_4 = 0;
        }
        j_1 = *(_DWORD *)(v13 + 108);
        j_2 = j_1;
        if ( j_1 > 0 )
        {
          i_13 = (_DWORD *)i_12;
          for ( j = 0; j < j_1; ++j )
          {
            if ( i_13 )
            {
              v24 = *(_DWORD *)(v13 + 116);
              *i_13 = *(_DWORD *)(v24 + 8 * j);
              i_13[1] = *(_DWORD *)(v24 + 8 * j + 4);
              j_1 = j_2;
            }
            i_13 += 2;
          }
          i_1 = i_2;
        }
        if ( *(_DWORD *)(v13 + 116) )
        {
          if ( *(_BYTE *)(v13 + 120) )
            sub_9D4D50(*(_DWORD *)(v13 + 116));
          *(_DWORD *)(v13 + 116) = 0;
        }
        i_14 = i_4;
        v18 = v141;
        *(_BYTE *)(v13 + 120) = 1;
        *(_DWORD *)(v13 + 116) = i_14;
        *(_DWORD *)(v13 + 112) = i_1;
        v19 = 0.0;
      }
      for ( ; SLODWORD(v18) < i_1; ++LODWORD(v18) )
      {
        v26 = (_DWORD *)(*(_DWORD *)(v13 + 116) + 8 * LODWORD(v18));
        if ( v26 )
        {
          *v26 = 0;
          v26[1] = 0;
        }
      }
    }
    i_3 = 0;
    *(_DWORD *)(v13 + 108) = i_1;
    i_4 = 0;
    if ( i_1 > 0 )
    {
      do
      {
        v28 = (_DWORD *)(*(_DWORD *)(v13 + 116) + 8 * i_3);
        (*(void (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(a8 + 4 * i_3) + 12))(*(_DWORD *)(a8 + 4 * i_3), v28);
        LODWORD(v19) = *v28 + LODWORD(v143);
        i_3 = i_4 + 1;
        v143 = v19;
        i_4 = i_3;
      }
      while ( i_3 < i_2 );
    }
    j_3 = *(_DWORD *)(v13 + 28);
    j_2 = j_3;
    if ( SLODWORD(v19) >= j_3 )
    {
      if ( SLODWORD(v19) > j_3 && *(_DWORD *)(v13 + 32) < SLODWORD(v19) )
      {
        if ( v19 == 0.0 )
        {
          k_1 = 0;
        }
        else
        {
          k_1 = (char *)sub_9D4CE0(192 * LODWORD(v19), 16);
          v19 = v143;
        }
        i_5 = *(_DWORD *)(v13 + 28);
        k = (int)k_1;
        i_4 = i_5;
        if ( i_5 > 0 )
        {
          v32 = 0;
          do
          {
            if ( k_1 )
            {
              qmemcpy(k_1, (const void *)(v32 + *(_DWORD *)(v13 + 36)), 0xC0u);
              v13 = v139;
              i_5 = i_4;
            }
            v32 += 192;
            k_1 += 192;
            i_4 = --i_5;
          }
          while ( i_5 );
          v19 = v143;
        }
        if ( *(_DWORD *)(v13 + 36) )
        {
          if ( *(_BYTE *)(v13 + 40) )
            sub_9D4D50(*(_DWORD *)(v13 + 36));
          v19 = v143;
          *(_DWORD *)(v13 + 36) = 0;
        }
        *(_DWORD *)(v13 + 36) = k;
        j_3 = j_2;
        *(_BYTE *)(v13 + 40) = 1;
        *(float *)(v13 + 32) = v19;
      }
      if ( j_3 < SLODWORD(v19) )
      {
        i_6 = 192 * j_3;
        k_2 = LODWORD(v19) - j_3;
        i_4 = 192 * j_3;
        k = LODWORD(v19) - j_3;
        do
        {
          dst = (void *)(i_6 + *(_DWORD *)(v13 + 36));
          if ( dst )
          {
            qmemcpy(dst, src, 0xC0u);
            v13 = v139;
            i_6 = i_4;
            k_2 = k;
          }
          i_6 += 192;
          --k_2;
          i_4 = i_6;
          k = k_2;
        }
        while ( k_2 );
      }
    }
    k_3 = 0;
    i_7 = 0;
    *(float *)(v13 + 28) = v19;
    i_4 = 0;
    for ( k = 0; k_3 < i_2; k = k_3 )
    {
      v38 = 8 * k_3;
      v39 = (int *)(8 * k_3 + *(_DWORD *)(v13 + 116));
      v135 = v38;
      v40 = *v39;
      v143 = *(float *)&v39;
      if ( v40 )
      {
        v41 = 3 * i_7;
        v42 = *(float *)(a8 + 4 * k);
        j_4 = *(_DWORD *)(v13 + 36) + (v41 << 6);
        v44 = *(float *)(LODWORD(v42) + 20);
        v141 = v42;
        v45 = *(_DWORD **)(LODWORD(v42) + 24);
        j_2 = j_4;
        v146 = v44;
        v136 = v45;
        v145 = 0.0;
        if ( v40 > 0 )
        {
          v108 = xmmword_B700C0;
          v46 = (float *)(j_4 + 152);
          v47 = v44;
          do
          {
            memset(v46 - 38, 0, 0xC0u);
            v45 = v136;
            v48 = v143;
            *(_OWORD *)(v46 - 18) = v108;
            LODWORD(v49) = LODWORD(v145) + 1;
            *(v46 - 1) = -3.4028235e38;
            *v46 = 3.4028235e38;
            *(_OWORD *)(v46 - 14) = xmmword_B700C0;
            *(v46 - 6) = v47;
            *((_DWORD *)v46 - 5) = v45;
            v145 = v49;
            v46 += 48;
          }
          while ( SLODWORD(v49) < *(_DWORD *)LODWORD(v48) );
          v13 = v139;
          j_4 = j_2;
          v44 = v146;
        }
        *(_DWORD *)(LODWORD(v44) + 576) = 0;
        *(_DWORD *)(LODWORD(v44) + 580) = 0;
        *(_DWORD *)(LODWORD(v44) + 584) = 0;
        *(_DWORD *)(LODWORD(v44) + 588) = 0;
        *(_DWORD *)(LODWORD(v44) + 592) = 0;
        *(_DWORD *)(LODWORD(v44) + 596) = 0;
        *(_DWORD *)(LODWORD(v44) + 600) = 0;
        *(_DWORD *)(LODWORD(v44) + 604) = 0;
        v45[144] = 0;
        v45[145] = 0;
        v45[146] = 0;
        v45[147] = 0;
        v45[148] = 0;
        v45[149] = 0;
        v45[150] = 0;
        v45[151] = 0;
        v50 = *(float *)(a10 + 12);
        v51 = *(float *)(a10 + 32);
        LODWORD(v105[2]) = j_4 + 16;
        LODWORD(v105[5]) = j_4 + 32;
        LODWORD(v105[7]) = j_4 + 140;
        v105[1] = v51;
        LODWORD(v105[3]) = j_4;
        v105[4] = 0.0;
        LODWORD(v105[6]) = 48;
        v105[0] = 1.0 / v50;
        *(float *)(j_4 + 144) = *(float *)(a10 + 40);
        v52 = *(float *)(a10 + 4);
        LODWORD(v105[8]) = j_4 + 144;
        LODWORD(v105[9]) = j_4 + 148;
        LODWORD(v105[10]) = j_4 + 152;
        v105[12] = *(float *)(a10 + 20);
        v106 = v52;
        (*(void (__thiscall **)(_DWORD, float *))(**(_DWORD **)(a8 + 4 * k) + 16))(*(_DWORD *)(a8 + 4 * k), v105);
        v53 = v143;
        j_2 = 0;
        if ( (int)*(_DWORD *)LODWORD(v143) > 0 )
        {
          v54 = (float *)LODWORD(v146);
          v55 = v141;
          v134 = 0;
          v130 = 0;
          v107 = xmmword_B700C0;
          v56 = j_4 + 40;
          do
          {
            *(float *)(v56 + 96) = v55;
            v141 = *(float *)(v56 - 36);
            v57 = *(float **)(LODWORD(v55) + 20);
            v140 = *(float *)(v56 - 40);
            v146 = *(float *)(v56 - 32);
            v112 = v57[70] * v146 + v57[68] * v140 + v57[69] * v141;
            v113 = v57[73] * v141 + v140 * v57[72] + v57[74] * v146;
            v114 = v140 * v57[76] + v141 * v57[77] + v146 * v57[78];
            v131 = v112 * v57[152];
            v132 = v57[153] * v113;
            v58 = v57[154] * v114;
            *(float *)(v56 + 8) = v131;
            *(float *)(v56 + 12) = v132;
            v133 = v58;
            *(float *)(v56 + 16) = v133;
            *(_DWORD *)(v56 + 20) = v134;
            v59 = *(float **)(LODWORD(v55) + 24);
            v141 = *(float *)(v56 - 4);
            v140 = *(float *)(v56 - 8);
            v146 = *(float *)v56;
            v118 = v59[70] * v146 + v59[69] * v141 + v140 * v59[68];
            v119 = v59[73] * v141 + v140 * v59[72] + v59[74] * v146;
            v120 = v146 * v59[78] + v141 * v59[77] + v140 * v59[76];
            v127 = v118 * v59[152];
            v128 = v59[153] * v119;
            v60 = v59[154] * v120;
            *(float *)(v56 + 24) = v127;
            *(float *)(v56 + 28) = v128;
            v129 = v60;
            *(float *)(v56 + 32) = v129;
            *(_DWORD *)(v56 + 36) = v130;
            v141 = v54[88];
            v143 = *(float *)(v56 - 24);
            v109 = v143 * v141;
            v145 = *(float *)(v56 - 20);
            v110 = v145 * v141;
            v146 = *(float *)(v56 - 16);
            v111 = v141 * v146;
            v141 = *(float *)(v56 - 36);
            v140 = *(float *)(v56 - 40);
            v138 = *(float *)(v56 - 32);
            v124 = v54[70] * v138 + v54[69] * v141 + v140 * v54[68];
            v61 = (float *)v136;
            v125 = v140 * v54[72] + v54[73] * v141 + v54[74] * v138;
            v62 = v138;
            v126 = v141 * v54[77] + v140 * v54[76] + v138 * v54[78];
            v138 = *((float *)v136 + 88);
            v115 = v143 * v138;
            v116 = v145 * v138;
            v117 = v138 * v146;
            v137 = *(float *)(v56 - 4);
            v138 = *(float *)(v56 - 8);
            v148 = *(float *)v56;
            v63 = v148;
            v121 = v61[70] * v148 + v61[69] * v137 + v61[68] * v138;
            v122 = v61[72] * v138 + v61[73] * v137 + v61[74] * v148;
            v123 = v137 * v61[77] + v61[76] * v138 + v148 * v61[78];
            v148 = v143 * v109 + v110 * v145 + v146 * v111;
            v64 = v148;
            v148 = v62 * v126 + v140 * v124 + v141 * v125;
            v148 = v64 + v148;
            v65 = v148;
            v148 = v143 * v115 + v145 * v116 + v146 * v117;
            v148 = v65 + v148;
            v66 = v148;
            v148 = v63 * v123 + v137 * v122 + v138 * v121;
            v148 = v66 + v148;
            v148 = 1.0 / v148;
            v137 = v148;
            *(float *)(v56 + 76) = v148;
            v143 = *(float *)(v56 - 24);
            v67 = v54[85];
            v145 = *(float *)(v56 - 20);
            v68 = v67 * *(float *)(v56 - 36);
            v69 = v54[84];
            v146 = *(float *)(v56 - 16);
            v148 = v68 + v69 * *(float *)(v56 - 40) + v54[86] * *(float *)(v56 - 32);
            v70 = v148;
            v56 += 192;
            v148 = v54[82] * v146 + v54[81] * v145 + v143 * v54[80];
            v148 = v70 + v148;
            v71 = v148;
            v148 = *(float *)(v56 - 200) * v61[84] + *(float *)(v56 - 196) * v61[85] + *(float *)(v56 - 192) * v61[86];
            v72 = v148;
            v148 = v146 * v61[82] + v145 * v61[81] + v143 * v61[80];
            v148 = v72 - v148;
            v148 = v71 + v148;
            v73 = v148 * v106;
            *(_QWORD *)(v56 - 136) = v107;
            *(_DWORD *)(v56 - 128) = DWORD2(v107);
            v148 = 0.0 - v73;
            *(_DWORD *)(v56 - 124) = HIDWORD(v107);
            v74 = ++j_2;
            v148 = v148 * v137;
            v75 = v148;
            v148 = v137 * *(float *)(v56 - 92);
            *(float *)(v56 - 92) = v75 + v148;
          }
          while ( v74 < *(_DWORD *)LODWORD(v53) );
          v13 = v139;
        }
        i_7 = i_4;
      }
      i_7 += *(_DWORD *)(*(_DWORD *)(v13 + 116) + v135);
      k_3 = k + 1;
      i_4 = i_7;
    }
    v76 = 0;
    v77 = 0;
    v80 = 0;
    v78 = a7 == 0;
    v81 = __SETP__(a7, 0);
    for ( m = a7 < 0; v76 < a7; m = v76 - a7 < 0 )
    {
      sub_9BD420(v13, (int)v149, v13, v76, a3, *(_DWORD **)(a6 + 4 * v76), a10);
      v77 = ++v76 < (unsigned int)a7;
      v80 = __OFSUB__(v76, a7);
      v78 = v76 == a7;
      v81 = __SETP__(v76, a7);
    }
    v82 = *(float *)(v13 + 8);
    v83 = *(_DWORD *)(v13 + 68);
    k_4 = *(_DWORD *)(v13 + 48);
    v146 = v82;
    k = k_4;
    if ( SLODWORD(v82) >= v83 )
    {
      if ( SLODWORD(v82) > v83 && *(_DWORD *)(v13 + 72) < SLODWORD(v82) )
      {
        if ( v82 == 0.0 )
        {
          v145 = 0.0;
        }
        else
        {
          v85 = COERCE_FLOAT(sub_9D4CE0(4 * LODWORD(v82), 16));
          v82 = v146;
          v145 = v85;
        }
        i_9 = 0;
        j_2 = *(_DWORD *)(v13 + 68);
        i_4 = 0;
        if ( j_2 > 0 )
        {
          v87 = v145;
          j_5 = j_2;
          do
          {
            if ( v87 != 0.0 )
            {
              i_8 = i_4;
              *(_DWORD *)LODWORD(v87) = *(_DWORD *)(*(_DWORD *)(v13 + 76) + 4 * i_4);
              i_9 = i_8;
              j_5 = j_2;
            }
            ++i_9;
            LODWORD(v87) += 4;
            i_4 = i_9;
          }
          while ( i_9 < j_5 );
          v82 = v146;
        }
        if ( *(_DWORD *)(v13 + 76) )
        {
          if ( *(_BYTE *)(v13 + 80) )
            sub_9D4D50(*(_DWORD *)(v13 + 76));
          v82 = v146;
          *(_DWORD *)(v13 + 76) = 0;
        }
        v90 = v145;
        k_4 = k;
        *(_BYTE *)(v13 + 80) = 1;
        *(float *)(v13 + 76) = v90;
        *(float *)(v13 + 72) = v82;
      }
      for ( ; v83 < SLODWORD(v82); ++v83 )
      {
        v91 = (_DWORD *)(*(_DWORD *)(v13 + 76) + 4 * v83);
        if ( v91 )
          *v91 = 0;
      }
    }
    *(float *)(v13 + 68) = v82;
    k_5 = *(_DWORD *)(v13 + 88);
    if ( k_4 >= k_5 )
    {
      if ( k_4 > k_5 && *(_DWORD *)(v13 + 92) < k_4 )
      {
        if ( k_4 )
        {
          v93 = COERCE_FLOAT(sub_9D4CE0(4 * k_4, 16));
          k_4 = k;
          v145 = v93;
        }
        else
        {
          v145 = 0.0;
        }
        i_11 = 0;
        j_2 = *(_DWORD *)(v13 + 88);
        i_4 = 0;
        if ( j_2 > 0 )
        {
          v95 = v145;
          j_6 = j_2;
          do
          {
            if ( v95 != 0.0 )
            {
              i_10 = i_4;
              *(_DWORD *)LODWORD(v95) = *(_DWORD *)(*(_DWORD *)(v13 + 96) + 4 * i_4);
              i_11 = i_10;
              j_6 = j_2;
            }
            ++i_11;
            LODWORD(v95) += 4;
            i_4 = i_11;
          }
          while ( i_11 < j_6 );
          k_4 = k;
        }
        if ( *(_DWORD *)(v13 + 96) )
        {
          if ( *(_BYTE *)(v13 + 100) )
            sub_9D4D50(*(_DWORD *)(v13 + 96));
          k_4 = k;
          *(_DWORD *)(v13 + 96) = 0;
        }
        v98 = v145;
        *(_BYTE *)(v13 + 100) = 1;
        *(float *)(v13 + 96) = v98;
        *(_DWORD *)(v13 + 92) = k_4;
      }
      for ( ; k_5 < k_4; ++k_5 )
      {
        v99 = (_DWORD *)(*(_DWORD *)(v13 + 96) + 4 * k_5);
        if ( v99 )
          *v99 = 0;
      }
    }
    v100 = v146;
    v101 = 0;
    for ( *(_DWORD *)(v13 + 88) = k_4; v101 < SLODWORD(v100); ++v101 )
      *(_DWORD *)(*(_DWORD *)(v13 + 76) + 4 * v101) = v101;
    for ( n = 0; n < k_4; ++n )
      *(_DWORD *)(*(_DWORD *)(v13 + 96) + 4 * n) = n;
  }
  return 0.0;
}
