// Function: sub_89E5D0
// Address: 0x89e5d0
int __cdecl sub_89E5D0(int n463, float a2, int a3, float a4, float a5)
{
  double v6; // st7
  double v7; // st5
  double v8; // st7
  double v9; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st6
  double v15; // st7
  float v16; // [esp+0h] [ebp-2Ch]
  float v17; // [esp+0h] [ebp-2Ch]
  float v18; // [esp+4h] [ebp-28h]
  int v19; // [esp+4h] [ebp-28h]
  float v20; // [esp+4h] [ebp-28h]
  int v21; // [esp+4h] [ebp-28h]
  float v22; // [esp+8h] [ebp-24h]
  float v23; // [esp+8h] [ebp-24h]
  float v24; // [esp+8h] [ebp-24h]
  float v25; // [esp+8h] [ebp-24h]
  float v26; // [esp+Ch] [ebp-20h]
  float v27; // [esp+Ch] [ebp-20h]
  float v28; // [esp+Ch] [ebp-20h]
  float v29; // [esp+Ch] [ebp-20h]
  int v30; // [esp+10h] [ebp-1Ch]
  int v31; // [esp+10h] [ebp-1Ch]
  float v32; // [esp+14h] [ebp-18h]
  int v33; // [esp+14h] [ebp-18h]
  float v34; // [esp+18h] [ebp-14h]
  int v35; // [esp+18h] [ebp-14h]
  float v36; // [esp+1Ch] [ebp-10h]
  int v37; // [esp+1Ch] [ebp-10h]
  float v38; // [esp+28h] [ebp-4h]
  float v39; // [esp+28h] [ebp-4h]
  float v40; // [esp+28h] [ebp-4h]
  float v41; // [esp+28h] [ebp-4h]
  float v42; // [esp+28h] [ebp-4h]
  float v43; // [esp+28h] [ebp-4h]
  float v44; // [esp+34h] [ebp+8h]
  float v45; // [esp+34h] [ebp+8h]
  float v46; // [esp+34h] [ebp+8h]
  float v47; // [esp+34h] [ebp+8h]
  float v48; // [esp+34h] [ebp+8h]
  float v49; // [esp+34h] [ebp+8h]
  float v50; // [esp+34h] [ebp+8h]
  float v51; // [esp+34h] [ebp+8h]
  float v52; // [esp+34h] [ebp+8h]
  float v53; // [esp+34h] [ebp+8h]
  float v54; // [esp+34h] [ebp+8h]
  float v55; // [esp+34h] [ebp+8h]
  float v56; // [esp+34h] [ebp+8h]
  float v57; // [esp+34h] [ebp+8h]
  int v58; // [esp+34h] [ebp+8h]
  float v59; // [esp+34h] [ebp+8h]
  float v60; // [esp+34h] [ebp+8h]
  float v61; // [esp+34h] [ebp+8h]
  float v62; // [esp+34h] [ebp+8h]
  float v63; // [esp+34h] [ebp+8h]
  int v64; // [esp+34h] [ebp+8h]
  float v65; // [esp+34h] [ebp+8h]
  float v66; // [esp+34h] [ebp+8h]
  float v67; // [esp+34h] [ebp+8h]
  int v68; // [esp+34h] [ebp+8h]
  float v69; // [esp+34h] [ebp+8h]
  float v70; // [esp+34h] [ebp+8h]
  float v71; // [esp+34h] [ebp+8h]

  sub_8B1300(-1, n463);
  if ( (unsigned int)(n463 - 440) <= 0xA )
  {
    v44 = (float)(n463 % 2);
    v45 = v44 * 129.0 + 768.0;
    v38 = (float)((n463 - 440) / 2);
    v39 = v38 * 96.0;
    v6 = v39;
    v40 = v39 + 80.0;
    v41 = v40 * 0.0009765625;
    v36 = v41;
    v7 = v45;
    v46 = v45 + 120.0;
    v47 = v46 * 0.0009765625;
    v34 = v47;
    v48 = v6 * 0.0009765625;
    v32 = v48;
    v49 = v7 * 0.0009765625;
    v8 = v49;
LABEL_3:
    *(float *)&v30 = v8;
    v26 = a5;
    v22 = a4;
    v18 = *(float *)&a3;
    v9 = a2;
LABEL_4:
    v16 = v9;
    return FFX_Menu2D_DrawTexQuadSolid(
             0x190u,
             v16,
             SLODWORD(v18),
             v22,
             v26,
             v30,
             SLODWORD(v32),
             SLODWORD(v34),
             SLODWORD(v36));
  }
  if ( (unsigned int)(n463 - 451) <= 7 )
  {
    FFX_Menu2D_DrawTexQuadSolid(
      0x190u,
      a2,
      a3,
      a4,
      a5,
      COERCE_INT(0.87597656),
      COERCE_INT(0.46875),
      COERCE_INT(0.99316406),
      COERCE_INT(0.546875));
    v50 = (float)(n463 - 451);
    v51 = (v50 * 31.0 + 769.0) * 0.0009765625;
    v36 = 0.85546875;
    v11 = v51;
    v52 = v51 + 0.029296875;
    v34 = v52;
    v32 = 0.81054688;
    *(float *)&v30 = v11;
    v53 = 0.6000000238418579 * a5;
    v26 = v53;
    v54 = 0.4000000059604645 * a4;
    v22 = v54;
    v55 = a5 * 0.2000000029802322 + *(float *)&a3;
    v18 = v55;
    v56 = a4 * 0.300000011920929 + a2;
    v9 = v56;
    goto LABEL_4;
  }
  if ( (unsigned int)(n463 - 459) <= 7 )
  {
    FFX_Menu2D_DrawTexQuadSolid(
      0x190u,
      a2,
      a3,
      a4,
      a5,
      COERCE_INT(0.75),
      COERCE_INT(0.5625),
      COERCE_INT(0.8671875),
      COERCE_INT(0.640625));
    v57 = (float)((n463 - 459) % 4);
    *(float *)&v58 = (v57 * 60.0 + 769.0) * 0.0009765625;
    if ( n463 == 463 )
    {
      *(float *)&v58 = *(float *)&v58 + 0.0009765625;
    }
    else if ( n463 < 463 )
    {
      v12 = 0.87304688;
      goto LABEL_11;
    }
    v12 = 0.93164062;
LABEL_11:
    v42 = v12;
    v13 = v42;
    v43 = v42 + 0.048828125;
    v36 = v43;
    v14 = *(float *)&v58;
    v59 = *(float *)&v58 + 0.0458984375;
    v34 = v59;
    v32 = v13;
    *(float *)&v30 = v14;
    v60 = 0.4000000059604645 * a5;
    v26 = v60;
    v61 = 0.2879999876022339 * a4;
    v22 = v61;
    v62 = a5 * 0.550000011920929 + *(float *)&a3;
    v18 = v62;
    v63 = a4 * 0.5199999809265137 + a2;
    v9 = v63;
    goto LABEL_4;
  }
  switch ( n463 )
  {
    case 467:
      v36 = 0.640625;
      v34 = 0.99316406;
      v32 = 0.5625;
      v8 = 0.87597656;
      goto LABEL_3;
    case 468:
      v36 = 0.734375;
      v34 = 0.8671875;
      v32 = 0.65625;
      v8 = 0.75;
      goto LABEL_3;
    case 438:
      v27 = FFX_Menu2D_ScaleY_1080to416(15.0);
      v23 = FFX_Menu2D_ScaleX_1920to512(14.0);
      *(float *)&v64 = *(float *)&a3 - 11.0;
      v19 = v64;
      v65 = FFX_Menu2D_ScaleX_1920to512(11.0) + a2 - 1.0;
      FFX_Menu2D_DrawTexQuadSolid(
        0x190u,
        v65,
        v19,
        v23,
        v27,
        COERCE_INT(0.71679688),
        COERCE_INT(0.94042969),
        COERCE_INT(0.75195312),
        COERCE_INT(0.97949219));
      *(float *)&v37 = 0.71972656;
      *(float *)&v35 = 0.73925781;
      *(float *)&v33 = 0.69238281;
      *(float *)&v31 = 0.68554688;
      v28 = FFX_Menu2D_ScaleY_1080to416(12.0);
      v24 = FFX_Menu2D_ScaleX_1920to512(24.0);
      v66 = *(float *)&a3 - FFX_Menu2D_ScaleY_1080to416(38.0) - 3.0;
      v20 = v66;
      v67 = FFX_Menu2D_ScaleX_1920to512(11.0) + a2;
      v15 = v67;
LABEL_22:
      v17 = v15;
      FFX_Menu2D_DrawTexQuadSolid(0x190u, v17, SLODWORD(v20), v24, v28, v31, v33, v35, v37);
      return sub_8B12E0();
    case 439:
      v29 = FFX_Menu2D_ScaleY_1080to416(15.0);
      v25 = FFX_Menu2D_ScaleX_1920to512(14.0);
      *(float *)&v68 = *(float *)&a3 - 2.0;
      v21 = v68;
      v69 = FFX_Menu2D_ScaleX_1920to512(11.0) + a2 - 1.0;
      FFX_Menu2D_DrawTexQuadSolid(
        0x190u,
        v69,
        v21,
        v25,
        v29,
        COERCE_INT(0.71679688),
        COERCE_INT(0.94042969),
        COERCE_INT(0.75195312),
        COERCE_INT(0.97949219));
      *(float *)&v37 = 0.87109375;
      *(float *)&v35 = 0.73925781;
      *(float *)&v33 = 0.84277344;
      *(float *)&v31 = 0.68554688;
      v28 = FFX_Menu2D_ScaleY_1080to416(12.0);
      v24 = FFX_Menu2D_ScaleX_1920to512(24.0);
      v70 = FFX_Menu2D_ScaleY_1080to416(26.0) + *(float *)&a3 + 2.0;
      v20 = v70;
      v71 = FFX_Menu2D_ScaleX_1920to512(11.0) + a2;
      v15 = v71;
      goto LABEL_22;
  }
  return sub_8B12E0();
}
