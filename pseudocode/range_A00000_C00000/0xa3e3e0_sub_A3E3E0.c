// Function: sub_A3E3E0
// Address: 0xa3e3e0
// Size: 0x56
// Prototype: 

_DWORD *__thiscall sub_A3E3E0(_DWORD *this, char a2)
{
  _DWORD *v3; // edx
  _DWORD *v4; // eax

  v3 = dword_C901A8;
  *this = &Phyre::PUtility::`vftable';
  if ( dword_C901A8[0] )
  {
    do
    {
      v4 = (_DWORD *)*v3;
      if ( (_DWORD *)*v3 == this )
        break;
      v3 = v4 + 1;
    }
    while ( v4[1] );
    if ( *v3 )
    {
      *v3 = *(this + 1);
      *(this + 1) = 0;
    }
  }
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}

