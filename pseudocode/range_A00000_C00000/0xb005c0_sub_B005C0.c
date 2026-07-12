// Function: sub_B005C0
// Address: 0xb005c0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B005C0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAA998;
  v1 = (_DWORD *)unk_CAA99C;
  *(_DWORD *)(dword_CAA998 + 4) = unk_CAA99C;
  *v1 = v0;
  dword_CAA998 = &dword_CAA998;
  unk_CAA99C = &dword_CAA998;
  if ( (unk_CAA9A8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAA9A4);
}

