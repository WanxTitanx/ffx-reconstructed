// Function: sub_AFB000
// Address: 0xafb000
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB000()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C94178;
  v1 = (_DWORD *)unk_C9417C;
  *(_DWORD *)(dword_C94178 + 4) = unk_C9417C;
  *v1 = v0;
  dword_C94178 = &dword_C94178;
  unk_C9417C = &dword_C94178;
  if ( (unk_C94188 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94184);
}

