// Function: sub_B024D0
// Address: 0xb024d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B024D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0178;
  v1 = (_DWORD *)unk_CB017C;
  *(_DWORD *)(dword_CB0178 + 4) = unk_CB017C;
  *v1 = v0;
  dword_CB0178 = &dword_CB0178;
  unk_CB017C = &dword_CB0178;
  if ( (unk_CB0188 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB0184);
}

