// Function: sub_9C9DF0
// Address: 0x9c9df0
int __stdcall sub_9C9DF0(float *a1, float *a2, int a3)
{
  float v3; // xmm0_4
  float v4; // xmm0_4
  int result; // eax
  float v6; // [esp-20h] [ebp-2Ch]
  float v7; // [esp-1Ch] [ebp-28h]
  float v8; // [esp-18h] [ebp-24h]
  float v9; // [esp-10h] [ebp-1Ch]
  float v10; // [esp-10h] [ebp-1Ch]
  float v11; // [esp-10h] [ebp-1Ch]
  float v12; // [esp-Ch] [ebp-18h]
  float v13; // [esp-Ch] [ebp-18h]
  float v14; // [esp-Ch] [ebp-18h]
  float v15; // [esp-Ch] [ebp-18h]
  float v16; // [esp-8h] [ebp-14h]
  float v17; // [esp-4h] [ebp-10h]
  float v18; // [esp-4h] [ebp-10h]

  v3 = a1[3];
  v6 = *a1;
  v7 = a1[1];
  v8 = a1[2];
  v17 = v3;
  if ( v3 >= -1.0 )
  {
    if ( v3 > 1.0 )
      v17 = 1.0;
  }
  else
  {
    v17 = -1.0;
  }
  v12 = acos(v17);
  v13 = v12 * 2.0;
  *a2 = v13;
  if ( v13 > 3.141592741012573 )
  {
    v6 = -*a1;
    v4 = -a1[3];
    v7 = -a1[1];
    v8 = -a1[2];
    v18 = v4;
    if ( v4 >= -1.0 )
    {
      if ( v4 > 1.0 )
        v18 = 1.0;
    }
    else
    {
      v18 = -1.0;
    }
    v14 = acos(v18);
    *a2 = v14 * 2.0;
  }
  *(float *)a3 = v6;
  *(float *)(a3 + 4) = v7;
  *(float *)(a3 + 8) = v8;
  result = 0;
  *(_DWORD *)(a3 + 12) = 0;
  if ( *a2 > 0.00000011920929 )
  {
    v16 = *(float *)(a3 + 4);
    v15 = *(float *)(a3 + 8);
    v9 = *(float *)a3 * *(float *)a3 + v16 * v16 + v15 * v15;
    v10 = sqrt(v9);
    v11 = 1.0 / v10;
    *(float *)a3 = *(float *)a3 * v11;
    *(float *)(a3 + 4) = v16 * v11;
    *(float *)(a3 + 8) = v11 * v15;
  }
  return result;
}
