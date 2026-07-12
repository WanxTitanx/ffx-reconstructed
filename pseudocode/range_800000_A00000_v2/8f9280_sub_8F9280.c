// Function: sub_8F9280
// Address: 0x8f9280
void __cdecl sub_8F9280(int a1, float a2, int a3, unsigned int a4)
{
  unsigned int v5; // esi
  float v6; // [esp+8h] [ebp-58h]
  float v7; // [esp+8h] [ebp-58h]
  float v8; // [esp+8h] [ebp-58h]
  float v9; // [esp+14h] [ebp-4Ch]
  float v10; // [esp+14h] [ebp-4Ch]
  float v11; // [esp+14h] [ebp-4Ch]
  float v12; // [esp+14h] [ebp-4Ch]
  float v13; // [esp+14h] [ebp-4Ch]
  int v14; // [esp+18h] [ebp-48h]
  float v15; // [esp+18h] [ebp-48h]
  float v16; // [esp+18h] [ebp-48h]
  float v17; // [esp+18h] [ebp-48h]
  float v18; // [esp+18h] [ebp-48h]
  float v19; // [esp+18h] [ebp-48h]
  float v20; // [esp+18h] [ebp-48h]
  float v21; // [esp+18h] [ebp-48h]
  float v22; // [esp+18h] [ebp-48h]
  float v23; // [esp+18h] [ebp-48h]
  float v24; // [esp+18h] [ebp-48h]
  float v25; // [esp+18h] [ebp-48h]
  float v26; // [esp+18h] [ebp-48h]
  int v27; // [esp+1Ch] [ebp-44h]
  float v28; // [esp+1Ch] [ebp-44h]
  float v29; // [esp+1Ch] [ebp-44h]
  float v30; // [esp+1Ch] [ebp-44h]
  float v31; // [esp+1Ch] [ebp-44h]
  float v32; // [esp+1Ch] [ebp-44h]
  float v33; // [esp+1Ch] [ebp-44h]
  float v34; // [esp+1Ch] [ebp-44h]
  float v35; // [esp+1Ch] [ebp-44h]
  float v36; // [esp+1Ch] [ebp-44h]
  float v37; // [esp+1Ch] [ebp-44h]
  float v38; // [esp+20h] [ebp-40h]
  double v39; // [esp+30h] [ebp-30h]
  double v40; // [esp+38h] [ebp-28h]
  double v41; // [esp+40h] [ebp-20h]
  float v42; // [esp+4Ch] [ebp-14h]
  float v43; // [esp+4Ch] [ebp-14h]
  float v44; // [esp+4Ch] [ebp-14h]
  float v45; // [esp+4Ch] [ebp-14h]
  double v46; // [esp+50h] [ebp-10h]
  int v47; // [esp+54h] [ebp-Ch]
  float v48; // [esp+58h] [ebp-8h]
  float v49; // [esp+5Ch] [ebp-4h]
  float v50; // [esp+6Ch] [ebp+Ch]
  int v51; // [esp+70h] [ebp+10h]
  int v52; // [esp+74h] [ebp+14h]
  int v53; // [esp+74h] [ebp+14h]
  float v54; // [esp+74h] [ebp+14h]
  float v55; // [esp+74h] [ebp+14h]
  float v56; // [esp+74h] [ebp+14h]
  float v57; // [esp+74h] [ebp+14h]
  float v58; // [esp+74h] [ebp+14h]
  float v59; // [esp+74h] [ebp+14h]
  float v60; // [esp+74h] [ebp+14h]
  float v61; // [esp+74h] [ebp+14h]
  float v62; // [esp+74h] [ebp+14h]
  float v63; // [esp+74h] [ebp+14h]
  float v64; // [esp+74h] [ebp+14h]
  float v65; // [esp+74h] [ebp+14h]
  float v66; // [esp+74h] [ebp+14h]
  float v67; // [esp+74h] [ebp+14h]
  float v68; // [esp+74h] [ebp+14h]
  float v69; // [esp+74h] [ebp+14h]
  float v70; // [esp+74h] [ebp+14h]
  float v71; // [esp+74h] [ebp+14h]
  float v72; // [esp+74h] [ebp+14h]

  v48 = FFX_Menu2D_ScaleX_1920to512(740.0);
  v49 = FFX_Menu2D_ScaleY_1080to416(48.0);
  v5 = (a4 << 24) + 8421504;
  *(float *)&v52 = 1080.0 * v49 / 416.0;
  v6 = FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawTexQuadTinted(
    0xFFFFFFFC,
    a2,
    a3,
    v6,
    v49,
    COERCE_INT(0.0),
    COERCE_INT(0.0),
    COERCE_INT(140.0),
    v52,
    0x808080u,
    v5);
  v39 = 1920.0 * v48 * 0.001953125;
  *(float *)&v47 = v39 - 140.0;
  v42 = v48 - FFX_Menu2D_ScaleX_1920to512(280.0);
  v7 = v42;
  v43 = FFX_Menu2D_ScaleX_1920to512(140.0) + a2;
  FFX_Menu2D_DrawTexQuadTinted(0xFFFFFFFC, v43, a3, v7, v49, COERCE_INT(140.0), COERCE_INT(0.0), v47, v52, v5, v5);
  v41 = v48 + a2;
  v27 = v52;
  *(float *)&v53 = v39;
  v14 = v53;
  v8 = FFX_Menu2D_ScaleX_1920to512(140.0);
  v54 = v41 - FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawTexQuadTinted(0xFFFFFFFC, v54, a3, v8, v49, v47, COERCE_INT(0.0), v14, v27, v5, 0x808080u);
  v55 = (float)a4;
  v40 = v55 * 0.0078125;
  v46 = v49 + *(float *)&a3;
  v56 = v46;
  v28 = FFX_Menu2D_ScaleY_1080to416(6.0);
  v15 = FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawFilledRect(a2, v56, v15, v28, 0, (unsigned int)(__int64)(v40 * 38.0) << 24);
  v29 = FFX_Menu2D_ScaleY_1080to416(6.0);
  v44 = v48 - FFX_Menu2D_ScaleX_1920to512(280.0);
  v16 = v44;
  v45 = FFX_Menu2D_ScaleX_1920to512(140.0) + a2;
  FFX_Menu2D_DrawFilledRect(
    v45,
    v56,
    v16,
    v29,
    (unsigned int)(__int64)(v40 * 38.0) << 24,
    (unsigned int)(__int64)(v40 * 38.0) << 24);
  v30 = FFX_Menu2D_ScaleY_1080to416(6.0);
  v17 = FFX_Menu2D_ScaleX_1920to512(140.0);
  v9 = v56;
  v57 = v41 - FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawFilledRect(v57, v9, v17, v30, (unsigned int)(__int64)(v40 * 38.0) << 24, 0);
  v18 = FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawFilledRect(a2, *(float *)&a3, v18, v49, 0, (int)(v40 * 90.0) << 24);
  v58 = v48 - FFX_Menu2D_ScaleX_1920to512(280.0);
  v19 = v58;
  v59 = FFX_Menu2D_ScaleX_1920to512(140.0) + a2;
  FFX_Menu2D_DrawFilledRect(v59, *(float *)&a3, v19, v49, (int)(v40 * 90.0) << 24, (int)(v40 * 90.0) << 24);
  v20 = FFX_Menu2D_ScaleX_1920to512(140.0);
  v60 = v41 - FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawFilledRect(v60, *(float *)&a3, v20, v49, (int)(v40 * 90.0) << 24, 0);
  v31 = FFX_Menu2D_ScaleY_1080to416(2.0);
  v21 = FFX_Menu2D_ScaleX_1920to512(140.0);
  v61 = FFX_Menu2D_ScaleY_1080to416(1.0) + *(float *)&a3;
  FFX_Menu2D_DrawFilledRect(
    a2,
    v61,
    v21,
    v31,
    (unsigned int)&unk_FFFFFF,
    (unsigned int)&unk_FFFFFF + 0x1000000 * (__int64)(v40 * 90.0));
  v32 = FFX_Menu2D_ScaleY_1080to416(2.0);
  v62 = v48 - FFX_Menu2D_ScaleX_1920to512(280.0);
  v22 = v62;
  v63 = FFX_Menu2D_ScaleY_1080to416(1.0) + *(float *)&a3;
  v10 = v63;
  v64 = FFX_Menu2D_ScaleX_1920to512(140.0) + a2;
  FFX_Menu2D_DrawFilledRect(
    v64,
    v10,
    v22,
    v32,
    (unsigned int)&unk_FFFFFF + 0x1000000 * (__int64)(v40 * 90.0),
    (unsigned int)&unk_FFFFFF + 0x1000000 * (__int64)(v40 * 90.0));
  v33 = FFX_Menu2D_ScaleY_1080to416(2.0);
  v23 = FFX_Menu2D_ScaleX_1920to512(140.0);
  v65 = FFX_Menu2D_ScaleY_1080to416(1.0) + *(float *)&a3;
  v11 = v65;
  v66 = v41 - FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawFilledRect(
    v66,
    v11,
    v23,
    v33,
    (unsigned int)&unk_FFFFFF + 0x1000000 * (__int64)(v40 * 90.0),
    (unsigned int)&unk_FFFFFF);
  v34 = FFX_Menu2D_ScaleY_1080to416(3.0);
  v24 = FFX_Menu2D_ScaleX_1920to512(140.0);
  v67 = v46 - FFX_Menu2D_ScaleY_1080to416(3.0);
  FFX_Menu2D_DrawFilledRect(a2, v67, v24, v34, 0, (unsigned int)(__int64)(v40 * 128.0) << 24);
  v35 = FFX_Menu2D_ScaleY_1080to416(3.0);
  v68 = v48 - FFX_Menu2D_ScaleX_1920to512(280.0);
  v25 = v68;
  v69 = v46 - FFX_Menu2D_ScaleY_1080to416(3.0);
  v12 = v69;
  v70 = FFX_Menu2D_ScaleX_1920to512(140.0) + a2;
  FFX_Menu2D_DrawFilledRect(
    v70,
    v12,
    v25,
    v35,
    (unsigned int)(__int64)(v40 * 128.0) << 24,
    (unsigned int)(__int64)(v40 * 128.0) << 24);
  v36 = FFX_Menu2D_ScaleY_1080to416(3.0);
  v26 = FFX_Menu2D_ScaleX_1920to512(140.0);
  v71 = v46 - FFX_Menu2D_ScaleY_1080to416(3.0);
  v13 = v71;
  v72 = v41 - FFX_Menu2D_ScaleX_1920to512(140.0);
  FFX_Menu2D_DrawFilledRect(v72, v13, v26, v36, (unsigned int)(__int64)(v40 * 128.0) << 24, 0);
  v38 = FFX_Menu2D_ScaleY_1080to416(36.0);
  v37 = FFX_Menu2D_ScaleX_1920to512(430.0);
  *(float *)&v51 = FFX_Menu2D_ScaleY_1080to416(6.0) + *(float *)&a3;
  v50 = FFX_Menu2D_ScaleX_1920to512(155.0) + a2;
  sub_8F8D50(a1, v50, v51, v37, v38, a4);
}
