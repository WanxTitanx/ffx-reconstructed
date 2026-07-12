// Function: sub_A23D00
// Address: 0xa23d00
// Size: 0x69
// Prototype: 

char __stdcall sub_A23D00(int a1, char a2)
{
  if ( a2 )
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1943718, a1 + 4, 1);
    else
      Phyre_PObject_TraverseBindMembers(dword_1943718, 0, 1);
    return 1;
  }
  else
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1943718, a1 + 4, 0);
    else
      Phyre_PObject_TraverseBindMembers(dword_1943718, 0, 0);
    return 1;
  }
}

