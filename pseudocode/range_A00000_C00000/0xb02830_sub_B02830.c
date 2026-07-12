// Function: sub_B02830
// Address: 0xb02830
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02830()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0DA4;
  v1 = (_DWORD *)unk_CB0DA8;
  *(_DWORD *)(dword_CB0DA4 + 4) = unk_CB0DA8;
  *v1 = v0;
  dword_CB0DA4 = &dword_CB0DA4;
  unk_CB0DA8 = &dword_CB0DA4;
  if ( (unk_CB0DB4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB0DB0);
}

