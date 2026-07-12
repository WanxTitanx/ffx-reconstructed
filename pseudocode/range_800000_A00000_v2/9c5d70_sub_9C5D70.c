// Function: sub_9C5D70
// Address: 0x9c5d70
void __thiscall sub_9C5D70(float *this, float *a2)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  double v5; // st7
  double v6; // st7
  float v7; // [esp+4h] [ebp-Ch]
  float v8; // [esp+4h] [ebp-Ch]
  float v9; // [esp+4h] [ebp-Ch]
  float v10; // [esp+8h] [ebp-8h]
  float v11; // [esp+8h] [ebp-8h]
  float v12; // [esp+18h] [ebp+8h]
  float v13; // [esp+18h] [ebp+8h]
  float v14; // [esp+18h] [ebp+8h]
  float v15; // [esp+18h] [ebp+8h]
  float v16; // [esp+18h] [ebp+8h]
  float v17; // [esp+18h] [ebp+8h]

  v3 = a2[1];
  v4 = -a2[2];
  v5 = v3;
  v10 = fabs(v3);
  if ( v10 > 0.00000011920929 )
  {
    v12 = v4 / v5;
    v13 = *(this + 121) / *(this + 120) * v12;
    v14 = v5 * v13;
    v15 = fabs(v14);
    if ( v4 <= 0.0 )
      v6 = -v15;
    else
      v6 = v15;
    v16 = v6;
    v11 = -v16;
    v17 = *a2;
    v7 = v17 * v17 + v3 * v3 + v11 * v11;
    v8 = sqrt(v7);
    v9 = 1.0 / v8;
    *a2 = v17 * v9;
    a2[1] = v3 * v9;
    a2[2] = v9 * v11;
  }
}
