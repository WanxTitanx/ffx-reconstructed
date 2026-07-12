// Function: sub_A01BC0
// Address: 0xa01bc0
// Size: 0x27

_DWORD *__thiscall sub_A01BC0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PGlowD3D11>::`vftable'; /*0xa01bc6*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa01bcc*/
  if ( (a2 & 1) != 0 ) /*0xa01bd5*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01bd8*/
  return this; /*0xa01be2*/
}