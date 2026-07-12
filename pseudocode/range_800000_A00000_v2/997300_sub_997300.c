// Function: sub_997300
// Address: 0x997300
float *__thiscall sub_997300(float *this, float *a2, float *a3)
{
  float *result; // eax
  double v4; // [esp+4h] [ebp-2Ch]
  double v5; // [esp+Ch] [ebp-24h]
  double v6; // [esp+14h] [ebp-1Ch]
  float v7; // [esp+20h] [ebp-10h]
  float v8; // [esp+24h] [ebp-Ch]
  float v9; // [esp+24h] [ebp-Ch]
  float v10; // [esp+24h] [ebp-Ch]
  float v11; // [esp+24h] [ebp-Ch]
  float v12; // [esp+28h] [ebp-8h]
  float v13; // [esp+38h] [ebp+8h]
  float v14; // [esp+3Ch] [ebp+Ch]
  float v15; // [esp+3Ch] [ebp+Ch]
  float v16; // [esp+3Ch] [ebp+Ch]

  result = a2;
  v14 = *a3 * 0.5;
  v6 = a2[1];
  v12 = *a2;
  v5 = a2[2];
  v8 = sin(v14);
  v4 = v8;
  v9 = v12 * v12 + v6 * v6 + v5 * v5;
  v10 = sqrt(v9);
  v7 = v14;
  v11 = v4 / v10;
  v13 = v5 * v11;
  v15 = v6 * v11;
  *this = v11 * v12;
  *(this + 1) = v15;
  *(this + 2) = v13;
  v16 = cos(v7);
  *(this + 3) = v16;
  return result;
}
