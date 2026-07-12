// Function: sub_B06470
// Address: 0xb06470
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B06470()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CCA05C;
  v1 = (_DWORD *)unk_CCA060;
  *(_DWORD *)(dword_CCA05C + 4) = unk_CCA060;
  *v1 = v0;
  dword_CCA05C = &dword_CCA05C;
  unk_CCA060 = &dword_CCA05C;
  if ( (unk_CCA06C & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CCA068);
}

