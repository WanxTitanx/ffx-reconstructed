// Function: sub_B05D60
// Address: 0xb05d60
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05D60()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0CCC;
  v1 = (_DWORD *)unk_CC0CD0;
  *(_DWORD *)(dword_CC0CCC + 4) = unk_CC0CD0;
  *v1 = v0;
  dword_CC0CCC = &dword_CC0CCC;
  unk_CC0CD0 = &dword_CC0CCC;
  if ( (unk_CC0CDC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0CD8);
}

