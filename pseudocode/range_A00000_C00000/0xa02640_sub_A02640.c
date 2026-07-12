// Function: sub_A02640
// Address: 0xa02640
// Size: 0x22

_DWORD *__thiscall sub_A02640(_DWORD *this, char a2)
{
  *this = &Phyre::PPostProcessing::PPostEffectBase::`vftable'; /*0xa0264a*/
  if ( (a2 & 1) != 0 ) /*0xa02650*/
    Phyre_Memory_AlignedFree((int)this); /*0xa02653*/
  return this; /*0xa0265d*/
}