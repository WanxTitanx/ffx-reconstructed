// Function: sub_B01E70
// Address: 0xb01e70
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01E70()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAEEFC;
  v1 = (_DWORD *)unk_CAEF00;
  *(_DWORD *)(dword_CAEEFC + 4) = unk_CAEF00;
  *v1 = v0;
  dword_CAEEFC = &dword_CAEEFC;
  unk_CAEF00 = &dword_CAEEFC;
  if ( (unk_CAEF0C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAEF08);
}

