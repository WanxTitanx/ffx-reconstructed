// Function: sub_A2EA30
// Address: 0xa2ea30
// Size: 0x82
// Prototype: 

_DWORD *sub_A2EA30()
{
  if ( (dword_1A85404[0] & 1) == 0 )
  {
    dword_1A85404[0] |= 1u;
    sub_5A0390("PInputMouseButtonSemantic", 16, 4, sub_A2EC60, sub_A2ECD0);
    dword_1A853D0[0] = &Phyre::PNamedSemanticDescriptorForType<Phyre::PInputs::PInputMouseButtonSemantic>::`vftable';
    atexit(sub_B0A5B0);
  }
  return dword_1A853D0;
}

