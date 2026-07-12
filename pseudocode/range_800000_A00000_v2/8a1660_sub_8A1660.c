// Function: sub_8A1660
// Address: 0x8a1660
int __cdecl sub_8A1660(int n6, int n60, float a3, int a4)
{
  double v4; // st7
  int n60_10; // esi
  double v6; // st7
  double v7; // st7
  double v9; // st7
  int result; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  float v14; // [esp+8h] [ebp-1Ch]
  float v15; // [esp+Ch] [ebp-18h]
  float v16; // [esp+Ch] [ebp-18h]
  float v17; // [esp+Ch] [ebp-18h]
  float v18; // [esp+Ch] [ebp-18h]
  float v19; // [esp+Ch] [ebp-18h]
  float v20; // [esp+Ch] [ebp-18h]
  float v21; // [esp+Ch] [ebp-18h]
  float v22; // [esp+10h] [ebp-14h]
  float v23; // [esp+10h] [ebp-14h]
  float v24; // [esp+10h] [ebp-14h]
  float v25; // [esp+10h] [ebp-14h]
  float v26; // [esp+10h] [ebp-14h]
  float v27; // [esp+10h] [ebp-14h]
  float v28; // [esp+10h] [ebp-14h]
  float v29; // [esp+10h] [ebp-14h]
  float v30; // [esp+14h] [ebp-10h]
  float v31; // [esp+14h] [ebp-10h]
  float v32; // [esp+14h] [ebp-10h]
  float v33; // [esp+14h] [ebp-10h]
  float v34; // [esp+14h] [ebp-10h]
  float v35; // [esp+14h] [ebp-10h]
  float v36; // [esp+14h] [ebp-10h]
  float v37; // [esp+14h] [ebp-10h]
  float v38; // [esp+14h] [ebp-10h]
  float v39; // [esp+14h] [ebp-10h]
  float v40; // [esp+14h] [ebp-10h]
  float v41; // [esp+14h] [ebp-10h]
  float v42; // [esp+14h] [ebp-10h]
  float v43; // [esp+1Ch] [ebp-8h]
  float v44; // [esp+1Ch] [ebp-8h]
  float v45; // [esp+1Ch] [ebp-8h]
  float v46; // [esp+1Ch] [ebp-8h]
  float n60_1; // [esp+1Ch] [ebp-8h]
  float v48; // [esp+1Ch] [ebp-8h]
  float v49; // [esp+20h] [ebp-4h]
  float v50; // [esp+20h] [ebp-4h]
  float v51; // [esp+20h] [ebp-4h]
  float n60_3; // [esp+2Ch] [ebp+8h]
  float v53; // [esp+2Ch] [ebp+8h]
  float n60_4; // [esp+2Ch] [ebp+8h]
  float v55; // [esp+2Ch] [ebp+8h]
  float v56; // [esp+30h] [ebp+Ch]
  float v57; // [esp+30h] [ebp+Ch]
  float v58; // [esp+30h] [ebp+Ch]
  float v59; // [esp+30h] [ebp+Ch]
  float v60; // [esp+30h] [ebp+Ch]
  float n60_2; // [esp+30h] [ebp+Ch]
  float v62; // [esp+30h] [ebp+Ch]
  float n60_5; // [esp+30h] [ebp+Ch]
  float v64; // [esp+30h] [ebp+Ch]
  float n60_6; // [esp+30h] [ebp+Ch]
  float v66; // [esp+30h] [ebp+Ch]
  float n60_7; // [esp+30h] [ebp+Ch]
  float v68; // [esp+30h] [ebp+Ch]
  float n60_8; // [esp+30h] [ebp+Ch]
  float v70; // [esp+30h] [ebp+Ch]
  float n60_9; // [esp+30h] [ebp+Ch]
  float v72; // [esp+30h] [ebp+Ch]

  v4 = 45.0;
  n60_10 = n60;
  if ( n60 >= 60 )
  {
    v15 = FFX_Menu2D_ScaleY_1080to416(45.0);
    v43 = FFX_Menu2D_ScaleX_1920to512(2.0) * 40.0;
    FFX_Menu2D_DrawFilledRect(a3, a4, v43, v15, 0x807C0F59, 0x807C0F59);
    v4 = 45.0;
  }
  if ( (unsigned int)(n60 - 40) <= 0x13 )
  {
    v44 = (float)(n60 - 40);
    v16 = v4;
    v17 = FFX_Menu2D_ScaleY_1080to416(v16);
    v49 = FFX_Menu2D_ScaleX_1920to512(2.0) * v44;
    FFX_Menu2D_DrawFilledRect(a3, a4, v49, v17, 0x807C0F59, 0x807C0F59);
    if ( 2 * n60 <= 110 )
    {
      v6 = 80.0;
    }
    else
    {
      v50 = (float)(2 * (95 - n60));
      v6 = v50;
    }
    v30 = v6;
    v51 = FFX_Menu2D_ScaleX_1920to512(v30);
    v18 = FFX_Menu2D_ScaleY_1080to416(45.0);
    v45 = FFX_Menu2D_ScaleX_1920to512(2.0) * v44 + a3;
    FFX_Menu2D_DrawFilledRect(v45, a4, v51, v18, 0x80C13995, 0x80C13995);
  }
  if ( n60 < 20 )
  {
    v21 = FFX_Menu2D_ScaleY_1080to416(45.0);
    n60_1 = (float)n60;
    v48 = FFX_Menu2D_ScaleX_1920to512(2.0) * n60_1;
    FFX_Menu2D_DrawFilledRect(a3, a4, v48, v21, 0x80D675B5, 0x80D675B5);
  }
  else
  {
    if ( n60 < 40 )
    {
      v56 = (float)(n60 - 20);
      v46 = v56;
      v19 = FFX_Menu2D_ScaleY_1080to416(45.0);
      v57 = FFX_Menu2D_ScaleX_1920to512(2.0) * v56;
      FFX_Menu2D_DrawFilledRect(a3, a4, v57, v19, 0x80C13995, 0x80C13995);
      if ( 2 * n60_10 + 40 <= 110 )
      {
        v7 = 80.0;
      }
      else
      {
        v58 = (float)(2 * (75 - n60_10));
        v7 = v58;
      }
      v31 = v7;
      v59 = FFX_Menu2D_ScaleX_1920to512(v31);
      v20 = FFX_Menu2D_ScaleY_1080to416(45.0);
      v14 = v59;
      v60 = FFX_Menu2D_ScaleX_1920to512(2.0) * v46 + a3;
      FFX_Menu2D_DrawFilledRect(v60, a4, v14, v20, 0x80D675B5, 0x80D675B5);
    }
    n60 = 20;
  }
  v9 = 46.0;
  if ( n6 <= 7 )
  {
    if ( n6 == 6 )
    {
      v9 = 46.0;
      if ( sub_86C400() < 1076 )
      {
        v32 = FFX_Menu2D_ScaleY_1080to416(46.0);
        v22 = FFX_Menu2D_ScaleX_1920to512(70.0);
        n60_2 = (float)n60;
        v62 = FFX_Menu2D_ScaleX_1920to512(2.0) * n60_2 + a3;
        return sub_89E5D0(468, v62, a4, v22, v32);
      }
    }
    v33 = v9;
    v34 = FFX_Menu2D_ScaleY_1080to416(v33);
    v23 = FFX_Menu2D_ScaleX_1920to512(70.0);
    n60_3 = (float)n60;
    v53 = FFX_Menu2D_ScaleX_1920to512(2.0) * n60_3 + a3;
    sub_89E5D0(n6 + 440, v53, a4, v23, v34);
    v9 = 46.0;
  }
  result = n6 - 8;
  if ( (unsigned int)(n6 - 8) <= 9 )
  {
    v35 = v9;
    v36 = FFX_Menu2D_ScaleY_1080to416(v35);
    v24 = FFX_Menu2D_ScaleX_1920to512(70.0);
    n60_4 = (float)n60;
    v55 = FFX_Menu2D_ScaleX_1920to512(2.0) * n60_4 + a3;
    result = sub_89E5D0(448, v55, a4, v24, v36);
  }
  if ( n6 >= 20 )
  {
    v11 = sub_79AE40(n6);
    v37 = 46.0;
    switch ( v11 )
    {
      case 20:
        v38 = FFX_Menu2D_ScaleY_1080to416(v37);
        v25 = FFX_Menu2D_ScaleX_1920to512(70.0);
        n60_5 = (float)n60;
        v64 = FFX_Menu2D_ScaleX_1920to512(2.0) * n60_5 + a3;
        v12 = sub_79AE20(n6);
        return sub_89E5D0(v12 + 459, v64, a4, v25, v38);
      case 21:
        v39 = FFX_Menu2D_ScaleY_1080to416(v37);
        v26 = FFX_Menu2D_ScaleX_1920to512(70.0);
        n60_6 = (float)n60;
        v66 = FFX_Menu2D_ScaleX_1920to512(2.0) * n60_6 + a3;
        return sub_89E5D0(450, v66, a4, v26, v39);
      case 22:
        v40 = FFX_Menu2D_ScaleY_1080to416(v37);
        v27 = FFX_Menu2D_ScaleX_1920to512(70.0);
        n60_7 = (float)n60;
        v68 = FFX_Menu2D_ScaleX_1920to512(2.0) * n60_7 + a3;
        v13 = sub_79AE20(n6);
        return sub_89E5D0(v13 + 451, v68, a4, v27, v40);
      case 23:
        v41 = FFX_Menu2D_ScaleY_1080to416(v37);
        v28 = FFX_Menu2D_ScaleX_1920to512(70.0);
        n60_8 = (float)n60;
        v70 = FFX_Menu2D_ScaleX_1920to512(2.0) * n60_8 + a3;
        return sub_89E5D0(467, v70, a4, v28, v41);
      default:
        v42 = FFX_Menu2D_ScaleY_1080to416(v37);
        v29 = FFX_Menu2D_ScaleX_1920to512(70.0);
        n60_9 = (float)n60;
        v72 = FFX_Menu2D_ScaleX_1920to512(2.0) * n60_9 + a3;
        return sub_89E5D0(449, v72, a4, v29, v42);
    }
  }
  return result;
}
