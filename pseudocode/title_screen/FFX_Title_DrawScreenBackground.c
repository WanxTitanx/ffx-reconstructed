/*
 * Function: FFX_Title_DrawScreenBackground
 * Address:   0x8F59C0
 * Prototype: void __cdecl FFX_Title_DrawScreenBackground(
 *                int n274_2, int n274_3, int n332, int n32,
 *                int n274, int n61, int a7, int a8)
 *
 * Renders title screen background image. Uses openingscreen.swf
 * from ps3data/flash/ via Iggy SDK.
 * Atlas ID: 16000
 *
 * Callees:
 *   FFX_Menu2D_TexHandleByAtlasId
 *   FFX_Menu2D_GetAtlasDimensions_structural
 *   FFX_Menu_RenderEnqueue
 */

void __cdecl FFX_Title_DrawScreenBackground(
        int n274_2,
        int n274_3,
        int n332,
        int n32,
        int n274,
        int n61,
        int a7,
        int a8)
{
  struct FFXMenu2DContext *v8; // ecx
  float v9; // [esp+4h] [ebp-A8h] BYREF
  float v10; // [esp+8h] [ebp-A4h] BYREF
  float n274_1; // [esp+Ch] [ebp-A0h]
  int v12; // [esp+10h] [ebp-9Ch]
  float v13; // [esp+14h] [ebp-98h]
  float v14; // [esp+18h] [ebp-94h]
  float v15; // [esp+1Ch] [ebp-90h]
  int n255; // [esp+20h] [ebp-8Ch]
  int n255_1; // [esp+24h] [ebp-88h]
  int n255_2; // [esp+28h] [ebp-84h]
  int v19; // [esp+2Ch] [ebp-80h]
  float v20; // [esp+30h] [ebp-7Ch]
  float v21; // [esp+34h] [ebp-78h]
  float v22; // [esp+38h] [ebp-74h]
  float v23; // [esp+3Ch] [ebp-70h]
  int n255_3; // [esp+40h] [ebp-6Ch]
  int n255_4; // [esp+44h] [ebp-68h]
  int n255_5; // [esp+48h] [ebp-64h]
  int v27; // [esp+4Ch] [ebp-60h]
  int v28; // [esp+98h] [ebp-14h]
  int v29; // [esp+A0h] [ebp-Ch]
  int v30; // [esp+A4h] [ebp-8h]

  v29 = 0;
  v30 = 0;
  FFX_Menu2D_TexHandleByAtlasId(16000);
  FFX_Menu2D_GetAtlasDimensions_structural(16000, &v9, &v10);
  v28 = 0;
  n274_1 = (float)n274_2;
  *(float *)&v12 = n274_1 * 512.0 / 1920.0;
  n274_1 = (float)n274_3;
  v13 = n274_1 * 416.0 / 1080.0;
  n274_1 = (float)n274;
  v14 = n274_1 / v9;
  n274_1 = (float)n61;
  v19 = a7;
  n255 = 255;
  n255_1 = 255;
  n255_2 = 255;
  v15 = n274_1 / v10;
  n274_1 = (float)(n332 + n274_2);
  v20 = 512.0 * n274_1 / 1920.0;
  n274_1 = (float)(n32 + n274_3);
  v21 = 416.0 * n274_1 / 1080.0;
  n274_1 = (float)(n332 + n274);
  v22 = n274_1 / v9;
  n274_1 = (float)(n32 + n61);
  v23 = n274_1 / v10;
  v27 = a8;
  n255_3 = 255;
  n255_4 = 255;
  n255_5 = 255;
  FFX_Menu_RenderEnqueue(v8);
}
