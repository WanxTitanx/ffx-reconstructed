// Function: sub_8A0B30
// Address: 0x8a0b30
int __cdecl sub_8A0B30(int n6, int a2, int a3)
{
  int v3; // esi
  double v4; // st7
  float v6; // [esp+4h] [ebp-1Ch]
  float v7; // [esp+8h] [ebp-18h]
  float v8; // [esp+Ch] [ebp-14h]
  int v9; // [esp+10h] [ebp-10h]
  int v10; // [esp+18h] [ebp-8h] BYREF
  float v11; // [esp+1Ch] [ebp-4h]
  float v12; // [esp+2Ch] [ebp+Ch]
  int v13; // [esp+30h] [ebp+10h]
  int v14; // [esp+30h] [ebp+10h]
  float v15; // [esp+30h] [ebp+10h]

  *(float *)&v13 = (float)a3;
  v12 = (float)a2;
  v8 = FFX_Menu2D_ScaleY_1080to416(114.0);
  v7 = FFX_Menu2D_ScaleX_1920to512(344.0);
  FFX_Menu2D_DrawRoundedPanel9Slice(v12, v13, v7, v8, 0);
  v3 = sub_897660(n6);
  sub_905290(v3, (int)&v10, 0, 0.80000001);
  v11 = FFX_Menu2D_ScaleY_1080to416(16.0) + *(float *)&v13;
  v6 = v11;
  v4 = FFX_Menu2D_ScaleX_1920to512(344.0);
  v11 = (v4 - *(float *)&v10) * 0.5 + v12;
  FFX_Menu2D_DrawStatusEffectTimerBar(v3, v11, v6, 0, 0.69999999, COERCE_INT(1.0));
  *(float *)&v14 = FFX_Menu2D_ScaleY_1080to416(61.0) + *(float *)&v13;
  v9 = v14;
  v15 = FFX_Menu2D_ScaleX_1920to512(15.0) + v12;
  return sub_892C20(n6, v15, v9);
}
