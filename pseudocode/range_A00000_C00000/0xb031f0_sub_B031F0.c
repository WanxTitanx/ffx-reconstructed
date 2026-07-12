// Function: sub_B031F0
// Address: 0xb031f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B031F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2A10;
  v1 = (_DWORD *)unk_CB2A14;
  *(_DWORD *)(dword_CB2A10 + 4) = unk_CB2A14;
  *v1 = v0;
  dword_CB2A10 = &dword_CB2A10;
  unk_CB2A14 = &dword_CB2A10;
  if ( (unk_CB2A20 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB2A1C);
}

