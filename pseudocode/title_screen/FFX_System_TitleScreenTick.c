/*
 * Function: FFX_System_TitleScreenTick
 * Address:   0x8FF3E0
 * Prototype: int __cdecl FFX_System_TitleScreenTick(unsigned __int8 *a1, int a2, int n32, int a4)
 *
 * Title screen tick handler. Draws save buffer progress bar
 * and menu string row.
 *
 * Callees:
 *   FFX_Save_BufferCountByType
 *   FFX_Menu2D_RenderSolidColorQuad
 *   FFX_Menu2D_RenderColorQuad
 *   FFX_Menu_DrawRowString
 */

int __cdecl FFX_System_TitleScreenTick(unsigned __int8 *a1, int a2, int n32, int a4)
{
  float v5; // [esp+8h] [ebp-8h] BYREF
  _WORD v6[2]; // [esp+Ch] [ebp-4h] BYREF

  FFX_Save_BufferCountByType(0, a1, &v5, v6, 0, 0);
  FFX_Menu2D_RenderSolidColorQuad(a2 + 4, n32 + 4, (int)(478.0 - v5), (__int16)unk_25D1642, 0, 0, 0, 128);
  FFX_Menu2D_RenderColorQuad(a2, n32, (int)(482.0 - v5), (__int16)unk_25D1642, unk_25D163C, unk_25D1638);
  return FFX_Menu_DrawRowString((int)a1, a2 + 15, n32 + 2, a4);
}
