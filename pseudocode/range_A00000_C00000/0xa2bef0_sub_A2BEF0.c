// Function: sub_A2BEF0
// Address: 0xa2bef0
// Size: 0x27

_DWORD *__thiscall sub_A2BEF0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PText::PBitmapFontCharInfo>::`vftable'; /*0xa2bef6*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa2befc*/
  if ( (a2 & 1) != 0 ) /*0xa2bf05*/
    Phyre_Memory_AlignedFree((int)this); /*0xa2bf08*/
  return this; /*0xa2bf12*/
}