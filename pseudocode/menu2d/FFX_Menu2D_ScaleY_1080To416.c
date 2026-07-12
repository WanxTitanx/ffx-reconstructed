/*
 * Function: FFX_Menu2D_ScaleY_1080To416
 * Address:   0x6449D0
 * Prototype: double __cdecl FFX_Menu2D_ScaleY_1080To416(float a1)
 *
 * Scales Y coordinate from 1080 to 416 internal resolution.
 * Formula: v * 416 / 1080
 *
 * This is the core scaling function for the menu rendering system.
 * The internal render buffer is 512x416, scaled from 1920x1080.
 */

double __cdecl FFX_Menu2D_ScaleY_1080To416(float a1)
{
  return (float)(a1 * 416.0 / 1080.0);
}
