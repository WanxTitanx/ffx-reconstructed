// Function: sub_A32C60
// Address: 0xa32c60
// Size: 0x87
// Prototype: 

void __cdecl sub_A32C60(int a1)
{
  if ( (dword_1A85744 & 1) == 0 )
  {
    dword_1A85744 |= 1u;
    sub_A32EF0();
    unk_1A85740 &= ~2u;
    dword_1A856B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PInputs::PInputMap *,4>>::`vftable';
    atexit(sub_B0B860);
  }
  Phyre_PObject_TraverseBindMembers(dword_1A856B0, a1, 1);
}

