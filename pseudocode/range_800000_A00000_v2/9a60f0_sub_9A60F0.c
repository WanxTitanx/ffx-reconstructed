// Function: sub_9A60F0
// Address: 0x9a60f0
// bad sp value at call has been detected, the output may be wrong!
char __userpurge sub_9A60F0@<al>(
        _DWORD *a1@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        float *a5,
        float *a6,
        float *a7,
        float *a8,
        void ***p_p_??_7CastResult@btConvexCast@@6B@)
{
  double v11; // st7
  double v12; // st7
  double v13; // st7
  float v14; // eax
  int v15; // eax
  int v16; // ecx
  float *v17; // eax
  double v18; // st7
  double v20; // st6
  double v21; // st7
  int v22; // ecx
  double v23; // st5
  double v24; // st3
  double v25; // st7
  double v26; // st4
  float *v28; // eax
  double v29; // st7
  int n32; // ecx
  double v31; // st7
  double v32; // st7
  double v33; // st6
  double v34; // st5
  double v35; // st4
  double v36; // st7
  double v37; // st6
  double v38; // st5
  double v39; // st4
  double v40; // st3
  double v41; // st2
  int v42; // ecx
  float *v43; // eax
  double v44; // st6
  int v45; // ecx
  float *v46; // eax
  double v47; // st6
  double v48; // st6
  double v49; // st5
  double v51; // st7
  double v52; // st6
  int v54; // [esp-1C0h] [ebp-1CCh] BYREF
  _BYTE v55[16]; // [esp-1B0h] [ebp-1BCh] BYREF
  _BYTE v56[16]; // [esp-1A0h] [ebp-1ACh] BYREF
  float v57[4]; // [esp-190h] [ebp-19Ch] BYREF
  _DWORD v58[4]; // [esp-180h] [ebp-18Ch] BYREF
  float v59[4]; // [esp-170h] [ebp-17Ch] BYREF
  float v60; // [esp-160h] [ebp-16Ch] BYREF
  float v61; // [esp-15Ch] [ebp-168h]
  __int64 v62; // [esp-158h] [ebp-164h]
  float v63; // [esp-150h] [ebp-15Ch] BYREF
  float v64; // [esp-14Ch] [ebp-158h]
  float v65; // [esp-148h] [ebp-154h]
  int v66; // [esp-144h] [ebp-150h]
  float v67; // [esp-140h] [ebp-14Ch]
  float v68; // [esp-13Ch] [ebp-148h]
  float v69; // [esp-138h] [ebp-144h]
  int v70; // [esp-134h] [ebp-140h]
  float v71; // [esp-130h] [ebp-13Ch]
  float v72; // [esp-12Ch] [ebp-138h]
  float v73; // [esp-128h] [ebp-134h]
  int v74; // [esp-124h] [ebp-130h]
  float v75; // [esp-120h] [ebp-12Ch]
  float v76; // [esp-11Ch] [ebp-128h]
  float v77; // [esp-118h] [ebp-124h]
  int v78; // [esp-114h] [ebp-120h]
  float v79; // [esp-110h] [ebp-11Ch]
  float v80; // [esp-10Ch] [ebp-118h]
  float v81; // [esp-108h] [ebp-114h]
  float v82; // [esp-100h] [ebp-10Ch] BYREF
  float v83; // [esp-FCh] [ebp-108h]
  float v84; // [esp-F8h] [ebp-104h]
  int v85; // [esp-F4h] [ebp-100h]
  float v86; // [esp-F0h] [ebp-FCh] BYREF
  float v87; // [esp-ECh] [ebp-F8h]
  float v88; // [esp-E8h] [ebp-F4h]
  int v89; // [esp-E4h] [ebp-F0h]
  float v90; // [esp-E0h] [ebp-ECh] BYREF
  float v91; // [esp-DCh] [ebp-E8h]
  float v92; // [esp-D8h] [ebp-E4h]
  int v93; // [esp-D4h] [ebp-E0h]
  float v94; // [esp-D0h] [ebp-DCh]
  float v95; // [esp-CCh] [ebp-D8h]
  float v96; // [esp-C8h] [ebp-D4h]
  int v97; // [esp-C4h] [ebp-D0h]
  float v98; // [esp-C0h] [ebp-CCh]
  float v99; // [esp-BCh] [ebp-C8h]
  float v100; // [esp-B8h] [ebp-C4h]
  float v101; // [esp-B4h] [ebp-C0h]
  float v102; // [esp-B0h] [ebp-BCh]
  float v103; // [esp-ACh] [ebp-B8h]
  __int64 v104; // [esp-A8h] [ebp-B4h]
  int n32_1; // [esp-A0h] [ebp-ACh]
  float v106; // [esp-9Ch] [ebp-A8h]
  float v107; // [esp-98h] [ebp-A4h]
  float v108; // [esp-94h] [ebp-A0h]
  float v109; // [esp-90h] [ebp-9Ch]
  float v110; // [esp-8Ch] [ebp-98h]
  float v111; // [esp-88h] [ebp-94h]
  int v112; // [esp-84h] [ebp-90h]
  float v113; // [esp-80h] [ebp-8Ch]
  float v114; // [esp-7Ch] [ebp-88h]
  float v115; // [esp-78h] [ebp-84h]
  int v116; // [esp-74h] [ebp-80h]
  float v117; // [esp-70h] [ebp-7Ch]
  float v118; // [esp-6Ch] [ebp-78h]
  float v119; // [esp-68h] [ebp-74h]
  int v120; // [esp-64h] [ebp-70h]
  float v121; // [esp-60h] [ebp-6Ch]
  float v122; // [esp-5Ch] [ebp-68h]
  float v123; // [esp-58h] [ebp-64h]
  int v124; // [esp-54h] [ebp-60h]
  float v125; // [esp-50h] [ebp-5Ch]
  float v126; // [esp-4Ch] [ebp-58h]
  float v127; // [esp-48h] [ebp-54h]
  int v128; // [esp-44h] [ebp-50h]
  float v129; // [esp-40h] [ebp-4Ch]
  float v130; // [esp-3Ch] [ebp-48h]
  float v131; // [esp-38h] [ebp-44h]
  int v132; // [esp-34h] [ebp-40h]
  float v133; // [esp-30h] [ebp-3Ch]
  float v134; // [esp-2Ch] [ebp-38h]
  float v135; // [esp-28h] [ebp-34h]
  int v136; // [esp-24h] [ebp-30h]
  float v137; // [esp-20h] [ebp-2Ch]
  float v138; // [esp-1Ch] [ebp-28h]
  float v139; // [esp-18h] [ebp-24h]
  int v140; // [esp-14h] [ebp-20h]
  _BYTE *v141; // [esp-Ch] [ebp-18h]
  float *v142; // [esp-8h] [ebp-14h]
  int v143; // [esp+0h] [ebp-Ch]
  void *v144; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v143 = a2;
  v144 = retaddr;
  sub_9B39F0(a1[1], a3, a4);
  v11 = a6[12] - a5[12];
  v99 = 0.0;
  v102 = v11;
  v103 = a6[13] - a5[13];
  *(float *)&v104 = a6[14] - a5[14];
  v75 = a8[12] - a7[12];
  v76 = a8[13] - a7[13];
  v12 = a8[14];
  v125 = *a5;
  v13 = v12 - a7[14];
  v126 = a5[1];
  v14 = a5[2];
  v77 = v13;
  v127 = v14;
  v128 = *((_DWORD *)a5 + 3);
  v129 = a5[4];
  v130 = a5[5];
  v131 = a5[6];
  v132 = *((_DWORD *)a5 + 7);
  v133 = a5[8];
  v134 = a5[9];
  v135 = a5[10];
  v136 = *((_DWORD *)a5 + 11);
  v137 = a5[12];
  v138 = a5[13];
  v139 = a5[14];
  v140 = *((_DWORD *)a5 + 15);
  v109 = *a7;
  v110 = a7[1];
  v111 = a7[2];
  v112 = *((_DWORD *)a7 + 3);
  v113 = a7[4];
  v114 = a7[5];
  v115 = a7[6];
  v116 = *((_DWORD *)a7 + 7);
  v117 = a7[8];
  v118 = a7[9];
  v119 = a7[10];
  v15 = *((_DWORD *)a7 + 11);
  v79 = v102 - v75;
  v120 = v15;
  v121 = a7[12];
  v122 = a7[13];
  v80 = v103 - v76;
  v123 = a7[14];
  v124 = *((_DWORD *)a7 + 15);
  v81 = *(float *)&v104 - v77;
  v89 = 0;
  v102 = -v79;
  v103 = -v80;
  *(float *)&v104 = -v81;
  v86 = *a5 * v102 + v103 * a5[4] + *(float *)&v104 * a5[8];
  v87 = a5[5] * v103 + a5[1] * v102 + a5[9] * *(float *)&v104;
  v16 = a1[2];
  v88 = *(float *)&v104 * a5[10] + v102 * a5[2] + v103 * a5[6];
  v17 = (float *)(*(int (__thiscall **)(int, float *, float *))(*(_DWORD *)v16 + 56))(v16, v59, &v86);
  v107 = v17[1];
  v108 = *v17;
  v18 = v17[2];
  v106 = v18;
  v20 = v107;
  v21 = a5[9] * v107;
  v22 = a1[3];
  v23 = v108;
  v85 = 0;
  v89 = 0;
  v24 = v21 + v108 * a5[8];
  v25 = v106;
  v107 = a5[10] * v106 + v24;
  v106 = v107 + a5[14];
  v26 = a5[5] * v20;
  v84 = v106;
  v107 = v26 + v108 * a5[4] + a5[6] * v25;
  v108 = v107 + a5[13];
  v107 = v25 * a5[2] + v20 * a5[1] + v23 * *a5;
  v82 = v107 + a5[12];
  v83 = v108;
  v86 = *a7 * v79 + v80 * a7[4] + v81 * a7[8];
  v87 = a7[5] * v80 + v79 * a7[1] + a7[9] * v81;
  v88 = v81 * a7[10] + v79 * a7[2] + v80 * a7[6];
  v28 = (float *)(*(int (__thiscall **)(int, float *, float *))(*(_DWORD *)v22 + 56))(v22, v59, &v86);
  v29 = v28[1];
  v97 = 0;
  v107 = v29;
  n32 = 32;
  v31 = *v28;
  v71 = 0.0;
  v108 = v31;
  v72 = 0.0;
  v106 = v28[2];
  v66 = 0;
  v32 = a7[9];
  v73 = 0.0;
  v33 = v107;
  v34 = v108;
  v107 = a7[10] * v106 + v32 * v107 + v108 * a7[8];
  v98 = v107 + a7[14];
  v35 = a7[5] * v33;
  v65 = v98;
  v107 = v35 + v108 * a7[4] + a7[6] * v106;
  v108 = v107 + a7[13];
  v107 = v106 * a7[2] + v33 * a7[1] + v34 * *a7;
  v63 = v107 + a7[12];
  v64 = v108;
  v94 = v82 - v63;
  v90 = v94;
  v95 = v83 - v108;
  v91 = v95;
  v96 = v84 - v98;
  v92 = v96;
  v93 = 0;
  v107 = v94 * v94 + v95 * v95 + v96 * v96;
  if ( v107 > 0.00009999999747378752 )
  {
    v36 = v135;
    v37 = v134;
    v38 = v129;
    v39 = v92;
    v40 = v91;
    v41 = v90;
    while ( 1 )
    {
      n32_1 = n32 - 1;
      if ( !n32 )
        break;
      v42 = a1[2];
      v86 = -v41;
      v57[3] = 0.0;
      v142 = v57;
      v87 = -v40;
      v141 = v56;
      v88 = -v39;
      v57[0] = v133 * v88 + v125 * v86 + v38 * v87;
      v57[1] = v37 * v88 + v130 * v87 + v126 * v86;
      v57[2] = v86 * v127 + v87 * v131 + v88 * v36;
      v43 = (float *)(*(int (__thiscall **)(int, _BYTE *, float *))(*(_DWORD *)v42 + 56))(v42, v56, v57);
      v106 = v43[1];
      v108 = *v43;
      v100 = v43[2];
      v44 = v108;
      v108 = v127 * v100 + v126 * v106 + v125 * v108;
      v75 = v108 + v137;
      v45 = a1[3];
      v82 = v75;
      v78 = 0;
      v59[3] = 0.0;
      v108 = v129 * v44 + v130 * v106 + v131 * v100;
      v142 = v59;
      v141 = v55;
      v76 = v108 + v138;
      v83 = v76;
      v108 = v106 * v134 + v44 * v133 + v100 * v135;
      v77 = v108 + v139;
      v84 = v77;
      v85 = 0;
      v59[0] = v117 * v92 + v109 * v90 + v113 * v91;
      v59[1] = v114 * v91 + v110 * v90 + v118 * v92;
      v59[2] = v92 * v119 + v91 * v115 + v90 * v111;
      v46 = (float *)(*(int (__thiscall **)(int, _BYTE *, float *))(*(_DWORD *)v45 + 56))(v45, v55, v59);
      v106 = v46[1];
      v108 = *v46;
      v100 = v46[2];
      v47 = v108;
      v97 = 0;
      v70 = 0;
      v108 = v111 * v100 + v110 * v106 + v109 * v108;
      v94 = v108 + v121;
      v63 = v94;
      v108 = v113 * v47 + v114 * v106 + v115 * v100;
      v95 = v108 + v122;
      v64 = v95;
      v108 = v106 * v118 + v47 * v117 + v100 * v119;
      v96 = v108 + v123;
      v65 = v96;
      v66 = 0;
      v100 = v82 - v94;
      v67 = v100;
      v60 = v100;
      v106 = v83 - v95;
      v68 = v106;
      v61 = v106;
      v108 = v84 - v96;
      v69 = v108;
      v62 = LODWORD(v108);
      v98 = v108 * v92 + v100 * v90 + v106 * v91;
      if ( v99 > 1.0 )
        return 0;
      if ( v98 > 0.0 )
      {
        v101 = v90 * v79 + v91 * v80 + v92 * v81;
        if ( v101 >= -1.4210855e-14 )
          return 0;
        v102 = v100;
        v103 = v106;
        v104 = LODWORD(v108);
        v99 = v99 - v98 / v101;
        v101 = 1.0 - v99;
        v137 = v101 * a5[12] + v99 * a6[12];
        v138 = v101 * a5[13] + a6[13] * v99;
        v139 = v101 * a5[14] + v99 * a6[14];
        v121 = a8[12] * v99 + v101 * a7[12];
        v122 = a8[13] * v99 + v101 * a7[13];
        v48 = v101 * a7[14];
        v49 = a8[14];
        v60 = v100;
        v61 = v106;
        v62 = LODWORD(v108);
        v123 = v99 * v49 + v48;
        v71 = v90;
        v72 = v91;
        v73 = v92;
        v74 = v93;
      }
      if ( !(unsigned __int8)sub_9B3580(&v60) )
        sub_9B2800(&v60, &v82, &v63);
      v107 = (unsigned __int8)sub_9B28D0(&v90) ? v90 * v90 + v91 * v91 + v92 * v92 : 0.0;
      if ( v107 <= 0.00009999999747378752 )
        break;
      n32 = n32_1;
      v36 = v135;
      v37 = v134;
      v41 = v90;
      v38 = v129;
      v39 = v92;
      v40 = v91;
    }
  }
  v51 = v72;
  v52 = v73;
  *((float *)p_p_??_7CastResult@btConvexCast@@6B@ + 44) = v99;
  *(float *)&n32_1 = v71 * v71 + v51 * v51 + v52 * v52;
  if ( *(float *)&n32_1 < 1.4210855e-14 )
  {
    v102 = 0.0;
    v103 = 0.0;
    LODWORD(v104) = 0;
  }
  else
  {
    *(float *)&n32_1 = sqrt(*(float *)&n32_1);
    *(float *)&n32_1 = 1.0 / *(float *)&n32_1;
    v102 = *(float *)&n32_1 * v71;
    v103 = *(float *)&n32_1 * v72;
    *(float *)&v104 = *(float *)&n32_1 * v73;
  }
  *((float *)p_p_??_7CastResult@btConvexCast@@6B@ + 36) = v102;
  *((float *)p_p_??_7CastResult@btConvexCast@@6B@ + 37) = v103;
  p_p_??_7CastResult@btConvexCast@@6B@[38] = (void **)v104;
  HIDWORD(v104) = 0;
  p_p_??_7CastResult@btConvexCast@@6B@[39] = 0;
  *(float *)&n32_1 = *((float *)p_p_??_7CastResult@btConvexCast@@6B@ + 37) * v80
                   + v79 * *((float *)p_p_??_7CastResult@btConvexCast@@6B@ + 36)
                   + *((float *)p_p_??_7CastResult@btConvexCast@@6B@ + 38) * v81;
  if ( *(float *)&n32_1 >= -*((float *)p_p_??_7CastResult@btConvexCast@@6B@ + 46) )
    return 0;
  sub_9B3420(&v54, v58);
  p_p_??_7CastResult@btConvexCast@@6B@[40] = (void **)v58[0];
  p_p_??_7CastResult@btConvexCast@@6B@[41] = (void **)v58[1];
  p_p_??_7CastResult@btConvexCast@@6B@[42] = (void **)v58[2];
  p_p_??_7CastResult@btConvexCast@@6B@[43] = (void **)v58[3];
  return 1;
}
