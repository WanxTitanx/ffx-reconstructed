// Function: sub_A2E150
// Address: 0xa2e150
// Size: 0x82

_DWORD *sub_A2E150()
{
  if ( (dword_1A8538C & 1) == 0 ) /*0xa2e179*/
  {
    dword_1A8538C |= 1u; /*0xa2e17e*/
    sub_5A0390("PInputJoypadButtonSemantic", 16, 4, sub_A2E380, sub_A2E3F0); /*0xa2e1a2*/
    dword_1A85358[0] = &Phyre::PNamedSemanticDescriptorForType<Phyre::PInputs::PInputJoypadButtonSemantic>::`vftable'; /*0xa2e1ac*/
    atexit(sub_B098F0); /*0xa2e1b6*/
  }
  return dword_1A85358; /*0xa2e1ce*/
}