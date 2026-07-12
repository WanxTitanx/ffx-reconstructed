// Function: sub_A6A2B0
// Address: 0xa6a2b0
// Size: 0x61
// Prototype: 

int __cdecl sub_A6A2B0(int a1)
{
  int v1; // esi
  int v2; // edi
  int *v3; // ebx
  int v4; // eax
  int v5; // edx
  int v6; // eax
  bool v7; // zf

  v1 = 0;
  v2 = 0;
  v3 = (int *)(a1 + 16);
  if ( *(_WORD *)(a1 + 4) )
  {
    do
    {
      v4 = unknown_libname_741(*v3) + 32;
      if ( *(_BYTE *)(v4 + 1) == 16 )
      {
        do
        {
          v5 = *(__int16 *)(v4 + 2);
          v1 += v5;
          v6 = v4 + 28 * v5;
          v7 = *(_BYTE *)(v6 + 33) == 16;
          v4 = v6 + 32;
        }
        while ( v7 );
      }
      ++v2;
      v3 += 4;
    }
    while ( v2 < *(unsigned __int16 *)(a1 + 4) );
  }
  return v1;
}

