// Function: sub_A25D50
// Address: 0xa25d50
// Size: 0x3b
// Prototype: 

void __cdecl sub_A25D50(_DWORD *a1, _DWORD *a2, int i_1)
{
  int i; // edi
  _DWORD *v6; // eax

  for ( i = i_1; i; --i )
  {
    v6 = a1;
    a1 += 4;
    if ( v6 )
    {
      *v6 = *a2;
      v6[1] = a2[1];
      v6[2] = a2[2];
      v6[3] = a2[3];
      a2 += 4;
    }
  }
}

