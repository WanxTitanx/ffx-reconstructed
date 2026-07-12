// Function: sub_8F59C0
// Address: 0x8f59c0
void __cdecl sub_8F59C0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  char *v8; // esi
  float v9; // [esp+4h] [ebp-A8h] BYREF
  float v10; // [esp+8h] [ebp-A4h] BYREF
  float v11; // [esp+Ch] [ebp-A0h]
  int v12[38]; // [esp+10h] [ebp-9Ch] BYREF

  v12[36] = 0;
  v12[37] = 0;
  v8 = FFX_Menu2D_TexHandleByAtlasId(16000);
  FFX_Menu2D_GetAtlasDimensions_structural(16000, &v9, &v10);
  v12[34] = 0;
  v11 = (float)a1;
  *(float *)v12 = v11 * 512.0 / 1920.0;
  v11 = (float)a2;
  *(float *)&v12[1] = v11 * 416.0 / 1080.0;
  v11 = (float)a5;
  *(float *)&v12[2] = v11 / v9;
  v11 = (float)a6;
  v12[7] = a7;
  v12[4] = 255;
  v12[5] = 255;
  v12[6] = 255;
  *(float *)&v12[3] = v11 / v10;
  v11 = (float)(a3 + a1);
  *(float *)&v12[8] = 512.0 * v11 / 1920.0;
  v11 = (float)(a4 + a2);
  *(float *)&v12[9] = 416.0 * v11 / 1080.0;
  v11 = (float)(a3 + a5);
  *(float *)&v12[10] = v11 / v9;
  v11 = (float)(a4 + a6);
  *(float *)&v12[11] = v11 / v10;
  v12[15] = a8;
  v12[12] = 255;
  v12[13] = 255;
  v12[14] = 255;
  sub_63F090((int)v12, v8, 1, 0, 0.0);
}
