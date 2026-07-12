// Function: sub_A23200
// Address: 0xa23200
// Size: 0x65
// Prototype: 

int __thiscall sub_A23200(_DWORD *this, unsigned int a2, unsigned int a3)
{
  int v3; // esi
  int *v4; // esi
  int result; // eax

  v3 = *(this + 23);
  if ( !v3 )
    return 1;
  if ( *(_BYTE *)(v3 + 4) )
    return 1;
  v4 = *(int **)v3;
  if ( !v4 )
    return 1;
  if ( v4[7] == a2 && v4[8] == a3 )
    return 0;
  if ( !sub_596120(v4) || (result = sub_59CDD0(v4)) == 0 )
  {
    result = sub_4C41C0(v4, a2, a3, *v4, 0);
    if ( !result )
      return 0;
  }
  return result;
}

