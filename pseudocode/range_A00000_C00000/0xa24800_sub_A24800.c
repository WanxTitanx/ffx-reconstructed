// Function: sub_A24800
// Address: 0xa24800
// Size: 0x69
// Prototype: 

char __stdcall sub_A24800(int a1, char a2)
{
  if ( a2 )
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1943D08, a1 + 4, 1);
    else
      Phyre_PObject_TraverseBindMembers(dword_1943D08, 0, 1);
    return 1;
  }
  else
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1943D08, a1 + 4, 0);
    else
      Phyre_PObject_TraverseBindMembers(dword_1943D08, 0, 0);
    return 1;
  }
}

