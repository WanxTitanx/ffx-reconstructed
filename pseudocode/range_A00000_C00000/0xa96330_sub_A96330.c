// Function: sub_A96330
// Address: 0xa96330
// Size: 0x107
// Prototype: 

int __fastcall sub_A96330(int a1, int a2, int a3)
{
  int v4; // esi
  int v5; // edi
  int v6; // edx
  int v7; // esi
  float v8; // xmm0_4
  int v9; // eax
  int v10; // ecx
  float v11; // xmm1_4
  int i; // ecx
  int result; // eax
  float j; // xmm0_4

  v4 = *(_DWORD *)(a1 + 36);
  v5 = 0;
  sub_A96440(*(_DWORD *)(a1 + 40));
  v6 = a3;
  v7 = **(_DWORD **)(a1 + 20) - (v4 >> 1) - *(_DWORD *)(a1 + 28);
  if ( *(int *)a1 > 1 )
  {
    do
    {
      v8 = *(float *)(a2 + 4 * v7);
      if ( v8 > *(float *)(*(_DWORD *)(a1 + 4) + 32) )
        v8 = *(float *)(*(_DWORD *)(a1 + 4) + 32);
      v9 = ((*(_DWORD *)(*(_DWORD *)(a1 + 20) + 4 * v5) + *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4 * v5 + 4)) >> 1)
         - *(_DWORD *)(a1 + 28);
      v10 = v7 + 1;
      if ( v7 + 1 <= v9 )
      {
        do
        {
          v11 = *(float *)(a2 + 4 * v7++ + 4);
          ++v10;
          if ( v11 <= -9999.0 || v8 <= v11 )
          {
            v9 = ((*(_DWORD *)(*(_DWORD *)(a1 + 20) + 4 * v5) + *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4 * v5 + 4)) >> 1)
               - *(_DWORD *)(a1 + 28);
            if ( v8 != -9999.0 )
              continue;
          }
          v8 = v11;
        }
        while ( v10 <= v9 );
        v6 = a3;
      }
      for ( i = v7 + *(_DWORD *)(a1 + 28); v5 < *(_DWORD *)a1; ++v5 )
      {
        if ( *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4 * v5) > i )
          break;
        if ( v8 > *(float *)(v6 + 4 * v5) )
          *(float *)(v6 + 4 * v5) = v8;
      }
    }
    while ( v5 + 1 < *(_DWORD *)a1 );
  }
  result = *(_DWORD *)(a1 + 40);
  for ( j = *(float *)(a2 + 4 * result - 4); v5 < *(_DWORD *)a1; ++v5 )
  {
    if ( j > *(float *)(v6 + 4 * v5) )
      *(float *)(v6 + 4 * v5) = j;
  }
  return result;
}

