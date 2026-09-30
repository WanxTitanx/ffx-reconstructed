// FFX TextLayout: Render type 1
void __cdecl FFX_TextLayout_RenderType1(float *dst, float *gFontInfo)
{
  char *text; // edi
  double v3; // st7
  char n3; // al
  double font_scale_jimaku; // st7
  float v6; // esi
  float v7; // edx
  float v8; // ecx
  double v9; // st7
  double v10; // st6
  double v11; // st7
  int i; // esi
  int v13; // eax
  __int16 n15648; // [esp-8h] [ebp-E8h]
  unsigned __int8 v15; // [esp-4h] [ebp-E4h]
  __int16 x; // [esp+0h] [ebp-E0h]
  float y; // [esp+4h] [ebp-DCh]
  float v18; // [esp+18h] [ebp-C8h] BYREF
  float v19; // [esp+1Ch] [ebp-C4h] BYREF
  float *dst_1; // [esp+20h] [ebp-C0h]
  float v21; // [esp+24h] [ebp-BCh]
  double v22; // [esp+28h] [ebp-B8h]
  int ctx_; // [esp+30h] [ebp-B0h] BYREF
  float v24; // [esp+34h] [ebp-ACh] BYREF
  float v25; // [esp+38h] [ebp-A8h] BYREF
  float v26[4]; // [esp+3Ch] [ebp-A4h] BYREF
  float v27; // [esp+4Ch] [ebp-94h]
  float v28; // [esp+50h] [ebp-90h] BYREF
  float v29; // [esp+54h] [ebp-8Ch] BYREF
  float v30; // [esp+58h] [ebp-88h] BYREF
  float v31[25]; // [esp+5Ch] [ebp-84h] BYREF
  _DWORD v32[2]; // [esp+C0h] [ebp-20h] BYREF
  _DWORD v33[5]; // [esp+C8h] [ebp-18h]

  x = *((_WORD *)gFontInfo + 2); /*0x8fc896*/
  v15 = *((_BYTE *)dst + 27); /*0x8fc89b*/
  n15648 = *(_WORD *)gFontInfo; /*0x8fc89f*/
  dst_1 = dst; /*0x8fc8a0*/
  v33[0] = -33489154; /*0x8fc8a6*/
  v33[1] = &unk_FFFE02; /*0x8fc8ad*/
  v33[2] = 65790; /*0x8fc8b4*/
  v33[3] = 50200578; /*0x8fc8bb*/
  v33[4] = &unk_2020200; /*0x8fc8c2*/
  v32[0] = 0; /*0x8fc8c9*/
  v32[1] = 0; /*0x8fc8d0*/
  text = FFX_Font_DrawText(n15648, v15, x, 1, v32); /*0x8fc8df*/
  v3 = FFX_Screen_AspectRatioClamped(); /*0x8fc8e1*/
  n3 = *((_BYTE *)dst + 26); /*0x8fc8e6*/
  v21 = v3; /*0x8fc8e9*/
  if ( n3 == 3 || n3 == 1 ) /*0x8fc8f5*/
    font_scale_jimaku = font_scale_jimaku; /*0x8fc8ff*/
  else
    font_scale_jimaku = 0.77999997; /*0x8fc8f7*/
  *((float *)&v22 + 1) = font_scale_jimaku; /*0x8fc90b*/
  FFX_Menu2D_GetAtlasDimensions_structural(*(__int16 *)gFontInfo, &v19, &v18); /*0x8fc91d*/
  LODWORD(v6) = *(unsigned __int8 *)dst; /*0x8fc928*/
  LODWORD(v7) = *((unsigned __int8 *)dst_1 + 1); /*0x8fc92b*/
  LODWORD(v8) = *((unsigned __int8 *)dst_1 + 2); /*0x8fc92f*/
  LODWORD(v27) = *((unsigned __int8 *)dst_1 + 3); /*0x8fc937*/
  v31[4] = v27; /*0x8fc93d*/
  v31[23] = 0.0; /*0x8fc946*/
  LODWORD(v31[21]) = 2000; /*0x8fc94d*/
  v26[1] = v6; /*0x8fc954*/
  v9 = dst_1[1]; /*0x8fc95a*/
  v26[2] = v7; /*0x8fc95d*/
  *(float *)&ctx_ = v9; /*0x8fc963*/
  v26[3] = v8; /*0x8fc969*/
  v31[1] = v6; /*0x8fc975*/
  v31[2] = v7; /*0x8fc97a*/
  v10 = *((float *)&v22 + 1) * gFontInfo[6]; /*0x8fc97d*/
  v31[3] = v8; /*0x8fc980*/
  v24 = v10 + dst_1[2]; /*0x8fc986*/
  v25 = gFontInfo[2] / v19; /*0x8fc99b*/
  v26[0] = gFontInfo[3] / v18; /*0x8fc9b0*/
  v28 = gFontInfo[7] * *((float *)&v22 + 1) + dst_1[1]; /*0x8fc9be*/
  v29 = *((float *)&v22 + 1) * (gFontInfo[8] + gFontInfo[6]) + dst_1[2]; /*0x8fc9e7*/
  v30 = gFontInfo[4] / v19; /*0x8fca14*/
  v31[0] = gFontInfo[5] / v18; /*0x8fca1d*/
  if ( FFX_Save_SystemSaveGame((float *)&ctx_, &v24, &v28, &v29, &v25, v26, &v30, v31) ) /*0x8fca23*/
  {
    v11 = v21; /*0x8fca33*/
    for ( i = 0; i < 10; ++i ) /*0x8fca39*/
    {
      HIDWORD(v22) = *((char *)v33 + 2 * i + 1); /*0x8fca40*/
      v22 = (double)SHIDWORD(v22); /*0x8fca51*/
      v13 = *((char *)v33 + 2 * i); /*0x8fca5d*/
      *((float *)&v22 + 1) = v22 / v11; /*0x8fca64*/
      y = *((float *)&v22 + 1); /*0x8fca70*/
      v22 = (double)v13; /*0x8fca86*/
      *((float *)&v22 + 1) = v22 / v11; /*0x8fca92*/
      DrawUITextElement((FFXMenu2DContext *)&ctx_, text, *((float *)&v22 + 1), y, 0); /*0x8fcaa3*/
      v11 = v21; /*0x8fcaa8*/
    }
  }
}