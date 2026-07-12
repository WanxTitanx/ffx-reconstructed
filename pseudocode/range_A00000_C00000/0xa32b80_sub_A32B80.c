// Function: sub_A32B80
// Address: 0xa32b80
// Size: 0x76
// Prototype: 

_DWORD *sub_A32B80()
{
  if ( (dword_1A85744 & 1) == 0 )
  {
    dword_1A85744 |= 1u;
    sub_A32EF0();
    unk_1A85740 &= ~2u;
    dword_1A856B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PInputs::PInputMap *,4>>::`vftable';
    atexit(sub_B0B860);
  }
  return dword_1A856B0;
}

