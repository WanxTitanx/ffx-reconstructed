// Function: sub_A02550
// Address: 0xa02550
// Size: 0x27

_DWORD *__thiscall sub_A02550(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PScreenSpaceReflection>::`vftable'; /*0xa02556*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa0255c*/
  if ( (a2 & 1) != 0 ) /*0xa02565*/
    Phyre_Memory_AlignedFree((int)this); /*0xa02568*/
  return this; /*0xa02572*/
}