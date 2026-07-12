// Function: sub_A2EBC0
// Address: 0xa2ebc0
// Size: 0x2b
// Prototype: 

_DWORD *__thiscall sub_A2EBC0(_DWORD *this, char a2)
{
  *this = &Phyre::PInputs::PInputMouseButtonSemantic::`vftable';
  sub_A2ECF0(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}

