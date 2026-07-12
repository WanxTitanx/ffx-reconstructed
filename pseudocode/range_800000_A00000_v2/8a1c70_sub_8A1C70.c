// Function: sub_8A1C70
// Address: 0x8a1c70
int sub_8A1C70()
{
  float v1; // [esp+0h] [ebp-20h]
  float v2; // [esp+0h] [ebp-20h]
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+4h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-1Ch]
  int v6; // [esp+4h] [ebp-1Ch]
  float v7; // [esp+8h] [ebp-18h]
  float v8; // [esp+8h] [ebp-18h]
  float v9; // [esp+8h] [ebp-18h]
  float v10; // [esp+Ch] [ebp-14h]
  float v11; // [esp+Ch] [ebp-14h]
  float v12; // [esp+Ch] [ebp-14h]

  v10 = FFX_Menu2D_ScaleY_1080to416(66.0);
  v7 = FFX_Menu2D_ScaleX_1920to512(1505.0);
  *(float *)&v4 = FFX_Menu2D_ScaleY_1080to416(175.0);
  v1 = FFX_Menu2D_ScaleX_1920to512(210.0);
  FFX_Menu2D_DrawTexQuadSolid(
    0xFFFFFFFF,
    v1,
    v4,
    v7,
    v10,
    COERCE_INT(0.0),
    COERCE_INT(290.0),
    COERCE_INT(1505.0),
    COERCE_INT(356.0));
  v11 = FFX_Menu2D_ScaleY_1080to416(155.0);
  v8 = FFX_Menu2D_ScaleX_1920to512(1505.0);
  *(float *)&v5 = FFX_Menu2D_ScaleY_1080to416(460.0);
  v2 = FFX_Menu2D_ScaleX_1920to512(210.0);
  FFX_Menu2D_DrawTexQuadSolid(
    0xFFFFFFFF,
    v2,
    v5,
    v8,
    v11,
    COERCE_INT(0.0),
    COERCE_INT(363.0),
    COERCE_INT(1505.0),
    COERCE_INT(518.0));
  v12 = FFX_Menu2D_ScaleY_1080to416(76.0);
  v9 = FFX_Menu2D_ScaleX_1920to512(1495.0);
  *(float *)&v6 = FFX_Menu2D_ScaleY_1080to416(499.0);
  v3 = FFX_Menu2D_ScaleX_1920to512(213.0);
  return FFX_Menu2D_DrawTexQuadSolid(
           0xFFFFFFFF,
           v3,
           v6,
           v9,
           v12,
           COERCE_INT(6.0),
           COERCE_INT(160.0),
           COERCE_INT(1500.0),
           COERCE_INT(236.0));
}
