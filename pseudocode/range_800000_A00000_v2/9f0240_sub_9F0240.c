// Function: sub_9F0240
// Address: 0x9f0240
char __stdcall sub_9F0240(int a1, char a2)
{
  if ( a2 )
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1941158, a1 + 4, 1);
    else
      Phyre_PObject_TraverseBindMembers(dword_1941158, 0, 1);
    return 1;
  }
  else
  {
    if ( a1 )
      Phyre_PObject_TraverseBindMembers(dword_1941158, a1 + 4, 0);
    else
      Phyre_PObject_TraverseBindMembers(dword_1941158, 0, 0);
    return 1;
  }
}
