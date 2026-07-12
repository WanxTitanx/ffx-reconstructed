// Function: sub_8F8BB0
// Address: 0x8f8bb0
void __cdecl sub_8F8BB0(int a1, float a2, int a3, float a4, float a5)
{
  char *v5; // edi
  int v6; // esi
  double v7; // st5
  float v8; // [esp+8h] [ebp-A8h] BYREF
  float v9; // [esp+Ch] [ebp-A4h] BYREF
  float v10; // [esp+10h] [ebp-A0h]
  int v11[38]; // [esp+14h] [ebp-9Ch] BYREF

  v11[36] = 0;
  v11[37] = 0;
  v5 = FFX_Menu2D_TexHandleByAtlasId(11980);
  FFX_Menu2D_GetAtlasDimensions_structural(11980, &v8, &v9);
  *(float *)v11 = a2;
  v11[1] = a3;
  v6 = 170 * (a1 / 9);
  v11[34] = 0;
  v10 = (float)v6;
  v7 = v10 / v8;
  LODWORD(v10) = 14 * (a1 % 9);
  *(float *)&v11[2] = v7;
  v10 = (float)SLODWORD(v10);
  v11[4] = 128;
  v11[5] = 128;
  v11[6] = 128;
  v11[7] = 128;
  *(float *)&v11[3] = v10 / v9;
  *(float *)&v11[8] = a2 + a4;
  *(float *)&v11[9] = *(float *)&a3 + a5;
  v10 = (float)(v6 + 170);
  *(float *)&v11[10] = v10 / v8;
  v10 = (float)(14 * (a1 % 9) + 14);
  v11[12] = 128;
  v11[13] = 128;
  v11[14] = 128;
  v11[15] = 128;
  *(float *)&v11[11] = v10 / v9;
  sub_63F090((int)v11, v5, 1, 0, 0.0);
}
