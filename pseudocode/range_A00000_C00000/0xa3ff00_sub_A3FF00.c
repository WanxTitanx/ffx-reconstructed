// Function: sub_A3FF00
// Address: 0xa3ff00
// Size: 0x4f
// Prototype: 

int *__thiscall sub_A3FF00(int *this)
{
  int v2; // eax
  int **j_1; // ecx
  int *j; // eax
  int i; // eax

  v2 = *this;
  if ( *(_BYTE *)(*this + 13) )
    return this;
  j_1 = *(int ***)(v2 + 8);
  if ( *((_BYTE *)j_1 + 13) )
  {
    for ( i = *(_DWORD *)(v2 + 4); !*(_BYTE *)(i + 13); i = *(_DWORD *)(i + 4) )
    {
      if ( *this != *(_DWORD *)(i + 8) )
        break;
      *this = i;
    }
    *this = i;
    return this;
  }
  for ( j = *j_1; !*((_BYTE *)j + 13); j = (int *)*j )
    j_1 = (int **)j;
  *this = (int)j_1;
  return this;
}

