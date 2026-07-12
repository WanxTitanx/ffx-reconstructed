// Function: sub_A243E0
// Address: 0xa243e0
// Size: 0x69

char __stdcall sub_A243E0(int a1, char a2)
{
  if ( a2 ) /*0xa243ea*/
  {
    if ( a1 ) /*0xa243ee*/
      Phyre_PObject_TraverseBindMembers(dword_1943DF0, a1 + 4, 1); /*0xa243fb*/
    else
      Phyre_PObject_TraverseBindMembers(dword_1943DF0, 0, 1); /*0xa24410*/
    return 1; /*0xa24400*/
  }
  else
  {
    if ( a1 ) /*0xa2441d*/
      Phyre_PObject_TraverseBindMembers(dword_1943DF0, a1 + 4, 0); /*0xa2442a*/
    else
      Phyre_PObject_TraverseBindMembers(dword_1943DF0, 0, 0); /*0xa2443e*/
    return 1; /*0xa2442f*/
  }
}