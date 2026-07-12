// Function: sub_A2E2B0
// Address: 0xa2e2b0
// Size: 0x21

void *__thiscall sub_A2E2B0(void *this, char a2)
{
  sub_5A0400(); /*0xa2e2b6*/
  if ( (a2 & 1) != 0 ) /*0xa2e2bf*/
    Phyre_Memory_AlignedFree((int)this); /*0xa2e2c2*/
  return this; /*0xa2e2cc*/
}