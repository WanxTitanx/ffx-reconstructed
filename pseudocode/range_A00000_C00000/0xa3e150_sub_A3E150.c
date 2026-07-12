// Function: sub_A3E150
// Address: 0xa3e150
// Size: 0x25
// Prototype: int __thiscall(_DWORD)

void __thiscall sub_A3E150(_DWORD *this)
{
  void *v2; // esi

  v2 = (void *)*(this + 4);
  if ( v2 )
  {
    nullsub_27(*(this + 4));
    FFX_Memory_Free(v2);
    *(this + 4) = 0;
  }
}

