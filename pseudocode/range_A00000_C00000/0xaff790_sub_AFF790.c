// Function: sub_AFF790
// Address: 0xaff790
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFF790()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA7860;
  v1 = (_DWORD *)unk_CA7864;
  *(_DWORD *)(dword_CA7860 + 4) = unk_CA7864;
  *v1 = v0;
  dword_CA7860 = &dword_CA7860;
  unk_CA7864 = &dword_CA7860;
  if ( (unk_CA7870 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA786C);
}

