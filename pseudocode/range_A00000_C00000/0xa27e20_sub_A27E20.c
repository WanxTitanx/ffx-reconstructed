// Function: sub_A27E20
// Address: 0xa27e20
// Size: 0x62
// Prototype: 

int __thiscall sub_A27E20(int this, int a2)
{
  int result; // eax
  int v4; // ecx

  if ( *(_UNKNOWN **)this == &unk_CA34CC )
    return 7;
  if ( sub_596120((_DWORD *)this) || (result = sub_58DC90(this)) == 0 )
  {
    v4 = *(_DWORD *)(this + 36) & 0x7FFFFFFF;
    if ( !v4 )
      v4 = 1;
    result = sub_596D20(v4 != *(_DWORD *)(this + 8) + 1 ? *(_DWORD *)(this + 8) + 1 : 0, a2);
    if ( !result )
      *(_BYTE *)(this + 4) = 2;
  }
  return result;
}

