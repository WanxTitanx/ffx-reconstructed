/*
 * Function: FFX_Menu2D_DrawAtlasQuadGeneric
 * Address:   0x8E7D30
 * Prototype: void __cdecl FFX_Menu2D_DrawAtlasQuadGeneric(
 *                int a1, float a2, float a3, float a4,
 *                float a5, float a6, float a7, float a8,
 *                float a9, float a10, unsigned int a11, unsigned int a12)
 *
 * Draws a textured atlas quad with animated UV offset.
 * Uses texture.dds.phyre (atlas ID 16001) for the generic menu texture.
 * UV animation driven by frame delta time.
 *
 * Callees:
 *   FFX_Menu2D_TexHandleByAtlasId
 *   FFX_Menu2D_GetAtlasDimensions_structural
 *   FFX_Engine_GetFrameDeltaTime_Bridge
 *   FFX_Menu_RenderEnqueue
 */

void __cdecl FFX_Menu2D_DrawAtlasQuadGeneric(
        int a1,
        float a2,
        float a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8,
        float a9,
        float a10,
        unsigned int a11,
        unsigned int a12)
{
  float v12; // [esp+4h] [ebp-A8h] BYREF
  float v13; // [esp+8h] [ebp-A4h] BYREF
  float v14; // [esp+Ch] [ebp-A0h]
  int v15; // [esp+10h] [ebp-9Ch]
  float v16; // [esp+14h] [ebp-98h]
  float v17; // [esp+18h] [ebp-94h]
  float v18; // [esp+1Ch] [ebp-90h]
  int v19; // [esp+20h] [ebp-8Ch]
  int v20; // [esp+24h] [ebp-88h]
  int v21; // [esp+28h] [ebp-84h]
  unsigned int v22; // [esp+2Ch] [ebp-80h]
  float v23; // [esp+30h] [ebp-7Ch]
  float v24; // [esp+34h] [ebp-78h]
  float v25; // [esp+38h] [ebp-74h]
  float v26; // [esp+3Ch] [ebp-70h]
  int v27; // [esp+40h] [ebp-6Ch]
  int v28; // [esp+44h] [ebp-68h]
  int v29; // [esp+48h] [ebp-64h]
  unsigned int v30; // [esp+4Ch] [ebp-60h]
  int v31; // [esp+A0h] [ebp-Ch]
  int v32; // [esp+A4h] [ebp-8h]
  float v33; // [esp+C4h] [ebp+18h]
  float v34; // [esp+C4h] [ebp+18h]
  float v35; // [esp+C4h] [ebp+18h]
  float v36; // [esp+C8h] [ebp+1Ch]
  float v37; // [esp+C8h] [ebp+1Ch]
  float v38; // [esp+C8h] [ebp+1Ch]

  v31 = 0;
  v32 = 0;
  FFX_Menu2D_TexHandleByAtlasId(16001);
  FFX_Menu2D_GetAtlasDimensions_structural(16001, &v12, &v13);
  v15 = a1;
  v16 = a2;
  v23 = *(float *)&a1 + a3;
  v24 = a2 + a4;
  v33 = FFX_Engine_GetFrameDeltaTime_Bridge() * a9 + a5;
  v34 = v33 / v12;
  v36 = FFX_Engine_GetFrameDeltaTime_Bridge() * a10 + a6;
  v37 = v36 / v13;
  v14 = (float)(int)v34;
  v35 = v34 - v14;
  v14 = (float)(int)v37;
  v19 = (unsigned __int8)a11;
  v38 = v37 - v14;
  v20 = BYTE1(a11);
  v17 = v35;
  v18 = v38;
  v22 = HIBYTE(a11);
  v21 = BYTE2(a11);
  v25 = v35 + a7 / v12;
  v26 = v38 + a8 / v13;
  v27 = (unsigned __int8)a12;
  v28 = BYTE1(a12);
  v29 = BYTE2(a12);
  v30 = HIBYTE(a12);
  FFX_Menu_RenderEnqueue((struct FFXMenu2DContext *)HIBYTE(a12));
}
