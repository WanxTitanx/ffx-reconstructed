// Function: sub_9A06B0
// Address: 0x9a06b0
_DWORD *__thiscall sub_9A06B0(_DWORD *this, char a2)
{
  sub_9A0460(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
