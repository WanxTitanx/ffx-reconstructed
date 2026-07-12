// Function: sub_A01B30
// Address: 0xa01b30
// Size: 0x27

_DWORD *__thiscall sub_A01B30(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PFXAAD3D11>::`vftable'; /*0xa01b36*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa01b3c*/
  if ( (a2 & 1) != 0 ) /*0xa01b45*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01b48*/
  return this; /*0xa01b52*/
}