// Function: sub_9F01D0
// Address: 0x9f01d0
char __stdcall sub_9F01D0(int a1, char a2)
{
  if ( a2 )
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1940EF8, a1 + 4, 1);
    else
      Phyre_PObject_TraverseBindMembers(dword_1940EF8, 0, 1);
    return 1;
  }
  else
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1940EF8, a1 + 4, 0);
    else
      Phyre_PObject_TraverseBindMembers(dword_1940EF8, 0, 0);
    return 1;
  }
}
