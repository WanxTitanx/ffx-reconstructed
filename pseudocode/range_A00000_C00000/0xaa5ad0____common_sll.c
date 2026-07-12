// Function: ___common_sll
// Address: 0xaa5ad0
// Size: 0x2b
// Prototype: __int64 __cdecl(_DWORD, _DWORD, _DWORD)

int __cdecl __common_sll(__int64 a1, unsigned __int8 n0x20)
{
  __int64 v2; // rax

  if ( n0x20 >= 0x40u )
  {
    LODWORD(v2) = 0;
  }
  else if ( n0x20 >= 0x20u )
  {
    LODWORD(v2) = 0;
  }
  else
  {
    return a1 << (n0x20 & 0x1F);
  }
  return v2;
}

