// Function: sub_A24340
// Address: 0xa24340
// Size: 0x2e

char __stdcall sub_A24340(int a1, char a2)
{
  if ( a2 ) /*0xa2434c*/
    Phyre_PObject_TraverseBindMembers(dword_1944348, a1, 1); /*0xa24353*/
  else
    Phyre_PObject_TraverseBindMembers(dword_1944348, a1, 0); /*0xa24363*/
  return 1; /*0xa2435a*/
}