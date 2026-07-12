/*
 * Function: FFX_Menu2D_DrawTextBlockGradient
 * Address:   0x8EB150
 * Prototype: _DWORD *__cdecl FFX_Menu2D_DrawTextBlockGradient(_DWORD *a1, int a2, int a3, int a4)
 *
 * Draws a text block with gradient background. Packs command buffer
 * with header type 2, gradient data, and two glyph positions for
 * multi-line text rendering.
 *
 * Callees:
 *   FFX_Menu_PackHeader5
 *   FFX_Menu_Pack8Args71
 *   FFX_Menu_Pack4Ints
 *   FFX_Menu_PackFontGlyphPos
 */

_DWORD *__cdecl FFX_Menu2D_DrawTextBlockGradient(_DWORD *a1, int a2, int a3, int a4)
{
  *a1 = 2;
  a1[1] = 0x10000000;
  a1[2] = 14;
  a1[3] = 0;
  a1[4] = 556875264;
  a1[5] = 1074123782;
  a1[6] = 6;
  a1[7] = 0;
  a1[8] = &word_18762A0[3952304];
  a1[9] = &word_18762A0[806576];
  a1[10] = 64;
  a1[11] = 0;
  a1[12] = 32769;
  a1[13] = 1352876032;
  a1[14] = 279022;
  a1[15] = 0;
  unk_187168C = a1 + 16;
  FFX_Menu_PackHeader5(0, 1, 0, 1, 128);
  FFX_Menu_Pack8Args71(1, 7, 0, 0, 0, 0, 0, 0);
  FFX_Menu_Pack4Ints(0, 0, 0, 128);
  FFX_Menu_PackFontGlyphPos(a2, a3);
  FFX_Menu_PackFontGlyphPos(a2 + a4, a3 + 19);
  return unk_187168C;
}
