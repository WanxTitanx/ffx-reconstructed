// Function: sub_A290D0
// Address: 0xa290d0
// Size: 0x70
// Prototype: int __cdecl(int, char *Str)

int __cdecl sub_A290D0(_BYTE *a1, char *Str)
{
  int v2; // ebx
  char *i; // esi

  v2 = 0;
  if ( !Str || !a1 )
    return 0;
  for ( i = sub_A29030(a1, Str); i; i = sub_A29030(i, Str) )
  {
    ++v2;
    if ( !*i )
      break;
    while ( !strchr(Str, *i) )
    {
      if ( !*++i )
        return v2;
    }
    if ( !*i )
      break;
  }
  return v2;
}

