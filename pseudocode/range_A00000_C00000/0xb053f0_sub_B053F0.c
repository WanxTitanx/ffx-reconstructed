// Function: sub_B053F0
// Address: 0xb053f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B053F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0D1C;
  v1 = (_DWORD *)unk_CC0D20;
  *(_DWORD *)(dword_CC0D1C + 4) = unk_CC0D20;
  *v1 = v0;
  dword_CC0D1C = &dword_CC0D1C;
  unk_CC0D20 = &dword_CC0D1C;
  if ( (unk_CC0D2C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0D28);
}

