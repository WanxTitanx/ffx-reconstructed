// Function: sub_B01660
// Address: 0xb01660
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01660()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADF70;
  v1 = (_DWORD *)unk_CADF74;
  *(_DWORD *)(dword_CADF70 + 4) = unk_CADF74;
  *v1 = v0;
  dword_CADF70 = &dword_CADF70;
  unk_CADF74 = &dword_CADF70;
  if ( (unk_CADF80 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADF7C);
}

