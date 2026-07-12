// Function: sub_9BDE50
// Address: 0x9bde50
int __thiscall sub_9BDE50(float *this, int a2, float *a3)
{
  double v3; // st5
  double v4; // st4
  double v5; // st6
  double v7; // st3
  float v8; // [esp-20h] [ebp-2Ch]
  float v9; // [esp-1Ch] [ebp-28h]
  float v10; // [esp-18h] [ebp-24h]
  float v11; // [esp-10h] [ebp-1Ch]
  float v12; // [esp-Ch] [ebp-18h]
  float v13; // [esp-4h] [ebp-10h]

  v13 = *(this + 85);
  v3 = a3[2];
  v4 = *(this + 86);
  v5 = a3[1];
  v8 = v13 * v3 - v4 * v5;
  v11 = *a3;
  v7 = *(this + 84);
  *(_DWORD *)(a2 + 12) = 0;
  v12 = v7;
  v9 = v4 * v11 - v3 * v12;
  v10 = v5 * v12 - v13 * v11;
  *(float *)a2 = *(this + 80) + v8;
  *(float *)(a2 + 4) = *(this + 81) + v9;
  *(float *)(a2 + 8) = *(this + 82) + v10;
  return a2;
}
