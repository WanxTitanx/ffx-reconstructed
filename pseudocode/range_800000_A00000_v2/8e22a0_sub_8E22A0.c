// Function: sub_8E22A0
// Address: 0x8e22a0
char __cdecl sub_8E22A0(int a1, float a2, int a3, int a4, int n4096)
{
  double v5; // st7
  double v6; // st7
  double v7; // st7
  int v9; // edi
  BOOL v10; // esi
  int v11; // eax
  double v12; // st7
  double v13; // st7
  char *v14; // eax
  char result; // al
  double v16; // st7
  float v17; // [esp+8h] [ebp-40h]
  float v18; // [esp+Ch] [ebp-3Ch]
  float v19; // [esp+14h] [ebp-34h]
  int v20; // [esp+1Ch] [ebp-2Ch]
  char n128; // [esp+24h] [ebp-24h]
  int v22; // [esp+34h] [ebp-14h] BYREF
  char v23[4]; // [esp+38h] [ebp-10h]
  float v24; // [esp+3Ch] [ebp-Ch]
  double v25; // [esp+40h] [ebp-8h]
  float v26; // [esp+50h] [ebp+8h]
  float v27; // [esp+50h] [ebp+8h]
  float v28; // [esp+54h] [ebp+Ch]
  float v29; // [esp+54h] [ebp+Ch]
  float n4096a; // [esp+60h] [ebp+18h]

  *(_DWORD *)v23 = n4096 / 32;
  v28 = FFX_Menu2D_ScaleX_1920to512(1304.0) + a2;
  v24 = (float)a1;
  v25 = FFX_Menu2D_ScaleY_1080to416(75.0) * v24;
  *((float *)&v25 + 1) = FFX_Menu2D_ScaleY_1080to416(194.0) + v25;
  v5 = *((float *)&v25 + 1);
  *((float *)&v25 + 1) = (float)n4096;
  v6 = v5 * *((float *)&v25 + 1);
  *((float *)&v25 + 1) = (float)(4096 - n4096);
  *((float *)&v25 + 1) = (v6 + *((float *)&v25 + 1) * 3.0) * 0.000244140625;
  v7 = v24 * 74.69999694824219;
  v24 = v7 + 67.0;
  *(float *)&v20 = v24;
  v24 = v7 + 0.0;
  v18 = FFX_Menu2D_ScaleY_1080to416(60.0);
  v17 = FFX_Menu2D_ScaleX_1920to512(476.0);
  FFX_Menu2D_DrawTexQuadTinted(
    0xFFFFFFFD,
    v28,
    SHIDWORD(v25),
    v17,
    v18,
    COERCE_INT(1118.0),
    SLODWORD(v24),
    COERCE_INT(1599.0),
    v20,
    ((n4096 / 32) << 24) + 8421504,
    ((n4096 / 32) << 24) + 8421504);
  v9 = sub_8E2270(a1);
  v10 = sub_8E2290(a1) == 0;
  v11 = sub_8DDF60(v9);
  sub_905290(v11, (int)&v22, v10, 0.77999997);
  n128 = v23[0];
  v12 = FFX_Menu2D_ScaleY_1080to416(7.0);
  v26 = v12 + *((float *)&v25 + 1);
  v19 = v26;
  v13 = FFX_Menu2D_ScaleX_1920to512(476.0);
  v27 = (v13 - *(float *)&v22) * 0.5 + v28;
  v14 = (char *)sub_8DDF60(v9);
  result = FFX_Menu2D_DrawStatusEffectTimerBarEx(v14, v27, v19, v10, 0.77999997, COERCE_INT(1.0), n128);
  if ( a1 == unk_1871508 && n4096 == 4096 )
  {
    v16 = FFX_Menu2D_ScaleY_1080to416(10.0);
    n4096a = v16 + *((float *)&v25 + 1);
    v29 = FFX_Menu2D_ScaleX_1920to512(115.0) + v28;
    return sub_8C0640(v29, n4096a, 0);
  }
  return result;
}
