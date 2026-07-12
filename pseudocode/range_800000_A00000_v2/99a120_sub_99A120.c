// Function: sub_99A120
// Address: 0x99a120
_DWORD *__thiscall sub_99A120(_DWORD *this, char a2)
{
  sub_99A070(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
