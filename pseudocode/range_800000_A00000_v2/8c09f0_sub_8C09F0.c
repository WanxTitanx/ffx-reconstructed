// Function: sub_8C09F0
// Address: 0x8c09f0
int __cdecl sub_8C09F0(float a1, int a2, float a3, float a4, int a5)
{
  double v5; // st7
  float v7; // [esp+8h] [ebp-28h]
  float v8; // [esp+10h] [ebp-20h]
  float v9; // [esp+10h] [ebp-20h]
  double v10; // [esp+24h] [ebp-Ch]
  float v11; // [esp+28h] [ebp-8h]
  int v12; // [esp+2Ch] [ebp-4h] BYREF
  float v13; // [esp+38h] [ebp+8h]
  float v14; // [esp+38h] [ebp+8h]
  float v15; // [esp+38h] [ebp+8h]
  float v16; // [esp+38h] [ebp+8h]

  v11 = a3 - FFX_Menu2D_ScaleX_1920to512(207.0);
  FFX_Menu2D_DrawTexQuadSolid(
    0xC8u,
    a1,
    a2,
    v11,
    a4,
    COERCE_INT(0.017578125),
    COERCE_INT(0.88476562),
    COERCE_INT(0.30371094),
    COERCE_INT(0.91894531));
  v10 = a1 + a3;
  v7 = FFX_Menu2D_ScaleX_1920to512(207.0);
  v13 = v10 - FFX_Menu2D_ScaleX_1920to512(207.0);
  FFX_Menu2D_DrawTexQuadSolid(
    0xC8u,
    v13,
    a2,
    v7,
    a4,
    COERCE_INT(0.30371094),
    COERCE_INT(0.88476562),
    COERCE_INT(0.50585938),
    COERCE_INT(0.91894531));
  sub_905230(a5, (int)&v12, 0.68000001, 1.0);
  v8 = -2.0;
  if ( FFX_Game_GetRegion() == 3 )
  {
    v14 = FFX_Menu2D_ScaleY_1080to416(v8) + *(float *)&a2;
    v9 = v14;
    v5 = FFX_Menu2D_ScaleX_1920to512(110.0);
  }
  else
  {
    v16 = FFX_Menu2D_ScaleY_1080to416(v8) + *(float *)&a2;
    v9 = v16;
    v5 = FFX_Menu2D_ScaleX_1920to512(95.0);
  }
  v15 = v10 - v5 - *(float *)&v12;
  return sub_905820(a5, v15, v9, 37, 0.68000001, 1.0);
}
