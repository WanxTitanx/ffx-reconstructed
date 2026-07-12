// Function: sub_B02550
// Address: 0xb02550
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02550()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0150;
  v1 = (_DWORD *)unk_CB0154;
  *(_DWORD *)(dword_CB0150 + 4) = unk_CB0154;
  *v1 = v0;
  dword_CB0150 = &dword_CB0150;
  unk_CB0154 = &dword_CB0150;
  if ( (unk_CB0160 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB015C);
}

