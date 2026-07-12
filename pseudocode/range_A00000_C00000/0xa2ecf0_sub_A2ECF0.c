// Function: sub_A2ECF0
// Address: 0xa2ecf0
// Size: 0x4b
// Prototype: 

int __cdecl sub_A2ECF0(int a1)
{
  int v1; // ecx
  _DWORD *v2; // edx

  v1 = dword_1A853CC;
  v2 = &dword_1A853CC;
  if ( dword_1A853CC )
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

