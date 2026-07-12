// Function: sub_B053B0
// Address: 0xb053b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B053B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0D6C;
  v1 = (_DWORD *)unk_CC0D70;
  *(_DWORD *)(dword_CC0D6C + 4) = unk_CC0D70;
  *v1 = v0;
  dword_CC0D6C = &dword_CC0D6C;
  unk_CC0D70 = &dword_CC0D6C;
  if ( (unk_CC0D7C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0D78);
}

