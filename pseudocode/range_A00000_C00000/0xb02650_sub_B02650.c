// Function: sub_B02650
// Address: 0xb02650
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02650()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB01F0;
  v1 = (_DWORD *)unk_CB01F4;
  *(_DWORD *)(dword_CB01F0 + 4) = unk_CB01F4;
  *v1 = v0;
  dword_CB01F0 = &dword_CB01F0;
  unk_CB01F4 = &dword_CB01F0;
  if ( (unk_CB0200 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB01FC);
}

