// Function: sub_B02770
// Address: 0xb02770
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02770()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0CB4;
  v1 = (_DWORD *)unk_CB0CB8;
  *(_DWORD *)(dword_CB0CB4 + 4) = unk_CB0CB8;
  *v1 = v0;
  dword_CB0CB4 = &dword_CB0CB4;
  unk_CB0CB8 = &dword_CB0CB4;
  if ( (unk_CB0CC4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB0CC0);
}

