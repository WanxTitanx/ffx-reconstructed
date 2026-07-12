// Function: sub_A24240
// Address: 0xa24240
// Size: 0x69

char __stdcall sub_A24240(int a1, char a2)
{
  if ( a2 ) /*0xa2424a*/
  {
    if ( a1 ) /*0xa2424e*/
      Phyre_PObject_TraverseBindMembers(dword_19440E8, a1 + 4, 1); /*0xa2425b*/
    else
      Phyre_PObject_TraverseBindMembers(dword_19440E8, 0, 1); /*0xa24270*/
    return 1; /*0xa24260*/
  }
  else
  {
    if ( a1 ) /*0xa2427d*/
      Phyre_PObject_TraverseBindMembers(dword_19440E8, a1 + 4, 0); /*0xa2428a*/
    else
      Phyre_PObject_TraverseBindMembers(dword_19440E8, 0, 0); /*0xa2429e*/
    return 1; /*0xa2428f*/
  }
}