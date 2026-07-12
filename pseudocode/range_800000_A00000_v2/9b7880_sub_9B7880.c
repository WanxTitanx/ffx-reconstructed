// Function: sub_9B7880
// Address: 0x9b7880
double __thiscall sub_9B7880(int this, float *a2, int a3)
{
  float v4; // [esp-30h] [ebp-3Ch]
  float v5; // [esp-2Ch] [ebp-38h]
  float v6; // [esp-28h] [ebp-34h]
  float v7; // [esp-20h] [ebp-2Ch]
  float v8; // [esp-1Ch] [ebp-28h]
  float v9; // [esp-18h] [ebp-24h]
  float v10; // [esp-4h] [ebp-10h]

  if ( *(_DWORD *)a2 == *(_DWORD *)(this + 96) )
    return 1.0;
  if ( (*(_DWORD *)(*(_DWORD *)a2 + 216) & 4) != 0 )
    return 1.0;
  v7 = *(float *)(this + 32) - *(float *)(this + 16);
  v8 = *(float *)(this + 36) - *(float *)(this + 20);
  v9 = *(float *)(this + 40) - *(float *)(this + 24);
  v4 = v7 - 0.0;
  v5 = v8 - 0.0;
  v6 = v9 - 0.0;
  v10 = a2[5] * v5 + a2[4] * v4 + a2[6] * v6;
  if ( v10 >= -*(float *)(this + 100) )
    return 1.0;
  else
    return sub_5F3D20(a2, a3);
}
