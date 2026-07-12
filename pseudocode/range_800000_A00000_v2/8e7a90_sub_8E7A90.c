// Function: sub_8E7A90
// Address: 0x8e7a90
int __cdecl sub_8E7A90(int n609, float a2, int a3, float a4, unsigned int a5, unsigned int a6)
{
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st7
  float v12; // [esp+1Ch] [ebp-8h]
  float v13; // [esp+20h] [ebp-4h]
  float v14; // [esp+2Ch] [ebp+8h]
  float v15; // [esp+2Ch] [ebp+8h]
  float v16; // [esp+2Ch] [ebp+8h]
  float v17; // [esp+2Ch] [ebp+8h]
  float v18; // [esp+2Ch] [ebp+8h]
  float v19; // [esp+2Ch] [ebp+8h]
  float v20; // [esp+2Ch] [ebp+8h]
  float v21; // [esp+2Ch] [ebp+8h]
  float v22; // [esp+2Ch] [ebp+8h]
  float v23; // [esp+2Ch] [ebp+8h]

  v12 = 0.0;
  v13 = 0.0;
  v7 = a4;
  v8 = 0.5;
  if ( (unsigned int)(n609 - 600) <= 0xB )
  {
    v14 = (float)(int)(v7 * 54.0 + 0.5);
    v12 = FFX_Menu2D_ScaleX_1920to512(v14);
    v13 = FFX_Menu2D_ScaleY_1080to416(v14);
    if ( n113 == 184 && n609 == 609 )
    {
      if ( FFX_Game_GetRegion() == 11 )
      {
        v9 = a2 + 5.0;
LABEL_16:
        a2 = v9;
        return sub_8E6070(n609, a2, a3, v12, v13, a5, a6);
      }
      return sub_8E6070(n609, a2, a3, v12, v13, a5, a6);
    }
    v7 = a4;
    v8 = 0.5;
  }
  if ( (unsigned int)(n609 - 612) <= 3 )
  {
    v15 = (float)(int)(v8 + v7 * 64.0);
    v12 = FFX_Menu2D_ScaleX_1920to512(v15);
    v16 = (float)(int)(a4 * 40.0 + 0.5);
    v13 = FFX_Menu2D_ScaleY_1080to416(v16);
    v17 = a4 * 7.0;
    *(float *)&a3 = FFX_Menu2D_ScaleY_1080to416(v17) + *(float *)&a3;
  }
  if ( n609 == 616 )
  {
    v21 = 7.0 * a4;
    *(float *)&a3 = FFX_Menu2D_ScaleY_1080to416(v21) + *(float *)&a3;
    v22 = (float)(int)(a4 * 84.5 + 0.5);
    v12 = FFX_Menu2D_ScaleX_1920to512(v22);
    v23 = (float)(int)(a4 * 60.0 + 0.5);
    v13 = FFX_Menu2D_ScaleY_1080to416(v23);
    if ( n113 == 184 )
    {
      v10 = a2;
      if ( FFX_Game_GetRegion() == 11 )
        v9 = v10 + 2.5;
      else
        v9 = v10 - 2.5;
      goto LABEL_16;
    }
  }
  else if ( n609 == 617 )
  {
    v18 = a4 * 1.5;
    *(float *)&a3 = FFX_Menu2D_ScaleY_1080to416(v18) + *(float *)&a3;
    v19 = (float)(int)(a4 * 147.3999938964844 + 0.5);
    v12 = FFX_Menu2D_ScaleX_1920to512(v19);
    v20 = (float)(int)(a4 * 50.0 + 0.5);
    v13 = FFX_Menu2D_ScaleY_1080to416(v20);
  }
  return sub_8E6070(n609, a2, a3, v12, v13, a5, a6);
}
