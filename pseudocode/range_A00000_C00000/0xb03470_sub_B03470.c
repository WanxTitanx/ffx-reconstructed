// Function: sub_B03470
// Address: 0xb03470
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B03470()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2A38;
  v1 = (_DWORD *)unk_CB2A3C;
  *(_DWORD *)(dword_CB2A38 + 4) = unk_CB2A3C;
  *v1 = v0;
  dword_CB2A38 = &dword_CB2A38;
  unk_CB2A3C = &dword_CB2A38;
  if ( (unk_CB2A48 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB2A44);
}

