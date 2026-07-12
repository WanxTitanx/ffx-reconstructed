// Function: sub_AA3EB0
// Address: 0xaa3eb0
// Size: 0x1dd
// Prototype: 

int __fastcall sub_AA3EB0(int a1, int a2, int *a3)
{
  int v3; // ebx
  int result; // eax
  __int64 v6; // rax
  int v7; // esi
  int v8; // esi
  float v9; // xmm0_4
  int v10; // ecx
  float v11; // [esp+34h] [ebp-10h]
  float v13; // [esp+3Ch] [ebp-8h]
  float v14; // [esp+3Ch] [ebp-8h]
  int v15; // [esp+4Ch] [ebp+8h]

  v3 = *(_DWORD *)(a1 + 28);
  result = a3[2];
  if ( !*(_DWORD *)(result + 4 * v3) )
  {
    v6 = *(int *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 64) + 4) + 28) + 4 * v3);
    v7 = ((int)v6 - HIDWORD(v6)) >> 1;
    v15 = v7;
    v13 = (float)*(int *)(a2 + 4) * 0.5;
    libm_sse2_atan_precise();
    libm_sse2_atan_precise();
    v11 = (double)*a3
        / ((float)((float)(v13 * v13) * 0.0000000185) * 2.240000009536743
         + (float)(v13 * 0.00073999999) * 13.10000038146973
         + (float)(v13 * 0.000099999997));
    *(_DWORD *)(a3[2] + 4 * v3) = malloc_0(4 * v7 + 4);
    v8 = 0;
    if ( v15 > 0 )
    {
      v9 = (float)v15;
      do
      {
        v14 = (float)((float)((float)*(int *)(a2 + 4) * 0.5) / v9) * (float)v8;
        libm_sse2_atan_precise();
        libm_sse2_atan_precise();
        v10 = (int)floor(
                     ((float)((float)(v14 * v14) * 0.0000000185) * 2.240000009536743
                    + (float)(v14 * 0.00073999999) * 13.10000038146973
                    + (float)(v14 * 0.000099999997))
                   * v11);
        if ( v10 >= *a3 )
          v10 = *a3 - 1;
        v9 = (float)v15;
        ++v8;
        *(_DWORD *)(*(_DWORD *)(a3[2] + 4 * v3) + 4 * v8 - 4) = v10;
      }
      while ( v8 < v15 );
    }
    *(_DWORD *)(*(_DWORD *)(a3[2] + 4 * v3) + 4 * v8) = -1;
    a3[v3 + 3] = v15;
    return v15;
  }
  return result;
}

