// Function: sub_B02730
// Address: 0xb02730
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02730()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0D2C;
  v1 = (_DWORD *)unk_CB0D30;
  *(_DWORD *)(dword_CB0D2C + 4) = unk_CB0D30;
  *v1 = v0;
  dword_CB0D2C = &dword_CB0D2C;
  unk_CB0D30 = &dword_CB0D2C;
  if ( (unk_CB0D3C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB0D38);
}

