// Function: sub_B01290
// Address: 0xb01290
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01290()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADF20;
  v1 = (_DWORD *)unk_CADF24;
  *(_DWORD *)(dword_CADF20 + 4) = unk_CADF24;
  *v1 = v0;
  dword_CADF20 = &dword_CADF20;
  unk_CADF24 = &dword_CADF20;
  if ( (unk_CADF30 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADF2C);
}

