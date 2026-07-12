/*
 * Function: FFX_Menu2D_TitleBarDraw
 * Address:   0x8A7D70
 * Prototype: int __cdecl FFX_Menu2D_TitleBarDraw(int a1)
 *
 * Draws the menu title bar with animated highlighting effect on
 * menu item slots (52px each, max 3 items = 156px). Uses generic
 * atlas quad drawing for textured bars and highlights.
 *
 * Callees:
 *   FFX_Engine_GetFrameDeltaTime_Bridge
 *   FFX_Menu2D_ScaleY_1080To416, FFX_Menu2D_ScaleX_1920To512
 *   FFX_Menu2D_DrawTexQuadAtlas
 *   FFX_Menu2D_DrawAtlasQuadGeneric
 *   FFX_EscMenu_Update
 *   Menu2D_RegisterAnimationSlot
 *   FFX_Menu2D_DrawAbilityDetailPanel
 */

int __cdecl FFX_Menu2D_TitleBarDraw(int a1)
{
  double v1; // st7
  int v2; // esi
  double v3; // st7
  double v4; // st6
  double v5; // st5
  int n156; // edi
  double v7; // st4
  double v8; // st3
  double v9; // st7
  int v10; // edi
  double v11; // st6
  int n156_1; // esi
  double v13; // st5
  double v14; // st4
  double v15; // st3
  int v16; // eax
  int v17; // edi
  int v18; // esi
  double v20; // st7
  float v22; // [esp+0h] [ebp-5Ch]
  float v23; // [esp+0h] [ebp-5Ch]
  float v24; // [esp+0h] [ebp-5Ch]
  float v25; // [esp+0h] [ebp-5Ch]
  int v26; // [esp+4h] [ebp-58h]
  int v27; // [esp+4h] [ebp-58h]
  int v28; // [esp+4h] [ebp-58h]
  int v29; // [esp+4h] [ebp-58h]
  float pQuad; // [esp+8h] [ebp-54h]
  float pQuada; // [esp+8h] [ebp-54h]
  float pQuadb; // [esp+8h] [ebp-54h]
  float pQuadc; // [esp+8h] [ebp-54h]
  float pQuadd; // [esp+8h] [ebp-54h]
  float pQuade; // [esp+8h] [ebp-54h]
  float pQuadf; // [esp+8h] [ebp-54h]
  float v37; // [esp+Ch] [ebp-50h]
  float v38; // [esp+Ch] [ebp-50h]
  float v39; // [esp+Ch] [ebp-50h]
  float v40; // [esp+Ch] [ebp-50h]
  float v41; // [esp+18h] [ebp-44h]
  float v42; // [esp+1Ch] [ebp-40h]
  float v43; // [esp+20h] [ebp-3Ch]
  float v44; // [esp+24h] [ebp-38h]
  int v45; // [esp+2Ch] [ebp-30h]
  double v46; // [esp+38h] [ebp-24h]
  float v47; // [esp+44h] [ebp-18h]
  float v48; // [esp+44h] [ebp-18h]
  float n156_4; // [esp+44h] [ebp-18h]
  float v50; // [esp+44h] [ebp-18h]
  float v51; // [esp+44h] [ebp-18h]
  float v52; // [esp+44h] [ebp-18h]
  int n156_3; // [esp+44h] [ebp-18h]
  float n156_6; // [esp+44h] [ebp-18h]
  float v55; // [esp+44h] [ebp-18h]
  float v56; // [esp+44h] [ebp-18h]
  float v57; // [esp+44h] [ebp-18h]
  float v58; // [esp+48h] [ebp-14h]
  float v59; // [esp+48h] [ebp-14h]
  float v60; // [esp+48h] [ebp-14h]
  int n156_2; // [esp+4Ch] [ebp-10h]
  float n156_5; // [esp+4Ch] [ebp-10h]
  float v63; // [esp+4Ch] [ebp-10h]
  float v64; // [esp+4Ch] [ebp-10h]
  int v65; // [esp+4Ch] [ebp-10h]
  float v66; // [esp+50h] [ebp-Ch]
  float v67; // [esp+50h] [ebp-Ch]
  float v68; // [esp+50h] [ebp-Ch]
  float v69; // [esp+54h] [ebp-8h]
  float v70; // [esp+54h] [ebp-8h]
  int v71; // [esp+58h] [ebp-4h]
  int v72; // [esp+58h] [ebp-4h]
  float n156_7; // [esp+58h] [ebp-4h]
  float v74; // [esp+64h] [ebp+8h]

  v1 = 0.0;
  v2 = a1;
  if ( *(float *)(a1 + 220) > 0.0 )
    v1 = FFX_Engine_GetFrameDeltaTime_Bridge() - *(float *)(a1 + 220);
  *(float *)(a1 + 224) = v1;
  v66 = *(float *)(a1 + 224);
  FFX_Engine_GetFrameDeltaTime_Bridge();
  FFX_Menu2D_ScaleY_1080To416(50.0);
  v47 = (float)(52 * ((*(__int16 *)(a1 + 66) - *(__int16 *)(a1 + 64)) / *(__int16 *)(a1 + 56)));
  v48 = v47 + 835.0;
  FFX_Menu2D_ScaleY_1080To416(v48);
  pQuad = FFX_Menu2D_ScaleX_1920To512(154.0);
  FFX_Menu2D_DrawTexQuadAtlas((FFXMenu2DContext *)0xFFFFFFFF, (void *)LODWORD(pQuad));
  /* ... animated title bar loop (3 slots, 52px each) ... */
  v3 = 574.0;
  v4 = 0.1000000014901161;
  v5 = 420.0;
  n156 = 0;
  v7 = -420.0;
  v71 = 0;
  v8 = -420.0;
  n156_2 = 0;
  while ( 1 )
  {
    v69 = v3 * v66 / v4 - v5;
    if ( v69 >= v7 )
    {
      if ( v69 > 154.0 )
        v69 = 154.0;
    }
    else
    {
      v69 = v8;
    }
    v66 = v66 - v4;
    n156_4 = (float)n156_2;
    n156_5 = n156_4;
    FFX_Menu2D_ScaleY_1080To416(50.0);
    FFX_Menu2D_ScaleX_1920To512(480.0);
    v50 = n156_4 + 835.0;
    FFX_Menu2D_ScaleY_1080To416(v50);
    v51 = v69 - 30.0;
    pQuada = FFX_Menu2D_ScaleX_1920To512(v51);
    FFX_Menu2D_DrawTexQuadAtlas((FFXMenu2DContext *)0xFFFFFFFF, (void *)LODWORD(pQuada));
    FFX_Menu2D_ScaleY_1080To416(44.0);
    FFX_Menu2D_ScaleX_1920To512(234.0);
    v52 = n156_5 + 838.0;
    FFX_Menu2D_ScaleY_1080To416(v52);
    pQuadb = FFX_Menu2D_ScaleX_1920To512(v69);
    FFX_Menu2D_DrawTexQuadAtlas((FFXMenu2DContext *)0xFFFFFFFF, (void *)LODWORD(pQuadb));
    ++v71;
    n156 += 52;
    n156_2 = n156;
    if ( n156 >= 156 )
      break;
    v3 = 574.0;
    v4 = 0.1000000014901161;
    v5 = 420.0;
    v7 = -420.0;
    v8 = -420.0;
  }
  if ( *(float *)(a1 + 224) >= 0.30000001 )
  {
    /* Draw highlight bars using FFX_Menu2D_DrawAtlasQuadGeneric */
    v9 = 20.0;
    v10 = 0;
    v11 = 0.0;
    n156_1 = 0;
    v13 = 40.0;
    v72 = 0;
    v14 = 3.0;
    n156_3 = 0;
    v15 = 210.0;
    while ( 1 )
    {
      v58 = (float)++v10;
      v70 = v58;
      v63 = v9 * v58;
      v59 = (float)v72;
      v46 = v11 * v59;
      v60 = v46;
      n156_6 = (float)n156_3;
      n156_7 = n156_6;
      v67 = n156_6 + 835.0;
      v44 = v13;
      v43 = v13;
      v42 = v14;
      v41 = v15;
      v37 = FFX_Menu2D_ScaleY_1080To416(v42);
      pQuadc = FFX_Menu2D_ScaleX_1920To512(210.0);
      *(float *)&v26 = FFX_Menu2D_ScaleY_1080To416(v67);
      v22 = FFX_Menu2D_ScaleX_1920To512(154.0);
      FFX_Menu2D_DrawAtlasQuadGeneric(v22, v26, pQuadc, v37, v60, v63, v41, v42, v43, v44, 0x808080u, 0x40808080u);
      v55 = v46 + 210.0;
      v38 = FFX_Menu2D_ScaleY_1080To416(3.0);
      pQuadd = FFX_Menu2D_ScaleX_1920To512(210.0);
      *(float *)&v27 = FFX_Menu2D_ScaleY_1080To416(v67);
      v23 = FFX_Menu2D_ScaleX_1920To512(364.0);
      FFX_Menu2D_DrawAtlasQuadGeneric(v23, v27, pQuadd, v38, v55, v63, 210.0, 3.0, 40.0, 40.0, 0x40808080u, 0x808080u);
      v64 = v70 * 50.0;
      v68 = n156_7 + 880.0;
      v39 = FFX_Menu2D_ScaleY_1080To416(3.0);
      pQuade = FFX_Menu2D_ScaleX_1920To512(210.0);
      *(float *)&v28 = FFX_Menu2D_ScaleY_1080To416(v68);
      v24 = FFX_Menu2D_ScaleX_1920To512(154.0);
      FFX_Menu2D_DrawAtlasQuadGeneric(v24, v28, pQuade, v39, v60, v64, 210.0, 3.0, 40.0, 40.0, 0x808080u, 0x40808080u);
      v40 = FFX_Menu2D_ScaleY_1080To416(3.0);
      pQuadf = FFX_Menu2D_ScaleX_1920To512(210.0);
      *(float *)&v29 = FFX_Menu2D_ScaleY_1080To416(v68);
      v25 = FFX_Menu2D_ScaleX_1920To512(364.0);
      FFX_Menu2D_DrawAtlasQuadGeneric(v25, v29, pQuadf, v40, v55, v64, 210.0, 3.0, 40.0, 40.0, 0x40808080u, 0x808080u);
      n156_1 += 52;
      v72 = v10;
      n156_3 = n156_1;
      if ( n156_1 >= 156 )
        break;
      v9 = 20.0;
      v11 = 0.0;
      v14 = 3.0;
      v15 = 210.0;
      v13 = 40.0;
    }
    v2 = a1;
  }
  FFX_EscMenu_Update(v2);
  v16 = (int)*(float *)(v2 + 120);
  v17 = *(__int16 *)(v2 + 66);
  v65 = *(__int16 *)(v2 + 56);
  v56 = (float)(v17 % v65);
  v18 = (int)(FFX_Menu2D_ScaleX_1920To512(420.0) * v56 + (double)v16);
  v57 = (float)(52 * ((v17 - *(__int16 *)(a1 + 64)) / v65) + 5);
  v20 = FFX_Menu2D_ScaleY_1080To416(v57) + *(float *)(a1 + 124);
  Menu2D_RegisterAnimationSlot(0, v18, (int)v20);
  if ( *(_WORD *)(*(_DWORD *)(a1 + 32) + 2 * *(__int16 *)(a1 + 66)) != 255 )
  {
    v45 = *(int *)(a1 + 108);
    v74 = FFX_Menu2D_ScaleX_1920To512(30.0) + *(float *)(a1 + 112);
    FFX_Menu2D_DrawAbilityDetailPanel(*(__int16 *)(*(_DWORD *)(a1 + 32) + 2 * *(__int16 *)(a1 + 66)), v74, v45);
  }
  return 0;
}
