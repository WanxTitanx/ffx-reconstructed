/*
 * Function: FFX_TextLayout_RenderStringWithColor
 * Address:   0x8E92A0
 * Prototype: _DWORD *__cdecl FFX_TextLayout_RenderStringWithColor(
 *                _DWORD *a1, int a2, char *a3, int a4, int a5,
 *                char a6, char a7, char n128, char a9, char a10, char n128a)
 *
 * Core text layout rendering function. Parses text buffer, handles
 * character types (newlines, color codes, glyph rendering).
 * Uses atlas-based glyph rendering via FFX_Menu2D_DrawCharQuadWithColor.
 * Supports styled text wrapping (type 1/4).
 *
 * Text buffer types:
 *   1: Newline - advances Y by 16, resets X
 *   2: Character/glyph - draws via atlas, handles color codes (7, 10, 11)
 *   3: Parse buffer with color
 *   4: Styled text - layout + render with scaling
 *
 * Callees:
 *   memset, FFX_Save_MapBufferTypeToLayer, FFX_Save_AdvanceTextBufferPtr
 *   FFX_Font_StringWidthQuery, FFX_Font_CharWidthQuery
 *   FFX_Menu2D_DrawCharQuadWithColor
 *   FFX_Save_GetCharDisplayWidth
 *   FFX_TextLayout_ParseBufferWithColor
 *   FFX_EventText_LayoutString
 *   FFX_TextLayout_RenderType1 (jump thunk)
 *   FFX_TextLayout_RenderStyledWrap
 *   FFX_TextLayout_RenderStyledColorWrap
 *   FFX_TextLayout_DispatchSafeCall
 *   FFX_Graphics_DispatchInit
 *   FFX_TextLayout_ScaleAndOffsetPosition
 */

_DWORD *__cdecl FFX_TextLayout_RenderStringWithColor(
        _DWORD *a1,
        int a2,
        char *a3,
        int a4,
        int a5,
        char a6,
        char a7,
        char n128,
        char a9,
        char a10,
        char n128a)
{
  /* ... full string renderer with styled text support ... */
  return unk_187168C;
}
