// Function: sub_AFD0F0
// Address: 0xafd0f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFD0F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9B2D0;
  v1 = (_DWORD *)unk_C9B2D4;
  *(_DWORD *)(dword_C9B2D0 + 4) = unk_C9B2D4;
  *v1 = v0;
  dword_C9B2D0 = &dword_C9B2D0;
  unk_C9B2D4 = &dword_C9B2D0;
  if ( (unk_C9B2E0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9B2DC);
}

