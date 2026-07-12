// Function: FFX_BtlUI_DrawScanElementResistRow_4ElemHardcoded
// Address: 0x894ab0
int __cdecl FFX_BtlUI_DrawScanElementResistRow_4ElemHardcoded(char a1, int n2, int n2c_1, int n2a_1)
{
  char ActorElementCategoryMask_Switch4; // bl
  int result; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st5
  double v9; // st4
  double v10; // st3
  int n2b_1; // [esp+4h] [ebp-24h]
  int n2f_1; // [esp+4h] [ebp-24h]
  int n2j_1; // [esp+4h] [ebp-24h]
  int n2n_1; // [esp+4h] [ebp-24h]
  int n2q_1; // [esp+4h] [ebp-24h]
  int n2s_1; // [esp+4h] [ebp-24h]
  int n2u_1; // [esp+4h] [ebp-24h]
  int n2w_1; // [esp+4h] [ebp-24h]
  float v19; // [esp+8h] [ebp-20h]
  float v20; // [esp+8h] [ebp-20h]
  float v21; // [esp+8h] [ebp-20h]
  float v22; // [esp+8h] [ebp-20h]
  float v23; // [esp+8h] [ebp-20h]
  float v24; // [esp+8h] [ebp-20h]
  float v25; // [esp+8h] [ebp-20h]
  float v26; // [esp+8h] [ebp-20h]
  float v27; // [esp+Ch] [ebp-1Ch]
  float v28; // [esp+Ch] [ebp-1Ch]
  float v29; // [esp+Ch] [ebp-1Ch]
  float v30; // [esp+Ch] [ebp-1Ch]
  float v31; // [esp+Ch] [ebp-1Ch]
  float v32; // [esp+Ch] [ebp-1Ch]
  float v33; // [esp+Ch] [ebp-1Ch]
  float v34; // [esp+Ch] [ebp-1Ch]
  float v35; // [esp+Ch] [ebp-1Ch]
  int v36; // [esp+Ch] [ebp-1Ch]
  int v37; // [esp+10h] [ebp-18h]
  float v38; // [esp+10h] [ebp-18h]
  int v39; // [esp+14h] [ebp-14h]
  float v40; // [esp+14h] [ebp-14h]
  int v41; // [esp+18h] [ebp-10h]
  int v42; // [esp+1Ch] [ebp-Ch]
  float n2a; // [esp+34h] [ebp+Ch]
  int n2b; // [esp+34h] [ebp+Ch]
  float n2c; // [esp+34h] [ebp+Ch]
  float n2d; // [esp+34h] [ebp+Ch]
  float n2e; // [esp+34h] [ebp+Ch]
  int n2f; // [esp+34h] [ebp+Ch]
  float n2g; // [esp+34h] [ebp+Ch]
  float n2h; // [esp+34h] [ebp+Ch]
  float n2i; // [esp+34h] [ebp+Ch]
  int n2j; // [esp+34h] [ebp+Ch]
  float n2k; // [esp+34h] [ebp+Ch]
  float n2l; // [esp+34h] [ebp+Ch]
  float n2m; // [esp+34h] [ebp+Ch]
  int n2n; // [esp+34h] [ebp+Ch]
  float n2o; // [esp+34h] [ebp+Ch]
  float n2p; // [esp+34h] [ebp+Ch]
  int n2q; // [esp+34h] [ebp+Ch]
  float n2r; // [esp+34h] [ebp+Ch]
  int n2s; // [esp+34h] [ebp+Ch]
  float n2t; // [esp+34h] [ebp+Ch]
  int n2u; // [esp+34h] [ebp+Ch]
  float n2v; // [esp+34h] [ebp+Ch]
  int n2w; // [esp+34h] [ebp+Ch]
  float n2x; // [esp+34h] [ebp+Ch]
  float n2c_2; // [esp+38h] [ebp+10h]
  float n2a_2; // [esp+3Ch] [ebp+14h]
  int v69; // [esp+3Ch] [ebp+14h]
  float v70; // [esp+3Ch] [ebp+14h]

  ActorElementCategoryMask_Switch4 = FFX_GetActorElementCategoryMask_Switch4(a1, n2);
  switch ( n2 )
  {
    case 0:
      v27 = FFX_Menu2D_ScaleY_1080to416(26.0);
      v19 = FFX_Menu2D_ScaleX_1920to512(75.0);
      n2a = (float)n2a_1;
      *(float *)&n2b = FFX_Menu2D_ScaleY_1080to416(6.0) + n2a;
      n2b_1 = n2b;
      n2c = (float)n2c_1;
      n2d = FFX_Menu2D_ScaleX_1920to512(25.0) + n2c;
      FFX_Menu2D_DrawTexQuadSolid(
        0x1AFu,
        n2d,
        n2b_1,
        v19,
        v27,
        COERCE_INT(0.041015625),
        COERCE_INT(0.94921875),
        COERCE_INT(0.13476562),
        COERCE_INT(0.98828125));
      break;
    case 1:
      v28 = FFX_Menu2D_ScaleY_1080to416(26.0);
      v20 = FFX_Menu2D_ScaleX_1920to512(75.0);
      n2e = (float)n2a_1;
      *(float *)&n2f = FFX_Menu2D_ScaleY_1080to416(6.0) + n2e;
      n2f_1 = n2f;
      n2g = (float)n2c_1;
      n2h = FFX_Menu2D_ScaleX_1920to512(25.0) + n2g;
      FFX_Menu2D_DrawTexQuadSolid(
        0x1B0u,
        n2h,
        n2f_1,
        v20,
        v28,
        COERCE_INT(0.041015625),
        COERCE_INT(0.88671875),
        COERCE_INT(0.13476562),
        COERCE_INT(0.92578125));
      break;
    case 2:
      v29 = FFX_Menu2D_ScaleY_1080to416(26.0);
      v21 = FFX_Menu2D_ScaleX_1920to512(75.0);
      n2i = (float)n2a_1;
      *(float *)&n2j = FFX_Menu2D_ScaleY_1080to416(6.0) + n2i;
      n2j_1 = n2j;
      n2k = (float)n2c_1;
      n2l = FFX_Menu2D_ScaleX_1920to512(25.0) + n2k;
      FFX_Menu2D_DrawTexQuadSolid(
        0x1B1u,
        n2l,
        n2j_1,
        v21,
        v29,
        COERCE_INT(0.23046875),
        COERCE_INT(0.88671875),
        COERCE_INT(0.32421875),
        COERCE_INT(0.92578125));
      break;
    case 3:
      v30 = FFX_Menu2D_ScaleY_1080to416(26.0);
      v22 = FFX_Menu2D_ScaleX_1920to512(75.0);
      n2m = (float)n2a_1;
      *(float *)&n2n = FFX_Menu2D_ScaleY_1080to416(6.0) + n2m;
      n2n_1 = n2n;
      n2o = (float)n2c_1;
      n2p = FFX_Menu2D_ScaleX_1920to512(25.0) + n2o;
      FFX_Menu2D_DrawTexQuadSolid(
        0x1B2u,
        n2p,
        n2n_1,
        v22,
        v30,
        COERCE_INT(0.41894531),
        COERCE_INT(0.88671875),
        COERCE_INT(0.51269531),
        COERCE_INT(0.92578125));
      break;
    default:
      break;
  }
  n2a_2 = (float)n2a_1;
  n2c_2 = (float)n2c_1;
  v31 = FFX_Menu2D_ScaleY_1080to416(35.700001);
  v23 = FFX_Menu2D_ScaleX_1920to512(225.0);
  *(float *)&n2q = FFX_Menu2D_ScaleY_1080to416(2.0) + n2a_2;
  n2q_1 = n2q;
  n2r = FFX_Menu2D_ScaleX_1920to512(125.0) + n2c_2;
  result = FFX_Menu2D_DrawTexQuadSolid(
             0x1AFu,
             n2r,
             n2q_1,
             v23,
             v31,
             COERCE_INT(0.22460938),
             COERCE_INT(0.94921875),
             COERCE_INT(0.46582031),
             COERCE_INT(0.98828125));
  v6 = 0.98632812;
  v7 = 0.58007812;
  v8 = 0.95117188;
  v9 = 0.54394531;
  v10 = 32.700001;
  if ( (ActorElementCategoryMask_Switch4 & 1) == 0 )
  {
    v32 = FFX_Menu2D_ScaleY_1080to416(32.700001);
    v24 = FFX_Menu2D_ScaleX_1920to512(32.700001);
    *(float *)&n2s = FFX_Menu2D_ScaleY_1080to416(4.0) + n2a_2;
    n2s_1 = n2s;
    n2t = FFX_Menu2D_ScaleX_1920to512(125.0) + n2c_2;
    result = FFX_Menu2D_DrawTexQuadSolid(
               0x1AFu,
               n2t,
               n2s_1,
               v24,
               v32,
               COERCE_INT(0.54394531),
               COERCE_INT(0.95117188),
               COERCE_INT(0.58007812),
               COERCE_INT(0.98632812));
    v6 = 0.98632812;
    v7 = 0.58007812;
    v9 = 0.54394531;
    v10 = 32.700001;
    v8 = 0.95117188;
  }
  if ( (ActorElementCategoryMask_Switch4 & 4) == 0 )
  {
    *(float *)&v42 = v6;
    *(float *)&v41 = v7;
    *(float *)&v39 = v8;
    *(float *)&v37 = v9;
    v33 = v10;
    v34 = FFX_Menu2D_ScaleY_1080to416(v33);
    v25 = FFX_Menu2D_ScaleX_1920to512(32.700001);
    *(float *)&n2u = FFX_Menu2D_ScaleY_1080to416(4.0) + n2a_2;
    n2u_1 = n2u;
    n2v = FFX_Menu2D_ScaleX_1920to512(188.0) + n2c_2;
    result = FFX_Menu2D_DrawTexQuadSolid(0x1AFu, n2v, n2u_1, v25, v34, v37, v39, v41, v42);
  }
  if ( (ActorElementCategoryMask_Switch4 & 8) == 0 )
  {
    v35 = FFX_Menu2D_ScaleY_1080to416(32.700001);
    v26 = FFX_Menu2D_ScaleX_1920to512(32.700001);
    *(float *)&n2w = FFX_Menu2D_ScaleY_1080to416(4.0) + n2a_2;
    n2w_1 = n2w;
    n2x = FFX_Menu2D_ScaleX_1920to512(251.0) + n2c_2;
    result = FFX_Menu2D_DrawTexQuadSolid(
               0x1AFu,
               n2x,
               n2w_1,
               v26,
               v35,
               COERCE_INT(0.54394531),
               COERCE_INT(0.95117188),
               COERCE_INT(0.58007812),
               COERCE_INT(0.98632812));
  }
  if ( (ActorElementCategoryMask_Switch4 & 2) == 0 )
  {
    v40 = FFX_Menu2D_ScaleY_1080to416(32.700001);
    v38 = FFX_Menu2D_ScaleX_1920to512(32.700001);
    *(float *)&v69 = FFX_Menu2D_ScaleY_1080to416(4.0) + n2a_2;
    v36 = v69;
    v70 = FFX_Menu2D_ScaleX_1920to512(316.0) + n2c_2;
    return FFX_Menu2D_DrawTexQuadSolid(
             0x1AFu,
             v70,
             v36,
             v38,
             v40,
             COERCE_INT(0.54394531),
             COERCE_INT(0.95117188),
             COERCE_INT(0.58007812),
             COERCE_INT(0.98632812));
  }
  return result;
}
