// Function: sub_AFA240
// Address: 0xafa240
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA240()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C90C80;
  v1 = (_DWORD *)unk_C90C84;
  *(_DWORD *)(dword_C90C80 + 4) = unk_C90C84;
  *v1 = v0;
  dword_C90C80 = &dword_C90C80;
  unk_C90C84 = &dword_C90C80;
  if ( (unk_C90C90 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C90C8C);
}

