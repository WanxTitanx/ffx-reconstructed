// Function: sub_8C0640
// Address: 0x8c0640
int __cdecl sub_8C0640(float a1, float a2, int n5)
{
  int n5_1; // eax
  double v4; // st7
  double v5; // st7
  float v6; // [esp+8h] [ebp-34h]
  float v7; // [esp+8h] [ebp-34h]
  float v8; // [esp+8h] [ebp-34h]
  float v9; // [esp+Ch] [ebp-30h]
  float v10; // [esp+Ch] [ebp-30h]
  float v11; // [esp+Ch] [ebp-30h]
  double v12; // [esp+20h] [ebp-1Ch] BYREF
  int v13; // [esp+28h] [ebp-14h] BYREF
  double v14; // [esp+2Ch] [ebp-10h]
  int n5_3; // [esp+34h] [ebp-8h] BYREF
  float n5_2; // [esp+38h] [ebp-4h]
  float v17; // [esp+44h] [ebp+8h]
  float v18; // [esp+44h] [ebp+8h]
  float v19; // [esp+44h] [ebp+8h]
  int v20; // [esp+48h] [ebp+Ch]
  int v21; // [esp+48h] [ebp+Ch]
  int v22; // [esp+48h] [ebp+Ch]

  n5_1 = n5;
  if ( *(float *)&n5 == 0.0 )
  {
    v4 = a1 - FFX_Menu2D_ScaleX_1920to512(68.0);
    v17 = v4;
    FFX_Engine_GetTime();
    *(float *)&n5 = cos(v4 * 8.0);
    v18 = *(float *)&n5 * 3.0 + v17;
    *(float *)&v20 = a2 - FFX_Menu2D_ScaleY_1080to416(5.0);
    v9 = FFX_Menu2D_ScaleY_1080to416(45.0);
    v6 = FFX_Menu2D_ScaleX_1920to512(68.0);
    return FFX_Menu2D_DrawTexQuadSolid(
             0xC8u,
             v18,
             v20,
             v6,
             v9,
             COERCE_INT(0.0009765625),
             COERCE_INT(0.76074219),
             COERCE_INT(0.067382812),
             COERCE_INT(0.8046875));
  }
  else if ( n5 == 4 )
  {
    sub_640F60(&n5, &n5_3);
    n5_2 = (float)n5;
    *((float *)&v14 + 1) = n5_2 * 0.001953125;
    n5_2 = (float)n5_3;
    n5_2 = n5_2 / 416.0;
    *((float *)&v14 + 1) = a1 / *((float *)&v14 + 1) + 256.0;
    v19 = *((float *)&v14 + 1) - FFX_Menu2D_ScaleX_1920to512(100.0);
    *((float *)&v14 + 1) = a2 / n5_2 + 208.0;
    *(float *)&v21 = *((float *)&v14 + 1) - FFX_Menu2D_ScaleY_1080to416(22.0);
    v10 = FFX_Menu2D_ScaleY_1080to416(45.0);
    v7 = FFX_Menu2D_ScaleX_1920to512(68.0);
    return FFX_Menu2D_DrawTexQuadSolid(
             0x190u,
             v19,
             v21,
             v7,
             v10,
             COERCE_INT(0.55273438),
             COERCE_INT(0.51074219),
             COERCE_INT(0.61914062),
             COERCE_INT(0.5546875));
  }
  else if ( n5 == 5 )
  {
    sub_640F60(&v13, (char *)&v12 + 4);
    *((float *)&v14 + 1) = (float)v13;
    n5_2 = *((float *)&v14 + 1) * 0.001953125;
    *((float *)&v14 + 1) = (float)SHIDWORD(v12);
    *(float *)&n5 = *((float *)&v14 + 1) / 416.0;
    *(float *)&n5 = a2 / *(float *)&n5 + 208.0;
    v14 = *(float *)&n5;
    v5 = FFX_Menu2D_ScaleY_1080to416(22.0);
    *(float *)&v22 = v14 - v5;
    v11 = FFX_Menu2D_ScaleY_1080to416(45.0);
    v8 = FFX_Menu2D_ScaleX_1920to512(68.0);
    *(float *)&n5 = a1 / n5_2 + 256.0;
    return FFX_Menu2D_DrawTexQuadSolid(
             0x190u,
             *(float *)&n5,
             v22,
             v8,
             v11,
             COERCE_INT(0.61914062),
             COERCE_INT(0.45214844),
             COERCE_INT(0.55273438),
             COERCE_INT(0.49609375));
  }
  return n5_1;
}
