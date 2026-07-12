// Function: sub_A24450
// Address: 0xa24450
// Size: 0x69

char __stdcall sub_A24450(int a1, char a2)
{
  if ( a2 ) /*0xa2445a*/
  {
    if ( a1 ) /*0xa2445e*/
      Phyre_PObject_TraverseBindMembers(dword_1943F20, a1 + 4, 1); /*0xa2446b*/
    else
      Phyre_PObject_TraverseBindMembers(dword_1943F20, 0, 1); /*0xa24480*/
    return 1; /*0xa24470*/
  }
  else
  {
    if ( a1 ) /*0xa2448d*/
      Phyre_PObject_TraverseBindMembers(dword_1943F20, a1 + 4, 0); /*0xa2449a*/
    else
      Phyre_PObject_TraverseBindMembers(dword_1943F20, 0, 0); /*0xa244ae*/
    return 1; /*0xa2449f*/
  }
}