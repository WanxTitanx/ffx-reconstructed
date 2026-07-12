// Function: sub_8F9C20
// Address: 0x8f9c20
int __cdecl sub_8F9C20(float n4e_5, int a2, float n4c_3, float n4b_4, int n4)
{
  double n4b_3; // st7
  double n4c_2; // st6
  double n4d_2; // st5
  double n4e_4; // st4
  double v10; // st3
  double v11; // st2
  double n4e_1; // st7
  double n4e_3; // rtt
  double n4b_2; // st4
  float n4e_2; // [esp+0h] [ebp-3Ch]
  float n4d_1; // [esp+4h] [ebp-38h]
  int n4p_1; // [esp+4h] [ebp-38h]
  int v19; // [esp+4h] [ebp-38h]
  int v20; // [esp+4h] [ebp-38h]
  float n4c_1; // [esp+8h] [ebp-34h]
  float n4o_1; // [esp+8h] [ebp-34h]
  float v23; // [esp+8h] [ebp-34h]
  float n4r_1; // [esp+8h] [ebp-34h]
  float v25; // [esp+8h] [ebp-34h]
  float v26; // [esp+8h] [ebp-34h]
  float v27; // [esp+8h] [ebp-34h]
  float v28; // [esp+8h] [ebp-34h]
  float v29; // [esp+8h] [ebp-34h]
  float v30; // [esp+8h] [ebp-34h]
  float v31; // [esp+Ch] [ebp-30h]
  float n4b_1; // [esp+Ch] [ebp-30h]
  float n4n_1; // [esp+Ch] [ebp-30h]
  float v34; // [esp+Ch] [ebp-30h]
  float v35; // [esp+Ch] [ebp-30h]
  float v36; // [esp+Ch] [ebp-30h]
  float n4u_1; // [esp+Ch] [ebp-30h]
  float v38; // [esp+Ch] [ebp-30h]
  float v39; // [esp+Ch] [ebp-30h]
  float v40; // [esp+Ch] [ebp-30h]
  float v41; // [esp+Ch] [ebp-30h]
  int v42; // [esp+10h] [ebp-2Ch]
  int v43; // [esp+14h] [ebp-28h]
  int v44; // [esp+14h] [ebp-28h]
  int v45; // [esp+18h] [ebp-24h]
  int v46; // [esp+1Ch] [ebp-20h]
  double v47; // [esp+2Ch] [ebp-10h]
  double v48; // [esp+34h] [ebp-8h]
  float v49; // [esp+44h] [ebp+8h]
  float v50; // [esp+44h] [ebp+8h]
  int v51; // [esp+44h] [ebp+8h]
  float v52; // [esp+44h] [ebp+8h]
  int v53; // [esp+44h] [ebp+8h]
  float v54; // [esp+44h] [ebp+8h]
  float v55; // [esp+4Ch] [ebp+10h]
  int v56; // [esp+4Ch] [ebp+10h]
  int n4a; // [esp+54h] [ebp+18h]
  float n4b; // [esp+54h] [ebp+18h]
  float n4c; // [esp+54h] [ebp+18h]
  float n4d; // [esp+54h] [ebp+18h]
  float n4e; // [esp+54h] [ebp+18h]
  float n4f; // [esp+54h] [ebp+18h]
  float n4g; // [esp+54h] [ebp+18h]
  float n4h; // [esp+54h] [ebp+18h]
  float n4i; // [esp+54h] [ebp+18h]
  float n4j; // [esp+54h] [ebp+18h]
  float n4k; // [esp+54h] [ebp+18h]
  float n4l; // [esp+54h] [ebp+18h]
  float n4m; // [esp+54h] [ebp+18h]
  float n4n; // [esp+54h] [ebp+18h]
  float n4o; // [esp+54h] [ebp+18h]
  int n4p; // [esp+54h] [ebp+18h]
  float n4q; // [esp+54h] [ebp+18h]
  float n4r; // [esp+54h] [ebp+18h]
  float n4s; // [esp+54h] [ebp+18h]
  float n4t; // [esp+54h] [ebp+18h]
  float n4u; // [esp+54h] [ebp+18h]
  int n4v; // [esp+54h] [ebp+18h]
  int n4w; // [esp+54h] [ebp+18h]

  n4b_3 = n4b_4;
  n4c_2 = n4c_3;
  n4d_2 = *(float *)&a2;
  n4e_4 = n4e_5;
  v10 = 0.390625;
  v11 = 0.0;
  if ( n4 && n4 != 4 && n4 != 5 )
  {
    v31 = FFX_Menu2D_ScaleY_1080to416(30.0);
    *(float *)&n4a = *(float *)&a2 + n4b_4;
    FFX_Menu2D_DrawTexQuadSolid(
      0xC8u,
      n4e_5,
      n4a,
      n4c_3,
      v31,
      COERCE_INT(0.0),
      COERCE_INT(0.390625),
      COERCE_INT(0.19433594),
      COERCE_INT(0.41992188));
    v10 = 0.390625;
    n4b_3 = n4b_4;
    n4c_2 = n4c_3;
    n4e_4 = n4e_5;
    v11 = 0.0;
    n4d_2 = *(float *)&a2;
  }
  switch ( n4 )
  {
    case 1:
      *(float *)&v46 = v10;
      *(float *)&v45 = 0.46191406;
      *(float *)&v43 = 0.32910156;
      *(float *)&v42 = 0.45410156;
      n4b = n4b_3 - FFX_Menu2D_ScaleY_1080to416(6.0);
      n4b_1 = n4b;
      n4c = n4c_3 - FFX_Menu2D_ScaleX_1920to512(6.0);
      n4c_1 = n4c;
      n4d = FFX_Menu2D_ScaleY_1080to416(3.0) + *(float *)&a2;
      n4d_1 = n4d;
      n4e = FFX_Menu2D_ScaleX_1920to512(3.0) + n4e_5;
      n4e_1 = n4e;
LABEL_7:
      n4e_2 = n4e_1;
      FFX_Menu2D_DrawTexQuadSolid(0xC8u, n4e_2, SLODWORD(n4d_1), n4c_1, n4b_1, v42, v43, v45, v46);
      break;
    case 2:
      *(float *)&v46 = 0.39160156;
      *(float *)&v45 = 0.44921875;
      *(float *)&v43 = 0.32910156;
      *(float *)&v42 = 0.43945312;
      n4f = n4b_3 - FFX_Menu2D_ScaleY_1080to416(6.0);
      n4b_1 = n4f;
      n4g = n4c_3 - FFX_Menu2D_ScaleX_1920to512(6.0);
      n4c_1 = n4g;
      n4h = FFX_Menu2D_ScaleY_1080to416(3.0) + *(float *)&a2;
      n4d_1 = n4h;
      n4i = FFX_Menu2D_ScaleX_1920to512(3.0) + n4e_5;
      n4e_1 = n4i;
      goto LABEL_7;
    case 3:
      *(float *)&v46 = 0.39160156;
      *(float *)&v45 = 0.48632812;
      *(float *)&v43 = 0.32910156;
      *(float *)&v42 = 0.48046875;
      n4e_3 = n4e_4;
      n4b_2 = n4b_3;
      n4e_1 = n4e_3;
      n4b_1 = n4b_2;
      n4c_1 = n4c_2;
      n4d_1 = n4d_2;
      goto LABEL_7;
    case 4:
      *(float *)&v46 = 0.39160156;
      *(float *)&v45 = 0.47363281;
      *(float *)&v43 = 0.32910156;
      *(float *)&v42 = 0.46777344;
      n4j = n4b_3 - FFX_Menu2D_ScaleY_1080to416(6.0);
      n4b_1 = n4j;
      n4k = n4c_3 - FFX_Menu2D_ScaleX_1920to512(6.0);
      n4c_1 = n4k;
      n4l = FFX_Menu2D_ScaleY_1080to416(3.0) + *(float *)&a2;
      n4d_1 = n4l;
      n4m = FFX_Menu2D_ScaleX_1920to512(3.0) + n4e_5;
      n4e_1 = n4m;
      goto LABEL_7;
    case 5:
      *(float *)&v44 = v11;
      n4n = n4b_3 - FFX_Menu2D_ScaleY_1080to416(6.0);
      n4n_1 = n4n;
      n4o = n4c_3 - FFX_Menu2D_ScaleX_1920to512(6.0);
      n4o_1 = n4o;
      *(float *)&n4p = FFX_Menu2D_ScaleY_1080to416(3.0) + *(float *)&a2;
      n4p_1 = n4p;
      n4q = FFX_Menu2D_ScaleX_1920to512(3.0) + n4e_5;
      FFX_Menu2D_DrawTexQuadSolid(
        0xFFFFFFFF,
        n4q,
        n4p_1,
        n4o_1,
        n4n_1,
        COERCE_INT(1258.0),
        v44,
        COERCE_INT(1262.0),
        COERCE_INT(60.0));
      break;
  }
  v34 = FFX_Menu2D_ScaleY_1080to416(3.0);
  v23 = FFX_Menu2D_ScaleX_1920to512(3.0);
  FFX_Menu2D_DrawTexQuadSolid(
    0xC8u,
    n4e_5,
    a2,
    v23,
    v34,
    COERCE_INT(0.375),
    COERCE_INT(0.328125),
    COERCE_INT(0.37890625),
    COERCE_INT(0.33203125));
  v35 = FFX_Menu2D_ScaleY_1080to416(3.0);
  n4r = n4c_3 - FFX_Menu2D_ScaleX_1920to512(6.0);
  n4r_1 = n4r;
  n4s = FFX_Menu2D_ScaleX_1920to512(3.0) + n4e_5;
  FFX_Menu2D_DrawTexQuadSolid(
    0xC8u,
    n4s,
    a2,
    n4r_1,
    v35,
    COERCE_INT(0.37890625),
    COERCE_INT(0.328125),
    COERCE_INT(0.43457031),
    COERCE_INT(0.33203125));
  v47 = n4e_5 + n4c_3;
  v36 = FFX_Menu2D_ScaleY_1080to416(3.0);
  v25 = FFX_Menu2D_ScaleX_1920to512(3.0);
  n4t = v47 - FFX_Menu2D_ScaleX_1920to512(3.0);
  FFX_Menu2D_DrawTexQuadSolid(
    0xC8u,
    n4t,
    a2,
    v25,
    v36,
    COERCE_INT(0.43457031),
    COERCE_INT(0.328125),
    COERCE_INT(0.43847656),
    COERCE_INT(0.33203125));
  n4u = n4b_4 - FFX_Menu2D_ScaleY_1080to416(6.0);
  n4u_1 = n4u;
  v26 = FFX_Menu2D_ScaleX_1920to512(3.0);
  *(float *)&n4v = FFX_Menu2D_ScaleY_1080to416(3.0) + *(float *)&a2;
  FFX_Menu2D_DrawTexQuadSolid(
    0xC8u,
    n4e_5,
    n4v,
    v26,
    n4u_1,
    COERCE_INT(0.375),
    COERCE_INT(0.33203125),
    COERCE_INT(0.37890625),
    COERCE_INT(0.38769531));
  v48 = *(float *)&a2 + n4b_4;
  v38 = FFX_Menu2D_ScaleY_1080to416(3.0);
  v27 = FFX_Menu2D_ScaleX_1920to512(3.0);
  *(float *)&n4w = v48 - FFX_Menu2D_ScaleY_1080to416(3.0);
  FFX_Menu2D_DrawTexQuadSolid(
    0xC8u,
    n4e_5,
    n4w,
    v27,
    v38,
    COERCE_INT(0.375),
    COERCE_INT(0.38769531),
    COERCE_INT(0.37890625),
    COERCE_INT(0.39160156));
  v39 = FFX_Menu2D_ScaleY_1080to416(3.0);
  v55 = n4c_3 - FFX_Menu2D_ScaleX_1920to512(6.0);
  v28 = v55;
  *(float *)&v56 = v48 - FFX_Menu2D_ScaleY_1080to416(3.0);
  v49 = FFX_Menu2D_ScaleX_1920to512(3.0) + n4e_5;
  FFX_Menu2D_DrawTexQuadSolid(
    0xC8u,
    v49,
    v56,
    v28,
    v39,
    COERCE_INT(0.37890625),
    COERCE_INT(0.38769531),
    COERCE_INT(0.43457031),
    COERCE_INT(0.39160156));
  v50 = n4b_4 - FFX_Menu2D_ScaleY_1080to416(6.0);
  v40 = v50;
  v29 = FFX_Menu2D_ScaleX_1920to512(3.0);
  *(float *)&v51 = FFX_Menu2D_ScaleY_1080to416(3.0) + *(float *)&a2;
  v19 = v51;
  v52 = v47 - FFX_Menu2D_ScaleX_1920to512(3.0);
  FFX_Menu2D_DrawTexQuadSolid(
    0xC8u,
    v52,
    v19,
    v29,
    v40,
    COERCE_INT(0.43457031),
    COERCE_INT(0.33203125),
    COERCE_INT(0.43847656),
    COERCE_INT(0.38769531));
  v41 = FFX_Menu2D_ScaleY_1080to416(3.0);
  v30 = FFX_Menu2D_ScaleX_1920to512(3.0);
  *(float *)&v53 = v48 - FFX_Menu2D_ScaleY_1080to416(3.0);
  v20 = v53;
  v54 = v47 - FFX_Menu2D_ScaleX_1920to512(3.0);
  return FFX_Menu2D_DrawTexQuadSolid(
           0xC8u,
           v54,
           v20,
           v30,
           v41,
           COERCE_INT(0.43457031),
           COERCE_INT(0.38769531),
           COERCE_INT(0.43847656),
           COERCE_INT(0.39160156));
}
