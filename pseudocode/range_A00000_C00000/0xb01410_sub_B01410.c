// Function: sub_B01410
// Address: 0xb01410
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01410()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADEF8;
  v1 = (_DWORD *)unk_CADEFC;
  *(_DWORD *)(dword_CADEF8 + 4) = unk_CADEFC;
  *v1 = v0;
  dword_CADEF8 = &dword_CADEF8;
  unk_CADEFC = &dword_CADEF8;
  if ( (unk_CADF08 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADF04);
}

