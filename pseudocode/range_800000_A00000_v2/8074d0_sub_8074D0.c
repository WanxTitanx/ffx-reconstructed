// Function: sub_8074D0
// Address: 0x8074d0
int *__thiscall sub_8074D0(_DWORD *this, int *a2, int i_6)
{
  _BYTE *i_9; // edx
  int i; // edi
  int i_2; // ecx
  int i_1; // esi
  _DWORD *v8; // eax
  _DWORD *i_3; // ecx
  _DWORD *i_4; // eax
  int v11; // eax
  int *v12; // eax
  char v13; // cl
  _BYTE *i_5; // ecx
  int v15; // eax
  int i_7; // [esp+4h] [ebp-8h]
  int i_8; // [esp+8h] [ebp-4h]

  i_8 = i_6;
  if ( *(_BYTE *)(i_6 + 13) )
    std::_Xout_of_range("invalid map/set<T> iterator");
  sub_8069C0(&i_6);
  i_9 = (_BYTE *)i_8;
  if ( *(_BYTE *)(*(_DWORD *)i_8 + 13) )
  {
    i = *(_DWORD *)(i_8 + 8);
  }
  else if ( *(_BYTE *)(*(_DWORD *)(i_8 + 8) + 13) )
  {
    i = *(_DWORD *)i_8;
  }
  else
  {
    i_2 = i_6;
    i_7 = i_6;
    i = *(_DWORD *)(i_6 + 8);
    if ( i_6 != i_8 )
    {
      *(_DWORD *)(*(_DWORD *)i_8 + 4) = i_6;
      *(_DWORD *)i_2 = *(_DWORD *)i_8;
      if ( i_2 == *(_DWORD *)(i_8 + 8) )
      {
        i_1 = i_2;
      }
      else
      {
        i_1 = *(_DWORD *)(i_2 + 4);
        if ( !*(_BYTE *)(i + 13) )
          *(_DWORD *)(i + 4) = i_1;
        *(_DWORD *)i_1 = i;
        *(_DWORD *)(i_2 + 8) = *(_DWORD *)(i_8 + 8);
        *(_DWORD *)(*(_DWORD *)(i_8 + 8) + 4) = i_2;
      }
      if ( *(_DWORD *)(*this + 4) == i_8 )
      {
        *(_DWORD *)(*this + 4) = i_2;
      }
      else
      {
        v12 = *(int **)(i_8 + 4);
        if ( *v12 == i_8 )
          *v12 = i_2;
        else
          v12[2] = i_2;
      }
      *(_DWORD *)(i_2 + 4) = *(_DWORD *)(i_8 + 4);
      v13 = *(_BYTE *)(i_2 + 12);
      *(_BYTE *)(i_7 + 12) = *(_BYTE *)(i_8 + 12);
      i_9 = (_BYTE *)i_8;
      *(_BYTE *)(i_8 + 12) = v13;
      goto LABEL_35;
    }
  }
  i_1 = *(_DWORD *)(i_8 + 4);
  if ( !*(_BYTE *)(i + 13) )
    *(_DWORD *)(i + 4) = i_1;
  if ( *(_DWORD *)(*this + 4) == i_8 )
  {
    *(_DWORD *)(*this + 4) = i;
  }
  else if ( *(_DWORD *)i_1 == i_8 )
  {
    *(_DWORD *)i_1 = i;
  }
  else
  {
    *(_DWORD *)(i_1 + 8) = i;
  }
  v8 = (_DWORD *)*this;
  if ( *(_DWORD *)*this == i_8 )
  {
    if ( *(_BYTE *)(i + 13) )
    {
      i_3 = (_DWORD *)i_1;
    }
    else
    {
      i_4 = sub_806CF0((_DWORD *)i);
      i_9 = (_BYTE *)i_8;
      i_3 = i_4;
      v8 = (_DWORD *)*this;
    }
    *v8 = i_3;
  }
  if ( *(_BYTE **)(*this + 8) == i_9 )
  {
    if ( *(_BYTE *)(i + 13) )
    {
      *(_DWORD *)(*this + 8) = i_1;
    }
    else
    {
      v11 = sub_806CB0(i);
      i_9 = (_BYTE *)i_8;
      *(_DWORD *)(*this + 8) = v11;
    }
  }
LABEL_35:
  if ( i_9[12] != 1 )
    goto LABEL_60;
  if ( i == *(_DWORD *)(*this + 4) )
    goto LABEL_59;
  while ( *(_BYTE *)(i + 12) == 1 )
  {
    i_5 = *(_BYTE **)i_1;
    if ( i == *(_DWORD *)i_1 )
    {
      i_5 = *(_BYTE **)(i_1 + 8);
      if ( !i_5[12] )
      {
        i_5[12] = 1;
        *(_BYTE *)(i_1 + 12) = 0;
        sub_806C30(this, i_1);
        i_5 = *(_BYTE **)(i_1 + 8);
      }
      if ( i_5[13] )
        goto LABEL_53;
      if ( *(_BYTE *)(*(_DWORD *)i_5 + 12) != 1 || *(_BYTE *)(*((_DWORD *)i_5 + 2) + 12) != 1 )
      {
        if ( *(_BYTE *)(*((_DWORD *)i_5 + 2) + 12) == 1 )
        {
          *(_BYTE *)(*(_DWORD *)i_5 + 12) = 1;
          i_5[12] = 0;
          sub_806E30(this, i_5);
          i_5 = *(_BYTE **)(i_1 + 8);
        }
        i_5[12] = *(_BYTE *)(i_1 + 12);
        *(_BYTE *)(i_1 + 12) = 1;
        *(_BYTE *)(*((_DWORD *)i_5 + 2) + 12) = 1;
        sub_806C30(this, i_1);
        break;
      }
    }
    else
    {
      if ( !i_5[12] )
      {
        i_5[12] = 1;
        *(_BYTE *)(i_1 + 12) = 0;
        sub_806E30(this, (_DWORD *)i_1);
        i_5 = *(_BYTE **)i_1;
      }
      if ( i_5[13] )
        goto LABEL_53;
      if ( *(_BYTE *)(*((_DWORD *)i_5 + 2) + 12) != 1 || *(_BYTE *)(*(_DWORD *)i_5 + 12) != 1 )
      {
        if ( *(_BYTE *)(*(_DWORD *)i_5 + 12) == 1 )
        {
          *(_BYTE *)(*((_DWORD *)i_5 + 2) + 12) = 1;
          i_5[12] = 0;
          sub_806C30(this, (int)i_5);
          i_5 = *(_BYTE **)i_1;
        }
        i_5[12] = *(_BYTE *)(i_1 + 12);
        *(_BYTE *)(i_1 + 12) = 1;
        *(_BYTE *)(*(_DWORD *)i_5 + 12) = 1;
        sub_806E30(this, (_DWORD *)i_1);
        break;
      }
    }
    i_5[12] = 0;
LABEL_53:
    i = i_1;
    i_1 = *(_DWORD *)(i_1 + 4);
    if ( i == *(_DWORD *)(*this + 4) )
      break;
  }
  i_9 = (_BYTE *)i_8;
LABEL_59:
  *(_BYTE *)(i + 12) = 1;
LABEL_60:
  FFX_Memory_Free(i_9);
  v15 = *(this + 1);
  if ( v15 )
    *(this + 1) = v15 - 1;
  *a2 = i_6;
  return a2;
}
