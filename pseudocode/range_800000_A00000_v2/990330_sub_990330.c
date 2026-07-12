// Function: sub_990330
// Address: 0x990330
int __thiscall sub_990330(int this, float *a2, float *a3, float a4)
{
  double v4; // st6
  double v5; // st7
  double v6; // st7
  float v8; // [esp-20h] [ebp-2Ch]
  float v9; // [esp-1Ch] [ebp-28h]
  float v10; // [esp-18h] [ebp-24h]
  float v11; // [esp-10h] [ebp-1Ch]
  float v12; // [esp-10h] [ebp-1Ch]
  float v13; // [esp-10h] [ebp-1Ch]
  float v14; // [esp-Ch] [ebp-18h]
  float v15; // [esp-Ch] [ebp-18h]
  float v16; // [esp-Ch] [ebp-18h]
  float v17; // [esp-8h] [ebp-14h]
  float v18; // [esp-8h] [ebp-14h]
  float v19; // [esp-8h] [ebp-14h]

  v11 = *a2 - a4;
  v14 = a2[1] - a4;
  v4 = a2[2];
  *(float *)(this + 16) = v11;
  *(float *)(this + 20) = v14;
  v17 = v4 - a4;
  *(float *)(this + 24) = v17;
  *(_DWORD *)(this + 28) = 0;
  v12 = *a3 + a4;
  v15 = a3[1] + a4;
  v5 = a4 + a3[2];
  *(float *)(this + 32) = v12;
  v18 = v5;
  *(float *)(this + 36) = v15;
  *(float *)(this + 40) = v18;
  *(_DWORD *)(this + 44) = 0;
  v8 = *(float *)(this + 32) - *(float *)(this + 16);
  v9 = *(float *)(this + 36) - *(float *)(this + 20);
  v6 = *(float *)(this + 40) - *(float *)(this + 24);
  *(_BYTE *)(this + 72) = 1;
  v10 = v6;
  v13 = 65533.0 / v8;
  *(float *)(this + 48) = v13;
  v16 = 65533.0 / v9;
  *(float *)(this + 52) = v16;
  v19 = 65533.0 / v10;
  *(float *)(this + 56) = v19;
  *(_DWORD *)(this + 60) = 0;
  return 0;
}
