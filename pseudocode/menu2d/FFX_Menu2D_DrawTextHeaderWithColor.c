/*
 * Function: FFX_Menu2D_DrawTextHeaderWithColor
 * Address:   0x8E9E00
 * Prototype: _DWORD *__cdecl FFX_Menu2D_DrawTextHeaderWithColor(
 *                _DWORD *a1, int a2, int a3, int a4,
 *                char n128, char a6, char a7, char a8)
 *
 * Draws a text header with color using the menu command buffer.
 * Packs header type 32769 with position offsets for two-line
 * layout (64,0 and 98,18 for non-centered; 98,0 and 64,18 for centered).
 *
 * Callees:
 *   FFX_Menu_PackHeader5
 *   FFX_Menu_Pack4Ints
 *   FFX_Menu_PackPositionOffset
 *   FFX_Menu_PackFontGlyphPos
 */

_DWORD *__cdecl FFX_Menu2D_DrawTextHeaderWithColor(
        _DWORD *a1,
        int a2,
        int a3,
        int a4,
        char n128,
        char a6,
        char a7,
        char a8)
{
  _DWORD *v8; // eax

  *a1 = 32769;
  a1[1] = -2135998464;
  a1[2] = 1128472302;
  a1[3] = 0;
  unk_187168C = a1 + 4;
  FFX_Menu_PackHeader5(0, 1, 0, 1, 128);
  v8 = unk_187168C + 8;
  *unk_187168C = 15;
  *(v8 - 7) = 0;
  *(v8 - 6) = 71;
  *(v8 - 5) = 0;
  *(v8 - 4) = 556875264;
  *(v8 - 3) = 1074123782;
  *(v8 - 2) = 6;
  *(v8 - 1) = 0;
  unk_187168C = v8;
  FFX_Menu_Pack4Ints((unsigned __int8)n128, (unsigned __int8)a6, (unsigned __int8)a7, (unsigned __int8)a8);
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      FFX_Menu_PackPositionOffset(98, 0);
      FFX_Menu_PackFontGlyphPos(a2, a3);
      FFX_Menu_PackPositionOffset(64, 18);
      FFX_Menu_PackFontGlyphPos(a2 + 34, a3 + 18);
    }
    return unk_187168C;
  }
  else
  {
    FFX_Menu_PackPositionOffset(64, 0);
    FFX_Menu_PackFontGlyphPos(a2 - 36, a3);
    FFX_Menu_PackPositionOffset(98, 18);
    FFX_Menu_PackFontGlyphPos(a2 - 2, a3 + 18);
    return unk_187168C;
  }
}
