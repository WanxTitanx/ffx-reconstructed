// Function: sub_B05FC0
// Address: 0xb05fc0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05FC0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC99A4;
  v1 = (_DWORD *)unk_CC99A8;
  *(_DWORD *)(dword_CC99A4 + 4) = unk_CC99A8;
  *v1 = v0;
  dword_CC99A4 = &dword_CC99A4;
  unk_CC99A8 = &dword_CC99A4;
  if ( (unk_CC99B4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC99B0);
}

