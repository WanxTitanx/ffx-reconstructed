// Function: sub_B02D20
// Address: 0xb02d20
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02D20()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2578;
  v1 = (_DWORD *)unk_CB257C;
  *(_DWORD *)(dword_CB2578 + 4) = unk_CB257C;
  *v1 = v0;
  dword_CB2578 = &dword_CB2578;
  unk_CB257C = &dword_CB2578;
  if ( (unk_CB2588 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB2584);
}

