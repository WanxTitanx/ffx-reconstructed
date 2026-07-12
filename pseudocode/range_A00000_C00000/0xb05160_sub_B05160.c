// Function: sub_B05160
// Address: 0xb05160
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05160()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC1348;
  v1 = (_DWORD *)unk_CC134C;
  *(_DWORD *)(dword_CC1348 + 4) = unk_CC134C;
  *v1 = v0;
  dword_CC1348 = &dword_CC1348;
  unk_CC134C = &dword_CC1348;
  if ( (unk_CC1358 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC1354);
}

