// Function: sub_8EC250
// Address: 0x8ec250
int __cdecl sub_8EC250(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v10[38]; // [esp+0h] [ebp-9Ch] BYREF

  *(float *)v10 = (float)a2;
  *(float *)&v10[1] = (float)a3;
  v10[7] = a9;
  v10[15] = a9;
  *(float *)&v10[8] = (float)a4;
  v10[36] = 0;
  v10[37] = 0;
  *(float *)&v10[9] = (float)a5;
  v10[4] = a6;
  v10[5] = a7;
  v10[6] = a8;
  v10[12] = a6;
  v10[13] = a7;
  v10[14] = a8;
  sub_63F090((int)v10, 0, 1, 0, 0.0);
  return a1;
}
