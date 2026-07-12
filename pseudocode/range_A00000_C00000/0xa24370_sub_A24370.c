// Function: sub_A24370
// Address: 0xa24370
// Size: 0x69

char __stdcall sub_A24370(int a1, char a2)
{
  if ( a2 ) /*0xa2437a*/
  {
    if ( a1 ) /*0xa2437e*/
      Phyre_PObject_TraverseBindMembers(dword_1943E88, a1 + 4, 1); /*0xa2438b*/
    else
      Phyre_PObject_TraverseBindMembers(dword_1943E88, 0, 1); /*0xa243a0*/
    return 1; /*0xa24390*/
  }
  else
  {
    if ( a1 ) /*0xa243ad*/
      Phyre_PObject_TraverseBindMembers(dword_1943E88, a1 + 4, 0); /*0xa243ba*/
    else
      Phyre_PObject_TraverseBindMembers(dword_1943E88, 0, 0); /*0xa243ce*/
    return 1; /*0xa243bf*/
  }
}