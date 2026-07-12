// Function: sub_A6E260
// Address: 0xa6e260
// Size: 0x78
// Prototype: 

unsigned __int16 *__cdecl sub_A6E260(unsigned __int16 *a1)
{
  unsigned __int16 *result; // eax
  int v2; // esi
  __int16 v3; // dx
  unsigned __int8 n0x20; // cl

  result = 0;
  v2 = 0;
  if ( *a1 )
  {
    result = a1 + 30;
    do
    {
      v3 = *result;
      if ( (*result & 0x8000u) == 0 )
      {
        n0x20 = *((_BYTE *)result + 2) + 1;
        *((_BYTE *)result + 2) = n0x20;
        if ( n0x20 >= 0x20u )
        {
          *(_WORD *)(*((_DWORD *)a1 + 3) + 2 * v3) = -2;
          *result = -1;
          *((_BYTE *)result + 2) = 0;
        }
        else
        {
          result[41] = (32 - n0x20) << 7;
        }
      }
      ++v2;
      result += 48;
    }
    while ( v2 < *a1 );
  }
  return result;
}

