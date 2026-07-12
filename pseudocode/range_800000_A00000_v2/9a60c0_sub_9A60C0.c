// Function: sub_9A60C0
// Address: 0x9a60c0
void *__thiscall sub_9A60C0(void *this, char a2)
{
  sub_9A6040(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
