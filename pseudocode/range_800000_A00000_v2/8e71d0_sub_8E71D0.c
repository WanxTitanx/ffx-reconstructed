// Function: sub_8E71D0
// Address: 0x8e71d0
int __cdecl sub_8E71D0(int n2)
{
  int n2_1; // eax
  double v2; // st7
  float v3; // [esp+0h] [ebp-20h]
  float v4; // [esp+0h] [ebp-20h]
  float v5; // [esp+0h] [ebp-20h]
  int v6; // [esp+4h] [ebp-1Ch]
  int v7; // [esp+4h] [ebp-1Ch]
  int v8; // [esp+4h] [ebp-1Ch]
  float v9; // [esp+4h] [ebp-1Ch]
  int v10; // [esp+4h] [ebp-1Ch]
  int v11; // [esp+4h] [ebp-1Ch]
  float v12; // [esp+8h] [ebp-18h]
  float v13; // [esp+8h] [ebp-18h]
  float v14; // [esp+8h] [ebp-18h]
  float v15; // [esp+8h] [ebp-18h]
  float v16; // [esp+8h] [ebp-18h]
  float v17; // [esp+Ch] [ebp-14h]
  float v18; // [esp+Ch] [ebp-14h]
  float v19; // [esp+Ch] [ebp-14h]
  float v20; // [esp+Ch] [ebp-14h]
  float v21; // [esp+Ch] [ebp-14h]
  int v22; // [esp+10h] [ebp-10h]
  int v23; // [esp+14h] [ebp-Ch]
  int v24; // [esp+18h] [ebp-8h]
  int v25; // [esp+1Ch] [ebp-4h]

  n2_1 = n2;
  if ( n2 == 1 )
  {
    v17 = FFX_Menu2D_ScaleY_1080to416(30.0);
    v12 = FFX_Menu2D_ScaleX_1920to512(1920.0);
    *(float *)&v6 = FFX_Menu2D_ScaleY_1080to416(149.0);
    FFX_Menu2D_DrawTexQuadSolid(
      0xC8u,
      0.0,
      v6,
      v12,
      v17,
      COERCE_INT(0.19433594),
      COERCE_INT(0.41992188),
      COERCE_INT(0.0),
      COERCE_INT(0.390625));
    v18 = FFX_Menu2D_ScaleY_1080to416(30.0);
    v13 = FFX_Menu2D_ScaleX_1920to512(1920.0);
    *(float *)&v7 = FFX_Menu2D_ScaleY_1080to416(999.0);
    return FFX_Menu2D_DrawTexQuadSolid(
             0xC8u,
             0.0,
             v7,
             v13,
             v18,
             COERCE_INT(0.0),
             COERCE_INT(0.390625),
             COERCE_INT(0.19433594),
             COERCE_INT(0.41992188));
  }
  if ( n2 == 2 )
  {
    *(float *)&v25 = 570.0;
    *(float *)&v24 = 1829.0;
    *(float *)&v23 = 567.0;
    *(float *)&v22 = 1631.0;
    v19 = FFX_Menu2D_ScaleY_1080to416(2.0);
    v14 = FFX_Menu2D_ScaleX_1920to512(1500.0);
    v2 = 224.0;
LABEL_14:
    v9 = v2;
    *(float *)&v10 = FFX_Menu2D_ScaleY_1080to416(v9);
    v4 = FFX_Menu2D_ScaleX_1920to512(210.0);
    FFX_Menu2D_DrawTexQuadSolid(0xFFFFFFFF, v4, v10, v14, v19, v22, v23, v24, v25);
    goto LABEL_15;
  }
  if ( n2 != 3 )
  {
    switch ( n2 )
    {
      case 4:
        *(float *)&v25 = 570.0;
        *(float *)&v24 = 1829.0;
        *(float *)&v23 = 567.0;
        *(float *)&v22 = 1631.0;
        v19 = FFX_Menu2D_ScaleY_1080to416(2.0);
        v14 = FFX_Menu2D_ScaleX_1920to512(1500.0);
        v2 = 250.0;
        break;
      case 5:
        *(float *)&v25 = 570.0;
        *(float *)&v24 = 1829.0;
        *(float *)&v23 = 567.0;
        *(float *)&v22 = 1631.0;
        v19 = FFX_Menu2D_ScaleY_1080to416(2.0);
        v14 = FFX_Menu2D_ScaleX_1920to512(1500.0);
        v2 = 410.0;
        break;
      case 6:
        v20 = FFX_Menu2D_ScaleY_1080to416(2.0);
        v15 = FFX_Menu2D_ScaleX_1920to512(1500.0);
        *(float *)&v8 = FFX_Menu2D_ScaleY_1080to416(305.0);
        v3 = FFX_Menu2D_ScaleX_1920to512(210.0);
        FFX_Menu2D_DrawTexQuadSolid(
          0xFFFFFFFF,
          v3,
          v8,
          v15,
          v20,
          COERCE_INT(1631.0),
          COERCE_INT(567.0),
          COERCE_INT(1829.0),
          COERCE_INT(570.0));
        *(float *)&v25 = 570.0;
        *(float *)&v24 = 1829.0;
        *(float *)&v23 = 567.0;
        *(float *)&v22 = 1631.0;
        v19 = FFX_Menu2D_ScaleY_1080to416(2.0);
        v14 = FFX_Menu2D_ScaleX_1920to512(1500.0);
        v2 = 590.0;
        break;
      case 7:
        *(float *)&v25 = 570.0;
        *(float *)&v24 = 1829.0;
        *(float *)&v23 = 567.0;
        *(float *)&v22 = 1631.0;
        v19 = FFX_Menu2D_ScaleY_1080to416(2.0);
        v14 = FFX_Menu2D_ScaleX_1920to512(1500.0);
        v2 = 305.0;
        break;
      default:
        return n2_1;
    }
    goto LABEL_14;
  }
LABEL_15:
  v21 = FFX_Menu2D_ScaleY_1080to416(2.0);
  v16 = FFX_Menu2D_ScaleX_1920to512(1500.0);
  *(float *)&v11 = FFX_Menu2D_ScaleY_1080to416(1015.0);
  v5 = FFX_Menu2D_ScaleX_1920to512(210.0);
  return FFX_Menu2D_DrawTexQuadSolid(
           0xFFFFFFFF,
           v5,
           v11,
           v16,
           v21,
           COERCE_INT(1631.0),
           COERCE_INT(567.0),
           COERCE_INT(1829.0),
           COERCE_INT(570.0));
}
