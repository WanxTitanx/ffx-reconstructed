// Function: sub_A01C20
// Address: 0xa01c20
// Size: 0x27

_DWORD *__thiscall sub_A01C20(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PLegacyGlow>::`vftable'; /*0xa01c26*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa01c2c*/
  if ( (a2 & 1) != 0 ) /*0xa01c35*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01c38*/
  return this; /*0xa01c42*/
}