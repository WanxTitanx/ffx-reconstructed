// Function: sub_A29030
// Address: 0xa29030
// Size: 0x49
// Prototype: int __cdecl(int, char *Str)

_BYTE *__cdecl sub_A29030(_BYTE *a1, char *Str)
{
  _BYTE *v2; // esi
  char Val; // al

  if ( !Str )
    return 0;
  v2 = a1;
  if ( !a1 )
    return 0;
  Val = *a1;
  if ( !*a1 )
    return 0;
  while ( strchr(Str, Val) )
  {
    Val = *++v2;
    if ( !Val )
      return 0;
  }
  if ( *v2 )
    return v2;
  else
    return 0;
}

