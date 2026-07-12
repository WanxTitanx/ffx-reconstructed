// Function: sub_B032B0
// Address: 0xb032b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B032B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2410;
  v1 = (_DWORD *)unk_CB2414;
  *(_DWORD *)(dword_CB2410 + 4) = unk_CB2414;
  *v1 = v0;
  dword_CB2410 = &dword_CB2410;
  unk_CB2414 = &dword_CB2410;
  if ( (unk_CB2420 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB241C);
}

