// Function: sub_807430
// Address: 0x807430
int *__thiscall sub_807430(int **this, int *a2, int i_3, int *i_5)
{
  int i_1; // eax
  int i_4; // ecx
  int i; // edx
  int *i_2; // eax
  int v10; // [esp+8h] [ebp-4h] BYREF

  i_1 = i_3;
  if ( i_3 == **this && i_5 == *this )
  {
    sub_807040();
    *a2 = **this;
    return a2;
  }
  else
  {
    for ( ; (int *)i_3 != i_5; i_1 = i_3 )
    {
      i_4 = i_1;
      if ( !*(_BYTE *)(i_1 + 13) )
      {
        i = *(_DWORD *)(i_1 + 8);
        if ( *(_BYTE *)(i + 13) )
        {
          for ( i = *(_DWORD *)(i_1 + 4); !*(_BYTE *)(i + 13); i = *(_DWORD *)(i + 4) )
          {
            if ( i_1 != *(_DWORD *)(i + 8) )
              break;
            i_1 = i;
          }
        }
        else
        {
          i_2 = *(int **)i;
          if ( !*(_BYTE *)(*(_DWORD *)i + 13) )
          {
            do
            {
              i = (int)i_2;
              i_2 = (int *)*i_2;
            }
            while ( !*((_BYTE *)i_2 + 13) );
          }
        }
        i_3 = i;
      }
      sub_8074D0(this, &v10, i_4);
    }
    *a2 = i_1;
    return a2;
  }
}
