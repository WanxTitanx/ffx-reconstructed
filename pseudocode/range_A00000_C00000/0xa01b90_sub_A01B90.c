// Function: sub_A01B90
// Address: 0xa01b90
// Size: 0x27

_DWORD *__thiscall sub_A01B90(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PGlowBase>::`vftable'; /*0xa01b96*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa01b9c*/
  if ( (a2 & 1) != 0 ) /*0xa01ba5*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01ba8*/
  return this; /*0xa01bb2*/
}