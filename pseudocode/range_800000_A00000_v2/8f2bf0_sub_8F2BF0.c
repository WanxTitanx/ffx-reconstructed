// Function: sub_8F2BF0
// Address: 0x8f2bf0
int __cdecl sub_8F2BF0(int a1, int a2, int a3, unsigned int a4, unsigned int a5)
{
  char *v5; // esi
  float v7; // [esp+4h] [ebp-A8h] BYREF
  float v8[2]; // [esp+8h] [ebp-A4h] BYREF
  int v9[38]; // [esp+10h] [ebp-9Ch] BYREF

  v9[36] = 0;
  v9[37] = 0;
  v5 = FFX_Menu2D_TexHandleByAtlasId(11948);
  FFX_Menu2D_GetAtlasDimensions_structural(11948, &v7, v8);
  *(float *)v9 = (float)a2;
  v9[4] = (unsigned __int8)a4;
  *(float *)&v9[1] = (float)a3;
  v9[5] = BYTE1(a4);
  v9[6] = BYTE2(a4);
  v9[7] = HIBYTE(a4);
  *(float *)&v9[2] = 0.0 / v7;
  *(float *)&v9[3] = 0.0 / v8[0];
  LODWORD(v8[1]) = a3 + 416;
  v9[12] = (unsigned __int8)a5;
  *(float *)&v9[8] = (float)(a2 + 512);
  v9[13] = BYTE1(a5);
  *(float *)&v9[9] = (float)(a3 + 416);
  v9[14] = BYTE2(a5);
  v9[15] = HIBYTE(a5);
  *(float *)&v9[10] = 512.0 / v7;
  *(float *)&v9[11] = 416.0 / v8[0];
  sub_63F090((int)v9, v5, 1, 0, 0.0);
  return a1;
}
