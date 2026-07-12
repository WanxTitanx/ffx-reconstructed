// Function: sub_A32910
// Address: 0xa32910
// Size: 0x82
// Prototype: 

int sub_A32910()
{
  if ( (dword_1A85744 & 1) == 0 )
  {
    dword_1A85744 |= 1u;
    sub_A32EF0();
    unk_1A85740 &= ~2u;
    dword_1A856B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PInputs::PInputMap *,4>>::`vftable';
    atexit(sub_B0B860);
  }
  return Phyre_PObject_ComputeLayout(dword_1A856B0);
}

