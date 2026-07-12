// Function: sub_A2E750
// Address: 0xa2e750
// Size: 0x2b
// Prototype: 

_DWORD *__thiscall sub_A2E750(_DWORD *this, char a2)
{
  *this = &Phyre::PInputs::PInputKeySemantic::`vftable';
  sub_A2E880(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}

