// Function: sub_A2DC80
// Address: 0xa2dc80
// Size: 0x2e
// Prototype: 

char __stdcall sub_A2DC80(int a1, char a2)
{
  if ( a2 )
    Phyre_PObject_TraverseBindMembers(dword_1A84D20, a1, 1);
  else
    Phyre_PObject_TraverseBindMembers(dword_1A84D20, a1, 0);
  return 1;
}

