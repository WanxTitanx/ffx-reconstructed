// Function: sub_B02510
// Address: 0xb02510
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02510()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB01A0;
  v1 = (_DWORD *)unk_CB01A4;
  *(_DWORD *)(dword_CB01A0 + 4) = unk_CB01A4;
  *v1 = v0;
  dword_CB01A0 = &dword_CB01A0;
  unk_CB01A4 = &dword_CB01A0;
  if ( (unk_CB01B0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB01AC);
}

