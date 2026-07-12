// Function: sub_A23280
// Address: 0xa23280
// Size: 0x16f
// Prototype: 

int __thiscall sub_A23280(_DWORD *this, unsigned int a2, unsigned int a3)
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
  int v12; // esi
  unsigned int v13; // edi
  unsigned int v14; // ebx
  int *v15; // esi
  int *v17; // [esp+10h] [ebp-8h]
  int n3_1; // [esp+14h] [ebp-4h]

  v3 = a2 >> 2;
  v4 = a3 >> 2;
  n3 = 0;
  v6 = this + 39;
  n3_1 = 0;
  v17 = this + 39;
  do
  {
    v7 = *(v6 - 3);
    if ( !v7 )
      return 1;
    if ( *(_BYTE *)(v7 + 4) )
      return 1;
    v8 = *(int **)v7;
    if ( !v8 )
      return 1;
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
    v10 = *v17;
    if ( !*v17 )
      return 1;
    if ( *(_BYTE *)(v10 + 4) )
      return 1;
    v11 = *(int **)v10;
    if ( !v11 )
      return 1;
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
    v6 = v17 + 1;
    v3 >>= 1;
    v4 >>= 1;
    n3_1 = n3;
    ++v17;
  }
  while ( n3 < 3 );
  v12 = *(this + 42);
  v13 = a3 >> 1;
  v14 = a2 >> 1;
  if ( !v12 )
    return 1;
  if ( *(_BYTE *)(v12 + 4) )
    return 1;
  v15 = *(int **)v12;
  if ( !v15 )
    return 1;
  if ( v15[7] == v14 && v15[8] == v13 )
    return 0;
  if ( !sub_596120(v15) || (result = sub_59CDD0(v15)) == 0 )
  {
    result = sub_4C41C0(v15, v14, v13, *v15, 0);
    if ( !result )
      return 0;
  }
  return result;
}

