// FFX EventText: Advance char glyph
unsigned __int8 *__cdecl FFX_EventText_AdvanceCharGlyph(unsigned __int8 *a1, int n3, float *a3, int CurrentTextSlot)
{
  unsigned __int8 *v4; // esi
  double v5; // st7
  int v6; // ecx
  int v7; // edx
  double font_scale_jimaku_1; // st7
  unsigned __int8 n0x2C; // bl
  int SlotGlyphMeta; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  double v17; // st7
  double v18; // st7
  unsigned __int8 *v19; // ecx
  double v20; // st7
  double v21; // st5
  unsigned __int8 n71; // al
  double GlyphOffsetScale; // [esp+10h] [ebp-1Ch]
  double v25; // [esp+10h] [ebp-1Ch]
  float v26; // [esp+18h] [ebp-14h]
  int b; // [esp+1Ch] [ebp-10h] BYREF
  int a; // [esp+20h] [ebp-Ch] BYREF
  unsigned __int8 *v29; // [esp+24h] [ebp-8h]
  int v30; // [esp+28h] [ebp-4h]
  float v31; // [esp+34h] [ebp+8h]
  float b_1; // [esp+34h] [ebp+8h]
  float v33; // [esp+34h] [ebp+8h]
  float v34; // [esp+34h] [ebp+8h]
  float font_scale_jimaku; // [esp+3Ch] [ebp+10h]

  v4 = a1; /*0x8b92e7*/
  v29 = a1; /*0x8b92f3*/
  FFX_Menu2D_GetNativeViewportSize1920x1080_structural(&a, &b); /*0x8b92f6*/
  v31 = (float)a; /*0x8b9301*/
  v5 = v31; /*0x8b9304*/
  b_1 = (float)b; /*0x8b930a*/
  v33 = v5 / b_1; /*0x8b9310*/
  v26 = v33 / 1.230769276618958; /*0x8b931c*/
  if ( (unsigned int)(FFX_Locale_GetCurrentId(v6) - 9) <= 1 && *v4 == 4 ) /*0x8b932f*/
  {
    v7 = 1; /*0x8b9331*/
    ++v4; /*0x8b9336*/
  }
  else
  {
    v7 = 0; /*0x8b9339*/
  }
  *a3 = 0.0; /*0x8b9346*/
  v30 = 1040 * v7; /*0x8b934b*/
  if ( n3 == 3 || n3 == 1 ) /*0x8b9356*/
    font_scale_jimaku_1 = ::font_scale_jimaku; /*0x8b9360*/
  else
    font_scale_jimaku_1 = 0.77999997; /*0x8b9358*/
  font_scale_jimaku = font_scale_jimaku_1; /*0x8b9367*/
  n0x2C = *v4; /*0x8b936a*/
  if ( *v4 >= 0x30u ) /*0x8b936f*/
  {
    SlotGlyphMeta = FFX_Font_GetSlotGlyphMeta(CurrentTextSlot); /*0x8b9374*/
    n0x2C = *v4; /*0x8b9379*/
    v30 = *v4 + v30 - 48; /*0x8b938b*/
    v33 = (double)*(char *)(SlotGlyphMeta + v30) * 0.25; /*0x8b93a4*/
  }
  if ( n0x2C >= 0x2Cu && n0x2C <= 0x2Fu ) /*0x8b93af*/
  {
    v12 = FFX_Font_GetSlotGlyphMeta(0); /*0x8b93b3*/
    n0x2C = *v4; /*0x8b93b8*/
    v33 = (double)*(char *)(v12 + 208 * *v4 + v4[1] + v30 - 8992) * 0.25; /*0x8b93ed*/
  }
  if ( n0x2C >= 0x2Au && n0x2C <= 0x2Bu ) /*0x8b93f8*/
  {
    v13 = FFX_Font_GetSlotGlyphMeta(1); /*0x8b93fc*/
    n0x2C = *v4; /*0x8b9401*/
    v33 = (double)*(char *)(v4[1] + v13 + 208 * *v4 - 8784) * 0.25; /*0x8b9431*/
  }
  if ( n0x2C >= 0x28u && n0x2C <= 0x29u ) /*0x8b943c*/
  {
    v14 = FFX_Font_GetSlotGlyphMeta(2); /*0x8b9440*/
    n0x2C = *v4; /*0x8b9445*/
    v33 = (double)*(char *)(v4[1] + v14 + 208 * *v4 - 8368) * 0.25; /*0x8b9475*/
  }
  if ( n0x2C >= 0x26u && n0x2C <= 0x27u ) /*0x8b9480*/
  {
    v15 = FFX_Font_GetSlotGlyphMeta(3); /*0x8b9484*/
    n0x2C = *v4; /*0x8b9489*/
    v33 = (double)*(char *)(v4[1] + v15 + 208 * *v4 - 7952) * 0.25; /*0x8b94b9*/
  }
  if ( n0x2C == 6 ) /*0x8b94c0*/
  {
    v16 = FFX_Font_GetSlotGlyphMeta(5); /*0x8b94c9*/
    if ( v16 ) /*0x8b94d0*/
      v17 = (double)*(char *)(v4[1] + v16 - 48) * 0.25; /*0x8b94e7*/
    else
      v17 = 56.0; /*0x8b94ef*/
    v33 = v17; /*0x8b94f5*/
  }
  if ( unk_18663AC ) /*0x8b950f*/
  {
    GlyphOffsetScale = FFX_Font_GetGlyphOffsetScale(v33, font_scale_jimaku); /*0x8b9516*/
    v18 = (FFX_Font_GetGlyphWidthScale(n3) + GlyphOffsetScale) * v26; /*0x8b9525*/
  }
  else
  {
    v25 = FFX_Font_GetGlyphOffsetScale(v33, font_scale_jimaku); /*0x8b952f*/
    v18 = FFX_Font_GetGlyphWidthScale(n3) + v25; /*0x8b953b*/
  }
  v19 = v29; /*0x8b953e*/
  v34 = v18; /*0x8b9541*/
  v20 = v34; /*0x8b9544*/
  if ( v34 <= 0.0 ) /*0x8b9553*/
  {
LABEL_41:
    n71 = *v4; /*0x8b9599*/
    if ( *v4 == 6 ) /*0x8b959d*/
      return v4 + 2; /*0x8b95a7*/
    if ( n71 < 0x30u ) /*0x8b95aa*/
    {
      v4 += 2; /*0x8b95d7*/
    }
    else
    {
      if ( *v19 != 71 || v4[1] != n71 ) /*0x8b95b4*/
        return v4 + 1; /*0x8b95d6*/
      if ( n71 == 71 ) /*0x8b95b8*/
      {
        do /*0x8b95c4*/
          ++v4; /*0x8b95c0*/
        while ( *v4 == 71 ); /*0x8b95c4*/
        return v4; /*0x8b95cd*/
      }
    }
    return v4; /*0x8b95db*/
  }
  if ( *v29 != 71 || v4[1] != *v4 ) /*0x8b955f*/
  {
    *a3 = v34; /*0x8b9593*/
    goto LABEL_41; /*0x8b9593*/
  }
  for ( ; *v4 == 71; *a3 = v21 ) /*0x8b9563*/
  {
    if ( CurrentTextSlot == 4 ) /*0x8b9571*/
      v21 = v20 * 2.0 + *a3; /*0x8b9577*/
    else
      v21 = *a3 + v20; /*0x8b957d*/
    ++v4; /*0x8b957f*/
  }
  return v4; /*0x8b958e*/
}