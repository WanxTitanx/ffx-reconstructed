// Function: sub_B015A0
// Address: 0xb015a0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B015A0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADD68;
  v1 = (_DWORD *)unk_CADD6C;
  *(_DWORD *)(dword_CADD68 + 4) = unk_CADD6C;
  *v1 = v0;
  dword_CADD68 = &dword_CADD68;
  unk_CADD6C = &dword_CADD68;
  if ( (unk_CADD78 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADD74);
}

