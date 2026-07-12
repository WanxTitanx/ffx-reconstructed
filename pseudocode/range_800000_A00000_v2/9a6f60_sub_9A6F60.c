// Function: sub_9A6F60
// Address: 0x9a6f60
// bad sp value at call has been detected, the output may be wrong!
char __userpurge sub_9A6F60@<al>(float a1@<ecx>, int a2@<ebp>, int *a3, int a4, int *a5, int a6, int a7)
{
  int v7; // ecx
  float v8; // esi
  double v9; // st7
  double v10; // st6
  float *v12; // ecx
  float v13; // eax
  int *v14; // esi
  int v15; // edi
  double v16; // st7
  int v17; // eax
  float v18; // ecx
  double (__thiscall *v19)(int *); // eax
  float v20; // edi
  int v21; // eax
  double v22; // st6
  float v23; // ecx
  double v24; // st7
  float v25; // edx
  int v26; // esi
  double v27; // st5
  double v28; // st4
  double v29; // st3
  double v30; // st2
  int v31; // ecx
  double v32; // st4
  double v33; // rt1
  double v34; // st4
  double v35; // st7
  double v36; // st6
  int v37; // ecx
  float v38; // xmm0_4
  float v39; // eax
  float v40; // eax
  float v41; // xmm0_4
  float v42; // eax
  _DWORD v43[16]; // [esp+90h] [ebp-2ECh] BYREF
  float v44; // [esp+D0h] [ebp-2ACh]
  void **p_??_7btPointCollector@@6B@; // [esp+E0h] [ebp-29Ch] BYREF
  float v46; // [esp+F0h] [ebp-28Ch]
  float v47; // [esp+F4h] [ebp-288h]
  float v48; // [esp+F8h] [ebp-284h]
  int v49; // [esp+FCh] [ebp-280h]
  float v50; // [esp+100h] [ebp-27Ch]
  float v51; // [esp+104h] [ebp-278h]
  float v52; // [esp+108h] [ebp-274h]
  float v53; // [esp+10Ch] [ebp-270h]
  float k_v_][2]; // [esp+110h] [ebp-26Ch] BYREF
  float v55[4]; // [esp+120h] [ebp-25Ch] BYREF
  float v56; // [esp+130h] [ebp-24Ch] BYREF
  float v57; // [esp+134h] [ebp-248h]
  float v58; // [esp+138h] [ebp-244h]
  float v59; // [esp+140h] [ebp-23Ch] BYREF
  float v60; // [esp+144h] [ebp-238h]
  float v61; // [esp+148h] [ebp-234h]
  float v62[4]; // [esp+150h] [ebp-22Ch] BYREF
  _DWORD v63[4]; // [esp+160h] [ebp-21Ch] BYREF
  void **p_??_7btPointCollector@@6B@_1; // [esp+170h] [ebp-20Ch] BYREF
  float v65; // [esp+180h] [ebp-1FCh]
  float v66; // [esp+184h] [ebp-1F8h]
  float v67; // [esp+188h] [ebp-1F4h]
  int v68; // [esp+18Ch] [ebp-1F0h]
  float v69; // [esp+190h] [ebp-1ECh]
  float v70; // [esp+194h] [ebp-1E8h]
  float v71; // [esp+198h] [ebp-1E4h]
  float v72; // [esp+19Ch] [ebp-1E0h]
  float k_v_]_1[2]; // [esp+1A0h] [ebp-1DCh] BYREF
  float v74[4]; // [esp+1B0h] [ebp-1CCh] BYREF
  float v75; // [esp+1C0h] [ebp-1BCh]
  float v76; // [esp+1C4h] [ebp-1B8h]
  float v77; // [esp+1C8h] [ebp-1B4h]
  float v78; // [esp+1D0h] [ebp-1ACh] BYREF
  float v79; // [esp+1D4h] [ebp-1A8h]
  float v80; // [esp+1D8h] [ebp-1A4h]
  float v81; // [esp+1DCh] [ebp-1A0h]
  float v82; // [esp+1E0h] [ebp-19Ch]
  float v83; // [esp+1E4h] [ebp-198h]
  int v84; // [esp+1E8h] [ebp-194h]
  int v85; // [esp+1ECh] [ebp-190h]
  float v86; // [esp+1F0h] [ebp-18Ch]
  int v87; // [esp+1F8h] [ebp-184h]
  float v88; // [esp+1FCh] [ebp-180h]
  float v89; // [esp+200h] [ebp-17Ch]
  float v90; // [esp+204h] [ebp-178h]
  int *v91; // [esp+208h] [ebp-174h]
  int *v92; // [esp+20Ch] [ebp-170h]
  float v93; // [esp+210h] [ebp-16Ch]
  float v94; // [esp+224h] [ebp-158h]
  float v95; // [esp+228h] [ebp-154h]
  float v96; // [esp+230h] [ebp-14Ch]
  float v97; // [esp+234h] [ebp-148h]
  float v98; // [esp+238h] [ebp-144h]
  char v99; // [esp+23Fh] [ebp-13Dh]
  _DWORD v100[12]; // [esp+240h] [ebp-13Ch] BYREF
  _DWORD v101[4]; // [esp+270h] [ebp-10Ch] BYREF
  _DWORD v102[16]; // [esp+280h] [ebp-FCh] BYREF
  int v103; // [esp+2C0h] [ebp-BCh] BYREF
  int v104; // [esp+2C4h] [ebp-B8h]
  int v105; // [esp+2C8h] [ebp-B4h]
  int v106; // [esp+2CCh] [ebp-B0h]
  int v107; // [esp+2D0h] [ebp-ACh]
  int v108; // [esp+2D4h] [ebp-A8h]
  int v109; // [esp+2D8h] [ebp-A4h]
  int v110; // [esp+2DCh] [ebp-A0h]
  int v111; // [esp+2E0h] [ebp-9Ch]
  int v112; // [esp+2E4h] [ebp-98h]
  int v113; // [esp+2E8h] [ebp-94h]
  int v114; // [esp+2ECh] [ebp-90h]
  int v115; // [esp+2F0h] [ebp-8Ch]
  int v116; // [esp+2F4h] [ebp-88h]
  int v117; // [esp+2F8h] [ebp-84h]
  int v118; // [esp+2FCh] [ebp-80h]
  int v119; // [esp+300h] [ebp-7Ch]
  int v120; // [esp+304h] [ebp-78h]
  int v121; // [esp+308h] [ebp-74h]
  int v122; // [esp+30Ch] [ebp-70h]
  int v123; // [esp+310h] [ebp-6Ch]
  int v124; // [esp+314h] [ebp-68h]
  int v125; // [esp+318h] [ebp-64h]
  int v126; // [esp+31Ch] [ebp-60h]
  int v127; // [esp+320h] [ebp-5Ch]
  int v128; // [esp+324h] [ebp-58h]
  int v129; // [esp+328h] [ebp-54h]
  int v130; // [esp+32Ch] [ebp-50h]
  int v131; // [esp+330h] [ebp-4Ch]
  int v132; // [esp+334h] [ebp-48h]
  int v133; // [esp+338h] [ebp-44h]
  int v134; // [esp+33Ch] [ebp-40h]
  int n1566444395; // [esp+340h] [ebp-3Ch]
  int v136; // [esp+344h] [ebp-38h]
  int v137; // [esp+350h] [ebp-2Ch]
  float v138; // [esp+354h] [ebp-28h]
  float v139; // [esp+358h] [ebp-24h]
  float v140; // [esp+35Ch] [ebp-20h]
  float v141; // [esp+360h] [ebp-1Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+364h] [ebp-18h]
  void *v143; // [esp+368h] [ebp-14h]
  int v144; // [esp+36Ch] [ebp-10h]
  int v145; // [esp+370h] [ebp-Ch]
  void *v146; // [esp+374h] [ebp-8h]
  int v147; // [esp+378h] [ebp-4h] BYREF
  void *retaddr; // [esp+37Ch] [ebp+0h]

  v145 = a2;
  v146 = retaddr;
  v144 = -1;
  v143 = &loc_AD9AF7;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v141 = COERCE_FLOAT(&v147);
  v96 = a1;
  v7 = *(_DWORD *)(LODWORD(a1) + 4);
  v92 = a3;
  v91 = a5;
  v87 = a7;
  sub_9B39F0(v7);
  sub_97D980(a3, a4, 1.0, v62, &v56);
  sub_97D980(v91, a6, 1.0, v55, &v59);
  v8 = v96;
  v93 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(LODWORD(v96) + 12) + 12))(*(_DWORD *)(LODWORD(v96) + 12));
  v95 = ((double (__thiscall *)(_DWORD, void *))*(_DWORD *)(**(_DWORD **)(LODWORD(v8) + 16) + 12))(
          *(_DWORD *)(LODWORD(v8) + 16),
          v143);
  v98 = v56 * v56 + v57 * v57 + v58 * v58;
  v94 = sqrt(v98);
  v98 = v59 * v59 + v60 * v60 + v61 * v61;
  v98 = sqrt(v98);
  v90 = v98 * v95 + v94 * v93;
  v98 = v55[2] - v62[2];
  v9 = v98;
  v89 = v98;
  v98 = v55[1] - v62[1];
  v10 = v98;
  v88 = v98;
  v98 = v55[0] - v62[0];
  v44 = v98;
  v74[0] = v98;
  v95 = v9;
  v98 = v10;
  v98 = v74[0] * v74[0] + v98 * v98 + v95 * v95;
  v98 = sqrt(v98);
  if ( v98 + v90 == 0.0 )
    return 0;
  v97 = 0.0;
  v83 = 0.0;
  v84 = 0;
  sub_6035C0(v102);
  sub_96A2F0(v43);
  v43[0] = &btSphereShape::`vftable';
  v43[1] = 8;
  v43[8] = 0;
  v144 = 1;
  v43[12] = 0;
  p_??_7btPointCollector@@6B@ = &btPointCollector::`vftable';
  strcpy((char *)k_v_], "k\v^]");
  v12 = *(float **)(LODWORD(v96) + 16);
  ExceptionList = *(struct _EXCEPTION_REGISTRATION_RECORD **)(LODWORD(v96) + 8);
  v13 = v12[1];
  v141 = *(float *)(LODWORD(v96) + 4);
  v98 = v13;
  v14 = *(int **)(LODWORD(v96) + 12);
  v15 = v14[1];
  v16 = ((double (__thiscall *)(float *))*(_DWORD *)(*(_DWORD *)v12 + 40))(v12);
  v17 = *v14;
  v140 = v18;
  v19 = *(double (__thiscall **)(int *))(v17 + 40);
  v140 = v16;
  v139 = v19(v14);
  v138 = v98;
  v137 = v15;
  v20 = v96;
  sub_9A82D0(
    *(_DWORD *)(LODWORD(v96) + 12),
    *(_DWORD *)(LODWORD(v96) + 16),
    v137,
    LODWORD(v98),
    LODWORD(v139),
    LODWORD(v140),
    LODWORD(v141),
    ExceptionList);
  LOBYTE(v144) = 2;
  v103 = *v92;
  v104 = v92[1];
  v105 = v92[2];
  v106 = v92[3];
  v107 = v92[4];
  v108 = v92[5];
  v109 = v92[6];
  v110 = v92[7];
  v111 = v92[8];
  v112 = v92[9];
  v113 = v92[10];
  v114 = v92[11];
  v115 = v92[12];
  v116 = v92[13];
  v21 = v92[14];
  n1566444395 = 1566444395;
  v136 = 0;
  v117 = v21;
  v118 = v92[15];
  v119 = *v91;
  v120 = v91[1];
  v121 = v91[2];
  v122 = v91[3];
  v123 = v91[4];
  v124 = v91[5];
  v125 = v91[6];
  v126 = v91[7];
  v127 = v91[8];
  v128 = v91[9];
  v129 = v91[10];
  v130 = v91[11];
  v131 = v91[12];
  v132 = v91[13];
  v133 = v91[14];
  v134 = v91[15];
  sub_9A8450(&v103, &p_??_7btPointCollector@@6B@, 0, 0);
  v93 = v50;
  v78 = v50;
  v94 = v51;
  v79 = v51;
  v95 = v52;
  v80 = v52;
  v98 = v53;
  v81 = v53;
  LOBYTE(v144) = 1;
  if ( LOBYTE(k_v_][1]) )
  {
    v22 = v88;
    v23 = v46;
    v24 = v44;
    v25 = v47;
    v26 = v87;
    v86 = v48;
    v77 = v48;
    v82 = k_v_][0];
    v27 = v89;
    v75 = v46;
    v76 = v47;
    v85 = v49;
    v96 = v48 * v89 + v46 * v44 + v47 * v88;
    if ( k_v_][0] <= 0.001 )
    {
LABEL_25:
      if ( *(float *)(v26 + 184) < v96 + v90 )
      {
        v40 = v86;
        v41 = v97;
        *(float *)(v26 + 144) = v23;
        *(float *)(v26 + 148) = v25;
        *(float *)(v26 + 152) = v40;
        *(_DWORD *)(v26 + 156) = v85;
        *(float *)(v26 + 160) = v93;
        *(float *)(v26 + 164) = v94;
        *(float *)(v26 + 168) = v95;
        v42 = v98;
        *(float *)(v26 + 176) = v41;
        *(float *)(v26 + 172) = v42;
        v99 = 1;
        goto LABEL_24;
      }
    }
    else
    {
      v28 = 0.2;
      v29 = 0.0000001192092895507812;
      v30 = v97;
      while ( 1 )
      {
        v31 = *(_DWORD *)(v26 + 180);
        if ( v31 )
        {
          v63[0] = 1065353216;
          v63[1] = 1065353216;
          v63[2] = 1065353216;
          v141 = v28;
          v63[3] = 0;
          (*(void (__thiscall **)(int, float *, float, _DWORD *))(*(_DWORD *)v31 + 12))(
            v31,
            &v78,
            COERCE_FLOAT(LODWORD(v141)),
            v63);
          v22 = v88;
          v24 = v44;
          v32 = v97;
          v29 = 0.0000001192092895507812;
          v27 = v89;
        }
        else
        {
          v32 = v30;
        }
        if ( ++v84 > 64 )
          break;
        v33 = v32;
        v34 = v24 * v75 + v22 * v76;
        v35 = v33;
        v96 = v27 * v77 + v34;
        v36 = v96 + v90;
        if ( v29 >= v36 )
          break;
        v98 = v82 / v36;
        v97 = v35 + v98;
        if ( v97 > 1.0 || v97 < 0.0 || v83 >= (double)v97 )
          break;
        v83 = v97;
        sub_9A7AC0(v92, v62, &v56, LODWORD(v97), v100);
        sub_9A7AC0(v91, v55, &v59, LODWORD(v97), v102);
        v37 = *(_DWORD *)(v26 + 180);
        if ( v37 )
        {
          v74[0] = 1.0;
          memset(&v74[1], 0, 12);
          (*(void (__thiscall **)(int, _DWORD *, _DWORD, float *))(*(_DWORD *)v37 + 12))(v37, v101, 0.2, v74);
        }
        (**(void (__thiscall ***)(int, float))v26)(v26, COERCE_FLOAT(LODWORD(v97)));
        p_??_7btPointCollector@@6B@_1 = &btPointCollector::`vftable';
        strcpy((char *)k_v_]_1, "k\v^]");
        ExceptionList = *(struct _EXCEPTION_REGISTRATION_RECORD **)(LODWORD(v20) + 8);
        v141 = *(float *)(LODWORD(v20) + 4);
        LOBYTE(v144) = 3;
        sub_9A8350(*(_DWORD *)(LODWORD(v20) + 12), *(_DWORD *)(LODWORD(v20) + 16), LODWORD(v141), ExceptionList);
        v103 = v100[0];
        v104 = v100[1];
        v105 = v100[2];
        v106 = v100[3];
        v107 = v100[4];
        v108 = v100[5];
        v109 = v100[6];
        v110 = v100[7];
        v111 = v100[8];
        v112 = v100[9];
        v113 = v100[10];
        v114 = v100[11];
        v115 = v101[0];
        v116 = v101[1];
        v117 = v101[2];
        v118 = v101[3];
        v119 = v102[0];
        v120 = v102[1];
        v121 = v102[2];
        v122 = v102[3];
        v123 = v102[4];
        v124 = v102[5];
        v125 = v102[6];
        v126 = v102[7];
        v127 = v102[8];
        v128 = v102[9];
        v129 = v102[10];
        v130 = v102[11];
        v131 = v102[12];
        LOBYTE(v144) = 4;
        n1566444395 = 1566444395;
        v136 = 0;
        v132 = v102[13];
        v133 = v102[14];
        v134 = v102[15];
        sub_9A8450(&v103, &p_??_7btPointCollector@@6B@_1, 0, 0);
        if ( !LOBYTE(k_v_]_1[1]) )
        {
          v99 = 0;
          p_??_7btPointCollector@@6B@_1 = &btDiscreteCollisionDetectorInterface::Result::`vftable';
          goto LABEL_24;
        }
        if ( k_v_]_1[0] < 0.0 )
        {
          v38 = v97;
          *(float *)(v26 + 144) = v65;
          *(float *)(v26 + 148) = v66;
          *(float *)(v26 + 152) = v67;
          *(_DWORD *)(v26 + 156) = v68;
          *(float *)(v26 + 160) = v69;
          *(float *)(v26 + 164) = v70;
          *(float *)(v26 + 168) = v71;
          v39 = v72;
          *(float *)(v26 + 176) = v38;
          *(float *)(v26 + 172) = v39;
          v99 = 1;
          p_??_7btPointCollector@@6B@_1 = &btDiscreteCollisionDetectorInterface::Result::`vftable';
          goto LABEL_24;
        }
        v23 = v65;
        v25 = v66;
        v93 = v69;
        v78 = v69;
        v94 = v70;
        v79 = v70;
        v95 = v71;
        v80 = v71;
        v98 = v72;
        v81 = v72;
        v86 = v67;
        v77 = v67;
        v75 = v65;
        v76 = v66;
        v85 = v68;
        v82 = k_v_]_1[0];
        LOBYTE(v144) = 1;
        p_??_7btPointCollector@@6B@_1 = &btDiscreteCollisionDetectorInterface::Result::`vftable';
        if ( k_v_]_1[0] <= 0.001 )
          goto LABEL_25;
        v30 = v97;
        v24 = v44;
        v22 = v88;
        v27 = v89;
        v28 = 0.2;
        v29 = 0.0000001192092895507812;
      }
    }
  }
  v99 = 0;
LABEL_24:
  p_??_7btPointCollector@@6B@ = &btDiscreteCollisionDetectorInterface::Result::`vftable';
  v144 = -1;
  v43[0] = &btConvexInternalShape::`vftable';
  sub_968890(v43);
  return v99;
}
