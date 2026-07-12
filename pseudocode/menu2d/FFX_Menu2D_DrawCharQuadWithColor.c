/*
 * Function: FFX_Menu2D_DrawCharQuadWithColor
 * Address:   0x8E99A0
 * Prototype: _DWORD *__cdecl FFX_Menu2D_DrawCharQuadWithColor(
 *                _DWORD *a1, int n49_1, int n214, int n355,
 *                char n128, char a6, char a7, char n128a)
 *
 * Draws a character quad with color using atlas quads.
 * Handles special characters (0-15: button icons, 48-57: digits,
 * 96: backtick) via atlas IDs 0x258-0x270.
 * Special handling for safe color key mapping.
 *
 * Atlas ID ranges:
 *   0x258-0x25F: button icon parts
 *   0x260-0x270: digit/backtick quads
 *   n49 + 560:    standard digit mapping
 *
 * Callees:
 *   FFX_Menu2D_DrawAtlasQuad_FullSize
 *   FFX_Font_GetSafeColorKey
 */

_DWORD *__cdecl FFX_Menu2D_DrawCharQuadWithColor(
        _DWORD *a1,
        int n49_1,
        int n214,
        int n355,
        char n128,
        char a6,
        char a7,
        char n128a)
{
  int n49; // ebx
  int n214_1; // esi
  int v10; // esi
  int v12; // [esp-4h] [ebp-10h]

  n49 = n49_1;
  n214_1 = n214;
  unk_187168C = a1;
  if ( (unsigned int)(n49_1 - 64) <= 0xF )
  {
    v10 = (unsigned __int8)n128
        | (((unsigned __int8)a6 | (((unsigned __int8)a7 | ((unsigned __int8)n128a << 8)) << 8)) << 8);
    n49 = n49_1 & 0xF;
    if ( (n49_1 & 1) != 0 )
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x259u, n214, n355, v10, v10);
    else
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x258u, n214, n355, v10, v10);
    if ( (n49_1 & 2) != 0 )
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x25Bu, n214, n355, v10, v10);
    else
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x25Au, n214, n355, v10, v10);
    if ( (n49_1 & 4) != 0 )
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x25Du, n214, n355, v10, v10);
    else
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x25Cu, n214, n355, v10, v10);
    v12 = (unsigned __int8)n128
        | (((unsigned __int8)a6 | (((unsigned __int8)a7 | ((unsigned __int8)n128a << 8)) << 8)) << 8);
    n214_1 = n214;
    if ( (n49_1 & 8) != 0 )
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x25Fu, n214, n355, v12, v12);
    else
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x25Eu, n214, n355, v12, v12);
  }
  if ( (unsigned int)(n49 - 48) <= 9 )
  {
    if ( FFX_Font_GetSafeColorKey() == 1 && (unsigned int)(n49 - 49) <= 1 )
    {
      if ( n49 == 49 )
      {
        FFX_Menu2D_DrawAtlasQuad_FullSize(
          0x262u, n214_1, n355,
          (unsigned __int8)n128 | (((unsigned __int8)a6 | (((unsigned __int8)a7 | ((unsigned __int8)n128a << 8)) << 8)) << 8),
          (unsigned __int8)n128 | (((unsigned __int8)a6 | (((unsigned __int8)a7 | ((unsigned __int8)n128a << 8)) << 8)) << 8));
        return unk_187168C;
      }
      if ( n49 == 50 )
      {
        FFX_Menu2D_DrawAtlasQuad_FullSize(
          0x261u, n214_1, n355,
          (unsigned __int8)n128 | (((unsigned __int8)a6 | (((unsigned __int8)a7 | ((unsigned __int8)n128a << 8)) << 8)) << 8),
          (unsigned __int8)n128 | (((unsigned __int8)a6 | (((unsigned __int8)a7 | ((unsigned __int8)n128a << 8)) << 8)) << 8));
        return unk_187168C;
      }
    }
    else
    {
      FFX_Menu2D_DrawAtlasQuad_FullSize(
        n49 + 560, n214_1, n355,
        (unsigned __int8)n128 | (((unsigned __int8)a6 | (((unsigned __int8)a7 | ((unsigned __int8)n128a << 8)) << 8)) << 8),
        (unsigned __int8)n128 | (((unsigned __int8)a6 | (((unsigned __int8)a7 | ((unsigned __int8)n128a << 8)) << 8)) << 8));
    }
  }
  if ( n49 == 96 )
    FFX_Menu2D_DrawAtlasQuad_FullSize(
      0x270u, n214_1, n355,
      (unsigned __int8)n128 | (((unsigned __int8)a6 | (((unsigned __int8)a7 | ((unsigned __int8)n128a << 8)) << 8)) << 8),
      (unsigned __int8)n128 | (((unsigned __int8)a6 | (((unsigned __int8)a7 | ((unsigned __int8)n128a << 8)) << 8)) << 8));
  return unk_187168C;
}
