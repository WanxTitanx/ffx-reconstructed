// FFX Menu2D: Draw char quad with color
_DWORD *__cdecl FFX_Menu2D_DrawCharQuadWithColor(
        _DWORD *a1,
        int n49,
        int n214,
        int n355,
        unsigned __int8 n128,
        unsigned __int8 a6,
        unsigned __int8 a7,
        unsigned __int8 n128a)
{
  int n49_1; // ebx
  int n214_1; // esi
  struct FFXMenu2DContext *v10; // esi
  struct FFXMenu2DContext *v12; // [esp-4h] [ebp-10h]

  n49_1 = n49; /*0x8e99a7*/
  n214_1 = n214; /*0x8e99ab*/
  unk_187168C = a1; /*0x8e99ae*/
  if ( (unsigned int)(n49 - 64) <= 0xF ) /*0x8e99bd*/
  {
    v10 = (struct FFXMenu2DContext *)(n128 + (a6 << 8) + (a7 << 16) + (n128a << 24)); /*0x8e99e0*/
    n49_1 = n49 & 0xF; /*0x8e99e7*/
    if ( (n49 & 1) != 0 ) /*0x8e99ef*/
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x259u, n214, n355, (int)v10, v10); /*0x8e99f6*/
    else
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x258u, n214, n355, (int)v10, v10); /*0x8e99fd*/
    if ( (n49 & 2) != 0 ) /*0x8e9a0e*/
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x25Bu, n214, n355, (int)v10, v10); /*0x8e9a15*/
    else
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x25Au, n214, n355, (int)v10, v10); /*0x8e9a1c*/
    if ( (n49 & 4) != 0 ) /*0x8e9a2d*/
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x25Du, n214, n355, (int)v10, v10); /*0x8e9a34*/
    else
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x25Cu, n214, n355, (int)v10, v10); /*0x8e9a3b*/
    v12 = (struct FFXMenu2DContext *)(n128 + (a6 << 8) + (a7 << 16) + (n128a << 24)); /*0x8e9a43*/
    n214_1 = n214; /*0x8e9a45*/
    if ( (n49 & 8) != 0 ) /*0x8e9a4d*/
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x25Fu, n214, n355, (int)v12, v12); /*0x8e9a54*/
    else
      FFX_Menu2D_DrawAtlasQuad_FullSize(0x25Eu, n214, n355, (int)v12, v12); /*0x8e9a5b*/
  }
  if ( (unsigned int)(n49_1 - 48) <= 9 ) /*0x8e9a69*/
  {
    if ( FFX_Font_GetSafeColorKey() == 1 && (unsigned int)(n49_1 - 49) <= 1 ) /*0x8e9a83*/
    {
      if ( n49_1 == 49 ) /*0x8e9a88*/
      {
        FFX_Menu2D_DrawAtlasQuad_FullSize( /*0x8e9ab2*/
          0x262u,
          n214_1,
          n355,
          n128 + (a6 << 8) + (a7 << 16) + (n128a << 24),
          (struct FFXMenu2DContext *)(n128 + (a6 << 8) + (a7 << 16) + (n128a << 24)));
        return unk_187168C; /*0x8e9ac3*/
      }
      if ( n49_1 == 50 ) /*0x8e9ac7*/
      {
        FFX_Menu2D_DrawAtlasQuad_FullSize( /*0x8e9af1*/
          0x261u,
          n214_1,
          n355,
          n128 + (a6 << 8) + (a7 << 16) + (n128a << 24),
          (struct FFXMenu2DContext *)(n128 + (a6 << 8) + (a7 << 16) + (n128a << 24)));
        return unk_187168C; /*0x8e9b02*/
      }
    }
    else
    {
      FFX_Menu2D_DrawAtlasQuad_FullSize( /*0x8e9b2d*/
        n49_1 + 560,
        n214_1,
        n355,
        n128 + (a6 << 8) + (a7 << 16) + (n128a << 24),
        (struct FFXMenu2DContext *)(n128 + (a6 << 8) + (a7 << 16) + (n128a << 24)));
    }
  }
  if ( n49_1 == 96 ) /*0x8e9b38*/
    FFX_Menu2D_DrawAtlasQuad_FullSize( /*0x8e9b62*/
      0x270u,
      n214_1,
      n355,
      n128 + (a6 << 8) + (a7 << 16) + (n128a << 24),
      (struct FFXMenu2DContext *)(n128 + (a6 << 8) + (a7 << 16) + (n128a << 24)));
  return unk_187168C; /*0x8e9abf*/
}