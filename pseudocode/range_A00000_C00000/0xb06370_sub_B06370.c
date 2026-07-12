// Function: sub_B06370
// Address: 0xb06370
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B06370()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CCA2B4;
  v1 = (_DWORD *)unk_CCA2B8;
  *(_DWORD *)(dword_CCA2B4 + 4) = unk_CCA2B8;
  *v1 = v0;
  dword_CCA2B4 = &dword_CCA2B4;
  unk_CCA2B8 = &dword_CCA2B4;
  if ( (unk_CCA2C4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CCA2C0);
}

