// Function: sub_9BCF30
// Address: 0x9bcf30
_DWORD *__thiscall sub_9BCF30(_DWORD *this, char a2)
{
  *this = &btConstraintSolver::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
