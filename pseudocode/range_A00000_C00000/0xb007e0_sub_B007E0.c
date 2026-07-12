// Function: sub_B007E0
// Address: 0xb007e0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B007E0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAA9E8;
  v1 = (_DWORD *)unk_CAA9EC;
  *(_DWORD *)(dword_CAA9E8 + 4) = unk_CAA9EC;
  *v1 = v0;
  dword_CAA9E8 = &dword_CAA9E8;
  unk_CAA9EC = &dword_CAA9E8;
  if ( (unk_CAA9F8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAA9F4);
}

