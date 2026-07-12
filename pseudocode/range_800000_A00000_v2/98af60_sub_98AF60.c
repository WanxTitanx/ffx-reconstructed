// Function: sub_98AF60
// Address: 0x98af60
_DWORD *__thiscall sub_98AF60(_DWORD *this, char a2)
{
  sub_98ACB0(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
