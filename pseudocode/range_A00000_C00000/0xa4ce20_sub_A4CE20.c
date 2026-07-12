// Function: sub_A4CE20
// Address: 0xa4ce20
// Size: 0x242a
// Prototype: 

int sub_A4CE20()
{
  float *v0; // esi
  int result; // eax
  int v2; // ecx
  int v3; // eax
  __int16 *v4; // ebx
  unsigned __int64 v5; // kr00_8
  __int64 v6; // rax
  int v7; // ecx
  double v8; // st4
  double v9; // st3
  unsigned __int64 v10; // kr08_8
  __int64 v11; // rax
  int v12; // ecx
  unsigned __int64 v13; // kr10_8
  __int64 v14; // rax
  int v15; // ecx
  unsigned __int64 v16; // kr18_8
  __int64 v17; // rax
  int v18; // ecx
  double v19; // st6
  float v20; // ebx
  float v21; // edi
  float v22; // esi
  float v23; // ebx
  __int64 v24; // kr20_8
  __int64 v25; // rax
  int v26; // ecx
  __int64 v27; // kr28_8
  __int64 v28; // rax
  float *v29; // edi
  double v30; // st6
  double v31; // st7
  unsigned int n10000; // ebx
  int i; // esi
  float v34; // eax
  int j; // esi
  float v36; // eax
  int k; // esi
  float v38; // esi
  float v39; // edx
  float v40; // ecx
  float v41; // eax
  int m; // esi
  double v43; // st4
  double v44; // st4
  double v45; // st5
  double v46; // st7
  float v47; // eax
  double v48; // st7
  double v49; // st6
  double v50; // st7
  double v51; // st5
  double v52; // st4
  double v53; // rt0
  float v54; // [esp+E0h] [ebp-284h]
  float v55; // [esp+E8h] [ebp-27Ch]
  float v56; // [esp+F8h] [ebp-26Ch]
  float v57; // [esp+104h] [ebp-260h]
  float v58; // [esp+108h] [ebp-25Ch]
  float v59; // [esp+10Ch] [ebp-258h]
  int v60; // [esp+110h] [ebp-254h]
  float v61; // [esp+114h] [ebp-250h]
  float v62; // [esp+118h] [ebp-24Ch]
  float v63; // [esp+11Ch] [ebp-248h]
  float v64; // [esp+130h] [ebp-234h]
  float v65; // [esp+134h] [ebp-230h]
  float v66; // [esp+138h] [ebp-22Ch]
  float v67; // [esp+14Ch] [ebp-218h] BYREF
  float v68; // [esp+150h] [ebp-214h]
  float v69; // [esp+154h] [ebp-210h]
  float v70; // [esp+158h] [ebp-20Ch]
  float v71; // [esp+15Ch] [ebp-208h]
  float v72; // [esp+160h] [ebp-204h]
  float v73; // [esp+164h] [ebp-200h]
  float v74; // [esp+168h] [ebp-1FCh]
  float v75; // [esp+16Ch] [ebp-1F8h]
  float v76; // [esp+170h] [ebp-1F4h]
  float v77; // [esp+174h] [ebp-1F0h]
  float v78; // [esp+178h] [ebp-1ECh]
  float v79; // [esp+17Ch] [ebp-1E8h]
  float v80; // [esp+180h] [ebp-1E4h]
  float v81; // [esp+184h] [ebp-1E0h]
  float v82; // [esp+188h] [ebp-1DCh]
  double v83; // [esp+18Ch] [ebp-1D8h]
  double v84; // [esp+194h] [ebp-1D0h]
  double v85; // [esp+19Ch] [ebp-1C8h]
  float v86; // [esp+1A4h] [ebp-1C0h]
  float v87; // [esp+1A8h] [ebp-1BCh]
  float v88; // [esp+1ACh] [ebp-1B8h]
  float v89; // [esp+1B0h] [ebp-1B4h]
  double v90; // [esp+1B4h] [ebp-1B0h]
  double v91; // [esp+1BCh] [ebp-1A8h]
  int v92; // [esp+1C4h] [ebp-1A0h]
  float v93; // [esp+1C8h] [ebp-19Ch]
  float v94; // [esp+1CCh] [ebp-198h]
  float v95; // [esp+1D0h] [ebp-194h]
  float v96; // [esp+1D4h] [ebp-190h]
  float v97; // [esp+1D8h] [ebp-18Ch]
  float v98; // [esp+1DCh] [ebp-188h]
  float v99; // [esp+1E0h] [ebp-184h]
  float v100; // [esp+1E4h] [ebp-180h]
  float v101; // [esp+1E8h] [ebp-17Ch]
  float v102; // [esp+1ECh] [ebp-178h]
  float v103; // [esp+1F0h] [ebp-174h]
  float v104; // [esp+1F4h] [ebp-170h]
  float v105; // [esp+1F8h] [ebp-16Ch]
  float v106; // [esp+1FCh] [ebp-168h]
  float v107; // [esp+200h] [ebp-164h]
  float v108; // [esp+204h] [ebp-160h]
  float v109; // [esp+208h] [ebp-15Ch]
  float v110; // [esp+20Ch] [ebp-158h]
  float v111; // [esp+210h] [ebp-154h]
  float v112; // [esp+214h] [ebp-150h]
  float v113; // [esp+218h] [ebp-14Ch]
  double v114; // [esp+21Ch] [ebp-148h]
  float v115; // [esp+224h] [ebp-140h]
  _DWORD v116[4]; // [esp+228h] [ebp-13Ch]
  _DWORD v117[4]; // [esp+238h] [ebp-12Ch]
  _DWORD v118[4]; // [esp+248h] [ebp-11Ch]
  _DWORD v119[28]; // [esp+258h] [ebp-10Ch]
  int v120[2]; // [esp+2C8h] [ebp-9Ch] BYREF
  float v121; // [esp+2D0h] [ebp-94h]
  float v122; // [esp+2D4h] [ebp-90h]
  int n64; // [esp+2D8h] [ebp-8Ch]
  int n64_1; // [esp+2DCh] [ebp-88h]
  int n64_2; // [esp+2E0h] [ebp-84h]
  int n128; // [esp+2E4h] [ebp-80h]
  float v127; // [esp+2E8h] [ebp-7Ch]
  float v128; // [esp+2ECh] [ebp-78h]
  float v129; // [esp+2F0h] [ebp-74h]
  float v130; // [esp+2F4h] [ebp-70h]
  int n64_3; // [esp+2F8h] [ebp-6Ch]
  int n64_4; // [esp+2FCh] [ebp-68h]
  int n64_5; // [esp+300h] [ebp-64h]
  int n128_1; // [esp+304h] [ebp-60h]
  float v135; // [esp+308h] [ebp-5Ch]
  float v136; // [esp+30Ch] [ebp-58h]
  float v137; // [esp+310h] [ebp-54h]
  float v138; // [esp+314h] [ebp-50h]
  int n64_6; // [esp+318h] [ebp-4Ch]
  int n64_7; // [esp+31Ch] [ebp-48h]
  int n64_8; // [esp+320h] [ebp-44h]
  int n128_2; // [esp+324h] [ebp-40h]
  float v143; // [esp+328h] [ebp-3Ch]
  float v144; // [esp+32Ch] [ebp-38h]
  float v145; // [esp+330h] [ebp-34h]
  float v146; // [esp+334h] [ebp-30h]
  int n64_9; // [esp+338h] [ebp-2Ch]
  int n64_10; // [esp+33Ch] [ebp-28h]
  int n64_11; // [esp+340h] [ebp-24h]
  int n128_3; // [esp+344h] [ebp-20h]
  int v151; // [esp+358h] [ebp-Ch]
  int v152; // [esp+35Ch] [ebp-8h]

  v0 = (float *)dword_2305834[0];
  result = *(__int16 *)dword_2305834[0];
  v2 = dword_2305834[0] + 8;
  v92 = dword_2305834[0] + 8;
  v151 = 0;
  v152 = 0;
  if ( result )
  {
    while ( 1 )
    {
      v60 = result - 1;
      v3 = dword_1A85F78[*(unsigned __int16 *)(v2 + 6)];
      LODWORD(v113) = v3 + *(__int16 *)(v3 + 16);
      v4 = (__int16 *)LODWORD(v113);
      sub_A5AD30((int)&v67, v2, 1.0);
      flt_C8F910 = v0[17656];
      flt_C8F914 = v0[17657];
      flt_C8F918 = v0[17658];
      flt_C8F91C = v0[17659];
      unk_C8F920 = v0[17660];
      unk_C8F924 = v0[17661];
      unk_C8F928 = v0[17662];
      unk_C8F92C = v0[17663];
      flt_C8F930 = v0[17664];
      flt_C8F934 = v0[17665];
      flt_C8F938 = v0[17666];
      flt_C8F93C = v0[17667];
      flt_C8F940 = v0[17668];
      flt_C8F944 = v0[17669];
      flt_C8F948 = v0[17670];
      flt_C8F94C = v0[17671];
      unk_C8F790 = v67 * flt_C8F910;
      unk_C8F794 = v67 * flt_C8F914;
      unk_C8F798 = v67 * flt_C8F918;
      unk_C8F79C = v67 * flt_C8F91C;
      unk_C8F790 = unk_C8F920 * v68 + unk_C8F790;
      unk_C8F794 = unk_C8F924 * v68 + unk_C8F794;
      unk_C8F798 = unk_C8F928 * v68 + unk_C8F798;
      unk_C8F79C = v68 * unk_C8F92C + unk_C8F79C;
      unk_C8F790 = flt_C8F930 * v69 + unk_C8F790;
      unk_C8F794 = flt_C8F934 * v69 + unk_C8F794;
      unk_C8F798 = flt_C8F938 * v69 + unk_C8F798;
      unk_C8F79C = v69 * flt_C8F93C + unk_C8F79C;
      flt_C8F950 = flt_C8F940 * v70 + unk_C8F790;
      flt_C8F954 = flt_C8F944 * v70 + unk_C8F794;
      flt_C8F958 = flt_C8F948 * v70 + unk_C8F798;
      flt_C8F95C = v70 * flt_C8F94C + unk_C8F79C;
      unk_C8F790 = v71 * flt_C8F910;
      unk_C8F794 = v71 * flt_C8F914;
      unk_C8F798 = v71 * flt_C8F918;
      unk_C8F79C = v71 * flt_C8F91C;
      unk_C8F790 = unk_C8F920 * v72 + unk_C8F790;
      unk_C8F794 = unk_C8F924 * v72 + unk_C8F794;
      unk_C8F798 = unk_C8F928 * v72 + unk_C8F798;
      unk_C8F79C = v72 * unk_C8F92C + unk_C8F79C;
      unk_C8F790 = flt_C8F930 * v73 + unk_C8F790;
      unk_C8F794 = flt_C8F934 * v73 + unk_C8F794;
      unk_C8F798 = flt_C8F938 * v73 + unk_C8F798;
      unk_C8F79C = v73 * flt_C8F93C + unk_C8F79C;
      flt_C8F960 = flt_C8F940 * v74 + unk_C8F790;
      flt_C8F964 = flt_C8F944 * v74 + unk_C8F794;
      flt_C8F968 = flt_C8F948 * v74 + unk_C8F798;
      flt_C8F96C = v74 * flt_C8F94C + unk_C8F79C;
      unk_C8F790 = v75 * flt_C8F910;
      unk_C8F794 = v75 * flt_C8F914;
      unk_C8F798 = v75 * flt_C8F918;
      unk_C8F79C = v75 * flt_C8F91C;
      unk_C8F790 = unk_C8F920 * v76 + unk_C8F790;
      unk_C8F794 = unk_C8F924 * v76 + unk_C8F794;
      unk_C8F798 = unk_C8F928 * v76 + unk_C8F798;
      unk_C8F79C = v76 * unk_C8F92C + unk_C8F79C;
      unk_C8F790 = v77 * flt_C8F930 + unk_C8F790;
      unk_C8F794 = v77 * flt_C8F934 + unk_C8F794;
      unk_C8F798 = v77 * flt_C8F938 + unk_C8F798;
      unk_C8F79C = v77 * flt_C8F93C + unk_C8F79C;
      flt_C8F970 = v78 * flt_C8F940 + unk_C8F790;
      flt_C8F974 = v78 * flt_C8F944 + unk_C8F794;
      flt_C8F978 = v78 * flt_C8F948 + unk_C8F798;
      flt_C8F97C = v78 * flt_C8F94C + unk_C8F79C;
      unk_C8F790 = v79 * flt_C8F910;
      unk_C8F794 = v79 * flt_C8F914;
      unk_C8F798 = v79 * flt_C8F918;
      unk_C8F79C = v79 * flt_C8F91C;
      unk_C8F790 = v80 * unk_C8F920 + unk_C8F790;
      unk_C8F794 = v80 * unk_C8F924 + unk_C8F794;
      unk_C8F798 = v80 * unk_C8F928 + unk_C8F798;
      unk_C8F79C = v80 * unk_C8F92C + unk_C8F79C;
      unk_C8F790 = v81 * flt_C8F930 + unk_C8F790;
      unk_C8F794 = v81 * flt_C8F934 + unk_C8F794;
      unk_C8F798 = v81 * flt_C8F938 + unk_C8F798;
      unk_C8F79C = flt_C8F93C * v81 + unk_C8F79C;
      unk_C8F980[0] = flt_C8F940 * v82 + unk_C8F790;
      flt_C8F984 = flt_C8F944 * v82 + unk_C8F794;
      flt_C8F988 = flt_C8F948 * v82 + unk_C8F798;
      flt_C8F98C[0] = flt_C8F94C * v82 + unk_C8F79C;
      v5 = v4[16];
      LODWORD(qword_C8F588) = v4[16];
      v6 = v4[17];
      v7 = v4[17];
      qword_C8F588 = v5;
      HIDWORD(qword_C8F588) = v7;
      unk_C8F590 = HIDWORD(v5);
      v119[24] = v5;
      unk_C8F594 = HIDWORD(v6);
      v119[25] = v7;
      v119[26] = HIDWORD(v5);
      qword_C8F598 = __PAIR64__(HIDWORD(v6), v7);
      v119[27] = HIDWORD(v6);
      v115 = (float)(int)v5;
      unk_C8F7D0 = v115 * 0.0625;
      v115 = (float)v7;
      unk_C8F7D4 = v115 * 0.0625;
      unk_C8F7D8 = *(float *)&dword_C0A00C;
      flt_C8F7DC = flt_C0A010;
      unk_C8F790 = flt_C8F950 * unk_C8F7D0;
      unk_C8F794 = flt_C8F954 * unk_C8F7D0;
      unk_C8F798 = flt_C8F958 * unk_C8F7D0;
      unk_C8F79C = unk_C8F7D0 * flt_C8F95C;
      unk_C8F790 = flt_C8F960 * unk_C8F7D4 + unk_C8F790;
      unk_C8F794 = flt_C8F964 * unk_C8F7D4 + unk_C8F794;
      unk_C8F798 = flt_C8F968 * unk_C8F7D4 + unk_C8F798;
      unk_C8F79C = unk_C8F7D4 * flt_C8F96C + unk_C8F79C;
      v8 = *(float *)&dword_C0A00C * flt_C8F970;
      unk_C8F790 = unk_C8F790 + v8;
      v9 = *(float *)&dword_C0A00C * flt_C8F974;
      unk_C8F794 = unk_C8F794 + v9;
      v83 = *(float *)&dword_C0A00C * flt_C8F978;
      unk_C8F798 = v83 + unk_C8F798;
      v114 = *(float *)&dword_C0A00C * flt_C8F97C;
      unk_C8F79C = v114 + unk_C8F79C;
      v84 = unk_C8F980[0] * flt_C0A010;
      flt_C8F940 = v84 + unk_C8F790;
      v85 = flt_C8F984 * flt_C0A010;
      flt_C8F944 = v85 + unk_C8F794;
      v91 = flt_C8F988 * flt_C0A010;
      flt_C8F948 = v91 + unk_C8F798;
      v101 = flt_C8F940;
      v90 = flt_C0A010 * flt_C8F98C[0];
      v102 = flt_C8F944;
      flt_C8F94C = v90 + unk_C8F79C;
      v103 = flt_C8F948;
      v104 = flt_C8F94C;
      if ( flt_C8F94C > 0.0 )
      {
        v10 = v4[18];
        LODWORD(qword_C8F588) = v4[18];
        v11 = v4[19];
        v12 = v4[19];
        qword_C8F588 = v10;
        HIDWORD(qword_C8F588) = v12;
        unk_C8F590 = HIDWORD(v10);
        v119[16] = v10;
        v119[17] = v12;
        unk_C8F594 = HIDWORD(v11);
        v119[18] = HIDWORD(v10);
        qword_C8F598 = __PAIR64__(HIDWORD(v11), v12);
        v119[19] = HIDWORD(v11);
        v115 = (float)(int)v10;
        unk_C8F7D0 = v115 * 0.0625;
        v115 = (float)v12;
        unk_C8F7D4 = v115 * 0.0625;
        unk_C8F7D8 = *(float *)&dword_C0A00C;
        flt_C8F7DC = flt_C0A010;
        unk_C8F790 = flt_C8F950 * unk_C8F7D0;
        unk_C8F794 = flt_C8F954 * unk_C8F7D0;
        unk_C8F798 = flt_C8F958 * unk_C8F7D0;
        unk_C8F79C = unk_C8F7D0 * flt_C8F95C;
        unk_C8F790 = flt_C8F960 * unk_C8F7D4 + unk_C8F790;
        unk_C8F794 = flt_C8F964 * unk_C8F7D4 + unk_C8F794;
        unk_C8F798 = flt_C8F968 * unk_C8F7D4 + unk_C8F798;
        unk_C8F79C = unk_C8F7D4 * flt_C8F96C + unk_C8F79C;
        unk_C8F790 = unk_C8F790 + v8;
        unk_C8F794 = unk_C8F794 + v9;
        unk_C8F798 = unk_C8F798 + v83;
        unk_C8F79C = unk_C8F79C + v114;
        flt_C8F940 = unk_C8F790 + v84;
        v105 = flt_C8F940;
        flt_C8F944 = unk_C8F794 + v85;
        v106 = flt_C8F944;
        flt_C8F948 = unk_C8F798 + v91;
        v107 = flt_C8F948;
        flt_C8F94C = unk_C8F79C + v90;
        v108 = flt_C8F94C;
        if ( flt_C8F94C > 0.0 )
        {
          v13 = v4[20];
          LODWORD(qword_C8F588) = v4[20];
          v14 = v4[21];
          v15 = v4[21];
          qword_C8F588 = v13;
          HIDWORD(qword_C8F588) = v15;
          unk_C8F590 = HIDWORD(v13);
          v119[12] = v13;
          v119[13] = v15;
          unk_C8F594 = HIDWORD(v14);
          v119[14] = HIDWORD(v13);
          qword_C8F598 = __PAIR64__(HIDWORD(v14), v15);
          v119[15] = HIDWORD(v14);
          v115 = (float)(int)v13;
          unk_C8F7D0 = v115 * 0.0625;
          v115 = (float)v15;
          unk_C8F7D4 = v115 * 0.0625;
          unk_C8F7D8 = *(float *)&dword_C0A00C;
          flt_C8F7DC = flt_C0A010;
          unk_C8F790 = flt_C8F950 * unk_C8F7D0;
          unk_C8F794 = flt_C8F954 * unk_C8F7D0;
          unk_C8F798 = flt_C8F958 * unk_C8F7D0;
          unk_C8F79C = unk_C8F7D0 * flt_C8F95C;
          unk_C8F790 = flt_C8F960 * unk_C8F7D4 + unk_C8F790;
          unk_C8F794 = flt_C8F964 * unk_C8F7D4 + unk_C8F794;
          unk_C8F798 = flt_C8F968 * unk_C8F7D4 + unk_C8F798;
          unk_C8F79C = unk_C8F7D4 * flt_C8F96C + unk_C8F79C;
          unk_C8F790 = unk_C8F790 + v8;
          unk_C8F794 = unk_C8F794 + v9;
          unk_C8F798 = v83 + unk_C8F798;
          unk_C8F79C = unk_C8F79C + v114;
          flt_C8F940 = unk_C8F790 + v84;
          v109 = flt_C8F940;
          flt_C8F944 = unk_C8F794 + v85;
          v110 = flt_C8F944;
          flt_C8F948 = unk_C8F798 + v91;
          v111 = flt_C8F948;
          flt_C8F94C = unk_C8F79C + v90;
          v112 = flt_C8F94C;
          if ( flt_C8F94C > 0.0 )
          {
            v16 = v4[22];
            LODWORD(qword_C8F588) = v4[22];
            v17 = v4[23];
            v18 = v4[23];
            qword_C8F588 = v16;
            HIDWORD(qword_C8F588) = v18;
            unk_C8F590 = HIDWORD(v16);
            v119[20] = v16;
            v119[21] = v18;
            unk_C8F594 = HIDWORD(v17);
            v119[22] = HIDWORD(v16);
            qword_C8F598 = __PAIR64__(HIDWORD(v17), v18);
            v119[23] = HIDWORD(v17);
            v115 = (float)(int)v16;
            unk_C8F7D0 = v115 * 0.0625;
            v115 = (float)v18;
            unk_C8F7D4 = 0.0625 * v115;
            unk_C8F7D8 = *(float *)&dword_C0A00C;
            flt_C8F7DC = flt_C0A010;
            unk_C8F790 = flt_C8F950 * unk_C8F7D0;
            unk_C8F794 = flt_C8F954 * unk_C8F7D0;
            unk_C8F798 = flt_C8F958 * unk_C8F7D0;
            unk_C8F79C = unk_C8F7D0 * flt_C8F95C;
            unk_C8F790 = flt_C8F960 * unk_C8F7D4 + unk_C8F790;
            unk_C8F794 = flt_C8F964 * unk_C8F7D4 + unk_C8F794;
            unk_C8F798 = flt_C8F968 * unk_C8F7D4 + unk_C8F798;
            unk_C8F79C = unk_C8F7D4 * flt_C8F96C + unk_C8F79C;
            unk_C8F790 = v8 + unk_C8F790;
            v19 = flt_C0A010;
            unk_C8F794 = v9 + unk_C8F794;
            unk_C8F798 = unk_C8F798 + v83;
            unk_C8F79C = unk_C8F79C + v114;
            flt_C8F940 = unk_C8F790 + v84;
            v93 = flt_C8F940;
            flt_C8F944 = unk_C8F794 + v85;
            v94 = flt_C8F944;
            flt_C8F948 = unk_C8F798 + v91;
            v95 = flt_C8F948;
            flt_C8F94C = unk_C8F79C + v90;
            v96 = flt_C8F94C;
            if ( flt_C8F94C > 0.0 )
              break;
          }
        }
      }
LABEL_34:
      result = v60;
      v2 = v92 + 16;
      v92 += 16;
      if ( !v60 )
        return result;
      v0 = (float *)dword_2305834[0];
    }
    unk_C8F788 = v19 / v104;
    unk_C8F7D0 = v101 * unk_C8F788;
    v115 = unk_C8F7D0;
    v101 = unk_C8F7D0;
    unk_C8F7D4 = unk_C8F788 * v102;
    v20 = unk_C8F7D4;
    v102 = unk_C8F7D4;
    unk_C8F7D8 = unk_C8F788 * v103;
    v21 = unk_C8F7D8;
    v103 = unk_C8F7D8;
    flt_C8F7DC = unk_C8F788 * v104;
    v22 = flt_C8F7DC;
    v104 = flt_C8F7DC;
    *((float *)&v85 + 1) = unk_C8F788 + flt_C0A004;
    unk_C8F788 = v19 / v108;
    unk_C8F7D0 = v105 * unk_C8F788;
    v63 = unk_C8F7D0;
    v105 = unk_C8F7D0;
    unk_C8F7D4 = unk_C8F788 * v106;
    v61 = unk_C8F7D4;
    v106 = unk_C8F7D4;
    unk_C8F7D8 = unk_C8F788 * v107;
    v59 = unk_C8F7D8;
    v107 = unk_C8F7D8;
    flt_C8F7DC = unk_C8F788 * v108;
    v57 = flt_C8F7DC;
    v108 = flt_C8F7DC;
    *((float *)&v84 + 1) = unk_C8F788 + flt_C0A004;
    unk_C8F788 = v19 / v112;
    unk_C8F7D0 = v109 * unk_C8F788;
    v65 = unk_C8F7D0;
    v109 = unk_C8F7D0;
    unk_C8F7D4 = unk_C8F788 * v110;
    v58 = unk_C8F7D4;
    v110 = unk_C8F7D4;
    unk_C8F7D8 = unk_C8F788 * v111;
    v62 = unk_C8F7D8;
    v111 = unk_C8F7D8;
    flt_C8F7DC = unk_C8F788 * v112;
    v66 = flt_C8F7DC;
    v112 = flt_C8F7DC;
    *((float *)&v114 + 1) = unk_C8F788 + flt_C0A004;
    unk_C8F788 = v19 / flt_C8F94C;
    unk_C8F7D0 = v93 * unk_C8F788;
    unk_C8F7D4 = unk_C8F788 * flt_C8F944;
    unk_C8F7D8 = unk_C8F788 * flt_C8F948;
    flt_C8F7DC = unk_C8F788 * flt_C8F94C;
    unk_C8F830 = flt_C0A004 + unk_C8F788;
    v54 = unk_C8F830;
    v64 = unk_C8F7D0;
    v93 = unk_C8F7D0;
    *((float *)&v83 + 1) = unk_C8F7D4;
    v94 = unk_C8F7D4;
    *((float *)&v90 + 1) = unk_C8F7D8;
    v95 = unk_C8F7D8;
    *((float *)&v91 + 1) = flt_C8F7DC;
    v96 = flt_C8F7DC;
    unk_C8F7E8 = 0.0;
    unk_C8F7EC = 0.0;
    unk_C8F800 = v115;
    dword_C8FAC4[0] = unk_C8F508[0];
    unk_C8F7D8 = 0.0;
    flt_C8F7DC = 0.0;
    unk_C8F7D4 = 1600.0;
    unk_C8F7D0 = 1528.0;
    unk_C8F7E4 = 2304.0;
    unk_C8F7E0 = 2576.0;
    unk_C8F804 = v20;
    unk_C8F808 = LODWORD(v21);
    unk_C8F80C = LODWORD(v22);
    sub_75E960((int)&unk_C8F7F0, (int)&unk_C8F800, 1528.0, 1600.0);
    sub_75E960((int)&unk_C8F7F0, (int)&unk_C8F7E0, unk_C8F800, unk_C8F804);
    if ( (dword_C8FAC4[0] & 0xC0) != 0 )
    {
      unk_C8F800 = v63;
      unk_C8F804 = v61;
      unk_C8F808 = LODWORD(v59);
      unk_C8F80C = LODWORD(v57);
      dword_C8FAC4[0] = unk_C8F508[0];
      unk_C8F7D4 = 1600.0;
      unk_C8F7D0 = 1528.0;
      unk_C8F7E4 = 2304.0;
      unk_C8F7E0 = 2576.0;
      sub_75E960((int)&unk_C8F7F0, (int)&unk_C8F800, 1528.0, 1600.0);
      sub_75E960((int)&unk_C8F7F0, (int)&unk_C8F7E0, unk_C8F800, unk_C8F804);
      if ( (dword_C8FAC4[0] & 0xC0) != 0 )
      {
        unk_C8F800 = v65;
        unk_C8F804 = v58;
        unk_C8F808 = LODWORD(v62);
        unk_C8F80C = LODWORD(v66);
        dword_C8FAC4[0] = unk_C8F508[0];
        unk_C8F7D4 = 1600.0;
        unk_C8F7D0 = 1528.0;
        unk_C8F7E4 = 2304.0;
        unk_C8F7E0 = 2576.0;
        sub_75E960((int)&unk_C8F7F0, (int)&unk_C8F800, 1528.0, 1600.0);
        sub_75E960((int)&unk_C8F7F0, (int)&unk_C8F7E0, unk_C8F800, unk_C8F804);
        if ( (dword_C8FAC4[0] & 0xC0) != 0 )
        {
          unk_C8F800 = v64;
          unk_C8F804 = *((float *)&v83 + 1);
          unk_C8F808 = HIDWORD(v90);
          unk_C8F80C = HIDWORD(v91);
          dword_C8FAC4[0] = unk_C8F508[0];
          unk_C8F7D4 = 1600.0;
          unk_C8F7D0 = 1528.0;
          unk_C8F7E4 = 2304.0;
          unk_C8F7E0 = 2576.0;
          sub_75E960((int)&unk_C8F7F0, (int)&unk_C8F800, 1528.0, 1600.0);
          sub_75E960((int)&unk_C8F7F0, (int)&unk_C8F7E0, unk_C8F800, unk_C8F804);
        }
      }
    }
    v23 = v113;
    v24 = *(__int16 *)(LODWORD(v113) + 48);
    LODWORD(qword_C8F588) = *(__int16 *)(LODWORD(v113) + 48);
    v25 = *(__int16 *)(LODWORD(v113) + 50);
    v26 = *(__int16 *)(LODWORD(v113) + 50);
    qword_C8F588 = v24;
    HIDWORD(qword_C8F588) = v26;
    unk_C8F590 = HIDWORD(v24);
    v119[4] = v24;
    v119[5] = v26;
    unk_C8F594 = HIDWORD(v25);
    v119[6] = HIDWORD(v24);
    v119[7] = HIDWORD(v25);
    qword_C8F598 = __PAIR64__(HIDWORD(v25), v26);
    v113 = (float)(int)v24;
    unk_C8F7D0 = v113 * 0.000244140625;
    v113 = (float)v26;
    v86 = unk_C8F7D0;
    unk_C8F7D4 = v113 * 0.000244140625;
    v87 = unk_C8F7D4;
    unk_C8F7D8 = *(float *)&dword_C0A00C;
    v88 = *(float *)&dword_C0A00C;
    flt_C8F7DC = flt_C0A010;
    v89 = flt_C0A010;
    v27 = *(__int16 *)(LODWORD(v23) + 52);
    LODWORD(qword_C8F588) = *(__int16 *)(LODWORD(v23) + 52);
    v28 = *(__int16 *)(LODWORD(v23) + 54);
    qword_C8F598 = v28;
    qword_C8F588 = v27;
    v119[8] = v27;
    HIDWORD(qword_C8F588) = v28;
    unk_C8F590 = HIDWORD(v27);
    unk_C8F594 = HIDWORD(v28);
    v119[9] = v28;
    v119[10] = HIDWORD(v27);
    v119[11] = HIDWORD(v28);
    v113 = (float)(int)v27;
    unk_C8F7D0 = v113 * 0.000244140625;
    v113 = (float)(int)v28;
    v97 = unk_C8F7D0;
    v29 = (float *)dword_1A860EC;
    unk_C8F7D4 = 0.000244140625 * v113;
    v98 = unk_C8F7D4;
    unk_C8F7D8 = *(float *)&dword_C0A00C;
    flt_C8F7DC = flt_C0A010;
    v99 = 1.0;
    *dword_1A860EC = 32769;
    v88 = 1.0;
    dword_1A860EC[1] = -804634624;
    v100 = 0.0;
    v89 = 0.0;
    v97 = v86 + v97;
    v98 = v87 + v98;
    v55 = v87;
    v30 = v86;
    v31 = v97;
    v56 = v98;
    v29[2] = 1.2690986e-16;
    *((_DWORD *)v29 + 3) = 332369;
    v29[4] = *(float *)(LODWORD(v23) + 16);
    v29[5] = *(float *)(LODWORD(v23) + 20);
    *((_DWORD *)v29 + 6) = 6;
    v29[7] = 0.0;
    n10000 = *(_DWORD *)(LODWORD(v23) + 16) & 0x3FFF;
    if ( n10000 == 13568 )
      n10000 = 10000;
    *(float *)v118 = v101;
    *(float *)&v118[1] = v102;
    *(float *)&v118[2] = v103;
    *(float *)&v118[3] = v104;
    for ( i = 0; i < 2; ++i )
      *(_DWORD *)((char *)&unk_C8F800 + i * 4) = (int)(*(float *)&v118[i] * 16.0);
    v29[16] = unk_C8F800;
    v29[17] = unk_C8F804;
    *((_DWORD *)v29 + 18) = unk_C8F808;
    *(float *)v116 = v105;
    *(float *)&v116[1] = v106;
    *(float *)&v116[2] = v107;
    v34 = v108;
    *((_DWORD *)v29 + 18) = 12288;
    *((_DWORD *)v29 + 19) = 0x8000;
    *(float *)&v116[3] = v34;
    for ( j = 0; j < 2; ++j )
      *(_DWORD *)((char *)&unk_C8F800 + j * 4) = (int)(*(float *)&v116[j] * 16.0);
    v29[28] = unk_C8F800;
    v29[29] = unk_C8F804;
    *((_DWORD *)v29 + 30) = unk_C8F808;
    *(float *)v119 = v109;
    *(float *)&v119[1] = v110;
    *(float *)&v119[2] = v111;
    v36 = v112;
    *((_DWORD *)v29 + 30) = 12288;
    v29[31] = 0.0;
    *(float *)&v119[3] = v36;
    for ( k = 0; k < 2; ++k )
      *(_DWORD *)((char *)&unk_C8F800 + k * 4) = (int)(*(float *)&v119[k] * 16.0);
    v38 = v93;
    v39 = v94;
    v40 = v95;
    v29[40] = unk_C8F800;
    v29[41] = unk_C8F804;
    *((_DWORD *)v29 + 42) = unk_C8F808;
    v41 = v96;
    *((_DWORD *)v29 + 42) = 12288;
    v29[43] = 0.0;
    unk_C8F810 = v38;
    *(float *)v117 = v38;
    unk_C8F814 = v39;
    unk_C8F818 = v40;
    unk_C8F81C = LODWORD(v41);
    *(float *)&v117[1] = v39;
    *(float *)&v117[2] = v40;
    *(float *)&v117[3] = v41;
    for ( m = 0; m < 2; ++m )
      *(_DWORD *)((char *)&unk_C8F800 + m * 4) = (int)(*(float *)&v117[m] * 16.0);
    v29[52] = unk_C8F800;
    v43 = *((float *)&v85 + 1);
    v29[53] = unk_C8F804;
    *((_DWORD *)v29 + 54) = unk_C8F808;
    *((_DWORD *)v29 + 54) = 12288;
    v29[55] = 0.0;
    unk_C8F7D0 = v30 * v43;
    unk_C8F7D4 = v87 * v43;
    flt_C8F7DC = v89;
    unk_C8F7D8 = v43 * v88;
    v29[8] = unk_C8F7D0;
    v44 = *((float *)&v84 + 1);
    v29[9] = unk_C8F7D4;
    v29[10] = unk_C8F7D8;
    v29[11] = flt_C8F7DC;
    unk_C8F7D0 = v31 * v44;
    unk_C8F7D4 = v55 * v44;
    flt_C8F7DC = 0.0;
    unk_C8F7D8 = v44 * (float)1.0;
    v29[20] = unk_C8F7D0;
    v45 = *((float *)&v114 + 1);
    v29[21] = unk_C8F7D4;
    v29[22] = unk_C8F7D8;
    v29[23] = flt_C8F7DC;
    unk_C8F7D0 = v30 * v45;
    unk_C8F7D4 = v56 * v45;
    flt_C8F7DC = 0.0;
    unk_C8F7D8 = v45 * (float)1.0;
    v29[32] = unk_C8F7D0;
    v29[33] = unk_C8F7D4;
    v29[34] = unk_C8F7D8;
    v29[35] = flt_C8F7DC;
    unk_C8F7E0 = v54;
    unk_C8F7D0 = v31 * v54;
    flt_C8F7DC = v100;
    unk_C8F7D4 = v98 * v54;
    unk_C8F7D8 = v54 * v99;
    v29[44] = unk_C8F7D0;
    v46 = (double)*((int *)v29 + 16);
    v29[45] = unk_C8F7D4;
    v29[46] = unk_C8F7D8;
    v47 = flt_C8F7DC;
    *((_DWORD *)v29 + 48) = 64;
    *((_DWORD *)v29 + 36) = 64;
    *((_DWORD *)v29 + 24) = 64;
    *((_DWORD *)v29 + 12) = 64;
    v29[47] = v47;
    *((_DWORD *)v29 + 49) = 64;
    *((_DWORD *)v29 + 37) = 64;
    *((_DWORD *)v29 + 25) = 64;
    *((_DWORD *)v29 + 13) = 64;
    *((_DWORD *)v29 + 50) = 64;
    *((_DWORD *)v29 + 38) = 64;
    *((_DWORD *)v29 + 26) = 64;
    *((_DWORD *)v29 + 14) = 64;
    *((_DWORD *)v29 + 51) = 64;
    *((_DWORD *)v29 + 39) = 64;
    *((_DWORD *)v29 + 27) = 64;
    *((_DWORD *)v29 + 15) = 64;
    *((float *)&v114 + 1) = v46;
    *(float *)v120 = *((float *)&v114 + 1) * 0.0625 - 2048.0 + 256.0;
    *((float *)&v114 + 1) = (float)*((int *)v29 + 17);
    *(float *)&v120[1] = *((float *)&v114 + 1) * 0.0625 - 2048.0 + 208.0;
    *((float *)&v114 + 1) = (float)*((int *)v29 + 28);
    v127 = *((float *)&v114 + 1) * 0.0625 - 2048.0 + 256.0;
    *((float *)&v114 + 1) = (float)*((int *)v29 + 29);
    v128 = *((float *)&v114 + 1) * 0.0625 - 2048.0 + 208.0;
    *((float *)&v114 + 1) = (float)*((int *)v29 + 40);
    v135 = *((float *)&v114 + 1) * 0.0625 - 2048.0 + 256.0;
    *((float *)&v114 + 1) = (float)*((int *)v29 + 41);
    v136 = *((float *)&v114 + 1) * 0.0625 - 2048.0 + 208.0;
    *((float *)&v114 + 1) = (float)*((int *)v29 + 52);
    v143 = *((float *)&v114 + 1) * 0.0625 - 2048.0 + 256.0;
    *((float *)&v114 + 1) = (float)*((int *)v29 + 53);
    v144 = 0.0625 * *((float *)&v114 + 1) - 2048.0 + 208.0;
    v121 = v29[8] / v29[10];
    v122 = v29[9] / v29[10];
    v129 = v29[20] / v29[22];
    v130 = v29[21] / v29[22];
    v137 = v29[32] / v29[34];
    v138 = v29[33] / v29[34];
    v145 = v29[44] / v29[46];
    v146 = v29[45] / v29[46];
    if ( n10000 > 0x3000 )
    {
      if ( n10000 == 12800 )
      {
        v121 = v121 * 0.5;
        v129 = v129 * 0.5;
        v137 = v137 * 0.5;
        v48 = 0.5 * v145;
        goto LABEL_32;
      }
      if ( n10000 != 13824 )
      {
LABEL_33:
        n64 = 64;
        n64_1 = 64;
        n64_2 = 64;
        n128 = 128;
        n64_3 = 64;
        n64_4 = 64;
        n64_5 = 64;
        n128_1 = 128;
        n64_6 = 64;
        n64_7 = 64;
        n64_8 = 64;
        n128_2 = 128;
        n64_9 = 64;
        n64_10 = 64;
        n64_11 = 64;
        n128_3 = 128;
        sub_63EAE0((int)v120, 0, 2);
        goto LABEL_34;
      }
      v49 = 0.125;
      v50 = 0.875;
      v121 = v121 * 0.125 + 0.875;
      v51 = v122;
      v52 = 0.25;
    }
    else
    {
      if ( n10000 == 12288 )
      {
        v121 = v121 * 0.5 + 0.5;
        v122 = v122 - 0.25;
        v129 = v129 * 0.5 + 0.5;
        v130 = v130 - 0.25;
        v137 = v137 * 0.5 + 0.5;
        v138 = v138 - 0.25;
        v145 = v145 * 0.5 + 0.5;
        v146 = v146 - 0.25;
        goto LABEL_33;
      }
      if ( n10000 != 10000 )
      {
        if ( n10000 == 12032 )
        {
          v121 = v121 * 0.5 + 0.375;
          v129 = v129 * 0.5 + 0.375;
          v137 = v137 * 0.5 + 0.375;
          v48 = 0.5 * v145 + 0.375;
LABEL_32:
          v145 = v48;
          goto LABEL_33;
        }
        goto LABEL_33;
      }
      v49 = 0.25;
      v50 = 0.75;
      v121 = v121 * 0.25 + 0.75;
      v51 = v122;
      v52 = 0.5;
    }
    v53 = v52;
    v122 = v51 * v52 + v52;
    v129 = v129 * v49 + v50;
    v130 = v130 * v53 + v53;
    v137 = v137 * v49 + v50;
    v138 = v138 * v53 + v53;
    v145 = v50 + v49 * v145;
    v146 = v53 + v146 * v53;
    goto LABEL_33;
  }
  return result;
}

