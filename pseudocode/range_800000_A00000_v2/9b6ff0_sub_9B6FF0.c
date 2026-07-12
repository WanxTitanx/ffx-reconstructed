// Function: sub_9B6FF0
// Address: 0x9b6ff0
_BYTE *__thiscall sub_9B6FF0(_BYTE *this, char a2)
{
  sub_9B6D20(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
