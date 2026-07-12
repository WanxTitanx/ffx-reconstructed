// Function: sub_B00760
// Address: 0xb00760
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B00760()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAA8D0;
  v1 = (_DWORD *)unk_CAA8D4;
  *(_DWORD *)(dword_CAA8D0 + 4) = unk_CAA8D4;
  *v1 = v0;
  dword_CAA8D0 = &dword_CAA8D0;
  unk_CAA8D4 = &dword_CAA8D0;
  if ( (unk_CAA8E0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAA8DC);
}

