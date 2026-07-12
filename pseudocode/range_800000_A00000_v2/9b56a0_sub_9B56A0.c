// Function: sub_9B56A0
// Address: 0x9b56a0
int __thiscall sub_9B56A0(float *this, int a2, float *a3)
{
  double v3; // st7
  double v4; // st6
  double v6; // st3
  double v7; // st7
  unsigned int v8; // [esp+0h] [ebp-20h]
  float v9; // [esp+4h] [ebp-1Ch]
  float v10; // [esp+8h] [ebp-18h]
  float v11; // [esp+Ch] [ebp-14h]
  float v12; // [esp+10h] [ebp-10h]
  float v13; // [esp+14h] [ebp-Ch]
  float v14; // [esp+18h] [ebp-8h]
  float v15; // [esp+1Ch] [ebp-4h]
  float v16; // [esp+2Ch] [ebp+Ch]

  v3 = a3[2];
  *(float *)&v8 = *(this + 10) * v3;
  v4 = a3[1];
  v9 = *(this + 9) * v4;
  v6 = *a3;
  v10 = *(this + 8) * v6;
  v11 = *(this + 6) * v3;
  v12 = *(this + 5) * v4;
  v13 = *(this + 4) * v6;
  v14 = v3 * *(this + 2);
  v15 = v4 * *(this + 1);
  v7 = v6 * *this;
  *(_DWORD *)(a2 + 12) = 0;
  v16 = v7;
  *(float *)a2 = v16;
  *(float *)(a2 + 4) = v15;
  *(float *)(a2 + 8) = v14;
  *(float *)(a2 + 16) = v13;
  *(float *)(a2 + 20) = v12;
  *(float *)(a2 + 24) = v11;
  *(_DWORD *)(a2 + 28) = 0;
  *(float *)(a2 + 32) = v10;
  *(float *)(a2 + 36) = v9;
  *(_QWORD *)(a2 + 40) = v8;
  return a2;
}
