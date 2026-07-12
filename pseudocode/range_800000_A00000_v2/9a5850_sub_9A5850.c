// Function: sub_9A5850
// Address: 0x9a5850
_DWORD *__thiscall sub_9A5850(_DWORD *this, char a2)
{
  sub_98ACB0(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
