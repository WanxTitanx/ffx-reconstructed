// Function: sub_A3FF80
// Address: 0xa3ff80
// Size: 0x5e
// Prototype: int __thiscall(_DWORD)

void *__thiscall sub_A3FF80(void *this)
{
  _DWORD *v2; // eax
  int i; // ecx
  int v5; // eax
  int v6; // ecx

  v2 = *(_DWORD **)this;
  if ( *(_BYTE *)(*(_DWORD *)this + 13) )
  {
    *(_DWORD *)this = v2[2];
    return this;
  }
  i = *v2;
  if ( *(_BYTE *)(*v2 + 13) )
  {
    for ( i = v2[1]; !*(_BYTE *)(i + 13); i = *(_DWORD *)(i + 4) )
    {
      if ( *(_DWORD *)this != *(_DWORD *)i )
        break;
      *(_DWORD *)this = i;
    }
    if ( *(_BYTE *)(*(_DWORD *)this + 13) )
      return this;
    goto LABEL_11;
  }
  v5 = *(_DWORD *)(i + 8);
  if ( *(_BYTE *)(v5 + 13) )
  {
LABEL_11:
    *(_DWORD *)this = i;
    return this;
  }
  do
  {
    v6 = v5;
    v5 = *(_DWORD *)(v5 + 8);
  }
  while ( !*(_BYTE *)(v5 + 13) );
  *(_DWORD *)this = v6;
  return this;
}

