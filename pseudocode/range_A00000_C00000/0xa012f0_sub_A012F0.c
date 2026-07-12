// Function: sub_A012F0
// Address: 0xa012f0
// Size: 0x21
// Prototype: void *__thiscall(void *this, char)

void *__thiscall sub_A012F0(void *this, char a2)
{
  sub_5760E0(); /*0xa012f6*/
  if ( (a2 & 1) != 0 ) /*0xa012ff*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01302*/
  return this; /*0xa0130c*/
}