// Function: sub_A2E880
// Address: 0xa2e880
// Size: 0x4b
// Prototype: 

int __cdecl sub_A2E880(int a1)
{
  int v1; // ecx
  _DWORD *v2; // edx

  v1 = dword_1A85390;
  v2 = &dword_1A85390;
  if ( dword_1A85390 )
  {
    while ( v1 + 8 != a1 + 8 )
    {
      v2 = (_DWORD *)(v1 + 8);
      v1 = *(_DWORD *)(v1 + 8);
      if ( !v1 )
        return 0;
    }
    if ( v1 )
    {
      *v2 = *(_DWORD *)(v1 + 8);
      *(_DWORD *)(v1 + 8) = 0;
    }
  }
  return 0;
}

