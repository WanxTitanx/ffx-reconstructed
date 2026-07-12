// Function: sub_A02610
// Address: 0xa02610
// Size: 0x22

_DWORD *__thiscall sub_A02610(_DWORD *this, char a2)
{
  *this = &Phyre::PCaller::`vftable'; /*0xa0261a*/
  if ( (a2 & 1) != 0 ) /*0xa02620*/
    FFX_Memory_Free(this); /*0xa02623*/
  return this; /*0xa0262d*/
}