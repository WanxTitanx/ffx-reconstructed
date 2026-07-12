// Function: sub_A3ECD0
// Address: 0xa3ecd0
// Size: 0x1ff
// Prototype: 

_DWORD *__thiscall sub_A3ECD0(_DWORD *this, _DWORD *a2, char a3, _DWORD *a4, int a5, int a6)
{
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  int *v11; // ecx
  int *v12; // esi
  int *v13; // edx
  _DWORD *v14; // edx
  _DWORD *v15; // ecx
  _DWORD *v16; // edx
  _DWORD *v17; // esi
  int v18; // ecx
  _DWORD *v19; // ecx
  int v20; // edx
  int v21; // ecx
  _DWORD *v22; // ecx
  _DWORD *v23; // ecx

  if ( *(this + 1) >= 0xCCCCCCBu )
    std::_Xlength_error("map/set<T> too long");
  v7 = sub_A3EC80(a5);
  ++*(this + 1);
  v8 = v7;
  *(_DWORD *)(v7 + 4) = a4;
  if ( a4 == (_DWORD *)*this )
  {
    *(_DWORD *)(*this + 4) = v7;
    *(_DWORD *)*this = v7;
    v9 = *this;
LABEL_9:
    *(_DWORD *)(v9 + 8) = v8;
    goto LABEL_10;
  }
  if ( !a3 )
  {
    a4[2] = v7;
    v9 = *this;
    if ( a4 != *(_DWORD **)(*this + 8) )
      goto LABEL_10;
    goto LABEL_9;
  }
  *a4 = v7;
  if ( a4 == *(_DWORD **)*this )
    *(_DWORD *)*this = v7;
LABEL_10:
  v10 = v8;
  while ( !*(_BYTE *)(*(_DWORD *)(v10 + 4) + 12) )
  {
    v11 = *(int **)(v10 + 4);
    v12 = (int *)v11[1];
    v13 = (int *)*v12;
    if ( v11 == (int *)*v12 )
    {
      v13 = (int *)v12[2];
      if ( *((_BYTE *)v13 + 12) )
      {
        if ( v10 == v11[2] )
        {
          v10 = *(_DWORD *)(v10 + 4);
          v14 = (_DWORD *)v11[2];
          v11[2] = *v14;
          if ( !*(_BYTE *)(*v14 + 13) )
            *(_DWORD *)(*v14 + 4) = v11;
          v14[1] = v11[1];
          if ( v11 == *(int **)(*this + 4) )
          {
            *(_DWORD *)(*this + 4) = v14;
          }
          else
          {
            v15 = (_DWORD *)v11[1];
            if ( v10 == *v15 )
              *v15 = v14;
            else
              v15[2] = v14;
          }
          *v14 = v10;
          *(_DWORD *)(v10 + 4) = v14;
        }
        *(_BYTE *)(*(_DWORD *)(v10 + 4) + 12) = 1;
        *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v10 + 4) + 4) + 12) = 0;
        v16 = *(_DWORD **)(*(_DWORD *)(v10 + 4) + 4);
        v17 = (_DWORD *)*v16;
        *v16 = *(_DWORD *)(*v16 + 8);
        v18 = v17[2];
        if ( !*(_BYTE *)(v18 + 13) )
          *(_DWORD *)(v18 + 4) = v16;
        v17[1] = v16[1];
        if ( v16 == *(_DWORD **)(*this + 4) )
        {
          *(_DWORD *)(*this + 4) = v17;
          v17[2] = v16;
        }
        else
        {
          v19 = (_DWORD *)v16[1];
          if ( v16 == (_DWORD *)v19[2] )
            v19[2] = v17;
          else
            *v19 = v17;
          v17[2] = v16;
        }
LABEL_49:
        v16[1] = v17;
        continue;
      }
    }
    else if ( *((_BYTE *)v13 + 12) )
    {
      if ( v10 == *v11 )
      {
        v10 = *(_DWORD *)(v10 + 4);
        v20 = *v11;
        *v11 = *(_DWORD *)(*v11 + 8);
        v21 = *(_DWORD *)(v20 + 8);
        if ( !*(_BYTE *)(v21 + 13) )
          *(_DWORD *)(v21 + 4) = v10;
        *(_DWORD *)(v20 + 4) = *(_DWORD *)(v10 + 4);
        if ( v10 == *(_DWORD *)(*this + 4) )
        {
          *(_DWORD *)(*this + 4) = v20;
        }
        else
        {
          v22 = *(_DWORD **)(v10 + 4);
          if ( v10 == v22[2] )
            v22[2] = v20;
          else
            *v22 = v20;
        }
        *(_DWORD *)(v20 + 8) = v10;
        *(_DWORD *)(v10 + 4) = v20;
      }
      *(_BYTE *)(*(_DWORD *)(v10 + 4) + 12) = 1;
      *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v10 + 4) + 4) + 12) = 0;
      v16 = *(_DWORD **)(*(_DWORD *)(v10 + 4) + 4);
      v17 = (_DWORD *)v16[2];
      v16[2] = *v17;
      if ( !*(_BYTE *)(*v17 + 13) )
        *(_DWORD *)(*v17 + 4) = v16;
      v17[1] = v16[1];
      if ( v16 == *(_DWORD **)(*this + 4) )
      {
        *(_DWORD *)(*this + 4) = v17;
      }
      else
      {
        v23 = (_DWORD *)v16[1];
        if ( v16 == (_DWORD *)*v23 )
          *v23 = v17;
        else
          v23[2] = v17;
      }
      *v17 = v16;
      goto LABEL_49;
    }
    *((_BYTE *)v11 + 12) = 1;
    *((_BYTE *)v13 + 12) = 1;
    *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v10 + 4) + 4) + 12) = 0;
    v10 = *(_DWORD *)(*(_DWORD *)(v10 + 4) + 4);
  }
  *(_BYTE *)(*(_DWORD *)(*this + 4) + 12) = 1;
  *a2 = v8;
  return a2;
}

