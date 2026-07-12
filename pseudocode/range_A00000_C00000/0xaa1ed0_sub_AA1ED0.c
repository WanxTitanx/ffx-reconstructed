// Function: sub_AA1ED0
// Address: 0xaa1ed0
// Size: 0x216
// Prototype: 

BOOL __fastcall sub_AA1ED0(int a1, int a2, int a3, int a4, int a5, int a6, float *a7)
{
  int v7; // edi
  int v8; // esi
  int v9; // ebx
  int v10; // edx
  int v11; // eax
  int v12; // esi
  float v13; // xmm1_4
  int n1023; // ecx
  float *v15; // eax
  float v16; // xmm5_4
  int v17; // edx
  int v19; // ebx
  float *v20; // edx
  int n1023_1; // ecx
  float v22; // xmm1_4
  int v23; // [esp+Ch] [ebp-18h]
  int v24; // [esp+10h] [ebp-14h]
  int v27; // [esp+1Ch] [ebp-8h]
  int v28; // [esp+20h] [ebp-4h]
  unsigned int v29; // [esp+2Ch] [ebp+8h]
  unsigned int v30; // [esp+2Ch] [ebp+8h]
  int v31; // [esp+30h] [ebp+Ch]
  int v32; // [esp+38h] [ebp+14h]

  v7 = a3;
  v8 = a4 - a3;
  v29 = abs32(a4 - a3);
  v9 = a2 - a1;
  v24 = a2 - a1;
  v10 = v8 / (a2 - a1);
  v23 = v10;
  v11 = v10 - 1;
  if ( v8 >= 0 )
    v11 = v10 + 1;
  v27 = v11;
  v12 = 0;
  v13 = *(float *)(a5 + 4 * a1);
  n1023 = (int)(float)((float)(v13 * 7.3142858) + 1023.5);
  if ( n1023 <= 1023 )
  {
    if ( n1023 < 0 )
      n1023 = 0;
  }
  else
  {
    n1023 = 1023;
  }
  v30 = v29 - abs32(v9 * v10);
  v15 = a7;
  v16 = a7[278];
  v31 = (v7 - n1023) * (v7 - n1023);
  v28 = 1;
  v17 = v31;
  if ( (float)(*(float *)(a6 + 4 * a1) + v16) >= v13
    && ((float)n1023 > (float)(a7[274] + (float)v7) || (float)((float)v7 - a7[275]) > (float)n1023) )
  {
    return 1;
  }
  v19 = a1 + 1;
  if ( a1 + 1 < a2 )
  {
    v32 = a6 - a5;
    v20 = (float *)(a5 + 4 * v19);
    while ( 1 )
    {
      v12 += v30;
      if ( v12 < v24 )
      {
        v7 += v23;
      }
      else
      {
        v12 -= v24;
        v7 += v27;
      }
      n1023_1 = (int)(float)((float)(*v20 * 7.3142858) + 1023.5);
      if ( n1023_1 <= 1023 )
      {
        if ( n1023_1 < 0 )
          n1023_1 = 0;
      }
      else
      {
        n1023_1 = 1023;
      }
      ++v28;
      v31 += (v7 - n1023_1) * (v7 - n1023_1);
      v15 = a7;
      if ( (float)(*(float *)((char *)v20 + v32) + v16) >= *v20
        && n1023_1
        && ((float)n1023_1 > (float)(a7[274] + (float)v7) || (float)((float)v7 - a7[275]) > (float)n1023_1) )
      {
        return 1;
      }
      ++v19;
      ++v20;
      if ( v19 >= a2 )
      {
        v17 = v31;
        break;
      }
    }
  }
  v22 = v15[276];
  return (float)((float)(v15[274] * v15[274]) / (float)v28) <= v22
      && (float)((float)(v15[275] * v15[275]) / (float)v28) <= v22
      && (float)(v17 / v28) > v22;
}

