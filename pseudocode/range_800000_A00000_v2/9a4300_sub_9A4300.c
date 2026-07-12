// Function: sub_9A4300
// Address: 0x9a4300
int __thiscall sub_9A4300(int this, float *a2)
{
  int v2; // edi
  int v3; // esi
  int v4; // edx
  float *v5; // ecx
  float v7; // [esp-20h] [ebp-2Ch]
  float v8; // [esp-1Ch] [ebp-28h]
  float v9; // [esp-18h] [ebp-24h]
  float v10; // [esp-8h] [ebp-14h]
  float v11; // [esp-4h] [ebp-10h]

  v2 = *(_DWORD *)(this + 1176);
  v3 = -1;
  v4 = 0;
  v10 = *(float *)(this + 1180) * *(float *)(this + 1180);
  if ( v2 > 0 )
  {
    v5 = (float *)(this + 24);
    do
    {
      v7 = *(v5 - 2) - *a2;
      v8 = *(v5 - 1) - a2[1];
      v9 = *v5 - a2[2];
      v11 = v7 * v7 + v8 * v8 + v9 * v9;
      if ( v10 > (double)v11 )
      {
        v10 = v7 * v7 + v8 * v8 + v9 * v9;
        v3 = v4;
      }
      ++v4;
      v5 += 72;
    }
    while ( v4 < v2 );
  }
  return v3;
}
