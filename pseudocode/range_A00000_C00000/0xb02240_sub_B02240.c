// Function: sub_B02240
// Address: 0xb02240
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02240()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAFA18;
  v1 = (_DWORD *)unk_CAFA1C;
  *(_DWORD *)(dword_CAFA18 + 4) = unk_CAFA1C;
  *v1 = v0;
  dword_CAFA18 = &dword_CAFA18;
  unk_CAFA1C = &dword_CAFA18;
  if ( (unk_CAFA28 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAFA24);
}

