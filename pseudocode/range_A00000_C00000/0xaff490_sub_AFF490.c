// Function: sub_AFF490
// Address: 0xaff490
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFF490()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA7950;
  v1 = (_DWORD *)unk_CA7954;
  *(_DWORD *)(dword_CA7950 + 4) = unk_CA7954;
  *v1 = v0;
  dword_CA7950 = &dword_CA7950;
  unk_CA7954 = &dword_CA7950;
  if ( (unk_CA7960 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA795C);
}

