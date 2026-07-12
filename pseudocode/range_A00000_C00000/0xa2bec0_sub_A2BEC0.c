// Function: sub_A2BEC0
// Address: 0xa2bec0
// Size: 0x27

_DWORD *__thiscall sub_A2BEC0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PText::PBitmapFont>::`vftable'; /*0xa2bec6*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa2becc*/
  if ( (a2 & 1) != 0 ) /*0xa2bed5*/
    Phyre_Memory_AlignedFree((int)this); /*0xa2bed8*/
  return this; /*0xa2bee2*/
}