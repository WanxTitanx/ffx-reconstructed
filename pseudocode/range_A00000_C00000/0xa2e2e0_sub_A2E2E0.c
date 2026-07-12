// Function: sub_A2E2E0
// Address: 0xa2e2e0
// Size: 0x2b

_DWORD *__thiscall sub_A2E2E0(_DWORD *this, char a2)
{
  *this = &Phyre::PInputs::PInputJoypadButtonSemantic::`vftable'; /*0xa2e2e7*/
  sub_A2E410(this); /*0xa2e2ed*/
  if ( (a2 & 1) != 0 ) /*0xa2e2f9*/
    FFX_Memory_Free(this); /*0xa2e2fc*/
  return this; /*0xa2e306*/
}