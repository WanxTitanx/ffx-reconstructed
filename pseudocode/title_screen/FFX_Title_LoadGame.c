/*
 * Function: FFX_Title_LoadGame
 * Address:   0x901280
 * Prototype: _DWORD *__cdecl FFX_Title_LoadGame(int n0x10, int a2, int a3, int a4)
 *
 * Loads a game save slot. Formats slot number as "%02d" and
 * draws each digit character using FFX_Menu2D_DrawAtlasQuad_FullSize
 * with atlas ID = digit + 442, advancing 16px per character.
 *
 * Callees:
 *   sprintf (format: "%02d")
 *   FFX_Menu2D_DrawAtlasQuad_FullSize
 *   FFX_Menu_PoolAllocatorB
 */

_DWORD *__cdecl FFX_Title_LoadGame(int n0x10, int a2, int a3, int a4)
{
  int i; // esi
  char n48; // al
  char Buffer[8]; // [esp+Ch] [ebp-Ch] BYREF

  sprintf(Buffer, "%02d", n0x10);
  for ( i = 0; i < 8; ++i )
  {
    n48 = Buffer[i];
    if ( !n48 )
      break;
    if ( n48 >= 48 && n48 <= 57 )
      FFX_Menu2D_DrawAtlasQuad_FullSize(n48 + 442, a2, a3, a4, a4);
    a2 += 16;
  }
  return FFX_Menu_PoolAllocatorB();
}
