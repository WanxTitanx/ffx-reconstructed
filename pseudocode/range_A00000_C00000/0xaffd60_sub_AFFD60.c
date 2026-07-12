// Function: sub_AFFD60
// Address: 0xaffd60
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFD60()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA928C;
  v1 = (_DWORD *)unk_CA9290;
  *(_DWORD *)(dword_CA928C + 4) = unk_CA9290;
  *v1 = v0;
  dword_CA928C = &dword_CA928C;
  unk_CA9290 = &dword_CA928C;
  if ( (unk_CA929C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA9298);
}

