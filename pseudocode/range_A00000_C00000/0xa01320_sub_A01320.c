// Function: sub_A01320
// Address: 0xa01320
// Size: 0x21
// Prototype: void *__thiscall(void *this, char)

void *__thiscall sub_A01320(void *this, char a2)
{
  sub_5760E0(); /*0xa01326*/
  if ( (a2 & 1) != 0 ) /*0xa0132f*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01332*/
  return this; /*0xa0133c*/
}