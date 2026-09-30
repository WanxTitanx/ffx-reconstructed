// FFX TextLayout: Render string with color
_DWORD *__cdecl FFX_TextLayout_RenderStringWithColor(
        _DWORD *a1,
        int a2,
        char *a3,
        int n214_1,
        int n355,
        char a6,
        char a7,
        char n128,
        char a9,
        char a10,
        char n128a)
{
  unsigned __int8 *v11; // esi
  char v12; // al
  double font_scale_jimaku; // st7
  unsigned __int8 n0xE0; // al
  char v15; // al
  unsigned __int8 n0x40; // cl
  float font_scale_jimaku_1; // [esp+0h] [ebp-Ch]
  float n214; // [esp+14h] [ebp+8h]
  float v20; // [esp+20h] [ebp+14h]
  float CharDisplayWidth; // [esp+20h] [ebp+14h]

  memset(gFontInfo, 0, 0x40u); /*0x8e92ae*/
  v11 = (unsigned __int8 *)a3; /*0x8e92bb*/
  MEMORY[0x25D09B8] = 0; /*0x8e92c3*/
  unk_25D09AC = 0.0; /*0x8e92d2*/
  unk_25D09B0 = 0.0; /*0x8e92d7*/
  unk_25D09B4 = 0; /*0x8e92dc*/
  unk_187168C = a1; /*0x8e92e4*/
  n214 = (float)n214_1; /*0x8e92e9*/
  unk_25D09A1 = a9; /*0x8e92f2*/
  unk_25D09A2 = a10; /*0x8e9300*/
  n214 = n214; /*0x8e9305*/
  ::n128a = n128a; /*0x8e9311*/
  MEMORY[0x25D09BA] = a7; /*0x8e9319*/
  n355 = (float)n355; /*0x8e931e*/
  gDrawInfo[0] = n128; /*0x8e9327*/
  MEMORY[0x25D09BB] = a6; /*0x8e932d*/
  v12 = *a3; /*0x8e9332*/
  if ( *a3 ) /*0x8e9332*/
  {
    do /*0x8e9524*/
    {
      switch ( FFX_Save_MapBufferTypeToLayer(v12) ) /*0x8e9353*/
      {
        case 1: /*0x8e9353*/
          n214 = n214; /*0x8e93f7*/
          n355 = n355 + 16.0; /*0x8e9409*/
          break; /*0x8e940f*/
        case 2: /*0x8e9353*/
          if ( *v11 == 7 ) /*0x8e9418*/
          {
            n0xE0 = v11[1]; /*0x8e941a*/
            if ( n0xE0 > 0xE0u && n0xE0 < 0xF0u ) /*0x8e9427*/
            {
              v20 = (float)(n0xE0 - 224); /*0x8e943b*/
              n214 = v20 + n214; /*0x8e9447*/
            }
          }
          else
          {
            if ( *v11 == 10 ) /*0x8e9454*/
            {
              v15 = MEMORY[0x25D09BB]; /*0x8e9459*/
              if ( (v11[1] & 0xF) != 0 ) /*0x8e9461*/
              {
                v15 = ((v11[1] & 0xF) - 1) | MEMORY[0x25D09BB] & 0xF0; /*0x8e9467*/
                MEMORY[0x25D09BB] = v15; /*0x8e9469*/
              }
              n0x40 = v11[1] & 0xF0; /*0x8e9471*/
              if ( n0x40 >= 0x40u ) /*0x8e9477*/
                MEMORY[0x25D09BB] = (n0x40 - 64) | v15 & 0xF; /*0x8e9480*/
            }
            if ( *v11 == 11 ) /*0x8e9488*/
            {
              FFX_Font_StringWidthQuery(v11[1], -1); /*0x8e9491*/
              unk_187168C = FFX_Menu2D_DrawCharQuadWithColor( /*0x8e94cb*/
                              unk_187168C,
                              v11[1],
                              (int)n214,
                              (int)n355,
                              n128,
                              a9,
                              a10,
                              n128a);
              CharDisplayWidth = (float)FFX_Save_GetCharDisplayWidth(v11[1]); /*0x8e94e3*/
              n214 = CharDisplayWidth * UiElementScaleX + n214; /*0x8e94f5*/
            }
            FFX_Font_CharWidthQuery(); /*0x8e94fb*/
          }
          break; /*0x8e944d*/
        case 3: /*0x8e9353*/
          if ( a2 != -1 ) /*0x8e9506*/
            FFX_TextLayout_ParseBufferWithColor(a2, v11, (int)gDrawInfo); /*0x8e9511*/
          break; /*0x8e9511*/
        case 4: /*0x8e9353*/
          FFX_EventText_LayoutString(v11, (int)gFontInfo); /*0x8e9360*/
          if ( MEMORY[0x25D09BA] == 1 ) /*0x8e936f*/
          {
            TOMakePktFont1612Edge(gDrawInfo, gFontInfo); /*0x8e937b*/
            FFX_TextLayout_RenderStyledWrap((int *)gDrawInfo, gFontInfo); /*0x8e938a*/
            font_scale_jimaku = font_scale_jimaku; /*0x8e938f*/
          }
          else
          {
            FFX_TextLayout_DispatchSafeCall(1); /*0x8e93b1*/
            FFX_Graphics_DispatchInit(0); /*0x8e93b8*/
            FFX_TextLayout_RenderStyledColorWrap((float *)gDrawInfo, gFontInfo); /*0x8e93c7*/
            FFX_Graphics_DispatchInit(1); /*0x8e93ce*/
            FFX_TextLayout_RenderStyledWrap((int *)gDrawInfo, gFontInfo); /*0x8e93dd*/
            FFX_TextLayout_DispatchSafeCall(0); /*0x8e93e4*/
            font_scale_jimaku = 0.77999997; /*0x8e93e9*/
          }
          font_scale_jimaku_1 = font_scale_jimaku; /*0x8e9398*/
          FFX_TextLayout_ScaleAndOffsetPosition((int)gDrawInfo, (int)gFontInfo, font_scale_jimaku_1); /*0x8e93a5*/
          break; /*0x8e93aa*/
        default:
          break;
      }
      v11 = FFX_Save_AdvanceTextBufferPtr(v11); /*0x8e9519*/
      v12 = *v11; /*0x8e9524*/
    }
    while ( *v11 ); /*0x8e9524*/
  }
  return unk_187168C; /*0x8e9533*/
}