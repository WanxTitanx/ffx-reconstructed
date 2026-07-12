// Function: sub_A0E520
// Address: 0xa0e520
// Size: 0x7b

int __cdecl sub_A0E520(_DWORD *a1)
{
  int result; // eax
  char n2; // dl
  int v3; // esi
  int v4; // esi
  _DWORD *v5; // esi

  result = (int)a1; /*0xa0e523*/
  if ( a1 ) /*0xa0e528*/
  {
    n2 = *((_BYTE *)a1 + 4); /*0xa0e52a*/
    if ( n2 ) /*0xa0e534*/
    {
      if ( n2 == 1 ) /*0xa0e537*/
      {
        if ( n2 == 1 ) /*0xa0e55e*/
        {
          v4 = *a1; /*0xa0e560*/
          if ( *a1 ) /*0xa0e560*/
          {
            result = sub_596130(*a1); /*0xa0e568*/
            if ( (_BYTE)result ) /*0xa0e56f*/
              return sub_59D090(v4); /*0xa0e575*/
          }
        }
      }
      else if ( n2 == 2 && n2 == 2 ) /*0xa0e53f*/
      {
        v3 = *a1; /*0xa0e541*/
        if ( *a1 ) /*0xa0e541*/
        {
          result = sub_596140(*a1); /*0xa0e549*/
          if ( (_BYTE)result ) /*0xa0e550*/
            return sub_59D280(v3); /*0xa0e556*/
        }
      }
    }
    else
    {
      v5 = (_DWORD *)*a1; /*0xa0e57e*/
      if ( *a1 ) /*0xa0e57e*/
      {
... [1194 chars total]