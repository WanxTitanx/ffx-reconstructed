// Function: sub_AFFCA0
// Address: 0xaffca0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFCA0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA9308;
  v1 = (_DWORD *)unk_CA930C;
  *(_DWORD *)(dword_CA9308 + 4) = unk_CA930C;
  *v1 = v0;
  dword_CA9308 = &dword_CA9308;
  unk_CA930C = &dword_CA9308;
  if ( (unk_CA9318 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA9314);
}

