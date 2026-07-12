// Function: sub_B05E20
// Address: 0xb05e20
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05E20()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0B50;
  v1 = (_DWORD *)unk_CC0B54;
  *(_DWORD *)(dword_CC0B50 + 4) = unk_CC0B54;
  *v1 = v0;
  dword_CC0B50 = &dword_CC0B50;
  unk_CC0B54 = &dword_CC0B50;
  if ( (unk_CC0B60 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0B5C);
}

