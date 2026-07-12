// Function: sub_A3E040
// Address: 0xa3e040
// Size: 0x74
// Prototype: _DWORD __cdecl()

int __thiscall sub_A3E040(_DWORD *this)
{
  void *v2; // edi

  *this = &VbfMkvReader::`vftable';
  v2 = (void *)*(this + 4);
  if ( v2 )
  {
    nullsub_27(v2);
    FFX_Memory_Free(v2);
    *(this + 4) = 0;
  }
  return sub_41E6A0(this);
}

