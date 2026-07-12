// Function: sub_810D40
// Address: 0x810d40
int __cdecl sub_810D40(int a1, int a2, int a3, _WORD *a4)
{
  __int16 v4; // dx
  __int16 v5; // ax

  v4 = *(_WORD *)(a3 + 4);
  v5 = *(_WORD *)(a3 + 2);
  if ( (*(_WORD *)(a1 + 538) & 0x1000) != 0 )
  {
    a4[22] = v5;
    a4[23] = v4;
    return a3 + 6;
  }
  else
  {
    a4[14] = v5;
    a4[15] = v4;
    return a3 + 6;
  }
}
