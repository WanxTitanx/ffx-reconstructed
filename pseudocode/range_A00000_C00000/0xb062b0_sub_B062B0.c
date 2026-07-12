// Function: sub_B062B0
// Address: 0xb062b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B062B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CCA20C;
  v1 = (_DWORD *)unk_CCA210;
  *(_DWORD *)(dword_CCA20C + 4) = unk_CCA210;
  *v1 = v0;
  dword_CCA20C = &dword_CCA20C;
  unk_CCA210 = &dword_CCA20C;
  if ( (unk_CCA21C & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CCA218);
}

