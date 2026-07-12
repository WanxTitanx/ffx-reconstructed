// Function: sub_A246F0
// Address: 0xa246f0
// Size: 0x2e
// Prototype: 

char __stdcall sub_A246F0(int a1, char a2)
{
  if ( a2 )
    Phyre_PObject_TraverseBindMembers(dword_19448A0, a1, 1);
  else
    Phyre_PObject_TraverseBindMembers(dword_19448A0, a1, 0);
  return 1;
}

