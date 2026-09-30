============================== 0x8FCCA0 ==============================
// FFX TextLayout: Render styled color
void __cdecl FFX_TextLayout_RenderStyledColor(float *a1, float *a2, int n4)
{
  char *Str_1; // eax
  char n3; // cl
  double font_scale_jimaku; // st7
  float v6; // esi
  float v7; // edx
  float v8; // ecx
  float v9; // eax
  double v10; // st6
  double v11; // st4
  double v12; // st4
  __int16 n15648; // [esp-8h] [ebp-CCh]
  unsigned __int8 v14; // [esp-4h] [ebp-C8h]
  __int16 x; // [esp+0h] [ebp-C4h]
  float v16; // [esp+18h] [ebp-ACh] BYREF
  char *Str; // [esp+1Ch] [ebp-A8h]
  float v18; // [esp+20h] [ebp-A4h] BYREF
  float font_scale_jimaku_1; // [esp+24h] [ebp-A0h]
  int ctx_; // [esp+28h] [ebp-9Ch] BYREF
  float v21; // [esp+2Ch] [ebp-98h] BYREF
  float v22; // [esp+30h] [ebp-94h] BYREF
  float v23[5]; // [esp+34h] [ebp-90h] BYREF
  float v24; // [esp+48h] [ebp-7Ch] BYREF
  float v25; // [esp+4Ch] [ebp-78h] BYREF
  float v26; // [esp+50h] [ebp-74h] BYREF
  float v27[25]; // [esp+54h] [ebp-70h] BYREF
  _DWORD v28[2]; // [esp+B8h] [ebp-Ch] BYREF

  x = *((_WORD *)a2 + 2); /*0x8fccc6*/
  v14 = *((_BYTE *)a1 + 27); /*0x8fcccb*/
  n15648 = *(_WORD *)a2; /*0x8fcccf*/
  v28[0] = 0; /*0x8fccd0*/
  v28[1] = 0; /*0x8fccd7*/
  Str_1 = FFX_Font_ResolveGlyphPagePath(n15648, v14, x, 1, v28); /*0x8fccde*/
  n3 = *((_BYTE *)a1 + 26); /*0x8fcce3*/
  Str = Str_1; /*0x8fcce9*/
  if ( n3 == 3 || n3 == 1 ) /*0x8fccf7*/
    font_scale_jimaku = font_scale_jimaku; /*0x8fcd01*/
  else
    font_scale_jimaku = 0.77999997; /*0x8fccf9*/
  font_scale_jimaku_1 = font_scale_jimaku; /*0x8fcd0d*/
  FFX_Font_ResolveSheetDims(*(__int16 *)a2, &v16, &v18); /*0x8fcd1f*/
  LODWORD(v6) = *(unsigned __int8 *)a1; /*0x8fcd24*/
  LODWORD(v7) = *((unsigned __int8 *)a1 + 1); /*0x8fcd30*/
  LODWORD(v8) = *((unsigned __int8 *)a1 + 2); /*0x8fcd3a*/
  *(float *)&ctx_ = a1[1] + UiFontShadowOffsetX; /*0x8fcd3e*/
  LODWORD(v9) = *((unsigned __int8 *)a1 + 3); /*0x8fcd47*/
  v10 = a2[6] * font_scale_jimaku_1; /*0x8fcd53*/
  v23[1] = v6; /*0x8fcd55*/
  v11 = a1[2]; /*0x8fcd5b*/
  v27[1] = v6; /*0x8fcd5e*/
  v27[23] = 0.0; /*0x8fcd6f*/
  LODWORD(v27[21]) = 2000; /*0x8fcd78*/
  v23[2] = v7; /*0x8fcd81*/
  v23[3] = v8; /*0x8fcd89*/
  v23[4] = v9; /*0x8fcd8f*/
  v21 = v10 + v11 + UiFontShadowOffsetY; /*0x8fcd92*/
  v27[2] = v7; /*0x8fcd98*/
  v12 = a2[2]; /*0x8fcd9b*/
  v27[3] = v8; /*0x8fcd9e*/
  v27[4] = v9; /*0x8fcda7*/
  v22 = v12 / v16; /*0x8fcdb0*/
  v23[0] = a2[3] / v18; /*0x8fcdc5*/
  v24 = UiFontShadowOffsetX + a2[7] * font_scale_jimaku_1 * UiElementScaleX + a1[1]; /*0x8fcddd*/
  v25 = UiFontShadowOffsetY + font_scale_jimaku_1 * (a2[8] + a2[6]) * UiElementScaleY + a1[2]; /*0x8fcdfb*/
  v26 = a2[4] / v16; /*0x8fce01*/
  v27[0] = a2[5] / v18; /*0x8fce07*/
  if ( n4 == 4 || FFX_Font_ClipGlyphQuadUVs((float *)&ctx_, &v21, &v24, &v25, &v22, v23, &v26, v27) ) /*0x8fce3b*/
    DrawUITextElement((FFXMenu2DContext *)&ctx_, Str, 2.0, 2.0, n4 + *((__int16 *)a2 + 2)); /*0x8fce6b*/
}
============================== 0x8FCAD0 ==============================
// FFX TextLayout: Render styled
void __cdecl FFX_TextLayout_RenderStyled(int *a1, float *a2, int n5)
{
  char *Str_1; // eax
  char n3; // cl
  double font_scale_jimaku; // st7
  float v6; // esi
  float v7; // edx
  float v8; // ecx
  float v9; // eax
  double v10; // st6
  int slot; // eax
  __int16 n15648; // [esp-8h] [ebp-CCh]
  unsigned __int8 v13; // [esp-4h] [ebp-C8h]
  __int16 x; // [esp+0h] [ebp-C4h]
  float v15; // [esp+18h] [ebp-ACh] BYREF
  char *Str; // [esp+1Ch] [ebp-A8h]
  float v17; // [esp+20h] [ebp-A4h] BYREF
  float font_scale_jimaku_1; // [esp+24h] [ebp-A0h]
  int ctx_; // [esp+28h] [ebp-9Ch] BYREF
  float v20; // [esp+2Ch] [ebp-98h] BYREF
  float v21; // [esp+30h] [ebp-94h] BYREF
  float v22[5]; // [esp+34h] [ebp-90h] BYREF
  float v23; // [esp+48h] [ebp-7Ch] BYREF
  float v24; // [esp+4Ch] [ebp-78h] BYREF
  float v25; // [esp+50h] [ebp-74h] BYREF
  float v26[25]; // [esp+54h] [ebp-70h] BYREF
  _DWORD v27[2]; // [esp+B8h] [ebp-Ch] BYREF

  x = *((_WORD *)a2 + 2); /*0x8fcaf6*/
  v13 = *((_BYTE *)a1 + 27); /*0x8fcafb*/
  n15648 = *(_WORD *)a2; /*0x8fcaff*/
  v27[0] = 0; /*0x8fcb00*/
  v27[1] = 0; /*0x8fcb07*/
  Str_1 = FFX_Font_ResolveGlyphPagePath(n15648, v13, x, 0, v27); /*0x8fcb0e*/
  n3 = *((_BYTE *)a1 + 26); /*0x8fcb13*/
  Str = Str_1; /*0x8fcb19*/
  if ( n3 == 3 || n3 == 1 ) /*0x8fcb27*/
    font_scale_jimaku = font_scale_jimaku; /*0x8fcb31*/
  else
    font_scale_jimaku = 0.77999997; /*0x8fcb29*/
  font_scale_jimaku_1 = font_scale_jimaku; /*0x8fcb3d*/
  FFX_Font_ResolveSheetDims(*(__int16 *)a2, &v15, &v17); /*0x8fcb4f*/
  LODWORD(v6) = *(unsigned __int8 *)a1; /*0x8fcb54*/
  ctx_ = a1[1]; /*0x8fcb5a*/
  LODWORD(v7) = *((unsigned __int8 *)a1 + 1); /*0x8fcb60*/
  LODWORD(v8) = *((unsigned __int8 *)a1 + 2); /*0x8fcb6f*/
  LODWORD(v9) = *((unsigned __int8 *)a1 + 3); /*0x8fcb78*/
  v20 = a2[6] * font_scale_jimaku_1 + *((float *)a1 + 2); /*0x8fcb87*/
  v10 = a2[2]; /*0x8fcb8d*/
  v26[23] = 0.0; /*0x8fcb90*/
  LODWORD(v26[21]) = 2000; /*0x8fcb9d*/
  v22[1] = v6; /*0x8fcba6*/
  v22[2] = v7; /*0x8fcbae*/
  v22[3] = v8; /*0x8fcbb4*/
  v22[4] = v9; /*0x8fcbba*/
  v26[1] = v6; /*0x8fcbbd*/
  v26[2] = v7; /*0x8fcbc0*/
  v26[3] = v8; /*0x8fcbc3*/
  v26[4] = v9; /*0x8fcbc6*/
  v21 = v10 / v15; /*0x8fcbcb*/
  v22[0] = a2[3] / v17; /*0x8fcbe0*/
  v23 = a2[7] * font_scale_jimaku_1 * UiElementScaleX + *((float *)a1 + 1); /*0x8fcbf4*/
  v24 = font_scale_jimaku_1 * (a2[8] + a2[6]) * UiElementScaleY + *((float *)a1 + 2); /*0x8fcc0e*/
  v25 = a2[4] / v15; /*0x8fcc14*/
  v26[0] = a2[5] / v17; /*0x8fcc1a*/
  if ( n5 == 5 ) /*0x8fcc1d*/
  {
    slot = *((__int16 *)a2 + 2) + 6; /*0x8fcc64*/
  }
  else
  {
    if ( !FFX_Font_ClipGlyphQuadUVs((float *)&ctx_, &v20, &v23, &v24, &v21, v22, &v25, v26) ) /*0x8fcc55*/
      return; /*0x8fcc55*/
    slot = *((__int16 *)a2 + 2) + 2; /*0x8fcc5b*/
  }
  DrawUITextElement((FFXMenu2DContext *)&ctx_, Str, 0.0, 0.0, slot); /*0x8fcc81*/
}
