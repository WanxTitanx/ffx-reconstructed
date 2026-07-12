// Function: sub_A026D0
// Address: 0xa026d0
// Size: 0x98
// Prototype: 

_DWORD *__thiscall sub_A026D0(_DWORD *this, char a2)
{
  *this = &Phyre::PPostProcessing::PDeferredLightingBase::`vftable';
  sub_A24A60();
  sub_5853C0();
  sub_5853C0();
  sub_5853C0();
  *this = &Phyre::PPostProcessing::PPostEffectBase::`vftable';
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

