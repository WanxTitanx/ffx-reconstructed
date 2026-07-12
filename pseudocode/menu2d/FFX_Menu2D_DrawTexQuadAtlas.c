/*
 * Function: FFX_Menu2D_DrawTexQuadAtlas
 * Address:   0x903EE0
 * Prototype: void __cdecl FFX_Menu2D_DrawTexQuadAtlas(FFXMenu2DContext *pCtx, void *pQuad)
 *
 * Draws a textured quad from an atlas. Handles multiple atlas contexts
 * via pCtx special values:
 *   -1: use title background atlas (16000, 2048x1024)
 *   -2: use ffx_bg atlas (16002, scale by 1/2048)
 *   -3: use menu_new atlas (16003, 2048x1024)
 *   -4: use stonetexture atlas (16004, 1024x1024, scale by 1/256)
 *   -6: use summonbg atlas (16006, 1024x1024)
 *   0-198: meswin atlas (15872, 256x256)
 *   200-398: meswin atlas (15872, ID-200)
 *   400-598: battle atlas (16128, ID-400)
 *   600-631: icon atlas (15808, ID-600, scale by 1/1024 or 1/512)
 *
 * Callees:
 *   FFX_Menu2D_GetAtlasDimensions_structural
 *   FFX_Menu2D_TexHandleByAtlasId
 *   FFX_Menu_RenderEnqueue
 *   FFX_Save_SystemSaveGame
 */

void __cdecl FFX_Menu2D_DrawTexQuadAtlas(FFXMenu2DContext *pCtx, void *pQuad)
{
  /* ... handles all atlas contexts with special scaling ... */
  FFX_Menu_RenderEnqueue((struct FFXMenu2DContext *)HIBYTE(v26));
}
