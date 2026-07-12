// Function: sub_9A95C0
// Address: 0x9a95c0
_DWORD *__thiscall sub_9A95C0(_DWORD *this, char a2)
{
  sub_9A6040(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
