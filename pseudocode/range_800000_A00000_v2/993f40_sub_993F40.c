// Function: sub_993F40
// Address: 0x993f40
_DWORD *__thiscall sub_993F40(_DWORD *this, char a2)
{
  *this = &btCollisionAlgorithmCreateFunc::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
