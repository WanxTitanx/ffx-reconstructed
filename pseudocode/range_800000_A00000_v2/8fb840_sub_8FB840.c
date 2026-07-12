// Function: sub_8FB840
// Address: 0x8fb840
int __cdecl sub_8FB840(int n9, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // edi
  double v8; // st7
  int v10; // [esp+4h] [ebp-2Ch]
  float v11; // [esp+8h] [ebp-28h]
  float v12; // [esp+Ch] [ebp-24h]
  int v13; // [esp+14h] [ebp-1Ch]
  int v14; // [esp+18h] [ebp-18h]
  int v15; // [esp+1Ch] [ebp-14h]
  int v16; // [esp+4Ch] [ebp+1Ch]
  float v17; // [esp+50h] [ebp+20h]
  float v18; // [esp+50h] [ebp+20h]
  float v19; // [esp+50h] [ebp+20h]
  int v20; // [esp+50h] [ebp+20h]
  int v21; // [esp+50h] [ebp+20h]
  int v22; // [esp+50h] [ebp+20h]
  float v23; // [esp+50h] [ebp+20h]

  v7 = a6 | (a7 << 8);
  v17 = (float)(n9 % 5);
  *(float *)&v16 = (v17 * 49.0 + 444.0) * 0.0009765625;
  v18 = (float)(65 * (n9 / 5));
  v19 = 0.0009765625 * (v18 + 254.0);
  v8 = v19;
  *(float *)&v20 = v19 + 0.0634765625;
  v15 = v20;
  *(float *)&v21 = *(float *)&v16 + 0.0478515625;
  v14 = v21;
  *(float *)&v13 = v8;
  v12 = FFX_Menu2D_ScaleY_1080to416(45.0);
  v11 = FFX_Menu2D_ScaleX_1920to512(34.0);
  *(float *)&v22 = (float)a3;
  v10 = v22;
  v23 = (float)a2;
  return FFX_Menu2D_DrawTexQuadTinted(
           0x190u,
           v23,
           v10,
           v11,
           v12,
           v16,
           v13,
           v14,
           v15,
           a4 | ((a5 | (v7 << 8)) << 8),
           a4 | ((a5 | (v7 << 8)) << 8));
}
