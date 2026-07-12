/*
 * Function: FFX_Menu2D_DrawAtlasQuad_FullSize
 * Address:   0x903A50
 * Prototype: _DWORD *__cdecl FFX_Menu2D_DrawAtlasQuad_FullSize(
 *                unsigned int n62, int a2, int a3, int a4, struct FFXMenu2DContext *a5)
 *
 * Draws an atlas quad at full size (no width/height override).
 * Wraps FFX_Menu2D_DrawAtlasQuad with zero width/height params.
 *
 * Callees:
 *   FFX_Menu2D_DrawAtlasQuad
 *   FFX_Menu_PoolAllocatorB
 */

_DWORD *__cdecl FFX_Menu2D_DrawAtlasQuad_FullSize(
        unsigned int n62,
        int a2,
        int a3,
        int a4,
        struct FFXMenu2DContext *a5)
{
  unk_187168C = (_DWORD *)FFX_Menu2D_DrawAtlasQuad((int)unk_187168C, n62, a2, a3, 0, 0, a4, a5);
  return FFX_Menu_PoolAllocatorB();
}
