// Function: sub_B05270
// Address: 0xb05270
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05270()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC12A4;
  v1 = (_DWORD *)unk_CC12A8;
  *(_DWORD *)(dword_CC12A4 + 4) = unk_CC12A8;
  *v1 = v0;
  dword_CC12A4 = &dword_CC12A4;
  unk_CC12A8 = &dword_CC12A4;
  if ( (unk_CC12B4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC12B0);
}

