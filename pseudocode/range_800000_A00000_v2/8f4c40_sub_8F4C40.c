// Function: sub_8F4C40
// Address: 0x8f4c40
void __cdecl sub_8F4C40(float a1, int a2, float a3, float a4, unsigned int a5, int a6, int a7)
{
  float v7; // [esp+0h] [ebp-B0h]
  float v8; // [esp+4h] [ebp-ACh]
  float v9; // [esp+8h] [ebp-A8h]
  float v10; // [esp+8h] [ebp-A8h]
  float v11; // [esp+Ch] [ebp-A4h]
  float v12; // [esp+Ch] [ebp-A4h]
  float v13; // [esp+10h] [ebp-A0h]
  float v14; // [esp+10h] [ebp-A0h]
  int v15[38]; // [esp+14h] [ebp-9Ch] BYREF

  *(float *)v15 = a1;
  v15[1] = a2;
  v15[7] = HIBYTE(a5);
  v15[4] = (unsigned __int8)a5;
  v15[34] = 0;
  v15[36] = 0;
  v15[37] = 0;
  v15[5] = BYTE1(a5);
  v15[6] = BYTE2(a5);
  v9 = (float)a7;
  v7 = v9;
  v10 = (float)((unsigned __int8)a6 - (unsigned __int8)a5);
  v13 = (float)(unsigned __int8)a5;
  v15[12] = (int)(v10 * a3 / v7 + v13);
  v14 = (float)(BYTE1(a6) - BYTE1(a5));
  v11 = (float)BYTE1(a5);
  v15[13] = (int)(v14 * a3 / v7 + v11);
  v12 = (float)(BYTE2(a6) - BYTE2(a5));
  v8 = (float)BYTE2(a5);
  *(float *)&v15[8] = a1 + a3;
  v15[14] = (int)(v12 * a3 / v7 + v8);
  v15[15] = 128;
  *(float *)&v15[9] = *(float *)&a2 + a4;
  sub_63F090((int)v15, 0, 1, 0, 0.0);
}
