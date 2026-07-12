// Function: sub_AFFC60
// Address: 0xaffc60
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFC60()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA9358;
  v1 = (_DWORD *)unk_CA935C;
  *(_DWORD *)(dword_CA9358 + 4) = unk_CA935C;
  *v1 = v0;
  dword_CA9358 = &dword_CA9358;
  unk_CA935C = &dword_CA9358;
  if ( (unk_CA9368 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA9364);
}

