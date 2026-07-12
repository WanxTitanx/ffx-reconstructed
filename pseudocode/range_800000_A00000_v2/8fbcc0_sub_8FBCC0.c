// Function: sub_8FBCC0
// Address: 0x8fbcc0
int __cdecl sub_8FBCC0(int n2, int a2, int a3, int a4)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-24h]
  int v6; // [esp+4h] [ebp-24h]
  int v7; // [esp+4h] [ebp-24h]
  int v8; // [esp+4h] [ebp-24h]
  float v9; // [esp+8h] [ebp-20h]
  float v10; // [esp+8h] [ebp-20h]
  float v11; // [esp+8h] [ebp-20h]
  float v12; // [esp+8h] [ebp-20h]
  float v13; // [esp+Ch] [ebp-1Ch]
  float v14; // [esp+Ch] [ebp-1Ch]
  float v15; // [esp+Ch] [ebp-1Ch]
  float v16; // [esp+Ch] [ebp-1Ch]
  unsigned int v17; // [esp+24h] [ebp-4h]
  unsigned int v18; // [esp+24h] [ebp-4h]
  unsigned int v19; // [esp+24h] [ebp-4h]
  unsigned int v20; // [esp+24h] [ebp-4h]
  int v21; // [esp+3Ch] [ebp+14h]
  float v22; // [esp+3Ch] [ebp+14h]
  int v23; // [esp+3Ch] [ebp+14h]
  float v24; // [esp+3Ch] [ebp+14h]
  int v25; // [esp+3Ch] [ebp+14h]
  float v26; // [esp+3Ch] [ebp+14h]
  int v27; // [esp+3Ch] [ebp+14h]
  float v28; // [esp+3Ch] [ebp+14h]

  result = (a4 << 24) | 0x808080;
  switch ( n2 )
  {
    case 0:
      v17 = (a4 << 24) | 0x808080;
      v13 = FFX_Menu2D_ScaleY_1080to416(38.0);
      v9 = FFX_Menu2D_ScaleX_1920to512(310.0);
      *(float *)&v21 = (float)a3;
      v5 = v21;
      v22 = (float)a2;
      result = FFX_Menu2D_DrawTexQuadTinted(
                 0x258u,
                 v22,
                 v5,
                 v9,
                 v13,
                 COERCE_INT(108.0),
                 COERCE_INT(452.0),
                 COERCE_INT(550.0),
                 COERCE_INT(506.0),
                 v17,
                 v17);
      break;
    case 1:
      v18 = (a4 << 24) | 0x808080;
      v14 = FFX_Menu2D_ScaleY_1080to416(60.0);
      v10 = FFX_Menu2D_ScaleX_1920to512(208.0);
      *(float *)&v23 = (float)a3;
      v6 = v23;
      v24 = (float)a2;
      result = FFX_Menu2D_DrawTexQuadTinted(
                 0x258u,
                 v24,
                 v6,
                 v10,
                 v14,
                 COERCE_INT(632.0),
                 COERCE_INT(382.0),
                 COERCE_INT(952.0),
                 COERCE_INT(474.0),
                 v18,
                 v18);
      break;
    case 2:
      v19 = (a4 << 24) | 0x808080;
      v15 = FFX_Menu2D_ScaleY_1080to416(38.0);
      v11 = FFX_Menu2D_ScaleX_1920to512(158.0);
      *(float *)&v25 = (float)a3;
      v7 = v25;
      v26 = (float)a2;
      result = FFX_Menu2D_DrawTexQuadTinted(
                 0x258u,
                 v26,
                 v7,
                 v11,
                 v15,
                 COERCE_INT(304.0),
                 COERCE_INT(392.0),
                 COERCE_INT(464.0),
                 COERCE_INT(432.0),
                 v19,
                 v19);
      break;
    case 3:
      v20 = (a4 << 24) | 0x808080;
      v16 = FFX_Menu2D_ScaleY_1080to416(45.0);
      v12 = FFX_Menu2D_ScaleX_1920to512(86.5);
      *(float *)&v27 = (float)a3;
      v8 = v27;
      v28 = (float)a2;
      result = FFX_Menu2D_DrawTexQuadTinted(
                 0x258u,
                 v28,
                 v8,
                 v12,
                 v16,
                 COERCE_INT(0.0),
                 COERCE_INT(382.0),
                 COERCE_INT(73.0),
                 COERCE_INT(420.0),
                 v20,
                 v20);
      break;
    default:
      return result;
  }
  return result;
}
