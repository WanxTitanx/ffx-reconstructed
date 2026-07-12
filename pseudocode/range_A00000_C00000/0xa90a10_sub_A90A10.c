// Function: sub_A90A10
// Address: 0xa90a10
// Size: 0x55
// Prototype: 

int __cdecl sub_A90A10(_DWORD *a1, _DWORD *a2)
{
  int v2; // eax
  int v3; // edi
  int i; // esi
  int v5; // eax

  v2 = a1[6];
  v3 = a1[1];
  if ( v2 <= -1 || v2 >= a1[5] )
    return 0;
  if ( a2 )
  {
    for ( i = 0; i < *(_DWORD *)(v3 + 4); *(_DWORD *)(a1[3] + 4 * i - 4) = v5 + 4 * a1[6] )
      v5 = *(_DWORD *)(a1[2] + 4 * i++);
    *a2 = a1[3];
  }
  return a1[5] - a1[6];
}

