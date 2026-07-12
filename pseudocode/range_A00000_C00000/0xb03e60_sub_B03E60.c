// Function: sub_B03E60
// Address: 0xb03e60
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B03E60()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CBAE04;
  v1 = (_DWORD *)unk_CBAE08;
  *(_DWORD *)(dword_CBAE04 + 4) = unk_CBAE08;
  *v1 = v0;
  dword_CBAE04 = &dword_CBAE04;
  unk_CBAE08 = &dword_CBAE04;
  if ( (unk_CBAE14 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CBAE10);
}

