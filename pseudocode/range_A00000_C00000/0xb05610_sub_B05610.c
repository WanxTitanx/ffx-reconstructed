// Function: sub_B05610
// Address: 0xb05610
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05610()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0504;
  v1 = (_DWORD *)unk_CC0508;
  *(_DWORD *)(dword_CC0504 + 4) = unk_CC0508;
  *v1 = v0;
  dword_CC0504 = &dword_CC0504;
  unk_CC0508 = &dword_CC0504;
  if ( (unk_CC0514 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0510);
}

