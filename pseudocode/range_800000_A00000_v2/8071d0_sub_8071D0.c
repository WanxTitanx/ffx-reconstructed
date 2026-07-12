// Function: sub_8071D0
// Address: 0x8071d0
_BYTE *__thiscall sub_8071D0(_DWORD *this, _BYTE *a2, int **i)
{
  int **i_2; // edx
  int *i_8; // edi
  int **i_3; // ecx
  int i_5; // esi
  _DWORD *v8; // eax
  _DWORD *i_6; // ecx
  _DWORD *i_7; // eax
  int v11; // eax
  int ***v12; // eax
  char v13; // cl
  _BYTE *i_9; // ecx
  int v15; // eax
  int **i_4; // [esp+4h] [ebp-8h]
  int **i_1; // [esp+8h] [ebp-4h]

  i_1 = i;
  if ( *((_BYTE *)i + 13) )
    std::_Xout_of_range("invalid map/set<T> iterator");
  sub_806970((int *)&i);
  i_2 = i_1;
  if ( *((_BYTE *)*i_1 + 13) )
  {
    i_8 = i_1[2];
  }
  else if ( *((_BYTE *)i_1[2] + 13) )
  {
    i_8 = *i_1;
  }
  else
  {
    i_3 = i;
    i_4 = i;
    i_8 = i[2];
    if ( i != i_1 )
    {
      (*i_1)[1] = (int)i;
      *i_3 = *i_1;
      if ( i_3 == (int **)i_1[2] )
      {
        i_5 = (int)i_3;
      }
      else
      {
        i_5 = (int)i_3[1];
        if ( !*((_BYTE *)i_8 + 13) )
          i_8[1] = i_5;
        *(_DWORD *)i_5 = i_8;
        i_3[2] = i_1[2];
        i_1[2][1] = (int)i_3;
      }
      if ( *(int ***)(*this + 4) == i_1 )
      {
        *(_DWORD *)(*this + 4) = i_3;
      }
      else
      {
        v12 = (int ***)i_1[1];
        if ( *v12 == i_1 )
          *v12 = i_3;
        else
          v12[2] = i_3;
      }
      i_3[1] = i_1[1];
      v13 = *((_BYTE *)i_3 + 12);
      *((_BYTE *)i_4 + 12) = *((_BYTE *)i_1 + 12);
      i_2 = i_1;
      *((_BYTE *)i_1 + 12) = v13;
      goto LABEL_35;
    }
  }
  i_5 = (int)i_1[1];
  if ( !*((_BYTE *)i_8 + 13) )
    i_8[1] = i_5;
  if ( *(int ***)(*this + 4) == i_1 )
  {
    *(_DWORD *)(*this + 4) = i_8;
  }
  else if ( *(int ***)i_5 == i_1 )
  {
    *(_DWORD *)i_5 = i_8;
  }
  else
  {
    *(_DWORD *)(i_5 + 8) = i_8;
  }
  v8 = (_DWORD *)*this;
  if ( *(int ***)*this == i_1 )
  {
    if ( *((_BYTE *)i_8 + 13) )
    {
      i_6 = (_DWORD *)i_5;
    }
    else
    {
      i_7 = sub_806CD0(i_8);
      i_2 = i_1;
      i_6 = i_7;
      v8 = (_DWORD *)*this;
    }
    *v8 = i_6;
  }
  if ( *(int ***)(*this + 8) == i_2 )
  {
    if ( *((_BYTE *)i_8 + 13) )
    {
      *(_DWORD *)(*this + 8) = i_5;
    }
    else
    {
      v11 = sub_806C90((int)i_8);
      i_2 = i_1;
      *(_DWORD *)(*this + 8) = v11;
    }
  }
LABEL_35:
  if ( *((_BYTE *)i_2 + 12) != 1 )
    goto LABEL_60;
  if ( i_8 == *(int **)(*this + 4) )
    goto LABEL_59;
  while ( *((_BYTE *)i_8 + 12) == 1 )
  {
    i_9 = *(_BYTE **)i_5;
    if ( i_8 == *(int **)i_5 )
    {
      i_9 = *(_BYTE **)(i_5 + 8);
      if ( !i_9[12] )
      {
        i_9[12] = 1;
        *(_BYTE *)(i_5 + 12) = 0;
        sub_806BD0(this, i_5);
        i_9 = *(_BYTE **)(i_5 + 8);
      }
      if ( i_9[13] )
        goto LABEL_53;
      if ( *(_BYTE *)(*(_DWORD *)i_9 + 12) != 1 || *(_BYTE *)(*((_DWORD *)i_9 + 2) + 12) != 1 )
      {
        if ( *(_BYTE *)(*((_DWORD *)i_9 + 2) + 12) == 1 )
        {
          *(_BYTE *)(*(_DWORD *)i_9 + 12) = 1;
          i_9[12] = 0;
          sub_806DD0(this, i_9);
          i_9 = *(_BYTE **)(i_5 + 8);
        }
        i_9[12] = *(_BYTE *)(i_5 + 12);
        *(_BYTE *)(i_5 + 12) = 1;
        *(_BYTE *)(*((_DWORD *)i_9 + 2) + 12) = 1;
        sub_806BD0(this, i_5);
        break;
      }
    }
    else
    {
      if ( !i_9[12] )
      {
        i_9[12] = 1;
        *(_BYTE *)(i_5 + 12) = 0;
        sub_806DD0(this, (_DWORD *)i_5);
        i_9 = *(_BYTE **)i_5;
      }
      if ( i_9[13] )
        goto LABEL_53;
      if ( *(_BYTE *)(*((_DWORD *)i_9 + 2) + 12) != 1 || *(_BYTE *)(*(_DWORD *)i_9 + 12) != 1 )
      {
        if ( *(_BYTE *)(*(_DWORD *)i_9 + 12) == 1 )
        {
          *(_BYTE *)(*((_DWORD *)i_9 + 2) + 12) = 1;
          i_9[12] = 0;
          sub_806BD0(this, (int)i_9);
          i_9 = *(_BYTE **)i_5;
        }
        i_9[12] = *(_BYTE *)(i_5 + 12);
        *(_BYTE *)(i_5 + 12) = 1;
        *(_BYTE *)(*(_DWORD *)i_9 + 12) = 1;
        sub_806DD0(this, (_DWORD *)i_5);
        break;
      }
    }
    i_9[12] = 0;
LABEL_53:
    i_8 = (int *)i_5;
    i_5 = *(_DWORD *)(i_5 + 4);
    if ( i_8 == *(int **)(*this + 4) )
      break;
  }
  i_2 = i_1;
LABEL_59:
  *((_BYTE *)i_8 + 12) = 1;
LABEL_60:
  FFX_Memory_Free(i_2);
  v15 = *(this + 1);
  if ( v15 )
    *(this + 1) = v15 - 1;
  *(_DWORD *)a2 = i;
  return a2;
}
