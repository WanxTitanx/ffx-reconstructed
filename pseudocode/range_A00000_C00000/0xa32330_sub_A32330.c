// Function: sub_A32330
// Address: 0xa32330
// Size: 0x2e
// Prototype: 

char __stdcall sub_A32330(int a1, char a2)
{
  if ( a2 )
    Phyre_PObject_TraverseBindMembers(Size_5, a1, 1);
  else
    Phyre_PObject_TraverseBindMembers(Size_5, a1, 0);
  return 1;
}

