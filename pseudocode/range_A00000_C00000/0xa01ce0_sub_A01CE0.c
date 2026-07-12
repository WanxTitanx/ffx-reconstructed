// Function: sub_A01CE0
// Address: 0xa01ce0
// Size: 0x27

_DWORD *__thiscall sub_A01CE0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PMLAA>::`vftable'; /*0xa01ce6*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa01cec*/
  if ( (a2 & 1) != 0 ) /*0xa01cf5*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01cf8*/
  return this; /*0xa01d02*/
}