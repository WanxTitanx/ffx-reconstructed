/*
 * Function: FFX_Menu2D_DrawFormattedNumber
 * Address:   0x8ECDE0
 * Prototype: _DWORD *__cdecl FFX_Menu2D_DrawFormattedNumber(
 *                _DWORD *a1, int a2, int a3, int a4, int a5, char a6)
 *
 * Formats a number and renders it. Uses FFX_Menu2D_FormatNumberString
 * for string formatting, then renders with default white color (128).
 *
 * Callees:
 *   FFX_Menu2D_FormatNumberString
 *   FFX_TextLayout_RenderStringWithColor
 */

_DWORD *__cdecl FFX_Menu2D_DrawFormattedNumber(_DWORD *a1, int a2, int a3, int a4, int a5, char a6)
{
  char v7[32]; // [esp+0h] [ebp-24h] BYREF

  FFX_Menu2D_FormatNumberString(a3, v7, a2);
  return FFX_TextLayout_RenderStringWithColor(a1, -1, v7, a4, a5, a6, 0, 128, 128, 128, 128);
}
