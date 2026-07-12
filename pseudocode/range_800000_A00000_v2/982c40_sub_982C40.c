// Function: sub_982C40
// Address: 0x982c40
int __usercall sub_982C40@<eax>(
        int a1@<ebp>,
        int *a2,
        float *a3,
        float *a4,
        float a5,
        int *a6,
        float *a7,
        float *a8,
        int a9)
{
  float *v9; // esi
  int n31; // ecx
  float *v11; // edx
  float v12; // xmm0_4
  int (__stdcall *v13)(char); // eax
  int result; // eax
  float *v15; // edx
  float *v16; // ecx
  double v17; // st7
  double v18; // st6
  double v19; // st7
  double v20; // st5
  double v21; // st4
  double v22; // st5
  double v23; // st1
  double v24; // st4
  double v25; // st3
  double v26; // st7
  double v27; // st5
  double v28; // st6
  float v29; // xmm0_4
  int v30; // eax
  float *v31; // edx
  float *v32; // ecx
  double v33; // st7
  double v34; // st6
  double v35; // st7
  double v36; // st5
  double v37; // st4
  double v38; // st6
  double v39; // st7
  double v40; // st5
  double v41; // st3
  double v42; // st4
  float v43; // xmm0_4
  int v44; // eax
  double v45; // st4
  double v46; // st2
  double v47; // st5
  double v48; // st6
  int v49; // eax
  bool v50; // cc
  int v51; // edi
  int v52; // ecx
  double v53; // st7
  double v54; // st7
  int v55; // eax
  int v56; // ecx
  double v57; // st2
  double v58; // st2
  int v59; // esi
  float v60; // ecx
  float v61[4]; // [esp+18h] [ebp-45Ch] BYREF
  float v62[4]; // [esp+28h] [ebp-44Ch] BYREF
  float v63[6]; // [esp+38h] [ebp-43Ch] BYREF
  float *v64; // [esp+50h] [ebp-424h]
  float v65; // [esp+54h] [ebp-420h]
  float v66; // [esp+58h] [ebp-41Ch]
  int (__stdcall **p_??_7LocalInfoAdder@?CB@??objectQuerySingle@btCollisionWorld@@)(char); // [esp+5Ch] [ebp-418h] BYREF
  int n1065353216; // [esp+60h] [ebp-414h]
  __int16 v69; // [esp+64h] [ebp-410h]
  __int16 v70; // [esp+66h] [ebp-40Eh]
  float *v71; // [esp+68h] [ebp-40Ch]
  float v72; // [esp+6Ch] [ebp-408h]
  float v73; // [esp+70h] [ebp-404h]
  float v74; // [esp+74h] [ebp-400h]
  float v75; // [esp+78h] [ebp-3FCh] BYREF
  float v76; // [esp+7Ch] [ebp-3F8h]
  float v77; // [esp+80h] [ebp-3F4h]
  float v78; // [esp+84h] [ebp-3F0h]
  float v79; // [esp+88h] [ebp-3ECh]
  float v80; // [esp+8Ch] [ebp-3E8h]
  float v81; // [esp+90h] [ebp-3E4h]
  float v82; // [esp+94h] [ebp-3E0h]
  float *v83; // [esp+A4h] [ebp-3D0h]
  float v84; // [esp+A8h] [ebp-3CCh] BYREF
  float v85; // [esp+ACh] [ebp-3C8h]
  float v86; // [esp+B0h] [ebp-3C4h]
  int v87; // [esp+B4h] [ebp-3C0h]
  float v88; // [esp+B8h] [ebp-3BCh] BYREF
  float v89; // [esp+BCh] [ebp-3B8h]
  float v90; // [esp+C0h] [ebp-3B4h]
  float v91; // [esp+C4h] [ebp-3B0h]
  float v92; // [esp+C8h] [ebp-3ACh]
  int *v93; // [esp+CCh] [ebp-3A8h]
  float v94; // [esp+D0h] [ebp-3A4h]
  float v95; // [esp+D4h] [ebp-3A0h]
  float v96; // [esp+D8h] [ebp-39Ch]
  float v97; // [esp+DCh] [ebp-398h]
  float v98; // [esp+E0h] [ebp-394h]
  float v99; // [esp+E4h] [ebp-390h]
  float v100; // [esp+E8h] [ebp-38Ch]
  float *v101; // [esp+ECh] [ebp-388h]
  float v102; // [esp+F0h] [ebp-384h]
  float *v103; // [esp+F4h] [ebp-380h]
  float v104; // [esp+F8h] [ebp-37Ch]
  float v105; // [esp+FCh] [ebp-378h]
  float v106; // [esp+100h] [ebp-374h]
  float v107; // [esp+104h] [ebp-370h] BYREF
  _DWORD v108[88]; // [esp+108h] [ebp-36Ch] BYREF
  __int16 v109; // [esp+268h] [ebp-20Ch]
  _BYTE v110[48]; // [esp+298h] [ebp-1DCh] BYREF
  void **p_??_7CastResult@btConvexCast@@6B@; // [esp+2C8h] [ebp-1ACh] BYREF
  float v112; // [esp+358h] [ebp-11Ch]
  float v113; // [esp+35Ch] [ebp-118h]
  float v114; // [esp+360h] [ebp-114h]
  int v115; // [esp+364h] [ebp-110h]
  float v116; // [esp+368h] [ebp-10Ch]
  float v117; // [esp+36Ch] [ebp-108h]
  float v118; // [esp+370h] [ebp-104h]
  int v119; // [esp+374h] [ebp-100h]
  float v120; // [esp+378h] [ebp-FCh]
  int v121; // [esp+37Ch] [ebp-F8h]
  int v122; // [esp+380h] [ebp-F4h]
  float v123; // [esp+388h] [ebp-ECh] BYREF
  float v124; // [esp+38Ch] [ebp-E8h]
  float v125; // [esp+390h] [ebp-E4h]
  int v126; // [esp+394h] [ebp-E0h]
  float v127; // [esp+398h] [ebp-DCh]
  float v128; // [esp+39Ch] [ebp-D8h]
  float v129; // [esp+3A0h] [ebp-D4h]
  int v130; // [esp+3A4h] [ebp-D0h]
  float v131; // [esp+3A8h] [ebp-CCh]
  float v132; // [esp+3ACh] [ebp-C8h]
  float v133; // [esp+3B0h] [ebp-C4h]
  int v134; // [esp+3B4h] [ebp-C0h]
  float v135; // [esp+3B8h] [ebp-BCh]
  float v136; // [esp+3BCh] [ebp-B8h]
  float v137; // [esp+3C0h] [ebp-B4h]
  int v138; // [esp+3C4h] [ebp-B0h]
  float v139; // [esp+3C8h] [ebp-ACh] BYREF
  float v140; // [esp+3CCh] [ebp-A8h]
  float v141; // [esp+3D0h] [ebp-A4h]
  int v142; // [esp+3D4h] [ebp-A0h]
  float v143; // [esp+3D8h] [ebp-9Ch]
  float v144; // [esp+3DCh] [ebp-98h]
  float v145; // [esp+3E0h] [ebp-94h]
  int v146; // [esp+3E4h] [ebp-90h]
  float v147; // [esp+3E8h] [ebp-8Ch]
  float v148; // [esp+3ECh] [ebp-88h]
  float v149; // [esp+3F0h] [ebp-84h]
  int v150; // [esp+3F4h] [ebp-80h]
  float v151; // [esp+3F8h] [ebp-7Ch]
  float v152; // [esp+3FCh] [ebp-78h]
  float v153; // [esp+400h] [ebp-74h]
  int v154; // [esp+404h] [ebp-70h]
  float v155; // [esp+408h] [ebp-6Ch] BYREF
  float v156; // [esp+40Ch] [ebp-68h]
  float v157; // [esp+410h] [ebp-64h]
  float v158; // [esp+418h] [ebp-5Ch]
  float v159; // [esp+41Ch] [ebp-58h]
  float v160; // [esp+420h] [ebp-54h]
  int v161; // [esp+424h] [ebp-50h]
  float v162; // [esp+428h] [ebp-4Ch]
  float v163; // [esp+42Ch] [ebp-48h]
  float v164; // [esp+430h] [ebp-44h]
  int v165; // [esp+434h] [ebp-40h]
  float v166; // [esp+438h] [ebp-3Ch]
  float v167; // [esp+43Ch] [ebp-38h]
  float v168; // [esp+440h] [ebp-34h]
  int v169; // [esp+444h] [ebp-30h]
  int *v170; // [esp+458h] [ebp-1Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+45Ch] [ebp-18h]
  void *v172; // [esp+460h] [ebp-14h]
  int n3; // [esp+464h] [ebp-10h]
  int v174; // [esp+468h] [ebp-Ch]
  void *v175; // [esp+46Ch] [ebp-8h]
  int v176; // [esp+470h] [ebp-4h] BYREF
  void *retaddr; // [esp+474h] [ebp+0h]

  v174 = a1;
  v175 = retaddr;
  n3 = -1;
  v172 = &loc_AD8B72;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v170 = &v176;
  v9 = a7;
  n31 = a6[1];
  v11 = a8;
  v93 = a2;
  v103 = a3;
  v101 = a4;
  v92 = a5;
  v107 = *(float *)&a6;
  v64 = a7;
  v83 = a8;
  if ( n31 >= 20 )
  {
    result = n31 - 21;
    if ( (unsigned int)(n31 - 21) > 8 )
    {
      if ( n31 == 31 )
      {
        v50 = a6[4] <= 0;
        v96 = 0.0;
        if ( !v50 )
        {
          result = LODWORD(v107);
          v87 = 0;
          v51 = 0;
          do
          {
            v52 = *(_DWORD *)(result + 24);
            v105 = v9[9];
            v53 = v9[8];
            v139 = *(float *)(v51 + v52);
            v99 = v53;
            v54 = v9[10];
            v140 = *(float *)(v51 + v52 + 4);
            v106 = v54;
            v141 = *(float *)(v51 + v52 + 8);
            v142 = *(_DWORD *)(v51 + v52 + 12);
            v143 = *(float *)(v51 + v52 + 16);
            v144 = *(float *)(v51 + v52 + 20);
            v145 = *(float *)(v51 + v52 + 24);
            v146 = *(_DWORD *)(v51 + v52 + 28);
            v147 = *(float *)(v51 + v52 + 32);
            v148 = *(float *)(v51 + v52 + 36);
            v149 = *(float *)(v51 + v52 + 40);
            v150 = *(_DWORD *)(v51 + v52 + 44);
            v151 = *(float *)(v51 + v52 + 48);
            v152 = *(float *)(v51 + v52 + 52);
            v153 = *(float *)(v51 + v52 + 56);
            v55 = *(_DWORD *)(v51 + v52 + 60);
            v56 = *(_DWORD *)(v51 + v52 + 64);
            v154 = v55;
            v100 = v106 * v153 + v105 * v152 + v99 * v151;
            v73 = v100 + v9[14];
            v98 = v9[5];
            v94 = v9[4];
            v97 = v9[6];
            v100 = v94 * v151 + v98 * v152 + v97 * v153;
            v74 = v100 + v9[13];
            v102 = v9[1];
            v57 = *v9;
            v85 = v74;
            v104 = v57;
            v58 = v9[2];
            v86 = v73;
            v95 = v58;
            v100 = v152 * v102 + v151 * v104 + v153 * v95;
            v84 = v100 + v9[12];
            v65 = v99 * v141 + v105 * v145 + v106 * v149;
            v66 = v106 * v148 + v105 * v144 + v99 * v140;
            v99 = v106 * v147 + v105 * v143 + v99 * v139;
            v105 = v94 * v141 + v98 * v145 + v97 * v149;
            v106 = v94 * v140 + v98 * v144 + v97 * v148;
            v161 = 0;
            v165 = 0;
            v169 = 0;
            v100 = v94 * v139 + v98 * v143 + v97 * v147;
            v74 = v104 * v141 + v102 * v145 + v95 * v149;
            v160 = v74;
            v162 = v100;
            v163 = v106;
            v164 = v105;
            v166 = v99;
            v167 = v66;
            v168 = v65;
            v73 = v148 * v95 + v144 * v102 + v104 * v140;
            v158 = v147 * v95 + v143 * v102 + v139 * v104;
            v123 = v158;
            v159 = v73;
            v124 = v73;
            v125 = v74;
            v126 = 0;
            v127 = v100;
            v128 = v106;
            v129 = v105;
            v130 = 0;
            v131 = v99;
            v132 = v66;
            v133 = v65;
            v134 = 0;
            v135 = v84;
            v136 = v85;
            v137 = v86;
            v138 = v87;
            n1065353216 = 1065353216;
            v59 = *(_DWORD *)(LODWORD(v92) + 204);
            *(_DWORD *)(LODWORD(v92) + 204) = v56;
            v69 = 1;
            v70 = -1;
            p_??_7LocalInfoAdder@?CB@??objectQuerySingle@btCollisionWorld@@ = &`btCollisionWorld::objectQuerySingle'::`33'::LocalInfoAdder::`vftable';
            v71 = v11;
            v72 = v96;
            n1065353216 = *((_DWORD *)v11 + 1);
            sub_982C40(v93, v103);
            v60 = v96;
            v11 = v83;
            *(_DWORD *)(LODWORD(v92) + 204) = v59;
            result = LODWORD(v107);
            v9 = v64;
            n3 = -1;
            LODWORD(v96) = LODWORD(v60) + 1;
            v51 += 80;
          }
          while ( LODWORD(v60) + 1 < *(_DWORD *)(LODWORD(v107) + 16) );
        }
      }
    }
    else if ( n31 == 21 )
    {
      sub_982990(a7, (int)&v155);
      v15 = v103;
      v16 = v101;
      v17 = v103[13];
      v91 = 0.0;
      v106 = v17;
      v107 = v103[12];
      v18 = v107;
      v19 = v106;
      v20 = v103[14];
      v107 = v164 * v20 + v163 * v106 + v162 * v107;
      v105 = v107 + v168;
      v90 = v105;
      v107 = v158 * v18 + v159 * v106 + v160 * v20;
      v106 = v107 + v167;
      v107 = v19 * v156 + v18 * v155 + v20 * v157;
      v88 = v107 + v166;
      v89 = v106;
      v106 = v101[13];
      v107 = v101[12];
      v105 = v101[14];
      v21 = v107;
      v22 = v106;
      v87 = 0;
      v23 = v105;
      v79 = 0.0;
      v80 = 0.0;
      v81 = 0.0;
      v82 = 0.0;
      v107 = v164 * v105 + v163 * v106 + v162 * v107;
      v105 = v107 + v168;
      v86 = v105;
      v107 = v158 * v21 + v159 * v106 + v160 * v23;
      v106 = v167 + v107;
      v107 = v23 * v157 + v22 * v156 + v21 * v155;
      v84 = v166 + v107;
      v85 = v106;
      v101 = *((float **)v101 + 6);
      v103 = *((float **)v16 + 2);
      v102 = v16[10];
      v98 = v162 * *(float *)&v103 + v163 * *(float *)&v101 + v164 * v102;
      v107 = v16[5];
      v104 = v16[1];
      v106 = v16[9];
      v24 = v107;
      v25 = v106;
      v97 = v164 * v106 + v163 * v107 + v162 * v104;
      v106 = v16[4];
      v107 = *v16;
      v26 = v106;
      v27 = v16[8];
      v28 = v107;
      v95 = v164 * v27 + v163 * v106 + v162 * v107;
      v96 = v158 * *(float *)&v103 + v159 * *(float *)&v101 + v160 * v102;
      v99 = v158 * v104 + v159 * v24 + v160 * v25;
      v105 = v158 * v107 + v159 * v106 + v160 * v27;
      v106 = v155 * *(float *)&v103 + v156 * *(float *)&v101 + v157 * v102;
      v107 = v25 * v157 + v24 * v156 + v155 * v104;
      v158 = v26 * v156 + v28 * v155 + v157 * v27;
      v159 = v107;
      v139 = v158;
      v140 = v107;
      v160 = v106;
      v141 = v106;
      v162 = v105;
      v161 = 0;
      v142 = 0;
      v143 = v105;
      v163 = v99;
      v144 = v99;
      v164 = v96;
      v145 = v96;
      v165 = 0;
      v146 = 0;
      v166 = v95;
      v147 = v95;
      v167 = v97;
      v148 = v97;
      v168 = v98;
      v149 = v98;
      v169 = 0;
      v150 = 0;
      v151 = 0.0;
      v152 = 0.0;
      v153 = 0.0;
      v154 = 0;
      sub_97B660(v93, v15, v16, v83, LODWORD(v92), a6, a7);
      v29 = v83[1];
      v30 = *v93;
      n3 = 3;
      v116 = v29;
      (*(void (__thiscall **)(int *, float *, float *, float *))(v30 + 4))(v93, &v139, v63, v62);
      sub_973860(v110, &v88, &v84, v63, v62);
      n3 = -1;
      return sub_98ACB0(v110);
    }
    else
    {
      sub_982990(a7, (int)&v155);
      v31 = v103;
      v32 = v101;
      v33 = v103[13];
      v82 = 0.0;
      v106 = v33;
      v107 = v103[12];
      v34 = v107;
      v35 = v106;
      v36 = v103[14];
      v107 = v164 * v36 + v163 * v106 + v162 * v107;
      v105 = v107 + v168;
      v81 = v105;
      v107 = v158 * v34 + v159 * v106 + v160 * v36;
      v106 = v107 + v167;
      v107 = v35 * v156 + v34 * v155 + v36 * v157;
      v79 = v107 + v166;
      v80 = v106;
      v106 = v101[13];
      v107 = v101[12];
      v105 = v101[14];
      v37 = v107;
      v84 = 0.0;
      v85 = 0.0;
      v86 = 0.0;
      v87 = 0;
      v107 = v164 * v105 + v163 * v106 + v162 * v107;
      v95 = v107 + v168;
      v107 = v158 * v37 + v159 * v106 + v160 * v105;
      v96 = v167 + v107;
      v107 = v105 * v157 + v106 * v156 + v37 * v155;
      v62[0] = v166 + v107;
      v101 = *((float **)v101 + 6);
      v103 = *((float **)v32 + 2);
      v102 = v32[10];
      v100 = v102 * v164 + *(float *)&v101 * v163 + *(float *)&v103 * v162;
      v107 = v32[5];
      v104 = v32[1];
      v106 = v32[9];
      v38 = v107;
      v39 = v106;
      v94 = v164 * v106 + v163 * v107 + v162 * v104;
      v106 = v32[4];
      v161 = 0;
      v107 = *v32;
      v40 = v107;
      v41 = v106;
      v42 = v32[8];
      v98 = v107 * v162 + v106 * v163 + v42 * v164;
      v97 = *(float *)&v103 * v158 + *(float *)&v101 * v159 + v102 * v160;
      v99 = v104 * v158 + v38 * v159 + v39 * v160;
      v105 = v107 * v158 + v106 * v159 + v42 * v160;
      v106 = *(float *)&v103 * v155 + *(float *)&v101 * v156 + v102 * v157;
      v160 = v106;
      v107 = v39 * v157 + v38 * v156 + v104 * v155;
      v158 = v156 * v41 + v40 * v155 + v157 * v42;
      v159 = v107;
      v139 = v158;
      v140 = v107;
      v141 = v106;
      v142 = 0;
      v162 = v105;
      v143 = v105;
      v163 = v99;
      v144 = v99;
      v164 = v97;
      v145 = v97;
      v165 = 0;
      v146 = 0;
      v166 = v98;
      v147 = v98;
      v167 = v94;
      v148 = v94;
      v168 = v100;
      v149 = v100;
      v169 = 0;
      v150 = 0;
      v151 = 0.0;
      v152 = 0.0;
      v153 = 0.0;
      v154 = 0;
      sub_97B6B0(v93, v31, v32, v83, LODWORD(v92), a6, a7);
      v43 = v83[1];
      v44 = *v93;
      n3 = 4;
      v116 = v43;
      (*(void (__thiscall **)(int *, float *, float *, float *))(v44 + 4))(v93, &v139, v61, v63);
      v88 = v79;
      v89 = v80;
      v90 = v81;
      v91 = v82;
      if ( v79 > (double)v62[0] )
        v88 = v62[0];
      v45 = v89;
      if ( v89 > (double)v96 )
      {
        v89 = v96;
        v45 = v96;
      }
      v46 = v90;
      if ( v90 > (double)v95 )
      {
        v90 = v95;
        v46 = v95;
      }
      if ( v91 > 0.0 )
        v91 = 0.0;
      v75 = v79;
      v76 = v80;
      v77 = v81;
      v78 = v82;
      if ( v62[0] > (double)v79 )
        v75 = v62[0];
      v47 = v76;
      if ( v96 > (double)v76 )
      {
        v76 = v96;
        v47 = v96;
      }
      v48 = v77;
      if ( v95 > (double)v77 )
      {
        v77 = v95;
        v48 = v95;
      }
      if ( v78 < 0.0 )
        v78 = 0.0;
      v49 = *a6;
      v88 = v61[0] + v88;
      v89 = v45 + v61[1];
      v90 = v46 + v61[2];
      v75 = v63[0] + v75;
      v76 = v47 + v63[1];
      v77 = v48 + v63[2];
      (*(void (__thiscall **)(int *, _BYTE *, float *, float *))(v49 + 56))(a6, v110, &v88, &v75);
      n3 = -1;
      return sub_98ACB0(v110);
    }
  }
  else
  {
    p_??_7CastResult@btConvexCast@@6B@ = &btConvexCast::CastResult::`vftable';
    v121 = 0;
    v122 = a9;
    v12 = a8[1];
    n3 = 1;
    v120 = v12;
    v108[80] = 953267991;
    v109 &= 0xFFF0u;
    v107 = COERCE_FLOAT(&btGjkEpaPenetrationDepthSolver::`vftable');
    sub_9A6E40(v93, a6, v108, &v107);
    v13 = p_??_7LocalInfoAdder@?CB@??objectQuerySingle@btCollisionWorld@@[1];
    LOBYTE(n3) = 2;
    if ( ((unsigned __int8 (__thiscall *)(int (__stdcall ***)(char), float *, float *, float *, float *, void ***))v13)(
           &p_??_7LocalInfoAdder@?CB@??objectQuerySingle@btCollisionWorld@@,
           v103,
           v101,
           a7,
           a7,
           &p_??_7CastResult@btConvexCast@@6B@) )
    {
      v106 = v112 * v112 + v113 * v113 + v114 * v114;
      if ( v106 > 0.00009999999747378752 && v83[1] > (double)v120 )
      {
        v106 = sqrt(v106);
        v123 = v92;
        v124 = 0.0;
        v135 = v120;
        v106 = 1.0 / v106;
        v112 = v112 * v106;
        v127 = v112;
        v113 = v113 * v106;
        v128 = v113;
        v114 = v106 * v114;
        v129 = v114;
        v130 = v115;
        v131 = v116;
        v132 = v117;
        v133 = v118;
        v134 = v119;
        (*(void (__thiscall **)(float *, float *, int))(*(_DWORD *)v83 + 8))(v83, &v123, 1);
      }
    }
    LOBYTE(n3) = 1;
    return sub_9A6040(&p_??_7LocalInfoAdder@?CB@??objectQuerySingle@btCollisionWorld@@);
  }
  return result;
}
