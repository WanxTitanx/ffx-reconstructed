// FFX Menu: Draw row string styled
_DWORD *__cdecl FFX_Menu_DrawRowStringStyled(
        _DWORD *a1,
        unsigned __int8 *ib,
        int n2a,
        int n42,
        char a5,
        char n128,
        char a7,
        char a8,
        char n128a,
        int a10,
        int n4)
{
  unsigned __int8 *ib_1; // edi
  bool v12; // zf
  double v13; // st7
  double v14; // st7
  float n4_1; // [esp+Ch] [ebp+8h]
  float n4_2; // [esp+Ch] [ebp+8h]

  memset(gFontInfo, 0, 0x40u); /*0x8ed19d*/
  ib_1 = ib; /*0x8ed1a5*/
  MEMORY[0x25D09B8] = 0; /*0x8ed1b2*/
  n214 = (float)n2a; /*0x8ed1bc*/
  unk_25D09AC = 0.0; /*0x8ed1ca*/
  unk_25D09B0 = 0.0; /*0x8ed1cf*/
  unk_25D09B4 = 0; /*0x8ed1d4*/
  n355 = (float)n42; /*0x8ed1d9*/
  gDrawInfo[0] = n128; /*0x8ed1e2*/
  unk_25D09A1 = a7; /*0x8ed1ea*/
  unk_25D09A2 = a8; /*0x8ed1f2*/
  n128a = n128a; /*0x8ed1fa*/
  MEMORY[0x25D09BB] = a5; /*0x8ed20c*/
  v12 = *ib == 0; /*0x8ed211*/
  unk_187168C = a1; /*0x8ed214*/
  if ( v12 ) /*0x8ed21a*/
    return a1; /*0x8ed311*/
  do /*0x8ed2fe*/
  {
    FFX_MenuText_LayoutGlyphRecord(ib_1, (int)gFontInfo, a10); /*0x8ed22f*/
    if ( n4 <= 0 ) /*0x8ed239*/
    {
      FFX_TextLayout_RenderStyledColor((float *)gDrawInfo, gFontInfo, n4); /*0x8ed284*/
      FFX_TextLayout_RenderStyled((int *)gDrawInfo, (__int16 *)gFontInfo, n4); /*0x8ed294*/
    }
    else
    {
      n4_1 = (float)n4; /*0x8ed24a*/
      v13 = 100.0 / n4_1; /*0x8ed250*/
      unk_1841D2C = unk_1841D2C * v13; /*0x8ed25e*/
      unk_1841D30 = v13 * unk_1841D30; /*0x8ed26a*/
      FFX_TextLayout_RenderStyledColor((float *)gDrawInfo, gFontInfo, 4); /*0x8ed270*/
      FFX_TextLayout_RenderStyled((int *)gDrawInfo, (__int16 *)gFontInfo, 5); /*0x8ed277*/
    }
    if ( n4 <= 0 ) /*0x8ed29e*/
    {
      v14 = unk_1841D2C * UiElementScaleX + 1.0 + unk_1871698; /*0x8ed2e1*/
    }
    else
    {
      n4_2 = (float)n4; /*0x8ed2a3*/
      v14 = 100.0 / n4_2 * (unk_1871698 + 1.0) + unk_1841D2C * UiElementScaleX * 0.6000000238418579; /*0x8ed2cd*/
    }
    n214 = v14 + n214; /*0x8ed2ee*/
    ib_1 = FFX_Save_AdvanceTextBufferPtr(ib_1); /*0x8ed2f9*/
  }
  while ( *ib_1 ); /*0x8ed2fe*/
  return unk_187168C; /*0x8ed30e*/
}
