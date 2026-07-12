// Function: sub_8C0550
// Address: 0x8c0550
int __cdecl sub_8C0550(float a1, float a2, int a3)
{
  int result; // eax
  double v4; // st7
  float v5; // [esp+8h] [ebp-20h]
  float v6; // [esp+Ch] [ebp-1Ch]
  float v7; // [esp+24h] [ebp-4h]
  float v8; // [esp+30h] [ebp+8h]
  int v9; // [esp+34h] [ebp+Ch]

  result = sub_8A9C10();
  if ( (result & 2) == 0 || !a3 )
  {
    v4 = a1 - FFX_Menu2D_ScaleX_1920to512(68.0);
    v8 = v4;
    if ( !a3 )
    {
      FFX_Engine_GetTime();
      v7 = cos(v4 * 8.0);
      v8 = v7 * 3.0 + v8;
    }
    *(float *)&v9 = a2 - FFX_Menu2D_ScaleY_1080to416(0.0);
    v6 = FFX_Menu2D_ScaleY_1080to416(45.0);
    v5 = FFX_Menu2D_ScaleX_1920to512(68.0);
    return FFX_Menu2D_DrawTexQuadSolid(
             0xC8u,
             v8,
             v9,
             v5,
             v6,
             COERCE_INT(0.0009765625),
             COERCE_INT(0.76074219),
             COERCE_INT(0.067382812),
             COERCE_INT(0.8046875));
  }
  return result;
}
