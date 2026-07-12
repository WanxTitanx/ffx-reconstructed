// Function: sub_B026F0
// Address: 0xb026f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B026F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0DF4;
  v1 = (_DWORD *)unk_CB0DF8;
  *(_DWORD *)(dword_CB0DF4 + 4) = unk_CB0DF8;
  *v1 = v0;
  dword_CB0DF4 = &dword_CB0DF4;
  unk_CB0DF8 = &dword_CB0DF4;
  if ( (unk_CB0E04 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB0E00);
}

