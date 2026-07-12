// Function: sub_8F8D50
// Address: 0x8f8d50
void __cdecl sub_8F8D50(int a1, float a2, int a3, float a4, float a5, int a6)
{
  char *v6; // edi
  int v7; // esi
  double v8; // st5
  float v9; // [esp+8h] [ebp-A8h] BYREF
  float v10; // [esp+Ch] [ebp-A4h] BYREF
  float v11; // [esp+10h] [ebp-A0h]
  int v12[38]; // [esp+14h] [ebp-9Ch] BYREF

  v12[36] = 0;
  v12[37] = 0;
  v6 = FFX_Menu2D_TexHandleByAtlasId(11980);
  FFX_Menu2D_GetAtlasDimensions_structural(11980, &v9, &v10);
  *(float *)v12 = a2;
  v12[1] = a3;
  v7 = 170 * (a1 / 9);
  v12[34] = 0;
  v11 = (float)v7;
  v8 = v11 / v9;
  LODWORD(v11) = 14 * (a1 % 9);
  *(float *)&v12[2] = v8;
  v11 = (float)SLODWORD(v11);
  v12[4] = 128;
  v12[5] = 128;
  v12[6] = 128;
  v12[7] = a6;
  *(float *)&v12[3] = v11 / v10;
  *(float *)&v12[8] = a2 + a4;
  *(float *)&v12[9] = *(float *)&a3 + a5;
  v11 = (float)(v7 + 170);
  *(float *)&v12[10] = v11 / v9;
  v11 = (float)(14 * (a1 % 9) + 14);
  v12[12] = 128;
  v12[13] = 128;
  v12[14] = 128;
  v12[15] = a6;
  *(float *)&v12[11] = v11 / v10;
  sub_63F090((int)v12, v6, 1, 0, 0.0);
}
