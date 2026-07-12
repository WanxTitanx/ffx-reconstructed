// Function: sub_800C80
// Address: 0x800c80
int __cdecl sub_800C80(int a1, __int16 a2)
{
  int v2; // edx
  int result; // eax
  __int16 v4; // cx

  v2 = *(_DWORD *)(a1 + 28);
  result = 0;
  if ( *(_WORD *)(a1 + 52) != 1 )
  {
    do
    {
      v4 = *(_WORD *)(v2 + 2 * result);
      if ( v4 < 0 )
        break;
      if ( v4 == a2 )
        return result;
      ++result;
    }
    while ( result < (unsigned __int16)(*(_WORD *)(a1 + 52) - 1) );
  }
  *(_WORD *)(v2 + 2 * result) = a2;
  return result;
}
