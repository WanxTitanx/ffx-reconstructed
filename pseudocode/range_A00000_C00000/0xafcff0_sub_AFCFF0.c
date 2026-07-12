// Function: sub_AFCFF0
// Address: 0xafcff0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFCFF0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9B230;
  v1 = (_DWORD *)unk_C9B234;
  *(_DWORD *)(dword_C9B230 + 4) = unk_C9B234;
  *v1 = v0;
  dword_C9B230 = &dword_C9B230;
  unk_C9B234 = &dword_C9B230;
  if ( (unk_C9B240 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9B23C);
}

