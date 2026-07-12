// Function: sub_A24310
// Address: 0xa24310
// Size: 0x2e

char __stdcall sub_A24310(int a1, char a2)
{
  if ( a2 ) /*0xa2431c*/
    Phyre_PObject_TraverseBindMembers(dword_1944478, a1, 1); /*0xa24323*/
  else
    Phyre_PObject_TraverseBindMembers(dword_1944478, a1, 0); /*0xa24333*/
  return 1; /*0xa2432a*/
}