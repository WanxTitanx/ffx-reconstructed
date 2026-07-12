/*
 * Function: FFX_Menu_DrawRowStringDefault
 * Address:   0x8ED0A0
 * Prototype: _DWORD *__cdecl FFX_Menu_DrawRowStringDefault(_DWORD *a1, char *a2, int a3, int a4, char a5)
 *
 * Default row string renderer. Delegates to FFX_TextLayout_RenderStringWithColor
 * with default white color (128).
 *
 * Callees:
 *   FFX_TextLayout_RenderStringWithColor
 */

_DWORD *__cdecl FFX_Menu_DrawRowStringDefault(_DWORD *a1, char *a2, int a3, int a4, char a5)
{
  return FFX_TextLayout_RenderStringWithColor(a1, -1, a2, a3, a4, a5, 0, 128, 128, 128, 128);
}
