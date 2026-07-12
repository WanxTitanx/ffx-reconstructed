// Function: FFX_Menu2D_DrawRoundedPanel9Slice
// Address: 0x8f41b0
void __usercall FFX_Menu2D_DrawRoundedPanel9Slice(
        double a1@<st0>,
        float a2,
        int a3,
        float a4,
        float a5,
        unsigned int n3)
{
  unsigned int v6; // edi
  double v8; // [esp+30h] [ebp-20h]
  double v9; // [esp+38h] [ebp-18h]
  float v10; // [esp+40h] [ebp-10h]
  float v11; // [esp+40h] [ebp-10h]
  float v12; // [esp+40h] [ebp-10h]
  float v13; // [esp+40h] [ebp-10h]
  float v14; // [esp+40h] [ebp-10h]
  float v15; // [esp+40h] [ebp-10h]
  float v16; // [esp+40h] [ebp-10h]
  float v17; // [esp+44h] [ebp-Ch]
  float v18; // [esp+44h] [ebp-Ch]
  float v19; // [esp+44h] [ebp-Ch]
  float v20; // [esp+44h] [ebp-Ch]
  float v21; // [esp+44h] [ebp-Ch]
  float v22; // [esp+44h] [ebp-Ch]
  float v23; // [esp+44h] [ebp-Ch]
  float v24; // [esp+44h] [ebp-Ch]
  float v25; // [esp+44h] [ebp-Ch]
  float v26; // [esp+4Ch] [ebp-4h]
  float v27; // [esp+4Ch] [ebp-4h]
  float v28; // [esp+4Ch] [ebp-4h]
  float v29; // [esp+4Ch] [ebp-4h]
  float v30; // [esp+4Ch] [ebp-4h]
  float v31; // [esp+4Ch] [ebp-4h]
  float v32; // [esp+4Ch] [ebp-4h]
  float v33; // [esp+4Ch] [ebp-4h]
  float v34; // [esp+4Ch] [ebp-4h]
  int v35; // [esp+68h] [ebp+18h]
  int v36; // [esp+68h] [ebp+18h]
  int v37; // [esp+68h] [ebp+18h]
  int v38; // [esp+68h] [ebp+18h]
  int v39; // [esp+68h] [ebp+18h]
  int v40; // [esp+68h] [ebp+18h]

  FFX_Engine_GetTime();
  v10 = cos(a1 * 3.0);
  v6 = ((unsigned int)(__int64)(v10 * 32.0 + 96.0) << 24) + 8421504;
  v17 = FFX_Menu2D_ScaleX_1920to512(8.0);
  v26 = FFX_Menu2D_ScaleY_1080to416(8.0);
  if ( !n3 || n3 == 2 )
  {
    FFX_Menu2D_DrawTexQuadSolid(
      0x194u,
      a2,
      a3,
      v17,
      v26,
      COERCE_INT(0.55175781),
      COERCE_INT(0.76953125),
      COERCE_INT(0.56054688),
      COERCE_INT(0.77734375));
  }
  else if ( n3 == 1 || n3 == 3 )
  {
    FFX_Menu2D_DrawTexQuadTinted(
      0x194u,
      a2,
      a3,
      v17,
      v26,
      COERCE_INT(0.55175781),
      COERCE_INT(0.83691406),
      COERCE_INT(0.56054688),
      COERCE_INT(0.84472656),
      v6,
      v6);
  }
  *(float *)&v35 = FFX_Menu2D_ScaleY_1080to416(8.0) + *(float *)&a3;
  v18 = FFX_Menu2D_ScaleX_1920to512(8.0);
  v27 = a5 - FFX_Menu2D_ScaleY_1080to416(16.0);
  if ( !n3 || n3 == 2 )
  {
    FFX_Menu2D_DrawTexQuadSolid(
      0x194u,
      a2,
      v35,
      v18,
      v27,
      COERCE_INT(0.55175781),
      COERCE_INT(0.77734375),
      COERCE_INT(0.56054688),
      COERCE_INT(0.81445312));
  }
  else if ( n3 == 1 || n3 == 3 )
  {
    FFX_Menu2D_DrawTexQuadTinted(
      0x194u,
      a2,
      v35,
      v18,
      v27,
      COERCE_INT(0.55175781),
      COERCE_INT(0.84472656),
      COERCE_INT(0.56054688),
      COERCE_INT(0.88671875),
      v6,
      v6);
  }
  v8 = *(float *)&a3 + a5;
  *(float *)&v36 = v8 - FFX_Menu2D_ScaleY_1080to416(8.0);
  v19 = FFX_Menu2D_ScaleX_1920to512(8.0);
  v28 = FFX_Menu2D_ScaleY_1080to416(8.0);
  if ( !n3 || n3 == 2 )
  {
    FFX_Menu2D_DrawTexQuadSolid(
      0x194u,
      a2,
      v36,
      v19,
      v28,
      COERCE_INT(0.55175781),
      COERCE_INT(0.81445312),
      COERCE_INT(0.56054688),
      COERCE_INT(0.82324219));
  }
  else if ( n3 == 1 || n3 == 3 )
  {
    FFX_Menu2D_DrawTexQuadTinted(
      0x194u,
      a2,
      v36,
      v19,
      v28,
      COERCE_INT(0.55175781),
      COERCE_INT(0.88671875),
      COERCE_INT(0.56054688),
      COERCE_INT(0.88964844),
      v6,
      v6);
  }
  v11 = FFX_Menu2D_ScaleX_1920to512(8.0) + a2;
  v20 = a4 - FFX_Menu2D_ScaleX_1920to512(16.0);
  v29 = FFX_Menu2D_ScaleY_1080to416(8.0);
  if ( !n3 || n3 == 2 )
  {
    FFX_Menu2D_DrawTexQuadSolid(
      0x194u,
      v11,
      a3,
      v20,
      v29,
      COERCE_INT(0.56054688),
      COERCE_INT(0.76953125),
      COERCE_INT(0.59570312),
      COERCE_INT(0.77734375));
  }
  else if ( n3 == 1 || n3 == 3 )
  {
    FFX_Menu2D_DrawTexQuadTinted(
      0x194u,
      v11,
      a3,
      v20,
      v29,
      COERCE_INT(0.56054688),
      COERCE_INT(0.83691406),
      COERCE_INT(0.59570312),
      COERCE_INT(0.84472656),
      v6,
      v6);
  }
  v12 = FFX_Menu2D_ScaleX_1920to512(8.0) + a2;
  *(float *)&v37 = v8 - FFX_Menu2D_ScaleY_1080to416(8.0);
  v21 = a4 - FFX_Menu2D_ScaleX_1920to512(16.0);
  v30 = FFX_Menu2D_ScaleY_1080to416(8.0);
  if ( !n3 || n3 == 2 )
  {
    FFX_Menu2D_DrawTexQuadSolid(
      0x194u,
      v12,
      v37,
      v21,
      v30,
      COERCE_INT(0.56054688),
      COERCE_INT(0.81445312),
      COERCE_INT(0.59570312),
      COERCE_INT(0.82324219));
  }
  else if ( n3 == 1 || n3 == 3 )
  {
    FFX_Menu2D_DrawTexQuadTinted(
      0x194u,
      v12,
      v37,
      v21,
      v30,
      COERCE_INT(0.56054688),
      COERCE_INT(0.88671875),
      COERCE_INT(0.59570312),
      COERCE_INT(0.88964844),
      v6,
      v6);
  }
  v9 = a2 + a4;
  v13 = v9 - FFX_Menu2D_ScaleX_1920to512(8.0);
  v22 = FFX_Menu2D_ScaleX_1920to512(8.0);
  v31 = FFX_Menu2D_ScaleY_1080to416(8.0);
  if ( !n3 || n3 == 2 )
  {
    FFX_Menu2D_DrawTexQuadSolid(
      0x194u,
      v13,
      a3,
      v22,
      v31,
      COERCE_INT(0.59570312),
      COERCE_INT(0.76953125),
      COERCE_INT(0.60449219),
      COERCE_INT(0.77734375));
  }
  else if ( n3 == 1 || n3 == 3 )
  {
    FFX_Menu2D_DrawTexQuadTinted(
      0x194u,
      v13,
      a3,
      v22,
      v31,
      COERCE_INT(0.59570312),
      COERCE_INT(0.83691406),
      COERCE_INT(0.60449219),
      COERCE_INT(0.84472656),
      v6,
      v6);
  }
  v14 = v9 - FFX_Menu2D_ScaleX_1920to512(8.0);
  *(float *)&v38 = FFX_Menu2D_ScaleY_1080to416(8.0) + *(float *)&a3;
  v23 = FFX_Menu2D_ScaleX_1920to512(8.0);
  v32 = a5 - FFX_Menu2D_ScaleY_1080to416(16.0);
  if ( !n3 || n3 == 2 )
  {
    FFX_Menu2D_DrawTexQuadSolid(
      0x194u,
      v14,
      v38,
      v23,
      v32,
      COERCE_INT(0.59570312),
      COERCE_INT(0.77734375),
      COERCE_INT(0.60449219),
      COERCE_INT(0.81445312));
  }
  else if ( n3 == 1 || n3 == 3 )
  {
    FFX_Menu2D_DrawTexQuadTinted(
      0x194u,
      v14,
      v38,
      v23,
      v32,
      COERCE_INT(0.59570312),
      COERCE_INT(0.84472656),
      COERCE_INT(0.60449219),
      COERCE_INT(0.88671875),
      v6,
      v6);
  }
  v15 = v9 - FFX_Menu2D_ScaleX_1920to512(8.0);
  *(float *)&v39 = v8 - FFX_Menu2D_ScaleY_1080to416(8.0);
  v24 = FFX_Menu2D_ScaleX_1920to512(8.0);
  v33 = FFX_Menu2D_ScaleY_1080to416(8.0);
  if ( !n3 || n3 == 2 )
  {
    FFX_Menu2D_DrawTexQuadSolid(
      0x194u,
      v15,
      v39,
      v24,
      v33,
      COERCE_INT(0.59570312),
      COERCE_INT(0.81445312),
      COERCE_INT(0.60449219),
      COERCE_INT(0.82324219));
  }
  else if ( n3 == 1 || n3 == 3 )
  {
    FFX_Menu2D_DrawTexQuadTinted(
      0x194u,
      v15,
      v39,
      v24,
      v33,
      COERCE_INT(0.59570312),
      COERCE_INT(0.88671875),
      COERCE_INT(0.60449219),
      COERCE_INT(0.88964844),
      v6,
      v6);
  }
  v16 = FFX_Menu2D_ScaleX_1920to512(8.0) + a2;
  *(float *)&v40 = FFX_Menu2D_ScaleY_1080to416(8.0) + *(float *)&a3;
  v25 = a4 - FFX_Menu2D_ScaleX_1920to512(16.0);
  v34 = a5 - FFX_Menu2D_ScaleY_1080to416(16.0);
  if ( n3 < 2 || n3 == 4 )
    FFX_Menu2D_DrawTexQuadSolid(
      0x194u,
      v16,
      v40,
      v25,
      v34,
      COERCE_INT(0.56054688),
      COERCE_INT(0.77734375),
      COERCE_INT(0.59570312),
      COERCE_INT(0.81445312));
}
