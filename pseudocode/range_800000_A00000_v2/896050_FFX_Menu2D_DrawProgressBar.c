// Function: FFX_Menu2D_DrawProgressBar
// Address: 0x896050
int __cdecl FFX_Menu2D_DrawProgressBar(int a1, float a2, float a3, float a4, float a5)
{
  double v5; // st7
  int v6; // edi
  int result; // eax
  double v8; // st7
  double v9; // st7
  int v10; // [esp+4h] [ebp-3Ch]
  float v11; // [esp+8h] [ebp-38h]
  float v12; // [esp+Ch] [ebp-34h]
  int v13; // [esp+14h] [ebp-2Ch]
  int v14; // [esp+14h] [ebp-2Ch]
  int v15; // [esp+14h] [ebp-2Ch]
  int v16; // [esp+14h] [ebp-2Ch]
  float v17; // [esp+18h] [ebp-28h]
  float v18; // [esp+18h] [ebp-28h]
  float v19; // [esp+18h] [ebp-28h]
  float v20; // [esp+18h] [ebp-28h]
  float v21; // [esp+1Ch] [ebp-24h]
  float v22; // [esp+1Ch] [ebp-24h]
  float v23; // [esp+1Ch] [ebp-24h]
  float v24; // [esp+1Ch] [ebp-24h]
  float v25; // [esp+1Ch] [ebp-24h]
  unsigned int v26; // [esp+20h] [ebp-20h]
  float v27; // [esp+34h] [ebp-Ch]
  float v28; // [esp+34h] [ebp-Ch]
  int v29; // [esp+34h] [ebp-Ch]
  float v30; // [esp+34h] [ebp-Ch]
  float v31; // [esp+34h] [ebp-Ch]
  float v32; // [esp+34h] [ebp-Ch]
  int v33; // [esp+34h] [ebp-Ch]
  float v34; // [esp+34h] [ebp-Ch]
  float v35; // [esp+34h] [ebp-Ch]
  float v36; // [esp+34h] [ebp-Ch]
  int v37; // [esp+34h] [ebp-Ch]
  float v38; // [esp+34h] [ebp-Ch]
  int v39; // [esp+38h] [ebp-8h]
  float v40; // [esp+3Ch] [ebp-4h]
  float v41; // [esp+58h] [ebp+18h]
  float v42; // [esp+58h] [ebp+18h]
  float v43; // [esp+58h] [ebp+18h]
  float v44; // [esp+58h] [ebp+18h]
  int v45; // [esp+58h] [ebp+18h]
  float v46; // [esp+58h] [ebp+18h]
  float v47; // [esp+58h] [ebp+18h]
  float v48; // [esp+58h] [ebp+18h]
  float v49; // [esp+58h] [ebp+18h]
  float v50; // [esp+58h] [ebp+18h]
  int v51; // [esp+58h] [ebp+18h]
  float v52; // [esp+58h] [ebp+18h]

  v5 = 4.0;
  v6 = unk_25D0AA4;
  v39 = unk_25D0AA4;
  if ( a1 >= unk_25D0AA4 )
  {
    FFX_Engine_GetTime();
    v40 = 4.0 * 3.0;
    sub_4CEBE0(v40);
    v26 = ((unsigned int)(__int64)(v40 * 32.0 + 96.0) << 24) + 8421504;
    v27 = FFX_Menu2D_ScaleY_1080to416(8.0) + a5;
    v12 = v27;
    v28 = FFX_Menu2D_ScaleX_1920to512(12.0) + a4;
    v11 = v28;
    *(float *)&v29 = a3 - FFX_Menu2D_ScaleY_1080to416(4.0);
    v10 = v29;
    v30 = a2 - FFX_Menu2D_ScaleX_1920to512(6.0);
    FFX_Menu2D_DrawTexQuadTinted(
      0xFFFFFFFF,
      v30,
      v10,
      v11,
      v12,
      COERCE_INT(870.0),
      COERCE_INT(260.0),
      COERCE_INT(1332.0),
      COERCE_INT(277.0),
      v26,
      v26);
    v5 = 4.0;
  }
  v21 = v5;
  v31 = FFX_Menu2D_ScaleY_1080to416(v21) + a5;
  v22 = v31;
  v32 = FFX_Menu2D_ScaleX_1920to512(4.0) + a4;
  v17 = v32;
  *(float *)&v33 = a3 - FFX_Menu2D_ScaleY_1080to416(2.0);
  v13 = v33;
  v34 = a2 - FFX_Menu2D_ScaleX_1920to512(2.0);
  FFX_Menu2D_DrawFilledRect(v34, v13, v17, v22, 0x80000000, 0x80000000);
  v35 = a5 - FFX_Menu2D_ScaleY_1080to416(2.0);
  v23 = v35;
  v36 = a4 - FFX_Menu2D_ScaleX_1920to512(2.0);
  v18 = v36;
  *(float *)&v37 = FFX_Menu2D_ScaleY_1080to416(1.0) + a3;
  v14 = v37;
  v38 = FFX_Menu2D_ScaleX_1920to512(1.0) + a2;
  result = FFX_Menu2D_DrawFilledRect(v38, v14, v18, v23, 0x401A1A1Au, 0x401A1A1Au);
  if ( a1 < v6 )
  {
    if ( a1 > 0 )
    {
      v47 = a5 - FFX_Menu2D_ScaleY_1080to416(2.0);
      v25 = v47;
      v48 = (float)a1;
      v9 = (a4 - FFX_Menu2D_ScaleX_1920to512(2.0)) * v48;
      v49 = (float)v39;
      v50 = v9 / v49;
      v20 = v50;
      *(float *)&v51 = FFX_Menu2D_ScaleY_1080to416(1.0) + a3;
      v16 = v51;
      v52 = FFX_Menu2D_ScaleX_1920to512(1.0) + a2;
      return FFX_Menu2D_DrawFilledRect(v52, v16, v20, v25, 0x8000D2FF, 0x80008AFF);
    }
  }
  else
  {
    v41 = a5 - FFX_Menu2D_ScaleY_1080to416(2.0);
    v24 = v41;
    v42 = (float)a1;
    v8 = (a4 - FFX_Menu2D_ScaleX_1920to512(2.0)) * v42;
    v43 = (float)v39;
    v44 = v8 / v43;
    v19 = v44;
    *(float *)&v45 = FFX_Menu2D_ScaleY_1080to416(1.0) + a3;
    v15 = v45;
    v46 = FFX_Menu2D_ScaleX_1920to512(1.0) + a2;
    return FFX_Menu2D_DrawFilledRect(v46, v15, v19, v24, 0x800053FF, 0x800053FF);
  }
  return result;
}
