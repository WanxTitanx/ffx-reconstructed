// Function: sub_B017A0
// Address: 0xb017a0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B017A0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADCF0;
  v1 = (_DWORD *)unk_CADCF4;
  *(_DWORD *)(dword_CADCF0 + 4) = unk_CADCF4;
  *v1 = v0;
  dword_CADCF0 = &dword_CADCF0;
  unk_CADCF4 = &dword_CADCF0;
  if ( (unk_CADD00 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADCFC);
}

