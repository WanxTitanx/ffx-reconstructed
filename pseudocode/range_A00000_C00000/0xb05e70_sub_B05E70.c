// Function: sub_B05E70
// Address: 0xb05e70
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05E70()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC00C8;
  v1 = (_DWORD *)unk_CC00CC;
  *(_DWORD *)(dword_CC00C8 + 4) = unk_CC00CC;
  *v1 = v0;
  dword_CC00C8 = &dword_CC00C8;
  unk_CC00CC = &dword_CC00C8;
  if ( (unk_CC00D8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC00D4);
}

