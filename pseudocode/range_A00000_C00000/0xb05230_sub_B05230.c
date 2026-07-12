// Function: sub_B05230
// Address: 0xb05230
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05230()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0D94;
  v1 = (_DWORD *)unk_CC0D98;
  *(_DWORD *)(dword_CC0D94 + 4) = unk_CC0D98;
  *v1 = v0;
  dword_CC0D94 = &dword_CC0D94;
  unk_CC0D98 = &dword_CC0D94;
  if ( (unk_CC0DA4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0DA0);
}

