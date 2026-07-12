// Function: sub_A03050
// Address: 0xa03050
// Size: 0x22
// Prototype: 

_DWORD *__thiscall sub_A03050(_DWORD *this, char a2)
{
  *this = &Phyre::PPostProcessing::PPostEffectBase::`vftable';
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

