// Function: sub_AFB410
// Address: 0xafb410
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB410()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C948E4;
  v1 = (_DWORD *)unk_C948E8;
  *(_DWORD *)(dword_C948E4 + 4) = unk_C948E8;
  *v1 = v0;
  dword_C948E4 = &dword_C948E4;
  unk_C948E8 = &dword_C948E4;
  if ( (unk_C948F4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C948F0);
}

