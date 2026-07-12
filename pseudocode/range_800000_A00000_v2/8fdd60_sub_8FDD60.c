// Function: sub_8FDD60
// Address: 0x8fdd60
void __cdecl sub_8FDD60(__int16 *a1)
{
  int v1; // eax
  double v2; // st7
  int v3; // eax
  int v4; // [esp+0h] [ebp-A0h]
  int v5; // [esp+0h] [ebp-A0h]
  int v6[38]; // [esp+4h] [ebp-9Ch] BYREF

  v6[4] = *((unsigned __int8 *)a1 + 16);
  v6[5] = *((unsigned __int8 *)a1 + 20);
  v6[6] = *((unsigned __int8 *)a1 + 24);
  v6[7] = *((unsigned __int8 *)a1 + 28);
  v6[12] = *((unsigned __int8 *)a1 + 19);
  v6[13] = *((unsigned __int8 *)a1 + 23);
  v6[14] = *((unsigned __int8 *)a1 + 27);
  v6[15] = *((unsigned __int8 *)a1 + 31);
  v4 = a1[4];
  v1 = a1[3];
  *(float *)v6 = (float)*a1;
  v2 = (double)v4;
  v5 = v1;
  v3 = a1[7];
  *(float *)&v6[1] = v2;
  *(float *)&v6[8] = (float)v5;
  v6[36] = 0;
  *(float *)&v6[9] = (float)v3;
  v6[37] = 0;
  v6[32] = 1000;
  v6[34] = 0;
  sub_63F090((int)v6, 0, 1, 0, 0.0);
}
