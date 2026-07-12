// Function: sub_B05710
// Address: 0xb05710
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05710()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0CF4;
  v1 = (_DWORD *)unk_CC0CF8;
  *(_DWORD *)(dword_CC0CF4 + 4) = unk_CC0CF8;
  *v1 = v0;
  dword_CC0CF4 = &dword_CC0CF4;
  unk_CC0CF8 = &dword_CC0CF4;
  if ( (unk_CC0D04 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0D00);
}

