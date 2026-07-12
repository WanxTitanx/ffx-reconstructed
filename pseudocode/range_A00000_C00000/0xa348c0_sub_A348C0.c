// Function: sub_A348C0
// Address: 0xa348c0
// Size: 0x2e
// Prototype: 

char __stdcall sub_A348C0(int a1, char a2)
{
  if ( a2 )
    Phyre_PObject_TraverseBindMembers(Size_6, a1, 1);
  else
    Phyre_PObject_TraverseBindMembers(Size_6, a1, 0);
  return 1;
}

