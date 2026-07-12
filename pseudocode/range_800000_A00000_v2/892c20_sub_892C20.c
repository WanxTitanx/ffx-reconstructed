// Function: sub_892C20
// Address: 0x892c20
int __cdecl sub_892C20(unsigned __int8 a1, float a2, int a3)
{
  int ActorCtbTurns; // esi
  int ActorCtbGaugeCurrent; // eax
  char n2; // di
  int v6; // esi
  int ActorCtbGaugeTarget; // esi
  float v9; // [esp+4h] [ebp-2Ch]
  float v10; // [esp+4h] [ebp-2Ch]
  float v11; // [esp+8h] [ebp-28h]
  float v12; // [esp+8h] [ebp-28h]
  float v13; // [esp+8h] [ebp-28h]
  float v14; // [esp+Ch] [ebp-24h]
  float v15; // [esp+Ch] [ebp-24h]
  float v16; // [esp+Ch] [ebp-24h]
  float v17; // [esp+Ch] [ebp-24h]
  int v18; // [esp+10h] [ebp-20h]
  int v19; // [esp+10h] [ebp-20h]
  float v20; // [esp+10h] [ebp-20h]
  float v21; // [esp+14h] [ebp-1Ch]
  int v22; // [esp+14h] [ebp-1Ch]
  int v23; // [esp+14h] [ebp-1Ch]
  float v24; // [esp+18h] [ebp-18h]
  int v25; // [esp+18h] [ebp-18h]
  int v26; // [esp+18h] [ebp-18h]
  float v27; // [esp+1Ch] [ebp-14h]
  int v28; // [esp+1Ch] [ebp-14h]
  int v29; // [esp+1Ch] [ebp-14h]
  float v30; // [esp+2Ch] [ebp-4h]
  float v31; // [esp+2Ch] [ebp-4h]
  float v32; // [esp+2Ch] [ebp-4h]
  float v33; // [esp+2Ch] [ebp-4h]
  float v34; // [esp+2Ch] [ebp-4h]
  float v35; // [esp+2Ch] [ebp-4h]
  float v36; // [esp+2Ch] [ebp-4h]
  float v37; // [esp+2Ch] [ebp-4h]
  float v38; // [esp+2Ch] [ebp-4h]
  float v39; // [esp+2Ch] [ebp-4h]
  float v40; // [esp+40h] [ebp+10h]
  float v41; // [esp+40h] [ebp+10h]

  v14 = FFX_Menu2D_ScaleY_1080to416(45.0);
  v11 = FFX_Menu2D_ScaleX_1920to512(320.0);
  FFX_Menu2D_DrawTexQuadSolid(
    0xFFFFFFFF,
    a2,
    a3,
    v11,
    v14,
    COERCE_INT(984.0),
    COERCE_INT(98.0),
    COERCE_INT(1581.0),
    COERCE_INT(148.0));
  v27 = FFX_Menu2D_ScaleY_1080to416(8.0);
  v24 = FFX_Menu2D_ScaleX_1920to512(300.0);
  v30 = FFX_Menu2D_ScaleY_1080to416(29.0) + *(float *)&a3;
  v21 = v30;
  v31 = FFX_Menu2D_ScaleX_1920to512(10.0) + a2;
  sub_892880(a1, v31, v21, v24, v27);
  if ( FFX_Game_GetRegion() == 11 )
  {
    *(float *)&v28 = 0.041015625;
    *(float *)&v25 = 0.44433594;
    *(float *)&v22 = 0.01171875;
    *(float *)&v18 = 0.36132812;
    v15 = FFX_Menu2D_ScaleY_1080to416(24.0);
    v12 = FFX_Menu2D_ScaleX_1920to512(68.0);
    v32 = FFX_Menu2D_ScaleY_1080to416(2.0) + *(float *)&a3 + 0.0;
    v9 = v32;
    v33 = FFX_Menu2D_ScaleX_1920to512(5.0) + a2 - 3.0;
  }
  else
  {
    *(float *)&v28 = 0.040039062;
    *(float *)&v25 = 0.42578125;
    *(float *)&v22 = 0.014648438;
    *(float *)&v18 = 0.34765625;
    v15 = FFX_Menu2D_ScaleY_1080to416(23.0);
    v12 = FFX_Menu2D_ScaleX_1920to512(61.5);
    v34 = FFX_Menu2D_ScaleY_1080to416(2.0) + *(float *)&a3;
    v9 = v34;
    v33 = FFX_Menu2D_ScaleX_1920to512(5.0) + a2;
  }
  FFX_Menu2D_DrawTexQuadSolid(0xE9u, v33, SLODWORD(v9), v12, v15, v18, v22, v25, v28);
  ActorCtbTurns = FFX_Btl_GetActorCtbTurns(a1);
  ActorCtbGaugeCurrent = FFX_Btl_GetActorCtbGaugeCurrent(a1);
  switch ( FFX_Btl_ComputeCtbStateFromODRatio(ActorCtbGaugeCurrent, ActorCtbTurns) )
  {
    case 1:
    case 2:
      n2 = 2;
      break;
    case 3:
      n2 = 83;
      break;
    default:
      n2 = 0;
      break;
  }
  v6 = FFX_Btl_GetActorCtbGaugeCurrent(a1);
  v35 = *(float *)&a3 - FFX_Menu2D_ScaleY_1080to416(4.0);
  v16 = v35;
  v36 = FFX_Menu2D_ScaleX_1920to512(160.0) + a2;
  FFX_Menu2D_DrawNumberWithAlignment(v6, v36, v16, n2, 0.64999998, 0.0);
  if ( FFX_Game_GetRegion() == 11 )
  {
    *(float *)&v29 = 0.041015625;
    *(float *)&v26 = 0.56933594;
    *(float *)&v23 = 0.01171875;
    *(float *)&v19 = 0.48828125;
    v17 = FFX_Menu2D_ScaleY_1080to416(24.0);
    v13 = FFX_Menu2D_ScaleX_1920to512(66.400002);
    v37 = FFX_Menu2D_ScaleY_1080to416(2.0) + *(float *)&a3 + 0.0;
    v10 = v37;
    v38 = FFX_Menu2D_ScaleX_1920to512(185.0) + a2 - 6.0;
  }
  else
  {
    *(float *)&v29 = 0.040039062;
    *(float *)&v26 = 0.55664062;
    *(float *)&v23 = 0.014648438;
    *(float *)&v19 = 0.49804688;
    v17 = FFX_Menu2D_ScaleY_1080to416(23.0);
    v13 = FFX_Menu2D_ScaleX_1920to512(49.0);
    v39 = FFX_Menu2D_ScaleY_1080to416(2.0) + *(float *)&a3;
    v10 = v39;
    v38 = FFX_Menu2D_ScaleX_1920to512(185.0) + a2;
  }
  FFX_Menu2D_DrawTexQuadSolid(0xEAu, v38, SLODWORD(v10), v13, v17, v19, v23, v26, v29);
  ActorCtbGaugeTarget = FFX_Btl_GetActorCtbGaugeTarget(a1);
  v40 = *(float *)&a3 - FFX_Menu2D_ScaleY_1080to416(4.0);
  v20 = v40;
  v41 = FFX_Menu2D_ScaleX_1920to512(305.0) + a2;
  return FFX_Menu2D_DrawNumberWithAlignment(ActorCtbGaugeTarget, v41, v20, 0, 0.64999998, 0.0);
}
