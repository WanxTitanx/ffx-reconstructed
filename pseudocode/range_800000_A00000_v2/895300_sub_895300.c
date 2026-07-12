// Function: sub_895300
// Address: 0x895300
unsigned int sub_895300()
{
  unsigned int n3; // eax
  double v1; // st7
  double v2; // st7
  double v3; // st7
  double v4; // st7
  float v5; // [esp+0h] [ebp-8h]
  float v6; // [esp+4h] [ebp-4h]

  if ( n2_5 == 2 )
  {
    n3 = sub_89BBF0();
    if ( n3 )
      ++n2_5;
  }
  else
  {
    n3 = n2_5 - 3;
    if ( n3 <= 3 )
    {
      sub_89BBF0();
      v6 = 535.0;
      if ( FFX_Game_GetRegion() )
      {
        FFX_Menu2D_ScaleY_1080to416(v6);
        v3 = FFX_Menu2D_ScaleX_1920to512(0.0);
        sub_89BEE0((int)v3);
        FFX_Menu2D_ScaleY_1080to416(535.0);
        v2 = 0.0;
      }
      else
      {
        FFX_Menu2D_ScaleY_1080to416(v6);
        v1 = FFX_Menu2D_ScaleX_1920to512(60.0);
        sub_89BEE0((int)v1);
        FFX_Menu2D_ScaleY_1080to416(535.0);
        v2 = 60.0;
      }
      v5 = v2;
      v4 = FFX_Menu2D_ScaleX_1920to512(v5);
      return sub_89C740((int)v4);
    }
  }
  return n3;
}
