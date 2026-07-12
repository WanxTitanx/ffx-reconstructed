// Function: sub_89F070
// Address: 0x89f070
int __cdecl sub_89F070(int n6, int a2, int a3)
{
  int v4; // esi
  double v5; // st7
  float v7; // [esp+4h] [ebp-20h]
  float v8; // [esp+4h] [ebp-20h]
  float v9; // [esp+4h] [ebp-20h]
  float v10; // [esp+8h] [ebp-1Ch]
  float v11; // [esp+8h] [ebp-1Ch]
  float v12; // [esp+8h] [ebp-1Ch]
  float v13; // [esp+8h] [ebp-1Ch]
  float v14; // [esp+Ch] [ebp-18h]
  float v15; // [esp+Ch] [ebp-18h]
  float v16; // [esp+Ch] [ebp-18h]
  int v17; // [esp+14h] [ebp-10h]
  int v18; // [esp+20h] [ebp-4h] BYREF
  float v19; // [esp+2Ch] [ebp+8h]
  float v20; // [esp+2Ch] [ebp+8h]
  float v21; // [esp+2Ch] [ebp+8h]
  float v22; // [esp+2Ch] [ebp+8h]
  float v23; // [esp+2Ch] [ebp+8h]
  float v24; // [esp+2Ch] [ebp+8h]
  float v25; // [esp+2Ch] [ebp+8h]
  float v26; // [esp+2Ch] [ebp+8h]
  float v27; // [esp+30h] [ebp+Ch]
  float v28; // [esp+34h] [ebp+10h]
  int v29; // [esp+34h] [ebp+10h]
  float v30; // [esp+34h] [ebp+10h]

  if ( n6 < 8 )
  {
    if ( n6 == 6 && sub_86C400() < 1076 )
    {
      v28 = (float)a3;
      v27 = (float)a2;
      v15 = FFX_Menu2D_ScaleY_1080to416(50.0);
      v11 = FFX_Menu2D_ScaleX_1920to512(70.0);
      v21 = FFX_Menu2D_ScaleY_1080to416(14.0) + v28;
      v8 = v21;
      v22 = FFX_Menu2D_ScaleX_1920to512(20.0) + v27;
      sub_9034B0(468, 0, v22, v8, v11, v15, -2139062144, -2139062144);
    }
    else
    {
      v28 = (float)a3;
      v27 = (float)a2;
      v16 = FFX_Menu2D_ScaleY_1080to416(50.0);
      v12 = FFX_Menu2D_ScaleX_1920to512(70.0);
      v23 = FFX_Menu2D_ScaleY_1080to416(14.0) + v28;
      v9 = v23;
      v24 = FFX_Menu2D_ScaleX_1920to512(20.0) + v27;
      sub_9034B0(n6 + 440, 0, v24, v9, v12, v16, -2139062144, -2139062144);
    }
  }
  else
  {
    v28 = (float)a3;
    v27 = (float)a2;
    v14 = FFX_Menu2D_ScaleY_1080to416(50.0);
    v10 = FFX_Menu2D_ScaleX_1920to512(70.0);
    v19 = FFX_Menu2D_ScaleY_1080to416(14.0) + v28;
    v7 = v19;
    v20 = FFX_Menu2D_ScaleX_1920to512(20.0) + v27;
    sub_9034B0(448, 0, v20, v7, v10, v14, -2139062144, -2139062144);
  }
  v4 = sub_897660(n6);
  sub_905290(v4, (int)&v18, 0, 0.70999998);
  v25 = FFX_Menu2D_ScaleY_1080to416(16.0) + v28;
  v13 = v25;
  v5 = FFX_Menu2D_ScaleX_1920to512(210.0);
  v26 = v5 + v27 - *(float *)&v18 * 0.5;
  FFX_Menu2D_DrawStatusEffectTimerBar(v4, v26, v13, 0, 0.70999998, COERCE_INT(1.0));
  *(float *)&v29 = FFX_Menu2D_ScaleY_1080to416(62.0) + v28;
  v17 = v29;
  v30 = FFX_Menu2D_ScaleX_1920to512(12.0) + v27;
  return sub_892C20(n6, v30, v17);
}
