// Function: sub_A03220
// Address: 0xa03220
// Size: 0x8c
// Prototype: 

_DWORD *__thiscall sub_A03220(_DWORD *this, char a2)
{
  *this = &Phyre::PPostProcessing::PVolumetricLightD3D11::`vftable';
  sub_A0E520(*(this + 26));
  sub_5853C0();
  sub_5853C0();
  *this = &Phyre::PPostProcessing::PPostEffectBase::`vftable';
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

