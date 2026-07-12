// Function: sub_8173F0
// Address: 0x8173f0
int __cdecl sub_8173F0(int a1, int a2)
{
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0x1000 )
      return a2;
    if ( !sub_86AFC0(*(unsigned __int16 *)(a2 + 2)) )
    {
      *(_BYTE *)(a1 + 528) = 1;
      return a2;
    }
  }
  else
  {
    sub_86F9D0(*(unsigned __int16 *)(a2 + 2));
  }
  return a2 + 4;
}
