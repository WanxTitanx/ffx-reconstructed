// Function: sub_AFB0D0
// Address: 0xafb0d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB0D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C943E8;
  v1 = (_DWORD *)unk_C943EC;
  *(_DWORD *)(dword_C943E8 + 4) = unk_C943EC;
  *v1 = v0;
  dword_C943E8 = &dword_C943E8;
  unk_C943EC = &dword_C943E8;
  if ( (unk_C943F8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C943F4);
}

