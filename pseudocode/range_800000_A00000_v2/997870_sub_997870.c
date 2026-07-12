// Function: sub_997870
// Address: 0x997870
_DWORD *__thiscall sub_997870(_DWORD *this, char a2)
{
  sub_98ACB0(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
