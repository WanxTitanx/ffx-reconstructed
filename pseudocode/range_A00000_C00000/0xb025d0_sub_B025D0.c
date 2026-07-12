// Function: sub_B025D0
// Address: 0xb025d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B025D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB00D8;
  v1 = (_DWORD *)unk_CB00DC;
  *(_DWORD *)(dword_CB00D8 + 4) = unk_CB00DC;
  *v1 = v0;
  dword_CB00D8 = &dword_CB00D8;
  unk_CB00DC = &dword_CB00D8;
  if ( (unk_CB00E8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB00E4);
}

