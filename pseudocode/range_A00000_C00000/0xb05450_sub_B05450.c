// Function: sub_B05450
// Address: 0xb05450
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05450()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0CA4;
  v1 = (_DWORD *)unk_CC0CA8;
  *(_DWORD *)(dword_CC0CA4 + 4) = unk_CC0CA8;
  *v1 = v0;
  dword_CC0CA4 = &dword_CC0CA4;
  unk_CC0CA8 = &dword_CC0CA4;
  if ( (unk_CC0CB4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0CB0);
}

