// Function: sub_9F0160
// Address: 0x9f0160
char __stdcall sub_9F0160(int a1, char a2)
{
  if ( a2 )
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1940F90, a1 + 4, 1);
    else
      Phyre_PObject_TraverseBindMembers(dword_1940F90, 0, 1);
    return 1;
  }
  else
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1940F90, a1 + 4, 0);
    else
      Phyre_PObject_TraverseBindMembers(dword_1940F90, 0, 0);
    return 1;
  }
}
