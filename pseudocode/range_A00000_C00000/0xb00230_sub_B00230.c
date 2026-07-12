// Function: sub_B00230
// Address: 0xb00230
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B00230()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA9D10;
  v1 = (_DWORD *)unk_CA9D14;
  *(_DWORD *)(dword_CA9D10 + 4) = unk_CA9D14;
  *v1 = v0;
  dword_CA9D10 = &dword_CA9D10;
  unk_CA9D14 = &dword_CA9D10;
  if ( (unk_CA9D20 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA9D1C);
}

