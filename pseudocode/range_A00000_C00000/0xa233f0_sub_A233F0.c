// Function: sub_A233F0
// Address: 0xa233f0
// Size: 0xef
// Prototype: 

int __thiscall sub_A233F0(_DWORD *this, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // edi
  unsigned int v4; // ebx
  int n3; // eax
  _DWORD *v6; // esi
  int v7; // esi
  int *v8; // esi
  int result; // eax
  int v10; // esi
  int *v11; // esi
  int n3_1; // [esp+14h] [ebp+8h]
  int *i; // [esp+18h] [ebp+Ch]

  v3 = a2 >> 2;
  v4 = a3 >> 2;
  n3 = 0;
  v6 = this + 33;
  n3_1 = 0;
  for ( i = this + 33; ; ++i )
  {
    v7 = *(v6 - 3);
    if ( !v7 )
      break;
    if ( *(_BYTE *)(v7 + 4) )
      break;
    v8 = *(int **)v7;
    if ( !v8 )
      break;
    if ( v8[7] != v3 || v8[8] != v4 )
    {
      if ( sub_596120(v8) )
      {
        result = sub_59CDD0(v8);
        if ( result )
          return result;
      }
      result = sub_4C41C0(v8, v3, v4, *v8, 0);
      if ( result )
        return result;
      n3 = n3_1;
    }
    v10 = *i;
    if ( !*i )
      break;
    if ( *(_BYTE *)(v10 + 4) )
      break;
    v11 = *(int **)v10;
    if ( !v11 )
      break;
    if ( v11[7] != v3 || v11[8] != v4 )
    {
      if ( sub_596120(v11) )
      {
        result = sub_59CDD0(v11);
        if ( result )
          return result;
      }
      result = sub_4C41C0(v11, v3, v4, *v11, 0);
      if ( result )
        return result;
      n3 = n3_1;
    }
    ++n3;
    v6 = i + 1;
    v3 >>= 1;
    v4 >>= 1;
    n3_1 = n3;
    if ( n3 >= 3 )
      return 0;
  }
  return 1;
}

