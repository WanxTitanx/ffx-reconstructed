// Function: sub_AFDF30
// Address: 0xafdf30
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFDF30()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA2C0C;
  v1 = (_DWORD *)unk_CA2C10;
  *(_DWORD *)(dword_CA2C0C + 4) = unk_CA2C10;
  *v1 = v0;
  dword_CA2C0C = &dword_CA2C0C;
  unk_CA2C10 = &dword_CA2C0C;
  if ( (unk_CA2C1C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA2C18);
}

