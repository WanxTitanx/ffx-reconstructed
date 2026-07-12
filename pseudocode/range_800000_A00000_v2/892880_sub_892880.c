// Function: sub_892880
// Address: 0x892880
void __cdecl sub_892880(unsigned __int8 a1, float a2, float a3, float a4, float a5)
{
  double v5; // st7
  int v6; // [esp+4h] [ebp-38h]
  float v7; // [esp+8h] [ebp-34h]
  float v8; // [esp+Ch] [ebp-30h]
  int v9; // [esp+14h] [ebp-28h]
  int v10; // [esp+14h] [ebp-28h]
  int v11; // [esp+14h] [ebp-28h]
  int v12; // [esp+14h] [ebp-28h]
  float v13; // [esp+18h] [ebp-24h]
  float v14; // [esp+18h] [ebp-24h]
  float v15; // [esp+18h] [ebp-24h]
  float v16; // [esp+18h] [ebp-24h]
  float v17; // [esp+1Ch] [ebp-20h]
  float v18; // [esp+1Ch] [ebp-20h]
  float v19; // [esp+1Ch] [ebp-20h]
  float v20; // [esp+1Ch] [ebp-20h]
  float v21; // [esp+1Ch] [ebp-20h]
  unsigned int v22; // [esp+20h] [ebp-1Ch]
  float v23; // [esp+2Ch] [ebp-10h]
  float v24; // [esp+2Ch] [ebp-10h]
  int v25; // [esp+2Ch] [ebp-10h]
  float v26; // [esp+2Ch] [ebp-10h]
  float v27; // [esp+2Ch] [ebp-10h]
  float v28; // [esp+2Ch] [ebp-10h]
  int v29; // [esp+2Ch] [ebp-10h]
  float v30; // [esp+2Ch] [ebp-10h]
  float v31; // [esp+2Ch] [ebp-10h]
  float v32; // [esp+2Ch] [ebp-10h]
  int v33; // [esp+2Ch] [ebp-10h]
  float v34; // [esp+2Ch] [ebp-10h]
  float OverdriveChargeMax; // [esp+30h] [ebp-Ch]
  float OverdriveCharge; // [esp+34h] [ebp-8h]
  float v37; // [esp+38h] [ebp-4h]
  float v38; // [esp+54h] [ebp+18h]
  float v39; // [esp+54h] [ebp+18h]
  int v40; // [esp+54h] [ebp+18h]
  float v41; // [esp+54h] [ebp+18h]
  float v42; // [esp+54h] [ebp+18h]
  float v43; // [esp+54h] [ebp+18h]
  int v44; // [esp+54h] [ebp+18h]
  float v45; // [esp+54h] [ebp+18h]

  OverdriveChargeMax = (float)FFX_Btl_GetOverdriveChargeMax(a1);
  OverdriveCharge = (float)FFX_Btl_GetOverdriveCharge(a1);
  v5 = 4.0;
  if ( OverdriveChargeMax <= (double)OverdriveCharge )
  {
    FFX_Engine_GetTime();
    v37 = 4.0 * 3.0;
    sub_4CEBE0(v37);
    v22 = ((unsigned int)(__int64)(v37 * 32.0 + 96.0) << 24) + 8421504;
    v23 = FFX_Menu2D_ScaleY_1080to416(8.0) + a5;
    v8 = v23;
    v24 = FFX_Menu2D_ScaleX_1920to512(12.0) + a4;
    v7 = v24;
    *(float *)&v25 = a3 - FFX_Menu2D_ScaleY_1080to416(4.0);
    v6 = v25;
    v26 = a2 - FFX_Menu2D_ScaleX_1920to512(6.0);
    FFX_Menu2D_DrawTexQuadTinted(
      0xFFFFFFFF,
      v26,
      v6,
      v7,
      v8,
      COERCE_INT(870.0),
      COERCE_INT(260.0),
      COERCE_INT(1332.0),
      COERCE_INT(277.0),
      v22,
      v22);
    v5 = 4.0;
  }
  v17 = v5;
  v27 = FFX_Menu2D_ScaleY_1080to416(v17) + a5;
  v18 = v27;
  v28 = FFX_Menu2D_ScaleX_1920to512(4.0) + a4;
  v13 = v28;
  *(float *)&v29 = a3 - FFX_Menu2D_ScaleY_1080to416(2.0);
  v9 = v29;
  v30 = a2 - FFX_Menu2D_ScaleX_1920to512(2.0);
  FFX_Menu2D_DrawFilledRect(v30, v9, v13, v18, 0x80000000, 0x80000000);
  v31 = a5 - FFX_Menu2D_ScaleY_1080to416(2.0);
  v19 = v31;
  v32 = a4 - FFX_Menu2D_ScaleX_1920to512(2.0);
  v14 = v32;
  *(float *)&v33 = FFX_Menu2D_ScaleY_1080to416(1.0) + a3;
  v10 = v33;
  v34 = FFX_Menu2D_ScaleX_1920to512(1.0) + a2;
  FFX_Menu2D_DrawFilledRect(v34, v10, v14, v19, 0x401A1A1Au, 0x401A1A1Au);
  if ( OverdriveChargeMax > (double)OverdriveCharge )
  {
    if ( OverdriveCharge > 0.0 )
    {
      v42 = a5 - FFX_Menu2D_ScaleY_1080to416(2.0);
      v21 = v42;
      v43 = (a4 - FFX_Menu2D_ScaleX_1920to512(2.0)) * OverdriveCharge / OverdriveChargeMax;
      v16 = v43;
      *(float *)&v44 = FFX_Menu2D_ScaleY_1080to416(1.0) + a3;
      v12 = v44;
      v45 = FFX_Menu2D_ScaleX_1920to512(1.0) + a2;
      FFX_Menu2D_DrawFilledRect(v45, v12, v16, v21, 0x8000D2FF, 0x80008AFF);
    }
  }
  else
  {
    v38 = a5 - FFX_Menu2D_ScaleY_1080to416(2.0);
    v20 = v38;
    v39 = (a4 - FFX_Menu2D_ScaleX_1920to512(2.0)) * OverdriveCharge / OverdriveChargeMax;
    v15 = v39;
    *(float *)&v40 = FFX_Menu2D_ScaleY_1080to416(1.0) + a3;
    v11 = v40;
    v41 = FFX_Menu2D_ScaleX_1920to512(1.0) + a2;
    FFX_Menu2D_DrawFilledRect(v41, v11, v15, v20, 0x800053FF, 0x800053FF);
  }
}
