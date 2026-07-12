// Function: sub_9849E0
// Address: 0x9849e0
int __usercall sub_9849E0@<eax>(int a1@<ebp>, float *a2, float *a3, float a4, _DWORD *a5, float *a6, float *a7)
{
  _DWORD *v7; // esi
  int n31; // ecx
  float v9; // xmm0_4
  double v10; // st7
  double v11; // st5
  double v12; // st6
  double v13; // st4
  double v14; // st3
  double v15; // st4
  double v16; // st7
  double v17; // st7
  double v18; // st5
  double v19; // st6
  double v20; // st5
  double v21; // st3
  double v22; // st4
  float *v23; // edi
  int v24; // xmm0_4
  double v25; // st7
  double v26; // st7
  double v27; // st5
  double v28; // st6
  double v29; // st5
  double v30; // st3
  double v31; // st4
  float *v32; // edi
  int v33; // xmm0_4
  bool v34; // cc
  float v35; // edx
  int v36; // ecx
  int v37; // ecx
  int v38; // esi
  float v39; // ecx
  _DWORD v41[17]; // [esp-410h] [ebp-41Ch] BYREF
  float v42; // [esp-3CCh] [ebp-3D8h]
  _DWORD *v43; // [esp-3C8h] [ebp-3D4h]
  float v44; // [esp-3C4h] [ebp-3D0h]
  float v45; // [esp-3C0h] [ebp-3CCh] BYREF
  float v46; // [esp-3BCh] [ebp-3C8h]
  float v47; // [esp-3B8h] [ebp-3C4h]
  float v48; // [esp-3B4h] [ebp-3C0h]
  float v49; // [esp-3B0h] [ebp-3BCh] BYREF
  float v50; // [esp-3ACh] [ebp-3B8h]
  float v51; // [esp-3A8h] [ebp-3B4h]
  float v52; // [esp-3A4h] [ebp-3B0h]
  float v53; // [esp-3A0h] [ebp-3ACh]
  float v54; // [esp-39Ch] [ebp-3A8h]
  float v55; // [esp-398h] [ebp-3A4h]
  float v56; // [esp-394h] [ebp-3A0h]
  float v57; // [esp-390h] [ebp-39Ch] BYREF
  float v58; // [esp-38Ch] [ebp-398h]
  float v59; // [esp-388h] [ebp-394h]
  float v60[6]; // [esp-384h] [ebp-390h] BYREF
  float *v61; // [esp-36Ch] [ebp-378h]
  float v62; // [esp-368h] [ebp-374h]
  float v63; // [esp-364h] [ebp-370h]
  float v64; // [esp-360h] [ebp-36Ch]
  float v65; // [esp-35Ch] [ebp-368h]
  float v66; // [esp-358h] [ebp-364h]
  float v67; // [esp-354h] [ebp-360h]
  float v68; // [esp-350h] [ebp-35Ch]
  float *v69; // [esp-34Ch] [ebp-358h]
  float *v70; // [esp-348h] [ebp-354h]
  float v71; // [esp-344h] [ebp-350h]
  float v72; // [esp-340h] [ebp-34Ch] BYREF
  float v73; // [esp-33Ch] [ebp-348h]
  float v74; // [esp-338h] [ebp-344h]
  float v75; // [esp-334h] [ebp-340h]
  float v76; // [esp-32Ch] [ebp-338h]
  float v77; // [esp-328h] [ebp-334h]
  float v78; // [esp-324h] [ebp-330h]
  _DWORD v79[88]; // [esp-320h] [ebp-32Ch] BYREF
  __int16 v80; // [esp-1C0h] [ebp-1CCh]
  void **p_??_7CastResult@btConvexCast@@6B@; // [esp-190h] [ebp-19Ch] BYREF
  _BYTE v82[52]; // [esp-160h] [ebp-16Ch] BYREF
  int v83; // [esp-12Ch] [ebp-138h]
  float v84; // [esp-100h] [ebp-10Ch]
  float v85; // [esp-FCh] [ebp-108h]
  float v86; // [esp-F8h] [ebp-104h]
  int v87; // [esp-F4h] [ebp-100h]
  float v88; // [esp-E0h] [ebp-ECh]
  int v89; // [esp-DCh] [ebp-E8h]
  int v90; // [esp-D8h] [ebp-E4h]
  float v91; // [esp-D0h] [ebp-DCh]
  float v92; // [esp-CCh] [ebp-D8h]
  float v93; // [esp-C8h] [ebp-D4h]
  int v94; // [esp-C4h] [ebp-D0h]
  float v95; // [esp-C0h] [ebp-CCh]
  float v96; // [esp-BCh] [ebp-C8h]
  float v97; // [esp-B8h] [ebp-C4h]
  int v98; // [esp-B4h] [ebp-C0h]
  float v99; // [esp-B0h] [ebp-BCh]
  float v100; // [esp-ACh] [ebp-B8h]
  float v101; // [esp-A8h] [ebp-B4h]
  int v102; // [esp-A4h] [ebp-B0h]
  float v103; // [esp-A0h] [ebp-ACh]
  float v104; // [esp-9Ch] [ebp-A8h]
  float v105; // [esp-98h] [ebp-A4h]
  float v106; // [esp-94h] [ebp-A0h]
  float v107; // [esp-90h] [ebp-9Ch] BYREF
  float v108; // [esp-8Ch] [ebp-98h]
  float v109; // [esp-88h] [ebp-94h]
  int v110; // [esp-84h] [ebp-90h]
  float v111; // [esp-80h] [ebp-8Ch]
  float v112; // [esp-7Ch] [ebp-88h]
  float v113; // [esp-78h] [ebp-84h]
  int v114; // [esp-74h] [ebp-80h]
  float v115; // [esp-70h] [ebp-7Ch]
  float v116; // [esp-6Ch] [ebp-78h]
  float v117; // [esp-68h] [ebp-74h]
  int v118; // [esp-64h] [ebp-70h]
  float v119; // [esp-60h] [ebp-6Ch] BYREF
  float v120; // [esp-5Ch] [ebp-68h]
  float v121; // [esp-58h] [ebp-64h]
  int v122; // [esp-54h] [ebp-60h]
  float v123; // [esp-50h] [ebp-5Ch]
  float v124; // [esp-4Ch] [ebp-58h]
  float v125; // [esp-48h] [ebp-54h]
  int v126; // [esp-44h] [ebp-50h]
  float v127; // [esp-40h] [ebp-4Ch]
  float v128; // [esp-3Ch] [ebp-48h]
  float v129; // [esp-38h] [ebp-44h]
  int v130; // [esp-34h] [ebp-40h]
  float v131; // [esp-30h] [ebp-3Ch]
  float v132; // [esp-2Ch] [ebp-38h]
  float v133; // [esp-28h] [ebp-34h]
  int v134; // [esp-24h] [ebp-30h]
  int *v135; // [esp-10h] [ebp-1Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp-Ch] [ebp-18h]
  void *v137; // [esp-8h] [ebp-14h]
  int v138; // [esp-4h] [ebp-10h]
  int v139; // [esp+0h] [ebp-Ch]
  void *v140; // [esp+4h] [ebp-8h]
  int v141; // [esp+8h] [ebp-4h] BYREF
  void *retaddr; // [esp+Ch] [ebp+0h]

  v139 = a1;
  v140 = retaddr;
  v138 = -1;
  v137 = &loc_AD8C62;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v135 = &v141;
  v7 = a5;
  v61 = a3;
  v68 = a4;
  v70 = a6;
  v43 = a5;
  v69 = a7;
  sub_96A2F0(v41);
  v41[0] = &btSphereShape::`vftable';
  v41[1] = 8;
  v41[8] = 0;
  n31 = a5[1];
  v138 = 0;
  v41[12] = 0;
  if ( n31 >= 20 )
  {
    if ( (unsigned int)(n31 - 21) > 8 )
    {
      if ( n31 == 31 )
      {
        v34 = a5[4] <= 0;
        v53 = 0.0;
        if ( !v34 )
        {
          v35 = v68;
          v75 = 0.0;
          v77 = 0.0;
          do
          {
            v36 = v7[6];
            v119 = *(float *)(LODWORD(v77) + v36);
            v120 = *(float *)(LODWORD(v77) + v36 + 4);
            v121 = *(float *)(LODWORD(v77) + v36 + 8);
            v122 = *(_DWORD *)(LODWORD(v77) + v36 + 12);
            v123 = *(float *)(LODWORD(v77) + v36 + 16);
            v124 = *(float *)(LODWORD(v77) + v36 + 20);
            v125 = *(float *)(LODWORD(v77) + v36 + 24);
            v126 = *(_DWORD *)(LODWORD(v77) + v36 + 28);
            v127 = *(float *)(LODWORD(v77) + v36 + 32);
            v128 = *(float *)(LODWORD(v77) + v36 + 36);
            v129 = *(float *)(LODWORD(v77) + v36 + 40);
            v130 = *(_DWORD *)(LODWORD(v77) + v36 + 44);
            v131 = *(float *)(LODWORD(v77) + v36 + 48);
            v132 = *(float *)(LODWORD(v77) + v36 + 52);
            v133 = *(float *)(LODWORD(v77) + v36 + 56);
            v134 = *(_DWORD *)(LODWORD(v77) + v36 + 60);
            v37 = *(_DWORD *)(LODWORD(v77) + v36 + 64);
            v78 = v70[9];
            v76 = v70[8];
            v67 = v70[10];
            v71 = v133 * v67 + v132 * v78 + v131 * v76;
            v54 = v71 + v70[14];
            v62 = v70[5];
            v64 = v70[4];
            v66 = v70[6];
            v71 = v131 * v64 + v132 * v62 + v133 * v66;
            v55 = v71 + v70[13];
            v63 = v70[1];
            v73 = v55;
            v65 = *v70;
            v74 = v54;
            v71 = v70[2];
            v56 = v133 * v71 + v132 * v63 + v131 * v65;
            v72 = v56 + v70[12];
            v42 = v67 * v129 + v121 * v76 + v125 * v78;
            v44 = v78 * v124 + v120 * v76 + v128 * v67;
            v67 = v76 * v119 + v123 * v78 + v127 * v67;
            v76 = v121 * v64 + v125 * v62 + v129 * v66;
            v78 = v120 * v64 + v124 * v62 + v66 * v128;
            v110 = 0;
            v114 = 0;
            v118 = 0;
            v56 = v64 * v119 + v62 * v123 + v66 * v127;
            v55 = v121 * v65 + v125 * v63 + v129 * v71;
            v109 = v55;
            v111 = v56;
            v112 = v78;
            v113 = v76;
            v115 = v67;
            v116 = v44;
            v117 = v42;
            v54 = v128 * v71 + v124 * v63 + v120 * v65;
            v107 = v127 * v71 + v123 * v63 + v119 * v65;
            v91 = v107;
            v108 = v54;
            v92 = v54;
            v93 = v55;
            v94 = 0;
            v95 = v56;
            v96 = v78;
            v97 = v76;
            v98 = 0;
            v99 = v67;
            v100 = v44;
            v101 = v42;
            v102 = 0;
            v38 = *(_DWORD *)(LODWORD(v35) + 204);
            v103 = v72;
            v104 = v73;
            v105 = v74;
            v106 = v75;
            LOWORD(v60[0]) = 1;
            *(_DWORD *)(LODWORD(v35) + 204) = v37;
            HIWORD(v60[0]) = -1;
            v58 = 1.0;
            v59 = 0.0;
            v60[1] = 0.0;
            v57 = COERCE_FLOAT(&`btCollisionWorld::rayTestSingle'::`33'::LocalInfoAdder2::`vftable');
            LODWORD(v60[2]) = v69;
            v60[3] = v53;
            v58 = v69[1];
            LOBYTE(v138) = 5;
            sub_9849E0(a2, v61);
            v35 = v68;
            v39 = v53;
            LODWORD(v77) += 80;
            *(_DWORD *)(LODWORD(v68) + 204) = v38;
            v7 = v43;
            v57 = COERCE_FLOAT(&btCollisionWorld::RayResultCallback::`vftable');
            LODWORD(v53) = LODWORD(v39) + 1;
          }
          while ( LODWORD(v39) + 1 < v43[4] );
        }
      }
    }
    else if ( n31 == 21 )
    {
      sub_982990(v70, (int)&v119);
      v76 = a2[13];
      v16 = a2[12];
      v60[0] = 0.0;
      v78 = v16;
      v77 = a2[14];
      v17 = v78;
      v18 = v76;
      v19 = v77;
      v78 = v78 * v127 + v76 * v128 + v77 * v129;
      v77 = v78 + v133;
      v59 = v77;
      v78 = v17 * v123 + v76 * v124 + v19 * v125;
      v76 = v78 + v132;
      v78 = v19 * v121 + v17 * v119 + v18 * v120;
      v57 = v78 + v131;
      v58 = v76;
      v76 = v61[13];
      v78 = v61[12];
      v77 = v61[14];
      v20 = v78;
      v21 = v76;
      v22 = v77;
      v78 = v78 * v127 + v76 * v128 + v77 * v129;
      v77 = v78 + v133;
      v23 = v69;
      v78 = v20 * v123 + v76 * v124 + v22 * v125;
      v74 = v77;
      v75 = 0.0;
      v76 = v78 + v132;
      v78 = v121 * v22 + v20 * v119 + v21 * v120;
      v72 = v131 + v78;
      v73 = v76;
      sub_97B700(&v57, &v72, v69, LODWORD(v68), a5, v70);
      v24 = *((_DWORD *)v23 + 1);
      LOBYTE(v138) = 3;
      v83 = v24;
      sub_9738D0(v82, &v57, &v72);
      LOBYTE(v138) = 0;
      sub_98ACB0(v82);
    }
    else
    {
      sub_982990(v70, (int)&v119);
      v76 = a2[13];
      v25 = a2[12];
      v75 = 0.0;
      v78 = v25;
      v77 = a2[14];
      v26 = v78;
      v27 = v76;
      v28 = v77;
      v78 = v78 * v127 + v76 * v128 + v77 * v129;
      v77 = v78 + v133;
      v74 = v77;
      v78 = v26 * v123 + v76 * v124 + v28 * v125;
      v76 = v78 + v132;
      v78 = v28 * v121 + v26 * v119 + v27 * v120;
      v72 = v78 + v131;
      v73 = v76;
      v76 = v61[13];
      v78 = v61[12];
      v77 = v61[14];
      v29 = v78;
      v30 = v76;
      v31 = v77;
      v78 = v78 * v127 + v76 * v128 + v77 * v129;
      v77 = v78 + v133;
      v32 = v69;
      v78 = v29 * v123 + v76 * v124 + v31 * v125;
      v51 = v77;
      v52 = 0.0;
      v76 = v78 + v132;
      v78 = v121 * v31 + v29 * v119 + v30 * v120;
      v49 = v131 + v78;
      v50 = v76;
      sub_97B7B0(&v72, &v49, v69, LODWORD(v68), a5, v70);
      v33 = *((_DWORD *)v32 + 1);
      LOBYTE(v138) = 4;
      v83 = v33;
      v57 = v72;
      v58 = v73;
      v59 = v74;
      v60[0] = v75;
      if ( v72 > (double)v49 )
        v57 = v49;
      if ( v58 > (double)v50 )
        v58 = v50;
      if ( v59 > (double)v51 )
        v59 = v51;
      if ( v60[0] > (double)v52 )
        v60[0] = v52;
      v45 = v72;
      v46 = v73;
      v47 = v74;
      v48 = v75;
      if ( v49 > (double)v72 )
        v45 = v49;
      if ( v50 > (double)v46 )
        v46 = v50;
      if ( v51 > (double)v47 )
        v47 = v51;
      if ( v52 > (double)v48 )
        v48 = v52;
      (*(void (__thiscall **)(_DWORD *, _BYTE *, float *, float *))(*a5 + 56))(a5, v82, &v57, &v45);
      LOBYTE(v138) = 0;
      sub_98ACB0(v82);
    }
  }
  else
  {
    p_??_7CastResult@btConvexCast@@6B@ = &btConvexCast::CastResult::`vftable';
    v89 = 0;
    v90 = 0;
    v9 = v69[1];
    v80 &= 0xFFF0u;
    LOBYTE(v138) = 1;
    v88 = v9;
    v79[80] = 953267991;
    sub_9A6090(v41, a5, v79);
    LOBYTE(v138) = 2;
    if ( (unsigned __int8)sub_9A60F0(a2, v61, v70, v70, &p_??_7CastResult@btConvexCast@@6B@)
      && (v10 = v85, v11 = v84, v12 = v86, v78 = v84 * v84 + v85 * v85 + v86 * v86, v78 > 0.00009999999747378752)
      && v69[1] > (double)v88 )
    {
      v13 = a2[9];
      v75 = 0.0;
      v14 = a2[8];
      v87 = 0;
      v77 = v13 * v10 + v14 * v11 + a2[10] * v12;
      v15 = a2[5] * v10;
      v74 = v77;
      v78 = v15 + a2[4] * v11 + a2[6] * v12;
      v72 = v10 * a2[1] + v11 * *a2 + v12 * a2[2];
      v73 = v78;
      v85 = v78;
      v78 = v78 * v78 + v72 * v72 + v77 * v77;
      v78 = sqrt(v78);
      v107 = v68;
      v108 = 0.0;
      v114 = 0;
      v115 = v88;
      v78 = 1.0 / v78;
      v84 = v78 * v72;
      v111 = v84;
      v85 = v78 * v85;
      v112 = v85;
      v86 = v78 * v77;
      v113 = v86;
      (*(void (__thiscall **)(float *, float *, int))(*(_DWORD *)v69 + 8))(v69, &v107, 1);
      LOBYTE(v138) = 1;
      sub_9A6040(v60);
    }
    else
    {
      LOBYTE(v138) = 1;
      sub_9A6040(v60);
    }
  }
  v138 = -1;
  v41[0] = &btConvexInternalShape::`vftable';
  return sub_968890(v41);
}
