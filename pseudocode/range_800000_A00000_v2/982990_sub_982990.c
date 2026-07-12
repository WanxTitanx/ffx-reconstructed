// Function: sub_982990
// Address: 0x982990
int __thiscall sub_982990(float *this, int a2)
{
  double v2; // st6
  double v3; // st7
  float v4; // xmm0_4
  double v5; // st5
  float v7; // [esp-50h] [ebp-5Ch]
  float v8; // [esp-50h] [ebp-5Ch]
  float v9; // [esp-4Ch] [ebp-58h]
  float v10; // [esp-4Ch] [ebp-58h]
  float v11; // [esp-48h] [ebp-54h]
  float v12; // [esp-48h] [ebp-54h]
  float v13; // [esp-3Ch] [ebp-48h]
  float v14; // [esp-38h] [ebp-44h]
  float v15; // [esp-30h] [ebp-3Ch]
  float v16; // [esp-2Ch] [ebp-38h]
  float v17; // [esp-28h] [ebp-34h]
  float v18; // [esp-20h] [ebp-2Ch]
  float v19; // [esp-1Ch] [ebp-28h]

  v7 = -*(this + 12);
  v13 = *(this + 4);
  v9 = -*(this + 13);
  v14 = *(this + 8);
  v11 = -*(this + 14);
  v15 = *(this + 1);
  v2 = v9;
  v16 = *(this + 5);
  v17 = *(this + 9);
  v18 = *(this + 2);
  v3 = v7;
  v19 = *(this + 6);
  v4 = *(this + 10);
  v5 = *this * v7 + v13 * v9;
  *(float *)a2 = *this;
  *(float *)(a2 + 4) = v13;
  *(float *)(a2 + 8) = v14;
  *(_DWORD *)(a2 + 12) = 0;
  v8 = v14 * v11 + v5;
  *(float *)(a2 + 16) = v15;
  *(float *)(a2 + 20) = v16;
  *(float *)(a2 + 24) = v17;
  v10 = v16 * v9 + v15 * v3 + v17 * v11;
  v12 = v3 * v18 + v2 * v19 + v11 * v4;
  *(_DWORD *)(a2 + 28) = 0;
  *(float *)(a2 + 32) = v18;
  *(float *)(a2 + 36) = v19;
  *(float *)(a2 + 40) = v4;
  *(_DWORD *)(a2 + 44) = 0;
  *(float *)(a2 + 48) = v8;
  *(float *)(a2 + 52) = v10;
  *(float *)(a2 + 56) = v12;
  *(_DWORD *)(a2 + 60) = 0;
  return a2;
}
