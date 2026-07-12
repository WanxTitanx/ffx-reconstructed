// Function: sub_8E7110
// Address: 0x8e7110
int __cdecl sub_8E7110(int a1, float a2, float a3, char a4)
{
  int v4; // eax
  float v6; // [esp+4h] [ebp-10h]
  float v7; // [esp+24h] [ebp+10h]
  float v8; // [esp+24h] [ebp+10h]

  v7 = FFX_Menu2D_ScaleY_1080to416(10.0) + a3;
  v6 = v7;
  v8 = FFX_Menu2D_ScaleX_1920to512(160.0) + a2;
  v4 = sub_8AC800(a1);
  return FFX_Menu2D_DrawStatusEffectTimerBar(v4, v8, v6, a4, 0.81999999, COERCE_INT(1.0));
}
