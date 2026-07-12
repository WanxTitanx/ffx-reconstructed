// Function: sub_B02CB0
// Address: 0xb02cb0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02CB0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB28B8;
  v1 = (_DWORD *)unk_CB28BC;
  *(_DWORD *)(dword_CB28B8 + 4) = unk_CB28BC;
  *v1 = v0;
  dword_CB28B8 = &dword_CB28B8;
  unk_CB28BC = &dword_CB28B8;
  if ( (unk_CB28C8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB28C4);
}

