// Function: sub_AFFBE0
// Address: 0xaffbe0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFBE0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA9470;
  v1 = (_DWORD *)unk_CA9474;
  *(_DWORD *)(dword_CA9470 + 4) = unk_CA9474;
  *v1 = v0;
  dword_CA9470 = &dword_CA9470;
  unk_CA9474 = &dword_CA9470;
  if ( (unk_CA9480 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA947C);
}

