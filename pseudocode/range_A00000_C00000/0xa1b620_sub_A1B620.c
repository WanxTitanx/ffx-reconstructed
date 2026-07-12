// Function: sub_A1B620
// Address: 0xa1b620
// Size: 0xb8
// Prototype: 

float *__cdecl sub_A1B620(float *a1, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st7
  double v5; // st7
  double v6; // st7
  float v8; // [esp+0h] [ebp-1Ch]
  float v9; // [esp+4h] [ebp-18h]
  float v10; // [esp+8h] [ebp-14h]
  float v11; // [esp+Ch] [ebp-10h]
  float v12; // [esp+10h] [ebp-Ch]
  float v13; // [esp+14h] [ebp-8h]
  float v14; // [esp+18h] [ebp-4h]
  float v15; // [esp+18h] [ebp-4h]
  float v16; // [esp+28h] [ebp+Ch]
  float v17; // [esp+2Ch] [ebp+10h]
  float v18; // [esp+2Ch] [ebp+10h]

  v9 = *a2;
  v8 = *a3;
  v11 = a2[1];
  v10 = a3[1];
  v14 = a2[2];
  v12 = a3[2];
  v17 = a3[3];
  v3 = a2[3];
  if ( v17 <= v3 )
    v3 = v17;
  v13 = v3;
  v4 = v14;
  if ( v12 <= (double)v14 )
    v4 = v12;
  v15 = v4;
  v5 = v11;
  if ( v10 <= (double)v11 )
    v5 = v10;
  v18 = v5;
  v6 = v9;
  if ( v8 <= (double)v9 )
    v6 = v8;
  v16 = v6;
  *a1 = v16;
  a1[1] = v18;
  a1[2] = v15;
  a1[3] = v13;
  return a1;
}

