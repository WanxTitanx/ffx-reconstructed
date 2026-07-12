// Function: sub_AFFE80
// Address: 0xaffe80
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFE80()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA9330;
  v1 = (_DWORD *)unk_CA9334;
  *(_DWORD *)(dword_CA9330 + 4) = unk_CA9334;
  *v1 = v0;
  dword_CA9330 = &dword_CA9330;
  unk_CA9334 = &dword_CA9330;
  if ( (unk_CA9340 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA933C);
}

