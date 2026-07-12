// Function: sub_B02DE0
// Address: 0xb02de0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02DE0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2668;
  v1 = (_DWORD *)unk_CB266C;
  *(_DWORD *)(dword_CB2668 + 4) = unk_CB266C;
  *v1 = v0;
  dword_CB2668 = &dword_CB2668;
  unk_CB266C = &dword_CB2668;
  if ( (unk_CB2678 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB2674);
}

