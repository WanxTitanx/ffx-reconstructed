// Function: sub_AFD1B0
// Address: 0xafd1b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFD1B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9B2F8;
  v1 = (_DWORD *)unk_C9B2FC;
  *(_DWORD *)(dword_C9B2F8 + 4) = unk_C9B2FC;
  *v1 = v0;
  dword_C9B2F8 = &dword_C9B2F8;
  unk_C9B2FC = &dword_C9B2F8;
  if ( (unk_C9B308 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9B304);
}

