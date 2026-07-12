/*
 * Function: FFX_System_DrawTitleScreen
 * Address:   0x8FE0B0
 * Size:     ~2.5KB
 * Prototype: void __cdecl FFX_System_DrawTitleScreen(int a1)
 *
 * Renders the FFX title screen with background, logo, and menu options.
 * Uses openingscreen.swf from ps3data/flash/ via Iggy SDK.
 *
 * Callees:
 *   FFX_Menu2D_ScaleY_1080To416
 *   FFX_Menu2D_ScaleX_1920To512
 *   FFX_Menu2D_DrawTexQuadAtlas
 *   FFX_Menu2D_DrawTexQuadSolid
 *   FFX_Menu2D_TableLookupSpriteData
 *   FFX_Menu2D_TexHandleByAtlasId
 *   FFX_Menu2D_GetAtlasDimensions_structural
 *   FFX_Menu2D_TableLookupAtlasBase
 *   FFX_Title_DrawScreenBackground
 *   FFX_Menu2D_InitAtlasQuadCoords
 *   FFX_Menu_RenderEnqueue
 */

void __cdecl FFX_System_DrawTitleScreen(int a1)
{
  unsigned int n0xC8; // eax
  double v2; // st6
  double v3; // st7
  float v4; // esi
  _DWORD *v5; // edi
  int n0xC8_1; // eax
  int n0x190; // eax
  bool v8; // zf
  char *v9; // edi
  int v10; // eax
  int v11; // ecx
  double v12; // st6
  double v13; // st5
  double v14; // st4
  __int16 pQuad_1; // ax
  double v16; // st3
  __int16 pQuad_2; // ax
  double v18; // st7
  int v19; // esi
  int v20; // eax
  double v21; // st6
  double v22; // rtt
  double v23; // st4
  int v24; // eax
  int v25; // esi
  double v26; // rt0
  struct FFXMenu2DContext *v27; // ecx
  int v28; // eax
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  double v33; // st7
  float v34; // [esp+0h] [ebp-110h]
  int v35; // [esp+34h] [ebp-DCh]
  int v36; // [esp+38h] [ebp-D8h]
  int v37; // [esp+3Ch] [ebp-D4h]
  float v38; // [esp+4Ch] [ebp-C4h] BYREF
  double v39; // [esp+50h] [ebp-C0h]
  float v40; // [esp+58h] [ebp-B8h] BYREF
  float v41; // [esp+5Ch] [ebp-B4h]
  float v42; // [esp+60h] [ebp-B0h]
  double v43; // [esp+64h] [ebp-ACh]
  double pQuad; // [esp+6Ch] [ebp-A4h]
  int v45; // [esp+74h] [ebp-9Ch] BYREF
  float v46; // [esp+78h] [ebp-98h]
  float v47; // [esp+7Ch] [ebp-94h]
  float v48; // [esp+80h] [ebp-90h]
  int v49; // [esp+84h] [ebp-8Ch]
  int v50; // [esp+88h] [ebp-88h]
  int v51; // [esp+8Ch] [ebp-84h]
  int v52; // [esp+90h] [ebp-80h]
  float v53; // [esp+94h] [ebp-7Ch]
  float v54; // [esp+98h] [ebp-78h]
  float v55; // [esp+9Ch] [ebp-74h]
  float v56; // [esp+A0h] [ebp-70h]
  int v57; // [esp+A4h] [ebp-6Ch]
  int v58; // [esp+A8h] [ebp-68h]
  int v59; // [esp+ACh] [ebp-64h]
  int v60; // [esp+B0h] [ebp-60h]
  int v61; // [esp+F4h] [ebp-1Ch]
  int v62; // [esp+FCh] [ebp-14h]
  int v63; // [esp+104h] [ebp-Ch]
  int v64; // [esp+108h] [ebp-8h]

  n0xC8 = *(unsigned __int16 *)(a1 + 20);
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  if ( (_WORD)n0xC8 != 415 && (_WORD)n0xC8 != 419 && (_WORD)n0xC8 != 411 && (_WORD)n0xC8 != 412 && (_WORD)n0xC8 != 507 )
  {
    if ( (_WORD)n0xC8 == 417 )
    {
      HIDWORD(pQuad) = *(__int16 *)(a1 + 16);
      v43 = (double)SHIDWORD(pQuad);
      HIDWORD(pQuad) = *(__int16 *)(a1 + 18);
      v42 = v43 / 100.0;
      v43 = (double)SHIDWORD(pQuad);
      v41 = v43 / 100.0;
      if ( *(__int16 *)(a1 + 14) <= 330 )
      {
        v2 = v41 * 120.0;
        if ( *(_WORD *)(a1 + 12) == 116 )
        {
          v43 = 120.0 * v42;
          *((float *)&pQuad + 1) = v2;
          FFX_Menu2D_ScaleY_1080To416(*((float *)&pQuad + 1));
          *((float *)&pQuad + 1) = v43;
          FFX_Menu2D_ScaleX_1920To512(*((float *)&pQuad + 1));
          *((float *)&pQuad + 1) = 535.0 - 0.5 * v2;
          FFX_Menu2D_ScaleY_1080To416(*((float *)&pQuad + 1));
          *((float *)&pQuad + 1) = 0.5 * v43;
          *((float *)&pQuad + 1) = 160.0 - FFX_Menu2D_ScaleX_1920To512(*((float *)&pQuad + 1));
        }
        else
        {
          v43 = 120.0 * v42;
          *((float *)&pQuad + 1) = v2;
          FFX_Menu2D_ScaleY_1080To416(*((float *)&pQuad + 1));
          *((float *)&pQuad + 1) = v43;
          FFX_Menu2D_ScaleX_1920To512(*((float *)&pQuad + 1));
          *((float *)&pQuad + 1) = 535.0 - 0.5 * v2;
          FFX_Menu2D_ScaleY_1080To416(*((float *)&pQuad + 1));
          *((float *)&pQuad + 1) = 0.5 * v43;
          *((float *)&pQuad + 1) = 388.0 - FFX_Menu2D_ScaleX_1920To512(*((float *)&pQuad + 1));
        }
        FFX_Menu2D_DrawTexQuadAtlas((FFXMenu2DContext *)0xFFFFFFFF, (void *)HIDWORD(pQuad));
      }
    }
    else if ( (_WORD)n0xC8 == 240 )
    {
      HIDWORD(pQuad) = *(__int16 *)(a1 + 14);
      v3 = (double)SHIDWORD(pQuad);
      HIDWORD(pQuad) = *(__int16 *)(a1 + 12);
      v43 = v3;
      FFX_Menu2D_ScaleY_1080To416(186.0);
      FFX_Menu2D_ScaleX_1920To512(89.0);
      FFX_Menu2D_ScaleY_1080To416(185.0);
      *((float *)&pQuad + 1) = (double)SHIDWORD(pQuad) - FFX_Menu2D_ScaleX_1920To512(10.0);
      FFX_Menu2D_DrawTexQuadSolid((FFXMenu2DContext *)0xC8, (void *)HIDWORD(pQuad));
    }
    else
    {
      if ( (unsigned __int16)n0xC8 >= 0xC8u )
      {
        v4 = *((float *)&v43 + 1);
        v5 = (_DWORD *)HIDWORD(v43);
        v42 = *((float *)&v43 + 1);
      }
      else
      {
        v4 = COERCE_FLOAT(FFX_Menu2D_TableLookupSpriteData(n0xC8));
        v42 = v4;
        v5 = (_DWORD *)(LODWORD(v4) + 4);
        FFX_Menu2D_TexHandleByAtlasId(15872);
        FFX_Menu2D_GetAtlasDimensions_structural(15872, &v38, &v40);
      }
      n0xC8_1 = *(unsigned __int16 *)(a1 + 20);
      if ( (unsigned __int16)n0xC8_1 >= 0xC8u && (unsigned __int16)n0xC8_1 < 0x190u )
      {
        v4 = COERCE_FLOAT(FFX_Menu2D_TableLookupSpriteData(n0xC8_1 - 200));
        v42 = v4;
        v5 = (_DWORD *)(LODWORD(v4) + 4);
        FFX_Menu2D_TexHandleByAtlasId(15872);
        FFX_Menu2D_GetAtlasDimensions_structural(15872, &v38, &v40);
      }
      n0x190 = *(unsigned __int16 *)(a1 + 20);
      if ( (unsigned __int16)n0x190 >= 0x190u && (unsigned __int16)n0x190 < 0x258u )
      {
        v4 = COERCE_FLOAT(FFX_Menu2D_TableLookupAtlasBase(n0x190 - 400));
        v42 = v4;
        v5 = (_DWORD *)(LODWORD(v4) + 4);
        FFX_Menu2D_TexHandleByAtlasId(16128);
        FFX_Menu2D_GetAtlasDimensions_structural(16128, &v38, &v40);
      }
      v8 = *(_DWORD *)LODWORD(v4) == 0;
      v35 = *(unsigned __int8 *)(a1 + 4);
      v36 = *(unsigned __int8 *)(a1 + 5);
      HIDWORD(v39) = *(unsigned __int8 *)(a1 + 6);
      HIDWORD(v43) = *(unsigned __int8 *)(a1 + 7);
      v41 = 0.0;
      if ( !v8 )
      {
        v9 = (char *)v5 + 3;
        while ( 2 )
        {
          v10 = *(v9 - 1) + *(unsigned __int16 *)(v9 + 1);
          HIDWORD(pQuad) = *(v9 - 1);
          v11 = *v9;
          v12 = (double)SHIDWORD(pQuad);
          HIDWORD(pQuad) = v10;
          v13 = (double)v10;
          v14 = (double)v11;
          HIDWORD(pQuad) = v11 + *(unsigned __int16 *)(v9 + 3);
          pQuad_1 = *(_WORD *)(a1 + 16);
          v16 = (double)SHIDWORD(pQuad);
          if ( pQuad_1 != 100 )
          {
            pQuad = (double)pQuad_1;
            v12 = v12 / 100.0 * pQuad;
            v13 = pQuad * (v13 / 100.0);
          }
          pQuad_2 = *(_WORD *)(a1 + 18);
          if ( pQuad_2 == 100 )
          {
            v18 = v16;
          }
          else
          {
            pQuad = (double)pQuad_2;
            v14 = v14 / 100.0 * pQuad;
            v18 = pQuad * (v16 / 100.0);
          }
          v19 = *(__int16 *)(a1 + 12);
          if ( *(_WORD *)(v9 + 5) == 1 )
          {
            v20 = (int)v13;
            v13 = v12;
            v21 = v14;
          }
          else
          {
            v22 = v14;
            v23 = v12;
            v21 = v22;
            v20 = (int)v23;
          }
          v37 = v19 + v20;
          v24 = v19 + (int)v13;
          v25 = *(__int16 *)(a1 + 14);
          if ( *(_WORD *)(v9 + 7) == 1 )
          {
            v26 = v21;
            v21 = v18;
            v18 = v26;
          }
          *(float *)&v45 = (float)v37;
          HIDWORD(pQuad) = v25 + (int)v18;
          v46 = (float)(v25 + (int)v21);
          v49 = v35;
          v57 = v35;
          v50 = v36;
          v58 = v36;
          v53 = (float)v24;
          v51 = HIDWORD(v39);
          v52 = HIDWORD(v43);
          v59 = HIDWORD(v39);
          v60 = HIDWORD(v43);
          v54 = (float)SHIDWORD(pQuad);
          HIDWORD(pQuad) = (unsigned __int8)*(v9 - 3);
          pQuad = (double)SHIDWORD(pQuad);
          v47 = pQuad / v38;
          HIDWORD(pQuad) = (unsigned __int8)*(v9 - 2);
          pQuad = (double)SHIDWORD(pQuad);
          v48 = pQuad / v40;
          HIDWORD(pQuad) = *(unsigned __int16 *)(v9 + 1) - 1 + (unsigned __int8)*(v9 - 3);
          *((float *)&pQuad + 1) = (float)SHIDWORD(pQuad);
          v55 = *((float *)&pQuad + 1) / v38;
          v27 = (struct FFXMenu2DContext *)*(unsigned __int16 *)(v9 + 3);
          HIDWORD(pQuad) = (char *)v27 + (unsigned __int8)*(v9 - 2) - 1;
          *((float *)&pQuad + 1) = (float)SHIDWORD(pQuad);
          v28 = *(unsigned __int16 *)(a1 + 20) - 413;
          v56 = *((float *)&pQuad + 1) / v40;
          switch ( v28 )
          {
            case 0:
              if ( v46 <= 300.0 )
              {
                FFX_Title_DrawScreenBackground(
                  (int)(*(float *)&v45 * 1920.0 * 0.001953125 - 21.0),
                  (int)(v46 * 1080.0 / 416.0 - 18.0),
                  332,
                  32,
                  274,
                  61,
                  SHIDWORD(v43),
                  SHIDWORD(v43));
                v43 = v46;
                FFX_Menu2D_ScaleY_1080To416(24.0);
                FFX_Menu2D_ScaleX_1920To512(201.0);
                v29 = FFX_Menu2D_ScaleY_1080To416(14.0);
                *((float *)&v43 + 1) = v43 - v29;
                v30 = FFX_Menu2D_ScaleX_1920To512(13.0);
                *((float *)&v43 + 1) = v30 + *(float *)&v45;
                v31 = *((float *)&v43 + 1);
                goto LABEL_46;
              }
              return;
            case 1:
              FFX_Menu2D_InitAtlasQuadCoords((float *)&v45, 4141);
              goto LABEL_41;
            case 90:
              v43 = v46;
              v39 = *(float *)&v45;
              FFX_Menu2D_ScaleY_1080To416(48.0);
              FFX_Menu2D_ScaleX_1920To512(58.0);
              v32 = FFX_Menu2D_ScaleY_1080To416(14.0);
              *((float *)&v43 + 1) = v43 - v32;
              v33 = FFX_Menu2D_ScaleX_1920To512(53.0);
              *((float *)&v43 + 1) = v39 - v33;
              v31 = *((float *)&v43 + 1);
LABEL_46:
              v34 = v31;
              FFX_Menu2D_DrawTexQuadAtlas((FFXMenu2DContext *)0x190, (void *)LODWORD(v34));
              return;
            case 94:
              if ( v41 == 0.0 )
                FFX_Menu2D_InitAtlasQuadCoords((float *)&v45, 411);
              else
                FFX_Menu2D_InitAtlasQuadCoords((float *)&v45, 507);
              goto LABEL_41;
            case 95:
              FFX_Menu2D_InitAtlasQuadCoords((float *)&v45, 508);
              goto LABEL_41;
            default:
LABEL_41:
              FFX_Menu_RenderEnqueue(v27);
              v9 += 12;
              if ( ++LODWORD(v41) < *(_DWORD *)LODWORD(v42) )
                continue;
              return;
          }
        }
      }
    }
  }
}
