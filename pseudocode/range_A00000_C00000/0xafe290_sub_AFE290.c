// Function: sub_AFE290
// Address: 0xafe290
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFE290()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA36A4;
  v1 = (_DWORD *)unk_CA36A8;
  *(_DWORD *)(dword_CA36A4 + 4) = unk_CA36A8;
  *v1 = v0;
  dword_CA36A4 = &dword_CA36A4;
  unk_CA36A8 = &dword_CA36A4;
  if ( (unk_CA36B4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA36B0);
}

