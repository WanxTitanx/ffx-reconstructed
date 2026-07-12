// Function: sub_A01C50
// Address: 0xa01c50
// Size: 0x27

_DWORD *__thiscall sub_A01C50(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PLegacyGlowBase>::`vftable'; /*0xa01c56*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa01c5c*/
  if ( (a2 & 1) != 0 ) /*0xa01c65*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01c68*/
  return this; /*0xa01c72*/
}