// Function: sub_B031B0
// Address: 0xb031b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B031B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2460;
  v1 = (_DWORD *)unk_CB2464;
  *(_DWORD *)(dword_CB2460 + 4) = unk_CB2464;
  *v1 = v0;
  dword_CB2460 = &dword_CB2460;
  unk_CB2464 = &dword_CB2460;
  if ( (unk_CB2470 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB246C);
}

