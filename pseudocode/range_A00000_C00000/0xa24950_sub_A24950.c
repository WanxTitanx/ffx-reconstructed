// Function: sub_A24950
// Address: 0xa24950
// Size: 0x69
// Prototype: 

char __stdcall sub_A24950(int a1, char a2)
{
  if ( a2 )
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1944808, a1 + 4, 1);
    else
      Phyre_PObject_TraverseBindMembers(dword_1944808, 0, 1);
    return 1;
  }
  else
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1944808, a1 + 4, 0);
    else
      Phyre_PObject_TraverseBindMembers(dword_1944808, 0, 0);
    return 1;
  }
}

