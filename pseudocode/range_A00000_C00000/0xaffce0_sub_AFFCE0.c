// Function: sub_AFFCE0
// Address: 0xaffce0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFCE0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA93D0;
  v1 = (_DWORD *)unk_CA93D4;
  *(_DWORD *)(dword_CA93D0 + 4) = unk_CA93D4;
  *v1 = v0;
  dword_CA93D0 = &dword_CA93D0;
  unk_CA93D4 = &dword_CA93D0;
  if ( (unk_CA93E0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA93DC);
}

