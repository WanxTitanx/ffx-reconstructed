// Function: sub_8ED380
// Address: 0x8ed380
int __cdecl sub_8ED380(int a1, unsigned int n0xC6, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *v8; // eax
  unsigned int n0xB; // ebx
  unsigned __int8 *v10; // esi
  unsigned int v11; // ecx
  unsigned int v12; // eax
  double v13; // st7
  double v14; // st6
  double v15; // st5
  double v16; // st4
  double v17; // st3
  double v18; // st2
  double v19; // st1
  double v20; // st7
  double v21; // st6
  double v22; // st4
  double v23; // st3
  double v24; // st2
  int v25; // eax
  double v26; // st2
  double v27; // st4
  double v28; // st2
  int v29; // eax
  double v30; // rt1
  double v31; // st3
  double v32; // st3
  double v33; // st2
  double v34; // st4
  double v35; // st2
  double v36; // st2
  int v37; // eax
  double v38; // rtt
  double v39; // st3
  double v40; // rt0
  int v41; // eax
  double v42; // st5
  double v43; // st4
  double v44; // st4
  double v45; // st4
  int v46; // eax
  double v47; // rt1
  double v48; // st4
  double v49; // st4
  int v50; // eax
  double v51; // rt2
  double v52; // st4
  double v53; // st4
  int v54; // ecx
  int v55; // edx
  int v56; // eax
  int v57; // eax
  double v58; // rt1
  double v59; // st5
  double v60; // st6
  double v61; // st7
  double v62; // st6
  double v63; // st5
  double v64; // rt1
  double v65; // st5
  double v66; // st6
  unsigned int v68; // [esp+Ch] [ebp-E8h]
  float v69; // [esp+10h] [ebp-E4h] BYREF
  float v70; // [esp+14h] [ebp-E0h] BYREF
  float v71; // [esp+18h] [ebp-DCh] BYREF
  char *Str; // [esp+1Ch] [ebp-D8h]
  unsigned int *v73; // [esp+20h] [ebp-D4h]
  float v74; // [esp+24h] [ebp-D0h] BYREF
  float v75; // [esp+28h] [ebp-CCh] BYREF
  float v76; // [esp+2Ch] [ebp-C8h] BYREF
  double v77; // [esp+30h] [ebp-C4h]
  float v78; // [esp+38h] [ebp-BCh]
  float v79; // [esp+3Ch] [ebp-B8h] BYREF
  float v80; // [esp+40h] [ebp-B4h] BYREF
  float v81; // [esp+44h] [ebp-B0h] BYREF
  float v82; // [esp+48h] [ebp-ACh]
  float v83; // [esp+4Ch] [ebp-A8h] BYREF
  double v84; // [esp+50h] [ebp-A4h]
  int n503[2]; // [esp+58h] [ebp-9Ch] BYREF
  float v86; // [esp+60h] [ebp-94h]
  float v87; // [esp+64h] [ebp-90h]
  int v88; // [esp+68h] [ebp-8Ch]
  int v89; // [esp+6Ch] [ebp-88h]
  int v90; // [esp+70h] [ebp-84h]
  int v91; // [esp+74h] [ebp-80h]
  float v92; // [esp+78h] [ebp-7Ch]
  float v93; // [esp+7Ch] [ebp-78h]
  float v94; // [esp+80h] [ebp-74h]
  float v95; // [esp+84h] [ebp-70h]
  int v96; // [esp+88h] [ebp-6Ch]
  int v97; // [esp+8Ch] [ebp-68h]
  int v98; // [esp+90h] [ebp-64h]
  int v99; // [esp+94h] [ebp-60h]
  int v100; // [esp+E0h] [ebp-14h]
  int v101; // [esp+E8h] [ebp-Ch]
  int v102; // [esp+ECh] [ebp-8h]

  v101 = 0;
  v102 = 0;
  if ( n0xC6 > 0xC6 )
  {
    v8 = (_DWORD *)HIDWORD(v84);
    Str = (char *)HIDWORD(v84);
  }
  else
  {
    Str = FFX_Menu2D_TexHandleByAtlasId(15872);
    FFX_Menu2D_GetAtlasDimensions_structural(15872, &v69, &v70);
    v8 = (_DWORD *)sub_8FA7D0(n0xC6);
  }
  v73 = v8;
  if ( n0xC6 - 200 <= 0xC6 )
  {
    Str = FFX_Menu2D_TexHandleByAtlasId(15872);
    FFX_Menu2D_GetAtlasDimensions_structural(15872, &v69, &v70);
    v8 = (_DWORD *)sub_8FA7D0(n0xC6 - 200);
    v73 = v8;
  }
  if ( n0xC6 - 400 <= 0xC6 )
  {
    Str = FFX_Menu2D_TexHandleByAtlasId(16128);
    FFX_Menu2D_GetAtlasDimensions_structural(16128, &v69, &v70);
    v8 = (_DWORD *)sub_8FA450(n0xC6 - 400);
    v73 = v8;
  }
  n0xB = n0xC6 - 600;
  if ( n0xC6 - 600 <= 0x31 )
  {
    Str = FFX_Menu2D_TexHandleByAtlasId(15808);
    FFX_Menu2D_GetAtlasDimensions_structural(15808, &v69, &v70);
    v8 = (_DWORD *)sub_8FA790(n0xC6 - 600);
    v73 = v8;
  }
  v10 = (unsigned __int8 *)(v8 + 1);
  v11 = 0;
  v68 = 0;
  *((float *)&v84 + 1) = (float)a5;
  v78 = *((float *)&v84 + 1) * flt_C5D778;
  *((float *)&v84 + 1) = (float)a6;
  v12 = *v8;
  v82 = *((float *)&v84 + 1) * flt_C5D77C;
  if ( v12 )
  {
    v13 = 8.0;
    v14 = 0.699999988079071;
    v15 = 0.8;
    v16 = 2.0;
    v17 = 1.0;
    v18 = v78;
    v19 = v82;
    while ( n0xC6 == 62 && v11 < v12 - 1 )
    {
LABEL_109:
      ++v11;
      v12 = *v73;
      v10 += 12;
      v68 = v11;
      if ( v11 >= *v73 )
        return a1;
    }
    if ( !a5 )
    {
      HIDWORD(v84) = *((unsigned __int16 *)v10 + 2);
      v84 = (double)SHIDWORD(v84);
      v78 = v84 * flt_C5D778;
      v18 = v78;
      v19 = v82;
    }
    if ( !a6 )
    {
      HIDWORD(v84) = *((unsigned __int16 *)v10 + 3);
      v84 = (double)SHIDWORD(v84);
      v82 = v84 * flt_C5D77C;
      v19 = v82;
    }
    if ( n0xB > 0xB )
    {
      v20 = v17;
      v21 = v16;
      v22 = v78;
      v24 = 10.0;
      v23 = v82;
    }
    else if ( unk_18716A8 )
    {
      v20 = v17;
      v78 = v18 * 0.6;
      v21 = v16;
      v82 = v19 * 0.9;
      v22 = v78;
      v23 = v82;
      v24 = 10.0;
    }
    else
    {
      v78 = v13 * v18 / 10.0 * v14;
      v82 = v14 * v19;
      v20 = v17;
      v21 = v16;
      v23 = v82;
      v24 = 10.0;
      v22 = v78;
    }
    if ( n0xC6 - 480 <= 9 )
    {
      v82 = v23 * v24 * 0.125;
      v23 = v82;
    }
    v25 = (char)v10[2];
    if ( *((_WORD *)v10 + 4) == 1 )
    {
      if ( n0xB <= 0xB )
      {
        v84 = (double)v25;
        if ( unk_18716A8 )
        {
          v26 = v84 * v15;
          v84 = (double)a3;
          v80 = v22 + v26 + v84;
          v27 = v23;
          v81 = v26 + v84;
        }
        else
        {
          v28 = v84 * 0.5600000023841858;
          *((float *)&v84 + 1) = (float)a3;
          v80 = v22 + v28 + *((float *)&v84 + 1);
          v27 = v23;
          v81 = v28 + *((float *)&v84 + 1);
        }
LABEL_44:
        v41 = (char)v10[3];
        if ( *((_WORD *)v10 + 5) == 1 )
        {
          if ( n0xB > 0xB )
          {
            v46 = a4 + v41;
            if ( !unk_18716A8 )
            {
              v42 = v27;
              *((float *)&v84 + 1) = (float)v46;
              v44 = *((float *)&v84 + 1);
              v79 = *((float *)&v84 + 1) + v42;
              goto LABEL_69;
            }
            HIDWORD(v84) = v46;
            v77 = (double)v46;
            v47 = v27;
            v48 = v15 * v27 + v77;
            v42 = v47;
            v79 = v48;
            v83 = v77;
            if ( unk_18716AC )
            {
              v44 = v83 + 4.0;
              goto LABEL_69;
            }
LABEL_70:
            v53 = 3.0;
            goto LABEL_71;
          }
          v42 = v27;
          if ( !unk_18716A8 )
          {
            v77 = (double)v41;
            *((float *)&v84 + 1) = (float)a4;
            v45 = v77 * 0.699999988079071 + *((float *)&v84 + 1);
            v79 = v42 + v45;
            v83 = v45;
            goto LABEL_70;
          }
          *((float *)&v84 + 1) = (float)(a4 + v41);
          v43 = *((float *)&v84 + 1);
          v79 = *((float *)&v84 + 1) + v42;
        }
        else
        {
          if ( n0xB > 0xB )
          {
            v50 = a4 + v41;
            if ( !unk_18716A8 )
            {
              v42 = v27;
              *((float *)&v84 + 1) = (float)v50;
              v79 = *((float *)&v84 + 1);
              v44 = *((float *)&v84 + 1) + v27;
              goto LABEL_69;
            }
            HIDWORD(v84) = v50;
            v79 = (float)v50;
            v77 = (double)v50;
            v51 = v27;
            v52 = v15 * v27 + v77;
            v42 = v51;
            v83 = v52;
            if ( unk_18716AC )
            {
              if ( n0xC6 == 604 || n0xC6 == 605 )
              {
                v79 = v79 + v21;
              }
              else if ( n0xC6 != 609 && n0xC6 != 610 )
              {
                v53 = 3.0;
                v83 = v83 + 3.0;
LABEL_71:
                if ( n0xB <= 0xB )
                {
                  v80 = v80 + v53;
                  v81 = v53 + v81;
                  v79 = v79 + 1.200000047683716;
                  v83 = v83 + 1.200000047683716;
                }
                v54 = *v10;
                v55 = v10[1];
                v56 = *((unsigned __int16 *)v10 + 2);
                HIDWORD(v84) = v55;
                v74 = (float)v54;
                v71 = (float)v55;
                if ( a5 )
                  --v56;
                HIDWORD(v84) = v54 + v56;
                v75 = (float)(v54 + v56);
                v57 = *((unsigned __int16 *)v10 + 3);
                if ( a6 )
                  --v57;
                HIDWORD(v84) = v55 + v57;
                v76 = (float)(v55 + v57);
                if ( n0xC6 - 479 > 0xA )
                {
                  v60 = v42;
                }
                else
                {
                  if ( v42 <= 10.0 )
                  {
                    v60 = v42;
                  }
                  else
                  {
                    if ( (char)v10[2] <= 4 )
                    {
                      v60 = v42;
                      v80 = v80 + v20;
                      v59 = v81 + v20;
                    }
                    else
                    {
                      v80 = v80 - v21;
                      v58 = v42;
                      v59 = v81 - v21;
                      v60 = v58;
                    }
                    v81 = v59;
                  }
                  v74 = v74 - v20;
                  v75 = v75 - v20;
                  v71 = v71 - v20;
                  v76 = v76 - v20;
                }
                if ( n0xC6 - 490 <= 9 )
                {
                  if ( 8.0 == v76 )
                  {
                    v76 = v76 - v20;
                    v82 = v60 - v20;
                    v60 = v82;
                  }
                  HIDWORD(v84) = (char)v10[3];
                  v74 = v74 - v20;
                  v75 = v75 - v20;
                  v82 = v60 * 1.444399952888489;
                  v77 = (double)SHIDWORD(v84);
                  *((float *)&v84 + 1) = (float)a4;
                  v79 = 1.444399952888489 * v77 + *((float *)&v84 + 1);
                  v83 = v79 + v82;
                }
                if ( sub_8E5A20(&v80, &v79, &v81, &v83, &v74, &v71, &v75, &v76) )
                {
                  *(float *)n503 = v80;
                  v88 = (unsigned __int8)a7;
                  *(float *)&n503[1] = v79;
                  v89 = BYTE1(a7);
                  v90 = BYTE2(a7);
                  v91 = HIBYTE(a7);
                  v96 = (unsigned __int8)a8;
                  v97 = BYTE1(a8);
                  v98 = BYTE2(a8);
                  v99 = HIBYTE(a8);
                  v100 = 0;
                  v86 = v74 / v69;
                  v87 = v71 / v70;
                  v92 = v81;
                  v93 = v83;
                  v94 = v75 / v69;
                  v95 = v76 / v70;
                  if ( 0.0 == v86 )
                  {
                    v61 = 0.0;
                    v62 = 0.0099999998;
                    v86 = 0.0099999998;
                    v63 = (float)0.0099999998;
                  }
                  else
                  {
                    v62 = 0.0099999998;
                    v63 = v86;
                    v61 = 0.0;
                  }
                  if ( v94 == v61 )
                  {
                    v64 = v63;
                    v65 = v62;
                    v66 = v64;
                    v94 = v65;
                  }
                  else
                  {
                    v66 = v63;
                  }
                  if ( n0xC6 == 62 )
                  {
                    sub_8E8A10((int)n503, 62);
                  }
                  else
                  {
                    if ( n0xC6 == 609 || n0xC6 == 610 )
                      v95 = v95 - 0.001953125;
                    if ( n0xC6 == 608 )
                    {
                      v86 = v61;
                    }
                    else if ( n0xC6 == 218 || n0xC6 == 216 )
                    {
                      v86 = v66 + 0.0009765625;
                    }
                  }
                  sub_63F090((int)n503, Str, 1, 0, 0.0);
                }
                v11 = v68;
                v13 = 8.0;
                v14 = 0.699999988079071;
                v15 = 0.8;
                v17 = 1.0;
                v16 = 2.0;
                v19 = v82;
                v18 = v78;
                goto LABEL_109;
              }
              v44 = v83 + 8.0;
              goto LABEL_69;
            }
            goto LABEL_70;
          }
          v42 = v27;
          if ( !unk_18716A8 )
          {
            v77 = (double)v41;
            *((float *)&v84 + 1) = (float)a4;
            v49 = v77 * 0.699999988079071 + *((float *)&v84 + 1);
            v79 = v49;
            v44 = v49 + v42;
            goto LABEL_69;
          }
          *((float *)&v84 + 1) = (float)(a4 + v41);
          v79 = *((float *)&v84 + 1);
          v43 = *((float *)&v84 + 1) + v27;
        }
        v83 = v43;
        if ( unk_18716AC )
        {
          v44 = v83 - v20;
LABEL_69:
          v83 = v44;
          goto LABEL_70;
        }
        goto LABEL_70;
      }
      v29 = a3 + v25;
      if ( unk_18716A8 )
      {
        HIDWORD(v84) = v29;
        v30 = v23;
        v31 = v22;
        v27 = v30;
        v77 = (double)v29;
        v80 = v31 * v15 + v77;
        v32 = v77;
LABEL_43:
        v81 = v32;
        goto LABEL_44;
      }
      *((float *)&v84 + 1) = (float)v29;
      v33 = v22 + *((float *)&v84 + 1);
      v34 = *((float *)&v84 + 1);
      v80 = v33;
    }
    else if ( n0xB > 0xB )
    {
      v37 = a3 + v25;
      if ( unk_18716A8 )
      {
        HIDWORD(v84) = v37;
        v80 = (float)v37;
        v38 = v23;
        v39 = v22;
        v27 = v38;
        v77 = (double)v37;
        v81 = v39 * v15 + v77;
        if ( !unk_18716AC )
          goto LABEL_44;
        v32 = v81 + v21;
        goto LABEL_43;
      }
      *((float *)&v84 + 1) = (float)v37;
      v80 = *((float *)&v84 + 1);
      v34 = v22 + *((float *)&v84 + 1);
    }
    else
    {
      if ( unk_18716A8 )
      {
        HIDWORD(v84) = (char)v10[2];
        v77 = (double)v25;
        v35 = v77 * v15;
        v77 = (double)a3;
        v36 = v35 + v77;
      }
      else
      {
        v77 = (double)v25;
        *((float *)&v84 + 1) = (float)a3;
        v36 = v77 * 0.5600000023841858 + *((float *)&v84 + 1);
      }
      v80 = v36;
      v34 = v22 + v36;
    }
    v40 = v23;
    v32 = v34;
    v27 = v40;
    goto LABEL_43;
  }
  return a1;
}
