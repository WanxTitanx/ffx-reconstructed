// Function: sub_A01C80
// Address: 0xa01c80
// Size: 0x27

_DWORD *__thiscall sub_A01C80(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PLegacyGlowD3D11>::`vftable'; /*0xa01c86*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa01c8c*/
  if ( (a2 & 1) != 0 ) /*0xa01c95*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01c98*/
  return this; /*0xa01ca2*/
}