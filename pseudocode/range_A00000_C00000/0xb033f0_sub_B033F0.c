// Function: sub_B033F0
// Address: 0xb033f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B033F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB2488;
  v1 = (_DWORD *)unk_CB248C;
  *(_DWORD *)(dword_CB2488 + 4) = unk_CB248C;
  *v1 = v0;
  dword_CB2488 = &dword_CB2488;
  unk_CB248C = &dword_CB2488;
  if ( (unk_CB2498 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB2494);
}

