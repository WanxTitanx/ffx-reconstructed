// Function: sub_A2DE70
// Address: 0xa2de70
// Size: 0x2b
// Prototype: 

_DWORD *__thiscall sub_A2DE70(_DWORD *this, char a2)
{
  *this = &Phyre::PInputs::PInputAxisSemantic::`vftable';
  sub_A2DFA0(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}

