// Function: sub_A2DCE0
// Address: 0xa2dce0
// Size: 0x82
// Prototype: 

_DWORD *sub_A2DCE0()
{
  if ( (dword_1A85350 & 1) == 0 )
  {
    dword_1A85350 |= 1u;
    sub_5A0390("PInputAxisSemantic", 16, 4, sub_A2DF10, sub_A2DF80);
    dword_1A8531C[0] = &Phyre::PNamedSemanticDescriptorForType<Phyre::PInputs::PInputAxisSemantic>::`vftable';
    atexit(sub_B09360);
  }
  return dword_1A8531C;
}

