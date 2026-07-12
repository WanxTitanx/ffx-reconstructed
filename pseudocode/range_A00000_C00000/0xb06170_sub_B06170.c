// Function: sub_B06170
// Address: 0xb06170
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B06170()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC9EF0;
  v1 = (_DWORD *)unk_CC9EF4;
  *(_DWORD *)(dword_CC9EF0 + 4) = unk_CC9EF4;
  *v1 = v0;
  dword_CC9EF0 = &dword_CC9EF0;
  unk_CC9EF4 = &dword_CC9EF0;
  if ( (unk_CC9F00 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC9EFC);
}

