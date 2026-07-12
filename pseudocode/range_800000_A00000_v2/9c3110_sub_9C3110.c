// Function: sub_9C3110
// Address: 0x9c3110
_DWORD *__thiscall sub_9C3110(_DWORD *this, char a2)
{
  *this = &btActionInterface::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
