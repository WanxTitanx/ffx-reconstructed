// Function: sub_B016A0
// Address: 0xb016a0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B016A0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADD40;
  v1 = (_DWORD *)unk_CADD44;
  *(_DWORD *)(dword_CADD40 + 4) = unk_CADD44;
  *v1 = v0;
  dword_CADD40 = &dword_CADD40;
  unk_CADD44 = &dword_CADD40;
  if ( (unk_CADD50 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADD4C);
}

