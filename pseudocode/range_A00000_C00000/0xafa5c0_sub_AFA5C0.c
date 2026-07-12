// Function: sub_AFA5C0
// Address: 0xafa5c0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA5C0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C91CD8;
  v1 = (_DWORD *)unk_C91CDC;
  *(_DWORD *)(dword_C91CD8 + 4) = unk_C91CDC;
  *v1 = v0;
  dword_C91CD8 = &dword_C91CD8;
  unk_C91CDC = &dword_C91CD8;
  if ( (unk_C91CE8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C91CE4);
}

