// Function: sub_992080
// Address: 0x992080
_DWORD *__thiscall sub_992080(_DWORD *this, char a2)
{
  sub_98ACA0(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
