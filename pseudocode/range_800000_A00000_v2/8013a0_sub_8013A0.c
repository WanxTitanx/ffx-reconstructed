// Function: sub_8013A0
// Address: 0x8013a0
_DWORD *__cdecl sub_8013A0(unsigned __int16 a1, unsigned __int16 a2)
{
  int v2; // ecx
  _DWORD *result; // eax

  v2 = a2;
  result = *(_DWORD **)(dword_12A4080[a1] + 32);
  if ( a2 )
  {
    do
    {
      *result = 0;
      result[1] = 0;
      result[2] = 0;
      result[3] = 0;
      result += 64;
      --v2;
    }
    while ( v2 );
  }
  return result;
}
