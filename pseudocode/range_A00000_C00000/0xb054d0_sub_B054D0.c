// Function: sub_B054D0
// Address: 0xb054d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B054D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC1370;
  v1 = (_DWORD *)unk_CC1374;
  *(_DWORD *)(dword_CC1370 + 4) = unk_CC1374;
  *v1 = v0;
  dword_CC1370 = &dword_CC1370;
  unk_CC1374 = &dword_CC1370;
  if ( (unk_CC1380 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC137C);
}

