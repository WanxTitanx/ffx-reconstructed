// Function: sub_AFA770
// Address: 0xafa770
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA770()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C91F40;
  v1 = (_DWORD *)unk_C91F44;
  *(_DWORD *)(dword_C91F40 + 4) = unk_C91F44;
  *v1 = v0;
  dword_C91F40 = &dword_C91F40;
  unk_C91F44 = &dword_C91F40;
  if ( (unk_C91F50 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C91F4C);
}

