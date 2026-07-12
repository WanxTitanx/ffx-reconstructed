// Function: sub_8F3EB0
// Address: 0x8f3eb0
void __cdecl sub_8F3EB0(int a1, int a2, int a3, int a4, unsigned int a5, int a6, int a7)
{
  int v7[38]; // [esp+8h] [ebp-9Ch] BYREF

  *(float *)v7 = (float)a1;
  *(float *)&v7[1] = (float)a2;
  v7[7] = HIBYTE(a5);
  v7[6] = BYTE2(a5);
  v7[5] = BYTE1(a5);
  v7[34] = 0;
  v7[36] = 0;
  v7[37] = 0;
  v7[4] = (unsigned __int8)a5;
  v7[15] = 128;
  v7[12] = (unsigned __int8)a5 + a3 * ((unsigned __int8)a6 - (unsigned __int8)a5) / a7;
  v7[13] = BYTE1(a5) + a3 * (BYTE1(a6) - BYTE1(a5)) / a7;
  v7[14] = BYTE2(a5) + a3 * (BYTE2(a6) - BYTE2(a5)) / a7;
  *(float *)&v7[8] = (float)(a3 + a1);
  *(float *)&v7[9] = (float)(a4 + a2);
  sub_63F090((int)v7, 0, 1, 0, 0.0);
}
