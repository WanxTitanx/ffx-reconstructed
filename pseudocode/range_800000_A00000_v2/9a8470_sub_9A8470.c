// Function: sub_9A8470
// Address: 0x9a8470
char __userpurge sub_9A8470@<al>(int a1@<ecx>, int a2@<ebp>, int a3, int *a4, float a5)
{
  int v6; // eax
  int v7; // eax
  int n17; // eax
  int n17_1; // eax
  float v10; // xmm0_4
  bool v11; // zf
  float *v12; // edi
  double v13; // st7
  int v14; // ecx
  float *v15; // eax
  double v16; // st7
  double v17; // st6
  double v18; // st5
  double v19; // st4
  double v20; // st7
  double v21; // st6
  double v22; // st5
  double v23; // st7
  int n1000; // ecx
  double v25; // st7
  double v26; // st6
  double v27; // st5
  long double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  float v32; // eax
  float *v33; // edx
  long double v34; // st7
  double v35; // st7
  double v36; // st6
  double v37; // st5
  float v38; // xmm0_4
  double v39; // st7
  double v40; // st6
  int *v41; // ecx
  double v42; // st6
  double v43; // st6
  double v44; // st6
  int v45; // eax
  float v46; // eax
  double v47; // st7
  float v49; // [esp+28h] [ebp-1E0h]
  float v50; // [esp+3Ch] [ebp-1CCh] BYREF
  float v51; // [esp+40h] [ebp-1C8h]
  float v52; // [esp+44h] [ebp-1C4h]
  float v53; // [esp+4Ch] [ebp-1BCh] BYREF
  float v54; // [esp+50h] [ebp-1B8h]
  float v55; // [esp+54h] [ebp-1B4h]
  float v56[7]; // [esp+5Ch] [ebp-1ACh] BYREF
  int *v57; // [esp+78h] [ebp-190h]
  float v58; // [esp+7Ch] [ebp-18Ch]
  float v59; // [esp+80h] [ebp-188h]
  float v60; // [esp+84h] [ebp-184h]
  float v61; // [esp+8Ch] [ebp-17Ch] BYREF
  float v62; // [esp+90h] [ebp-178h]
  float v63; // [esp+94h] [ebp-174h]
  int v64; // [esp+98h] [ebp-170h]
  float v65; // [esp+A0h] [ebp-168h]
  float *v66; // [esp+A4h] [ebp-164h]
  float v67; // [esp+A8h] [ebp-160h]
  float v68; // [esp+ACh] [ebp-15Ch] BYREF
  float v69; // [esp+B0h] [ebp-158h]
  float v70; // [esp+B4h] [ebp-154h]
  int v71; // [esp+B8h] [ebp-150h]
  float v72; // [esp+BCh] [ebp-14Ch] BYREF
  float v73; // [esp+C0h] [ebp-148h]
  float v74; // [esp+C4h] [ebp-144h]
  int v75; // [esp+C8h] [ebp-140h]
  float v76; // [esp+CCh] [ebp-13Ch] BYREF
  float v77; // [esp+D0h] [ebp-138h]
  float v78; // [esp+D4h] [ebp-134h]
  int v79; // [esp+D8h] [ebp-130h]
  float v80; // [esp+E0h] [ebp-128h]
  float v81; // [esp+E4h] [ebp-124h]
  float v82; // [esp+E8h] [ebp-120h]
  float v83; // [esp+ECh] [ebp-11Ch] BYREF
  float v84; // [esp+F0h] [ebp-118h]
  float v85; // [esp+F4h] [ebp-114h]
  int v86; // [esp+F8h] [ebp-110h]
  float v87; // [esp+FCh] [ebp-10Ch] BYREF
  float v88; // [esp+100h] [ebp-108h]
  float v89; // [esp+104h] [ebp-104h]
  float v90; // [esp+108h] [ebp-100h]
  float v91; // [esp+10Ch] [ebp-FCh] BYREF
  float v92; // [esp+110h] [ebp-F8h]
  float v93; // [esp+114h] [ebp-F4h]
  int v94; // [esp+118h] [ebp-F0h]
  float v95; // [esp+11Ch] [ebp-ECh] BYREF
  float v96; // [esp+120h] [ebp-E8h]
  float v97; // [esp+124h] [ebp-E4h]
  float v98; // [esp+128h] [ebp-E0h]
  float v99; // [esp+138h] [ebp-D0h]
  float v100; // [esp+13Ch] [ebp-CCh]
  float v101; // [esp+140h] [ebp-C8h]
  float v102; // [esp+144h] [ebp-C4h]
  float v103; // [esp+150h] [ebp-B8h]
  float v104; // [esp+154h] [ebp-B4h]
  bool v105; // [esp+15Bh] [ebp-ADh]
  float v106; // [esp+15Ch] [ebp-ACh]
  float v107; // [esp+160h] [ebp-A8h]
  char v108; // [esp+167h] [ebp-A1h]
  float v109; // [esp+168h] [ebp-A0h]
  float v110; // [esp+16Ch] [ebp-9Ch] BYREF
  float v111; // [esp+170h] [ebp-98h]
  float v112; // [esp+174h] [ebp-94h]
  int v113; // [esp+178h] [ebp-90h]
  float v114; // [esp+17Ch] [ebp-8Ch]
  float v115; // [esp+180h] [ebp-88h]
  float v116; // [esp+184h] [ebp-84h]
  int v117; // [esp+188h] [ebp-80h]
  float v118; // [esp+18Ch] [ebp-7Ch]
  float v119; // [esp+190h] [ebp-78h]
  float v120; // [esp+194h] [ebp-74h]
  int v121; // [esp+198h] [ebp-70h]
  float v122; // [esp+19Ch] [ebp-6Ch]
  float v123; // [esp+1A0h] [ebp-68h]
  float v124; // [esp+1A4h] [ebp-64h]
  int v125; // [esp+1A8h] [ebp-60h]
  float v126; // [esp+1ACh] [ebp-5Ch] BYREF
  float v127; // [esp+1B0h] [ebp-58h]
  float v128; // [esp+1B4h] [ebp-54h]
  int v129; // [esp+1B8h] [ebp-50h]
  float v130; // [esp+1BCh] [ebp-4Ch]
  float v131; // [esp+1C0h] [ebp-48h]
  float v132; // [esp+1C4h] [ebp-44h]
  int v133; // [esp+1C8h] [ebp-40h]
  float v134; // [esp+1CCh] [ebp-3Ch]
  float v135; // [esp+1D0h] [ebp-38h]
  float v136; // [esp+1D4h] [ebp-34h]
  int v137; // [esp+1D8h] [ebp-30h]
  float v138; // [esp+1DCh] [ebp-2Ch]
  float v139; // [esp+1E0h] [ebp-28h]
  float v140; // [esp+1E4h] [ebp-24h]
  int v141; // [esp+1E8h] [ebp-20h]
  int v142; // [esp+1FCh] [ebp-Ch]
  void *v143; // [esp+200h] [ebp-8h]
  void *retaddr; // [esp+208h] [ebp+0h]

  v142 = a2;
  v143 = retaddr;
  v57 = a4;
  v107 = a5;
  *(_DWORD *)(a1 + 68) = 0;
  v126 = *(float *)a3;
  v127 = *(float *)(a3 + 4);
  v128 = *(float *)(a3 + 8);
  v129 = *(_DWORD *)(a3 + 12);
  v130 = *(float *)(a3 + 16);
  v131 = *(float *)(a3 + 20);
  v132 = *(float *)(a3 + 24);
  v133 = *(_DWORD *)(a3 + 28);
  v134 = *(float *)(a3 + 32);
  v135 = *(float *)(a3 + 36);
  v136 = *(float *)(a3 + 40);
  v137 = *(_DWORD *)(a3 + 44);
  v138 = *(float *)(a3 + 48);
  v139 = *(float *)(a3 + 52);
  v140 = *(float *)(a3 + 56);
  v141 = *(_DWORD *)(a3 + 60);
  v110 = *(float *)(a3 + 64);
  v111 = *(float *)(a3 + 68);
  v112 = *(float *)(a3 + 72);
  v113 = *(_DWORD *)(a3 + 76);
  v114 = *(float *)(a3 + 80);
  v115 = *(float *)(a3 + 84);
  v116 = *(float *)(a3 + 88);
  v117 = *(_DWORD *)(a3 + 92);
  v118 = *(float *)(a3 + 96);
  v119 = *(float *)(a3 + 100);
  v120 = *(float *)(a3 + 104);
  v121 = *(_DWORD *)(a3 + 108);
  v122 = *(float *)(a3 + 112);
  v123 = *(float *)(a3 + 116);
  v124 = *(float *)(a3 + 120);
  v6 = *(_DWORD *)(a3 + 124);
  v66 = (float *)a3;
  v104 = 0.0;
  v95 = 0.0;
  v96 = 0.0;
  v97 = 0.0;
  v98 = 0.0;
  v125 = v6;
  v7 = *(_DWORD *)(a1 + 40);
  v72 = v122 + v138;
  v73 = v123 + v139;
  v74 = v124 + v140;
  v58 = v72 * 0.5;
  v59 = v73 * 0.5;
  v60 = 0.5 * v74;
  v138 = v138 - v58;
  v139 = v139 - v59;
  v140 = v140 - v60;
  v122 = v122 - v58;
  v123 = v123 - v59;
  v124 = v124 - v60;
  n17 = *(_DWORD *)(v7 + 4);
  v105 = (n17 == 17 || n17 == 18) && ((n17_1 = *(_DWORD *)(*(_DWORD *)(a1 + 44) + 4), n17_1 == 17) || n17_1 == 18);
  v65 = *(float *)(a1 + 56);
  v10 = *(float *)(a1 + 60);
  ++unk_193F654;
  v11 = *(_BYTE *)(a1 + 64) == 0;
  v67 = v10;
  if ( !v11 )
  {
    v65 = 0.0;
    v67 = 0.0;
  }
  v12 = (float *)(a1 + 16);
  v13 = v67 + v65;
  *(_DWORD *)(a1 + 76) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 1065353216;
  *(_DWORD *)(a1 + 24) = 0;
  v103 = v13;
  *(_DWORD *)(a1 + 28) = 0;
  v14 = *(_DWORD *)(a1 + 36);
  v108 = 0;
  *(_DWORD *)(a1 + 80) = 0;
  *(_DWORD *)(a1 + 72) = -1;
  v82 = 9.9999998e17;
  sub_9B39F0(v14);
  while ( 1 )
  {
    v15 = v66;
    v16 = *v66;
    v80 = *v12;
    v100 = -v80;
    v17 = (float)-v80;
    v81 = *(float *)(a1 + 20);
    v101 = -v81;
    v18 = (float)-v81;
    v19 = v18 * v66[4];
    v99 = *(float *)(a1 + 24);
    v102 = -v99;
    v56[3] = 0.0;
    v64 = 0;
    v56[0] = v16 * v17 + v19 + (float)-v99 * v66[8];
    v56[1] = v15[1] * v17 + v18 * v15[5] + (float)-v99 * v15[9];
    v56[2] = (float)-v99 * v15[10] + v17 * v15[2] + v18 * v15[6];
    v61 = v15[24] * v99 + v15[16] * v80 + v81 * v15[20];
    v62 = v15[21] * v81 + v80 * v15[17] + v66[25] * v99;
    v63 = v99 * v66[26] + v80 * v66[18] + v81 * v66[22];
    sub_969B20(&v50, v56);
    sub_969B20(&v53, &v61);
    v90 = 0.0;
    v109 = v127 * v51 + v126 * v50 + v52 * v128;
    v87 = v109 + v138;
    v109 = v50 * v130 + v51 * v131 + v52 * v132;
    v88 = v109 + v139;
    v109 = v51 * v135 + v50 * v134 + v52 * v136;
    v89 = v109 + v140;
    v109 = v53 * v110 + v54 * v111 + v55 * v112;
    v83 = v109 + v122;
    v109 = v53 * v114 + v54 * v115 + v55 * v116;
    v84 = v109 + v123;
    v86 = 0;
    v109 = v53 * v118 + v54 * v119 + v55 * v120;
    v85 = v109 + v124;
    if ( v105 )
    {
      v89 = 0.0;
      v85 = 0.0;
    }
    v75 = 0;
    v72 = v87 - v83;
    v73 = v88 - v84;
    v74 = v89 - v85;
    v109 = v72 * *(float *)(a1 + 16) + v73 * *(float *)(a1 + 20) + v74 * *(float *)(a1 + 24);
    if ( v109 > 0.0 && v109 * v109 > v66[32] * v82 )
    {
      *(_DWORD *)(a1 + 80) = 10;
      goto LABEL_30;
    }
    if ( (unsigned __int8)sub_9B3580(&v72) )
    {
      *(_DWORD *)(a1 + 80) = 1;
      goto LABEL_30;
    }
    v109 = v82 - v109;
    v106 = v82 * 0.0000009999999974752427;
    if ( v106 >= (double)v109 )
      break;
    sub_9B2800(&v72, &v87, &v83);
    if ( !(unsigned __int8)sub_9B28D0(&v91) )
    {
      *(_DWORD *)(a1 + 80) = 3;
      goto LABEL_30;
    }
    v20 = v92;
    v21 = v93;
    *v12 = v91;
    v22 = v91 * v91;
    *(float *)(a1 + 20) = v92;
    *(float *)(a1 + 24) = v93;
    *(_DWORD *)(a1 + 28) = v94;
    v106 = v22 + v20 * v20 + v21 * v21;
    v23 = v106;
    if ( v106 < 0.000001 )
    {
      *(_DWORD *)(a1 + 80) = 6;
      goto LABEL_30;
    }
    v106 = v82;
    v82 = v23;
    if ( v106 * 0.0000001192092895507812 >= v106 - v82 )
    {
      sub_9B28A0(a1 + 16);
      *(_DWORD *)(a1 + 80) = 12;
      goto LABEL_30;
    }
    n1000 = *(_DWORD *)(a1 + 76);
    *(_DWORD *)(a1 + 76) = n1000 + 1;
    if ( n1000 > 1000 )
      goto LABEL_35;
    if ( **(_DWORD **)(a1 + 36) == 4 )
    {
      sub_9B28A0(a1 + 16);
      *(_DWORD *)(a1 + 80) = 13;
      goto LABEL_35;
    }
  }
  if ( v109 > 0.0 )
    *(_DWORD *)(a1 + 80) = 11;
  else
    *(_DWORD *)(a1 + 80) = 2;
LABEL_30:
  sub_9B3420(&v68, &v76);
  v75 = 0;
  v72 = v68 - v76;
  v95 = v72;
  v73 = v69 - v77;
  v96 = v73;
  v74 = v70 - v78;
  v25 = *(float *)(a1 + 20);
  v97 = v74;
  v26 = *(float *)(a1 + 24);
  v27 = *v12;
  v98 = 0.0;
  v109 = v27 * v27 + v25 * v25 + v26 * v26;
  v28 = v109;
  if ( v109 < 0.0001 )
    *(_DWORD *)(a1 + 80) = 5;
  if ( v109 > 1.4210855e-14 )
  {
    v106 = sqrt(v28);
    v109 = 1.0 / v106;
    v95 = v72 * v109;
    v96 = v96 * v109;
    v97 = v109 * v97;
    v106 = sqrt(v82);
    v29 = v106;
    v106 = v65 / v106;
    v80 = *v12;
    v100 = v106 * v80;
    v81 = *(float *)(a1 + 20);
    v101 = v106 * v81;
    v99 = *(float *)(a1 + 24);
    v102 = v106 * v99;
    v68 = v68 - v100;
    v69 = v69 - v101;
    v70 = v70 - v102;
    v106 = v67 / v29;
    v100 = v80 * v106;
    v101 = v81 * v106;
    v102 = v106 * v99;
    v76 = v100 + v76;
    v77 = v101 + v77;
    v108 = 1;
    v30 = v102;
    *(_DWORD *)(a1 + 72) = 1;
    v78 = v30 + v78;
    v31 = v103;
    v104 = 1.0 / v109 - v103;
    goto LABEL_36;
  }
  *(_DWORD *)(a1 + 72) = 2;
LABEL_35:
  v31 = v103;
LABEL_36:
  LOBYTE(v32) = *(_DWORD *)(a1 + 84) && *(_DWORD *)(a1 + 32) && *(_DWORD *)(a1 + 80) && v31 + v104 < 0.01;
  if ( v108 && !LOBYTE(v32) || !*(_DWORD *)(a1 + 32) )
    goto LABEL_53;
  ++unk_193F650;
  v33 = v66;
  *v12 = 0.0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 28) = 0;
  LOBYTE(v32) = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, float *, float *, int, float *, float *, float, _DWORD))(**(_DWORD **)(a1 + 32) + 4))(
                  *(_DWORD *)(a1 + 32),
                  *(_DWORD *)(a1 + 36),
                  *(_DWORD *)(a1 + 40),
                  *(_DWORD *)(a1 + 44),
                  &v126,
                  &v110,
                  a1 + 16,
                  &v83,
                  &v91,
                  COERCE_FLOAT(LODWORD(v107)),
                  *((_DWORD *)v33 + 33));
  if ( LOBYTE(v32) )
  {
    v90 = 0.0;
    v87 = v91 - v83;
    v88 = v92 - v84;
    v89 = v93 - v85;
    v103 = v87 * v87 + v88 * v88 + v89 * v89;
    v34 = v103;
    if ( v103 > 1.4210855e-14 )
    {
      v32 = v90;
    }
    else
    {
      v35 = *(float *)(a1 + 20);
      v87 = *v12;
      v36 = *(float *)(a1 + 24);
      v37 = *v12;
      v88 = *(float *)(a1 + 20);
      v89 = *(float *)(a1 + 24);
      v32 = *(float *)(a1 + 28);
      v103 = v37 * v37 + v35 * v35 + v36 * v36;
      v34 = v103;
    }
    v99 = v32;
    if ( v103 <= 1.4210855e-14 )
    {
      *(_DWORD *)(a1 + 72) = 9;
    }
    else
    {
      v107 = sqrt(v34);
      v107 = 1.0 / v107;
      v87 = v107 * v87;
      v88 = v107 * v88;
      v89 = v107 * v89;
      v100 = v83 - v91;
      v101 = v84 - v92;
      v102 = v85 - v93;
      v107 = v100 * v100 + v101 * v101 + v102 * v102;
      v107 = sqrt(v107);
      v109 = -v107;
      if ( !v108 || v104 > (double)v109 )
      {
        v68 = v83;
        v69 = v84;
        v70 = v85;
        v38 = v109;
        v71 = v86;
        v76 = v91;
        v77 = v92;
        v78 = v93;
        v79 = v94;
        v95 = v87;
        v96 = v88;
        v97 = v89;
        v104 = v109;
        v98 = v99;
        *(_DWORD *)(a1 + 72) = 3;
        goto LABEL_55;
      }
      *(_DWORD *)(a1 + 72) = 8;
    }
    goto LABEL_53;
  }
  v81 = *(float *)(a1 + 20);
  v99 = *v12;
  v80 = *(float *)(a1 + 24);
  v107 = v99 * v99 + v81 * v81 + v80 * v80;
  if ( v107 <= 0.0 )
  {
LABEL_53:
    if ( !v108 )
      return LOBYTE(v32);
    goto LABEL_54;
  }
  v100 = v83 - v91;
  v101 = v84 - v92;
  v102 = v85 - v93;
  v107 = v100 * v100 + v101 * v101 + v102 * v102;
  v107 = sqrt(v107);
  v109 = v107 - v103;
  if ( v108 && v104 <= (double)v109 )
  {
    *(_DWORD *)(a1 + 72) = 5;
    goto LABEL_53;
  }
  v68 = v83;
  v69 = v84;
  v70 = v85;
  v100 = v99 * v65;
  v71 = v86;
  v76 = v91;
  v77 = v92;
  v101 = v81 * v65;
  v78 = v93;
  v79 = v94;
  v95 = *v12;
  v102 = v65 * v80;
  v96 = *(float *)(a1 + 20);
  v97 = *(float *)(a1 + 24);
  v46 = *(float *)(a1 + 28);
  v68 = v83 - v100;
  v104 = v109;
  v98 = v46;
  v69 = v84 - v101;
  v70 = v85 - v102;
  v100 = v99 * v67;
  v101 = v81 * v67;
  v102 = v67 * v80;
  v76 = v100 + v91;
  v77 = v101 + v92;
  v78 = v102 + v93;
  v107 = v96 * v96 + v95 * v95 + v97 * v97;
  v107 = sqrt(v107);
  v47 = v107;
  *(_DWORD *)(a1 + 72) = 6;
  v107 = 1.0 / v47;
  v95 = v95 * v107;
  v96 = v96 * v107;
  v97 = v107 * v97;
LABEL_54:
  v38 = v104;
LABEL_55:
  v39 = v104;
  if ( v38 < 0.0 || (LOBYTE(v32) = (_BYTE)v66, v66[32] > v39 * v39) )
  {
    v40 = v76 + v58;
    v41 = v57;
    *v12 = v95;
    v61 = v40;
    *(float *)(a1 + 20) = v96;
    v42 = v77 + v59;
    *(float *)(a1 + 24) = v97;
    v62 = v42;
    v43 = v78;
    *(float *)(a1 + 28) = v98;
    v44 = v43 + v60;
    *(float *)(a1 + 68) = v38;
    v45 = *v41;
    v64 = 0;
    v63 = v44;
    v49 = v39;
    LOBYTE(v32) = (*(int (__thiscall **)(int *, float *, float *, _DWORD))(v45 + 12))(v41, &v95, &v61, LODWORD(v49));
  }
  return LOBYTE(v32);
}
