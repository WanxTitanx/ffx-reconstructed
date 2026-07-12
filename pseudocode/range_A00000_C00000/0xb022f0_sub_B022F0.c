// Function: sub_B022F0
// Address: 0xb022f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B022F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAFC04;
  v1 = (_DWORD *)unk_CAFC08;
  *(_DWORD *)(dword_CAFC04 + 4) = unk_CAFC08;
  *v1 = v0;
  dword_CAFC04 = &dword_CAFC04;
  unk_CAFC08 = &dword_CAFC04;
  if ( (unk_CAFC14 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAFC10);
}

