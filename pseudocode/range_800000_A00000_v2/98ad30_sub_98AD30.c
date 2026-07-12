// Function: sub_98AD30
// Address: 0x98ad30
float *__thiscall sub_98AD30(float *this, float *a2, float *a3)
{
  float v5; // [esp-20h] [ebp-2Ch]
  float v6; // [esp-1Ch] [ebp-28h]
  float v7; // [esp-18h] [ebp-24h]
  float v8; // [esp-Ch] [ebp-18h]
  float v9; // [esp-8h] [ebp-14h]

  *(_DWORD *)this = &SupportVertexCallback::`vftable';
  *(this + 4) = 0.0;
  *(this + 5) = 0.0;
  *(this + 6) = 0.0;
  *(this + 7) = 0.0;
  *(this + 8) = *a3;
  *(this + 9) = a3[1];
  *(this + 10) = a3[2];
  *(this + 11) = a3[3];
  *(this + 12) = a3[4];
  *(this + 13) = a3[5];
  *(this + 14) = a3[6];
  *(this + 15) = a3[7];
  *(this + 16) = a3[8];
  *(this + 17) = a3[9];
  *(this + 18) = a3[10];
  *(this + 19) = a3[11];
  *(this + 20) = a3[12];
  *(this + 21) = a3[13];
  *(this + 22) = a3[14];
  *(this + 23) = a3[15];
  *(this + 24) = -9.9999998e17;
  v9 = a2[1];
  v8 = a2[2];
  v5 = *(this + 12) * v9 + *a2 * *(this + 8) + v8 * *(this + 16);
  v6 = *(this + 9) * *a2 + *(this + 13) * v9 + *(this + 17) * v8;
  v7 = v8 * *(this + 18) + v9 * *(this + 14) + *a2 * *(this + 10);
  *(this + 28) = v5;
  *(this + 29) = v6;
  *(this + 30) = v7;
  *(this + 31) = 0.0;
  return this;
}
