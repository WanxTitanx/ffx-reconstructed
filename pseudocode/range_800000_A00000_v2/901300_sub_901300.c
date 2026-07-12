// Function: sub_901300
// Address: 0x901300
int __cdecl sub_901300(int n160, int a2, int a3)
{
  float v4; // [esp+8h] [ebp-24h]
  float v5; // [esp+8h] [ebp-24h]
  float v6; // [esp+Ch] [ebp-20h]
  float v7; // [esp+Ch] [ebp-20h]
  float v8; // [esp+Ch] [ebp-20h]
  float v9; // [esp+24h] [ebp-8h]
  float v10; // [esp+24h] [ebp-8h]
  float n160_1; // [esp+28h] [ebp-4h]
  int v12; // [esp+38h] [ebp+Ch]
  float v13; // [esp+3Ch] [ebp+10h]

  *(float *)&v12 = (float)a2;
  n160_1 = (float)n160;
  v6 = FFX_Menu2D_ScaleY_1080to416(51.0);
  v4 = FFX_Menu2D_ScaleX_1920to512(27.0);
  v9 = n160_1 - FFX_Menu2D_ScaleX_1920to512(27.0);
  FFX_Menu2D_DrawTexQuadSolid(
    0x190u,
    v9,
    v12,
    v4,
    v6,
    COERCE_INT(0.05859375),
    COERCE_INT(0.010742188),
    COERCE_INT(0.084960938),
    COERCE_INT(0.060546875));
  v7 = FFX_Menu2D_ScaleY_1080to416(51.0);
  v10 = (float)a3;
  FFX_Menu2D_DrawTexQuadSolid(
    0x190u,
    n160_1,
    v12,
    v10,
    v7,
    COERCE_INT(0.084960938),
    COERCE_INT(0.010742188),
    COERCE_INT(0.18554688),
    COERCE_INT(0.060546875));
  v8 = FFX_Menu2D_ScaleY_1080to416(51.0);
  v5 = FFX_Menu2D_ScaleX_1920to512(27.0);
  v13 = (float)(a3 + n160);
  return FFX_Menu2D_DrawTexQuadSolid(
           0x190u,
           v13,
           v12,
           v5,
           v8,
           COERCE_INT(0.18554688),
           COERCE_INT(0.010742188),
           COERCE_INT(0.21191406),
           COERCE_INT(0.060546875));
}
