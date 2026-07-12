// Function: sub_B03370
// Address: 0xb03370
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B03370()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB24B0;
  v1 = (_DWORD *)unk_CB24B4;
  *(_DWORD *)(dword_CB24B0 + 4) = unk_CB24B4;
  *v1 = v0;
  dword_CB24B0 = &dword_CB24B0;
  unk_CB24B4 = &dword_CB24B0;
  if ( (unk_CB24C0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB24BC);
}

