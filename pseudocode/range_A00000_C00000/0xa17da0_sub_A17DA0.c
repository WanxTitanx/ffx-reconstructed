// Function: sub_A17DA0
// Address: 0xa17da0
// Size: 0x60
// Prototype: 

int __thiscall sub_A17DA0(_DWORD *this, int a2, int a3)
{
  void **v5; // ecx
  int v6; // eax

  if ( *(this + 851) )
    return 22;
  if ( *(_BYTE *)(a3 + 4) )
    v5 = 0;
  else
    v5 = *(void ***)a3;
  if ( *v5 != &unk_CA3364 )
    return 5;
  *(this + 851) = a3;
  v6 = sub_A05E70(a2);
  *(this + 823) = v6;
  return v6 != 0 ? 0 : 14;
}

