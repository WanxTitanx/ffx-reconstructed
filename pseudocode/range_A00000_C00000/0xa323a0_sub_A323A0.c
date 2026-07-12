// Function: sub_A323A0
// Address: 0xa323a0
// Size: 0x82
// Prototype: 

_DWORD *sub_A323A0()
{
  if ( (dword_1A855B0[0] & 1) == 0 )
  {
    dword_1A855B0[0] |= 1u;
    sub_5A0390("PInputChannelSemantic", 16, 4, sub_A325D0, sub_A32640);
    dword_1A8557C[0] = &Phyre::PNamedSemanticDescriptorForType<Phyre::PInputs::PInputChannelSemantic>::`vftable';
    atexit(sub_B0B820);
  }
  return dword_1A8557C;
}

