// Function: sub_A2B3B0
// Address: 0xa2b3b0
// Size: 0x87
// Prototype: 

void __cdecl sub_A2B3B0(int a1)
{
  if ( (dword_1A85144 & 1) == 0 )
  {
    dword_1A85144 |= 1u;
    sub_A2B780();
    unk_1A85140 &= ~2u;
    dword_1A850B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PText::PBitmapFontCharInfo,4>>::`vftable';
    atexit(sub_B090E0);
  }
  Phyre_PObject_TraverseBindMembers(dword_1A850B0, a1, 1);
}

