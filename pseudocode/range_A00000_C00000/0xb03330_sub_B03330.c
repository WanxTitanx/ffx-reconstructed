// Function: sub_B03330
// Address: 0xb03330
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B03330()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2438;
  v1 = (_DWORD *)unk_CB243C;
  *(_DWORD *)(dword_CB2438 + 4) = unk_CB243C;
  *v1 = v0;
  dword_CB2438 = &dword_CB2438;
  unk_CB243C = &dword_CB2438;
  if ( (unk_CB2448 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB2444);
}

