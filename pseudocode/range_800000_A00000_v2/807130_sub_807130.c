// Function: sub_807130
// Address: 0x807130
int **__thiscall sub_807130(int ***this, int **a2, int **i_3, int **i_4)
{
  int *i_1; // eax
  int **i_5; // ecx
  int *i; // edx
  int *i_2; // eax
  _BYTE v10[4]; // [esp+8h] [ebp-4h] BYREF

  i_1 = (int *)i_3;
  if ( i_3 == (int **)**this && i_4 == *this )
  {
    sub_806FF0(this);
    *a2 = **this;
    return a2;
  }
  else
  {
    for ( ; i_3 != i_4; i_1 = (int *)i_3 )
    {
      i_5 = (int **)i_1;
      if ( !*((_BYTE *)i_1 + 13) )
      {
        i = (int *)i_1[2];
        if ( *((_BYTE *)i + 13) )
        {
          for ( i = (int *)i_1[1]; !*((_BYTE *)i + 13); i = (int *)i[1] )
          {
            if ( i_1 != (int *)i[2] )
              break;
            i_1 = i;
          }
        }
        else
        {
          i_2 = (int *)*i;
          if ( !*(_BYTE *)(*i + 13) )
          {
            do
            {
              i = i_2;
              i_2 = (int *)*i_2;
            }
            while ( !*((_BYTE *)i_2 + 13) );
          }
        }
        i_3 = (int **)i;
      }
      sub_8071D0(v10, i_5);
    }
    *a2 = i_1;
    return a2;
  }
}
