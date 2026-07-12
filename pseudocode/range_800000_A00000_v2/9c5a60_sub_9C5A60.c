// Function: sub_9C5A60
// Address: 0x9c5a60
float *__thiscall sub_9C5A60(float *this, float *a2)
{
  double v3; // st7
  double v5; // st6
  double v6; // st4
  double v7; // st3
  double v8; // st5
  float v9; // [esp+0h] [ebp-1Ch]
  float v10; // [esp+0h] [ebp-1Ch]
  float v11; // [esp+4h] [ebp-18h]
  float v12; // [esp+8h] [ebp-14h]
  float v13; // [esp+Ch] [ebp-10h]
  float v14; // [esp+14h] [ebp-8h]
  float v15; // [esp+18h] [ebp-4h]
  float v16; // [esp+24h] [ebp+8h]

  v15 = a2[3];
  v16 = *(this + 3);
  v13 = *a2;
  v14 = a2[1];
  v3 = a2[2];
  v9 = v3;
  v5 = *this;
  v6 = *(this + 1);
  v7 = *(this + 2);
  v8 = v9;
  v12 = v16 * v15 - v5 * v13 - v6 * v14 - v7 * v9;
  v11 = v9 * v16 + v7 * v15 + v14 * v5 - v6 * v13;
  *(this + 2) = v11;
  *(this + 3) = v12;
  v10 = v14 * v16 + v6 * v15 + v7 * v13 - v9 * v5;
  *this = v5 * v15 + v13 * v16 + v8 * v6 - v7 * v14;
  *(this + 1) = v10;
  return this;
}
