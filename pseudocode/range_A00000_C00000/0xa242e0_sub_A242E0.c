// Function: sub_A242E0
// Address: 0xa242e0
// Size: 0x2e

char __stdcall sub_A242E0(int a1, char a2)
{
  if ( a2 ) /*0xa242ec*/
    Phyre_PObject_TraverseBindMembers(dword_19442B0, a1, 1); /*0xa242f3*/
  else
    Phyre_PObject_TraverseBindMembers(dword_19442B0, a1, 0); /*0xa24303*/
  return 1; /*0xa242fa*/
}