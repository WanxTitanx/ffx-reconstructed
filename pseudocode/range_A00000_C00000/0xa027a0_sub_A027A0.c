// Function: sub_A027A0
// Address: 0xa027a0
// Size: 0x75
// Prototype: 

_DWORD *__thiscall sub_A027A0(_DWORD *this, char a2)
{
  *this = &Phyre::PPostProcessing::PDepthOfFieldD3D11::`vftable';
  sub_A0E520(*(this + 1004));
  sub_9FDD30();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

