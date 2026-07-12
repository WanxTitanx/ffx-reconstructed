// Function: sub_A41FF0
// Address: 0xa41ff0
// Size: 0x259
// Prototype: _DWORD __stdcall(_BYTE *, int **i)

_BYTE *__thiscall sub_A41FF0(int ***this, _BYTE *a2, int **i)
{
  int **i_2; // edx
  int *i_9; // edi
  int **i_3; // ecx
  int *i_5; // esi
  int **v8; // eax
  int *i_6; // ecx
  int *i_7; // eax
  int *v11; // eax
  int ***v12; // eax
  char v13; // cl
  _BYTE *i_8; // ecx
  int v15; // eax
  int **i_4; // [esp+4h] [ebp-8h]
  int **i_1; // [esp+8h] [ebp-4h]

  i_1 = i;
  if ( *((_BYTE *)i + 13) )
    std::_Xout_of_range("invalid map/set<T> iterator");
  sub_A3FF00((int *)&i);
  i_2 = i_1;
  if ( *((_BYTE *)*i_1 + 13) )
  {
    i_9 = i_1[2];
  }
  else if ( *((_BYTE *)i_1[2] + 13) )
  {
    i_9 = *i_1;
  }
  else
  {
    i_3 = i;
    i_4 = i;
    i_9 = i[2];
    if ( i != i_1 )
    {
      (*i_1)[1] = (int)i;
      *i_3 = *i_1;
      if ( i_3 == (int **)i_1[2] )
      {
        i_5 = (int *)i_3;
      }
      else
      {
        i_5 = i_3[1];
        if ( !*((_BYTE *)i_9 + 13) )
          i_9[1] = (int)i_5;
        *i_5 = (int)i_9;
        i_3[2] = i_1[2];
        i_1[2][1] = (int)i_3;
      }
      if ( (*this)[1] == (int *)i_1 )
      {
        (*this)[1] = (int *)i_3;
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
  i_5 = i_1[1];
  if ( !*((_BYTE *)i_9 + 13) )
    i_9[1] = (int)i_5;
  if ( (*this)[1] == (int *)i_1 )
  {
    (*this)[1] = i_9;
  }
  else if ( (int **)*i_5 == i_1 )
  {
    *i_5 = (int)i_9;
  }
  else
  {
    i_5[2] = (int)i_9;
  }
  v8 = *this;
  if ( **this == (int *)i_1 )
  {
    if ( *((_BYTE *)i_9 + 13) )
    {
      i_6 = i_5;
    }
    else
    {
      i_7 = (int *)sub_A419B0(i_9);
      i_2 = i_1;
      i_6 = i_7;
      v8 = *this;
    }
    *v8 = i_6;
  }
  if ( (*this)[2] == (int *)i_2 )
  {
    if ( *((_BYTE *)i_9 + 13) )
    {
      (*this)[2] = i_5;
    }
    else
    {
      v11 = (int *)sub_A41990(i_9);
      i_2 = i_1;
      (*this)[2] = v11;
    }
  }
LABEL_35:
  if ( *((_BYTE *)i_2 + 12) != 1 )
    goto LABEL_60;
  if ( i_9 == (*this)[1] )
    goto LABEL_59;
  while ( *((_BYTE *)i_9 + 12) == 1 )
  {
    i_8 = (_BYTE *)*i_5;
    if ( i_9 == (int *)*i_5 )
    {
      i_8 = (_BYTE *)i_5[2];
      if ( !i_8[12] )
      {
        i_8[12] = 1;
        *((_BYTE *)i_5 + 12) = 0;
        sub_A41930(i_5);
        i_8 = (_BYTE *)i_5[2];
      }
      if ( i_8[13] )
        goto LABEL_53;
      if ( *(_BYTE *)(*(_DWORD *)i_8 + 12) != 1 || *(_BYTE *)(*((_DWORD *)i_8 + 2) + 12) != 1 )
      {
        if ( *(_BYTE *)(*((_DWORD *)i_8 + 2) + 12) == 1 )
        {
          *(_BYTE *)(*(_DWORD *)i_8 + 12) = 1;
          i_8[12] = 0;
          sub_A41B40(this, i_8);
          i_8 = (_BYTE *)i_5[2];
        }
        i_8[12] = *((_BYTE *)i_5 + 12);
        *((_BYTE *)i_5 + 12) = 1;
        *(_BYTE *)(*((_DWORD *)i_8 + 2) + 12) = 1;
        sub_A41930(i_5);
        break;
      }
    }
    else
    {
      if ( !i_8[12] )
      {
        i_8[12] = 1;
        *((_BYTE *)i_5 + 12) = 0;
        sub_A41B40(this, i_5);
        i_8 = (_BYTE *)*i_5;
      }
      if ( i_8[13] )
        goto LABEL_53;
      if ( *(_BYTE *)(*((_DWORD *)i_8 + 2) + 12) != 1 || *(_BYTE *)(*(_DWORD *)i_8 + 12) != 1 )
      {
        if ( *(_BYTE *)(*(_DWORD *)i_8 + 12) == 1 )
        {
          *(_BYTE *)(*((_DWORD *)i_8 + 2) + 12) = 1;
          i_8[12] = 0;
          sub_A41930(i_8);
          i_8 = (_BYTE *)*i_5;
        }
        i_8[12] = *((_BYTE *)i_5 + 12);
        *((_BYTE *)i_5 + 12) = 1;
        *(_BYTE *)(*(_DWORD *)i_8 + 12) = 1;
        sub_A41B40(this, i_5);
        break;
      }
    }
    i_8[12] = 0;
LABEL_53:
    i_9 = i_5;
    i_5 = (int *)i_5[1];
    if ( i_9 == (*this)[1] )
      break;
  }
  i_2 = i_1;
LABEL_59:
  *((_BYTE *)i_9 + 12) = 1;
LABEL_60:
  FFX_Memory_Free(i_2);
  v15 = (int)*(this + 1);
  if ( v15 )
    *(this + 1) = (int **)(v15 - 1);
  *(_DWORD *)a2 = i;
  return a2;
}

