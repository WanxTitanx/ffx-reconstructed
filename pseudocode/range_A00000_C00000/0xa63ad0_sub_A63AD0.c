// Function: sub_A63AD0
// Address: 0xa63ad0
// Size: 0x27
// Prototype: 

void __cdecl sub_A63AD0(_BYTE *a1, char *a2)
{
  char v2; // cl
  _BYTE *v3; // eax

  v2 = *a2;
  if ( *a2 )
  {
    v3 = a1;
    do
    {
      *v3 = v2;
      v2 = (v3++)[a2 - a1 + 1];
    }
    while ( v2 );
  }
}

