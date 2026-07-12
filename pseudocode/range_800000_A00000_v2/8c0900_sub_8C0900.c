// Function: sub_8C0900
// Address: 0x8c0900
void __cdecl sub_8C0900(float a1, int a2, float a3, float a4, unsigned int a5, unsigned int a6)
{
  int v6[38]; // [esp+0h] [ebp-9Ch] BYREF

  *(float *)v6 = a1;
  v6[4] = (unsigned __int8)a5;
  v6[1] = a2;
  v6[5] = BYTE1(a5);
  *(float *)&v6[8] = a1 + a3;
  v6[6] = BYTE2(a5);
  v6[7] = HIBYTE(a5);
  *(float *)&v6[9] = *(float *)&a2 + a4;
  v6[12] = (unsigned __int8)a6;
  v6[13] = BYTE1(a6);
  v6[14] = BYTE2(a6);
  v6[36] = 0;
  v6[37] = 0;
  v6[32] = 1000;
  v6[34] = 0;
  v6[15] = HIBYTE(a6);
  sub_63F090((int)v6, 0, 1, 0, 0.0);
}
