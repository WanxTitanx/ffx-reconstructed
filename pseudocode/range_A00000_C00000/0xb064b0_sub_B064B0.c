// Function: sub_B064B0
// Address: 0xb064b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B064B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC9F1C;
  v1 = (_DWORD *)unk_CC9F20;
  *(_DWORD *)(dword_CC9F1C + 4) = unk_CC9F20;
  *v1 = v0;
  dword_CC9F1C = &dword_CC9F1C;
  unk_CC9F20 = &dword_CC9F1C;
  if ( (unk_CC9F2C & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CC9F28);
}

