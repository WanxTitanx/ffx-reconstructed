// Function: sub_8FD390
// Address: 0x8fd390
void __cdecl sub_8FD390(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6[38]; // [esp+4h] [ebp-9Ch] BYREF

  v6[4] = (unsigned __int8)a5;
  *(float *)v6 = (float)a1;
  v6[5] = BYTE1(a5);
  *(float *)&v6[1] = (float)a2;
  v6[6] = BYTE2(a5);
  v6[7] = HIBYTE(a5);
  v6[12] = (unsigned __int8)a6;
  v6[13] = BYTE1(a6);
  v6[14] = BYTE2(a6);
  *(float *)&v6[8] = (float)(a3 + a1);
  *(float *)&v6[9] = (float)(a4 + a2);
  v6[36] = 0;
  v6[37] = 0;
  v6[32] = 1000;
  v6[34] = 0;
  v6[15] = HIBYTE(a6);
  sub_63F090((int)v6, 0, 1, 0, 0.0);
}
