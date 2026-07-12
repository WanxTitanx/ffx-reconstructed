// Function: sub_A02580
// Address: 0xa02580
// Size: 0x27

_DWORD *__thiscall sub_A02580(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PScreenSpaceReflectionBase>::`vftable'; /*0xa02586*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa0258c*/
  if ( (a2 & 1) != 0 ) /*0xa02595*/
    Phyre_Memory_AlignedFree((int)this); /*0xa02598*/
  return this; /*0xa025a2*/
}