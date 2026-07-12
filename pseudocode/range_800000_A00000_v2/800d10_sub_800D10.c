// Function: sub_800D10
// Address: 0x800d10
int __cdecl sub_800D10(int a1)
{
  int result; // eax
  __int16 v2; // cx

  result = *(unsigned __int16 *)(a1 + 2);
  v2 = result + 1;
  if ( (__int16)(result + 1) >= -16 )
    v2 = 0x8000;
  *(_WORD *)(a1 + 2) = v2;
  return result;
}
