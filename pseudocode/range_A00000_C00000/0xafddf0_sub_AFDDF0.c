// Function: sub_AFDDF0
// Address: 0xafddf0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFDDF0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA2D9C;
  v1 = (_DWORD *)unk_CA2DA0;
  *(_DWORD *)(dword_CA2D9C + 4) = unk_CA2DA0;
  *v1 = v0;
  dword_CA2D9C = &dword_CA2D9C;
  unk_CA2DA0 = &dword_CA2D9C;
  if ( (unk_CA2DAC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA2DA8);
}

