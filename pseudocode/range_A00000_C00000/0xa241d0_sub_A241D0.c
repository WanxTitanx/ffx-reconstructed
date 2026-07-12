// Function: sub_A241D0
// Address: 0xa241d0
// Size: 0x69

char __stdcall sub_A241D0(int a1, char a2)
{
  if ( a2 ) /*0xa241da*/
  {
    if ( a1 ) /*0xa241de*/
      Phyre_PObject_TraverseBindMembers(dword_1944218, a1 + 4, 1); /*0xa241eb*/
    else
      Phyre_PObject_TraverseBindMembers(dword_1944218, 0, 1); /*0xa24200*/
    return 1; /*0xa241f0*/
  }
  else
  {
    if ( a1 ) /*0xa2420d*/
      Phyre_PObject_TraverseBindMembers(dword_1944218, a1 + 4, 0); /*0xa2421a*/
    else
      Phyre_PObject_TraverseBindMembers(dword_1944218, 0, 0); /*0xa2422e*/
    return 1; /*0xa2421f*/
  }
}