// Function: sub_A250A0
// Address: 0xa250a0
// Size: 0x3f
// Prototype: 

int __thiscall sub_A250A0(int this, int a2)
{
  int v3; // ecx
  int v4; // eax
  int v5; // esi
  int result; // eax

  v3 = *(_DWORD *)(this + 8) + 1;
  v4 = *(_DWORD *)(this + 40) & 0x7FFFFFFF;
  if ( !v4 )
    v4 = 1;
  v5 = v4 != v3 ? v3 : 0;
  result = sub_59DEB0(v5, a2);
  if ( !result )
  {
    *(_DWORD *)(this + 8) = v5;
    *(_BYTE *)(this + 4) = 0;
  }
  return result;
}

