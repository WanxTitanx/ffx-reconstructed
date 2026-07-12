// Function: sub_B02C70
// Address: 0xb02c70
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02C70()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2690;
  v1 = (_DWORD *)unk_CB2694;
  *(_DWORD *)(dword_CB2690 + 4) = unk_CB2694;
  *v1 = v0;
  dword_CB2690 = &dword_CB2690;
  unk_CB2694 = &dword_CB2690;
  if ( (unk_CB26A0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB269C);
}

