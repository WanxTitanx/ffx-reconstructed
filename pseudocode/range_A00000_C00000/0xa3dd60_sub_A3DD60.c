// Function: sub_A3DD60
// Address: 0xa3dd60
// Size: 0x22
// Prototype: 

_DWORD *__thiscall sub_A3DD60(_DWORD *this, char a2)
{
  *this = &CDataFrameQueue::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}

