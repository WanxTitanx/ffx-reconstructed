// Function: sub_A2EF70
// Address: 0xa2ef70
// Size: 0x5ea
// Prototype: 

double __cdecl sub_A2EF70(float *a1, float *a2, int a3, _BYTE *a4, float a5)
{
  double v5; // st7
  float *v6; // eax
  float v7; // ecx
  unsigned __int8 v8; // dl
  unsigned int v9; // eax
  float v10; // esi
  double v11; // st7
  double v12; // st6
  float *v13; // edx
  double v14; // st5
  double v15; // st4
  double v16; // st3
  char v17; // cl
  double v18; // st2
  double v19; // st2
  double v20; // st2
  float *v21; // ecx
  double v22; // st6
  double v23; // st5
  double v24; // st4
  double v25; // st3
  double v26; // rt0
  double v27; // st3
  double v28; // st7
  double v29; // st3
  double v30; // st6
  float *v31; // eax
  float *v32; // eax
  double v33; // st7
  double v34; // st7
  _BYTE *v35; // ecx
  double v36; // st6
  _BYTE *v37; // eax
  _BYTE *v38; // eax
  _BYTE *v39; // eax
  _BYTE *v40; // eax
  _BYTE *v41; // eax
  _BYTE *v42; // eax
  double v43; // st7
  double v44; // st7
  float v46[4]; // [esp+4h] [ebp-2B8h] BYREF
  float v47[4]; // [esp+14h] [ebp-2A8h] BYREF
  float v48[4]; // [esp+24h] [ebp-298h] BYREF
  float v49; // [esp+34h] [ebp-288h]
  float v50; // [esp+38h] [ebp-284h]
  float v51; // [esp+3Ch] [ebp-280h]
  float v52; // [esp+40h] [ebp-27Ch]
  float v53; // [esp+44h] [ebp-278h]
  float v54; // [esp+48h] [ebp-274h]
  float v55; // [esp+4Ch] [ebp-270h]
  float v56; // [esp+50h] [ebp-26Ch]
  float v57; // [esp+54h] [ebp-268h]
  float v58; // [esp+58h] [ebp-264h]
  float v59; // [esp+5Ch] [ebp-260h]
  float v60; // [esp+60h] [ebp-25Ch]
  float v61; // [esp+64h] [ebp-258h]
  float v62; // [esp+68h] [ebp-254h]
  float v63; // [esp+6Ch] [ebp-250h]
  float v64; // [esp+70h] [ebp-24Ch] BYREF
  float v65; // [esp+74h] [ebp-248h]
  float v66; // [esp+78h] [ebp-244h]
  float v67; // [esp+7Ch] [ebp-240h]
  float v68; // [esp+80h] [ebp-23Ch] BYREF
  float v69; // [esp+84h] [ebp-238h]
  float v70; // [esp+88h] [ebp-234h]
  float v71; // [esp+8Ch] [ebp-230h]
  float v72; // [esp+90h] [ebp-22Ch]
  unsigned int v73; // [esp+94h] [ebp-228h]
  float v74; // [esp+98h] [ebp-224h]
  float v75; // [esp+9Ch] [ebp-220h]
  float v76; // [esp+A0h] [ebp-21Ch] BYREF
  float v77; // [esp+A4h] [ebp-218h]
  float v78; // [esp+A8h] [ebp-214h]
  float v79; // [esp+ACh] [ebp-210h]
  float v80; // [esp+B0h] [ebp-20Ch]
  _BYTE *v81; // [esp+B4h] [ebp-208h]
  float v82; // [esp+B8h] [ebp-204h] BYREF
  float v83; // [esp+BCh] [ebp-200h]
  float v84; // [esp+C0h] [ebp-1FCh]
  float v85; // [esp+C4h] [ebp-1F8h]
  float v86; // [esp+C8h] [ebp-1F4h]
  float v87; // [esp+CCh] [ebp-1F0h]
  char v88; // [esp+D3h] [ebp-1E9h]
  float v89; // [esp+D4h] [ebp-1E8h] BYREF
  _BYTE v90[192]; // [esp+D8h] [ebp-1E4h] BYREF
  _BYTE v91[192]; // [esp+198h] [ebp-124h] BYREF
  _BYTE v92[8]; // [esp+258h] [ebp-64h] BYREF
  _BYTE v93[88]; // [esp+260h] [ebp-5Ch] BYREF

  v89 = 1.0;
  v5 = 0.0;
  v81 = a4;
  v86 = a5;
  v6 = *(float **)(a3 + 176);
  if ( v6 )
  {
    v82 = v6[8];
    v83 = v6[9];
    v84 = v6[10];
    v76 = v82;
    v77 = v83;
    v5 = v84;
  }
  else
  {
    v76 = 0.0;
    v77 = 0.0;
  }
  v78 = v5;
  v82 = v76;
  v83 = v77;
  v84 = v78;
  v85 = v79;
  if ( !(unsigned __int8)sub_A2FC90(&v82, a1, a2) )
  {
    sub_4C9FD0(&v76, &v82);
    LODWORD(v86) = (char *)&unk_B79C20 + 8 * sub_5A4310(a1, a2, &v76);
    sub_4CA480(v48, a3 + 112, v81);
    v7 = v86;
    v8 = *(_BYTE *)LODWORD(v86);
    if ( *(_BYTE *)LODWORD(v86) )
    {
      v64 = 3.4028235e38;
      v88 = 0;
      v65 = 3.4028235e38;
      v9 = 0;
      v66 = 3.4028235e38;
      v73 = 0;
      v67 = 3.4028235e38;
      LODWORD(v10) = v8;
      v68 = -3.4028235e38;
      v69 = -3.4028235e38;
      v70 = -3.4028235e38;
      v71 = -3.4028235e38;
      v11 = 1.0;
      v12 = v60;
      v13 = (float *)v93;
      v14 = v53;
      v81 = v93;
      v15 = v49;
      v16 = v48[0];
      do
      {
        v17 = *(_BYTE *)(LODWORD(v7) + v9 + 1);
        if ( (v17 & 1) != 0 )
          v18 = *a2;
        else
          v18 = *a1;
        v74 = v18;
        v76 = v74;
        if ( (v17 & 2) != 0 )
          v19 = a2[1];
        else
          v19 = a1[1];
        v75 = v19;
        v77 = v75;
        if ( (v17 & 4) != 0 )
          v20 = a2[2];
        else
          v20 = a1[2];
        v72 = v20;
        v78 = v72;
        v21 = v13 - 2;
        v87 = *(float *)&v21;
        v82 = v14 * v72 + v16 * v76 + v15 * v77 + v57;
        v83 = v50 * v77 + v48[1] * v76 + v54 * v72 + v58;
        v84 = v51 * v77 + v48[2] * v76 + v55 * v72 + v59;
        v85 = v12 + v72 * v56 + v76 * v48[3] + v77 * v52;
        v22 = v82;
        *v21 = v82;
        v23 = v83;
        *(v13 - 1) = v83;
        v24 = v84;
        *v13 = v84;
        v25 = v85;
        v13[1] = v85;
        v26 = v25;
        v27 = v11 / v25;
        v28 = v26;
        v80 = v27;
        if ( v80 < 0.0000099999997 )
          v88 = 1;
        v29 = v22 * v80;
        v30 = v80;
        v80 = v29;
        v62 = v23 * v30;
        v61 = v24 * v30;
        v63 = v28 * v30;
        *v21 = v80;
        *(v13 - 1) = v62;
        *v13 = v61;
        v13[1] = v63;
        v31 = sub_A1B620(v46, &v64, v13 - 2);
        v64 = *v31;
        v65 = v31[1];
        v66 = v31[2];
        v67 = v31[3];
        v32 = sub_A1B560(v47, &v68, (float *)LODWORD(v87));
        v7 = v86;
        v68 = *v32;
        v13 = (float *)(v81 + 16);
        v69 = v32[1];
        v33 = v32[2];
        v81 += 16;
        v70 = v33;
        v71 = v32[3];
        v9 = v73 + 1;
        v11 = 1.0;
        v73 = v9;
        v12 = v60;
        v14 = v53;
        v15 = v49;
        v16 = v48[0];
      }
      while ( v9 < LODWORD(v10) );
      if ( !v88 )
      {
        v34 = 1.0;
        v89 = v10;
        v35 = v92;
        v87 = v68 - 1.0;
        v36 = 0.0;
        if ( v87 > 0.0 )
        {
          v37 = (_BYTE *)sub_A2F5E0(v92, LODWORD(v10), v91, &v89, sub_A2F780);
          v34 = 1.0;
          v10 = v89;
          v36 = 0.0;
          v35 = v37;
        }
        v87 = v69 - v34;
        if ( v87 > v36 )
        {
          v38 = (_BYTE *)sub_A2F5E0(v35, LODWORD(v10), v90, &v89, sub_A2F7A0);
          v34 = 1.0;
          v10 = v89;
          v36 = 0.0;
          v35 = v38;
        }
        v87 = -(v64 + v34);
        if ( v87 > v36 )
        {
          v39 = v90;
          if ( v35 != v91 )
            v39 = v91;
          v40 = (_BYTE *)sub_A2F5E0(v35, LODWORD(v10), v39, &v89, sub_A2F740);
          v34 = 1.0;
          v10 = v89;
          v36 = 0.0;
          v35 = v40;
        }
        v87 = -(v34 + v65);
        if ( v36 < v87 )
        {
          v41 = v90;
          if ( v35 != v91 )
            v41 = v91;
          v42 = (_BYTE *)sub_A2F5E0(v35, LODWORD(v10), v41, &v89, sub_A2F760);
          v10 = v89;
          v35 = v42;
        }
        v87 = sub_5A3C80(v35, LODWORD(v10)) * 0.5 * 0.25;
        v43 = v87;
        if ( v87 >= 1.0 )
          v43 = 1.0;
        v86 = v43;
        v44 = v86;
        if ( v86 < 0.0 )
          return (float)0.0;
        return (float)v44;
      }
    }
  }
  return v89;
}

