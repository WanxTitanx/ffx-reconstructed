// Function: sub_A30C60
// Address: 0xa30c60
// Size: 0x22
// Prototype: 

_DWORD *__thiscall sub_A30C60(_DWORD *this, char a2)
{
  *this = &Phyre::PCaller::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}

