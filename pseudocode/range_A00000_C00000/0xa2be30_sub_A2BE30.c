// Function: sub_A2BE30
// Address: 0xa2be30
// Size: 0x27

_DWORD *__thiscall sub_A2BE30(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PArray<Phyre::PText::PBitmapFontCharInfo,4>>::`vftable'; /*0xa2be36*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa2be3c*/
  if ( (a2 & 1) != 0 ) /*0xa2be45*/
    Phyre_Memory_AlignedFree((int)this); /*0xa2be48*/
  return this; /*0xa2be52*/
}