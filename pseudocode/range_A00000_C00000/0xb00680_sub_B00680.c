// Function: sub_B00680
// Address: 0xb00680
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B00680()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAA8A8;
  v1 = (_DWORD *)unk_CAA8AC;
  *(_DWORD *)(dword_CAA8A8 + 4) = unk_CAA8AC;
  *v1 = v0;
  dword_CAA8A8 = &dword_CAA8A8;
  unk_CAA8AC = &dword_CAA8A8;
  if ( (unk_CAA8B8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAA8B4);
}

