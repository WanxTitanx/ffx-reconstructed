// Function: sub_B018A0
// Address: 0xb018a0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B018A0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADFE8;
  v1 = (_DWORD *)unk_CADFEC;
  *(_DWORD *)(dword_CADFE8 + 4) = unk_CADFEC;
  *v1 = v0;
  dword_CADFE8 = &dword_CADFE8;
  unk_CADFEC = &dword_CADFE8;
  if ( (unk_CADFF8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADFF4);
}

