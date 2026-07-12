// Function: sub_B05550
// Address: 0xb05550
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05550()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0140;
  v1 = (_DWORD *)unk_CC0144;
  *(_DWORD *)(dword_CC0140 + 4) = unk_CC0144;
  *v1 = v0;
  dword_CC0140 = &dword_CC0140;
  unk_CC0144 = &dword_CC0140;
  if ( (unk_CC0150 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC014C);
}

