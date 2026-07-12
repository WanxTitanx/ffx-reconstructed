/*
 * Function: FFX_Title_DrawCopyrightScreen
 * Address:   0x904A70
 * Prototype: void __cdecl FFX_Title_DrawCopyrightScreen(int n272)
 *
 * Draws the copyright screen overlay.
 * Uses copyright_nagi.dds.phyre or copyright_nagi_NEA.dds.phyre
 * from /FFX_Data/GameData/PS3Data/menu/D3D11/
 * Color fade: fades in from 0 to 128 over 32 frames, then holds,
 * fades out after 272 frames.
 *
 * Callees:
 *   FFX_Locale_GetCurrentId
 *   FFX_Menu_RenderEnqueue
 *
 * Referenced strings:
 *   /FFX_Data/GameData/PS3Data/menu/D3D11/copyright_nagi.dds.phyre
 *   /FFX_Data/GameData/PS3Data/menu/D3D11/copyright_nagi_NEA.dds.phyre
 */

void __cdecl FFX_Title_DrawCopyrightScreen(int n272)
{
  int n128; // ecx
  struct FFXMenu2DContext *v2; // ecx

  if ( n272 >= 32 )
  {
    if ( n272 >= 272 )
      n128 = (n128 - 4) & ((n128 - 4 < 0) - 1);
    else
      n128 = 128;
    goto LABEL_7;
  }
  n128 = n128 + 4;
  n128 = n128;
  if ( n128 > 128 )
  {
    n128 = 128;
LABEL_7:
    n128 = n128;
  }
  FFX_Locale_GetCurrentId(n128);
  FFX_Menu_RenderEnqueue(v2);
}
