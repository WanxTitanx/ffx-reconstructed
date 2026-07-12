// Function: sub_B015E0
// Address: 0xb015e0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B015E0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADDB8;
  v1 = (_DWORD *)unk_CADDBC;
  *(_DWORD *)(dword_CADDB8 + 4) = unk_CADDBC;
  *v1 = v0;
  dword_CADDB8 = &dword_CADDB8;
  unk_CADDBC = &dword_CADDB8;
  if ( (unk_CADDC8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADDC4);
}

