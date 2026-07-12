// Function: sub_89B0B0
// Address: 0x89b0b0
int __cdecl sub_89B0B0(int a1, int a2, int n250, int n150, int a5)
{
  int n140; // edi

  if ( n113 == 389 && n250 == 250 )
  {
    n140 = n150;
    if ( n150 == 150 && FFX_Game_GetRegion() > 1 && FFX_Game_GetRegion() <= 5 )
      n140 = 140;
  }
  else
  {
    n140 = n150;
  }
  sub_8AD9E0(a1);
  sub_8AFFB0(a1, 0, 0);
  sub_8B8980(a1, a2, a2);
  sub_8AF800(a1, a5, n250, n140);
  sub_8AFB40(a1, 4);
  sub_8AF780(a1);
  return sub_8ADDC0(a1);
}
