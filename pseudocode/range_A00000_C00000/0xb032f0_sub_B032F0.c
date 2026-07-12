// Function: sub_B032F0
// Address: 0xb032f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B032F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2528;
  v1 = (_DWORD *)unk_CB252C;
  *(_DWORD *)(dword_CB2528 + 4) = unk_CB252C;
  *v1 = v0;
  dword_CB2528 = &dword_CB2528;
  unk_CB252C = &dword_CB2528;
  if ( (unk_CB2538 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB2534);
}

