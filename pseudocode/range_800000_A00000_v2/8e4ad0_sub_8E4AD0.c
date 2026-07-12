// Function: sub_8E4AD0
// Address: 0x8e4ad0
int __cdecl sub_8E4AD0(int a1)
{
  int result; // eax

  result = (512 - *(__int16 *)(a1 + 78)) / 2;
  *(_WORD *)(a1 + 74) = result;
  return result;
}
