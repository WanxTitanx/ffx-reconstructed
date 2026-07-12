/*
 * Function: FFX_Menu_DrawRowString
 * Address:   0x901CB0
 * Prototype: _DWORD *__cdecl FFX_Menu_DrawRowString(char *a1, int a2, int a3, char a4)
 *
 * Draws a row string using the default renderer, then allocates
 * from the pool.
 *
 * Callees:
 *   FFX_Menu_DrawRowStringDefault
 *   FFX_Menu_PoolAllocatorB
 */

_DWORD *__cdecl FFX_Menu_DrawRowString(char *a1, int a2, int a3, char a4)
{
  unk_187168C = FFX_Menu_DrawRowStringDefault(unk_187168C, a1, a2, a3, a4);
  return FFX_Menu_PoolAllocatorB();
}
