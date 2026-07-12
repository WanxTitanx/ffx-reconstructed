// Function: sub_A57000
// Address: 0xa57000
// Size: 0x3b
// Prototype: int __cdecl(float, float, float, float)

BOOL __cdecl sub_A57000(float a1, float a2, float a3, float a4)
{
  double v4; // st7
  double v5; // st6

  v4 = a1;
  if ( a3 <= (double)a1 )
  {
    if ( a3 >= v4 )
      return 1;
    v5 = a4;
  }
  else
  {
    v4 = a3;
    v5 = a2;
  }
  return v5 >= v4;
}

