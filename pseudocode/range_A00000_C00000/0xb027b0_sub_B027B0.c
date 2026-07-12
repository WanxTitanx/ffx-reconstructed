// Function: sub_B027B0
// Address: 0xb027b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B027B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0D04;
  v1 = (_DWORD *)unk_CB0D08;
  *(_DWORD *)(dword_CB0D04 + 4) = unk_CB0D08;
  *v1 = v0;
  dword_CB0D04 = &dword_CB0D04;
  unk_CB0D08 = &dword_CB0D04;
  if ( (unk_CB0D14 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB0D10);
}

