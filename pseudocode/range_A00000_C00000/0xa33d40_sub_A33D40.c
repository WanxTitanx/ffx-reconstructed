// Function: sub_A33D40
// Address: 0xa33d40
// Size: 0x76
// Prototype: 

_DWORD *sub_A33D40()
{
  if ( (dword_1A85744 & 1) == 0 )
  {
    dword_1A85744 |= 1u;
    sub_A32EF0();
    unk_1A85740 &= ~2u;
    Size_7[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PInputs::PInputMap *,4>>::`vftable';
    atexit(sub_B0B860);
  }
  return Size_7;
}

