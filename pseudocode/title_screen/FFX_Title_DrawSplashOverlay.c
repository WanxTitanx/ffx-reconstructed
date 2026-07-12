/*
 * Function: FFX_Title_DrawSplashOverlay
 * Address:   0x907210
 * Prototype: int __cdecl FFX_Title_DrawSplashOverlay(int a1)
 *
 * Draws splash overlay with clip rect. Sets clip rect to 512x416
 * for menu rendering, or adjusts per-element.
 *
 * Callees:
 *   std::_Get_future_error_what (symbol lookup alias)
 *   FFX_Menu2D_SetClipRectWH
 *   FFX_Menu2D_SetClipRect4
 */

int __cdecl FFX_Title_DrawSplashOverlay(int a1)
{
  int v1; // esi
  float *future_error_what; // edi

  if ( n347 == 347 && 65.0 == *(float *)(a1 + 40) && 290.0 == *(float *)(a1 + 44) )
  {
    v1 = 0;
    while ( 1 )
    {
      future_error_what = (float *)std::_Get_future_error_what(v1);
      if ( 38.0 == future_error_what[10] && 115.0 == future_error_what[11] )
        break;
      if ( ++v1 >= 8 )
        goto LABEL_8;
    }
    FFX_Menu2D_SetClipRectWH(
      (int)(future_error_what[18] - 5.0),
      (int)future_error_what[19],
      (int)(future_error_what[20] - 0.0),
      (int)future_error_what[21]);
    return 0;
  }
  else
  {
LABEL_8:
    FFX_Menu2D_SetClipRect4(0, 0, 512, 416);
    return 0;
  }
}
