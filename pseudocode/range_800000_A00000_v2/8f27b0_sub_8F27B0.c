// Function: sub_8F27B0
// Address: 0x8f27b0
_DWORD *__cdecl sub_8F27B0(_DWORD *a1, int a2, int a3, int a4, float a5)
{
  char *v5; // eax
  int v6; // eax
  int v7; // eax
  int v9; // [esp+Ch] [ebp-54h]
  int v10; // [esp+Ch] [ebp-54h]
  float v11; // [esp+18h] [ebp-48h]
  float v12; // [esp+18h] [ebp-48h]
  float v13; // [esp+18h] [ebp-48h]
  int v14; // [esp+24h] [ebp-3Ch]
  int v15; // [esp+24h] [ebp-3Ch]
  int v16; // [esp+34h] [ebp-2Ch]
  float v17; // [esp+38h] [ebp-28h]
  float v18; // [esp+38h] [ebp-28h]
  float v19; // [esp+38h] [ebp-28h]
  float v20; // [esp+38h] [ebp-28h]
  int v21; // [esp+38h] [ebp-28h]
  float v22; // [esp+38h] [ebp-28h]
  float v23; // [esp+38h] [ebp-28h]
  float v24; // [esp+38h] [ebp-28h]
  int v25; // [esp+38h] [ebp-28h]
  float v26; // [esp+38h] [ebp-28h]
  float v27; // [esp+38h] [ebp-28h]
  float v28; // [esp+38h] [ebp-28h]
  char Buffer[32]; // [esp+3Ch] [ebp-24h] BYREF

  dword_187168C = a1;
  *(float *)&v16 = (float)(a4 - 1);
  v17 = (float)a3;
  FFX_Menu2D_DrawTexQuadTinted(
    0xCCu,
    v17,
    v16,
    142.0,
    38.0,
    COERCE_INT(0.0),
    COERCE_INT(0.0),
    COERCE_INT(0.02734375),
    COERCE_INT(0.15136719),
    unk_25D0B14,
    unk_25D0B10);
  v18 = (float)(a3 + 142);
  FFX_Menu2D_DrawTexQuadTinted(
    0xCDu,
    v18,
    v16,
    40.0,
    38.0,
    COERCE_INT(0.03125),
    COERCE_INT(0.0),
    COERCE_INT(0.18554688),
    COERCE_INT(0.15136719),
    unk_25D0B10,
    unk_25D0B10);
  v19 = (float)(a4 + unk_25D1662);
  v11 = v19;
  v20 = (float)(a3 + unk_25D1664);
  v5 = (char *)sub_8AC800(a2);
  FFX_Menu2D_DrawKernelString(v5, v20, v11, a5, 1.0);
  sub_6449B0(26.0);
  sub_644970(46.0);
  *(float *)&v21 = (float)(a4 + unk_25D165E);
  v9 = v21;
  v22 = (float)(a3 + unk_25D1660);
  FFX_Menu2D_DrawTexQuadSolid(
    0xE9u,
    v22,
    v9,
    46.0,
    26.0,
    COERCE_INT(0.37304688),
    COERCE_INT(0.001953125),
    COERCE_INT(0.44335938),
    COERCE_INT(0.0625));
  v14 = sub_8A9940(a2);
  v6 = sub_8A9870(a2);
  sprintf(Buffer, "%5d/%5d", v6, v14);
  v23 = (float)(a4 + unk_25D165A);
  v12 = v23;
  v24 = (float)(a3 + unk_25D165C);
  FFX_Menu2D_DrawIconOrTimer((int)Buffer, v24, v12, 37, 1.0, 0.0);
  sub_6449B0(26.0);
  sub_644970(46.0);
  *(float *)&v25 = (float)(a4 + unk_25D1656);
  v10 = v25;
  v26 = (float)(a3 + unk_25D1658);
  FFX_Menu2D_DrawTexQuadSolid(
    0xEAu,
    v26,
    v10,
    46.0,
    26.0,
    COERCE_INT(0.49316406),
    COERCE_INT(0.001953125),
    COERCE_INT(0.57226562),
    COERCE_INT(0.0625));
  v15 = sub_8A9960(a2);
  v7 = sub_8A9920(a2);
  sprintf(Buffer, "%4d/%4d", v7, v15);
  v27 = (float)(a4 + unk_25D1652);
  v13 = v27;
  v28 = (float)(a3 + unk_25D1654);
  FFX_Menu2D_DrawIconOrTimer((int)Buffer, v28, v13, 37, 1.0, 0.0);
  sub_903B70(231, a3, a4, 512, 0, -2139062144, -2139062144);
  return dword_187168C;
}
