// Function: sub_8E6CC0
// Address: 0x8e6cc0
void __cdecl sub_8E6CC0(float a1, int a2, float a3, float a4, int a5, int a6, int a7)
{
  double v7; // st7
  double v9; // st7
  double v10; // st6
  double v11; // st7
  float v12; // [esp+Ch] [ebp-24h]
  double v13; // [esp+18h] [ebp-18h]
  float v14; // [esp+20h] [ebp-10h]
  float v15; // [esp+24h] [ebp-Ch]
  float v16; // [esp+28h] [ebp-8h]
  float v17; // [esp+28h] [ebp-8h]
  int v18; // [esp+28h] [ebp-8h]
  float v19; // [esp+2Ch] [ebp-4h]
  float v20; // [esp+2Ch] [ebp-4h]
  float v21; // [esp+3Ch] [ebp+Ch]
  float v22; // [esp+3Ch] [ebp+Ch]
  float v23; // [esp+50h] [ebp+20h]
  float v24; // [esp+50h] [ebp+20h]
  float v25; // [esp+50h] [ebp+20h]

  v14 = FFX_Menu2D_ScaleX_1920to512(1.0) + a1;
  v16 = FFX_Menu2D_ScaleY_1080to416(1.0) + *(float *)&a2;
  v15 = a1 + a3 - FFX_Menu2D_ScaleX_1920to512(1.0);
  v13 = *(float *)&a2 + a4;
  v7 = FFX_Menu2D_ScaleY_1080to416(1.0);
  v19 = v13 - v7;
  if ( a7 > a6 )
  {
    v23 = (float)a7;
    v9 = v16;
    v17 = (v19 - v16) / v23;
    v24 = (float)a5;
    v10 = v9 + v24 * v17;
    v11 = v17;
    *(float *)&v18 = v10;
    v25 = (float)a6;
    v20 = v11 * v25 + *(float *)&v18;
    if ( a6 + a5 >= a7 )
      v20 = v13 - FFX_Menu2D_ScaleY_1080to416(1.0);
    FFX_Menu2D_DrawFilledRect(a1, a2, a3, a4, 0x801A1A1A, 0x801A1A1A);
    v21 = v20 - *(float *)&v18;
    v12 = v21;
    v22 = v15 - v14;
    FFX_Menu2D_DrawFilledRect(v14, v18, v22, v12, 0x80BBA09F, 0x80976C6F);
  }
}
