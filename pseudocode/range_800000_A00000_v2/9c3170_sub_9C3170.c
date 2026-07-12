// Function: sub_9C3170
// Address: 0x9c3170
void *__thiscall sub_9C3170(void *this, char a2)
{
  sub_9C3060();
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
