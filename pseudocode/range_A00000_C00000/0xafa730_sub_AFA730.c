// Function: sub_AFA730
// Address: 0xafa730
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA730()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C91F90;
  v1 = (_DWORD *)unk_C91F94;
  *(_DWORD *)(dword_C91F90 + 4) = unk_C91F94;
  *v1 = v0;
  dword_C91F90 = &dword_C91F90;
  unk_C91F94 = &dword_C91F90;
  if ( (unk_C91FA0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C91F9C);
}

