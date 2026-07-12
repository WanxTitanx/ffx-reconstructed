// Function: sub_A3E0C0
// Address: 0xa3e0c0
// Size: 0x87
// Prototype: 

_DWORD *__thiscall sub_A3E0C0(_DWORD *this, char a2)
{
  void *v3; // edi

  *this = &VbfMkvReader::`vftable';
  v3 = (void *)*(this + 4);
  if ( v3 )
  {
    nullsub_27(v3);
    FFX_Memory_Free(v3);
    *(this + 4) = 0;
  }
  sub_41E6A0(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}

