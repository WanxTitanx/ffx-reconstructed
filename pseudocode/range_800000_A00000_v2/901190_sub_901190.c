// Function: sub_901190
// Address: 0x901190
void __cdecl sub_901190(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7, unsigned int a8)
{
  int v8[38]; // [esp+0h] [ebp-9Ch] BYREF

  v8[4] = (unsigned __int8)a8;
  *(float *)v8 = (float)a1;
  *(float *)&v8[1] = (float)a2;
  v8[5] = BYTE1(a8);
  *(float *)&v8[8] = (float)a3;
  *(float *)&v8[9] = (float)a4;
  *(float *)&v8[16] = (float)a5;
  v8[6] = BYTE2(a8);
  *(float *)&v8[17] = (float)a6;
  v8[36] = 0;
  v8[37] = 0;
  v8[32] = 20;
  v8[34] = 0;
  v8[7] = HIBYTE(a8);
  v8[12] = (unsigned __int8)a7;
  v8[13] = BYTE1(a7);
  v8[14] = BYTE2(a7);
  v8[15] = HIBYTE(a7);
  v8[20] = (unsigned __int8)a7;
  v8[21] = BYTE1(a7);
  v8[22] = BYTE2(a7);
  v8[23] = HIBYTE(a7);
  sub_63F090((int)v8, 0, 0, 1, 0.0);
}
