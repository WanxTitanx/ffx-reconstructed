// Function: sub_B027F0
// Address: 0xb027f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B027F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0D7C;
  v1 = (_DWORD *)unk_CB0D80;
  *(_DWORD *)(dword_CB0D7C + 4) = unk_CB0D80;
  *v1 = v0;
  dword_CB0D7C = &dword_CB0D7C;
  unk_CB0D80 = &dword_CB0D7C;
  if ( (unk_CB0D8C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB0D88);
}

