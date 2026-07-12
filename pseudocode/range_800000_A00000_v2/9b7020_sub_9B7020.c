// Function: sub_9B7020
// Address: 0x9b7020
_DWORD *__thiscall sub_9B7020(_DWORD *this, char a2)
{
  *this = &btDynamicsWorld::`vftable';
  sub_97C4A0();
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
