// Function: sub_A2B320
// Address: 0xa2b320
// Size: 0x87
// Prototype: 

void __cdecl sub_A2B320(int a1)
{
  if ( (unk_C9A004 & 1) == 0 )
  {
    unk_C9A004 |= 1u;
    sub_48E8C0();
    unk_C9A000 &= ~2u;
    unk_C99F70[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<int,4>>::`vftable';
    atexit(sub_AFC9E0);
  }
  Phyre_PObject_TraverseBindMembers(unk_C99F70, a1, 1);
}

