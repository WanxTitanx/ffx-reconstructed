// Function: sub_A7B1A0
// Address: 0xa7b1a0
// Size: 0x4f
// Prototype: 

unsigned int __cdecl sub_A7B1A0(_BYTE *a1, const char *a2)
{
  const char *v2; // esi
  unsigned int v4; // edx
  _BYTE *v5; // edi
  char v6; // cl

  v2 = a2;
  if ( a2 )
  {
    v4 = strlen(a2);
    v5 = a1;
    do
    {
      v6 = *v2;
      *v5 = *v2 == 10 ? 0 : *v2;
      ++v2;
      ++v5;
    }
    while ( v6 );
    return v4 + 1;
  }
  else
  {
    *a1 = 0;
    return 0;
  }
}

