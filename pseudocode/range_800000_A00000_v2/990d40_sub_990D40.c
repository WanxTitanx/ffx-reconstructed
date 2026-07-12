// Function: sub_990D40
// Address: 0x990d40
int __userpurge sub_990D40@<eax>(
        int a1@<ecx>,
        int a2@<ebp>,
        int a3,
        float *a4,
        float *a5,
        float *a6,
        float *a7,
        int a8,
        int a9)
{
  double v9; // st7
  unsigned __int16 *v10; // esi
  double v11; // st3
  double v12; // st6
  double v13; // st4
  double v14; // st6
  double v15; // st6
  float v16; // ecx
  float v17; // xmm3_4
  float v18; // eax
  float v19; // edx
  double v20; // st4
  double v21; // st3
  double v22; // st2
  double v23; // st6
  double v24; // st5
  double v25; // st2
  double v26; // st6
  float v27; // xmm4_4
  double v28; // st6
  double v29; // st5
  float v30; // xmm0_4
  double v31; // st4
  double v32; // st3
  double v33; // st2
  float v34; // eax
  int v35; // ecx
  int v36; // eax
  double v37; // st5
  double v38; // st4
  double v39; // st3
  unsigned __int16 v40; // di
  int v41; // edx
  bool v42; // cl
  int v43; // edi
  int v44; // edx
  int v45; // ecx
  double v46; // st7
  double v47; // st7
  double v48; // st6
  double v49; // st7
  double v50; // st6
  double v51; // st5
  double v52; // st6
  double v53; // st4
  double v54; // st3
  double v55; // st2
  double v56; // st6
  float v57; // xmm1_4
  double v58; // st7
  double v59; // st6
  double v60; // rt2
  double v61; // st5
  int v62; // eax
  char v63; // cl
  int v64; // ecx
  int v65; // edx
  int result; // eax
  float v67; // [esp-170h] [ebp-17Ch]
  float v68; // [esp-16Ch] [ebp-178h]
  float v69; // [esp-168h] [ebp-174h]
  float v70; // [esp-160h] [ebp-16Ch]
  float v71; // [esp-15Ch] [ebp-168h]
  float v72; // [esp-158h] [ebp-164h]
  float v73; // [esp-150h] [ebp-15Ch]
  float v74; // [esp-14Ch] [ebp-158h]
  float v75; // [esp-148h] [ebp-154h]
  float v76; // [esp-140h] [ebp-14Ch]
  float v77; // [esp-13Ch] [ebp-148h]
  float v78; // [esp-138h] [ebp-144h]
  float v79; // [esp-124h] [ebp-130h]
  float v80; // [esp-120h] [ebp-12Ch]
  float v81; // [esp-11Ch] [ebp-128h]
  float v82[2]; // [esp-118h] [ebp-124h]
  float v83; // [esp-110h] [ebp-11Ch]
  float v84; // [esp-10Ch] [ebp-118h]
  float v85[5]; // [esp-108h] [ebp-114h]
  float *v86; // [esp-F4h] [ebp-100h]
  int v87; // [esp-F0h] [ebp-FCh]
  BOOL v88; // [esp-ECh] [ebp-F8h]
  BOOL v89; // [esp-E8h] [ebp-F4h]
  BOOL v90; // [esp-E4h] [ebp-F0h]
  float v91; // [esp-E0h] [ebp-ECh]
  float v92; // [esp-DCh] [ebp-E8h]
  float v93; // [esp-D8h] [ebp-E4h]
  int v94; // [esp-D4h] [ebp-E0h]
  float v95; // [esp-D0h] [ebp-DCh]
  float v96; // [esp-CCh] [ebp-D8h]
  float v97; // [esp-C8h] [ebp-D4h]
  int v98; // [esp-C4h] [ebp-D0h]
  unsigned __int16 v99; // [esp-B4h] [ebp-C0h]
  unsigned __int16 v100; // [esp-B2h] [ebp-BEh]
  unsigned __int16 v101; // [esp-B0h] [ebp-BCh]
  int v102; // [esp-ACh] [ebp-B8h]
  unsigned __int16 v103; // [esp-A8h] [ebp-B4h]
  __int16 v104; // [esp-A6h] [ebp-B2h]
  __int16 v105; // [esp-A4h] [ebp-B0h]
  float v106; // [esp-A0h] [ebp-ACh]
  float v107; // [esp-9Ch] [ebp-A8h]
  float v108; // [esp-98h] [ebp-A4h]
  float v109; // [esp-94h] [ebp-A0h]
  float v110; // [esp-90h] [ebp-9Ch]
  float v111; // [esp-8Ch] [ebp-98h]
  float v112; // [esp-88h] [ebp-94h]
  float v113; // [esp-84h] [ebp-90h]
  float v114; // [esp-80h] [ebp-8Ch]
  float v115; // [esp-7Ch] [ebp-88h]
  float v116; // [esp-78h] [ebp-84h]
  float v117; // [esp-74h] [ebp-80h]
  float v118; // [esp-70h] [ebp-7Ch]
  float v119; // [esp-6Ch] [ebp-78h]
  float v120; // [esp-68h] [ebp-74h]
  float v121; // [esp-64h] [ebp-70h]
  float v122; // [esp-54h] [ebp-60h]
  float v123; // [esp-50h] [ebp-5Ch]
  float v124; // [esp-4Ch] [ebp-58h]
  float v125; // [esp-48h] [ebp-54h]
  float v126; // [esp-3Ch] [ebp-48h]
  double v127; // [esp-38h] [ebp-44h]
  float v128; // [esp-2Ch] [ebp-38h]
  double v129; // [esp-28h] [ebp-34h]
  float v130; // [esp-1Ch] [ebp-28h]
  float v131; // [esp-18h] [ebp-24h]
  float v132; // [esp-14h] [ebp-20h]
  float v133; // [esp-10h] [ebp-1Ch]
  float v134; // [esp-Ch] [ebp-18h]
  int v135; // [esp-8h] [ebp-14h]
  float v136; // [esp-4h] [ebp-10h]
  int v137; // [esp+0h] [ebp-Ch]
  void *v138; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v137 = a2;
  v138 = retaddr;
  v134 = *a5;
  v9 = v134 - *a4;
  v10 = (unsigned __int16 *)(*(_DWORD *)(a1 + 148) + 16 * a8);
  v86 = (float *)a1;
  v132 = v9;
  v102 = 0;
  v123 = v132;
  v130 = a5[1];
  v128 = v130 - a4[1];
  v124 = v128;
  v136 = a5[2];
  v133 = v136 - a4[2];
  *((float *)&v129 + 1) = v124 * v124 + v123 * v123 + v133 * v133;
  *((float *)&v129 + 1) = sqrt(*((float *)&v129 + 1));
  *((float *)&v129 + 1) = 1.0 / *((float *)&v129 + 1);
  v123 = v132 * *((float *)&v129 + 1);
  v124 = v128 * *((float *)&v129 + 1);
  v125 = *((float *)&v129 + 1) * v133;
  v79 = v133 * v125 + v128 * v124 + v132 * v123;
  v11 = 9.999999843067494e17;
  if ( v123 != 0.0 )
    v11 = 1.0 / v123;
  v123 = v11;
  if ( v124 == 0.0 )
  {
    v12 = v125;
    v13 = 9.999999843067494e17;
  }
  else
  {
    v13 = 1.0 / v124;
    v12 = v125;
  }
  v124 = v13;
  if ( v125 == 0.0 )
    v14 = 9.999999843067494e17;
  else
    v14 = 1.0 / v12;
  v125 = v14;
  v88 = v123 < 0.0;
  v89 = v124 < 0.0;
  v90 = v125 < 0.0;
  v15 = v134;
  v16 = a4[3];
  v17 = v134;
  v114 = *a4;
  v115 = a4[1];
  v116 = a4[2];
  v118 = *a4;
  v119 = a4[1];
  v18 = a4[2];
  v19 = v16;
  v117 = v16;
  v120 = v18;
  v121 = v16;
  if ( v114 > (double)v134 )
    v114 = v134;
  v20 = v115;
  if ( v115 > (double)v130 )
  {
    v115 = v130;
    v20 = v130;
  }
  v21 = v116;
  if ( v116 > (double)v136 )
  {
    v116 = v136;
    v21 = v136;
  }
  v134 = a5[3];
  if ( v117 > (double)v134 )
  {
    v117 = v134;
    v16 = v134;
  }
  v22 = v15;
  v23 = v118;
  if ( v22 > v118 )
  {
    v118 = v17;
    v23 = v17;
  }
  v24 = v119;
  if ( v130 > (double)v119 )
  {
    v119 = v130;
    v24 = v130;
  }
  v25 = v120;
  if ( v136 > (double)v120 )
  {
    v120 = v136;
    v25 = v136;
  }
  if ( v134 > (double)v121 )
  {
    v121 = v134;
    v19 = v134;
  }
  v109 = v16;
  v114 = v114 + *a6;
  v115 = v20 + a6[1];
  v116 = v21 + a6[2];
  v118 = v23 + *a7;
  v119 = v24 + a7[1];
  v26 = v25 + a7[2];
  v106 = v114;
  v120 = v26;
  v107 = v115;
  v136 = v86[4];
  v27 = v136;
  v108 = v116;
  v28 = v136;
  if ( v136 > (double)v114 )
    v106 = v136;
  v132 = v86[5];
  v29 = v107;
  v30 = v132;
  v31 = v132;
  if ( v132 > (double)v107 )
  {
    v107 = v132;
    v29 = v132;
  }
  v130 = v86[6];
  v32 = v108;
  if ( v130 > (double)v108 )
  {
    v108 = v130;
    v32 = v130;
  }
  v133 = v86[8];
  v33 = v106;
  if ( v106 > (double)v133 )
  {
    v106 = v133;
    v33 = v133;
  }
  v128 = v86[9];
  if ( v29 > v128 )
  {
    v107 = v128;
    v29 = v128;
  }
  v132 = v86[10];
  if ( v32 > v132 )
  {
    v108 = v132;
    v32 = v132;
  }
  v113 = v19;
  v73 = v33 - v28;
  v136 = v86[5];
  v74 = v29 - v136;
  v134 = v86[6];
  v75 = v32 - v134;
  v122 = v86[12];
  v67 = v73 * v122;
  v131 = v86[13];
  v68 = v74 * v131;
  LODWORD(v34) = (int)v68;
  v135 = *((int *)v86 + 14);
  v35 = (int)v67;
  v69 = v75 * *(float *)&v135;
  LOWORD(v34) = (int)v68 & 0xFFFE;
  v100 = LOWORD(v34);
  LOWORD(v35) = (int)v67 & 0xFFFE;
  v99 = v35;
  v126 = v34;
  v36 = (int)v69;
  HIDWORD(v129) = v35;
  LOWORD(v36) = (int)v69 & 0xFFFE;
  v101 = v36;
  v87 = v36;
  v110 = v118;
  v111 = v119;
  v112 = v120;
  if ( v28 > v118 )
    v110 = v27;
  v37 = v111;
  if ( v31 > v111 )
  {
    v111 = v30;
    v37 = v30;
  }
  v38 = v112;
  if ( v130 > (double)v112 )
  {
    v112 = v130;
    v38 = v130;
  }
  v39 = v110;
  if ( v110 > (double)v133 )
  {
    v110 = v133;
    v39 = v133;
  }
  if ( v37 > v128 )
  {
    v111 = v128;
    v37 = v128;
  }
  if ( v38 > v132 )
  {
    v112 = v132;
    v38 = v132;
  }
  v76 = v39 - v28;
  v77 = v37 - v136;
  v78 = v38 - v134;
  v70 = v76 * v122;
  v71 = v77 * v131;
  v72 = v78 * *(float *)&v135;
  v40 = (int)(v70 + 1.0) | 1;
  HIWORD(v136) = v40;
  v103 = v40;
  HIWORD(v134) = (int)(v71 + 1.0) | 1;
  v104 = HIWORD(v134);
  v135 = (int)(v72 + 1.0);
  HIWORD(v130) = v135 | 1;
  v105 = v135 | 1;
  if ( a8 < a9 )
  {
    do
    {
      ++v102;
      v128 = 0.0;
      v41 = v10[3];
      LODWORD(v131) = v10[2];
      v135 = v10[1];
      LODWORD(v132) = v10[5];
      LODWORD(v122) = v10[4];
      v42 = v40 >= *v10 && (unsigned __int16)v41 >= (unsigned __int16)v35;
      v43 = *((_DWORD *)v10 + 3);
      HIDWORD(v127) = v41;
      v44 = a8;
      v45 = HIWORD(v130) >= LOWORD(v131)
         && HIWORD(v134) >= (unsigned __int16)v135
         && LOWORD(v132) >= (unsigned __int16)v87
         && LOWORD(v122) >= LOWORD(v126)
         && v42;
      HIBYTE(v133) = v43 >= 0;
      if ( (v45 | -v45) >= 0 )
      {
        v62 = 0;
      }
      else
      {
        v46 = v86[12];
        HIDWORD(v129) = *v10;
        v126 = v46;
        v129 = (double)SHIDWORD(v129);
        v47 = v129;
        HIDWORD(v129) = (unsigned __int16)v135;
        v48 = v47 / v126;
        v49 = v126;
        v91 = v48;
        v126 = v86[13];
        v129 = (double)(unsigned __int16)v135;
        v50 = v129;
        HIDWORD(v129) = LOWORD(v131);
        v51 = v50 / v126;
        v52 = v126;
        v92 = v51;
        v126 = v86[14];
        v129 = (double)LOWORD(v131);
        v94 = 0;
        v93 = v129 / v126;
        v136 = v86[4];
        v53 = v136;
        v91 = v136 + v91;
        v54 = v86[5];
        v80 = v91;
        v136 = v54;
        v92 = v92 + v136;
        v55 = v86[6];
        v81 = v92;
        v134 = v55;
        v93 = v93 + v134;
        v82[0] = v93;
        v82[1] = 0.0;
        v127 = (double)WORD2(v127);
        v95 = v127 / v49;
        v127 = (double)LOWORD(v122);
        v96 = v127 / v52;
        v127 = (double)LOWORD(v132);
        v98 = 0;
        v97 = v127 / v126;
        v95 = v53 + v95;
        v83 = v95;
        v96 = v136 + v96;
        v84 = v96;
        v97 = v134 + v97;
        v85[0] = v97;
        v85[1] = 0.0;
        v80 = v91 - *a7;
        v81 = v92 - a7[1];
        v82[0] = v93 - a7[2];
        v83 = v95 - *a6;
        v84 = v96 - a6[1];
        v85[0] = v97 - a6[2];
        *((float *)&v127 + 1) = *a4;
        v136 = (*(&v80 + 4 * v88) - *((float *)&v127 + 1)) * v123;
        v134 = v123 * (*(&v83 - 4 * v88) - *((float *)&v127 + 1));
        *((float *)&v127 + 1) = a4[1];
        *(float *)&v135 = (v82[4 * v89 - 1] - *((float *)&v127 + 1)) * v124;
        v131 = v124 * (v85[-4 * v89 - 1] - *((float *)&v127 + 1));
        v56 = v136;
        if ( v136 > (double)v131 || *(float *)&v135 > (double)v134 )
          goto LABEL_67;
        if ( *(float *)&v135 > v56 )
        {
          v136 = *(float *)&v135;
          v56 = *(float *)&v135;
        }
        if ( v134 <= (double)v131 )
        {
          v57 = v134;
          v60 = v56;
          v59 = v134;
          v58 = v60;
        }
        else
        {
          v57 = v131;
          v58 = v56;
          v134 = v131;
          v59 = v131;
        }
        *((float *)&v127 + 1) = a4[2];
        *(float *)&v135 = (v82[4 * v90] - *((float *)&v127 + 1)) * v125;
        v131 = v125 * (v85[-4 * v90] - *((float *)&v127 + 1));
        v61 = v58;
        if ( v58 > v131 || *(float *)&v135 > v59 )
          goto LABEL_67;
        if ( *(float *)&v135 > v58 )
        {
          v136 = *(float *)&v135;
          v61 = *(float *)&v135;
        }
        if ( v59 > v131 )
          v57 = v131;
        if ( v79 <= v61 || v57 <= 0.0 )
LABEL_67:
          LOBYTE(v62) = 0;
        else
          LOBYTE(v62) = 1;
        v87 = v101;
        LODWORD(v126) = v100;
        HIDWORD(v129) = v99;
        HIWORD(v130) = v105;
        v62 = (unsigned __int8)v62;
        HIWORD(v134) = v104;
        LODWORD(v128) = (unsigned __int8)v62;
        HIWORD(v136) = v103;
      }
      v63 = HIBYTE(v133);
      if ( HIBYTE(v133) )
      {
        if ( !v62 )
          goto LABEL_74;
        (*(void (__thiscall **)(int, int, int))(*(_DWORD *)a3 + 4))(a3, v43 >> 21, v43 & 0x1FFFFF);
        v44 = a8;
        v63 = HIBYTE(v133);
      }
      if ( v128 != 0.0 )
        goto LABEL_76;
LABEL_74:
      if ( v63 )
      {
LABEL_76:
        v10 += 8;
        v65 = v44 + 1;
        goto LABEL_77;
      }
      v64 = -*((_DWORD *)v10 + 3);
      v10 -= 8 * *((_DWORD *)v10 + 3);
      v65 = v64 + v44;
LABEL_77:
      v40 = HIWORD(v136);
      LOWORD(v35) = WORD2(v129);
      a8 = v65;
    }
    while ( v65 < a9 );
  }
  result = dword_193F244;
  if ( dword_193F244 < v102 )
    result = v102;
  dword_193F244 = result;
  return result;
}
