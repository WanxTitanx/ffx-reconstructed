// Function: sub_9F00F0
// Address: 0x9f00f0
char __stdcall sub_9F00F0(int a1, char a2)
{
  if ( a2 )
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_19410C0, a1 + 4, 1);
    else
      Phyre_PObject_TraverseBindMembers(dword_19410C0, 0, 1);
    return 1;
  }
  else
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_19410C0, a1 + 4, 0);
    else
      Phyre_PObject_TraverseBindMembers(dword_19410C0, 0, 0);
    return 1;
  }
}
