// Function: sub_B016E0
// Address: 0xb016e0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B016E0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADD90;
  v1 = (_DWORD *)unk_CADD94;
  *(_DWORD *)(dword_CADD90 + 4) = unk_CADD94;
  *v1 = v0;
  dword_CADD90 = &dword_CADD90;
  unk_CADD94 = &dword_CADD90;
  if ( (unk_CADDA0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADD9C);
}

