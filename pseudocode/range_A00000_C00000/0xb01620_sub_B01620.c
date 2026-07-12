// Function: sub_B01620
// Address: 0xb01620
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01620()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADFC0;
  v1 = (_DWORD *)unk_CADFC4;
  *(_DWORD *)(dword_CADFC0 + 4) = unk_CADFC4;
  *v1 = v0;
  dword_CADFC0 = &dword_CADFC0;
  unk_CADFC4 = &dword_CADFC0;
  if ( (unk_CADFD0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADFCC);
}

