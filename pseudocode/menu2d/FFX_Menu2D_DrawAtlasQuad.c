/*
 * Function: FFX_Menu2D_DrawAtlasQuad
 * Address:   0x8ED380
 * Prototype: int __cdecl FFX_Menu2D_DrawAtlasQuad(
 *                int a1, unsigned int n62, int a3, int a4,
 *                int a5, int a6, int a7, struct FFXMenu2DContext *a8)
 *
 * Core atlas quad drawing function. Routes atlas ID lookups through
 * multiple tables (sprite data, atlas base, pack data) based on ID ranges.
 * Handles UV coordinate calculation, aspect ratio adjustments, and
 * special edge cases for certain atlas IDs (480-490 range, 604-610 range).
 *
 * Atlas ID ranges:
 *   0-198:     sprite data from meswin atlas (15872)
 *   200-398:   sprite data from meswin atlas (15872), ID-200
 *   400-598:   atlas base from battle atlas (16128), ID-400
 *   600-649:   pack data from icon atlas (15808), ID-600
 *
 * Callees:
 *   FFX_Menu2D_TexHandleByAtlasId
 *   FFX_Menu2D_GetAtlasDimensions_structural
 *   FFX_Menu2D_TableLookupSpriteData
 *   FFX_Menu2D_TableLookupAtlasBase
 *   FFX_Menu2D_TableLookupPackData
 *   FFX_Menu2D_InitAtlasQuadCoords
 *   FFX_Menu_RenderEnqueue
 *   FFX_Save_SystemSaveGame
 */

int __cdecl FFX_Menu2D_DrawAtlasQuad(
        int a1,
        unsigned int n62,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        struct FFXMenu2DContext *a8)
{
  _DWORD *v8; // eax
  unsigned int n0xB; // ebx
  unsigned __int8 *v10; // esi
  unsigned int v11; // ecx
  unsigned int v12; // eax
  /* ... large function with UV calculations ... */
  return a1;
}
