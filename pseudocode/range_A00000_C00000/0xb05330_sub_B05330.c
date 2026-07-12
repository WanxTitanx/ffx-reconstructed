// Function: sub_B05330
// Address: 0xb05330
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B05330()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC12F8;
  v1 = (_DWORD *)unk_CC12FC;
  *(_DWORD *)(dword_CC12F8 + 4) = unk_CC12FC;
  *v1 = v0;
  dword_CC12F8 = &dword_CC12F8;
  unk_CC12FC = &dword_CC12F8;
  if ( (unk_CC1308 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC1304);
}

