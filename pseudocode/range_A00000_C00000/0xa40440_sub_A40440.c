// Function: sub_A40440
// Address: 0xa40440
// Size: 0xdc2
// Prototype: int __cdecl(int, int, float)

float *__cdecl sub_A40440(float a1, float *a2, float a3)
{
  int v3; // ebx
  unsigned int v4; // edi
  int v5; // esi
  int *v6; // eax
  int v7; // ecx
  int n8; // edx
  unsigned int v9; // esi
  float *v10; // ebx
  float v11; // eax
  int v12; // ecx
  float v13; // eax
  int v14; // edx
  _BYTE *v15; // edi
  int *v16; // ecx
  int v17; // eax
  int v18; // edx
  float v19; // ebx
  float v20; // eax
  int v21; // edx
  float v22; // ecx
  int v23; // eax
  int v24; // ebx
  _DWORD *v25; // eax
  _DWORD *v26; // edx
  int *v27; // esi
  unsigned int v28; // ecx
  int v29; // ecx
  int v30; // eax
  int v31; // eax
  unsigned int n4; // ecx
  float *v33; // ebx
  int v34; // eax
  int v35; // edi
  float *v36; // eax
  int v37; // eax
  int v38; // eax
  _DWORD *v39; // edi
  float v40; // eax
  float v41; // eax
  _DWORD *v42; // edi
  float *v43; // edx
  unsigned int v44; // esi
  float *v45; // eax
  int v46; // eax
  int v47; // eax
  float v48; // eax
  float v49; // eax
  float v50; // ebx
  int *i_1; // esi
  double v52; // st7
  int v53; // eax
  float *v54; // eax
  double v55; // st5
  double v56; // st6
  float *v57; // eax
  float *v58; // eax
  int **v59; // eax
  int *j; // eax
  int *i; // eax
  int *v62; // eax
  int *v63; // edx
  int v64; // ebx
  unsigned int v65; // edi
  unsigned int v66; // ecx
  int v67; // esi
  _BYTE *v68; // edx
  _BYTE *v69; // esi
  int *v70; // edx
  _BYTE *v71; // esi
  unsigned int v72; // edi
  unsigned int v73; // ecx
  int v74; // esi
  _BYTE *v75; // edx
  _DWORD *v76; // edx
  unsigned int v77; // edi
  unsigned int v78; // ecx
  int v79; // esi
  _BYTE *v80; // edx
  _BYTE *v81; // esi
  _DWORD *v82; // edx
  _BYTE *v83; // esi
  unsigned int v84; // edi
  unsigned int v85; // ecx
  int v86; // esi
  _BYTE *v87; // edx
  int v89; // [esp-8h] [ebp-30Ch]
  int v90; // [esp-4h] [ebp-308h]
  char v91[64]; // [esp+14h] [ebp-2F0h] BYREF
  char v92[64]; // [esp+54h] [ebp-2B0h] BYREF
  float v93[4]; // [esp+94h] [ebp-270h] BYREF
  float v94[10]; // [esp+A4h] [ebp-260h] BYREF
  int v95[3]; // [esp+CCh] [ebp-238h] BYREF
  int *v96; // [esp+D8h] [ebp-22Ch]
  _BYTE v97[24]; // [esp+E4h] [ebp-220h] BYREF
  int v98; // [esp+FCh] [ebp-208h]
  int v99; // [esp+100h] [ebp-204h] BYREF
  int v100; // [esp+104h] [ebp-200h]
  float v101; // [esp+108h] [ebp-1FCh]
  int v102; // [esp+10Ch] [ebp-1F8h]
  _DWORD v103[3]; // [esp+110h] [ebp-1F4h] BYREF
  _DWORD *v104; // [esp+11Ch] [ebp-1E8h]
  _DWORD *v105; // [esp+120h] [ebp-1E4h]
  _DWORD *v106; // [esp+124h] [ebp-1E0h]
  _BYTE v107[24]; // [esp+128h] [ebp-1DCh] BYREF
  int v108; // [esp+140h] [ebp-1C4h] BYREF
  int v109; // [esp+144h] [ebp-1C0h]
  float v110; // [esp+148h] [ebp-1BCh] BYREF
  int v111; // [esp+14Ch] [ebp-1B8h]
  int v112; // [esp+150h] [ebp-1B4h]
  float v113; // [esp+154h] [ebp-1B0h]
  float v114; // [esp+158h] [ebp-1ACh] BYREF
  float v115; // [esp+15Ch] [ebp-1A8h]
  float v116; // [esp+160h] [ebp-1A4h] BYREF
  float v117; // [esp+164h] [ebp-1A0h]
  int v118; // [esp+168h] [ebp-19Ch] BYREF
  int v119; // [esp+16Ch] [ebp-198h]
  float v120; // [esp+170h] [ebp-194h]
  void *v121[2]; // [esp+174h] [ebp-190h] BYREF
  int *v122; // [esp+17Ch] [ebp-188h] BYREF
  int *v123; // [esp+180h] [ebp-184h]
  int v124; // [esp+184h] [ebp-180h]
  int v125; // [esp+188h] [ebp-17Ch]
  int v126; // [esp+18Ch] [ebp-178h]
  int v127; // [esp+190h] [ebp-174h] BYREF
  int *v128; // [esp+194h] [ebp-170h]
  int v129; // [esp+198h] [ebp-16Ch]
  float v130; // [esp+19Ch] [ebp-168h] BYREF
  int v131; // [esp+1A0h] [ebp-164h]
  int v132; // [esp+1A4h] [ebp-160h]
  float v133; // [esp+1A8h] [ebp-15Ch]
  float *v134; // [esp+1ACh] [ebp-158h]
  _DWORD *v135; // [esp+1B0h] [ebp-154h]
  float v136; // [esp+1B4h] [ebp-150h] BYREF
  float v137; // [esp+1B8h] [ebp-14Ch]
  float v138; // [esp+1BCh] [ebp-148h] BYREF
  float v139; // [esp+1C0h] [ebp-144h]
  _DWORD *v140; // [esp+1C4h] [ebp-140h]
  int v141; // [esp+1C8h] [ebp-13Ch]
  int v142; // [esp+1CCh] [ebp-138h]
  float v143; // [esp+1D0h] [ebp-134h]
  _BYTE *v144; // [esp+1D4h] [ebp-130h]
  _BYTE *v145; // [esp+1D8h] [ebp-12Ch] BYREF
  float v146; // [esp+1DCh] [ebp-128h] BYREF
  int v147[53]; // [esp+1E0h] [ebp-124h] BYREF
  float v148[4]; // [esp+2B4h] [ebp-50h] BYREF
  _BYTE v149[16]; // [esp+2C4h] [ebp-40h] BYREF
  _BYTE v150[16]; // [esp+2D4h] [ebp-30h] BYREF
  _BYTE v151[16]; // [esp+2E4h] [ebp-20h] BYREF
  int v152; // [esp+300h] [ebp-4h]

  v146 = a1;
  v134 = a2;
  v108 = 0;
  v109 = 0;
  v152 = 0;
  v3 = sub_49BDE0(&v108);
  v4 = *(_DWORD *)a2 / 3u;
  v125 = v3;
  sub_A3F870(v3, v4);
  v5 = 0;
  LOBYTE(v152) = 1;
  v6 = v147;
  v7 = 0;
  n8 = 8;
  do
  {
    v5 += *v6;
    v7 += v6[1];
    v6 += 2;
    --n8;
  }
  while ( n8 );
  v9 = v7 + v5;
  if ( v9 != (3 * v4) >> 1 )
  {
    v10 = 0;
    goto LABEL_115;
  }
  v11 = 0.0;
  v132 = 0;
  if ( v9 )
  {
    v11 = COERCE_FLOAT(sub_42FC60(8 * v9, 4));
    v132 = LODWORD(v11);
  }
  v94[9] = v11;
  v98 = LODWORD(v11) != 0 ? v9 : 0;
  LODWORD(v94[8]) = v98;
  v12 = 0;
  LOBYTE(v152) = 2;
  v135 = 0;
  if ( v9 )
  {
    v12 = sub_42FC60(8 * v9, 4);
    v135 = (_DWORD *)v12;
  }
  LODWORD(v94[7]) = v12;
  v102 = v12 != 0 ? v9 : 0;
  LODWORD(v94[6]) = v102;
  v13 = 0.0;
  LOBYTE(v152) = 3;
  v126 = 0;
  if ( v4 )
  {
    v13 = COERCE_FLOAT(sub_42FC60(12 * v4, 4));
    v12 = (int)v135;
    v126 = LODWORD(v13);
  }
  v94[5] = v13;
  v14 = v4 & ((unsigned __int64)-(__int64)LODWORD(v13) >> 32);
  v100 = v14;
  LODWORD(v94[4]) = v14;
  if ( v132 && v12 && v126 )
  {
    sub_A423C0(v132, v12, v126, v4);
    v118 = 0;
    v119 = 0;
    LOBYTE(v152) = 5;
    v131 = sub_49BF90(&v118);
    if ( !v131 )
    {
      v10 = 0;
LABEL_100:
      LOBYTE(v152) = 4;
      if ( v118 >= 0 && v119 )
        Phyre_Memory_AlignedFree(v119);
      v14 = v100;
      v119 = 0;
      v118 = 0;
      goto LABEL_106;
    }
    v122 = 0;
    v123 = 0;
    v124 = 0;
    v127 = 0;
    v128 = 0;
    v129 = 0;
    LOBYTE(v152) = 7;
    sub_A3F830(v121);
    LOBYTE(v152) = 8;
    sub_A3F590(v95);
    v15 = 0;
    LOBYTE(v152) = 9;
    v145 = 0;
    if ( v9 )
    {
      v140 = v135;
      v16 = (int *)(v132 + 4);
      v144 = (_BYTE *)(v132 + 4);
      v134 = (float *)((char *)v135 - v132);
      while ( 1 )
      {
        v17 = *(v16 - 1);
        v18 = *v16;
        v142 = v17;
        v141 = v18;
        if ( *(float *)&v17 == NAN || *(float *)&v18 == NAN )
          break;
        LODWORD(v143) = v3 + 12 * v17;
        v19 = *(float *)(v3 + 12 * v18);
        v20 = *(float *)(v125 + 12 * v18 + 8);
        v133 = *(float *)(v125 + 12 * v18 + 4);
        v21 = *v140;
        v120 = v20;
        v99 = v21;
        v22 = *(float *)((char *)v134 + (_DWORD)v144);
        v130 = v22;
        if ( v21 == LODWORD(v19) || LODWORD(v22) == LODWORD(v19) )
        {
          if ( v21 == LODWORD(v133) || (v19 = v133, LODWORD(v22) == LODWORD(v133)) )
            v19 = v120;
        }
        sub_A413D0(&v110, LODWORD(v143), v131, 3);
        v23 = 3 * LODWORD(v19);
        v24 = v131;
        v143 = *(float *)(v131 + 4 * v23);
        v120 = *(float *)(v131 + 4 * v23 + 4);
        v133 = *(float *)(v131 + 4 * v23 + 8);
        v101 = -v113;
        v143 = v143 * v110;
        v143 = v143 + v120 * *(float *)&v111;
        v143 = v133 * *(float *)&v112 + v143;
        if ( a3 < v143 - v101 )
          break;
        if ( a3 >= v101 - v143 )
        {
          v3 = v125;
        }
        else
        {
          sub_A42690(&v145);
          sub_A3EED0(v121, (int)&v116, 0, &v99, unk_1A85A28);
          sub_A3EED0(v121, (int)&v138, 0, &v130, unk_1A85A28);
          v89 = v24;
          v3 = v125;
          sub_A400C0(v142, v125, v95, (int)&v127, v89, 3, a3);
          sub_A400C0(v141, v3, v95, (int)&v127, v131, 3, a3);
          v15 = v145;
        }
        v140 += 2;
        ++v15;
        v16 = (int *)(v144 + 8);
        v145 = v15;
        v144 += 8;
        if ( (unsigned int)v15 >= v9 )
          goto LABEL_30;
      }
    }
    else
    {
LABEL_30:
      v25 = (_DWORD *)sub_A41210(LODWORD(v146), ((int)v128 - v127) >> 2, v121[1], v123 - v122);
      v26 = v25;
      v134 = (float *)v25;
      if ( v25 )
      {
        v27 = (int *)v127;
        v28 = (unsigned int)(*v25 + 3) >> 2;
        LODWORD(v133) = &v25[16 * v28 + 12];
        v29 = v25[1] + 4 * v28 + 3;
        v144 = &v25[4 * v29];
        v30 = v25[2];
        v140 = v26 + 12;
        v31 = v30 + 8 * v29;
        n4 = 0;
        v145 = (char *)v26 + 2 * v31;
        if ( (int *)v127 != v128 )
        {
          v33 = (float *)(v26 + 26);
          do
          {
            v34 = *v27;
            LODWORD(v146) = n4 + 1;
            v35 = 2 * n4;
            v36 = (float *)sub_A413D0(&v110, v125 + 12 * v34, v131, 3);
            n4 = LODWORD(v146);
            v148[2 * v35] = *v36;
            v148[2 * v35 + 1] = v36[1];
            v148[2 * v35 + 2] = v36[2];
            v148[2 * v35 + 3] = v36[3];
            if ( n4 == 4 )
            {
              v37 = sub_450E20(v148, v149, v150, v151);
              v38 = sub_4F9560(v92, v37);
              v39 = v140;
              sub_453420(v38);
              v136 = *(v33 - 2);
              v40 = *(v33 - 1);
              v146 = -v136;
              v137 = v40;
              v138 = *v33;
              v41 = v33[1];
              *(float *)&v141 = -v137;
              v139 = v41;
              v42 = v39 + 16;
              *(float *)&v142 = -v138;
              v33 += 16;
              v140 = v42;
              n4 = 0;
              v130 = -v41;
              *(v33 - 18) = v146;
              *(v33 - 17) = *(float *)&v141;
              *(v33 - 16) = *(float *)&v142;
              *(v33 - 15) = v130;
            }
            else
            {
              v42 = v140;
            }
            ++v27;
          }
          while ( v27 != v128 );
          if ( n4 )
          {
            if ( n4 < 4 )
            {
              v43 = &v148[4 * n4];
              v44 = 4 - n4;
              do
              {
                v45 = v43;
                v43 += 4;
                *v45 = 0.0;
                v45[1] = 0.0;
                v45[2] = 0.0;
                v45[3] = 0.0;
                --v44;
              }
              while ( v44 );
            }
            v46 = sub_450E20(v148, v149, v150, v151);
            v47 = sub_4F9560(v91, v46);
            sub_453420(v47);
            v136 = *((float *)v42 + 12);
            v48 = *((float *)v42 + 13);
            v146 = -v136;
            v137 = v48;
            v138 = *((float *)v42 + 14);
            v49 = *((float *)v42 + 15);
            *(float *)&v141 = -v137;
            v139 = v49;
            *(float *)&v142 = -v138;
            v130 = -v49;
            *((float *)v42 + 12) = v146;
            *((float *)v42 + 13) = *(float *)&v141;
            *((float *)v42 + 14) = *(float *)&v142;
            *((float *)v42 + 15) = v130;
          }
        }
        v136 = 3.4028235e38;
        v103[0] = v103;
        v137 = 3.4028235e38;
        v103[1] = v103;
        v138 = 3.4028235e38;
        v103[2] = v103;
        v139 = 3.4028235e38;
        v106 = v103;
        v105 = v103;
        v114 = -3.4028235e38;
        v104 = v103;
        v115 = -3.4028235e38;
        v116 = -3.4028235e38;
        v117 = -3.4028235e38;
        LOBYTE(v152) = 10;
        sub_49C550(20, 8, 4, "PMapPair");
        v50 = 0.0;
        i_1 = *(int **)v121[0];
        LOBYTE(v152) = 11;
        if ( i_1 != v121[0] )
        {
          v52 = 0.0;
          v113 = 0.0;
          do
          {
            v53 = 3 * i_1[4];
            v146 = *(float *)(v131 + 12 * i_1[4]);
            v141 = *(int *)(v131 + 4 * v53 + 4);
            v142 = *(int *)(v131 + 4 * v53 + 8);
            v54 = (float *)LODWORD(v133);
            v110 = v146;
            LODWORD(v133) += 16;
            v55 = *(float *)&v141;
            v111 = v141;
            v112 = v142;
            v56 = *(float *)&v142;
            *v54 = v146;
            v54[1] = v55;
            v54[2] = v56;
            v54[3] = v52;
            v57 = sub_A1B620(v93, &v110, &v136);
            v136 = *v57;
            v137 = v57[1];
            v138 = v57[2];
            v139 = v57[3];
            v58 = sub_A1B560(v94, &v110, &v114);
            v114 = *v58;
            v146 = v50;
            v115 = v58[1];
            ++LODWORD(v50);
            v116 = v58[2];
            v117 = v58[3];
            sub_A42520(i_1 + 4, &v146);
            if ( !*((_BYTE *)i_1 + 13) )
            {
              v59 = (int **)i_1[2];
              if ( *((_BYTE *)v59 + 13) )
              {
                for ( i = (int *)i_1[1]; !*((_BYTE *)i + 13); i = (int *)i[1] )
                {
                  if ( i_1 != (int *)i[2] )
                    break;
                  i_1 = i;
                }
                i_1 = i;
              }
              else
              {
                i_1 = (int *)i_1[2];
                for ( j = *v59; !*((_BYTE *)j + 13); j = (int *)*j )
                  i_1 = j;
              }
            }
            v52 = 0.0;
          }
          while ( i_1 != v121[0] );
        }
        v10 = v134;
        v134[4] = v136;
        v10[5] = v137;
        v10[6] = v138;
        v10[8] = v114;
        v10[9] = v115;
        v10[10] = v116;
        v62 = v122;
        if ( v122 == v123 )
        {
LABEL_95:
          LOBYTE(v152) = 13;
          sub_574AE0(v103);
          sub_49CCE0(v107);
          LOBYTE(v152) = 12;
          sub_49C680(v107);
          LOBYTE(v152) = 14;
          sub_5748D0(v103);
          LOBYTE(v152) = 9;
          sub_5748D0(v103);
          goto LABEL_96;
        }
LABEL_56:
        v63 = v96;
        v64 = *v62;
        if ( v96 != v95 )
        {
          v65 = *(_DWORD *)(v132 + 8 * v64);
          do
          {
            v66 = v63[3];
            if ( v66 <= v65 )
            {
              if ( v66 >= v65 )
              {
                v68 = v63 + 4;
                goto LABEL_64;
              }
              v67 = -1;
            }
            else
            {
              v67 = 1;
            }
            v63 = (int *)v63[v67 < 0];
          }
          while ( v63 != v95 );
        }
        v68 = 0;
LABEL_64:
        v69 = v144;
        *v144 = *v68;
        v70 = v96;
        v71 = v69 + 1;
        v144 = v71;
        if ( v96 == v95 )
          goto LABEL_73;
        v72 = *(_DWORD *)(v132 + 8 * v64 + 4);
        do
        {
          v73 = v70[3];
          if ( v73 <= v72 )
          {
            if ( v73 >= v72 )
            {
              v71 = v144;
              v75 = v70 + 4;
              goto LABEL_74;
            }
            v74 = -1;
          }
          else
          {
            v74 = 1;
          }
          v70 = (int *)v70[v74 < 0];
        }
        while ( v70 != v95 );
        v71 = v144;
LABEL_73:
        v75 = 0;
LABEL_74:
        *v71 = *v75;
        v76 = v104;
        v144 = v71 + 1;
        if ( v104 == v103 )
        {
LABEL_82:
          v80 = 0;
          goto LABEL_83;
        }
        v77 = v135[2 * v64];
        while ( 1 )
        {
          v78 = v76[3];
          if ( v78 <= v77 )
          {
            if ( v78 >= v77 )
            {
              v80 = v76 + 4;
LABEL_83:
              v81 = v145;
              *v145 = *v80;
              v82 = v104;
              v83 = v81 + 1;
              v145 = v83;
              if ( v104 == v103 )
              {
LABEL_92:
                v87 = 0;
                goto LABEL_93;
              }
              v84 = v135[2 * v64 + 1];
              while ( 2 )
              {
                v85 = v82[3];
                if ( v85 > v84 )
                {
                  v86 = 1;
                  goto LABEL_90;
                }
                if ( v85 < v84 )
                {
                  v86 = -1;
LABEL_90:
                  v82 = (_DWORD *)v82[v86 < 0];
                  if ( v82 == v103 )
                  {
                    v83 = v145;
                    goto LABEL_92;
                  }
                  continue;
                }
                break;
              }
              v83 = v145;
              v87 = v82 + 4;
LABEL_93:
              *v83 = *v87;
              ++v62;
              v145 = v83 + 1;
              if ( v62 == v123 )
              {
                v10 = v134;
                goto LABEL_95;
              }
              goto LABEL_56;
            }
            v79 = -1;
          }
          else
          {
            v79 = 1;
          }
          v76 = (_DWORD *)v76[v79 < 0];
          if ( v76 == v103 )
            goto LABEL_82;
        }
      }
    }
    v10 = 0;
LABEL_96:
    LOBYTE(v152) = 16;
    sub_574AE0(v95);
    sub_49CCE0(v97);
    LOBYTE(v152) = 15;
    sub_49C680(v97);
    LOBYTE(v152) = 17;
    sub_5748D0(v95);
    LOBYTE(v152) = 8;
    sub_5748D0(v95);
    v90 = *(_DWORD *)v121[0];
    LOBYTE(v152) = 7;
    sub_A41F50(&v146, v90, v121[0]);
    FFX_Memory_Free(v121[0]);
    LOBYTE(v152) = 6;
    if ( v127 )
    {
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v127);
      FFX_Memory_Free((void *)v127);
      v127 = 0;
      v128 = 0;
      v129 = 0;
    }
    LOBYTE(v152) = 5;
    if ( v122 )
    {
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v122);
      FFX_Memory_Free(v122);
      v122 = 0;
      v123 = 0;
      v124 = 0;
    }
    goto LABEL_100;
  }
  v10 = 0;
LABEL_106:
  LOBYTE(v152) = 3;
  if ( v14 >= 0 && v126 )
    Phyre_Memory_AlignedFree(v126);
  LOBYTE(v152) = 2;
  if ( v102 >= 0 && v135 )
    Phyre_Memory_AlignedFree((int)v135);
  LOBYTE(v152) = 1;
  if ( v98 >= 0 && v132 )
    Phyre_Memory_AlignedFree(v132);
LABEL_115:
  LOBYTE(v152) = 0;
  sub_A3FD30(v147);
  v152 = -1;
  if ( v108 >= 0 && v109 )
    Phyre_Memory_AlignedFree(v109);
  return v10;
}

