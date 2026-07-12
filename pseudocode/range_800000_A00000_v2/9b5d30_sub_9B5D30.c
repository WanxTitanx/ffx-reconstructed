// Function: sub_9B5D30
// Address: 0x9b5d30
int __thiscall sub_9B5D30(int this, float a2, float *a3)
{
  double v3; // st7
  double v4; // st5
  double v5; // st5
  double v6; // st5
  double v7; // st7
  double v8; // st7
  double v9; // st7
  float v11; // [esp-20h] [ebp-2Ch]
  float v12; // [esp-20h] [ebp-2Ch]
  float v13; // [esp-1Ch] [ebp-28h]
  float v14; // [esp-1Ch] [ebp-28h]
  float v15; // [esp-18h] [ebp-24h]
  float v16; // [esp-18h] [ebp-24h]
  float v17; // [esp-Ch] [ebp-18h]
  float v18; // [esp-8h] [ebp-14h]

  v3 = a2;
  if ( a2 == 0.0 )
  {
    *(_DWORD *)(this + 216) |= 1u;
    *(_DWORD *)(this + 352) = 0;
  }
  else
  {
    *(_DWORD *)(this + 216) &= ~1u;
    *(float *)(this + 352) = 1.0 / v3;
  }
  v11 = *(float *)(this + 400) * v3;
  v13 = *(float *)(this + 404) * v3;
  v4 = *(float *)(this + 408);
  *(float *)(this + 384) = v11;
  *(float *)(this + 388) = v13;
  v15 = v3 * v4;
  *(float *)(this + 392) = v15;
  *(_DWORD *)(this + 396) = 0;
  if ( a3[2] == 0.0 )
    v5 = 0.0;
  else
    v5 = 1.0 / a3[2];
  v17 = v5;
  if ( a3[1] == 0.0 )
    v6 = 0.0;
  else
    v6 = 1.0 / a3[1];
  if ( *a3 == 0.0 )
    v7 = 0.0;
  else
    v7 = 1.0 / *a3;
  *(float *)(this + 416) = v7;
  v18 = v6;
  *(float *)(this + 420) = v18;
  *(_QWORD *)(this + 424) = LODWORD(v17);
  v8 = *(float *)(this + 352);
  v12 = v8 * *(float *)(this + 368);
  v14 = *(float *)(this + 372) * v8;
  v9 = v8 * *(float *)(this + 376);
  *(float *)(this + 624) = v12;
  *(float *)(this + 628) = v14;
  v16 = v9;
  *(float *)(this + 632) = v16;
  *(_DWORD *)(this + 636) = 0;
  return 0;
}
