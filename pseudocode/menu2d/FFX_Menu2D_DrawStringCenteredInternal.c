/*
 * Function: FFX_Menu2D_DrawStringCenteredInternal
 * Address:   0x8ED060
 * Prototype: _DWORD *__cdecl FFX_Menu2D_DrawStringCenteredInternal(_DWORD *a1, char *a2, int a3, int a4)
 *
 * Convenience wrapper for centered string rendering. Delegates to
 * FFX_TextLayout_RenderStringWithColor with default color (128,128,128,128).
 *
 * Callees:
 *   FFX_TextLayout_RenderStringWithColor
 */

_DWORD *__cdecl FFX_Menu2D_DrawStringCenteredInternal(_DWORD *a1, char *a2, int a3, int a4)
{
  return FFX_TextLayout_RenderStringWithColor(a1, 0, a2, a3, a4, 0, 0, 128, 128, 128, 128);
}
