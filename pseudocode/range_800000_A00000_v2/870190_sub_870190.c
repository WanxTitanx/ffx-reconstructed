// Function: sub_870190
// Address: 0x870190
int __cdecl sub_870190(int a1, int a2)
{
  int result; // eax
  int n127; // edx
  char v4; // bl

  result = sub_785310();
  n127 = (a1 < 0 ? 0 : a1) >> 3;
  v4 = 1 << ((a1 < 0 ? 0 : a1) % 8);
  if ( n127 >= 128 )
    n127 = 127;
  if ( a2 )
    *(_BYTE *)(result + n127) |= v4;
  else
    *(_BYTE *)(result + n127) &= ~v4;
  return result;
}
