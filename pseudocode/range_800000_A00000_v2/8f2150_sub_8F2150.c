// Function: sub_8F2150
// Address: 0x8f2150
int __cdecl sub_8F2150(int a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v6; // esi
  float v8; // [esp+8h] [ebp-50h]
  float v9; // [esp+8h] [ebp-50h]
  float v10; // [esp+8h] [ebp-50h]
  int v11; // [esp+14h] [ebp-44h]
  int v12; // [esp+14h] [ebp-44h]
  int v13; // [esp+14h] [ebp-44h]
  int v14; // [esp+18h] [ebp-40h]
  float v15; // [esp+18h] [ebp-40h]
  float v16; // [esp+18h] [ebp-40h]
  float v17; // [esp+18h] [ebp-40h]
  float v18; // [esp+18h] [ebp-40h]
  float v19; // [esp+18h] [ebp-40h]
  float v20; // [esp+18h] [ebp-40h]
  float v21; // [esp+18h] [ebp-40h]
  float v22; // [esp+18h] [ebp-40h]
  float v23; // [esp+18h] [ebp-40h]
  float v24; // [esp+18h] [ebp-40h]
  float v25; // [esp+18h] [ebp-40h]
  float v26; // [esp+18h] [ebp-40h]
  float v27; // [esp+1Ch] [ebp-3Ch]
  float v28; // [esp+1Ch] [ebp-3Ch]
  float v29; // [esp+1Ch] [ebp-3Ch]
  float v30; // [esp+1Ch] [ebp-3Ch]
  float v31; // [esp+1Ch] [ebp-3Ch]
  float v32; // [esp+1Ch] [ebp-3Ch]
  float v33; // [esp+1Ch] [ebp-3Ch]
  float v34; // [esp+1Ch] [ebp-3Ch]
  float v35; // [esp+1Ch] [ebp-3Ch]
  unsigned int v36; // [esp+24h] [ebp-34h]
  double v37; // [esp+2Ch] [ebp-2Ch]
  double v38; // [esp+34h] [ebp-24h]
  float v39; // [esp+3Ch] [ebp-1Ch]
  float v40; // [esp+3Ch] [ebp-1Ch]
  int v41; // [esp+3Ch] [ebp-1Ch]
  float v42; // [esp+3Ch] [ebp-1Ch]
  float v43; // [esp+3Ch] [ebp-1Ch]
  float v44; // [esp+3Ch] [ebp-1Ch]
  float v45; // [esp+3Ch] [ebp-1Ch]
  float v46; // [esp+3Ch] [ebp-1Ch]
  float v47; // [esp+3Ch] [ebp-1Ch]
  float v48; // [esp+3Ch] [ebp-1Ch]
  int v49; // [esp+3Ch] [ebp-1Ch]
  float v50; // [esp+3Ch] [ebp-1Ch]
  int v51; // [esp+3Ch] [ebp-1Ch]
  float v52; // [esp+3Ch] [ebp-1Ch]
  int v53; // [esp+3Ch] [ebp-1Ch]
  float v54; // [esp+3Ch] [ebp-1Ch]
  int v55; // [esp+3Ch] [ebp-1Ch]
  float v56; // [esp+3Ch] [ebp-1Ch]
  int v57; // [esp+3Ch] [ebp-1Ch]
  double v58; // [esp+40h] [ebp-18h]
  int v59; // [esp+44h] [ebp-14h]
  int v60; // [esp+48h] [ebp-10h]
  int v61; // [esp+48h] [ebp-10h]
  float v62; // [esp+4Ch] [ebp-Ch]
  float v63; // [esp+50h] [ebp-8h]
  int v64; // [esp+54h] [ebp-4h]
  int v65; // [esp+74h] [ebp+1Ch]
  float v66; // [esp+74h] [ebp+1Ch]
  float v67; // [esp+74h] [ebp+1Ch]
  int v68; // [esp+74h] [ebp+1Ch]
  float v69; // [esp+74h] [ebp+1Ch]

  v6 = a6 & 0xFF000000;
  v62 = FFX_Menu2D_ScaleX_1920to512(740.0);
  v63 = FFX_Menu2D_ScaleY_1080to416(48.0);
  v36 = a6 & 0xFF000000;
  *(float *)&v60 = 1080.0 * v63 / 416.0;
  *(float *)&v65 = (float)a4;
  v64 = v65;
  v66 = (float)a3;
  v8 = FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawTexQuadTinted(
    0xFFFFFFFC,
    v66,
    v64,
    v8,
    v63,
    COERCE_INT(0.0),
    COERCE_INT(0.0),
    COERCE_INT(140.0),
    v60,
    0x808080u,
    v36);
  v37 = 1920.0 * v62 * 0.001953125;
  *(float *)&v59 = v37 - 140.0;
  v39 = v62 - FFX_Menu2D_ScaleX_1920to512(280.0);
  v9 = v39;
  v40 = FFX_Menu2D_ScaleX_1920to512(140.0) + v66;
  FFX_Menu2D_DrawTexQuadTinted(0xFFFFFFFC, v40, v64, v9, v63, COERCE_INT(140.0), COERCE_INT(0.0), v59, v60, v6, v6);
  v38 = v66 + v62;
  *(float *)&v41 = v37;
  v14 = v41;
  v10 = FFX_Menu2D_ScaleX_1920to512(140.0);
  v42 = v38 - FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawTexQuadTinted(0xFFFFFFFC, v42, v64, v10, v63, v59, COERCE_INT(0.0), v14, v60, v6, 0x808080u);
  v58 = *(float *)&v64 + v63;
  *(float *)&v61 = v58;
  v27 = FFX_Menu2D_ScaleY_1080to416(6.0);
  v15 = FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawFilledRect(v66, v61, v15, v27, 0, 0x26000000u);
  v28 = FFX_Menu2D_ScaleY_1080to416(6.0);
  v43 = v62 - FFX_Menu2D_ScaleX_1920to512(280.0);
  v16 = v43;
  v44 = FFX_Menu2D_ScaleX_1920to512(140.0) + v66;
  FFX_Menu2D_DrawFilledRect(v44, v61, v16, v28, 0x26000000u, 0x26000000u);
  v29 = FFX_Menu2D_ScaleY_1080to416(6.0);
  v17 = FFX_Menu2D_ScaleX_1920to512(140.0);
  v45 = v38 - FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawFilledRect(v45, v61, v17, v29, 0x26000000u, 0);
  v18 = FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawFilledRect(v66, v64, v18, v63, 0, v6);
  v46 = v62 - FFX_Menu2D_ScaleX_1920to512(280.0);
  v19 = v46;
  v47 = FFX_Menu2D_ScaleX_1920to512(140.0) + v66;
  FFX_Menu2D_DrawFilledRect(v47, v64, v19, v63, v6, v6);
  v20 = FFX_Menu2D_ScaleX_1920to512(140.0);
  v48 = v38 - FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawFilledRect(v48, v64, v20, v63, v6, 0);
  v30 = FFX_Menu2D_ScaleY_1080to416(2.0);
  v21 = FFX_Menu2D_ScaleX_1920to512(140.0);
  *(float *)&v49 = FFX_Menu2D_ScaleY_1080to416(1.0) + *(float *)&v64;
  FFX_Menu2D_DrawFilledRect(v66, v49, v21, v30, (unsigned int)&unk_FFFFFF, 0x5AFFFFFFu);
  v31 = FFX_Menu2D_ScaleY_1080to416(2.0);
  v50 = v62 - FFX_Menu2D_ScaleX_1920to512(280.0);
  v22 = v50;
  *(float *)&v51 = FFX_Menu2D_ScaleY_1080to416(1.0) + *(float *)&v64;
  v11 = v51;
  v52 = FFX_Menu2D_ScaleX_1920to512(140.0) + v66;
  FFX_Menu2D_DrawFilledRect(v52, v11, v22, v31, 0x5AFFFFFFu, 0x5AFFFFFFu);
  v32 = FFX_Menu2D_ScaleY_1080to416(2.0);
  v23 = FFX_Menu2D_ScaleX_1920to512(140.0);
  *(float *)&v53 = FFX_Menu2D_ScaleY_1080to416(1.0) + *(float *)&v64;
  v12 = v53;
  v54 = v38 - FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawFilledRect(v54, v12, v23, v32, 0x5AFFFFFFu, (unsigned int)&unk_FFFFFF);
  v33 = FFX_Menu2D_ScaleY_1080to416(3.0);
  v24 = FFX_Menu2D_ScaleX_1920to512(140.0);
  *(float *)&v55 = v58 - FFX_Menu2D_ScaleY_1080to416(3.0);
  FFX_Menu2D_DrawFilledRect(v66, v55, v24, v33, 0, 0x80000000);
  v34 = FFX_Menu2D_ScaleY_1080to416(3.0);
  v56 = v62 - FFX_Menu2D_ScaleX_1920to512(280.0);
  v25 = v56;
  *(float *)&v57 = v58 - FFX_Menu2D_ScaleY_1080to416(3.0);
  v67 = FFX_Menu2D_ScaleX_1920to512(140.0) + v66;
  FFX_Menu2D_DrawFilledRect(v67, v57, v25, v34, 0x80000000, 0x80000000);
  v35 = FFX_Menu2D_ScaleY_1080to416(3.0);
  v26 = FFX_Menu2D_ScaleX_1920to512(140.0);
  *(float *)&v68 = v58 - FFX_Menu2D_ScaleY_1080to416(3.0);
  v13 = v68;
  v69 = v38 - FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawFilledRect(v69, v13, v26, v35, 0x80000000, 0);
  return sub_8F1F00(a1, a2, a3 + 21, a4 + 5, a5 & 0xFF000000);
}
