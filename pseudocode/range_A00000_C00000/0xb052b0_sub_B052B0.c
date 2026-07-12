// Function: sub_B052B0
// Address: 0xb052b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B052B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC1320;
  v1 = (_DWORD *)unk_CC1324;
  *(_DWORD *)(dword_CC1320 + 4) = unk_CC1324;
  *v1 = v0;
  dword_CC1320 = &dword_CC1320;
  unk_CC1324 = &dword_CC1320;
  if ( (unk_CC1330 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC132C);
}

