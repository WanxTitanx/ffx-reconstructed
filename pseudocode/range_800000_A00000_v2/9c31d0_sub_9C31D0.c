// Function: sub_9C31D0
// Address: 0x9c31d0
double __thiscall sub_9C31D0(int this, int a2, int a3)
{
  float *v4; // eax
  double v5; // st7
  float v6; // [esp-30h] [ebp-3Ch]
  float v7; // [esp-2Ch] [ebp-38h]
  float v8; // [esp-28h] [ebp-34h]
  float v9; // [esp-20h] [ebp-2Ch]
  float v10; // [esp-1Ch] [ebp-28h]
  float v11; // [esp-18h] [ebp-24h]
  float v12; // [esp-Ch] [ebp-18h]
  float v13; // [esp-8h] [ebp-14h]
  float v14; // [esp-4h] [ebp-10h]

  if ( *(_DWORD *)a2 == *(_DWORD *)(this + 96) )
    return 1.0;
  if ( (_BYTE)a3 )
  {
    v9 = *(float *)(a2 + 16);
    v10 = *(float *)(a2 + 20);
    v11 = *(float *)(a2 + 24);
  }
  else
  {
    v4 = *(float **)(this + 80);
    v14 = *(float *)(a2 + 20);
    v13 = *(float *)(a2 + 16);
    v5 = *(float *)(a2 + 24);
    v6 = v4[6] * v5 + v4[5] * v14 + v13 * v4[4];
    v7 = v4[9] * v14 + v4[8] * v13 + v4[10] * v5;
    v9 = v6;
    v10 = v7;
    v8 = v5 * v4[14] + v14 * v4[13] + v13 * v4[12];
    v11 = v8;
  }
  v12 = *(float *)(this + 116) * v10 + *(float *)(this + 112) * v9 + *(float *)(this + 120) * v11;
  if ( *(float *)(this + 128) > (double)v12 )
    return 1.0;
  else
    return sub_5F3D20(a2, a3);
}
