// Function: sub_AA3D10
// Address: 0xaa3d10
// Size: 0x13b
// Prototype: 

char *__cdecl sub_AA3D10(_DWORD *a1, int a2)
{
  _DWORD *v3; // esi
  int v4; // eax
  float v5; // xmm1_4
  unsigned int v6; // eax
  int v7; // edx
  int v8; // eax
  _DWORD *v9; // ebx
  char *buf; // esi
  int j_1; // edx
  int j; // eax
  int v13; // ecx
  float v14; // xmm0_4
  float i; // [esp+Ch] [ebp-4h]
  float v17; // [esp+1Ch] [ebp+Ch]

  v3 = *(_DWORD **)(a2 + 20);
  v4 = sub_42EB10(a1 + 1, v3[3]);
  if ( v4 <= 0 )
    return 0;
  v5 = (float)v4;
  v6 = v3[5];
  v7 = 0;
  for ( i = (float)(v5 / (float)((1 << v3[3]) - 1)) * (float)(int)v3[4]; v6; v6 >>= 1 )
    ++v7;
  v8 = sub_42EB10(a1 + 1, v7);
  if ( v8 == -1 )
    return 0;
  if ( v8 >= v3[5] )
    return 0;
  v17 = 0.0;
  v9 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1[16] + 4) + 28) + 2848) + 56 * v3[v8 + 6]);
  buf = (char *)sub_A92150(a1, 4 * (*v9 + *(_DWORD *)(a2 + 4)) + 4);
  if ( sub_A93930(v9, buf, a1 + 1, *(_DWORD *)(a2 + 4)) == -1 )
    return 0;
  j_1 = *(_DWORD *)(a2 + 4);
  for ( j = 0; j < j_1; v17 = *(float *)&buf[4 * j - 4] )
  {
    v13 = 0;
    if ( j < j_1 )
    {
      do
      {
        if ( v13 >= *v9 )
          break;
        v14 = *(float *)&buf[4 * j++] + v17;
        ++v13;
        *(float *)&buf[4 * j - 4] = v14;
      }
      while ( j < *(_DWORD *)(a2 + 4) );
    }
    j_1 = *(_DWORD *)(a2 + 4);
  }
  *(float *)&buf[4 * *(_DWORD *)(a2 + 4)] = i;
  return buf;
}

