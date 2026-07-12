// Function: sub_A235F0
// Address: 0xa235f0
// Size: 0xc8
// Prototype: 

int __thiscall sub_A235F0(_DWORD *this, unsigned int a2, unsigned int a3)
{
  int v3; // esi
  int *v4; // esi
  int result; // eax
  int v6; // esi
  int *v7; // esi

  v3 = *(this + 822);
  if ( !v3 )
    return 1;
  if ( *(_BYTE *)(v3 + 4) )
    return 1;
  v4 = *(int **)v3;
  if ( !v4 )
    return 1;
  if ( v4[7] != a2 || v4[8] != a3 )
  {
    if ( sub_596120(v4) )
    {
      result = sub_59CDD0(v4);
      if ( result )
        return result;
    }
    result = sub_4C41C0(v4, a2, a3, *v4, 0);
    if ( result )
      return result;
  }
  v6 = *(this + 851);
  if ( !v6 )
    return 1;
  if ( *(_BYTE *)(v6 + 4) )
    return 1;
  v7 = *(int **)v6;
  if ( !v7 )
    return 1;
  if ( v7[7] == a2 && v7[8] == a3 )
    return 0;
  if ( !sub_596120(v7) || (result = sub_59CDD0(v7)) == 0 )
  {
    result = sub_4C41C0(v7, a2, a3, *v7, 0);
    if ( !result )
      return 0;
  }
  return result;
}

