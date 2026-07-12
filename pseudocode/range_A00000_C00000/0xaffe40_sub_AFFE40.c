// Function: sub_AFFE40
// Address: 0xaffe40
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFE40()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA9380;
  v1 = (_DWORD *)unk_CA9384;
  *(_DWORD *)(dword_CA9380 + 4) = unk_CA9384;
  *v1 = v0;
  dword_CA9380 = &dword_CA9380;
  unk_CA9384 = &dword_CA9380;
  if ( (unk_CA9390 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA938C);
}

