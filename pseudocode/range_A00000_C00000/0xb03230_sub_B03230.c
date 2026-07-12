// Function: sub_B03230
// Address: 0xb03230
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B03230()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB28E0;
  v1 = (_DWORD *)unk_CB28E4;
  *(_DWORD *)(dword_CB28E0 + 4) = unk_CB28E4;
  *v1 = v0;
  dword_CB28E0 = &dword_CB28E0;
  unk_CB28E4 = &dword_CB28E0;
  if ( (unk_CB28F0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB28EC);
}

