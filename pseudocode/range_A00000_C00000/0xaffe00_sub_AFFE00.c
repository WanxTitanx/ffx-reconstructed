// Function: sub_AFFE00
// Address: 0xaffe00
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFE00()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA9420;
  v1 = (_DWORD *)unk_CA9424;
  *(_DWORD *)(dword_CA9420 + 4) = unk_CA9424;
  *v1 = v0;
  dword_CA9420 = &dword_CA9420;
  unk_CA9424 = &dword_CA9420;
  if ( (unk_CA9430 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA942C);
}

