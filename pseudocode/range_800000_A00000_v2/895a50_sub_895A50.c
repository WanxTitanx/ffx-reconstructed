// Function: sub_895A50
// Address: 0x895a50
int __cdecl sub_895A50(char a1, int n2, int a3, int a4)
{
  char ActorElementCategoryMask_Switch4; // bl
  int result; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st5
  double v9; // st4
  double v10; // st3
  int v11; // [esp+4h] [ebp-24h]
  int v12; // [esp+4h] [ebp-24h]
  int v13; // [esp+4h] [ebp-24h]
  int v14; // [esp+4h] [ebp-24h]
  int v15; // [esp+4h] [ebp-24h]
  int v16; // [esp+4h] [ebp-24h]
  int v17; // [esp+4h] [ebp-24h]
  int v18; // [esp+4h] [ebp-24h]
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
  float v43; // [esp+34h] [ebp+Ch]
  int v44; // [esp+34h] [ebp+Ch]
  float v45; // [esp+34h] [ebp+Ch]
  float v46; // [esp+34h] [ebp+Ch]
  float v47; // [esp+34h] [ebp+Ch]
  int v48; // [esp+34h] [ebp+Ch]
  float v49; // [esp+34h] [ebp+Ch]
  float v50; // [esp+34h] [ebp+Ch]
  float v51; // [esp+34h] [ebp+Ch]
  int v52; // [esp+34h] [ebp+Ch]
  float v53; // [esp+34h] [ebp+Ch]
  float v54; // [esp+34h] [ebp+Ch]
  float v55; // [esp+34h] [ebp+Ch]
  int v56; // [esp+34h] [ebp+Ch]
  float v57; // [esp+34h] [ebp+Ch]
  float v58; // [esp+34h] [ebp+Ch]
  int v59; // [esp+34h] [ebp+Ch]
  float v60; // [esp+34h] [ebp+Ch]
  int v61; // [esp+34h] [ebp+Ch]
  float v62; // [esp+34h] [ebp+Ch]
  int v63; // [esp+34h] [ebp+Ch]
  float v64; // [esp+34h] [ebp+Ch]
  int v65; // [esp+34h] [ebp+Ch]
  float v66; // [esp+34h] [ebp+Ch]
  float v67; // [esp+38h] [ebp+10h]
  float v68; // [esp+3Ch] [ebp+14h]
  int v69; // [esp+3Ch] [ebp+14h]
  float v70; // [esp+3Ch] [ebp+14h]

  ActorElementCategoryMask_Switch4 = FFX_GetActorElementCategoryMask_Switch4(a1, n2);
  switch ( n2 )
  {
    case 0:
      v27 = FFX_Menu2D_ScaleY_1080to416(26.0);
      v19 = FFX_Menu2D_ScaleX_1920to512(75.0);
      v43 = (float)a4;
      *(float *)&v44 = FFX_Menu2D_ScaleY_1080to416(6.0) + v43;
      v11 = v44;
      v45 = (float)a3;
      v46 = FFX_Menu2D_ScaleX_1920to512(25.0) + v45;
      FFX_Menu2D_DrawTexQuadSolid(
        0x1AFu,
        v46,
        v11,
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
      v47 = (float)a4;
      *(float *)&v48 = FFX_Menu2D_ScaleY_1080to416(6.0) + v47;
      v12 = v48;
      v49 = (float)a3;
      v50 = FFX_Menu2D_ScaleX_1920to512(25.0) + v49;
      FFX_Menu2D_DrawTexQuadSolid(
        0x1B0u,
        v50,
        v12,
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
      v51 = (float)a4;
      *(float *)&v52 = FFX_Menu2D_ScaleY_1080to416(6.0) + v51;
      v13 = v52;
      v53 = (float)a3;
      v54 = FFX_Menu2D_ScaleX_1920to512(25.0) + v53;
      FFX_Menu2D_DrawTexQuadSolid(
        0x1B1u,
        v54,
        v13,
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
      v55 = (float)a4;
      *(float *)&v56 = FFX_Menu2D_ScaleY_1080to416(6.0) + v55;
      v14 = v56;
      v57 = (float)a3;
      v58 = FFX_Menu2D_ScaleX_1920to512(25.0) + v57;
      FFX_Menu2D_DrawTexQuadSolid(
        0x1B2u,
        v58,
        v14,
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
  v68 = (float)a4;
  v67 = (float)a3;
  v31 = FFX_Menu2D_ScaleY_1080to416(35.700001);
  v23 = FFX_Menu2D_ScaleX_1920to512(225.0);
  *(float *)&v59 = FFX_Menu2D_ScaleY_1080to416(2.0) + v68;
  v15 = v59;
  v60 = FFX_Menu2D_ScaleX_1920to512(125.0) + v67;
  result = FFX_Menu2D_DrawTexQuadSolid(
             0x1AFu,
             v60,
             v15,
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
    *(float *)&v61 = FFX_Menu2D_ScaleY_1080to416(4.0) + v68;
    v16 = v61;
    v62 = FFX_Menu2D_ScaleX_1920to512(125.0) + v67;
    result = FFX_Menu2D_DrawTexQuadSolid(
               0x1AFu,
               v62,
               v16,
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
    *(float *)&v63 = FFX_Menu2D_ScaleY_1080to416(4.0) + v68;
    v17 = v63;
    v64 = FFX_Menu2D_ScaleX_1920to512(188.0) + v67;
    result = FFX_Menu2D_DrawTexQuadSolid(0x1AFu, v64, v17, v25, v34, v37, v39, v41, v42);
  }
  if ( (ActorElementCategoryMask_Switch4 & 8) == 0 )
  {
    v35 = FFX_Menu2D_ScaleY_1080to416(32.700001);
    v26 = FFX_Menu2D_ScaleX_1920to512(32.700001);
    *(float *)&v65 = FFX_Menu2D_ScaleY_1080to416(4.0) + v68;
    v18 = v65;
    v66 = FFX_Menu2D_ScaleX_1920to512(251.0) + v67;
    result = FFX_Menu2D_DrawTexQuadSolid(
               0x1AFu,
               v66,
               v18,
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
    *(float *)&v69 = FFX_Menu2D_ScaleY_1080to416(4.0) + v68;
    v36 = v69;
    v70 = FFX_Menu2D_ScaleX_1920to512(316.0) + v67;
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
