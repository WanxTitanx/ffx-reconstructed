/*
 * Function: FFX_Menu2D_ScaleX_1920To512
 * Address:   0x644990
 * Prototype: double __cdecl FFX_Menu2D_ScaleX_1920To512(float a1)
 *
 * Scales X coordinate from 1920 to 512 internal resolution.
 * Formula: v * 512 / 1920
 *
 * This is the core scaling function for the menu rendering system.
 * The internal render buffer is 512x416, scaled from 1920x1080.
 */

double __cdecl FFX_Menu2D_ScaleX_1920To512(float a1)
{
  return (float)(a1 * 512.0 / 1920.0);
}
