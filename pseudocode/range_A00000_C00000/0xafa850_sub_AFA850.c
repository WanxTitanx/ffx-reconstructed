// Function: sub_AFA850
// Address: 0xafa850
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA850()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C91F68;
  v1 = (_DWORD *)unk_C91F6C;
  *(_DWORD *)(dword_C91F68 + 4) = unk_C91F6C;
  *v1 = v0;
  dword_C91F68 = &dword_C91F68;
  unk_C91F6C = &dword_C91F68;
  if ( (unk_C91F78 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C91F74);
}

