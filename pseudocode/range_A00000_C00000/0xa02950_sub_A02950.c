// Function: sub_A02950
// Address: 0xa02950
// Size: 0x94
// Prototype: 

_DWORD *__thiscall sub_A02950(_DWORD *this, char a2)
{
  *this = &Phyre::PPostProcessing::PExponentialShadowD3D11::`vftable';
  sub_A0E520(*(this + 24));
  sub_A0E520(*(this + 25));
  sub_5853C0();
  sub_5853C0();
  *this = &Phyre::PPostProcessing::PPostEffectBase::`vftable';
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

