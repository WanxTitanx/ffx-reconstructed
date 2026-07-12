// Function: sub_B061B0
// Address: 0xb061b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B061B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CCA1B8;
  v1 = (_DWORD *)unk_CCA1BC;
  *(_DWORD *)(dword_CCA1B8 + 4) = unk_CCA1BC;
  *v1 = v0;
  dword_CCA1B8 = &dword_CCA1B8;
  unk_CCA1BC = &dword_CCA1B8;
  if ( (unk_CCA1C8 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CCA1C4);
}

