// Function: sub_A1B2A0
// Address: 0xa1b2a0
// Size: 0x51
// Prototype: 

int __thiscall sub_A1B2A0(int this, int a2)
{
  int result; // eax
  int v4; // esi

  if ( *(_UNKNOWN **)this == &unk_CA34CC )
    return 7;
  if ( sub_596120((_DWORD *)this) || (result = sub_58DC90(this)) == 0 )
  {
    v4 = *(_DWORD *)(this + 8);
    sub_5A8690(v4);
    result = sub_596870(v4, a2);
    if ( !result )
      *(_BYTE *)(this + 4) = 1;
  }
  return result;
}

