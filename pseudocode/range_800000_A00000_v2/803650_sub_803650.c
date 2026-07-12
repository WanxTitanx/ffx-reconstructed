// Function: sub_803650
// Address: 0x803650
_DWORD *__cdecl sub_803650(int a1)
{
  _DWORD *result; // eax
  int n8; // ecx

  result = &unk_11A11C0;
  n8 = 0;
  while ( *result != a1 )
  {
    ++n8;
    result += 4;
    if ( n8 >= 8 )
      return result;
  }
  *result = 0;
  return result;
}
