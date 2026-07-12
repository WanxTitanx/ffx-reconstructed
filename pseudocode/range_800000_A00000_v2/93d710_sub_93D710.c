// Function: sub_93D710
// Address: 0x93d710
double __cdecl sub_93D710(_DWORD *a1, float *a2, float *a3, int a4)
{
  double v4; // st7
  double v5; // st6
  double v6; // st4
  int v7; // eax
  double v8; // st4
  double v9; // rt2
  double v10; // st6
  double result; // st7
  double v12; // st5
  int v13; // eax
  double v14; // st5
  double v15; // rtt
  float v16; // [esp+4h] [ebp-14h] BYREF
  float v17; // [esp+8h] [ebp-10h]
  float v18; // [esp+Ch] [ebp-Ch]
  float v19; // [esp+10h] [ebp-8h]
  float v20; // [esp+14h] [ebp-4h]

  sub_93CBF0((int)&v16, a2, a3);
  v4 = v19;
  v20 = 1.0 / v19;
  v5 = v20;
  v16 = v16 * v20;
  v17 = v17 * v20;
  v18 = v18 * v20;
  if ( a4 )
  {
    v12 = v17;
    *a1 = (int)v16;
    v13 = (int)v12;
    v14 = v18;
    a1[1] = v13;
    v15 = v5;
    v10 = v4;
    result = v15;
    a1[2] = (int)v14;
  }
  else
  {
    v6 = v17 * 16.0;
    *a1 = (int)(v16 * 16.0);
    v7 = (int)v6;
    v8 = v18 * 16.0;
    a1[1] = v7;
    v9 = v5;
    v10 = v4 * 16.0;
    result = v9;
    a1[2] = (int)v8;
  }
  a1[3] = (int)v10;
  return result;
}
