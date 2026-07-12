// Function: sub_81E4C0
// Address: 0x81e4c0
int __cdecl sub_81E4C0(int a1)
{
  int n0x10000; // eax

  n0x10000 = *(_DWORD *)(a1 + 12);
  if ( n0x10000 > 0 && n0x10000 <= 0x10000 )
    return sub_67A510(*(__int16 *)(a1 + 8), 0);
  return n0x10000;
}
