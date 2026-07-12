// Function: sub_A031A0
// Address: 0xa031a0
// Size: 0x74
// Prototype: 

_DWORD *__thiscall sub_A031A0(_DWORD *this, char a2)
{
  sub_5853C0();
  sub_5853C0();
  *this = &Phyre::PPostProcessing::PPostEffectBase::`vftable';
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

