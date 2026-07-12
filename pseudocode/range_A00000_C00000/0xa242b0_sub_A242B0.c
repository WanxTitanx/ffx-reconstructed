// Function: sub_A242B0
// Address: 0xa242b0
// Size: 0x2e

char __stdcall sub_A242B0(int a1, char a2)
{
  if ( a2 ) /*0xa242bc*/
    Phyre_PObject_TraverseBindMembers(dword_19443E0, a1, 1); /*0xa242c3*/
  else
    Phyre_PObject_TraverseBindMembers(dword_19443E0, a1, 0); /*0xa242d3*/
  return 1; /*0xa242ca*/
}