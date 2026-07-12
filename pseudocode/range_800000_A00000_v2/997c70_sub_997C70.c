// Function: sub_997C70
// Address: 0x997c70
double __userpurge sub_997C70@<st0>(int a1@<ecx>, int a2@<ebp>, float *a3, float *a4, int a5, int a6)
{
  float *v6; // edi
  float *v7; // esi
  double v8; // st7
  double v9; // st6
  double v10; // st7
  double v11; // st4
  double v12; // st7
  double v13; // st6
  double v14; // st4
  double v15; // st5
  double v16; // st3
  double v17; // st4
  double v18; // st4
  double v19; // st3
  double v20; // st7
  double v21; // st5
  double result; // st7
  float v23; // xmm1_4
  double v24; // st4
  double v25; // st2
  bool v26; // cc
  double v27; // st5
  double v28; // st6
  int v29; // ecx
  float v30; // xmm0_4
  double v31; // st7
  float v32; // [esp+1Ch] [ebp-23Ch]
  float v33; // [esp+1Ch] [ebp-23Ch]
  float v34; // [esp+20h] [ebp-238h]
  float v35; // [esp+24h] [ebp-234h]
  float v36; // [esp+2Ch] [ebp-22Ch]
  float v37; // [esp+2Ch] [ebp-22Ch]
  float v38; // [esp+30h] [ebp-228h]
  float v39; // [esp+34h] [ebp-224h]
  float v40; // [esp+34h] [ebp-224h]
  float v41; // [esp+38h] [ebp-220h]
  float v42; // [esp+38h] [ebp-220h]
  float v43; // [esp+3Ch] [ebp-21Ch] BYREF
  float v44; // [esp+40h] [ebp-218h]
  float v45; // [esp+44h] [ebp-214h]
  float v46; // [esp+48h] [ebp-210h]
  float v47; // [esp+58h] [ebp-200h]
  float v48; // [esp+5Ch] [ebp-1FCh] BYREF
  float v49; // [esp+60h] [ebp-1F8h]
  float v50; // [esp+64h] [ebp-1F4h]
  float v51; // [esp+68h] [ebp-1F0h]
  float v52; // [esp+74h] [ebp-1E4h]
  float v53; // [esp+78h] [ebp-1E0h]
  float v54; // [esp+7Ch] [ebp-1DCh]
  float v55; // [esp+80h] [ebp-1D8h]
  float v56; // [esp+84h] [ebp-1D4h]
  float v57; // [esp+88h] [ebp-1D0h]
  float v58; // [esp+8Ch] [ebp-1CCh]
  float v59; // [esp+90h] [ebp-1C8h]
  float v60; // [esp+94h] [ebp-1C4h]
  float v61; // [esp+98h] [ebp-1C0h]
  _DWORD v62[53]; // [esp+9Ch] [ebp-1BCh] BYREF
  float v63; // [esp+170h] [ebp-E8h]
  _DWORD v64[16]; // [esp+17Ch] [ebp-DCh] BYREF
  float v65; // [esp+1BCh] [ebp-9Ch]
  float v66; // [esp+1C0h] [ebp-98h]
  float v67; // [esp+1C4h] [ebp-94h]
  int v68; // [esp+1C8h] [ebp-90h]
  float v69; // [esp+1CCh] [ebp-8Ch]
  float v70; // [esp+1D0h] [ebp-88h]
  float v71; // [esp+1D4h] [ebp-84h]
  int v72; // [esp+1D8h] [ebp-80h]
  float v73; // [esp+1DCh] [ebp-7Ch]
  float v74; // [esp+1E0h] [ebp-78h]
  float v75; // [esp+1E4h] [ebp-74h]
  int v76; // [esp+1E8h] [ebp-70h]
  float v77; // [esp+1ECh] [ebp-6Ch] BYREF
  float v78; // [esp+1F0h] [ebp-68h]
  float v79; // [esp+1F4h] [ebp-64h]
  int v80; // [esp+1F8h] [ebp-60h]
  float v81; // [esp+1FCh] [ebp-5Ch]
  float v82; // [esp+200h] [ebp-58h]
  float v83; // [esp+204h] [ebp-54h]
  int v84; // [esp+208h] [ebp-50h]
  float v85; // [esp+20Ch] [ebp-4Ch]
  float v86; // [esp+210h] [ebp-48h]
  float v87; // [esp+214h] [ebp-44h]
  int v88; // [esp+218h] [ebp-40h]
  float v89; // [esp+21Ch] [ebp-3Ch]
  float v90; // [esp+220h] [ebp-38h]
  float v91; // [esp+224h] [ebp-34h]
  int v92; // [esp+228h] [ebp-30h]
  int *v93; // [esp+23Ch] [ebp-1Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+240h] [ebp-18h]
  void *v95; // [esp+244h] [ebp-14h]
  int v96; // [esp+248h] [ebp-10h]
  int v97; // [esp+24Ch] [ebp-Ch]
  void *v98; // [esp+250h] [ebp-8h]
  int v99; // [esp+254h] [ebp-4h] BYREF
  void *retaddr; // [esp+258h] [ebp+0h]

  v97 = a2;
  v98 = retaddr;
  v96 = -1;
  v95 = &loc_AD924B;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v93 = &v99;
  v6 = a4;
  v7 = a3;
  if ( *(_BYTE *)(a1 + 8) )
  {
    v7 = a4;
    v6 = a3;
  }
  v60 = v7[34] - v7[18];
  v61 = v7[33] - v7[17];
  v32 = v7[32] - v7[16];
  v61 = v61 * v61 + v32 * v32 + v60 * v60;
  v8 = v61;
  v61 = v7[65] * v7[65];
  if ( v61 <= v8 )
  {
    sub_982990(v6 + 4, (int)&v77);
    v60 = v7[17];
    v61 = v7[16];
    v9 = v61;
    v10 = v60;
    v11 = v7[18];
    v61 = v87 * v11 + v86 * v60 + v85 * v61;
    v58 = v61 + v91;
    v35 = v58;
    v61 = v81 * v9 + v82 * v60 + v83 * v11;
    v60 = v61 + v90;
    v61 = v10 * v78 + v9 * v77 + v11 * v79;
    v33 = v61 + v89;
    v34 = v60;
    v54 = v7[10];
    v53 = v7[6];
    v52 = v7[14];
    v59 = v85 * v53 + v86 * v54 + v87 * v52;
    v61 = v7[9];
    v58 = v7[5];
    v60 = v7[13];
    v12 = v60;
    v13 = v61;
    v57 = v87 * v60 + v86 * v61 + v85 * v58;
    v60 = v7[8];
    v61 = v7[4];
    v14 = v61;
    v15 = v60;
    v16 = v7[12];
    v55 = v87 * v16 + v86 * v60 + v85 * v61;
    v36 = v81 * v53 + v82 * v54 + v83 * v52;
    v41 = v81 * v58 + v82 * v13 + v83 * v12;
    v39 = v81 * v61 + v82 * v60 + v83 * v16;
    v60 = v77 * v53 + v78 * v54 + v79 * v52;
    v67 = v60;
    v69 = v39;
    v68 = 0;
    v61 = v12 * v79 + v13 * v78 + v77 * v58;
    v70 = v41;
    v71 = v36;
    v72 = 0;
    v73 = v55;
    v74 = v57;
    v75 = v59;
    v76 = 0;
    *(float *)&v64[12] = v33;
    *(float *)&v64[13] = v34;
    v47 = v16 * v79 + v15 * v78 + v14 * v77;
    v65 = v47;
    *(float *)v64 = v47;
    v66 = v61;
    *(float *)&v64[1] = v61;
    v57 = v7[33];
    *(float *)&v64[2] = v60;
    v59 = v7[32];
    v64[3] = 0;
    v55 = v7[34];
    *(float *)&v64[4] = v39;
    v17 = v59;
    *(float *)&v64[5] = v41;
    *(float *)&v64[6] = v36;
    v64[7] = 0;
    *(float *)&v64[8] = v73;
    *(float *)&v64[9] = v74;
    *(float *)&v64[10] = v75;
    v64[11] = 0;
    *(float *)&v64[14] = v35;
    v64[15] = 0;
    v51 = 0.0;
    v59 = v87 * v55 + v86 * v57 + v85 * v59;
    v61 = v59 + v91;
    v50 = v61;
    v59 = v81 * v17 + v82 * v57 + v83 * v55;
    v60 = v59 + v90;
    v59 = v55 * v79 + v57 * v78 + v17 * v77;
    v48 = v59 + v89;
    v49 = v60;
    v52 = v7[26];
    v58 = v7[22];
    v54 = v7[30];
    v56 = v85 * v58 + v86 * v52 + v87 * v54;
    v59 = v7[25];
    v53 = v7[21];
    v57 = v7[29];
    v18 = v59;
    v19 = v57;
    v38 = v87 * v57 + v86 * v59 + v85 * v53;
    v57 = v7[24];
    v59 = v7[20];
    v20 = v57;
    v21 = v7[28];
    v47 = v87 * v21 + v86 * v57 + v85 * v59;
    v40 = v81 * v58 + v82 * v52 + v83 * v54;
    v42 = v81 * v53 + v82 * v18 + v83 * v19;
    v37 = v81 * v59 + v82 * v57 + v83 * v21;
    v55 = v77 * v58 + v78 * v52 + v79 * v54;
    v57 = v19 * v79 + v18 * v78 + v77 * v53;
    v59 = v20 * v78 + v59 * v77 + v79 * v21;
    v67 = v55;
    v65 = v59;
    v77 = v59;
    v66 = v57;
    result = 1.0;
    v78 = v57;
    v79 = v55;
    v69 = v37;
    v68 = 0;
    v80 = 0;
    v81 = v37;
    v70 = v42;
    v82 = v42;
    v71 = v40;
    v83 = v40;
    v72 = 0;
    v84 = 0;
    v73 = v47;
    v85 = v47;
    v74 = v38;
    v86 = v38;
    v75 = v56;
    v87 = v56;
    v76 = 0;
    v88 = 0;
    v89 = v48;
    v90 = v60;
    v91 = v61;
    v92 = 0;
    if ( (unsigned int)(*(_DWORD *)(*((_DWORD *)v6 + 51) + 4) - 21) > 8 )
      return result;
    v23 = v48;
    v45 = v35;
    v43 = v33;
    v44 = v34;
    v46 = 0.0;
    if ( v33 > (double)v48 )
      v43 = v48;
    v24 = v44;
    if ( v44 > (double)v60 )
    {
      v44 = v60;
      v24 = v60;
    }
    v25 = v45;
    if ( v45 > (double)v61 )
    {
      v45 = v61;
      v25 = v61;
    }
    if ( v46 > 0.0 )
      v46 = 0.0;
    v50 = v35;
    v26 = v48 <= (double)v33;
    v48 = v33;
    v49 = v34;
    v51 = 0.0;
    if ( !v26 )
      v48 = v23;
    v27 = v49;
    if ( v60 > (double)v49 )
    {
      v49 = v60;
      v27 = v60;
    }
    v28 = v50;
    if ( v61 > (double)v50 )
    {
      v50 = v61;
      v28 = v61;
    }
    if ( v51 < 0.0 )
      v51 = 0.0;
    v56 = v7[64];
    v43 = v43 - v56;
    v44 = v24 - v56;
    v45 = v25 - v56;
    v48 = v48 + v56;
    v49 = v27 + v56;
    v50 = v56 + v28;
    sub_9974A0(v62, v64, &v77, SLODWORD(v56), COERCE_INT(1.0));
    v29 = *((_DWORD *)v6 + 51);
    v30 = v7[63];
    v96 = 0;
    v63 = v30;
    if ( v29 )
    {
      (*(void (__thiscall **)(int, _DWORD *, float *, float *))(*(_DWORD *)v29 + 56))(v29, v62, &v43, &v48);
      v30 = v63;
    }
    v31 = v7[63];
    v96 = -1;
    v56 = v31;
    if ( v56 > (double)v63 )
    {
      v56 = v63;
      v7[63] = v30;
      sub_98ACB0(v62);
      return v56;
    }
    sub_98ACB0(v62);
  }
  return 1.0;
}
