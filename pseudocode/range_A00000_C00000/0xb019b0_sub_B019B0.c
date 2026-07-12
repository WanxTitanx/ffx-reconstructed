// Function: sub_B019B0
// Address: 0xb019b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B019B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAE6A4;
  v1 = (_DWORD *)unk_CAE6A8;
  *(_DWORD *)(dword_CAE6A4 + 4) = unk_CAE6A8;
  *v1 = v0;
  dword_CAE6A4 = &dword_CAE6A4;
  unk_CAE6A8 = &dword_CAE6A4;
  if ( (unk_CAE6B4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAE6B0);
}

