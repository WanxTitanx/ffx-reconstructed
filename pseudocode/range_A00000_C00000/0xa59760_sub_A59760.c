// Function: sub_A59760
// Address: 0xa59760
// Size: 0x99
// Prototype: _DWORD __cdecl(__int16, int (__cdecl *sub_A49440)(int, int), _DWORD *)

unsigned __int16 *__cdecl sub_A59760(unsigned __int16 a1, int (__cdecl *sub_A49440)(int, int), _DWORD *a3)
{
  unsigned __int16 *result; // eax
  unsigned __int16 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int16 v6; // cx

  result = (unsigned __int16 *)sub_A49440(dword_2305834[0] + 40 * a1 + 2056, (int)a3);
  if ( !result )
  {
    v4 = 0;
    do
    {
      v5 = dword_2305834[0] + 4 * (5 * *(__int16 *)(dword_2305834[0] + 4) + 10754);
      result = (unsigned __int16 *)(dword_2305834[0] + 43016);
      if ( v4 )
        result = v4 + 10;
      if ( (unsigned int)result >= v5 )
        break;
      while ( *result != a1 )
      {
        if ( result[1] == a1 )
        {
          v6 = *result;
          goto LABEL_12;
        }
        result += 10;
        if ( (unsigned int)result >= v5 )
          return result;
      }
      v6 = result[1];
LABEL_12:
      v4 = result;
      result = (unsigned __int16 *)sub_A49440(dword_2305834[0] + 8 * (5 * v6 + 257), (int)a3);
    }
    while ( !result );
  }
  return result;
}

