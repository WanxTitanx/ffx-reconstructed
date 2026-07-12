// Function: sub_A32530
// Address: 0xa32530
// Size: 0x2b
// Prototype: 

_DWORD *__thiscall sub_A32530(_DWORD *this, char a2)
{
  *this = &Phyre::PInputs::PInputChannelSemantic::`vftable';
  sub_A32660(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}

