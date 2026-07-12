// Function: sub_B05650
// Address: 0xb05650
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05650()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC0BA0;
  v1 = (_DWORD *)unk_CC0BA4;
  *(_DWORD *)(dword_CC0BA0 + 4) = unk_CC0BA4;
  *v1 = v0;
  dword_CC0BA0 = &dword_CC0BA0;
  unk_CC0BA4 = &dword_CC0BA0;
  if ( (unk_CC0BB0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC0BAC);
}

