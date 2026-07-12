// Function: sub_B055D0
// Address: 0xb055d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B055D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0118;
  v1 = (_DWORD *)unk_CC011C;
  *(_DWORD *)(dword_CC0118 + 4) = unk_CC011C;
  *v1 = v0;
  dword_CC0118 = &dword_CC0118;
  unk_CC011C = &dword_CC0118;
  if ( (unk_CC0128 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0124);
}

