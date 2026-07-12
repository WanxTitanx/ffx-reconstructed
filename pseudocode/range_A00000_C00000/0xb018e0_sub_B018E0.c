// Function: sub_B018E0
// Address: 0xb018e0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B018E0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADDE0;
  v1 = (_DWORD *)unk_CADDE4;
  *(_DWORD *)(dword_CADDE0 + 4) = unk_CADDE4;
  *v1 = v0;
  dword_CADDE0 = &dword_CADDE0;
  unk_CADDE4 = &dword_CADDE0;
  if ( (unk_CADDF0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADDEC);
}

