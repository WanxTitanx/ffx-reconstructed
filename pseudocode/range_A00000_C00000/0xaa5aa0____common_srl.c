// Function: ___common_srl
// Address: 0xaa5aa0
// Size: 0x2d
// Prototype: __int64 __cdecl(_DWORD, _DWORD, _DWORD)

int __cdecl __common_srl(__int64 a1, unsigned __int8 n0x20)
{
  __int64 v2; // rax

  if ( n0x20 >= 0x40u )
  {
    LODWORD(v2) = SHIDWORD(a1) >> 31;
  }
  else if ( n0x20 >= 0x20u )
  {
    LODWORD(v2) = SHIDWORD(a1) >> (n0x20 & 0x1F);
  }
  else
  {
    return a1 >> (n0x20 & 0x1F);
  }
  return v2;
}

