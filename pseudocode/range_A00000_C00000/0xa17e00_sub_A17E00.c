// Function: sub_A17E00
// Address: 0xa17e00
// Size: 0x97
// Prototype: 

int __thiscall sub_A17E00(_DWORD *this, int a2, int a3, int a4)
{
  int result; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // [esp+4h] [ebp-4h] BYREF

  if ( *(this + 851) )
    return 22;
  v8 = 0;
  v6 = sub_A06A30(a2, a3, a4, &unk_CA3364, 0, 0, &v8);
  result = v8;
  if ( v6 && !v8 )
  {
    if ( *(_BYTE *)(v6 + 4) )
      v7 = 0;
    else
      v7 = *(_DWORD *)v6;
    *(_DWORD *)(v7 + 20) &= ~2u;
    sub_4C4350(v7);
    *(this + 822) = sub_A06A30(a2, a3, a4, &unk_CA310C, 0, 0, 0);
    return sub_A17DA0(this, a2, v6);
  }
  return result;
}

