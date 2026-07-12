// Function: sub_98AF30
// Address: 0x98af30
_DWORD *__thiscall sub_98AF30(_DWORD *this, char a2)
{
  sub_98ACA0(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
