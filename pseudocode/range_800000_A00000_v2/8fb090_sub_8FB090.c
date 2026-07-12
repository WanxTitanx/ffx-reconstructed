// Function: sub_8FB090
// Address: 0x8fb090
void __cdecl sub_8FB090(int a1, int a2, int a3, int a4, float n32, float a6, float n128, float a8)
{
  int v8; // [esp+0h] [ebp-9Ch] BYREF
  float v9[7]; // [esp+4h] [ebp-98h] BYREF
  float v10; // [esp+20h] [ebp-7Ch] BYREF
  float v11[29]; // [esp+24h] [ebp-78h] BYREF

  *(float *)&v8 = (float)a1;
  v9[6] = a8;
  v11[6] = a8;
  v9[0] = (float)a2;
  v10 = (float)a3;
  v11[0] = (float)a4;
  v11[27] = 0.0;
  v11[28] = 0.0;
  v11[25] = 0.0;
  v9[3] = n32;
  v9[4] = a6;
  v9[5] = n128;
  v11[3] = n32;
  v11[4] = a6;
  v11[5] = n128;
  if ( sub_8E58E0((float *)&v8, v9, &v10, v11) )
    sub_63F090((int)&v8, 0, 1, 0, 0.0);
}
