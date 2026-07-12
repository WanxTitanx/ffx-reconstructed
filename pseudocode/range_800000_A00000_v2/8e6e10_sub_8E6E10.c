// Function: sub_8E6E10
// Address: 0x8e6e10
int __cdecl sub_8E6E10(int a1, float a2, float a3, char a4)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v8; // [esp+4h] [ebp-54h]
  int v9; // [esp+4h] [ebp-54h]
  float v10; // [esp+8h] [ebp-50h]
  float v11; // [esp+8h] [ebp-50h]
  float v12; // [esp+Ch] [ebp-4Ch]
  float v13; // [esp+Ch] [ebp-4Ch]
  float v14; // [esp+10h] [ebp-48h]
  float v15; // [esp+10h] [ebp-48h]
  float v16; // [esp+10h] [ebp-48h]
  int v17; // [esp+18h] [ebp-40h]
  int v18; // [esp+18h] [ebp-40h]
  int v19; // [esp+1Ch] [ebp-3Ch]
  int v20; // [esp+1Ch] [ebp-3Ch]
  int v21; // [esp+1Ch] [ebp-3Ch]
  float v22; // [esp+24h] [ebp-34h]
  float v23; // [esp+28h] [ebp-30h]
  float v24; // [esp+2Ch] [ebp-2Ch]
  float v25; // [esp+30h] [ebp-28h]
  float v26; // [esp+30h] [ebp-28h]
  int v27; // [esp+30h] [ebp-28h]
  int v28; // [esp+30h] [ebp-28h]
  float v29; // [esp+30h] [ebp-28h]
  float v30; // [esp+30h] [ebp-28h]
  int v31; // [esp+30h] [ebp-28h]
  float v32; // [esp+30h] [ebp-28h]
  float v33; // [esp+30h] [ebp-28h]
  float v34; // [esp+30h] [ebp-28h]
  int v35; // [esp+30h] [ebp-28h]
  float v36; // [esp+30h] [ebp-28h]
  int v37; // [esp+30h] [ebp-28h]
  float v38; // [esp+30h] [ebp-28h]
  float v39; // [esp+30h] [ebp-28h]
  float v40; // [esp+30h] [ebp-28h]
  char Buffer[32]; // [esp+34h] [ebp-24h] BYREF

  v24 = 0.0;
  v22 = 0.0;
  v23 = 0.0;
  v25 = FFX_Menu2D_ScaleY_1080to416(10.0) + a3;
  v14 = v25;
  v26 = FFX_Menu2D_ScaleX_1920to512(160.0) + a2;
  v4 = sub_8AC800(a1);
  FFX_Menu2D_DrawStatusEffectTimerBar(v4, v26, v14, a4, 0.81999999, COERCE_INT(1.0));
  if ( FFX_Game_GetRegion() == 11 )
  {
    v24 = 22.0;
    v22 = 1.0;
    v23 = 11.0;
  }
  *(float *)&v27 = (v22 + 41.0) * 0.0009765625;
  v19 = v27;
  *(float *)&v28 = 0.0009765625 * (v24 + 436.0);
  v17 = v28;
  v29 = v22 + 23.0;
  v12 = FFX_Menu2D_ScaleY_1080to416(v29);
  v30 = v24 + 61.5;
  v10 = FFX_Menu2D_ScaleX_1920to512(v30);
  *(float *)&v31 = FFX_Menu2D_ScaleY_1080to416(8.0) + a3;
  v8 = v31;
  v32 = FFX_Menu2D_ScaleX_1920to512(480.0) + a2;
  FFX_Menu2D_DrawTexQuadSolid(0x21u, v32, v8, v10, v12, COERCE_INT(0.34765625), COERCE_INT(0.014648438), v17, v19);
  v20 = sub_8A9940(a1);
  v5 = sub_8A9870(a1);
  sprintf(Buffer, "%5d/%5d", v5, v20);
  v33 = FFX_Menu2D_ScaleY_1080to416(9.0) + a3;
  v15 = v33;
  v34 = FFX_Menu2D_ScaleX_1920to512(594.0) + a2 + v23;
  FFX_Menu2D_DrawIconOrTimer((int)Buffer, v34, v15, 37, 0.68000001, 0.0);
  *(float *)&v35 = (v24 + 570.0) * 0.0009765625;
  v18 = v35;
  v13 = FFX_Menu2D_ScaleY_1080to416(23.0);
  v36 = v24 + 49.0;
  v11 = FFX_Menu2D_ScaleX_1920to512(v36);
  *(float *)&v37 = FFX_Menu2D_ScaleY_1080to416(35.0) + a3;
  v9 = v37;
  v38 = FFX_Menu2D_ScaleX_1920to512(530.0) + a2;
  FFX_Menu2D_DrawTexQuadSolid(
    0x22u,
    v38,
    v9,
    v11,
    v13,
    COERCE_INT(0.49804688),
    COERCE_INT(0.014648438),
    v18,
    COERCE_INT(0.040039062));
  v21 = sub_8A9960(a1);
  v6 = sub_8A9920(a1);
  sprintf(Buffer, "%4d/%4d", v6, v21);
  v39 = FFX_Menu2D_ScaleY_1080to416(37.0) + a3;
  v16 = v39;
  v40 = FFX_Menu2D_ScaleX_1920to512(615.0) + a2 + v23;
  return FFX_Menu2D_DrawIconOrTimer((int)Buffer, v40, v16, 37, 0.68000001, 0.0);
}
