// Function: sub_930220
// Address: 0x930220
_DWORD *__cdecl sub_930220(_DWORD *a1, _DWORD *a2)
{
  _DWORD *result; // eax

  result = a1;
  if ( a1 )
  {
    while ( result[46] <= a2[46] )
    {
      result = (_DWORD *)result[2];
      if ( !result )
        return result;
    }
    *(_DWORD *)(result[1] + 8) = a2;
    a2[1] = result[1];
    result[1] = a2;
    a2[2] = result;
  }
  return result;
}
