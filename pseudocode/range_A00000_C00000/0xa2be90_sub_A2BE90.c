// Function: sub_A2BE90
// Address: 0xa2be90
// Size: 0x27

_DWORD *__thiscall sub_A2BE90(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PArray<Phyre::PText::PBitmapFontCharInfo,4>>::`vftable'; /*0xa2be96*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa2be9c*/
  if ( (a2 & 1) != 0 ) /*0xa2bea5*/
    Phyre_Memory_AlignedFree((int)this); /*0xa2bea8*/
  return this; /*0xa2beb2*/
}