// Function: sub_9C3140
// Address: 0x9c3140
_DWORD *__thiscall sub_9C3140(_DWORD *this, char a2)
{
  *this = &btActionInterface::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
