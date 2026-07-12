// Function: sub_8701F0
// Address: 0x8701f0
void __cdecl sub_8701F0(int n8, int a2)
{
  int v2; // eax

  if ( n8 < 8 )
  {
    v2 = 1 << n8;
    if ( a2 )
      unk_1326B50 |= v2;
    else
      unk_1326B50 &= ~v2;
  }
}
