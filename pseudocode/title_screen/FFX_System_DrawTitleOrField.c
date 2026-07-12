/*
 * Function: FFX_System_DrawTitleOrField
 * Address:   0x8E2B60
 * Prototype: int __cdecl FFX_System_DrawTitleOrField(int a1)
 *
 * Draws either title screen or field name overlay based on context.
 * Sets clip rect to 512x416 for menu rendering.
 * When alpha (a1+100) == 128, renders scene30 widget and location text.
 * Uses ScaleX_1920To512 / ScaleY_1080To416 for coordinate conversion.
 *
 * Callees:
 *   Menu_InitDrawBufferBoundaries
 *   FFX_Menu2D_SetClipRectCoord
 *   FFX_BtlUI_QueueDrawCommand
 *   FFX_SceneState_GetWord90, FFX_SceneState_GetWord91
 *   FFX_Menu_LoadLayerResourceByName
 *   FFX_Menu_WidgetSceneDispatch
 *   FFX_Menu2D_ScaleY_1080To416 / FFX_Menu2D_ScaleX_1920To512
 *   FFX_Menu2D_DrawTexQuadAtlas / FFX_Menu2D_DrawTexQuadSolid
 *   FFX_SceneState_GetFieldOrMenuWord
 *   FFX_ReturnZero
 *   FFX_Menu_ResolveIndexedTextByTable
 *   FFX_Menu_DrawString
 *   Menu_PoolAllocCallback
 */

int __cdecl FFX_System_DrawTitleOrField(int a1)
{
  int Word90; // edi
  int Word91; // eax
  int Word91_1; // esi
  int FieldOrMenuWord; // esi
  int v5; // eax
  char *str; // esi
  float pQuad; // [esp+0h] [ebp-30h]
  float v9; // [esp+8h] [ebp-28h]
  float x; // [esp+14h] [ebp-1Ch]
  float y; // [esp+18h] [ebp-18h]

  Menu_InitDrawBufferBoundaries();
  FFX_Menu2D_SetClipRectCoord(0, 0, 512, 416);
  FFX_BtlUI_QueueDrawCommand(0, 0, (*(_DWORD *)(a1 + 100) << 24) | 0x808080, (*(_DWORD *)(a1 + 100) << 24) | 0x808080);
  if ( *(_DWORD *)(a1 + 100) == 128 )
  {
    Word90 = FFX_SceneState_GetWord90();
    Word91 = FFX_SceneState_GetWord91();
    Word91_1 = Word91;
    if ( Word90 || Word91 )
    {
      FFX_Menu_LoadLayerResourceByName(1, "scene30");
      FFX_Menu_WidgetSceneDispatch(1, "scene30", Word90 / 2, Word91_1 / 2 - 16);
    }
    FFX_Menu2D_ScaleY_1080To416(55.0);
    FFX_Menu2D_ScaleX_1920To512(1130.0);
    FFX_Menu2D_ScaleY_1080To416(951.0);
    pQuad = FFX_Menu2D_ScaleX_1920To512(445.0);
    FFX_Menu2D_DrawTexQuadAtlas((FFXMenu2DContext *)0xFFFFFFFF, (void *)LODWORD(pQuad));
    FFX_Menu2D_ScaleY_1080To416(24.0);
    FFX_Menu2D_ScaleX_1920To512(360.0);
    FFX_Menu2D_ScaleY_1080To416(933.0);
    v9 = FFX_Menu2D_ScaleX_1920To512(445.0);
    FFX_Menu2D_DrawTexQuadSolid((FFXMenu2DContext *)0xC8, (void *)LODWORD(v9));
    FieldOrMenuWord = FFX_SceneState_GetFieldOrMenuWord();
    v5 = FFX_ReturnZero();
    str = FFX_Menu_ResolveIndexedTextByTable(FieldOrMenuWord, v5);
    y = FFX_Menu2D_ScaleY_1080To416(954.0);
    x = FFX_Menu2D_ScaleX_1920To512(535.0);
    FFX_Menu_DrawString(0, str, x, y, 0, 0.77999997, 1.0);
  }
  return Menu_PoolAllocCallback();
}
