// Function: sub_AFA890
// Address: 0xafa890
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA890()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C91F18;
  v1 = (_DWORD *)unk_C91F1C;
  *(_DWORD *)(dword_C91F18 + 4) = unk_C91F1C;
  *v1 = v0;
  dword_C91F18 = &dword_C91F18;
  unk_C91F1C = &dword_C91F18;
  if ( (unk_C91F28 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C91F24);
}

