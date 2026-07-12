// Function: sub_8FB150
// Address: 0x8fb150
void __cdecl sub_8FB150(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8[38]; // [esp+4h] [ebp-9Ch] BYREF

  *(float *)v8 = (float)a1;
  *(float *)&v8[1] = (float)a2;
  *(float *)&v8[8] = (float)(a3 + a1);
  *(float *)&v8[9] = (float)(a4 + a2);
  v8[36] = 0;
  v8[37] = 0;
  v8[34] = 0;
  v8[4] = a5;
  v8[5] = a6;
  v8[6] = a7;
  v8[7] = a8;
  v8[12] = a5;
  v8[13] = a6;
  v8[14] = a7;
  v8[15] = a8;
  sub_63F090((int)v8, 0, 1, 0, 0.0);
}
