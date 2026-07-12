// Function: sub_A8DBB0
// Address: 0xa8dbb0
// Size: 0x21
// Prototype: 

_DWORD *__thiscall sub_A8DBB0(_DWORD *this, char a2)
{
  sub_A8DA90(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}

