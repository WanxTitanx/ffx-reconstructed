// Function: sub_A78620
// Address: 0xa78620
// Size: 0x1d

int __cdecl sub_A78620(int a1, int a2)
{
  int result; // eax

  result = 0; /*0xa78628*/
  if ( *(_DWORD *)a2 )
    return *(_BYTE *)(*(_DWORD *)a2 + 1846) != 0 ? 0 : 5;
  return result; /*0xa7863b*/
}