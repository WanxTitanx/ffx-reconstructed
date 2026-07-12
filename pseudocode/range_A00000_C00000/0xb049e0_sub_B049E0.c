// Function: sub_B049E0
// Address: 0xb049e0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B049E0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CBDAB0;
  v1 = (_DWORD *)unk_CBDAB4;
  *(_DWORD *)(dword_CBDAB0 + 4) = unk_CBDAB4;
  *v1 = v0;
  dword_CBDAB0 = &dword_CBDAB0;
  unk_CBDAB4 = &dword_CBDAB0;
  if ( (unk_CBDAC0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CBDABC);
}

