// Function: sub_A56E00
// Address: 0xa56e00
// Size: 0xc7
// Prototype: 

__int16 __cdecl sub_A56E00(__int16 a1, unsigned __int16 a2, unsigned __int16 **a3)
{
  __int16 result; // ax
  unsigned __int16 v4; // dx
  int v5; // ebx
  unsigned __int16 v6; // si
  unsigned __int16 *i; // edi
  unsigned int i_2; // ecx
  unsigned __int16 *i_1; // eax
  __int16 v10; // [esp+0h] [ebp-4h]
  unsigned __int16 v11; // [esp+10h] [ebp+Ch]

  result = a1;
  v4 = a2;
  if ( a1 != a2 )
  {
    v5 = dword_2305834[0];
    v6 = -1;
    v10 = -1;
    v11 = -1;
    for ( i = 0; ; i = 0 )
    {
      while ( 1 )
      {
        i_2 = v5 + 4 * (5 * *(__int16 *)(v5 + 4) + 10754);
        i_1 = (unsigned __int16 *)(v5 + 43016);
        if ( i )
          i_1 = i + 10;
        if ( (unsigned int)i_1 >= i_2 )
          break;
        while ( *i_1 != v4 )
        {
          if ( i_1[1] == v4 )
          {
            v6 = *i_1;
            goto LABEL_15;
          }
          i_1 += 10;
          if ( (unsigned int)i_1 >= i_2 )
            goto LABEL_10;
        }
        v6 = i_1[1];
LABEL_15:
        i = i_1;
        if ( v11 <= *(_WORD *)(v5 + 40 * v6 + 2092) )
        {
          v6 = v10;
        }
        else
        {
          v11 = *(_WORD *)(v5 + 40 * v6 + 2092);
          *a3 = i_1;
          v5 = dword_2305834[0];
          v10 = v6;
        }
      }
LABEL_10:
      result = -1;
      if ( v6 == 0xFFFF )
        break;
      if ( v6 == a1 )
        return v4;
      v4 = v6;
      v6 = -1;
      v10 = -1;
      v11 = -1;
    }
  }
  return result;
}

