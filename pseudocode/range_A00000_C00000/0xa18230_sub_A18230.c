// Function: sub_A18230
// Address: 0xa18230
// Size: 0x3d
// Prototype: 

int __thiscall sub_A18230(_DWORD *this, int a2, int a3)
{
  void **v5; // ecx

  if ( *(this + 26) )
    return 22;
  if ( *(_BYTE *)(a3 + 4) )
    v5 = 0;
  else
    v5 = *(void ***)a3;
  if ( *v5 != &unk_CA2FCC )
    return 5;
  *(this + 26) = a3;
  return 0;
}

