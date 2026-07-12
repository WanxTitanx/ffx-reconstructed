// Function: sub_B05DA0
// Address: 0xb05da0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05DA0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0B00;
  v1 = (_DWORD *)unk_CC0B04;
  *(_DWORD *)(dword_CC0B00 + 4) = unk_CC0B04;
  *v1 = v0;
  dword_CC0B00 = &dword_CC0B00;
  unk_CC0B04 = &dword_CC0B00;
  if ( (unk_CC0B10 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0B0C);
}

