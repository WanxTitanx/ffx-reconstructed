// Function: sub_B02D60
// Address: 0xb02d60
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02D60()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2550;
  v1 = (_DWORD *)unk_CB2554;
  *(_DWORD *)(dword_CB2550 + 4) = unk_CB2554;
  *v1 = v0;
  dword_CB2550 = &dword_CB2550;
  unk_CB2554 = &dword_CB2550;
  if ( (unk_CB2560 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB255C);
}

