// Function: sub_A025E0
// Address: 0xa025e0
// Size: 0x22

_DWORD *__thiscall sub_A025E0(_DWORD *this, char a2)
{
  *this = &Phyre::PCaller::`vftable'; /*0xa025ea*/
  if ( (a2 & 1) != 0 ) /*0xa025f0*/
    FFX_Memory_Free(this); /*0xa025f3*/
  return this; /*0xa025fd*/
}