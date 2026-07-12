// Function: sub_B05590
// Address: 0xb05590
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05590()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC00F0;
  v1 = (_DWORD *)unk_CC00F4;
  *(_DWORD *)(dword_CC00F0 + 4) = unk_CC00F4;
  *v1 = v0;
  dword_CC00F0 = &dword_CC00F0;
  unk_CC00F4 = &dword_CC00F0;
  if ( (unk_CC0100 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC00FC);
}

