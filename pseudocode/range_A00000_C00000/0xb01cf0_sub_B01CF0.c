// Function: sub_B01CF0
// Address: 0xb01cf0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01CF0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAEA2C;
  v1 = (_DWORD *)unk_CAEA30;
  *(_DWORD *)(dword_CAEA2C + 4) = unk_CAEA30;
  *v1 = v0;
  dword_CAEA2C = &dword_CAEA2C;
  unk_CAEA30 = &dword_CAEA2C;
  if ( (unk_CAEA3C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAEA38);
}

