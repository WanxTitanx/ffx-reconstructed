// Function: sub_9B5C70
// Address: 0x9b5c70
int __thiscall sub_9B5C70(int this, int a2)
{
  double v2; // st7
  int result; // eax
  float v4; // [esp-20h] [ebp-2Ch]
  float v5; // [esp-1Ch] [ebp-28h]
  float v6; // [esp-18h] [ebp-24h]
  float v7; // [esp-4h] [ebp-10h]

  if ( *(float *)(this + 352) != 0.0 )
  {
    v7 = 1.0 / *(float *)(this + 352);
    v4 = *(float *)a2 * v7;
    v5 = *(float *)(a2 + 4) * v7;
    v2 = v7 * *(float *)(a2 + 8);
    *(float *)(this + 384) = v4;
    *(float *)(this + 388) = v5;
    v6 = v2;
    *(float *)(this + 392) = v6;
    *(_DWORD *)(this + 396) = 0;
  }
  *(_DWORD *)(this + 400) = *(_DWORD *)a2;
  *(_DWORD *)(this + 404) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 408) = *(_DWORD *)(a2 + 8);
  result = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 412) = result;
  return result;
}
