// Function: sub_A4B790
// Address: 0xa4b790
// Size: 0xc81
// Prototype: 

int sub_A4B790()
{
  int v0; // eax
  double v1; // st7
  float *v2; // edx
  double v3; // st6
  int v4; // ebx
  int n7; // esi
  float *v6; // ecx
  char *v7; // edi
  double v8; // rt0
  float v9; // eax
  double v10; // st5
  double v11; // rt2
  double v12; // st6
  double v13; // st7
  int n2; // esi
  double v15; // st7
  double v16; // st6
  int v17; // edx
  int n7_1; // esi
  _DWORD *v19; // ecx
  int v20; // ebx
  double v21; // rt0
  double v22; // rt1
  double v23; // st6
  double v24; // st7
  char v25; // al
  char n2_1; // al
  double v27; // st6
  __int16 v28; // ax
  int v29; // esi
  int v30; // edi
  __int16 v31; // ax
  int v32; // eax
  int v33; // ecx
  int v34; // edx
  double v35; // st7
  double v36; // st7
  double v37; // st7
  double v38; // st7
  double v39; // st6
  double v40; // st4
  double v41; // st5
  double v42; // st7
  char n2_2; // al
  double v44; // st7
  double v45; // st7
  double v46; // st7
  int v47; // eax
  int v48; // edi
  double v49; // st7
  int v50; // eax
  int v52; // [esp+0h] [ebp-29Ch]
  int v53; // [esp+0h] [ebp-29Ch]
  int n19; // [esp+Ch] [ebp-290h] BYREF
  int v55; // [esp+10h] [ebp-28Ch]
  float v56; // [esp+14h] [ebp-288h] BYREF
  int n19_1; // [esp+18h] [ebp-284h]
  int n7_2; // [esp+1Ch] [ebp-280h]
  _BYTE *v59; // [esp+20h] [ebp-27Ch]
  int v60; // [esp+24h] [ebp-278h]
  int v61; // [esp+28h] [ebp-274h]
  int v62; // [esp+2Ch] [ebp-270h]
  float v63; // [esp+30h] [ebp-26Ch]
  float v64; // [esp+34h] [ebp-268h]
  float v65; // [esp+38h] [ebp-264h]
  float v66; // [esp+3Ch] [ebp-260h]
  _DWORD v67[8]; // [esp+40h] [ebp-25Ch]
  int v68; // [esp+60h] [ebp-23Ch] BYREF
  float v69; // [esp+64h] [ebp-238h]
  float v70; // [esp+68h] [ebp-234h]
  float v71; // [esp+6Ch] [ebp-230h]
  int n128; // [esp+70h] [ebp-22Ch]
  int n128_1; // [esp+74h] [ebp-228h]
  int n128_2; // [esp+78h] [ebp-224h]
  int n128_3; // [esp+7Ch] [ebp-220h]
  float v76; // [esp+80h] [ebp-21Ch]
  float v77; // [esp+84h] [ebp-218h]
  float v78; // [esp+88h] [ebp-214h]
  float v79; // [esp+8Ch] [ebp-210h]
  int n128_4; // [esp+90h] [ebp-20Ch]
  int n128_5; // [esp+94h] [ebp-208h]
  int n128_6; // [esp+98h] [ebp-204h]
  int n128_7; // [esp+9Ch] [ebp-200h]
  int v84; // [esp+A0h] [ebp-1FCh]
  float v85; // [esp+A4h] [ebp-1F8h]
  float v86; // [esp+A8h] [ebp-1F4h]
  float v87; // [esp+ACh] [ebp-1F0h]
  int n128_8; // [esp+B0h] [ebp-1ECh]
  int n128_9; // [esp+B4h] [ebp-1E8h]
  int n128_10; // [esp+B8h] [ebp-1E4h]
  int n128_11; // [esp+BCh] [ebp-1E0h]
  float v92; // [esp+C0h] [ebp-1DCh]
  float v93; // [esp+C4h] [ebp-1D8h]
  float v94; // [esp+C8h] [ebp-1D4h]
  float v95; // [esp+CCh] [ebp-1D0h]
  int n128_12; // [esp+D0h] [ebp-1CCh]
  int n128_13; // [esp+D4h] [ebp-1C8h]
  int n128_14; // [esp+D8h] [ebp-1C4h]
  int n128_15; // [esp+DCh] [ebp-1C0h]
  int v100; // [esp+F0h] [ebp-1ACh]
  int v101; // [esp+F4h] [ebp-1A8h]
  _BYTE v102[12]; // [esp+F8h] [ebp-1A4h] BYREF
  char v103; // [esp+104h] [ebp-198h] BYREF
  int v104; // [esp+178h] [ebp-124h] BYREF
  int v105; // [esp+17Ch] [ebp-120h]
  float v106[4]; // [esp+188h] [ebp-114h] BYREF
  char Str[256]; // [esp+198h] [ebp-104h] BYREF

  v0 = FFX_Memory_Alloc(0x1ECu, v52);
  v1 = 0.0;
  v2 = (float *)dword_2305834[0];
  v3 = 16.0;
  v4 = v0;
  n7 = 7;
  v6 = (float *)(dword_2305834[0] + 69828);
  v55 = v0;
  LODWORD(v65) = 7;
  v7 = &v103;
  v62 = dword_2305834[0] + 69828;
  while ( 1 )
  {
    flt_C8F940 = *(v6 - 11);
    flt_C8F944 = *(v6 - 10);
    flt_C8F948 = *(v6 - 9);
    unk_C8F94C = *((_DWORD *)v6 - 8);
    flt_C8F950 = v2[17656];
    flt_C8F954 = v2[17657];
    flt_C8F958 = v2[17658];
    flt_C8F95C = v2[17659];
    flt_C8F960 = v2[17660];
    flt_C8F964 = v2[17661];
    flt_C8F968 = v2[17662];
    flt_C8F96C = v2[17663];
    flt_C8F970 = v2[17664];
    flt_C8F974 = v2[17665];
    flt_C8F978 = v2[17666];
    flt_C8F97C = v2[17667];
    unk_C8F980[0] = v2[17668];
    flt_C8F984 = v2[17669];
    flt_C8F988 = v2[17670];
    v9 = v2[17671];
    unk_C8F790 = flt_C8F940 * flt_C8F950;
    flt_C8F98C[0] = v9;
    unk_C8F794 = flt_C8F954 * flt_C8F940;
    unk_C8F798 = flt_C8F958 * flt_C8F940;
    unk_C8F79C = flt_C8F940 * flt_C8F95C;
    unk_C8F790 = flt_C8F944 * flt_C8F960 + unk_C8F790;
    unk_C8F794 = flt_C8F964 * flt_C8F944 + unk_C8F794;
    unk_C8F798 = flt_C8F968 * flt_C8F944 + unk_C8F798;
    unk_C8F79C = flt_C8F944 * flt_C8F96C + unk_C8F79C;
    unk_C8F790 = flt_C8F948 * flt_C8F970 + unk_C8F790;
    unk_C8F794 = flt_C8F974 * flt_C8F948 + unk_C8F794;
    unk_C8F798 = flt_C8F978 * flt_C8F948 + unk_C8F798;
    v10 = flt_C8F948 * flt_C8F97C;
    *(_DWORD *)v7 = 0;
    unk_C8F79C = v10 + unk_C8F79C;
    flt_C8F930 = unk_C8F980[0] * flt_C0A010 + unk_C8F790;
    flt_C8F934 = flt_C8F984 * flt_C0A010 + unk_C8F794;
    flt_C8F938 = flt_C8F988 * flt_C0A010 + unk_C8F798;
    flt_C8F93C = flt_C0A010 * flt_C8F98C[0] + unk_C8F79C;
    *(float *)(v4 + 48) = flt_C8F930;
    v11 = v3;
    v12 = v1;
    v13 = v11;
    *(float *)(v4 + 52) = flt_C8F934;
    *(float *)(v4 + 56) = flt_C8F938;
    *(float *)(v4 + 60) = flt_C8F93C;
    if ( v12 < *v6 && v12 < *(float *)(v4 + 60) )
    {
      unk_C8F7D0 = *(float *)(v4 + 48);
      unk_C8F7D4 = *(float *)(v4 + 52);
      unk_C8F7D8 = *(float *)(v4 + 56);
      flt_C8F7DC = *(float *)(v4 + 60);
      unk_C8F7E0 = *(float *)(v4 + 60);
      n2 = 0;
      unk_C8F788 = flt_C0A010 / unk_C8F7E0;
      unk_C8F7D0 = unk_C8F7D0 * unk_C8F788;
      unk_C8F7D4 = unk_C8F7D4 * unk_C8F788;
      unk_C8F7D8 = unk_C8F788 * unk_C8F7D8;
      *(float *)(v4 + 48) = unk_C8F7D0;
      *(float *)(v4 + 52) = unk_C8F7D4;
      *(float *)(v4 + 56) = unk_C8F7D8;
      *(float *)(v4 + 60) = flt_C8F7DC;
      n7_2 = *(_DWORD *)(v4 + 48);
      LODWORD(unk_C8F810) = n7_2;
      v59 = *(_BYTE **)(v4 + 52);
      LODWORD(unk_C8F814) = v59;
      v56 = *(float *)(v4 + 56);
      unk_C8F818 = v56;
      v66 = *(float *)(v4 + 60);
      unk_C8F81C = LODWORD(v66);
      v67[0] = *(_DWORD *)(v4 + 48);
      v67[1] = *(_DWORD *)(v4 + 52);
      v67[2] = *(_DWORD *)(v4 + 56);
      v67[3] = *(_DWORD *)(v4 + 60);
      do
      {
        *(_DWORD *)((char *)&unk_C8F800 + n2 * 4) = (int)(*(float *)&v67[n2] * v13);
        ++n2;
      }
      while ( n2 < 2 );
      v67[4] = n7_2;
      v67[5] = v59;
      *(float *)&v67[6] = v56;
      *(float *)&v67[7] = v66;
      unk_C8F808 = (int)v56;
      unk_C8F80C = (int)v66;
      v6 = (float *)v62;
      *(float *)&n7 = v65;
      *(float *)(v4 + 96) = unk_C8F800;
      *(float *)(v4 + 100) = unk_C8F804;
      *(_DWORD *)(v4 + 104) = unk_C8F808;
      *(_DWORD *)(v4 + 108) = unk_C8F80C;
      *((_DWORD *)v7 - 3) = *(int *)(v4 + 96) >> 4;
      *((_DWORD *)v7 - 2) = *(int *)(v4 + 100) >> 4;
      *(_DWORD *)v7 = 1;
    }
    v6 += 20;
    v7 += 16;
    --n7;
    v62 = (int)v6;
    v65 = *(float *)&n7;
    if ( *(float *)&n7 == 0.0 )
      break;
    v2 = (float *)dword_2305834[0];
    v8 = v12;
    v3 = v13;
    v1 = v8;
  }
  v15 = v12;
  v16 = 1.0;
  v17 = 0;
  n7_1 = 7;
  v19 = v102;
  v100 = 0;
  v101 = 0;
  n7_2 = 7;
  v62 = 0;
  v20 = dword_2305834[0] + 69768;
  v59 = v102;
  while ( 1 )
  {
    v22 = v16;
    v23 = v15;
    v24 = v22;
    if ( v23 >= *(float *)(v20 + 60) || !v19[3] )
      goto LABEL_41;
    LODWORD(v65) = *v19 - 2048;
    v25 = *(_BYTE *)(v20 + 78);
    v106[0] = (float)SLODWORD(v65);
    n2_1 = v25 & 3;
    if ( !n2_1 || n2_1 == 2 )
      v27 = *(float *)v20 - v106[0] + *(float *)(v20 + 4);
    else
      v27 = *(float *)(v20 + 4) - (*(float *)v20 - v106[0]);
    v106[1] = v27;
    v106[2] = v24;
    v106[3] = v24;
    sub_642A80(&v104, v106);
    v28 = *(_WORD *)(v20 + 70);
    v29 = v104 + 256;
    v30 = v105 + 208;
    v60 = v104 + 256;
    v61 = v105 + 208;
    if ( v28 )
    {
      v29 += v28 >> 4;
      v60 = v29;
    }
    v31 = *(_WORD *)(v20 + 72);
    if ( v31 )
    {
      v30 += v31 >> 4;
      v61 = v30;
    }
    v32 = *(__int16 *)(v20 + 48);
    LODWORD(v66) = v62 != *(unsigned __int8 *)(dword_2305834[0] + 71100);
    v65 = (float)(v32 + *(__int16 *)(v20 + 56));
    v33 = *(_BYTE *)(v20 + 78) & 3;
    v34 = (int)v65;
    v65 = *(float *)&v34;
    n19 = 19;
    switch ( v33 )
    {
      case 0:
        v35 = 0.25;
        goto LABEL_23;
      case 1:
        v35 = 0.51464844;
        v29 += -7 - v34;
        v60 = v29;
LABEL_23:
        v30 -= 19;
        v64 = v35;
        v36 = 0.18554688;
        v61 = v30;
        n19_1 = 19;
        goto LABEL_28;
      case 2:
        v37 = 0.51464844;
        v29 += -7 - v34;
        v60 = v29;
        goto LABEL_27;
      case 3:
        v37 = 0.25;
LABEL_27:
        v64 = v37;
        n19_1 = 1;
        v36 = 0.11914062;
LABEL_28:
        v63 = v36;
        break;
      default:
        break;
    }
    if ( v66 == 0.0 )
    {
      v38 = v63;
      if ( v64 > 0.5 )
      {
        v64 = 0.76464844;
        v39 = (float)0.76464844;
LABEL_32:
        v66 = (float)(v34 + v29);
        *(float *)&v68 = v66;
        v66 = (float)v61;
        v40 = v66;
        LODWORD(v66) = v34 + v29 + 7;
        v69 = v40;
        v66 = (float)SLODWORD(v66);
        v76 = v66;
        v92 = v66;
        v77 = v40;
        v66 = (float)(v30 + 19);
        n128 = 128;
        n128_1 = 128;
        n128_2 = 128;
        v93 = v66;
        n128_3 = 128;
        v85 = v66;
        n128_4 = 128;
        n128_5 = 128;
        v84 = v68;
        n128_6 = 128;
        n128_7 = 128;
        n128_8 = 128;
        n128_9 = 128;
        n128_10 = 128;
        n128_11 = 128;
        v66 = v39 + 0.2099609375;
        n128_12 = 128;
        n128_13 = 128;
        v70 = v66;
        n128_14 = 128;
        v41 = v38;
        v42 = v66;
        n128_15 = 128;
        v71 = v41;
        v66 = v39 + 0.236328125;
        v78 = v66;
        v94 = v66;
        v79 = v41;
        v66 = v41 + 0.05078125;
        v95 = v66;
        v87 = v66;
        v86 = v42;
        sub_63EAE0((int)&v68, Str, 5);
        v66 = (float)v60;
        v76 = v66;
        v92 = v66;
        v78 = v64;
        v94 = v64;
        goto LABEL_33;
      }
      v64 = 0.0;
      v39 = (float)0.0;
    }
    else
    {
      v39 = v64;
      v38 = v63;
      if ( v64 >= 0.5 )
        goto LABEL_32;
    }
    v66 = (float)v60;
    *(float *)&v68 = v66;
    v66 = (float)v61;
    v69 = v66;
    v66 = (float)(v29 + 7);
    v76 = v66;
    v92 = v66;
    v77 = v69;
    v66 = (float)(v30 + 19);
    n128 = 128;
    n128_1 = 128;
    n128_2 = 128;
    v93 = v66;
    n128_3 = 128;
    v85 = v66;
    n128_4 = 128;
    n128_5 = 128;
    v84 = v68;
    n128_6 = 128;
    n128_7 = 128;
    v70 = v39;
    n128_8 = 128;
    n128_9 = 128;
    v71 = v38;
    n128_10 = 128;
    n128_11 = 128;
    n128_12 = 128;
    n128_13 = 128;
    n128_14 = 128;
    v66 = v39 + 0.0263671875;
    n128_15 = 128;
    v78 = v66;
    v94 = v66;
    v79 = v71;
    v66 = v38 + 0.05078125;
    v95 = v66;
    v87 = v66;
    v86 = v39;
    sub_63EAE0((int)&v68, Str, 5);
    LODWORD(v66) = v29 + LODWORD(v65) + 7;
    v66 = (float)SLODWORD(v66);
    *(float *)&v68 = v66;
    *(float *)&v84 = v66;
    v66 = v64 + 0.236328125;
    v70 = v66;
    v86 = v66;
LABEL_33:
    sub_63EAE0((int)&v68, Str, 5);
    sub_8B70E0(*(_DWORD *)(v20 + 44), &v56, &n19);
    n2_2 = *(_BYTE *)(v20 + 78) & 3;
    if ( n2_2 == 1 || n2_2 == 2 )
    {
      v65 = (float)SLODWORD(v65);
      v46 = v65;
      v65 = (float)SLODWORD(v56);
      v45 = (v46 - v65) * 0.5;
    }
    else
    {
      v65 = (float)SLODWORD(v65);
      v44 = v65;
      v65 = (float)SLODWORD(v56);
      v45 = (v44 - v65) * 0.5 + 7.0;
    }
    v47 = (int)v45;
    v48 = n19_1 + *(__int16 *)(v20 + 76);
    v49 = *(float *)(dword_2305834[0] + 70484) * 100.0;
    v65 = *(float *)&v47;
    v50 = sub_8E8FB0(
            unk_230FD2C + 16,
            -1,
            *(_DWORD *)(v20 + 44),
            v47 + v60,
            v61 + v48,
            0,
            0,
            128,
            128,
            128,
            *(_BYTE *)(dword_2305834[0] + 71097),
            (int)v49);
    v19 = v59;
    v17 = v62;
    n7_1 = n7_2;
    v23 = 0.0;
    v24 = 1.0;
    unk_230FD2C = v50;
LABEL_41:
    v19 += 4;
    ++v17;
    v20 += 80;
    --n7_1;
    v59 = v19;
    v62 = v17;
    n7_2 = n7_1;
    if ( !n7_1 )
      return FFX_Memory_Delete(v55, v53);
    v21 = v23;
    v16 = v24;
    v15 = v21;
  }
}

