// Function: sub_992050
// Address: 0x992050
_DWORD *__thiscall sub_992050(_DWORD *this, char a2)
{
  sub_98ACA0(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
