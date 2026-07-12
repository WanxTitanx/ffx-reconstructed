// Function: sub_AFD130
// Address: 0xafd130
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFD130()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9B370;
  v1 = (_DWORD *)unk_C9B374;
  *(_DWORD *)(dword_C9B370 + 4) = unk_C9B374;
  *v1 = v0;
  dword_C9B370 = &dword_C9B370;
  unk_C9B374 = &dword_C9B370;
  if ( (unk_C9B380 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9B37C);
}

