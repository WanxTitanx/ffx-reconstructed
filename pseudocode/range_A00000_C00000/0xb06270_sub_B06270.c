// Function: sub_B06270
// Address: 0xb06270
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B06270()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC9F44;
  v1 = (_DWORD *)unk_CC9F48;
  *(_DWORD *)(dword_CC9F44 + 4) = unk_CC9F48;
  *v1 = v0;
  dword_CC9F44 = &dword_CC9F44;
  unk_CC9F48 = &dword_CC9F44;
  if ( (unk_CC9F54 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CC9F50);
}

