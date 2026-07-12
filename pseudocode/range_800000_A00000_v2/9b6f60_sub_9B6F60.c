// Function: sub_9B6F60
// Address: 0x9b6f60
_DWORD *__thiscall sub_9B6F60(_DWORD *this, char a2)
{
  sub_9B6C10(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
