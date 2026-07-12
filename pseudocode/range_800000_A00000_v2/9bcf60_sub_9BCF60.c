// Function: sub_9BCF60
// Address: 0x9bcf60
_DWORD *__thiscall sub_9BCF60(_DWORD *this, char a2)
{
  sub_9BCCD0(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
