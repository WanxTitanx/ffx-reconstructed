// Function: sub_AFD0B0
// Address: 0xafd0b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFD0B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9B258;
  v1 = (_DWORD *)unk_C9B25C;
  *(_DWORD *)(dword_C9B258 + 4) = unk_C9B25C;
  *v1 = v0;
  dword_C9B258 = &dword_C9B258;
  unk_C9B25C = &dword_C9B258;
  if ( (unk_C9B268 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9B264);
}

