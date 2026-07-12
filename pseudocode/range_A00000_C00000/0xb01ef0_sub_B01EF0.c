// Function: sub_B01EF0
// Address: 0xb01ef0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01EF0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAEED4;
  v1 = (_DWORD *)unk_CAEED8;
  *(_DWORD *)(dword_CAEED4 + 4) = unk_CAEED8;
  *v1 = v0;
  dword_CAEED4 = &dword_CAEED4;
  unk_CAEED8 = &dword_CAEED4;
  if ( (unk_CAEEE4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAEEE0);
}

