// Function: sub_8F1F00
// Address: 0x8f1f00
int __cdecl sub_8F1F00(int a1, int a2, int a3, int a4, unsigned int a5)
{
  char *v5; // ebx
  double v6; // st7
  float v8; // [esp+Ch] [ebp-A8h] BYREF
  float v9; // [esp+10h] [ebp-A4h] BYREF
  float v10; // [esp+14h] [ebp-A0h]
  int v11[38]; // [esp+18h] [ebp-9Ch] BYREF

  v11[36] = 0;
  v11[37] = 0;
  v11[34] = 0;
  v5 = FFX_Menu2D_TexHandleByAtlasId(11980);
  FFX_Menu2D_GetAtlasDimensions_structural(11980, &v8, &v9);
  *(float *)v11 = (float)a3;
  *(float *)&v11[1] = (float)a4;
  LODWORD(v10) = 170 * (a2 / 9);
  v11[4] = 128;
  v11[5] = 128;
  v11[6] = 128;
  v11[7] = HIBYTE(a5);
  v10 = (float)SLODWORD(v10);
  v6 = v10 / v8;
  LODWORD(v10) = 14 * (a2 % 9);
  *(float *)&v11[2] = v6;
  v10 = (float)SLODWORD(v10);
  v11[12] = 128;
  v11[13] = 128;
  v11[14] = 128;
  v11[15] = HIBYTE(a5);
  *(float *)&v11[3] = v10 / v9;
  *(float *)&v11[8] = (float)(a3 + 170);
  *(float *)&v11[9] = (float)(a4 + 14);
  v10 = (float)(170 * (a2 / 9) + 170);
  *(float *)&v11[10] = v10 / v8;
  v10 = (float)(14 * (a2 % 9) + 14);
  *(float *)&v11[11] = v10 / v9;
  sub_63F090((int)v11, v5, 1, 0, 0.0);
  return a1;
}
