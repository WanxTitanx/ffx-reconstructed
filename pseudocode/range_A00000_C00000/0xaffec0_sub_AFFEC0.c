// Function: sub_AFFEC0
// Address: 0xaffec0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFEC0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA9448;
  v1 = (_DWORD *)unk_CA944C;
  *(_DWORD *)(dword_CA9448 + 4) = unk_CA944C;
  *v1 = v0;
  dword_CA9448 = &dword_CA9448;
  unk_CA944C = &dword_CA9448;
  if ( (unk_CA9458 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA9454);
}

