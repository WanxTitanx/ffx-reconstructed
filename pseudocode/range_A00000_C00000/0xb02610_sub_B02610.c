// Function: sub_B02610
// Address: 0xb02610
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02610()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0128;
  v1 = (_DWORD *)unk_CB012C;
  *(_DWORD *)(dword_CB0128 + 4) = unk_CB012C;
  *v1 = v0;
  dword_CB0128 = &dword_CB0128;
  unk_CB012C = &dword_CB0128;
  if ( (unk_CB0138 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB0134);
}

