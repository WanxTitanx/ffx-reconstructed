// Function: sub_B05EB0
// Address: 0xb05eb0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05EB0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0B28;
  v1 = (_DWORD *)unk_CC0B2C;
  *(_DWORD *)(dword_CC0B28 + 4) = unk_CC0B2C;
  *v1 = v0;
  dword_CC0B28 = &dword_CC0B28;
  unk_CC0B2C = &dword_CC0B28;
  if ( (unk_CC0B38 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0B34);
}

