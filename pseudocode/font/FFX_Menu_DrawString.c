/*
 * Function: FFX_Menu_DrawString
 * Address:   0x9016B0
 * Prototype: char __cdecl FFX_Menu_DrawString(int ctx, const char *str, float x, float y, char a5, float a6, float a7)
 *
 * Draws a menu string. Delegates to FFX_System_DisplaySplashLoad_structural
 * with default white color (128) and scale.
 *
 * Callees:
 *   FFX_System_DisplaySplashLoad_structural
 */

char __cdecl FFX_Menu_DrawString(int ctx, const char *str, float x, float y, char a5, float a6, float a7)
{
  return FFX_System_DisplaySplashLoad_structural(ctx, (char *)str, x, y, a5, 0, 128, 128, 128, 128, a6, a7);
}
