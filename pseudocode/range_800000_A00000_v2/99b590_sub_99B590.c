// Function: sub_99B590
// Address: 0x99b590
int __userpurge sub_99B590@<eax>(int a1@<ecx>, int a2@<ebp>, float a3, int a4, int a5, int a6)
{
  bool v7; // zf
  float v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edi
  float v15; // eax
  int v16; // ecx
  int i; // edi
  int v18; // ecx
  int *v19; // esi
  int v20; // eax
  double v21; // st6
  double v22; // st5
  double v23; // st5
  double v24; // st7
  double v25; // st5
  double v26; // st6
  double v27; // st4
  double v28; // st3
  double v29; // st2
  double v30; // st7
  double v31; // st2
  double v32; // st6
  int v33; // ecx
  int v34; // esi
  int v35; // edi
  int result; // eax
  int v37; // esi
  int v38; // edx
  int v39; // ecx
  int v40; // edx
  double v41; // st7
  double v42; // st5
  double v43; // st3
  double v44; // st6
  double v45; // st7
  double v46; // st4
  double v47; // st5
  double v48; // st0
  char v49; // cl
  void (__thiscall ***v50)(_DWORD, _DWORD); // ecx
  float v51[4]; // [esp-1Ch] [ebp-20Ch] BYREF
  float v52[4]; // [esp-Ch] [ebp-1FCh] BYREF
  float v53[4]; // [esp+4h] [ebp-1ECh] BYREF
  _DWORD v54[5]; // [esp+14h] [ebp-1DCh] BYREF
  _DWORD v55[7]; // [esp+28h] [ebp-1C8h] BYREF
  float v56; // [esp+44h] [ebp-1ACh] BYREF
  float v57; // [esp+48h] [ebp-1A8h]
  float v58; // [esp+4Ch] [ebp-1A4h]
  int v59; // [esp+50h] [ebp-1A0h]
  char v60; // [esp+54h] [ebp-19Ch]
  _DWORD src[4]; // [esp+64h] [ebp-18Ch] BYREF
  float v62; // [esp+74h] [ebp-17Ch]
  float v63; // [esp+78h] [ebp-178h]
  float v64; // [esp+7Ch] [ebp-174h]
  int v65; // [esp+80h] [ebp-170h]
  float v66; // [esp+84h] [ebp-16Ch] BYREF
  int i_1; // [esp+88h] [ebp-168h]
  float v68; // [esp+8Ch] [ebp-164h]
  int v69; // [esp+90h] [ebp-160h]
  char v70; // [esp+94h] [ebp-15Ch]
  float v71; // [esp+ACh] [ebp-144h]
  float *v72; // [esp+B0h] [ebp-140h]
  float v73; // [esp+B4h] [ebp-13Ch]
  float v74; // [esp+B8h] [ebp-138h]
  float v75; // [esp+BCh] [ebp-134h]
  float v76; // [esp+C0h] [ebp-130h]
  float v77; // [esp+C4h] [ebp-12Ch]
  int v78; // [esp+C8h] [ebp-128h]
  float v79; // [esp+CCh] [ebp-124h]
  float v80; // [esp+D0h] [ebp-120h]
  int v81; // [esp+D4h] [ebp-11Ch]
  float v82; // [esp+D8h] [ebp-118h]
  float v83; // [esp+DCh] [ebp-114h]
  float v84; // [esp+E0h] [ebp-110h]
  float v85; // [esp+E4h] [ebp-10Ch]
  float v86; // [esp+E8h] [ebp-108h]
  float v87; // [esp+ECh] [ebp-104h]
  float v88; // [esp+F0h] [ebp-100h]
  float v89; // [esp+F4h] [ebp-FCh]
  float v90; // [esp+F8h] [ebp-F8h]
  float v91; // [esp+FCh] [ebp-F4h]
  int v92; // [esp+100h] [ebp-F0h]
  _DWORD v93[16]; // [esp+104h] [ebp-ECh] BYREF
  int v94; // [esp+144h] [ebp-ACh] BYREF
  float v95; // [esp+154h] [ebp-9Ch]
  float v96; // [esp+158h] [ebp-98h]
  float v97; // [esp+15Ch] [ebp-94h]
  int v98; // [esp+160h] [ebp-90h]
  float v99; // [esp+164h] [ebp-8Ch]
  float v100; // [esp+168h] [ebp-88h]
  float v101; // [esp+16Ch] [ebp-84h]
  int v102; // [esp+170h] [ebp-80h]
  float v103; // [esp+174h] [ebp-7Ch]
  float v104; // [esp+178h] [ebp-78h]
  float v105; // [esp+17Ch] [ebp-74h]
  int v106; // [esp+180h] [ebp-70h]
  float v107; // [esp+184h] [ebp-6Ch] BYREF
  float v108; // [esp+188h] [ebp-68h]
  float v109; // [esp+18Ch] [ebp-64h]
  int v110; // [esp+190h] [ebp-60h]
  float v111; // [esp+194h] [ebp-5Ch]
  float v112; // [esp+198h] [ebp-58h]
  float v113; // [esp+19Ch] [ebp-54h]
  int v114; // [esp+1A0h] [ebp-50h]
  float v115; // [esp+1A4h] [ebp-4Ch]
  float v116; // [esp+1A8h] [ebp-48h]
  float v117; // [esp+1ACh] [ebp-44h]
  int v118; // [esp+1B0h] [ebp-40h]
  float v119; // [esp+1B4h] [ebp-3Ch]
  float v120; // [esp+1B8h] [ebp-38h]
  float v121; // [esp+1BCh] [ebp-34h]
  int v122; // [esp+1C0h] [ebp-30h]
  int *v123; // [esp+1D4h] [ebp-1Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+1D8h] [ebp-18h]
  void *v125; // [esp+1DCh] [ebp-14h]
  int v126; // [esp+1E0h] [ebp-10h]
  _DWORD v127[2]; // [esp+1E4h] [ebp-Ch] BYREF
  int v128; // [esp+1ECh] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+1F0h] [ebp+0h]

  v127[0] = a2;
  v127[1] = retaddr;
  v126 = -1;
  v125 = &loc_AD93C6;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v123 = &v128;
  v78 = a1;
  v89 = *(float *)&a4;
  v7 = *(_BYTE *)(a1 + 28) == 0;
  v8 = *(float *)&a4;
  if ( *(_BYTE *)(a1 + 28) )
    v8 = a3;
  v9 = LODWORD(a3);
  if ( !v7 )
    v9 = LODWORD(v89);
  v73 = v8;
  v72 = *(float **)(v9 + 204);
  v10 = *((_DWORD *)v72 + 17);
  v88 = a3;
  v92 = v9;
  if ( v10 != *(_DWORD *)(a1 + 40) )
  {
    sub_99C2C0(a1);
    sub_99B440(a1, SLODWORD(v88), SLODWORD(v89));
  }
  v11 = *(_DWORD *)(a1 + 32);
  v12 = *(_DWORD *)(a1 + 20);
  v88 = v72[16];
  v13 = *(_DWORD *)(a1 + 4);
  v55[0] = v92;
  v55[2] = v13;
  *(float *)&v55[1] = v73;
  v55[3] = a5;
  v55[4] = a6;
  v55[5] = v12;
  v55[6] = v11;
  v70 = 1;
  v69 = 0;
  *(float *)&i_1 = 0.0;
  v68 = 0.0;
  v14 = v78;
  v15 = 0.0;
  v126 = 0;
  v90 = 0.0;
  if ( *(int *)(v78 + 12) > 0 )
  {
    do
    {
      v16 = *(_DWORD *)(v14 + 20);
      if ( *(_DWORD *)(v16 + 4 * LODWORD(v15)) )
      {
        (*(void (__thiscall **)(_DWORD, float *))(**(_DWORD **)(v16 + 4 * LODWORD(v15)) + 12))(
          *(_DWORD *)(v16 + 4 * LODWORD(v15)),
          &v66);
        for ( i = 0; i < i_1; ++i )
        {
          v18 = *(_DWORD *)(v69 + 4 * i);
          if ( *(_DWORD *)(v18 + 1176) )
          {
            *(_DWORD *)(a6 + 4) = v18;
            if ( *(_DWORD *)(v18 + 1176) )
            {
              if ( *(_DWORD *)(v18 + 1168) == *(_DWORD *)(a6 + 144) )
                sub_9A4470(a6 + 16, a6 + 80);
              else
                sub_9A4470(a6 + 80, a6 + 16);
            }
            *(_DWORD *)(a6 + 4) = 0;
          }
        }
        if ( v69 && v70 )
          sub_9D4D50(v69);
        v14 = v78;
        v15 = v90;
        v70 = 1;
        v69 = 0;
        *(float *)&i_1 = 0.0;
        v68 = 0.0;
      }
      ++LODWORD(v15);
      v90 = v15;
    }
    while ( SLODWORD(v15) < *(_DWORD *)(v14 + 12) );
  }
  v19 = (int *)LODWORD(v88);
  v126 = -1;
  if ( v88 == 0.0 )
  {
    v34 = 0;
    v91 = *(float *)(v14 + 12);
    if ( SLODWORD(v91) > 0 )
    {
      v35 = 0;
      do
      {
        sub_99A5D0(v55, (int)v127, v35, v34, *(_DWORD *)(*((_DWORD *)v72 + 6) + v35 + 64), v34);
        ++v34;
        v35 += 80;
      }
      while ( v34 < SLODWORD(v91) );
      v14 = v78;
    }
  }
  else
  {
    v20 = sub_982990((float *)(v92 + 16), (int)&v94);
    v88 = *(float *)(v20 + 36);
    v83 = *(float *)(LODWORD(v73) + 68);
    v90 = *(float *)(LODWORD(v73) + 64);
    v85 = *(float *)(v20 + 32);
    v77 = *(float *)(v20 + 40);
    v87 = *(float *)(LODWORD(v73) + 72);
    v21 = v90;
    v22 = v83;
    v90 = v87 * v77 + v83 * v88 + v85 * v90;
    *(float *)&v81 = v90 + *(float *)(v20 + 56);
    v76 = *(float *)(v20 + 20);
    v74 = *(float *)(v20 + 16);
    v75 = *(float *)(v20 + 24);
    v90 = v74 * v21 + v76 * v83 + v75 * v87;
    v80 = v90 + *(float *)(v20 + 52);
    v83 = *(float *)(v20 + 4);
    v63 = v80;
    v89 = *(float *)v20;
    v90 = *(float *)(v20 + 8);
    v87 = v87 * v90 + v22 * v83 + v21 * v89;
    v62 = v87 + *(float *)(v20 + 48);
    v80 = *(float *)(LODWORD(v73) + 40);
    v64 = *(float *)&v81;
    v23 = *(float *)(LODWORD(v73) + 24);
    v65 = 0;
    *(float *)&v81 = v23;
    v87 = *(float *)(LODWORD(v73) + 56);
    v24 = v85;
    v91 = v77 * v87 + v88 * v80 + *(float *)&v81 * v85;
    v82 = *(float *)(LODWORD(v73) + 36);
    v85 = *(float *)(LODWORD(v73) + 20);
    v79 = *(float *)(LODWORD(v73) + 52);
    v25 = v82;
    v26 = v88;
    v27 = v79;
    v86 = v82 * v88 + v85 * v24 + v79 * v77;
    v82 = *(float *)(LODWORD(v73) + 32);
    v79 = *(float *)(LODWORD(v73) + 16);
    v88 = *(float *)(LODWORD(v73) + 48);
    v28 = v79;
    v29 = v24 * v79;
    v30 = v82;
    v31 = v26 * v82 + v29 + v88 * v77;
    v32 = v88;
    v84 = v31;
    v71 = *(float *)&v81 * v74 + v80 * v76 + v87 * v75;
    v77 = v85 * v74 + v25 * v76 + v27 * v75;
    v98 = 0;
    v102 = 0;
    v106 = 0;
    v88 = v79 * v74 + v82 * v76 + v88 * v75;
    v82 = *(float *)&v81 * v89 + v80 * v83 + v87 * v90;
    v97 = v82;
    v99 = v88;
    v100 = v77;
    v101 = v71;
    v103 = v84;
    v104 = v86;
    v105 = v91;
    v79 = v27 * v90 + v25 * v83 + v85 * v89;
    v95 = v28 * v89 + v83 * v30 + v32 * v90;
    v107 = v95;
    v96 = v79;
    v108 = v79;
    v109 = v82;
    v110 = 0;
    v111 = v88;
    v112 = v77;
    v113 = v71;
    v114 = 0;
    v115 = v84;
    v116 = v86;
    v117 = v91;
    v33 = *(_DWORD *)(LODWORD(v73) + 204);
    v118 = 0;
    v119 = v62;
    v120 = v63;
    v121 = v64;
    v122 = 0;
    (*(void (__thiscall **)(int, float *, _DWORD *, float *))(*(_DWORD *)v33 + 4))(v33, &v107, v54, &v56);
    src[0] = v54[0];
    src[1] = v54[1];
    src[2] = v54[2];
    src[3] = v54[3];
    v62 = v56;
    v63 = v57;
    v64 = v58;
    v65 = v59;
    sub_999CE0((int)v127, *v19, src, (int)v55);
  }
  result = *(int *)(v14 + 12);
  v81 = result;
  v60 = 1;
  v59 = 0;
  v57 = 0.0;
  v58 = 0.0;
  v37 = 0;
  v126 = 1;
  if ( result > 0 )
  {
    *(float *)&v38 = 0.0;
    v89 = 0.0;
    do
    {
      result = *(int *)(v14 + 20);
      if ( *(_DWORD *)(result + 4 * v37) )
      {
        v39 = *((_DWORD *)v72 + 6);
        v40 = *(_DWORD *)(v39 + v38 + 64);
        v107 = *(float *)(v92 + 16);
        v108 = *(float *)(v92 + 20);
        v109 = *(float *)(v92 + 24);
        v110 = *(_DWORD *)(v92 + 28);
        v111 = *(float *)(v92 + 32);
        v112 = *(float *)(v92 + 36);
        v113 = *(float *)(v92 + 40);
        v114 = *(_DWORD *)(v92 + 44);
        v115 = *(float *)(v92 + 48);
        v116 = *(float *)(v92 + 52);
        v117 = *(float *)(v92 + 56);
        v118 = *(_DWORD *)(v92 + 60);
        v119 = *(float *)(v92 + 64);
        v120 = *(float *)(v92 + 68);
        v121 = *(float *)(v92 + 72);
        v122 = *(_DWORD *)(v92 + 76);
        v86 = *(float *)(v39 + LODWORD(v89) + 52);
        v91 = *(float *)(v39 + LODWORD(v89) + 48);
        v84 = *(float *)(v39 + LODWORD(v89) + 56);
        v41 = v91;
        v42 = v86;
        v43 = v84;
        v91 = v84 * v117 + v86 * v116 + v91 * v115;
        v84 = v91 + v121;
        v64 = v84;
        v65 = 0;
        v91 = v41 * v111 + v86 * v112 + v43 * v113;
        v86 = v91 + v120;
        v91 = v43 * v109 + v42 * v108 + v41 * v107;
        v62 = v91 + v119;
        v63 = v86;
        v83 = *(float *)(v39 + LODWORD(v89) + 24);
        v90 = *(float *)(v39 + LODWORD(v89) + 8);
        v85 = *(float *)(v39 + LODWORD(v89) + 40);
        v80 = v115 * v90 + v116 * v83 + v117 * v85;
        v91 = *(float *)(v39 + LODWORD(v89) + 20);
        v87 = *(float *)(v39 + LODWORD(v89) + 4);
        v86 = *(float *)(v39 + LODWORD(v89) + 36);
        v44 = v86;
        v45 = v91;
        v88 = v117 * v86 + v116 * v91 + v115 * v87;
        v86 = *(float *)(v39 + LODWORD(v89) + 16);
        v91 = *(float *)(v39 + LODWORD(v89));
        v84 = *(float *)(v39 + LODWORD(v89) + 32);
        v46 = v91;
        v47 = v86;
        v98 = 0;
        v102 = 0;
        v48 = v84;
        v82 = v117 * v84 + v116 * v86 + v115 * v91;
        v79 = v111 * v90 + v112 * v83 + v113 * v85;
        v71 = v111 * v87 + v112 * v45 + v113 * v44;
        v84 = v111 * v91 + v112 * v86 + v113 * v84;
        v86 = v107 * v90 + v108 * v83 + v109 * v85;
        v97 = v86;
        v99 = v84;
        v100 = v71;
        v101 = v79;
        v103 = v82;
        v104 = v88;
        v105 = v80;
        v91 = v44 * v109 + v45 * v108 + v107 * v87;
        v95 = v47 * v108 + v46 * v107 + v48 * v109;
        v96 = v91;
        *(float *)v93 = v95;
        *(float *)&v93[1] = v91;
        *(float *)&v93[2] = v86;
        v93[3] = 0;
        *(float *)&v93[4] = v84;
        *(float *)&v93[5] = v71;
        *(float *)&v93[6] = v79;
        v93[7] = 0;
        *(float *)&v93[8] = v82;
        *(float *)&v93[9] = v88;
        *(float *)&v93[10] = v80;
        v106 = 0;
        v93[11] = 0;
        *(float *)&v93[12] = v62;
        *(float *)&v93[13] = v63;
        *(float *)&v93[14] = v64;
        v93[15] = 0;
        (*(void (__thiscall **)(int, _DWORD *, float *, float *))(*(_DWORD *)v40 + 4))(v40, v93, v53, v52);
        *(float *)&result = COERCE_FLOAT(
                              (*(int (__thiscall **)(_DWORD, int, float *, float *))(**(_DWORD **)(LODWORD(v73) + 204)
                                                                                   + 4))(
                                *(_DWORD *)(LODWORD(v73) + 204),
                                LODWORD(v73) + 16,
                                &v66,
                                v51));
        v14 = v78;
        v49 = 1;
        if ( v53[0] > (double)v51[0] || v66 > (double)v52[0] )
          v49 = 0;
        if ( v53[2] > (double)v51[2] || v68 > (double)v52[2] )
          v49 = 0;
        if ( v53[1] > (double)v51[1] || *(float *)&i_1 > (double)v52[1] || !v49 )
        {
          v50 = *(void (__thiscall ****)(_DWORD, _DWORD))(*(_DWORD *)(v78 + 20) + 4 * v37);
          (**v50)(v50, 0);
          (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(v14 + 4) + 48))(
            *(_DWORD *)(v14 + 4),
            *(_DWORD *)(*(_DWORD *)(v14 + 20) + 4 * v37));
          result = *(int *)(v14 + 20);
          *(_DWORD *)(result + 4 * v37) = 0;
        }
        *(float *)&v38 = v89;
      }
      ++v37;
      v38 += 80;
      v89 = *(float *)&v38;
    }
    while ( v37 < v81 );
  }
  return result;
}
