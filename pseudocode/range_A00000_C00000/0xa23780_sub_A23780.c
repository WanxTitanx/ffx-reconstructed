// Function: sub_A23780
// Address: 0xa23780
// Size: 0x13d
// Prototype: 

int __thiscall sub_A23780(_DWORD *this, unsigned int a2, unsigned int a3)
{
  _DWORD *this_1; // edx
  int v5; // esi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  int *v9; // esi
  int result; // eax
  int v11; // esi
  int *v12; // esi
  int v13; // esi
  unsigned int v14; // edi
  unsigned int v15; // ebx
  int *v16; // esi
  unsigned int v18; // [esp+18h] [ebp+8h]
  unsigned int v19; // [esp+1Ch] [ebp+Ch]

  this_1 = this;
  v5 = *(this + 26);
  if ( v5 )
  {
    v7 = a3 >> 1;
    v8 = a2 >> 1;
    v19 = a3 >> 1;
    v18 = a2 >> 1;
    if ( *(_BYTE *)(v5 + 4) )
      return 1;
    v9 = *(int **)v5;
    if ( !v9 )
      return 1;
    if ( v9[7] != v8 || v9[8] != v7 )
    {
      if ( sub_596120(v9) )
      {
        result = sub_59CDD0(v9);
        if ( result )
          return result;
      }
      result = sub_4C41C0(v9, v18, v19, *v9, 0);
      if ( result )
        return result;
      this_1 = this;
    }
  }
  v11 = this_1[28];
  if ( !v11 )
    goto LABEL_19;
  if ( *(_BYTE *)(v11 + 4) )
    return 1;
  v12 = *(int **)v11;
  if ( !v12 )
    return 1;
  if ( v12[7] != a2 >> 1 || v12[8] != a3 >> 1 )
  {
    if ( sub_596120(v12) )
    {
      result = sub_59CDD0(v12);
      if ( result )
        return result;
    }
    result = sub_4C41C0(v12, a2 >> 1, a3 >> 1, *v12, 0);
    if ( result )
      return result;
    this_1 = this;
  }
LABEL_19:
  v13 = this_1[27];
  if ( !v13 )
    return 0;
  v14 = a3 >> 1;
  v15 = a2 >> 1;
  if ( *(_BYTE *)(v13 + 4) )
    return 1;
  v16 = *(int **)v13;
  if ( !v16 )
    return 1;
  if ( v16[7] == v15 && v16[8] == v14 )
    return 0;
  if ( !sub_596120(v16) || (result = sub_59CDD0(v16)) == 0 )
  {
    result = sub_4C41C0(v16, v15, v14, *v16, 0);
    if ( !result )
      return 0;
  }
  return result;
}

