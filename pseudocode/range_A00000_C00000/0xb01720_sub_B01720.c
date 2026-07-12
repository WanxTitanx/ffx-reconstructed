// Function: sub_B01720
// Address: 0xb01720
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01720()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADF98;
  v1 = (_DWORD *)unk_CADF9C;
  *(_DWORD *)(dword_CADF98 + 4) = unk_CADF9C;
  *v1 = v0;
  dword_CADF98 = &dword_CADF98;
  unk_CADF9C = &dword_CADF98;
  if ( (unk_CADFA8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADFA4);
}

