// Function: sub_8F51E0
// Address: 0x8f51e0
int __cdecl sub_8F51E0(unsigned int n8, float a2, int a3)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  float v7; // [esp+8h] [ebp-60h]
  float v8; // [esp+8h] [ebp-60h]
  float v9; // [esp+8h] [ebp-60h]
  float v10; // [esp+8h] [ebp-60h]
  float v11; // [esp+Ch] [ebp-5Ch]
  float v12; // [esp+Ch] [ebp-5Ch]
  float v13; // [esp+Ch] [ebp-5Ch]
  float v14; // [esp+Ch] [ebp-5Ch]
  int v15; // [esp+14h] [ebp-54h]
  int v16; // [esp+14h] [ebp-54h]
  int v17; // [esp+14h] [ebp-54h]
  int v18; // [esp+14h] [ebp-54h]
  float v19; // [esp+18h] [ebp-50h]
  float v20; // [esp+18h] [ebp-50h]
  float v21; // [esp+18h] [ebp-50h]
  float v22; // [esp+18h] [ebp-50h]
  float v23; // [esp+18h] [ebp-50h]
  float v24; // [esp+18h] [ebp-50h]
  float v25; // [esp+18h] [ebp-50h]
  float v26; // [esp+1Ch] [ebp-4Ch]
  float v27; // [esp+1Ch] [ebp-4Ch]
  float v28; // [esp+1Ch] [ebp-4Ch]
  float v29; // [esp+1Ch] [ebp-4Ch]
  float v30; // [esp+1Ch] [ebp-4Ch]
  float v31; // [esp+1Ch] [ebp-4Ch]
  float v32; // [esp+1Ch] [ebp-4Ch]
  float v33; // [esp+20h] [ebp-48h]
  float v34; // [esp+20h] [ebp-48h]
  float v35; // [esp+20h] [ebp-48h]
  char v36; // [esp+24h] [ebp-44h]
  int v37; // [esp+28h] [ebp-40h]
  int v38; // [esp+28h] [ebp-40h]
  int v39; // [esp+28h] [ebp-40h]
  int v40; // [esp+28h] [ebp-40h]
  int v41; // [esp+2Ch] [ebp-3Ch]
  int v42; // [esp+2Ch] [ebp-3Ch]
  int v43; // [esp+2Ch] [ebp-3Ch]
  int v44; // [esp+2Ch] [ebp-3Ch]
  float v45; // [esp+34h] [ebp-34h]
  float v46; // [esp+38h] [ebp-30h]
  float v47; // [esp+3Ch] [ebp-2Ch]
  float v48; // [esp+40h] [ebp-28h]
  float v49; // [esp+40h] [ebp-28h]
  float v50; // [esp+40h] [ebp-28h]
  float v51; // [esp+40h] [ebp-28h]
  int v52; // [esp+40h] [ebp-28h]
  int v53; // [esp+40h] [ebp-28h]
  float v54; // [esp+40h] [ebp-28h]
  float v55; // [esp+40h] [ebp-28h]
  int v56; // [esp+40h] [ebp-28h]
  float v57; // [esp+40h] [ebp-28h]
  float v58; // [esp+40h] [ebp-28h]
  float v59; // [esp+40h] [ebp-28h]
  float v60; // [esp+40h] [ebp-28h]
  int v61; // [esp+40h] [ebp-28h]
  float v62; // [esp+40h] [ebp-28h]
  int v63; // [esp+40h] [ebp-28h]
  float v64; // [esp+40h] [ebp-28h]
  float v65; // [esp+40h] [ebp-28h]
  float v66; // [esp+40h] [ebp-28h]
  float v67; // [esp+40h] [ebp-28h]
  int v68; // [esp+40h] [ebp-28h]
  int v69; // [esp+40h] [ebp-28h]
  float v70; // [esp+40h] [ebp-28h]
  float v71; // [esp+40h] [ebp-28h]
  int v72; // [esp+40h] [ebp-28h]
  float v73; // [esp+40h] [ebp-28h]
  int v74; // [esp+40h] [ebp-28h]
  float v75; // [esp+40h] [ebp-28h]
  int v76; // [esp+40h] [ebp-28h]
  float v77; // [esp+40h] [ebp-28h]
  char Buffer[32]; // [esp+44h] [ebp-24h] BYREF

  v47 = 0.0;
  v46 = 0.0;
  v45 = 0.0;
  if ( n8 > 7 )
  {
    v30 = FFX_Menu2D_ScaleY_1080to416(72.0);
    v23 = FFX_Menu2D_ScaleX_1920to512(1110.0);
    FFX_Menu2D_DrawTexQuadSolid(
      0xFFFFFFFD,
      a2,
      a3,
      v23,
      v30,
      COERCE_INT(0.0),
      COERCE_INT(700.0),
      COERCE_INT(1110.0),
      COERCE_INT(772.0));
    if ( FFX_Game_GetRegion() == 11 )
    {
      v47 = 22.0;
      v46 = 1.0;
    }
    *(float *)&v68 = (v46 + 41.0) * 0.0009765625;
    v44 = v68;
    *(float *)&v69 = 0.0009765625 * (v47 + 436.0);
    v39 = v69;
    v70 = v46 + 23.0;
    v31 = FFX_Menu2D_ScaleY_1080to416(v70);
    v71 = v47 + 61.5;
    v24 = FFX_Menu2D_ScaleX_1920to512(v71);
    *(float *)&v72 = FFX_Menu2D_ScaleY_1080to416(8.0) + *(float *)&a3;
    v17 = v72;
    v73 = FFX_Menu2D_ScaleX_1920to512(490.0) + a2;
    FFX_Menu2D_DrawTexQuadSolid(0x21u, v73, v17, v24, v31, COERCE_INT(0.34765625), COERCE_INT(0.014648438), v39, v44);
    *(float *)&v74 = (v47 + 570.0) * 0.0009765625;
    v40 = v74;
    v32 = FFX_Menu2D_ScaleY_1080to416(23.0);
    v75 = v47 + 49.0;
    v25 = FFX_Menu2D_ScaleX_1920to512(v75);
    *(float *)&v76 = FFX_Menu2D_ScaleY_1080to416(35.0) + *(float *)&a3;
    v18 = v76;
    v77 = FFX_Menu2D_ScaleX_1920to512(540.0) + a2;
    return FFX_Menu2D_DrawTexQuadSolid(
             0x22u,
             v77,
             v18,
             v25,
             v32,
             COERCE_INT(0.49804688),
             COERCE_INT(0.014648438),
             v40,
             COERCE_INT(0.040039062));
  }
  else
  {
    if ( (sub_8A9B10() & (1 << n8)) != 0 )
    {
      v26 = FFX_Menu2D_ScaleY_1080to416(72.0);
      v19 = FFX_Menu2D_ScaleX_1920to512(1110.0);
      FFX_Menu2D_DrawTexQuadSolid(
        0xFFFFFFFD,
        a2,
        a3,
        v19,
        v26,
        COERCE_INT(0.0),
        COERCE_INT(0.0),
        COERCE_INT(1110.0),
        COERCE_INT(72.0));
      v11 = FFX_Menu2D_ScaleY_1080to416(64.0);
      v7 = FFX_Menu2D_ScaleX_1920to512(250.0);
      sub_8E7D30(a2, *(float *)&a3, v7, v11, 0.0, 64.0, 250.0, 64.0, 50.0, -20.0, (int)&unk_C56870, 449144944);
      v12 = FFX_Menu2D_ScaleY_1080to416(64.0);
      v8 = FFX_Menu2D_ScaleX_1920to512(250.0);
      v48 = FFX_Menu2D_ScaleX_1920to512(250.0) + a2;
      sub_8E7D30(v48, *(float *)&a3, v8, v12, 250.0, 64.0, 250.0, 64.0, 50.0, -20.0, 449144944, (int)&unk_C56870);
      v13 = FFX_Menu2D_ScaleY_1080to416(64.0);
      v9 = FFX_Menu2D_ScaleX_1920to512(250.0);
      sub_8E7D30(a2, *(float *)&a3, v9, v13, 300.0, 64.0, 250.0, 64.0, -80.0, -10.0, (int)&unk_C56870, 868575344);
      v14 = FFX_Menu2D_ScaleY_1080to416(64.0);
      v10 = FFX_Menu2D_ScaleX_1920to512(250.0);
      v49 = FFX_Menu2D_ScaleX_1920to512(250.0) + a2;
      sub_8E7D30(v49, *(float *)&a3, v10, v14, 550.0, 64.0, 250.0, 64.0, -80.0, -10.0, 868575344, (int)&unk_C56870);
    }
    else
    {
      v27 = FFX_Menu2D_ScaleY_1080to416(72.0);
      v20 = FFX_Menu2D_ScaleX_1920to512(1110.0);
      FFX_Menu2D_DrawTexQuadSolid(
        0xFFFFFFFD,
        a2,
        a3,
        v20,
        v27,
        COERCE_INT(0.0),
        COERCE_INT(700.0),
        COERCE_INT(1110.0),
        COERCE_INT(772.0));
    }
    v36 = sub_8A9A20(n8);
    v50 = FFX_Menu2D_ScaleY_1080to416(10.0) + *(float *)&a3;
    v33 = v50;
    v51 = FFX_Menu2D_ScaleX_1920to512(160.0) + a2;
    v3 = sub_8AC800(n8);
    FFX_Menu2D_DrawStatusEffectTimerBar(v3, v51, v33, v36, 0.81999999, COERCE_INT(1.0));
    if ( FFX_Game_GetRegion() == 11 )
    {
      v47 = 22.0;
      v46 = 1.0;
      v45 = 11.0;
    }
    *(float *)&v52 = (v46 + 41.0) * 0.0009765625;
    v41 = v52;
    *(float *)&v53 = 0.0009765625 * (v47 + 436.0);
    v37 = v53;
    v54 = v46 + 23.0;
    v28 = FFX_Menu2D_ScaleY_1080to416(v54);
    v55 = v47 + 61.5;
    v21 = FFX_Menu2D_ScaleX_1920to512(v55);
    *(float *)&v56 = FFX_Menu2D_ScaleY_1080to416(8.0) + *(float *)&a3;
    v15 = v56;
    v57 = FFX_Menu2D_ScaleX_1920to512(490.0) + a2;
    FFX_Menu2D_DrawTexQuadSolid(0x21u, v57, v15, v21, v28, COERCE_INT(0.34765625), COERCE_INT(0.014648438), v37, v41);
    v42 = sub_8A9940(n8);
    v4 = sub_8A9870(n8);
    sprintf(Buffer, "%5d/%5d", v4, v42);
    v58 = FFX_Menu2D_ScaleY_1080to416(9.0) + *(float *)&a3;
    v34 = v58;
    v59 = v45 + 604.0;
    v60 = FFX_Menu2D_ScaleX_1920to512(v59) + a2;
    FFX_Menu2D_DrawIconOrTimer((int)Buffer, v60, v34, 37, 0.68000001, 0.0);
    *(float *)&v61 = (v47 + 570.0) * 0.0009765625;
    v38 = v61;
    v29 = FFX_Menu2D_ScaleY_1080to416(23.0);
    v62 = v47 + 49.0;
    v22 = FFX_Menu2D_ScaleX_1920to512(v62);
    *(float *)&v63 = FFX_Menu2D_ScaleY_1080to416(35.0) + *(float *)&a3;
    v16 = v63;
    v64 = FFX_Menu2D_ScaleX_1920to512(540.0) + a2;
    FFX_Menu2D_DrawTexQuadSolid(
      0x22u,
      v64,
      v16,
      v22,
      v29,
      COERCE_INT(0.49804688),
      COERCE_INT(0.014648438),
      v38,
      COERCE_INT(0.040039062));
    v43 = sub_8A9960(n8);
    v5 = sub_8A9920(n8);
    sprintf(Buffer, "%4d/%4d", v5, v43);
    v65 = FFX_Menu2D_ScaleY_1080to416(37.0) + *(float *)&a3;
    v35 = v65;
    v66 = v45 + 625.0;
    v67 = FFX_Menu2D_ScaleX_1920to512(v66) + a2;
    return FFX_Menu2D_DrawIconOrTimer((int)Buffer, v67, v35, 37, 0.68000001, 0.0);
  }
}
