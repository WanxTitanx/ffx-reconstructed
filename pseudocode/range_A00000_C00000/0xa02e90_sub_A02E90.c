// Function: sub_A02E90
// Address: 0xa02e90
// Size: 0x75
// Prototype: 

_DWORD *__thiscall sub_A02E90(_DWORD *this, char a2)
{
  *this = &Phyre::PPostProcessing::PMotionBlurD3D11::`vftable';
  sub_A0E520(*(this + 851));
  sub_9FE640();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

