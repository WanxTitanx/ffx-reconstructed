// Function: sub_AFF450
// Address: 0xaff450
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFF450()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA7900;
  v1 = (_DWORD *)unk_CA7904;
  *(_DWORD *)(dword_CA7900 + 4) = unk_CA7904;
  *v1 = v0;
  dword_CA7900 = &dword_CA7900;
  unk_CA7904 = &dword_CA7900;
  if ( (unk_CA7910 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA790C);
}

