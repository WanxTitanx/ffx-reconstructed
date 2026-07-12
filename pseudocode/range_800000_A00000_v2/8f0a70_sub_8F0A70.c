// Function: sub_8F0A70
// Address: 0x8f0a70
_DWORD *__cdecl sub_8F0A70(_DWORD *a1, unsigned int n7, int a3, int a4)
{
  char *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  unsigned int v8; // esi
  int v9; // eax
  int v11; // [esp+Ch] [ebp-5Ch]
  int v12; // [esp+Ch] [ebp-5Ch]
  int v13; // [esp+Ch] [ebp-5Ch]
  int v14; // [esp+Ch] [ebp-5Ch]
  int v15; // [esp+Ch] [ebp-5Ch]
  int v16; // [esp+Ch] [ebp-5Ch]
  int v17; // [esp+Ch] [ebp-5Ch]
  float v18; // [esp+18h] [ebp-50h]
  float v19; // [esp+18h] [ebp-50h]
  float v20; // [esp+18h] [ebp-50h]
  float v21; // [esp+18h] [ebp-50h]
  float v22; // [esp+18h] [ebp-50h]
  float v23; // [esp+1Ch] [ebp-4Ch]
  int v24; // [esp+24h] [ebp-44h]
  int v25; // [esp+24h] [ebp-44h]
  int v26; // [esp+38h] [ebp-30h]
  int v27; // [esp+3Ch] [ebp-2Ch]
  float v28; // [esp+3Ch] [ebp-2Ch]
  float v29; // [esp+40h] [ebp-28h]
  float v30; // [esp+40h] [ebp-28h]
  float v31; // [esp+40h] [ebp-28h]
  int v32; // [esp+40h] [ebp-28h]
  float v33; // [esp+40h] [ebp-28h]
  float v34; // [esp+40h] [ebp-28h]
  float v35; // [esp+40h] [ebp-28h]
  int v36; // [esp+40h] [ebp-28h]
  float v37; // [esp+40h] [ebp-28h]
  float v38; // [esp+40h] [ebp-28h]
  float v39; // [esp+40h] [ebp-28h]
  int v40; // [esp+40h] [ebp-28h]
  float v41; // [esp+40h] [ebp-28h]
  int v42; // [esp+40h] [ebp-28h]
  float v43; // [esp+40h] [ebp-28h]
  int v44; // [esp+40h] [ebp-28h]
  float v45; // [esp+40h] [ebp-28h]
  int v46; // [esp+40h] [ebp-28h]
  float v47; // [esp+40h] [ebp-28h]
  int v48; // [esp+40h] [ebp-28h]
  float v49; // [esp+40h] [ebp-28h]
  float v50; // [esp+40h] [ebp-28h]
  float v51; // [esp+40h] [ebp-28h]
  float v52; // [esp+40h] [ebp-28h]
  float v53; // [esp+40h] [ebp-28h]
  char Buffer[32]; // [esp+44h] [ebp-24h] BYREF

  dword_187168C = a1;
  if ( n7 > 7 )
  {
    sub_8F5E90(204, 205, a3, a4, unk_25D1672, unk_25D166C, unk_25D1668);
    sub_903A10(233, a3 + unk_25D1660, a4 + unk_25D165E);
    sub_903A10(234, a3 + unk_25D1658, a4 + unk_25D1656);
    sub_903B70(231, 0, a4, 512, 0, -2139062144, -2139062144);
    sub_903A10(263, a3 + unk_25D1650 + 104, a4 + unk_25D164E);
  }
  else
  {
    *(float *)&v27 = (float)a4;
    v26 = v27;
    v28 = (float)a3;
    FFX_Menu2D_DrawTexQuadTinted(
      4u,
      v28,
      v26,
      142.0,
      38.0,
      COERCE_INT(0.0),
      COERCE_INT(0.0),
      COERCE_INT(0.02734375),
      COERCE_INT(0.15136719),
      unk_25D166C,
      unk_25D1668);
    v29 = (float)(a3 + 142);
    FFX_Menu2D_DrawTexQuadTinted(
      5u,
      v29,
      v26,
      40.0,
      38.0,
      COERCE_INT(0.03125),
      COERCE_INT(0.0),
      COERCE_INT(0.18554688),
      COERCE_INT(0.15136719),
      unk_25D1668,
      unk_25D1668);
    v23 = COERCE_FLOAT(sub_8A99A0(n7));
    v30 = (float)(a4 + unk_25D1662);
    v18 = v30;
    v31 = (float)(a3 + unk_25D1664);
    v4 = (char *)sub_8AC800(n7);
    FFX_Menu2D_DrawKernelString(v4, v31, v18, v23, 1.0);
    sub_6449B0(26.0);
    sub_644970(46.0);
    *(float *)&v32 = (float)(a4 + unk_25D165E);
    v11 = v32;
    v33 = (float)(a3 + unk_25D1660);
    FFX_Menu2D_DrawTexQuadSolid(
      0x21u,
      v33,
      v11,
      46.0,
      26.0,
      COERCE_INT(0.37304688),
      COERCE_INT(0.001953125),
      COERCE_INT(0.44335938),
      COERCE_INT(0.0625));
    v24 = sub_8A9940(n7);
    v5 = sub_8A9870(n7);
    sprintf(Buffer, "%5d/%5d", v5, v24);
    v34 = (float)(a4 + unk_25D165A);
    v19 = v34;
    v35 = (float)(a3 + unk_25D165C);
    FFX_Menu2D_DrawIconOrTimer((int)Buffer, v35, v19, 37, 1.0, 0.0);
    sub_6449B0(26.0);
    sub_644970(46.0);
    *(float *)&v36 = (float)(a4 + unk_25D1656);
    v12 = v36;
    v37 = (float)(a3 + unk_25D1658);
    FFX_Menu2D_DrawTexQuadSolid(
      0x22u,
      v37,
      v12,
      46.0,
      26.0,
      COERCE_INT(0.49316406),
      COERCE_INT(0.001953125),
      COERCE_INT(0.57226562),
      COERCE_INT(0.0625));
    v25 = sub_8A9960(n7);
    v6 = sub_8A9920(n7);
    sprintf(Buffer, "%4d/%4d", v6, v25);
    v38 = (float)(a4 + unk_25D1652);
    v20 = v38;
    v39 = (float)(a3 + unk_25D1654);
    FFX_Menu2D_DrawIconOrTimer((int)Buffer, v39, v20, 37, 1.0, 0.0);
    *(float *)&v40 = (float)(a4 + 5);
    v13 = v40;
    v41 = (float)(a3 + 332);
    FFX_Menu2D_DrawTexQuadSolid(
      0x107u,
      v41,
      v13,
      96.0,
      14.0,
      COERCE_INT(0.0),
      COERCE_INT(0.8125),
      COERCE_INT(0.5625),
      COERCE_INT(0.859375));
    sub_6449B0(60.0);
    sub_644970(60.0);
    *(float *)&v42 = *(float *)&v26 - 0.0;
    v14 = v42;
    v43 = v28 + 315.0;
    FFX_Menu2D_DrawTexQuadSolid(
      0x107u,
      v43,
      v14,
      60.0,
      60.0,
      COERCE_INT(0.18457031),
      COERCE_INT(0.0234375),
      COERCE_INT(0.35351562),
      COERCE_INT(0.1953125));
    sub_6449B0(20.0);
    sub_644970(60.0);
    *(float *)&v44 = *(float *)&v26 + 22.0;
    v15 = v44;
    v45 = v28 + 295.0;
    FFX_Menu2D_DrawTexQuadSolid(
      0x107u,
      v45,
      v15,
      60.0,
      20.0,
      COERCE_INT(0.81054688),
      COERCE_INT(0.068359375),
      COERCE_INT(0.92773438),
      COERCE_INT(0.11230469));
    *(float *)&v46 = *(float *)&v26 + 5.0;
    v16 = v46;
    v47 = v28 + 342.0;
    FFX_Menu2D_DrawTexQuadSolid(
      0x107u,
      v47,
      v16,
      25.0,
      16.0,
      COERCE_INT(0.625),
      COERCE_INT(0.0),
      COERCE_INT(0.70605469),
      COERCE_INT(0.05078125));
    *(float *)&v48 = *(float *)&v26 + 19.0;
    v17 = v48;
    v49 = v28 + 438.0;
    FFX_Menu2D_DrawTexQuadSolid(
      0x107u,
      v49,
      v17,
      24.0,
      15.0,
      COERCE_INT(0.37109375),
      COERCE_INT(0.0625),
      COERCE_INT(0.46484375),
      COERCE_INT(0.1171875));
    v50 = (float)(a4 + unk_25D164A + unk_25D164E);
    v21 = v50;
    v51 = (float)(a3 + unk_25D164C + unk_25D1650 - 13);
    v7 = sub_8A9B30(n7);
    sub_9019F0(v7, v51, v21, 0, 1.0, -3.0);
    v52 = (float)(a4 + unk_25D164E - 15);
    v22 = v52;
    v53 = (float)(a3 + 139 + unk_25D1650);
    v8 = FFX_Btl_Od_ComputeChargeLevelThreshold(n7);
    v9 = sub_785370(n7);
    sub_9019F0(v8 - v9, v53, v22, 37, 1.0, -3.0);
  }
  return dword_187168C;
}
