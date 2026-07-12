// Function: sub_A9D940
// Address: 0xa9d940
// Size: 0x8a
// Prototype: 

int __fastcall sub_A9D940(int a1, _DWORD *a2)
{
  int v2; // esi
  _DWORD *v3; // edi
  int n7; // ecx
  int v7; // edx
  int v8; // eax

  v2 = *(_DWORD *)(a1 + 104);
  v3 = *(_DWORD **)(v2 + 120);
  n7 = 7;
  if ( !v3 )
    return 0;
  if ( a2 )
  {
    v7 = v3[26];
    if ( *(_DWORD *)(v3[16] + 104) != -80 )
    {
      if ( *(_DWORD *)(*(_DWORD *)(v3[16] + 104) + 80) )
        n7 = *(_DWORD *)(v2 + 124);
    }
    *a2 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * n7 + 12) + 8);
    v8 = **(_DWORD **)(v7 + 4 * n7 + 12) + (*(_DWORD *)(*(_DWORD *)(v7 + 4 * n7 + 12) + 4) + 7) / 8;
    a2[2] = 0;
    a2[1] = v8;
    a2[3] = v3[11];
    a2[4] = v3[12];
    a2[5] = v3[13];
    a2[6] = v3[14];
    a2[7] = v3[15];
  }
  *(_DWORD *)(v2 + 120) = 0;
  return 1;
}

