// Function: sub_A2D0F0
// Address: 0xa2d0f0
// Size: 0x76
// Prototype: 

_DWORD *sub_A2D0F0()
{
  if ( (dword_1A85144 & 1) == 0 )
  {
    dword_1A85144 |= 1u;
    sub_A2B780(dword_1A850B0);
    unk_1A85140 &= ~2u;
    dword_1A850B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PText::PBitmapFontCharInfo,4>>::`vftable';
    atexit(sub_B090E0);
  }
  return dword_1A850B0;
}

