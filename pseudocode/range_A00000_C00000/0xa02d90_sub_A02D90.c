// Function: sub_A02D90
// Address: 0xa02d90
// Size: 0x77
// Prototype: 

_DWORD *__thiscall sub_A02D90(_DWORD *this, char a2)
{
  sub_5853C0();
  sub_9FE3A0();
  *this = &Phyre::PPostProcessing::PPostEffectBase::`vftable';
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

