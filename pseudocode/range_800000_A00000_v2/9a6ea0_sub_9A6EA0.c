// Function: sub_9A6EA0
// Address: 0x9a6ea0
void *__thiscall sub_9A6EA0(void *this, char a2)
{
  sub_9A6040(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
