// Function: sub_80AE00
// Address: 0x80ae00
int __cdecl sub_80AE00(int a1, int a2)
{
  int n0x2000; // eax

  n0x2000 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( n0x2000 == 4096 )
    {
      sub_7FC470(-2, 0);
      return a2 + 4;
    }
    else if ( n0x2000 == 0x2000 )
    {
      sub_7FC370(-2);
      return a2 + 2;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    sub_7FD710(unk_119FE70, *(__int16 *)(a2 + 2), *(__int16 *)(a2 + 4), -2);
    return a2 + 6;
  }
}
