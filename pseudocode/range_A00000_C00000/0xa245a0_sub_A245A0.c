// Function: sub_A245A0
// Address: 0xa245a0
// Size: 0x69
// Prototype: 

char __stdcall sub_A245A0(int a1, char a2)
{
  if ( a2 )
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1943A10, a1 + 4, 1);
    else
      Phyre_PObject_TraverseBindMembers(dword_1943A10, 0, 1);
    return 1;
  }
  else
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1943A10, a1 + 4, 0);
    else
      Phyre_PObject_TraverseBindMembers(dword_1943A10, 0, 0);
    return 1;
  }
}

