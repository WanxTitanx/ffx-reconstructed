// Function: sub_B061F0
// Address: 0xb061f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B061F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC9F94;
  v1 = (_DWORD *)unk_CC9F98;
  *(_DWORD *)(dword_CC9F94 + 4) = unk_CC9F98;
  *v1 = v0;
  dword_CC9F94 = &dword_CC9F94;
  unk_CC9F98 = &dword_CC9F94;
  if ( (unk_CC9FA4 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CC9FA0);
}

