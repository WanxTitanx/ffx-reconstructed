// Function: sub_A2E5C0
// Address: 0xa2e5c0
// Size: 0x82
// Prototype: 

_DWORD *sub_A2E5C0()
{
  if ( (dword_1A853C8 & 1) == 0 )
  {
    dword_1A853C8 |= 1u;
    sub_5A0390("PInputKeySemantic", 16, 4, sub_A2E7F0, sub_A2E860);
    dword_1A85394[0] = &Phyre::PNamedSemanticDescriptorForType<Phyre::PInputs::PInputKeySemantic>::`vftable';
    atexit(sub_B0A520);
  }
  return dword_1A85394;
}

