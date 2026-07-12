// Function: sub_A23DE0
// Address: 0xa23de0
// Size: 0x69
// Prototype: 

char __stdcall sub_A23DE0(int a1, char a2)
{
  if ( a2 )
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_19437B0, a1 + 4, 1);
    else
      Phyre_PObject_TraverseBindMembers(dword_19437B0, 0, 1);
    return 1;
  }
  else
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_19437B0, a1 + 4, 0);
    else
      Phyre_PObject_TraverseBindMembers(dword_19437B0, 0, 0);
    return 1;
  }
}

