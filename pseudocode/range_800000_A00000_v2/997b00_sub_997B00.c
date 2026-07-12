// Function: sub_997B00
// Address: 0x997b00
int __thiscall sub_997B00(float *this, int a2)
{
  double v2; // st7
  double v3; // st6
  float v5; // [esp-40h] [ebp-4Ch]
  float v6; // [esp-3Ch] [ebp-48h]
  float v7; // [esp-38h] [ebp-44h]
  float v8; // [esp-30h] [ebp-3Ch]
  float v9; // [esp-2Ch] [ebp-38h]
  float v10; // [esp-28h] [ebp-34h]
  float v11; // [esp-20h] [ebp-2Ch]
  float v12; // [esp-1Ch] [ebp-28h]
  float v13; // [esp-18h] [ebp-24h]
  float v14; // [esp-10h] [ebp-1Ch]
  float v15; // [esp-10h] [ebp-1Ch]
  float v16; // [esp-10h] [ebp-1Ch]
  float v17; // [esp-Ch] [ebp-18h]
  float v18; // [esp-Ch] [ebp-18h]
  float v19; // [esp-8h] [ebp-14h]

  v2 = *(this + 16);
  v8 = *(this + 24) - v2;
  v3 = *(this + 17);
  v9 = *(this + 25) - v3;
  v17 = *(this + 18);
  v10 = *(this + 26) - v17;
  v5 = *(this + 20) - v2;
  v6 = *(this + 21) - v3;
  v7 = *(this + 22) - v17;
  v11 = v6 * v10 - v7 * v9;
  *(float *)a2 = v11;
  v12 = v7 * v8 - v10 * v5;
  *(float *)(a2 + 4) = v12;
  v13 = v9 * v5 - v6 * v8;
  *(float *)(a2 + 8) = v13;
  *(_DWORD *)(a2 + 12) = 0;
  v19 = *(float *)(a2 + 4);
  v18 = *(float *)(a2 + 8);
  v14 = *(float *)a2 * *(float *)a2 + v19 * v19 + v18 * v18;
  v15 = sqrt(v14);
  v16 = 1.0 / v15;
  *(float *)a2 = *(float *)a2 * v16;
  *(float *)(a2 + 4) = v19 * v16;
  *(float *)(a2 + 8) = v16 * v18;
  return 0;
}
